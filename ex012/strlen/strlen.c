#include <stdio.h>
#include <string.h>
#include <locale.h>

#define N 30

main(){
	setlocale(LC_ALL, "Portuguese");
	
	char s[N];
	int i;
	
	printf("Digite um texto: ");
	gets(s);
	fflush(stdin);
	i = strlen(s);
	
	printf("Tamanho do texto: %d\n\n", i);
	
	printf("Impress�o de posi��o a posi��o:\n");
	for(i=0; i<strlen(s); i++){
		printf("%c", s[i]);
	}	
			
}
