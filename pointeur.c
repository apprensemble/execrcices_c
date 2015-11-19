#include <stdio.h>
#include <string.h>
int main() {
  int *pi;
  int i;
  int *pj;
  int *pt;
  int j;
  i=3;
  j=2;
  pi = &i;
  pj = &j;

  void affiche(int i, int j) {
    printf("i : %d - j : %d\n",i,j);

  }
  void affiche2(char f[],char *i, char *j) {
    printf("%s : %s,%s\n",f,i,j);

  }
  void affiche3(char *a,char *b,int i, int j) {
    printf("%s : %d - %s : %d\n",a,i,b,j);

  }
  affiche(i,j);


  printf("affichage pi et pj\n");
  affiche(*pi,*pj);
  printf("changement de i vers 4 et affichage des pointeurs\n");
  i=4;
  affiche(*pi,*pj);
  
  printf("cette fois *pi a 3");
  *pi = 3;
  affiche(*pi,*pj);

  printf("un pointeur tempo pt dans lequel je mets l'adresse *pi\n");
  //pt = &(*pi);
  pt = pi;
  affiche(*pt,*pj);
  printf("je rechange i vers 4 et affiche *pt\n");
  i = 4;
  affiche(*pt,*pj);

  printf("on affiche *pi");
  affiche(*pi,*pj);


  printf("a present les pointeurs de pointeurs prenons *tabS[3] et *tabD[3]\n");
  char *tabS[3];
  char *tabD[3];
  char **tabT;

  *tabS = "un ";
  *(tabS+1) = "deux";
  *(tabS+2) = "trois";
  *tabD = "1 ";
  *(tabD+1) = "2 ";
  *(tabD+2) = "3 ";

  *tabD = *tabS;
  printf("tabD = 1 ,2 ,3  && tabS = un ,deux ,trois \n");
  printf("j'ai copie la valeur pointe par tabS dans tabD : *tabD = *tabS\n");
  affiche2("tabD,tabS",*tabD,*tabS);
  affiche2("*tabD,*(tabS+1)",*tabD,*(tabS+1));
  affiche2("*(tabD+1),*(tabS+1)",*(tabD+1),*(tabS+1));
  printf("la valeur 0 est bien copier mais pas les suivantes");
  
  printf("il faut copier les elements du tableau 1 par 1\n");
  
  printf("sachant que l'on peut naviguer d'une valeur a l'autre arithmetiquement (++), ");
  printf("on doit pouvoir transmettre la valeur a une variable...\n");

  printf("prenons char **tabT\n");
  printf("essayons de le faire pointer sur tabD[0]\n");
  //tabT = &tabD[0];
  tabT = tabD; //c'est equivalent a ce qu'il y a au dessus
  affiche2("tabT[0],tabD[0]",tabT[0],tabD[0]);
  affiche2("tabT[1],tabD[1]",tabT[1],tabD[1]);
  affiche2("tabT[2],tabD[2]",tabT[2],tabD[2]);
  printf("tabT = &tabD[0]; fonctionne\n");

  printf("pour s'en assurer essayons de changer la valeur de tabT[1] en dos \n");
  tabT[1] = "dos ";
  affiche2("tabT[1],tabD[1]",tabT[1],tabD[1]);
  printf("puisque tt cela fonctionne essayons a present d'incrementer tabD deux fois\n");
  printf("puis d'assigner a tabD l'adresse de &tabD[-2]\n");
  printf("oups pas possible car tabD est un tableau et ce genre de manip n'est possible qu'avec un pointeur...\n");
  printf("faisons le avec tabT dans ce cas :-)\n");
  tabT++;
  tabT++;
  affiche2("tabT[0],tabD[0]",tabT[0],tabD[0]);
  printf("a presont assignons a tabT l'adresse tabT[-2]\n");
  tabT = tabT-2;
  affiche2("tabT[0],tabD[0]",tabT[0],tabD[0]);
  
  printf("OK je pense avoir compris ! passons a l'utilisation des pointeurs dans les fonctions\n");
  printf("une fonction ech1(int a,int b) sans pointeur a=1 b=2\n");
  void ech1(int a,int b) {
    int t;
    t=a;
    a=b;
    b=t;
  }
  printf("une fonction ech2(int *a,int *b) avec pointeur a=1 b=2\n");
  void ech2(int *a,int *b) {
    int t;
    t=*a;
    *a=*b;
    *b=t;
  }
  void ech3(char *a,char *b) {
    
     // printf("a : %s",a);
    printf("taille a : %d,taille b : %d",strlen(a),strlen(b));
    int sc;
    sc = strlen(a);
    char c[sc];
    char *t;
    t = c;
    int i;
    i=0;

    while (*t++=*a++) printf("%d",++i);
a = (a-i-1);
t = (t-i-1);
   printf("int : %s \n",a) ;
   i=0;
   while (*a++=*b++) printf("%d",++i);
a = (a-i-1);
b = (b-i-1);
   printf("int : %s \n",a) ;
i=0;
   while (*b++=*t++) printf("%d",++i);
b = (b-i-1);
t = (t-i-1);
printf("fin : %s\n",b);
  }
  int a,b;
  a=1;
  b=2;
  printf("depart :\n");
  affiche3("a","b",a,b);
  printf("a present appellons la fonction ech1(a,b)\n");
  ech1(a,b);
  affiche3("a","b",a,b);
  printf("a present appellons la fonction ech2(&a,&b)\n");
  ech2(&a,&b);
  affiche3("a","b",a,b);
  printf("creons un pointeur a et b tel que pa et pb\n");
  int *pa;
  int *pb;
  pb = &b;
  pa = &a;
  printf("a present appellons la fonction ech1(*pa,*pb)\n");
  printf("avant : ");
  affiche3("*pa","*pb",*pa,*pb);
  ech1(*pa,*pb);
  printf("apres : ");
  affiche3("*pa","*pb",*pa,*pb);

  printf("a present appellons la fonction ech2(pa,pb)\n");
  printf("avant : ");
  affiche3("*pa","*pb",*pa,*pb);
  ech2(pa,pb);
  printf("apres : ");
  affiche3("*pa","*pb",*pa,*pb);
  printf("pour finir on va inverser tabD et tabS par l'intermediaire de *pD et *pS\n");
  char **pD;
  char **pS;
  pD = tabD;
  pS = tabS;
  affiche2("*pD,*pS",*(pD+1),*(pS+1));
  //ech3(pD[1],pS[1]);
//  affiche2("*pD,*pS",*(pD+1),*(pS+1));


  char n[] = "dos ";
  char v[] = "deux";

  ech3(n,v);
  affiche2("n[]=dos,v[]=deux",n,v);
  printf("on ne peut pas faire d'echange via pointeur...ou alors je ne sais pas le faire\n");
  printf("il faut utiliser les tableaux...choc\n");
//  ech3(pD[1],pS[1]);



}
