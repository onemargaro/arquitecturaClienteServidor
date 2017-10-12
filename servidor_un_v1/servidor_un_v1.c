#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 4567 //se define el puerto para aceptar solicitudes de conexión
#define QLEN 2000

int visitas = 0;

/**
 * Margarito Sánchez Baños
 * @return      0 si todo sale bien
 */
int main(int argc, char *argv[])
{
  struct sockaddr_in server;
  struct sockaddr_in client;
  struct hostent *info_client;
  int sd, td;
  int longClient;
  char buf[256];
  signal ( SIGCHLD, SIG_IGN ); /*  para no crear zombies */

  sd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

  memset((char *) &server, 0, sizeof(struct sockaddr_in));
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons((u_short) PORT);

  bind(sd, (struct sockaddr *) &server, sizeof(struct sockaddr_in));

  listen(sd, QLEN);
  longClient = sizeof(struct sockaddr_in);

  while (1) {
    td = accept(sd, (struct sockaddr *) &client, &longClient);
    if( fork() == 0 ) {
      info_client = gethostbyaddr((char *) &client.sin_addr, sizeof(struct in_addr), AF_INET);
      printf("Conectado desde %s\n", info_client->h_name);
      visitas = visitas+1;
      sprintf(buf, "Este servidor ha sido contactado %d veces\n", visitas);
      send(td, buf, strlen(buf), 0);
      close(td);
      exit(0);
    }
    else {
      close(td);
    }
  }
}
