#include <stdio.h>
#include <windows.h>

void embarque();
void comissao();

float prc_basico, prc_embarque, prc_comissao, prc_consumidor;

int main () {
	int controle;
	DWORD dwThreadid;
	HANDLE threads[2];
	
	printf("Digite o valor basico da passagem: ");
	scanf("%f", &prc_basico);
	
	threads[0] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&embarque, (LPVOID)&controle, 0, &dwThreadid);
	threads[1] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&comissao, (LPVOID)&controle, 0, &dwThreadid);
	WaitForMultipleObjects(2, threads, TRUE, INFINITE);
	
	prc_consumidor = prc_embarque + prc_comissao + prc_basico;
	
	printf("Valor do embarque: %.2f \n", prc_embarque);
	printf("Valor da comissao: %.2f \n", prc_comissao);
	printf("Valor ao consumidor: %.2f \n", prc_consumidor);
}

void embarque() {
	if (prc_basico <= 953.5) {
		prc_embarque = prc_basico * 0.07;
	} else if (prc_basico <= 2018.5) {
		prc_embarque = prc_basico * 0.04;
	} else {
		prc_embarque = prc_basico * 0.02;
	}
}

void comissao() {
	if (prc_basico <= 1315) {
		prc_comissao = prc_basico * 0.08;
	} else if (prc_basico <= 4235) {
		prc_comissao = prc_basico * 0.05;
	} else {
		prc_comissao = prc_basico * 0.03;
	}
}
