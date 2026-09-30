#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){
  int K=100;
    printf("Soy el padre con ID: %d y mi valor de K es %d\n",(int)getpid(), K);
		
     int x=vfork();
      if(x!=0){
      	      printf("Ya termino mi hijo, mi valor de K es %d\n", K);
      	      while(1);
		
      
      }else{
		printf("Soy el hijo con ID: %d y veo a K =%d\n",(int)getpid(), K);
		
               // while(1);
               K=20;
               sleep(10);
		printf("Soy el hijo con ID: %d y termine con K=%d\n",(int)getpid(),K);
		_exit(0);
      }
  }
