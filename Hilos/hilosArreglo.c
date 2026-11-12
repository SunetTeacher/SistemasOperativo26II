#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/syscall.h>
#include<time.h>

int hiloElegido;
int * arregloDatos;
int subsuma[2];
int total=0;
pthread_barrier_t barrera;
void imprimeaArreglo(int tam);
void llenaArreglo (int tam);

void* tarea (void *a);

int sumaArreglo(int inicio, int fin);

int main(){
srand(time(NULL));

int N=2;
  int datosHilo1[4];
  int datosHilo2[4];
     pthread_t hilos[2];
  
    int totalDatos;
    int elegido=rand()%2;
    printf("De que tamaño quieres tu arreglo: \n");
    scanf("%d", &totalDatos);
     pthread_barrier_init(&barrera,NULL, N); 
    arregloDatos= (int*)calloc(totalDatos, sizeof(int));
    llenaArreglo(totalDatos);
    imprimeaArreglo(totalDatos);
   //Llenado de datos de los Hilos
  datosHilo1[0]=0;//en la posicion 0 almaceno los id
  datosHilo2[0]=1 ; 
    //En la pos 1 siempre almaceno cuanto hilos tengo
    datosHilo1[1]=datosHilo2[1]=2;
  //En la pos 2 siempre alamceno el tamaño del arreglo
   datosHilo1[2]=datosHilo2[2]=totalDatos;
  //En la pos 3 almaceno quien es el hilo elegido para hacer subsuma
  datosHilo1[3]=datosHilo2[3]=elegido;
  //Creando los hilos
  

   pthread_create(&hilos[0], NULL, tarea, (void*)datosHilo1);
   pthread_create(&hilos[1], NULL, tarea, (void*)datosHilo2);
   pthread_join(hilos[0], NULL);
   pthread_join(hilos[1], NULL);
   return 0; 
}
   
  
void* tarea (void *a){
  
  int id = ((int*)a)[0];
  int totalHilos= ((int*)a)[1];
  int tamArreglo= ((int*)a)[2];
  int porcion =  tamArreglo/ totalHilos;
  int elegido= ((int*)a)[3];
  int inicio = id * porcion;
  int fin = inicio+porcion-1;
  //Ajuste en caso de que no sea multiplo
  if(tamArreglo%totalHilos!=0){
      if(id==totalHilos-1){
        fin=tamArreglo-1;
      }
  
  }
  
  
  int res = sumaArreglo(inicio, fin);
  printf("Soy el hilo %d  y sume de %d a %d y  mi subtotal es %d\n", id,inicio, fin, res);
  //ir dejar al arreglo global de subtotales
  int aleatorio=rand()%5;
  sleep(aleatorio);
  subsuma[id]=res;
  pthread_barrier_wait(&barrera);
  printf("Soy el hilo %d y elegido es %d y ya alcance la barrera, dormi %d seg\n", id, elegido, aleatorio);
  //verificar si soy el elegido 
if (id==elegido){
   printf("Soy el hilo %d y me toca hacer la suma desde la subsuma\n", id);
   total=subsuma[0]+subsuma[1];
   printf("Soy el hilo %d y la suma total es  %d\n", id,total);
   
}else{
  printf("soy el hilo %d y ya acabe\n", id);
}
  
  
}
//Funcion que llena el arreglo con numeros aleatorios de 15 a 30
void llenaArreglo (int tam){
  int i;
  for (i = 0; i< tam; i++){
    arregloDatos[i] = (rand () % (30 - 15 +1)) + 15;
  }
}

int sumaArreglo(int inicio, int fin){
    int suma=0;
    for(int i=inicio; i<= fin; i++){ 
      suma += arregloDatos[i];
    }
  return suma;
}
  
void imprimeaArreglo(int tam){
    for(int i=0; i<tam; i++){ 
      printf ("%d ", arregloDatos[i]);
    }
 printf("\n");
}
   
