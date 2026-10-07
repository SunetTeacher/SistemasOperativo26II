#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int suma(int a, int b);
int resta(int a, int b);
int multi(int a, int b);
int division(int a, int b);
int modulo(int a, int b);
int incognita (int a, int z);

int main(){
 int x=8, y=9;
  int (*ap) (int, int);
 printf("Soy main  y mi direccion es %p  y mi valor es %p\n", &main, main);
  printf("Soy suma  y mi direccion es %p  y mi valor es %p\n", &suma, suma);
  ap= suma;
  printf("El valor de ap es %p y vive en un %p\n", ap, &ap); 
  printf("invocando a suma de forma normal");
  int r= suma(x,y);
  printf("El resultado de la suma:%d\n", r);
    printf("invocando a suma desde un apuntador a funcion");
  int z= ap(x,y);
  printf("El resultado de la suma por el apuntador es :%d\n", z);

}


int suma(int a, int b){
  return a+b;
}
int resta(int a, int b){
  return a-b;
}
int multi(int a, int b){
  return a*b;
}
int division(int a, int b){
  return a/b;
}
int modulo(int a, int b){
  return a%b;
}
