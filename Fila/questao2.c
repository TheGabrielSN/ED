#include <stdio.h>
#include <stdlib.h>

struct sNODE{
    int dado;
    struct sNODE *prox;
};

struct sFILA{
    struct sNODE *ini, *fim;
};

typedef struct sFILA FILA;

void criar(FILA *fi);
void apagar(FILA *fi);

void enqueue(FILA *fi, int dado);
int dequeue(FILA *fi);

int tamanho(FILA *fi);
void imprimir(FILA *fi);

int main(){
    FILA fila1;
    criar(&fila1);

    enqueue(&fila1, 100);
    enqueue(&fila1, 50);
    enqueue(&fila1, 200);
    imprimir(&fila1);

    printf("Dequeue em Fila1 -> %d\n",dequeue(&fila1));

    imprimir(&fila1);

    apagar(&fila1);

    return 0;
}

void criar(FILA *fi){
    fi->ini = NULL;
    fi->fim = NULL;

    return;
}

void apagar(FILA *fi){
    struct sNODE *aux = fi->ini, *ant = NULL;

    while(aux){
        ant = aux;
        aux = aux->prox;
        free(ant);
    }
    fi->ini = fi->fim = NULL;

    return;
}

void enqueue(FILA *fi, int dado){
    struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE));
    novo->dado = dado;
    novo->prox = NULL;

    if(!fi->ini){
        fi->ini = fi->fim = novo;
    } else {
        fi->fim->prox = novo;
        fi->fim = novo;
    }
    return;
}

int dequeue(FILA *fi){
    if(fi->ini){
        int dado = fi->ini->dado;
        struct sNODE *aux = fi->ini;
        if(fi->ini == fi->fim){
            fi->ini = fi->fim = NULL;
        } else {
            fi->ini = fi->ini->prox;
        }
        free(aux);
        return dado;
    } else {
        printf("Impossível remover elemento, lista vazia!\n");
        exit(1);
    }
}

int tamanho(FILA *fi){
    int tam = 0;
    struct sNODE *aux = fi->ini;
    while(aux){
        tam++;
        aux = aux->prox;
    }
    return tam;
}

void imprimir(FILA *fi){
    struct sNODE *aux = fi->ini;
    
    printf("F[ ");
    while (aux){
        printf("%d ", aux->dado);
        aux = aux->prox;
    }
    printf("]\n");

    return;
}