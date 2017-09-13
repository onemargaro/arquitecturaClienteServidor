#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
/**
 * Margarito Sánchez Baños
 * @param  program  programa a ejecutar
 * @param  arg_list lista de argumento a pasar al programa
 * @return          el proceso id del hijo generado
 */
int spawn (char* program, char** arg_list){
  pid_t child_pid;
  child_pid = fork(); //ejecuta un duplicado del proceso
  sleep(10); // se duermen los procesos durante 10 segundos
  if (child_pid != 0) {
    return child_pid; //el padre devuelve el pid del proceso hijo
  } else {
    execvp (program, arg_list); //ejecuta el programa pasado
    fprintf (stderr, "an error occurred in execvp\n"); //en caso de que suceda algún error
    abort (); //termina de manera anormal
  }
}

/**
 * Programa que ejecuta el programa que se le indique sin perder
 * el programa principal
 * @return 0 si todo va bien
 */
int main () {
  int child_status;
  char* arg_list[] = {
    "ls",
    "-l",
    "/",
    NULL
  };
  spawn ("ls", arg_list);
  wait (&child_status); //espera a que el hijo termine de manera correcta
  sleep(10); // se duerme durante 10 segundos
  if (WIFEXITED (child_status)) //en caso de que termine correctamente el programa
    printf ("the child process exited normally, with exit code %d\n", WEXITSTATUS (child_status));
  else
    printf ("the child process exited abnormally\n"); //el proceso termine de manera anormal
  return 0;
}
