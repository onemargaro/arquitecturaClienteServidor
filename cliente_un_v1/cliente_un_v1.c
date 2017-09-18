#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h> //libreria para hacer uso de sockets

void lee( int df );
void leeLinea ( int df, char *cad );

/**
 * Margarito Sánchez Baños
 * proceso cliente con sockets AF_UNIX
 */

int main(int argc, char *argv[])
{
 int dfClient, longServer, resultado;
 struct sockaddr_un dirUNIXServer;
 struct sockaddr* puntSockServer;

 puntSockServer = ( struct sockaddr* ) &dirUNIXServer;
 longServer = sizeof ( dirUNIXServer );

 dfClient = socket ( AF_UNIX, SOCK_STREAM, 0 ); /* se crea un socket UNIX, bidireccional */

 dirUNIXServer.sun_family = AF_UNIX;    /* tipo de dominio server */
 strcpy ( dirUNIXServer.sun_path, "archivo1" );   /* nombre server */

 do {
   resultado = connect ( dfClient, puntSockServer, longServer );
   if ( resultado == -1 )
     sleep (1);   /* reintento */
 }
 while ( resultado == -1 );

 lee( dfClient );     /* lee el archivo1 */
 close ( dfClient );      /* cierra el socket */
 exit (0);     /* buen fin */

}

/*************     lee( df )  *****************/

void lee( int df ) {
 char cad[200];
 while ( leeLinea ( df, cad ) )      /* lee hasta fin de la entrada */
   printf ("%s\n", cad );            /* e imprime lo leido */
}


/*************   leeLinea ( df, cad )  ******************/
void leeLinea ( int df, char *cad ) {
 int n;
 do {
    n = read ( df, cad, 1 );          /* lectura de un caracter */
    printf("n=%d\n",n);
    printf("*cad=%c\n",*cad);
 }
 while ( n > 0 && (*cad)++ != EOF );   /* lee hasta NULL o fin entrada */

 return ( n > 0 );   /* devuelve falso si fin de entrada */

}

/************* fin de cliente.c ****************************/
