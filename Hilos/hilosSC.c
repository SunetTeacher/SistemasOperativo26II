#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/syscall.h>

int numero = 30;
pthread_mutex_t candado;

void* tarea (void *a){
  int id = *((int *)a);
  while(1){
    // ======================= Seccion critica =======================
      // Cerramos candado
    pthread_mutex_lock(&candado);  
    printf("Hola desde el hilo %d y veo la variable numero en %d\n",id, numero);
    numero++;
    printf("Adios desde el hilo %d y veo la variable numero en %d\n",id, numero);
    //sleep((id + 1) * 2); 
    // Abrimos candado
    pthread_mutex_unlock(&candado); 
    sleep((id + 1) * 2); 
    // ======================= Seccion critica =======================
  }
  return NULL;
}

int main(){
  // Main inicializa el candado
  pthread_mutex_init(&candado, NULL);
  pthread_t *hilos;
  int * idHilos;  //Para hacer un arrego dinamico
  int i, numHilos, valor;
  
  printf("Soy el proceso %d\n", getpid());
  printf("Cuantos hilos deseas ejecutar: ");
  scanf("%d", &numHilos);
  // CALLOC -> Genera memoria de formagenerica para nuestros hilos
  hilos = (pthread_t *)calloc(numHilos, sizeof(pthread_t));
  // Asignamos el tamaño de memoria en idHilos para generar el arreglo
  idHilos = (int*)calloc(numHilos, sizeof(int));
  
  // Creamos los hilos
  for(i = 0; i < numHilos; i++){
    idHilos[i] = i;
    valor = pthread_create(&hilos[i], NULL, tarea, (void*)&idHilos[i]);
    if(valor != 0){
      printf("El hilo no fue creado...\n");
    } else {
      printf("El hilo fue creado satisfactoriamente...\n");
    }
  }
  
  // Esperamos los hilos
  for(i = 0; i < numHilos; i++){
    pthread_join(hilos[i], NULL);
  }
  
  while(1);
  return 0;
}


