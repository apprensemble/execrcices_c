#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
//quasi copier/coller de http://www.binarytides.com/socket-programming-c-linux-tutorial/
int main (int argc, char *argv[]) {
int mon_socket;
struct sockaddr_in server;
char *message, reponse_server[2000];

mon_socket = socket(AF_INET , SOCK_STREAM , 0);

if (mon_socket == -1) {
  printf("impossible de creer ton socket de merde");

}

server.sin_addr.s_addr = inet_addr("172.17.0.41");
server.sin_family = AF_INET;
server.sin_port = htons(80);

//Connect to remote server
if (connect(mon_socket , (struct sockaddr *)&server , sizeof(server)) < 0)
{

puts("erreur de connexion");
return 1;
}

puts("connexion active");

message = "GET / HTTP 1.1 \r\n\r\n";
if (send(mon_socket , message, strlen(message) , 0) < 0)
{
  puts ("echec envoie");
  return 1;

}
puts("envoie reussi\n");

//reception
//while (recv(mon_socket, reponse_server, 200, 0) > 0) {
int n;
while ((n=read(mon_socket, reponse_server, 200))>0) {
  //printf("lu : %d\n",n);
write(1,reponse_server,n);
//return 1;
}
//puts(reponse_server);

//read(mon_socket, reponse_server, 2000);
close(mon_socket);




return 0;


}
