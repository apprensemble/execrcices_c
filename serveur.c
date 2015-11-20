#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
int main(int argc,int **argv) {
//definition de variable necessaire a l'utilisation de la socket serveur
int ma_socket;
struct sockaddr_in server;
char *message, reponse_server[2000];

//idem pour le client
int ta_socket;
struct sockaddr_in client;


//definition de la cible
server.sin_addr.s_addr = htonl(INADDR_ANY);
server.sin_family = AF_INET;
server.sin_port = htons(2080);

//creation de la socket
ma_socket = socket(AF_INET , SOCK_STREAM , 0);

if (ma_socket == -1) {
  perror("impossible de creer ton socket de merde\n");
  exit(errno);

  }

//il faut a present rattacher la socket au couple adresse/port defini dans la struct server
if (bind(ma_socket,(struct sockaddr *) &server,sizeof server) <0) {
  perror("impossible de joindre les deux bouts\n");
  exit(errno);
}

//on accepte une file de 5
if(listen(ma_socket,5)<0) {
  perror("can't listen, je suis sourd\n");
  exit(errno);
}
int client_size = sizeof client;
//a present on prend en charge les connexions
ta_socket = accept(ma_socket,(struct sockaddr *)&client,&client_size);
if (ta_socket < 0) {
  perror("change ta socket\n");
  exit(errno);

}

int n;
while ((n=read(ta_socket, reponse_server, 1))>0) {
  //printf("lu : %d\n",n);
write(1,reponse_server,n);
}
//fermeture des connexions
close(client);
close(server);






}
