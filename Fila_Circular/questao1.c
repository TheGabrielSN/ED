#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int l[MAX], ini = 0, fim = 0;

int getFront();
int elementoNaFila(int elemento);
int indiceNaFila(int index);

void enqueue(int elemento);
int dequeue();

int tamanho();
void imprimir();
void apagar();

int main(void) {
	enqueue(-2);
	enqueue(-1);
	enqueue(0);
	enqueue(1);
	enqueue(2);

	printf("Elemento Inicial: %d\n", getFront());
	printf("Elemento da fila: %d\n", elementoNaFila(2));
	printf("Elemento da fila: %d\n", elementoNaFila(5));
	printf("Indice na fila: %d\n", indiceNaFila(3));
	printf("Indice na fila: %d\n", indiceNaFila(7));

	apagar();
	return 0;
}

int getFront(){
	return l[ini];
}

int elementoNaFila(int elemento){
	for (int i = ini ; i != fim ; i++) {
		if(i == MAX){ i = 0; }
		if(l[i] == elemento){ return 1; }
	}
	return 0;
}

int indiceNaFila(int index){
	if(index >= ini && index < fim){
		return 1;
	} else {
		return 0;
	}
}

void enqueue(int elemento){
	if ((fim + 1) != ini && !(fim + 1 == MAX && !ini) ){
		l[fim] = elemento;
		fim = (fim + 1) % MAX;
	}
	else
		printf("Não foi possível inserir %d. Fila cheia.\n",elemento);
	return;
}

int dequeue(){
	if (ini != fim) {
		int dado = l[ini];
		ini = (ini + 1) % MAX;
		return dado;
	}
	else {
		printf("Não há elementos. Fila vazia.\n");
		exit(1);
	}
	return;
}

int tamanho(){
	if (ini <= fim)
		return fim - ini;
	else
		return MAX - (ini - fim);
}

void imprimir(){
	printf("F[ ");
	for (int i = ini ; i != fim ; i++) {
		if (i == MAX){ i = 0;}
		printf("%d ",l[i]);
	}
	printf("]\n");
	return;
}

void apagar(){
	ini = fim = 0;
	return;
}