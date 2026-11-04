#include <stdio.h>
#include<pthread.h>
#include <unistd.h>
#include <sys/syscall.h>

void* tarea (void * a){
 
  printf("Hola desde e hilo, estoy en el proceso  %d \n", (int)getpid()); //(int)syscall(SYS_gettid) lo uso para obtener el id de hilo directo del sistema
   while(1);
  return NULL;
}

int main(){
 pthread_t hilo;

 printf("Soy el proceso %d \n", (int)getpid());
 int valor= pthread_create(&hilo, NULL, tarea, NULL);
 if(valor!=0){ //Validado si se creo el hilo o no
    printf("El hilo no fue creado \n");
 }else{
    printf("El hilo fue creado satisfactoriamente\n");
 }
 
 pthread_join(hilo, NULL);


 while(1);
  return 0;
}
