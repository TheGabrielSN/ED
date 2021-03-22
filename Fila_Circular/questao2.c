#include <stdio.h>
#include <stdlib.h>

struct sFILA{
    int dado;
    int *arr, ini, fim;
    int MAX;
};

typedef struct sFILA FILA;

void criar(FILA *fi, int tam_MAX);
void apagar(FILA *fi);

void enqueue(FILA *fi, int dado);
int dequeue(FILA *fi);

int tamanho(FILA *fi);
void imprimir(FILA *fi);

int main(){
    FILA fila1;
    criar(&fila1, 10);

    enqueue(&fila1, 100);
    enqueue(&fila1, 50);
    enqueue(&fila1, 200);

    printf("Dequeue em Fila1 -> %d\n",dequeue(&fila1));

    imprimir(&fila1);

    apagar(&fila1);

    return 0;
}

void criar(FILA *fi, int tam_MAX){
    fi->arr = (int*) malloc(sizeof(int)*tam_MAX);
    fi->ini = 0;
    fi->fim = 0;
    fi->dado = 0;
    fi->MAX = tam_MAX;
    return;
}

void apagar(FILA *fi){
    fi->ini = 0;
    fi->fim = 0;
    fi->MAX = 0;
    fi->dado = 0;
    free(fi->arr);
    return;
}

void enqueue(FILA *fi, int dado){
    if((fi->fim +1) != fi->ini && !(fi->fim+1 == fi->MAX && !fi->ini)){
        fi->arr[fi->fim] = dado;
        fi->fim = (fi->fim + 1) % fi->MAX;
    } else {
        printf("Inserção indisponível, fila cheia.\n");
    }
    return;
}

int dequeue(FILA *fi){
    if(fi->ini != fi->fim){
        fi->dado = fi->arr[fi->ini];
        fi->ini = (fi->ini + 1) % fi->MAX;
        return fi->dado;
    } else {
        printf("Retorno indisponível, fila vazia.\n");
        exit(1);
    }
}

int tamanho(FILA *fi){
    if(fi->ini <= fi->fim){
        return fi->fim - fi->ini; 
    } else {
        return fi->MAX - (fi->ini - fi->fim);
    }
}

void imprimir(FILA *fi){
	printf("F[ ");
	for (int i = fi->ini ; i != fi->fim ; i++) {
		if (i == fi->MAX){ i = 0;}
		printf("%d ",fi->arr[i]);
	}
	printf("]\n");
    return;
}