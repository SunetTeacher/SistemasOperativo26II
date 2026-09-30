#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

long long factorial(int n) {
    long long fac = 1;
    for (int i = 1; i <= n; i++) fac *= i;
    printf("Factorial %d! = %lld\n", n, fac);
    return fac;
}
int  n2(int n) {
    printf("n^2 %d² = %d\n", n, n * n);
    return n*n;
    
}
void suma1an(int n) {
    long long suma = 0;
    for (int i = 1; i <= n; i++) suma += i;
    printf("Suma de 1 a %d = %lld\n", n, suma);
}

void primos(int n) {
    int total_primos = 0;
    for (int i = 2; i <= n; i++) {
        int es_primo = 1;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                es_primo = 0;
                break;
            }
        }
        if (es_primo) total_primos++;
    }
    printf("[primos] Cantidad de primos de 1 a %d = %d\n", n, total_primos);
}

void divisor(int n) {
    int divisores = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) divisores++;
    }
    printf("[divisor] Cantidad de divisores de %d = %d\n", n, divisores);
}

int main(){
  int n=4;
  int i,z,x,y;
  for(i=0; i<3; i++){
    x=fork();
    if(x==0){
        break;
    }
  }
  if(i==0){
        y=fork();
  }
  if(i==1){
        z=fork();
  }
  
  
  if (i==3){
      printf("Soy el papa general");
    }
    if(i==0 && y!=0){
      printf("Soy el proceso %d y hago la suma", (int)getpid());
    }
    if(i==0 && y==0){
      printf("Soy el proceso %d y hago la division", (int)getpid());
    }
     
    if(i==1 && z!=0){
      printf("Soy el proceso %d y hago la resta", (int)getpid());
    }
    
    if(i==1 && z==0){
      printf("Soy el proceso %d y hago la factorial", (int)getpid());
    }
    if(i==2){
           printf("Soy el proceso %d y hago la multiplicacion", (int)getpid());
    }
  //while(1);
    sleep(10);
  }

