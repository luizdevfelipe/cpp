#include <stdio.h>

int main(){
	
	 int v[5] = {10, 20, 30, 40, 50};
	 int i;
	 float soma;
	 
	 for (i=0; i<5; i++){
	 	soma += v[i];	 		
	 }
	
	printf("Resultado: %f\n", soma/5);	
}
