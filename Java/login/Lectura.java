import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.Console;
public class Lectura{
  public static String leer() throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        return br.readLine();
  }
  public static String password() {
        Console console = System.console();
        if (console == null) {
            System.out.println("Error al instanciar Console");
            System.exit(0);
        }

        char passwordArray[] = console.readPassword("");
        String passwd = new String(passwordArray);
        return passwd;
    }
}
