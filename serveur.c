//pour les sockets
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

//pour le fork
#include <unistd.h>
#include <sys/wait.h>


//perso
#include "menu.h"
#include "ls.h"
#include "gestion_message.h"

//definition du serveur (cad adresse/port d'ecoute)
int def_serveur(struct sockaddr_in *server) {

//definition de la cible
server->sin_addr.s_addr = htonl(INADDR_ANY);
server->sin_family = AF_INET;
server->sin_port = htons(2080);

return 0;
}

//creation socket qu'on attache au serveur
int init_serveur(struct sockaddr_in *server) { 

//creation de la socket
int ma_socket;
ma_socket = socket(AF_INET , SOCK_STREAM , 0);

if (ma_socket == -1) {
  perror("impossible de creer ton socket de merde\n");
  exit(errno);

  }

//il faut a present rattacher la socket au couple adresse/port defini dans la struct server
if (bind(ma_socket,(struct sockaddr *) server,sizeof *server) <0) {
  perror("impossible de joindre les deux bouts\n");
  exit(errno);
}

//on accepte une file de 5
if(listen(ma_socket,5)<0) {
  perror("can't listen, je suis sourd\n");
  exit(errno);
}
return ma_socket;
}

creation_canal(int ma_socket,int *ta_socket,struct sockaddr_in *client) {
  pid_t pid = fork();
  if (pid == 0) {
    int client_size = sizeof client;
    //a present on prend en charge les connexions
    *ta_socket = accept(ma_socket,(struct sockaddr *)client,&client_size);
    if (*ta_socket < 0) {
      perror("change ta socket\n");
      exit(errno);
    }
  }
  else if (pid == -1) {
    perror("impossible de forker\n");
    exit(errno);
  }
  return pid;
}

//c'est le vrai main. le coeur du service
int lancement_service(int ma_socket,int ta_socket,struct sockaddr_in *client) {
  int n;
  char message[256];
  char nom[20];
  if ((n=read(ta_socket, message, 256))>0) strcpy(nom,message);
  else strcpy(nom,"sombre inconnu");
  strcpy(message,"bonjour ");
  strcat(message,nom);
  write(ta_socket,message,strlen(message));
  menu;
  strcpy(message,get_message());
  write(ta_socket,message,strlen(message));
  //while ((n=read(ta_socket, message, 256))>0) {
  //printf("%s",message);
  //write(ta_socket,message,strlen(message));
  //}
  //fermeture des connexions
  close(ta_socket);

}

int main(int argc,int **argv) {
char *message, reponse_server[2000];

//socket plus structure client
int ta_socket;
struct sockaddr_in client;

//tout en un cote serveur
struct sockaddr_in server;
def_serveur(&server);
int ma_socket = init_serveur(&server);

int i;
int pid;

//un peu fragile comme construction mais bon ca fait bcp de notions d'un coups
for (i=5;i>0;i--) {
  pid = creation_canal(ma_socket,&ta_socket,&client);
  if (pid == 0) {
    lancement_service(ma_socket,ta_socket,&client);
  }
}
if (pid>0) {
  wait(0);
  close(ma_socket);
}




}
