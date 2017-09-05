#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
/**
 * Margarito Sánchez Baños
 * Imprime los Ids del usuario actual logueado y su id efectivo(de quien son los procesos)
 * @return [description]
 */
int main()
{
  printf("Real user ID: %d\n", getuid()); //id del usuario logueado
  printf("Effective user ID: %d\n", geteuid()); //id del usuario que ejecuto el archivo o dueño del proceso
  printf("Real group ID: %d\n", getgid());  //id del grupo al que pertenece el usuario actualmente logueado
  printf("Effective group ID: %d\n", getegid()); // id del grupo al que pertenece el usuario que ejecuta el archivo
  return 0;
}
