#include <stdio.h>

// d para int,  f para float e s para textos

int main(){
	
	int idade = 0;
	float peso = 0;
	
	printf("Digite sua idade:\n");
	scanf("%d", &idade);
	
	printf("Digite seu peso:\n");
	scanf("%f", &peso);
	
	/* printf("Digite sua idade e peso:\n");
	scanf("%d %f", &idade, &peso); */
	
	printf("Idade informada: %d anos e %.2f Kg.\n", idade, peso);
} 
