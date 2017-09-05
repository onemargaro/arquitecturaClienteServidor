#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
/**
 * Margarito Sánchez Baños
 * @param  program  programa a ejecutar
 * @param  arg_list lista de argumento a pasar al programa
 * @return          el proceso id del hijo generado
 */
int spawn(char* program, char** arg_list){
  pid_t child_pid;
  child_pid = fork();

  if (child_pid != 0){
    return child_pid; //si se puede crear el hijo, retorna al padre al main
  }else{
    execvp(program, arg_list); //el hijo ejecuta esta parte de codigo y si se ejecuta de manera correcta no regresara a este programa
    fprintf(stderr, "an error ocurred in execvp\n"); // solo se ejecuta en caso de error
    abort(); //termina ocn la ejecución del programa
  }
}
/**
 * Programa que ejecuta el programa que se le indique sin perder
 * el programa principal
 * @return 0 si todo va bien
 */
int main() {
  char * arg_list[] = {
    "ls",
    "-l",
    "/",
    NULL
  };

  spawn("ls",arg_list);
  printf("done with main program\n"); //el unico que ejecuta esta linea es el proceso padre
  return 0;
}
