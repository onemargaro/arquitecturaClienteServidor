#include <stdio.h>
#include <unistd.h>
/**
 * Margarito Sánchez Baños
 * El programa comprueba el uso del fork al regresar el id del proceso hijo al proceso padre
 * @return 0 si la ejecución fue correcta
 */
int main ()
{
    pid_t id_hijo; //declara una estrutura de tipo pid_t
    printf( "1: el id del proceso main es %d\n", getpid() ); //imprime le id del proceso actual
    id_hijo = fork (); // divide el proceso y solo retorna el valor del id del proceso hijo al padre
    printf( "2: Este printf saldra duplicado\n"); //esto se ejecuta tanto por el padre como con el hijo
    printf( "3: El id del proceso hijo es %d\n", id_hijo ); //esto se ejecuta tanto por el padre como con el hijo, pero solo el padre lo imprime correctamente
    return 0;
}
