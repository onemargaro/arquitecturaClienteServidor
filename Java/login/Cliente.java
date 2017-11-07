import java.net.*;
import java.io.*;

public class Cliente extends Lectura
{
 public static void main(String a[])
 {
  Socket socket = null;
  // String peticion = "Mensaje para el servidor";
  String respuesta = null;

  try{
   socket = new Socket(a[0],8000);
   DataInputStream dis = new DataInputStream( socket.getInputStream() );
   DataOutputStream dos = new DataOutputStream( socket.getOutputStream() );
   // Leer datos login user
   respuesta = dis.readUTF();
   System.out.println(respuesta);
   dos.writeUTF(Lectura.leer());
   // Leer datos login password
   respuesta = dis.readUTF();
   System.out.println(respuesta);
   dos.writeUTF(Lectura.password());
   //respuesta del servidor
   respuesta = dis.readUTF();
   System.out.println(respuesta);

   dos.close();
   dis.close();
   socket.close();
  }
  catch(IOException e)
  {
   System.out.println("java.io.IOException generada");
   e.printStackTrace();
  }
 }
}
