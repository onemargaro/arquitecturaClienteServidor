#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

// #define SERVER "localhost"
/**
 * Margito Sánchez Baños
 * Programa que se conecta a un servidor a
 * través de un socket
 */
int main(int argc, char *argv[])
{
  struct sockaddr_in server;
  struct hostent *sp;
  int sd;
  int n;
  char *host;
  char buf[200];

  sd = socket(AF_INET, SOCK_STREAM, 0);

  server.sin_family = AF_INET;
  server.sin_port = htons((u_short) 4567);
  sp = gethostbyname("132.248.59.6");
  memcpy(&server.sin_addr, sp->h_addr, sp->h_length);

  connect(sd, (struct sockaddr *) &server, sizeof(struct sockaddr_in));

  /*
  n = recv(sd, buf, sizeof(buf), 0);
  while (n > 0) {
    write(1, buf, n);
    n = recv(sd, buf, sizeof(buf), 0);
  }
  */
  n = 1;
  while (n > 0) {
    n = recv(sd, buf, sizeof(buf), 0);
    write(1, buf, n);
  }

  close(sd);
  exit(0);
}
