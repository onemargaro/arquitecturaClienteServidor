#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>
/**
 * Margarito Sánchez Baños
 * verifica que al ejecutar el fork se pasa el id del proceso hijo al padre
 * y al hijo se le retorna un 0
 * @return  int exit success or failure
 */
int main(void) {
  pid_t child; //declara variable de tipo estructura pid_t
  if((child = fork()) == -1) { //realiza un hijo y verifica si aparecio un error
    perror("fork"); //ejecuta un error
    exit(EXIT_FAILURE);  //termina la ejecución del programa con un fallo
  } else if(child == 0) { //el proceso hijo ejecuta estas sentencias
    puts("in child"); // pone en el flujo de salida in child
    printf("\tchild pid = %d\n", getpid());  //imprime el id del proceso hijo
    printf("\tchild ppid = %d\n", getppid()); //imprime el id del proceso padre
    exit(EXIT_SUCCESS); //termina la ejecución de manera correcta
  } else { //el proceso padre ejecuta estas sentencias
    puts("in parent"); // pone en el flujo de salida in parent
    printf("\tparent pid = %d\n", getpid());  //imprime el proceso actual del padre
    printf("\tparent ppid = %d\n", getppid()); //imprime el proceso del padre de la ejecución de este codigo
  }
  exit(EXIT_SUCCESS); //termina de manera correcta la ejecución
}
