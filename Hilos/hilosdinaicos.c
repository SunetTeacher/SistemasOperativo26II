#include <stdio.h>
#include<pthread.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <stdlib.h>

void* tarea (void * a){
 int id=  *((int*)a);
  printf("Hola desde e hilo, estoy en el proceso  %d  y mi id de programador %d y del SO es %d\n", (int)getpid(), id, (int)syscall(SYS_gettid)); //(int)syscall(SYS_gettid) lo uso para obtener el id de hilo directo del sistema
   while(1);
  return NULL;
}

int main(){
 pthread_t *hilos;
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
