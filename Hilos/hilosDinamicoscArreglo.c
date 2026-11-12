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
void crearMatriz(int filas, int columnas);

void* tarea (void *a);

int sumaArreglo(int inicio, int fin);

int main(){
  srand(time(NULL));
  int numHilos;
  //Esto tambien cambia con hilos dinamicos
  int datosHilo1[4];
  int datosHilo2[4];
  int **datosHilos;
  pthread_t *hilos;
  int totalDatos, elegido;
   
    printf("Cuantos hilos desea crear: \n");
    scanf("%d", &numHilos);
    //arreglo  dinamico de hilos
    hilos=(pthread_t *)calloc(numHilos, sizeof(pthread_t));
    elegido=rand()%numHilos;
    printf("De que tamaño quieres tu arreglo: \n");
    scanf("%d", &totalDatos);
    pthread_barrier_init(&barrera,NULL, N); 
          //Arreglo dinamico
    arregloDatos= (int*)calloc(totalDatos, sizeof(int));
    
    //Crear la matriz dinámica.
    datosHilos = crearMatriz(filas, columnas);
    
    llenaArreglo(totalDatos);
    imprimeaArreglo(totalDatos);
   
   //Llenado de datos de los Hilos en la matriz
   
   
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

int **crearDatosHilos(int filas, int columnas){
  int **matriz, i;
  matriz=(int**)calloc(filas, sizeof(int*));
  for(i=0; i<filas; i++){
    matriz[i]=(int*)calloc(columnas, sizeof(int));
  }
  return matriz;
}

















