#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NBR_ACTION 4 //c'est le nombre d'actions plus 1 car je commence a 1

int main (int argc, char **argv) {
  //dans cet exemple la valeur du premier pointeur est ecrase par la valeur[3] du deuxieme pointeur
  //le 3e pointeur ecrase la valeur 4 du deuxieme pointeur.
  //il est possible que le resultat soit different sur votre machine mais c'est pour montrer que le compilateur ne protege pas du debordement et que les effets de bords sont pervers.
  //Il concerne tt le programme et pas seulement le pointeur mal utilise.
  int *ordre;
  char *nomFichier;
  char *nomDossier;
  char *url;

  int aide() {
    printf("programme d'essai de dev en C\n");
    printf("\n");
    printf("usage : \n");
    printf("\n");
    printf("[pointeur]\n\n");
    printf("--errPtr pour un exemple d'erreur de pointeur[1]\n\n");
    printf("[arguments en ligne de commande]\n\n");
    printf("--affArgv pour afficher les arguments[0]\n\n");
    printf("[Flux D'E/S]\n\n");
    printf("--lecture nomfichier pour afficher le contenu d'un fichier[3]\n");
    printf("--lectured nomdossier pour afficher le contenu d'un dossier[4]\n\n");
    printf("[socket]\n\n");
    printf("--cnxweb url pour afficher une page web[5]\n\n");
    printf("\n");
     

  }
  int erreur_pointeur() {
    char *mot;
    char *mot2[2];
    char *mot3;
    //char mot[3] = "un";
    mot = "un";
    //mot[0] = 'o';
    //mot[1] = 'o';
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

  int execute_ordre(int argc) {
    int i;
      if (*(ordre+1) == 1) {
	//argv = (argv-1);
	for (i=argc;i>0;--i) {
	  printf((i>1) ? "%s " : "%s\n",*++argv);
      //printf("%s%s",*++argv,(argc>1) ? " " : "\n");
      //c'est l'inverse et ca fonctionne aussi
	  

	}




    }

    

  }
  // erreur a ajouter dans un menu...
  //erreur_pointeur();
  int init_ordre(int argc) {
    int i;
    for (i=0;i<NBR_ACTION;i++) *ordre++ = 0;
    i=0;
    while (--argc > 0) {
      i++;

      if (strcmp(*(argv+i),"--errPtr") == 0) { 
	*(ordre+2) = 1;
      }
      else if (strcmp(*(argv+i), "--affArgv")==0) {
	*(ordre+1) = 1;
      }
      else if (strcmp(*(argv+i), "--lecture")==0) {
	*(ordre+3) = 1;
	i++;
	nomFichier=*(argv+i);
	--argc;
      }
      else {
	printf("choix errone : %s\n",*(argv+i));
	aide();
//	return 1;
      }
    }
  }
  //pour un mini exemple| a retirer
  erreur_pointeur();
  return 0;

  int init_ordre2(int argc) {
    int i;
    int n = argc-1;
    char **argv2;
    argv2 = &argv;
    for (i=0;i<NBR_ACTION;i++) *ordre++ = 0;
    i=0;
    while (--argc > 0) {
      (*argv)++;

      if (strcmp(*argv,"--errPtr") == 0) { 
	*(ordre+2) = 1;
      }
      else if (strcmp(*argv, "--affArgv")==0) {
	*(ordre+1) = 1;
      }
      else if (strcmp(*argv, "--lecture")==0) {
	*(ordre+3) = 1;
	*argv++;
	nomFichier=*argv;
	--argc;
      }
      else {
	printf("choix errone : %s\n",*argv);
	//aide();
//	return 1;
      }
    }
    //argv = argv2; //OK
    //argv = &argv[-1]; //OK avec 1 arg
    //argv = &argv[-n]; //OK avec n args
    //argv = (argv-n); //OK avec n args
    printf("fin %s\n",*argv);
  }
	printf("helo %d %s\n",argc,*(argv+1));
	argv=argv+1;
	printf("helo %d %s\n",argc,*(argv+0));
	argv--;
	printf("helo %d %s\n",argc,*(argv+1));
  init_ordre2(argc);
	printf("helo %d %s\n",argc,*(argv+1));
  //execute_ordre(argc);
  //argv = &argv[1];
  return 0;
}
