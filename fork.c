#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
int main () {
  printf("hello\n");
  pid_t pid;
  pid = fork();
  if (pid == 0) {
    printf("je suis le fils %d et mon pere est %d\n",getpid(),getppid());
    return 0;
  }
  else if (pid>0) {
    printf("je suis le pere %d\n",getpid());
    wait(0);
    return 0;
  }
  else {
    perror("erreur");
    exit(errno);
  }
}
