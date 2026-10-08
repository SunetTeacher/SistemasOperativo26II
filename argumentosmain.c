#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
  int i;
  int a,b,suma;
  printf("El total de argumentos es %d\n", argc);
  for(i=0; i<argc; i++){
        printf("Argumento[%d]=%s\n", i, argv[i]);
  }
    a=atoi(argv[1]);
    b=atoi(argv[2]);
    suma=a+b;
    printf("La suma es %d+%d=%d\n", a,b,suma);
    printf("El caracter ingresado es  %c", argv[3][0]);
}
