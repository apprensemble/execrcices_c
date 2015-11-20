#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
int banniere(char *nom) {
  if (nom == NULL) {
    nom = "sombre inconnu";

  }
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
  printf("choix : ");
  if (scanf("%d",&c)==1) ;
  else c=0;
  clean_stdin();
  return c;
}
