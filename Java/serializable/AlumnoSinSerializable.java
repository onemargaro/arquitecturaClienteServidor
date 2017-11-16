public class AlumnoSinSerializable{
  private String nombre;
  private int edad;

  public static void main(String[] args){
    AlumnoSinSerializable alumno1 = new AlumnoSinSerializable();
    System.out.println( "Antes de asignar valores a atributos");
    System.out.println( "nombre=" + alumno1.nombre );
    System.out.println( "edad=" + alumno1.edad );
    System.out.println("----------------------------");
    alumno1.nombre = "Juan";
    alumno1.edad = 23;
    System.out.println( "Despues de asignar valores a atributos");
    System.out.println( "nombre=" + alumno1.nombre );
    System.out.println( "edad=" + alumno1.edad );
  }
}
