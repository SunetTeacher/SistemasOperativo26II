#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    int hijos=4;
    int i;
    for(i=0; i< hijos; i++){
       if(!vfork()){
          break;
       }
    
    }
    
    while(1);
}
