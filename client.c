#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
//quasi copier/coller de http://www.binarytides.com/socket-programming-c-linux-tutorial/
int main (int argc, char *argv[]) {
int ma_socket;
struct sockaddr_in server;
char *message, reponse_server[2000];

//definition de la cible
server.sin_addr.s_addr = inet_addr("127.0.0.1");
server.sin_family = AF_INET;
server.sin_port = htons(2080);

//creation de la socket
ma_socket = socket(AF_INET , SOCK_STREAM , 0);

if (ma_socket == -1) {
  printf("impossible de creer ton socket de merde");

}

//connexion vers le serveur distant
if (connect(ma_socket , (struct sockaddr *)&server , sizeof(server)) < 0)
{

puts("erreur de connexion");
return 1;
}

puts("connexion active");
//envoie d'une requete HTTP GET
if (argv[1] == NULL) {
  message = "JAMES KIRK";
}
  else message=argv[1];
if (send(ma_socket , message, strlen(message) , 0) < 0)
{
  puts ("echec envoie");
  return 1;

}
puts("envoie reussi\n");

//reception du resultat de la requete

int n;
while ((n=read(ma_socket, reponse_server, 2000))>0) {
  //printf("lu : %d\n",n);
write(1,reponse_server,n);
}

close(ma_socket);

return 0;

}
