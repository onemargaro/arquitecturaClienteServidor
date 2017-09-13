#include <stdio.h>
#include <sys/types.h>
#include <signal.h>

/**
 * Programa que describe como usaar señales para terminar un proceso
 * y se deja un proceso que no terminara y lo adoptara init cuando termine
 * de ejecutarse el padre
 * @param  argc Numero de argumentos pasados al programa
 * @param  argv Argumentos pasados al programa
 * @return      0 si todo sale bien
 */
int main(int argc, char *argv[])
{
  pid_t pid;
  int times=0; //variable que controla las veces ejecutadas
  // Hijo 1
  if((pid = fork()) == 0) { //se duplica el proceso
    while(1){ //el hijo entra en un ciclo infinito
      printf("HIJO PID = %d\n", getpid()); //imprime su pid
      sleep(1); //se duerme 1 segundo
      times++; //se incrementa las veces ejecutados
      if (times >= 20) { //si es mayor o igual a 20 termina su ejecución
        kill(getpid(), SIGTERM);
      }
    }
  }
  // Hijo 2
  if((pid = fork()) == 0) { //se vuelve a duplicar el proceso
    while(1){ //el hijo entra en un ciclo infinito
      printf("HIJO PID = %d\n", getpid()); //imprime su pid
      sleep(1); //se duerme 1 segundo
    }
  }
  sleep(10); //el padre se duerme 10 segundos
  printf("PADRE Terminacion proceso %d\n", pid); //imprime el pid del hijo
  kill(pid, SIGTERM); //manda la señal de terminación al proceso hijo al ultimo creado
  exit(0); //termina su ejecución
}
