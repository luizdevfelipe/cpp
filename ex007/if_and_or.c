#include <stdio.h>

main(){
	
	float m;
		
	printf("Digite a nota:\n");
	scanf("%f", &m);
	
	if(m >= 4 && m < 7){
		printf("Aluno(a) tem direito a exame!");
	} else if (m <= 3){
		printf("Reprovado!");
	} else {
		printf("Aprovado!");
	}
}
