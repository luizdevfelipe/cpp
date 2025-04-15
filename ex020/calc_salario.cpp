#include <stdio.h>
#include <windows.h>

void dependentes();
void inss();
void ir();

float sal_base, sal_liquido, val_dependentes, val_inss, val_ir;
int num_dependentes;

int main() {
	HANDLE threads[3];
	DWORD dwThreadId;
	int controle;
	
	printf("Informe o salario base: ");
	scanf("%f", &sal_base);
	
	printf("Informe a quantidade de dependentes: ");
	scanf("%d", &num_dependentes);

	threads[0] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&dependentes, (LPVOID)&controle, 0, &dwThreadId);
	threads[1] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&inss, (LPVOID)&controle, 0, &dwThreadId);
	threads[2] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&ir, (LPVOID)&controle, 0, &dwThreadId);
	
	WaitForMultipleObjects(3, threads, TRUE, INFINITE);
	
	sal_liquido = sal_base + val_dependentes - val_inss - val_ir;
	
	printf("\nO valor liquido do salario: %.2f\n", sal_liquido);
	printf("O valor referente aos dependentes: %.2f\n", val_dependentes);
	printf("O valor de desconto do INSS: %.2f\n", val_inss);
	printf("O valor de desconto do IR: %.2f\n", val_ir);
}

void dependentes() {
	if (num_dependentes == 0) {
		val_dependentes = 0;
	} else if (num_dependentes >= 1 && num_dependentes <= 3) {
		val_dependentes = sal_base * 0.01;
	} else if (num_dependentes > 3 && num_dependentes <= 6) {
		val_dependentes = sal_base * 0.02;
	} else {
		val_dependentes = sal_base * 0.03;
	}
}

void inss() {
	if (sal_base <= 911.7) {
		val_inss = sal_base * 0.08;
	} else if (sal_base <= 1519.5) {
		val_inss = sal_base * 0.09;
	} else if (sal_base <= 3038.99) {
		val_inss = sal_base * 0.11;
	} else {
		val_inss = 3038.99 * 0.11;
	}
}

void ir() {
	if (sal_base <= 1371.81) {
		val_ir = 0;
	} else if (sal_base <= 2743.25) {
		val_ir = sal_base * 0.15 - 205.92;
	} else {
		val_ir = sal_base * 0.2750 - 548.92;
	}
}
