import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.ObjectInput;
import java.io.ObjectInputStream;
import java.io.ObjectOutput;
import java.io.ObjectOutputStream;
import java.io.Serializable;

public class AlumnoSerializable implements Serializable {
  private String nombre;
  private int edad;

  public static void main(String[] args) throws Exception {
    ObjectInput in = null;
    AlumnoSerializable alumno1 = null;
    try {
      // Primero se lee el archivo que guarda el objeto
      in = new ObjectInputStream(new FileInputStream("alumno.ser"));
      // Se lee el objeto
      alumno1 = (AlumnoSerializable)in.readObject();
    } catch(FileNotFoundException exc) {
      System.out.println("El archivo no existe, es la primera vez que se ejecuta");
      System.out.println("----------------------------");
    }
    // Lo imprimimos para saber que habia en el archivo
    System.out.println( "alumno1=" + alumno1 );
    // Si es null, entonces lo inicializamos con new
    if( alumno1 == null ) {
      alumno1 = new AlumnoSerializable();
    }
    System.out.println( "Antes de asignar valores a atributos");
    System.out.println( "nombre=" + alumno1.nombre );
    System.out.println( "edad=" + alumno1.edad );
    System.out.println("----------------------------");
    alumno1.nombre = "Juan";
    alumno1.edad = 23;
    System.out.println( "Despues de asignar valores a atributos");
    System.out.println( "nombre=" + alumno1.nombre );
    System.out.println( "edad=" + alumno1.edad );
    System.out.println("----------------------------");
    System.out.println( "Ahora se guardara el objeto en un archivo SER");
    ObjectOutput out = new ObjectOutputStream(new FileOutputStream("alumno.ser"));
    out.writeObject( alumno1 );
    out.close();
  }
}
