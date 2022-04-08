#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

void doprocessing (int sock);
int empty(char* buf);

int main( int argc, char *argv[] ) {
   int sockfd, newsockfd, portno;
   socklen_t  clilen;
   char buffer[256];
   struct sockaddr_in serv_addr;
   struct sockaddr  cli_addr;
   int n, pid;

   /* First call to socket() function */
   sockfd = socket(AF_INET, SOCK_STREAM, 0);

   if (sockfd < 0) {
      perror("ERROR opening socket");
      exit(1);
   }

   /* Initialize socket structure */
   bzero((char *) &serv_addr, sizeof(serv_addr));
   portno = 23227;

   serv_addr.sin_family = AF_INET;
   serv_addr.sin_addr.s_addr = INADDR_ANY;
   serv_addr.sin_port = htons(portno);
   /* Now bind the host address using bind() call.*/
   if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
      perror("ERROR on binding");
      exit(1);
   }

   /* Now start listening for the clients, here
    * process will go in sleep mode and will wait
    * for the incoming connection
    */
   if(listen(sockfd, 5))
   {
      perror("ERROR on listening");
      exit(1);
   }

   clilen = sizeof(cli_addr);
   while (1) {
      newsockfd = accept(sockfd,  &cli_addr, &clilen);
      if (newsockfd < 0) {
         perror("ERROR on accept");
         exit(1);
      }

      /* Create child process */
      pid = fork();
      if (pid < 0) 
      {
         perror("ERROR on fork");
         exit(1);
      }

      if (pid == 0) 
      {
         /* This is the child  process */
         close(sockfd);
         doprocessing(newsockfd);
         exit(0);
      }
      else 
      {
         /* this is the parent process */
         close(newsockfd);
         listen(sockfd,5);
      }

   } /* end of while */
}

int empty(char buf[])
{
  int flag = 1;
  for(int i = 0; i < strlen(buf); ++i)
    flag = flag && isspace(buf[i]);

  return flag;
}


void doprocessing (int sock) {
   int n=0;
   char buffer[256];
   n = write(sock,"\nWhat's up?: ",13);
   while (1)
   {
   bzero(buffer,256);
   n = read(sock,buffer,255);
   if (n < 0) {
      perror("ERROR reading from socket");
      exit(1);
   }

   if (!empty(buffer) && n>0)
   {
     char out[256];
     int printed = snprintf(out,256,"\nHere is the message %d: %s",n,buffer);
     write(1,out,printed);
     n = write(sock,"Tell me more: ",14);
     sync();
   }

   if (n < 0) {
      perror("ERROR writing to socket");
      exit(1);
   }
   }
}
