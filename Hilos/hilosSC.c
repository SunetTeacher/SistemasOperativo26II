#include <stdio.h>
#include<pthread.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <stdlib.h>

int numero=30;
pthread_mutex_t candado;

void* tarea (void * a){
 int id=  *((int*)a);
 while(1){
 //cerrar el candado
  printf("Hola desde el hilo %d y veo la variable numero en %d \n", id,numero); 
  numero++;
  sleep((id+2)*10);
  printf("Adios desde el hilo %d y veo la variable numero en %d \n", id,numero); 
  //abrir el candado 
}
   
  return NULL;
}

int main(){

 pthread_t *hilos;
 
 //inciializacin candado
 int * idHilos;
 int i,numHilos;
 printf("Soy el proceso %d \n", (int)getpid());
 printf("Cuantos hilos deseas ejecutr \n");
 scanf("%d", &numHilos);
 hilos=(pthread_t *)calloc(numHilos, sizeof(pthread_t));
 idHilos=(int*)calloc(numHilos, sizeof(int));
 for(i=0; i<numHilos; i++){
    idHilos[i]=i;
   int valor= pthread_create(&hilos[i], NULL, tarea, (void*)&idHilos[i]);
   if(valor!=0){ //Validado si se creo el hilo o no
      printf("El hilo no fue creado \n");
   }else{
      printf("El hilo fue creado satisfactoriamente\n");
   }
 }
 for(i=0; i<numHilos; i++){
    pthread_join(hilos[i], NULL);
}

 while(1);
  return 0;
}
