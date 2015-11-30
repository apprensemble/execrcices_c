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

pthread_mutex_t lock;

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

//on accepte une file de 5(5 ou 1 je ne vois pas la diff)
if(listen(ma_socket,5)<0) {
  perror("can't listen, je suis sourd\n");
  exit(errno);
}
return ma_socket;
}

creation_canal(int ma_socket,int *ta_socket,struct sockaddr_in *client) {
    int client_size = sizeof client;
    //a present on prend en charge les connexions
    *ta_socket = accept(ma_socket,(struct sockaddr *)client,&client_size);
    if (*ta_socket < 0) {
      perror("change ta socket\n");
      exit(errno);
    }
}

int ecriture_s(int ta_socket) {
  char message[TLIM];
  strcpy(message,get_message());
  //ajouter un mode debug?
  //printf("strlen message : %d\n%s\n",strlen(message),message);
  write(ta_socket,message,strlen(message));
}
int lecture_s(int ta_socket) {
  char message[TLIM];
  char garde_message[TLIM];
  int n;
  if ((n=read(ta_socket, message, TLIM))>0) strncpy(garde_message,message,n);
  else strcpy(garde_message,"pas de reponse");
  set_message(garde_message);
}

//c'est le vrai main. le coeur du service
void lancement_service(int ta_socket) {
  //int ta_socket = *(int*) t_socket;
  
  int n;
  int choix;
  choix = 1;
  char message[TLIM] = "";
  char reponse[TLIM] = "";
  char nom[20] = "";
  if ((n=read(ta_socket, message, TLIM))>0) strncpy(nom,message,n);
  else strcpy(nom,"sombre inconnu");
  banniere(nom);
  ecriture_s(ta_socket);
  while (lecture("menu.txt")) {
    ecriture_s(ta_socket);
  }
  while (choix) {
  lecture_s(ta_socket);
  sleep(1);
  if (sscanf(get_message(),"%d",&choix)>0) {
    n=0;
    switch(choix) {
      case 1 : 
	while (liste_fichiers("refs")) {
	  ecriture_s(ta_socket);
	}
	break;
      case 2 : 
	strcpy(message,"quel referentiel? ");
	set_message(message);
	ecriture_s(ta_socket);
	lecture_s(ta_socket);
	if (sscanf(get_message(),"%s",&message)>0) {
	chdir("refs");
	while ((n=lecture(message))==1) {
	  ecriture_s(ta_socket);
	}
	if (n<0) ecriture_s(ta_socket);
	chdir("..");
	}
	else {
	  ecriture_s(ta_socket);
	}
	break;
      case 3 :
	strcpy(message,"virus LOADED!!!\n");
	set_message(message);
	ecriture_s(ta_socket);
	break;
      case 4 : 
	choix = 0;
	strcpy(message,"ne me quittes pas...\n");
	set_message(message);
	ecriture_s(ta_socket);
	break;
      default :
	printf("je n'ai pas reconnu le choix\n");
	strcpy(message,"je ne comprends pas...\n");
	set_message(message);
	ecriture_s(ta_socket);
	break;
    }
  }
  else {
  while (lecture("menu.txt")) {
    ecriture_s(ta_socket);
  }

  }
  }


  //fermeture des connexions
  close(ta_socket);
  pthread_exit();
}

int main(int argc,int **argv) {
char *message, reponse_server[TLIM];
if (pthread_mutex_init(&lock,NULL)!=0) {
  perror("echec de la creation du lock \n");
  exit(1);

}


//tout en un cote serveur
struct sockaddr_in server;
def_serveur(&server);
int ma_socket = init_serveur(&server);

int i;
i=0;
//un peu fragile comme construction mais bon ca fait bcp de notions d'un coups
void connexion_individuelle(void* m_socket) {
  //cree un canal puis lance le service grace a ma_socket


  pthread_mutex_lock(&lock);
  int ma_socket = *(int*) m_socket;
  int ta_socket;
  struct sockaddr_in client;
int id;
id = pthread_self();
  printf("threadid : %d \n",id);
  creation_canal(ma_socket,&ta_socket,&client);
  //close(ma_socket);
  pthread_mutex_unlock(&lock);
  lancement_service(ta_socket);
  

}
pthread_t thread[5];
for(i=0;i<5;i++) {
 pthread_create(&thread[i], NULL, connexion_individuelle, (void*)&ma_socket);
}
for (i=0;i<5;i++) {
  printf("thread %d : %d\n",i,thread[i]);
  pthread_join(thread[i]);
}
  close(ma_socket);
  pthread_mutex_destroy(&lock);
}
