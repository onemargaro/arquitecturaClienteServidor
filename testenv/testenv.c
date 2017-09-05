#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * Margarito Sánchez Baños
 * Programa para mostrar las funciones
 * para manipular las variables de ambiente
 * @return int estatus
 */
int main() {
  char envval[] = {"MYPATH=/usr/local/bin"}; //variable de ambiente a settear
  if(putenv(envval)) //ejecuta la instrucción para poner la variable de ambiente
    puts("putenv failed"); //si retorna un valor diferente de cero sucede un error
  else
    puts("putenv succeeded"); //si retorna el valor de 0 se ejecuto correctamente

  if(getenv("MYPATH")) //obtiene la variable de ambiente MYPATH
    printf("MYPATH=%s\n", getenv("MYPATH")); //si exixte la imprime
  else
    puts("MYPATH unassigned"); //si no existe imprime esto

  if(getenv("YOURPATH")) //obtiene la variable de ambiente YOURPATH
    printf("YOURPATH=%s\n", getenv("YOURPATH")); //si exixte la imprime
  else
    puts("YOURPATH unassigned"); //si no existe imprime esto
  exit(EXIT_SUCCESS); 
}
