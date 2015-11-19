#include <stdio.h>
#include <stdlib.h>
int main (int argc,char **argv) {
  int accueil(char *nom) {
    printf("Bienvenue %s\n",nom); 
    printf("---------\n\n"); 
  }
  int menu() {
   printf("menu : \n"); 
   printf("1.liste des referentiels\n"); 
   printf("2.contenu d'un referentiel\n"); 
   printf("3.telechargement d'un referentiel\n"); 
   printf("4.quitter\n");
  }
  void clean_stdin() {
    int c;
    while(c=getchar()!='\n');
  }
  int choix() {
    int c;
    c=0;
    if (scanf("%d",&c)==1) ;
    else c=0;
    clean_stdin();
    return c;
  }

  accueil(argv[1]);
  menu();
  int c =1;
  while(c!=4) {
    c=choix();
    if (c>0 && c<4)
    printf("votre choix est : %d\n",c);
    else if (c == 4) printf("vous souhaitez quitter?OK!\n");
    else {
      printf("je n'ai pas su interpreter votre choix\n");
    }
  }
}
