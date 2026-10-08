#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
int i,a,b, suma;
 printf("El total de argumentos es %d\n", argc);
  for(i=0; i<argc; i++){
        printf("Argumento[%d]=%s\n", i, argv[i]);
  }

   printf("Soy el programa suma y mi id es %d y mi padre es %d", (int)getpid(), (int)getppid());
    a=atoi(argv[1]);
    b=atoi(argv[2]);
    suma=a+b;
    printf("La suma es %d+%d=%d\n", a,b,suma);
  while(1);
}
