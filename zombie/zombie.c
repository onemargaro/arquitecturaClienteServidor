#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

/**
 * Margarito Sánchez Baños
 * Programa que crea un proceso zombie
 * Durmiendo al padre y matando al hijo
 * este no puede morir hasta que el padre
 * se lo permita
 * @param  argc numero de argumentos pasados
 * @param  argv argumentos pasados
 * @return      0 si todo sale bien
 */
int main(int argc, char *argv[])
{
  pid_t child_pid;
  // Create a child process
  child_pid = fork();
  if (child_pid > 0){
    // This is the parent process. Sleep for a minute
    sleep(60);
  }else {
    // This is the child process. Exit immediately
    exit(0);
  }
  return 0;
}
