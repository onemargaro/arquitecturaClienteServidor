import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
public class Lectura{
  public static String leer() throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Ingresa el mensaje");
        return br.readLine();
  }
}
