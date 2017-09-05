#include <stdio.h>
#include <unistd.h>
/**
 * Margarito Sánchez Baños
 * Se imprime el id del proceso del hijo y del padre
 * @return      0 para una ejecución correcta
 */
int main()
{
  printf("The process ID is %d\n", getpid()); //id del proceso
  printf("The parent process ID is %d\n", (int) getppid()); //id del proceso padre
  return 0;
}
