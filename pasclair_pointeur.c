#include <stdio.h>
#include <stdlib.h>
void echint(int* a,int* b) {
printf("avant a,b : %d,%d\n",*a,*b);
  int *t;
  *t=*a;
  *a=*b;
  *b=*t;
printf("apres a,b : %d,%d\n",*a,*b);
}
void echpint(int** a,int** b) {
printf("avant a,b : %d,%d\n",*a,*b);
  int **t;
  *t=*a;
  *a=*b;
  *b=*t;
printf("apres a,b : %d,%d\n",*a,*b);
}
void ech1(char** a,char** b) {
printf("avant a,b : %s,%s\n",*a,*b);
char** t;
t = malloc(0);
  *t=*a;
  *a=*b;
  *b=*t;
printf("apres a,b : %s,%s\n",*a,*b);


}
void main() {
char** tab;
char *mot;
printf("%d\n",tab);


tab = malloc(5);
printf("%d\n",tab);
tab[0] = "bonjour";
tab[1] = "hello";
mot = "test";
printf("hors avant a,b : %s,%s\n",tab[0],tab[1]);
ech1(tab,tab+1);
//ech1(mot,tab[1]);
printf("hors apres a,b : %s,%s\n",tab[0],tab[1]);
int a = 1;
int b = 2;
int* pa = &a;
int* pb = &b;
printf("pa = &a ; %d = %d\n",pa,&a);
printf("*pa = a ; %d = %d\n",*pa,a);
echpint(&pa,&pb);
printf("fin apres a,b : %d,%d\n",a,b);
printf("----------------\n\n");

printf("pa = &a ; %d = %d\n",pa,&a);
printf("*pa = a ; %d = %d\n",*pa,a);
//printf("&pa = &&a ; %d = %d\n",&pa,&&a);
}
