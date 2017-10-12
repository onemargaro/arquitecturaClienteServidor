import java.net.*;
import java.io.*;

public class Servidor{
 public static void main(String a[]){
  ServerSocket serverSocket = null;
  Socket socket = null;
  String peticion = null;
  String respuesta = "Datos incorrectos";

  try {
   System.out.println("Escuchando por el puerto 8000");
   serverSocket = new ServerSocket(8000);
  } catch(IOException e) {
   System.out.println("java.io.IOException generada");
   e.printStackTrace();
  }

  System.out.println("Esperando a que los clientes se conecten...");
  while(true) {
   try {
    socket = serverSocket.accept();
    System.out.println("Se conecto un cliente: " + socket.getInetAddress().getHostName());
    DataInputStream dis = new DataInputStream( socket.getInputStream() );
    peticion = dis.readUTF();
    System.out.println("El mensaje que me envio el cliente es: " + peticion);
    DataOutputStream dos = new DataOutputStream( socket.getOutputStream() );
    if(peticion != null)
     respuesta = "Datos correctos";
    System.out.println("El mensaje que le envio al cliente es: " + respuesta);
    dos.writeUTF(respuesta);
    dos.close();
    dis.close();
    socket = null;
   } catch(IOException e) {
    System.out.println("java.io.IOException generada");
    e.printStackTrace();
   }
  }
 }
}
