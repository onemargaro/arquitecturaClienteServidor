#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

// #define SERVER "localhost"
#define SERVER "132.248.59.6"
#define PORT 4898
#define BLEN 128

main(int argc, char *argv[])
{
  struct sockaddr_in server;
  struct hostent *sp;
  int sd;
  int n;
  char *host;
  char buf[BLEN];

  sd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

  memset((char *) &server, 0, sizeof(struct sockaddr_in));
  server.sin_family = AF_INET;
  server.sin_port = htons((u_short) PORT);
  sp = gethostbyname(SERVER);
  memcpy(&server.sin_addr, sp->h_addr, sp->h_length);

  connect(sd, (struct sockaddr *) &server, sizeof(struct sockaddr_in));

  n = recv(sd, buf, sizeof(buf), 0);
  while (n > 0) {
    write(1, buf, n);
    n = recv(sd, buf, sizeof(buf), 0);
  }

  close(sd);
  exit(0);
}
