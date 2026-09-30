#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){
 
     int x=fork();
     int regWait=-1;
	 int aux;
      if(x!=0){
      		printf("Soy el padre con ID: %d\n",(int)getpid());
			regWait= (int) wait(&aux);
			printf("Estoy por terminar y me desperto mi hijo con ID %d \n", regWait);
			if (WIFEXITED(aux)) {
				printf("El hijo terminó normalmente con el código: %d\n", WEXITSTATUS(aux));
	        }else{
				printf("No termino por exit");
				
			}
			exit(0);
      
      }else{
			printf("Soy el hijo con ID: %d\n", (int) getpid());	
		       sleep(10);
			exit(3);
      }
  }
