#include <stdio.h>

main(){
	
	int v[5], i;
	
	for (i=0; i<5; i++){
		printf("Digite um valor para a posicao %d do vetor: ", i);
		scanf("%d", &v[i]);
	}
	printf("\nValores digitados: ");
	for (i=0; i<5; i++){
		printf("%d ", v[i]);
	}
}
