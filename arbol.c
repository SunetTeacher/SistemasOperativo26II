#include <stdio.h>
#include <unistd.h>

int main(){
	int i,j,x,y;
	for(i=0; i<3; i++){
		x=fork();
		if(x==0){
			break;
		}
	}
	if(i==1){
		for(j=0; j<2;j++){
			y=fork();
			if(y==0){
				break;
				
			}
		}
	}
	
	
	if(i==2){
		fork();
		sleep(150);
	}
	while(1);
	
}
	
