#include <string.h> //pour strlen
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/types.h>
#define TLIM 1000 //limite du tampax

int main () {
  int lecture(char *nom_de_fichier) {
  char tampax[TLIM];
  int n;
  int fd;
  if ((fd = open(nom_de_fichier,O_RDONLY,0)) == -1)
    error("le fichier n'a pu etre ouvert");

  while ((n = read(fd, tampax,TLIM)) > 0) 
    write(1, tampax, n);
  close(fd);
  return 0;
  }
  int liste_fichiers(char *rep) {
    DIR *dir_fd;
    struct dirent *dp; //structure decrite dans :Man 3 readdir
    char nom[1024];

    if ((dir_fd = opendir(rep)) == NULL) {
      fprintf(stderr, "impossible d'ouvrir le rep %s\n",rep);
      return;
    }
    while ((dp = readdir(dir_fd)) != NULL) {
      if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0) 
	continue;
      if (strlen(rep)+strlen(dp->d_name)+2 > sizeof(nom))
	fprintf(stderr, "nom %s/%s trop long pour etre lu", rep, dp->d_name);
      else { 
	sprintf(nom, "%s", dp->d_name);
	printf("%s\n",nom);

      }
    }
  }
  lecture("message.txt");
  liste_fichiers(".");
  return 0;
}
