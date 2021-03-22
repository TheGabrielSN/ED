#include <stdio.h>
#include <stdlib.h>

struct sPILHA{
    int pos, *arr;
    int MAX;
};

typedef struct sPILHA PILHA;

void criar(PILHA *pi, int tam_MAX);
void apagar(PILHA *pi);

void push(PILHA *pi, int dado);
int pop(PILHA *pi);

int tamanho(PILHA *pi);
void imprimir(PILHA *pi);

int main(){
    PILHA pilha1;
    criar(&pilha1, 10);

    push(&pilha1, 100);
    push(&pilha1, 50);
    push(&pilha1, 200);

    printf("Pop em Pilha 1 -> %d",pop(&pilha1));

    imprimir(&pilha1);

    apagar(&pilha1);

    return 0;
}

void criar(PILHA *pi, int tam_MAX){
    pi->arr = (int*) malloc(sizeof(int)*tam_MAX);
    if(pi->arr == NULL){
        exit(1);
    }
    pi->MAX = tam_MAX;
    pi->pos = 0;
}

void apagar(PILHA *pi){
    pi->pos = 0;
    pi->MAX = 0;
    free(pi->arr);
}

void push(PILHA *pi, int dado){
    if(pi->pos < pi->MAX){
        pi->arr[pi->pos++] = dado;
    } else {
        printf("Não foi possivel inserir o elemento, pilha cheia!");
    }

}

int pop(PILHA *pi){
    int dado = pi->arr[--pi->pos];
    return dado;
}

int tamanho(PILHA *pi){
    return pi->pos+1;
}

void imprimir(PILHA *pi){
    printf("P[ ");
    for (int i = pi->pos -1 ; i >= 0 ; i--)
        printf("%d ",pi->arr[i]);
    printf("]\n");
}
