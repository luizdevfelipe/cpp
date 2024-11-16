#include <stdio.h>
#include <conio.h>
#include <locale.h>
main(){
	setlocale(LC_ALL, "Portuguese");	
	int i;
	for(i=1; i<=10; i++){
		printf("\nO %dº valor é %d ", i, i*2);
	}
	getch();
}
