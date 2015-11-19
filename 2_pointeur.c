#include <stdio.h>

int main() {

  void ech1(char* a,char *b) {
    //echange de deux pointeurs
    char *t;
    printf("aff a : %s\n",a);
    t=a;
    printf("t : %s\n",t);
    a=b;
    b=t;
    printf("aff a : %s\n",a);

  }
  void ech2(char **a,char **b) {
    //echange de deux pointeurs
    char **t;
    printf("aff a : %s\n",a);
    *t=*a;
    printf("t : %s\n",t);
    *a=*b;
    *b=*t;
    printf("aff a : %s\n",a);

  }
  void echint(int *a,int *b) {
    int *t;
    t=a;
    a=b;
    b=t;

  }
  char *prems[1];
  char *deuz[1];
  prems[0] = "coucou";
  *deuz = "hello";
  printf("prems0,*deuz : %s,%s\n",prems[0],*deuz);
  ech2(prems,deuz);
  printf("ech coucou,hello : %s,%s\n",*prems,*deuz);

  //*prems == prems[0];
  

}
