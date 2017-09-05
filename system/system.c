#include <stdlib.h>
/**
 * Margarito Sánchez Baños
 * Returna el entero estatus del comando ejecutado
 * @return int a interpretar por la shell
 */
int main()
{
  int return_value; //declarando un entero
  return_value = system("ls -l /"); // ejecuta hasta terminar con system y guarda el estatus en return_value
  return return_value;
}
