#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int suma(int a, int b);
int resta(int a, int b);
int multi(int a, int b);
int division(int a, int b);
int modulo(int a, int b);

int main(){
  int i;
  int numhijos=5;
   int a=9; 
   int b=10;
  int (*pFun[numhijos])(int, int);
  pFun[0]=suma;
  pFun[1]=resta;
  pFun[2]=multi;
  pFun[3]=division;
  pFun[4]=modulo;
  
  int resultados[numhijos];
  
  for (i=0; i<5; i++){
      if(fork()==0){   //!fork()
          printf("Soy el hijo %d y mi i vale %d\n", (int)getpid(), i);
          int z=pFun[i](a, b);
          printf("Soy el hijo %d y mi resultado es vale %d\n", (int)getpid(), z);
          _exit(0);
      }
  
  }
  while(1);




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
