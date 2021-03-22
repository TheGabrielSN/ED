#include <stdio.h>
#include <stdlib.h>

struct sNODE{
    int dado;
    struct sNODE *prox;
};
typedef struct sNODE sNODE;

sNODE *ini = NULL, *fim = NULL;

void enqueue_init(int dado);
int dequeue_init();

void enqueue_end(int dado);
int dequeue_end();

int tamanho();
void imprimir();
void apagar();

int main(void) {
    enqueue_init(1);
    enqueue_init(3);
    enqueue_init(5);
    enqueue_init(7);
    imprimir();

    printf("Valor removido: %d\n", dequeue_init());
    printf("Valor removido: %d\n", dequeue_init());
    imprimir();

    enqueue_end(0);
    enqueue_end(2);
    enqueue_end(4);
    enqueue_end(6);
    imprimir();
    
    printf("Valor removido: %d\n", dequeue_end());
    printf("Valor removido: %d\n", dequeue_end());
    imprimir();

    apagar();

    return 0;
}

void enqueue_init(int dado){
    sNODE *novo = (sNODE*) malloc(sizeof(sNODE));
    novo->dado = dado;
    novo->prox = NULL;

    if (!ini)
        ini = fim = novo;
    else{
        novo->prox = ini;
        ini = novo;
    }
}

int dequeue_init(){
    if (ini) {
        int dado = ini->dado;
        sNODE *tmp = ini;
        
        if (ini == fim){
            ini = fim = NULL;
        } else {
            ini = ini->prox;
        }
        free(tmp);

        return dado;
    }
    else {
        printf("Impossível remover elemento, lista vazia!\n");
        exit(1);
    }
}

void enqueue_end(int dado){
    sNODE *novo = (sNODE*) malloc(sizeof(sNODE));
    novo->dado = dado;
    novo->prox = NULL;

    if (!ini)
        ini = fim = novo;
    else{
        fim->prox = novo;
        fim = novo;
    }
}

int dequeue_end(){
    if (ini) {
        int dado = fim->dado;
        sNODE *tmp = fim, *aux = ini;
        
        if (ini == fim){
            ini = fim = NULL;
        } else {
            while(aux->prox != fim){
                aux = aux->prox;
            }
            aux->prox = NULL;
            fim = aux;
        }
        free(tmp);

        return dado;
    }
    else {
        printf("Impossível remover elemento, lista vazia!\n");
        exit(1);
    }
}

void apagar(){
    sNODE *aux = ini, *ant = NULL;
    
    while (aux){
        ant = aux;
        aux = aux->prox;
        free(ant);
    }
    ini = fim = NULL;
}

int tamanho(){
    sNODE *aux = ini;
    int tam = 0;
    
    while (aux){
        tam++;
        aux = aux->prox;
    }
    
    return tam;
}

void imprimir(){
    sNODE *aux = ini;
    
    printf("F[ ");
    while (aux){
        printf("%d ", aux->dado);
        aux = aux->prox;
    }
    printf("]\n");
}