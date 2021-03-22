#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int l[MAX], ini = 0, fim = 0;

void inserir_ini(int elemento);
int remover_ini();
void inserir_fim(int elemento);
int remover_fim();

void enqueue(int elemento);
int dequeue();

int tamanho();
void imprimir();
void apagar();

int main(void) {
    inserir_ini(-2);
	inserir_fim(-1);
	inserir_ini(0);
	inserir_fim(1);
	inserir_ini(2);

    imprimir();

    printf("Dado Inicio: %d\n", remover_ini());
    printf("Dado Fim: %d\n", remover_fim());

    imprimir();

	apagar();
	return 0;
}

void inserir_ini(int elemento){
	if ((fim + 1) != ini && !(fim + 1 == MAX && !ini)){
        for(int i = fim; i != ini; i--){
            if(i == -1){ i = MAX;}
            l[i] = l[i-1];
        }
        l[ini] = elemento;
        fim = (fim + 1) % MAX;
	}
	else
		printf("Não foi possível inserir %d. Fila cheia.\n",elemento);
    return;
}

int remover_ini(){
	if (ini != fim) {
		int dado = l[ini];
		ini = (ini + 1) % MAX;
		return dado;
	}
	else {
		printf("Não há elementos. Fila vazia.\n");
		exit(1);
	}
}

void inserir_fim(int elemento){
	if ((fim + 1) != ini && !(fim + 1 == MAX && !ini) ){
		l[fim] = elemento;
		fim = (fim + 1) % MAX;
	}
	else
		printf("Não foi possível inserir %d. Fila cheia.\n",elemento);
    return;
}

int remover_fim(){
	if (ini != fim) {
		int dado = l[fim-1];
		fim = (fim - 1) % MAX;
		return dado;
	}
	else {
		printf("Não há elementos. Fila vazia.\n");
		exit(1);
	}
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