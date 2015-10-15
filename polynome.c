#include <stdio.h>
#include <stdlib.h>

int main () {
  typedef struct monome {
    int coeff;
    int degre;
    struct monome * monome_suivant;
  } monome;

  typedef struct monome * polynome;

  polynome polynomeconstructeur (int c, int d, polynome P) {
    polynome Q;
    Q = (polynome)malloc(sizeof(monome));
    Q-> coeff = c;
    Q-> degre = d;
    Q-> monome_suivant = P;
    printf ("je construis %d %d %d\n",Q->coeff,Q->degre,Q->monome_suivant);
    return Q;
  }

  int degre (polynome P) {
    int deg = -1;
    polynome iterateur = P;

    while (iterateur) {
      printf ("%d %d %d, ",iterateur->coeff,iterateur->degre,iterateur->monome_suivant);
      if (iterateur->degre > deg) {
	deg = iterateur->degre;
      }
	iterateur = iterateur->monome_suivant;


    }
    return deg;

  }

  int degreR (polynome P) {
    int deg = -1;

    if (P) {
      printf ("%d %d %d, ",P->coeff,P->degre,P->monome_suivant);
      deg = degreR(P->monome_suivant);
      if (P->degre > deg) {
	deg = P->degre;
      }
      return deg;
    }


  }

  /* que fait cette fonction? */
  polynome copyPolynome(polynome P) {
    polynome C,S; //Courant,Suivant
    int i = 0;
    while (P != NULL) {
      if (i == 1) {
	S = C->monome_suivant = polynomeconstructeur(P->coeff,P->degre,NULL);
	//S = C->monome_suivant;
      }
      else if (i==0) {
	C = polynomeconstructeur(P->coeff,P->degre,NULL);
      }
      else {
	S = S->monome_suivant = polynomeconstructeur(P->coeff,P->degre,NULL);
	//S = S->monome_suivant;
      }
      i++;
	P = P->monome_suivant;
    }
    return C;
  }

  polynome copyPolynomeR(polynome P) {
    polynome Q;

    if (P != NULL) {
      Q = polynomeconstructeur(P->coeff,P->degre,copyPolynomeR(P->monome_suivant));
    }
    else {
      Q = NULL;
    }
    return Q;
  }

  polynome M,N,O,P,Q,R,A,B,C,D;
  int mon_deg;

  N = polynomeconstructeur(2,4,NULL);
  M = polynomeconstructeur(1,2,N);
  O = polynomeconstructeur(3,6,M);
  P = polynomeconstructeur(4,1,O);
  A = polynomeconstructeur(3,12,P);
  B = polynomeconstructeur(5,14,A);
  C = polynomeconstructeur(3,16,B);
  D = polynomeconstructeur(4,10,C);

R = copyPolynome(D);
Q = copyPolynomeR(D);

  printf ("\nplus haut degre D : %d\n",degre(D));
  printf ("\nplus haut degre version Recursive  D : %d\n\n\n",degreR(D));
  printf ("\nplus haut degre Q : %d\n",degre(Q));
  printf ("\nplus haut degre version Recursive  Q : %d\n\n\n",degreR(Q));
  printf ("\nplus haut degre R : %d\n",degre(R));
  printf ("\nplus haut degre version Recursive  R : %d\n",degreR(R));


}
