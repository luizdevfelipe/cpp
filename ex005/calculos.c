#include <stdio.h>
#include <stdlib.h>

int main(){
	int A, B, soma, sub, mult, div;
	
	printf("Digite o primeiro valor: ");
	scanf("%d", &A);
	
	printf("Digite o segundo valor: ");
	scanf("%d", &B);
	
	soma = A + B;
	sub = A - B;
	mult = A * B;
	div = A / B;
	
	printf("Resultados:\n");
	printf("Soma: %d.\n", soma);
	printf("Subtracao: %d.\n", sub);
	printf("Multiplicacao: %d.\n", mult);
	printf("Divisao: %d.\n", div);
	system("pause");
}
