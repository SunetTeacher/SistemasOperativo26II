#include <stdio.h>
#include<pthread.h>
#include <unistd.h>
#include <sys/syscall.h>

void* tarea (void * a){
 char id= *((char*)a);
  printf("Hola desde e hilo, estoy en el proceso  %d y mi id en el Operativo es %d y mi id de la libreria es %ld y el progamador me nombro %c\n", (int)getpid(), (int)syscall(SYS_gettid), (long int)pthread_self(), id); //(int)syscall(SYS_gettid) lo uso para obtener el id de hilo directo del sistema
   while(1);
  return NULL;
}

int main(){
 pthread_t hilo,hilo2;
 char id1='A';
 char id2='B';
 printf("Soy el proceso %d y mi hilo main es :%d\n", (int)getpid(), (int)syscall(SYS_gettid));
 int valor= pthread_create(&hilo, NULL, tarea, (void*)&id1);
 if(valor!=0){ //Validado si se creo el hilo o no
    printf("El hilo no fue creado \n");
 }else{
    printf("El hilo fue creado satisfactoriamente\n");
 }
  valor= pthread_create(&hilo2, NULL, tarea, (void*)&id2);
  if(valor!=0){ //Validado si se creo el hilo o no
    printf("El hilo no fue creado \n");
 }else{
    printf("El hilo fue creado satisfactoriamente\n");
 }
 pthread_join(hilo, NULL);
 pthread_join(hilo2, NULL);
 while(1);
  return 0;
}


