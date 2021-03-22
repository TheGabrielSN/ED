#include <stdio.h>
#include <stdlib.h>

struct sNODE{
  int dado;
  struct sNODE *prox;
};

struct sNODE *topo = NULL;

int getTopo();
void push(int dado);
int pop();

int tamanho();
void imprimir();
void apagar();

int main(void) {
    push(10);
    push(100);
    push(1000);
    push(10000);
    push(1);

    imprimir();
    printf("%d\n", pop());
    imprimir();
    printf("%d\n", getTopo());
    apagar();

    return 0;
}

int getTopo(){
    return topo->prox->dado;
}

void push(int dado){
    struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE));
    novo->dado = dado;
    novo->prox = NULL;

    if (!topo)
    topo = novo;
    else{
    novo->prox = topo;
    topo = novo;
    }
}

int pop(){
    if (topo) {
    int dado = topo->dado;
    struct sNODE *tmp = topo;
      
    topo = topo->prox;

    free(tmp);

    return dado;
    }
    else {
    printf("Não há elementos. Pilha vazia.\n");
    exit(1);
    }
}


int tamanho(){
    struct sNODE *aux = topo;
    int tam = 0;
  
    while (aux){
    tam++;
    aux = aux->prox;
    }
  
    return tam;
}

void imprimir(){
    struct sNODE *aux = topo;
  
    printf("P[ ");
    while (aux){
    printf("%d ", aux->dado);
    aux = aux->prox;
    }
    printf("]\n");
}

void apagar(){
    struct sNODE *aux = topo, *ant;
  
    while (aux){
    ant = aux;
    aux = aux->prox;
    free(ant);
    }
    topo = NULL;
}