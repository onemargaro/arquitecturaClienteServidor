import java.net.*;
import java.io.*;

public class Servidor extends Lectura
{

  private static Boolean doLogin(String user, String password) throws FileNotFoundException, IOException{
    String line;
    String[] userFile;
    FileReader f = new FileReader("./passwords.txt");
    BufferedReader b = new BufferedReader(f);
    Boolean response = false;
    while((line = b.readLine())!=null) {
      userFile = line.split(":");
      if (user.equals(userFile[0]) && password.equals(userFile[1])) {
        response = true;
        break;
      }
    }
    b.close();
    return response;
  }

  public static void main(String a[]){
    ServerSocket serverSocket = null;
    Socket socket = null;
    String peticion = null;
    String respuesta = "Datos incorrectos";
    String user;
    String password;
    try {
      System.out.println("Escuchando por el puerto 8000");
      serverSocket = new ServerSocket(8000);
    } catch(IOException e){
      System.out.println("java.io.IOException generada");
      e.printStackTrace();
    }

    System.out.println("Esperando a que los clientes se conecten...");
    while(true){
      try{
        socket = serverSocket.accept();
        DataInputStream dis = new DataInputStream( socket.getInputStream() );
        DataOutputStream dos = new DataOutputStream( socket.getOutputStream() );
        dos.writeUTF("Login: ");
        user = dis.readUTF();
        dos.writeUTF("Password: ");
        password = dis.readUTF();
        if(Servidor.doLogin(user, password)){
          dos.writeUTF("Datos Correctos");
        }else{
          dos.writeUTF("Datos Incorrectos");
        }
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
