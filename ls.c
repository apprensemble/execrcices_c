#include "ls.h"

int lecture(char *nom_de_fichier) {
  char tampax[TLIM];
  int n;
  int fd;
  if ((fd = open(nom_de_fichier,O_RDONLY,0)) == -1)
    perror("le fichier n'a pu etre ouvert");

  while ((n = read(fd,tampax,TLIM)) > 0) 
    write(1, tampax, n);
  close(fd);
  return 0;
}
int liste_fichiers(char *rep,int *fd) {
  //ajout pour pouvoir ecrire dans la socket
if (fd == NULL) {
  *fd = 1;
}

  DIR *dir_fd;
  struct dirent *dp; //structure decrite dans :Man 3 readdir
  char nom[1024];
  char message[2048];

  if ((dir_fd = opendir(rep)) == NULL) {
    strcat(message,"impossible d'ouvrir le rep ");
    strcat(message,rep);
    strcat(message,"\n");
    write(2,message,strlen(message));
    return 0;
  }
  while ((dp = readdir(dir_fd)) != NULL) {
    if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0) 
      continue;
    if (strlen(rep)+strlen(dp->d_name)+2 > sizeof(nom))
      fprintf(stderr, "nom %s/%s trop long pour etre lu\n", rep, dp->d_name);
    else { 
      sprintf(nom, "%s", dp->d_name);
      strcat(nom,"\n");
      write(*fd,nom,strlen(nom));
    }
  }
}
