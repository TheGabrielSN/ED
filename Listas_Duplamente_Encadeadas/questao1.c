#include <stdio.h>
#include <stdlib.h>

struct sNODE{
    int dado;
    struct sNODE *ant;
    struct sNODE *prox;
};

struct sNODE *ini = NULL, *fim = NULL;

void inserir_ini(int dado);
void imprimir_reverso();

void inserir(int dado);
void remover(int dado);
struct sNODE *buscar(int dado);

int obter(struct sNODE *node);
int tamanho();
void imprimir();
void apagar();

int main(){
    int x;
    printf("Programa Listas Duplamente\n");
    for(int i = 0; i<10; i++){
        inserir(i);
    }
    imprimir();
    printf("Insira no inicio: ");
    scanf(" %d", &x);
    inserir_ini(x);
    printf("Impressão: ");
    imprimir();
    printf("Impressão Inversa: ");
    imprimir_reverso();
    apagar();
    return 0;
}

void inserir_ini(int dado){
    struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE));
    novo->dado = dado;
    novo->ant = NULL;
    novo->prox = NULL;

    if (!ini)
        ini = fim = novo;
    else{
        ini->ant = novo;
        novo->prox = ini;
        ini = novo;
    }
}

void imprimir_reverso(){
    struct sNODE *aux = fim;
    
    printf("[ ");
    while (aux){
        printf("%d ", aux->dado);
        aux = aux->ant;
    }
    printf("]\n");
}

void inserir(int dado){
    struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE));
    novo->dado = dado;
    novo->ant = NULL;
    novo->prox = NULL;

    if (!ini)
        ini = fim = novo;
    else{
        fim->prox = novo;
        novo->ant = fim;
        fim = novo;
    }
}

struct sNODE *buscar(int dado){
    struct sNODE *aux = ini;

    while (aux){
        if (dado == aux->dado)
            return aux;
        aux = aux->prox;
    }

    return NULL;
}

void remover(int dado){
    struct sNODE *aux = buscar(dado);

    if (!aux)
        return;
    if (!aux->ant && !aux->prox){
        ini = fim = NULL;
    } else if (aux == ini) {
        ini = ini->prox;
        ini->ant = NULL;
    } else if (aux == fim) {
        fim = fim->ant;
        fim->prox = NULL;
    } else {
        aux->ant->prox = aux->prox;
        aux->prox->ant = aux->ant;
    }
    free(aux);
}

void apagar(){
    struct sNODE *aux = ini, *ant;
    
    while (aux){
        ant = aux;
        aux = aux->prox;
        free(ant);
    }
    ini = fim = NULL;
}

int obter(struct sNODE *node){
    if (!node){
        printf("Erro ao obter dado. Ponteiro invalido.");
        exit(0);
    }
    
    return node->dado;
}

int tamanho(){
    struct sNODE *aux = ini;
    int tam = 0;
    
    while (aux){
        tam++;
        aux = aux->prox;
    }
    
    return tam;
}

void imprimir(){
    struct sNODE *aux = ini;
    
    printf("[ ");
    while (aux){
        printf("%d ", aux->dado);
        aux = aux->prox;
    }
    printf("]\n");
}