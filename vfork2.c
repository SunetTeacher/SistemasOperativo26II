#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    int x = 2; 
    int a=8,  b=6;
    int resultsuma, resultresta;
    printf("Soy el proceso padre %d y mi x= %d\n", (int) getpid(), x);

    if (vfork() == 0) {
        x = 5; 
      printf("Soy el proceso %d y mi padre es el proces %d y mi x= %d\n", (int)getpid(), (int)getppid(), x);
          resultsuma=a+b;
        if (vfork() == 0) {
            x = 3; 
                  printf("Soy el proceso %d y mi padre es el proces %d y mi x= %d\n", (int)getpid(), (int)getppid(), x);
              resultresta=a-b;
             sleep(15);
            _exit(0); 
        }
      
        _exit(0); 
    }
    printf("Soy el proceso padre %d y mi x= %d . los resultados son %d y %d al final\n", (int) getpid(), x, resultsuma, resultresta);
    while(1);
}
