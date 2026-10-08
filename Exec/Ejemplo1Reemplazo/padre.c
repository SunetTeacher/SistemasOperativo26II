#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
   int a, b;
   char dato1[10];
   char dato2[10];
   printf("Soy el proceso padre %d\n", (int)getpid());
   printf("Dame los dos numeros\n");
   scanf("%d %d", &a, &b);
    sprintf(dato1, "%d", a);
     sprintf(dato2, "%d", b);
     printf("Los datos convertidos son %s y %s\n", dato1, dato2);
   int y =fork();
   if(y==0){
   
     printf("Soy el proceso hijo %d y mi padre es %d\n", (int)getpid(), (int)getppid());

    
        sleep(5);
     int r=execl("./suma", "./suma",dato1, dato2, NULL);    
     
     if(r==-1){
          printf("Error al sustituir el proceso");
          exit(0);
     }else{
          printf("Fui sustituido");
     
     }
     
     
   }
   while(1);
   
}
