#include <unistd.h> 
#include <stdlib.h> 
#include <stdio.h> 
/**
 * Margarito Sánchez Baños
 * Programa que muestra el uso del execv para ejecutar un proceso diferente al principal
 * sustituyendo por el nuevo proceso al programa principal
 * @return int estatus
 */
int main() {
  char *args[] = {"/bin/ls", NULL}; // comando a ser ejecutado
  if(execve("/bin/ls", args, NULL) == -1) { //si el programa se ejecuta correctamente aqui se termina la ejecución del este programa
    perror("execve"); //si sucede algún error se lanza un error de execve
    exit(EXIT_FAILURE); //se termina la ejecución del programa con una estatus del falla
  }
  puts("shouldn't get here"); //esta linea no aparecera
  exit(EXIT_SUCCESS); //termina con estatus exitoso el programa
}
