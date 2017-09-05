#include <stdio.h>
#include <unistd.h>
/**
 * Margarito Sánchez Baños
 * El programa comprueba el uso del fork al regresar el id del proceso hijo al proceso padre
 * tomando caminos diferentes por el uso de las sentencias if-else
 * @return 0 si la ejecución fue correcta
 */
int main ()
{
    pid_t id_hijo; //declara variable de tipo estructura pid_t
    printf( "1: el id del proceso main es %d\n", getpid() ); //imprime el id del proceso principal
    id_hijo = fork (); // divide el proceso, retornando al padre el id del proceso hijo y al hijo un 0
    printf( "2: Este printf saldra duplicado\n"); // se ejecuta por el padre y por el hijo
    printf( "3: El id del proceso hijo es %d\n", id_hijo ); // se ejecuta por el padre y por el hijo, pero solo el padre imprimira correctamente
    if( id_hijo != 0 )
    { //ejecución del proceso padre
        printf( "\nPADRE:proceso main con id %d\n", getpid());
        printf( "PADRE:id del hijo es %d\n", id_hijo );
        printf( "PADRE:id del padre del padre %d\n",getppid());
    }
    else
    {
      //ejecución del proceso hijo
        printf( "\nHIJO:proceso id %d\n", getpid() );
        printf( "HIJO:id del hijo es %d\n", id_hijo );
        printf( "HIJO:id del padre es %d\n", getppid() );
    }
    return 0;
}
