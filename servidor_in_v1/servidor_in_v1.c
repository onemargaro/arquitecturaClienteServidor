#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int visitas=0;

int main(int argc, char *argv[])
{
  struct sockaddr_in server;
  struct sockaddr_in client;
  struct hostent *info_client;
  int sd, cd;
  int longClient;
  char buf[256];

  sd = socket(AF_INET, SOCK_STREAM, 0);

  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons((u_short) 4567);

  bind(sd, (struct sockaddr *) &server, sizeof(struct sockaddr_in));

  listen(sd, 5);
  printf("Levantando el servidor\n");

  while (1) {
    printf("Esperando que se conecte un cliente\n");
    longClient = sizeof(struct sockaddr_in);
    cd = accept(sd, (struct sockaddr *) &client, &longClient);

    info_client = gethostbyaddr((char *) &client.sin_addr, sizeof(struct in_addr), AF_INET);
    printf("Conectado desde %s\n", info_client->h_name);
    visitas++;
    sprintf(buf, "Este servidor ha sido contactado %d veces\n", visitas);
    send(cd, buf, strlen(buf), 0);

    close(cd);
  }
}
