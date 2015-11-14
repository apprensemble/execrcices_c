#include <stdio.h>
#include <stdlib.h>

int main() {
  typedef struct element {
    int cle;
    struct element * successeur;
  } element;

  typedef struct element * liste;

  liste listecons (int cle, liste succ) {
    liste teteDeListe;
    teteDeListe = (liste)malloc(sizeof(element));
    teteDeListe -> cle = cle;
    teteDeListe -> successeur = succ;
    return teteDeListe;
  }


  void afficheliste (liste L) {
    while (L != NULL) {
      printf ("%d, ",L->cle);
      L = L->successeur;
    }
    printf ("\n");
  }

  void affiche_tableau (int tab[],int taille) {
    int curseur;
    printf("tab : ");
    for (curseur=0;curseur<taille;curseur++) {
      printf ("%d ",tab[curseur]);

    }
    printf("\n");


  }


  liste a,b,c,d,e,f,g;

  g=NULL;

  f = listecons(7,g);
  e = listecons(9,f);
  d = listecons(5,e);
  c = listecons(2,d);
  b = listecons(5,c);
  a = listecons(1,b);

afficheliste (a);

int rec_val_haute (liste L) {
  int max = 0;
  while (L != NULL) {
    if (L->cle > max) {
      max = L->cle;
     }
    L = L->successeur;
  }
  return max;
}

liste tri_par_denombrement (liste L) {
  int max = rec_val_haute(L);
  int tab[max+1];
  int i = 0;
  liste a;
  a = NULL;
  while ( i<max+1) {
    tab[i++] = 0;
  }
  i=0;
  while (L != NULL) {
    i = L -> cle;
    tab[i]++;//tab[i] = tab[i]+1;
    L = L->successeur;
  }
  i=max+1;
  while (i-- > 0) { //tant que i>0; i=i-1;
    while (tab[i]-- > 0) {
      a = listecons(i,a);
    }

  }
  return a;

}

void echanger (int L[],int i,int j) {
  int tmp;
  tmp = L[i];
  L[i] = L[j];
  L[j] = tmp;
}
int partitionner (int L[],int position,int taille) {
  int x,i,j;
  x = L[position];
  i = position-1;
  j = taille+1;
  while (1) {
    do {
      j--;

    } while (L[j]>x);
    do {
      i++;

    } while (L[i]<x);
    if (i<j) {

      echanger(L,i,j);
    }
    else {
      return j;

    }

  }

}
void tri_rapide (int L[],int position,int taille) {
  int q;
  if (position < taille) {
    q = partitionner (L,position,taille);
    tri_rapide(L,position,q);
    tri_rapide(L,q+1,taille);
  }
}

void tri_par_bulle (int tab[],int taille) {
  int g,d;//pour gauche et droit
  int i; //indice
  int nbr_echange=0; // on s'arrete quand il n'y a plus d'echanges

  while (1) { //on va defiler indefiniement
    for (i=0;i<taille;i++) {
      g = tab[i];
      d = tab[i+1];
      if (g>d) {
      affiche_tableau(tab,6);
	printf("indice %d echange %d et %d\n",i,g,d);
	echanger(tab,i,i+1);
	nbr_echange++;
      }
    }
    if (nbr_echange == 0) {
	printf("fin a indice %d echange %d et %d\n",i,g,d);
	break;
    }
    else {
      affiche_tableau(tab,6);
      printf("nbr_ech %d\n",nbr_echange);
      nbr_echange = 0;
    }
  }
}




a = tri_par_denombrement(a);

afficheliste (a);

int tab[3] = {1,2,3};

affiche_tableau(tab,3);
echanger(tab,0,2);
affiche_tableau(tab,3);
tri_rapide(tab,0,2);
affiche_tableau(tab,3);

int tab2[3] = {1,2,1};
affiche_tableau(tab2,3);
tri_rapide(tab2,0,2);
affiche_tableau(tab2,3);

int tab3[6] = {1,5,2,5,9,7};
affiche_tableau(tab3,6);
tri_rapide(tab3,0,5);

affiche_tableau(tab3,6);

int tab4[6] = {1,5,2,5,9,7};
affiche_tableau(tab4,6);
tri_par_bulle(tab4,5);
affiche_tableau(tab4,6);
printf("\n\n");

int tab5[6] = {5,4,3,2,1,0};
affiche_tableau(tab5,6);
tri_par_bulle(tab5,5);
affiche_tableau(tab5,6);

}
