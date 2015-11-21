#include "menu.h"
#include "ls.h"
int liste_referentiels(int *fd) {
  liste_fichiers(".",fd);

}
int action_referentiel(int choix) {
  //permettre le telechargement ou la lecture
  char nom_fichier[256];
  printf("quel fichier souhaitez vous %s%s",(choix==2) ? "lire" : "telecharger","? ");
  scanf("%s",&nom_fichier);
  printf("-------------------\n");
  printf("%s\n",nom_fichier);
  printf("-------------------\n");
  switch (choix) {
    case 2 : 
  lecture(nom_fichier);
  printf("-------------------\n\n");
  break;
    case 3 : 
  printf("Virus loaded!!\n");
  break;
    default :
  printf("je n'ai pas compris votre choix\n");
  break;
  }

}


int main (int argc,char **argv) {
  int fd = 1;
  banniere(argv[1]);
  int c =1;
  char *message[200];
  while(c!=4) {
    menu();
    switch (c=choix()) {
      case 1 :
	liste_referentiels(&fd);
	break;
      case 2 :
	action_referentiel(c);
	break;
      case 3 :
	action_referentiel(c);
	break;
      case 4 :
	printf("byebye\n");
	return 0;
	break;
      default : 
	printf("je n'ai pas compris votre choix\n");
	break;
    }
}
return 0;

}
