#include <stdio.h>
#include <stdlib.h>

int main () {
  //dans cet exemple la valeur du premier pointeur est ecrase par la valeur[3] du deuxieme pointeur
  //le 3e pointeur ecrase la valeur 4 du deuxieme pointeur.
  //il est possible que le resultat soit different sur votre machine mais c'est pour montrer que le compilateur ne protege pas du debordement et que les effets de bords sont pervers.
  //Il concerne tt le programme et pas seulement le pointeur mal utilise.
  char *mot;
  char *mot2[2];
  char *mot3;
mot = "un";
mot2[0] = "deux";
mot2[1] = "trois";
mot2[2] = "quatre";
mot2[3] = "cinq";
mot3 = "six";
printf("mot 1 : %s\n",mot);
printf("mot 2 : %s\n",mot2[0]);
printf("mot 2 : %s\n",mot2[1]);
printf("mot 2 : %s\n",mot2[2]);
printf("mot 2 : %s\n",mot2[3]);
printf("mot 3 : %s\n",mot3);
printf("taille : %d\n",sizeof mot2);
}
