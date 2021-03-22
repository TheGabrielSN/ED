#include <stdio.h>
#include <stdlib.h>

struct sNODE{
  int dado;
  struct sNODE *prox;
};

struct sNODE *ini = NULL, *fim = NULL;

/*>>>>> funções do BubbleSort <<<<<*/
void troca(struct sNODE *a, struct sNODE *b);
void bubbleSort(int tam);

/*>>>>> Funções da lista <<<<<*/
void inserir(int dado);
void remover(int dado);
struct sNODE *buscar(int dado);

int obter(struct sNODE *node);
int tamanho();
void imprimir();
void apagar();

int main(){
    inserir(5);
    inserir(4);
    inserir(3);
    inserir(2);
    inserir(1);
    imprimir();

    bubbleSort(tamanho());
    imprimir();

    apagar();
    return 0;
}

/*>>>>> funções do BubbleSort <<<<<*/
void troca(struct sNODE *a, struct sNODE *b) {
    int t = a->dado;
    a->dado = b->dado;
    b->dado = t;
}

void bubbleSort(int tam){
    struct sNODE *aux = ini;
    int trocou = 1;
    for (int i = 0 ; i < tam && trocou; i++) {
        trocou = 0;
        for (int j = 0 ; j < tam - 1 - i && aux->prox != NULL; j++){
            if (aux->dado > aux->prox->dado) {
                troca(aux,aux->prox);
                trocou = 1;
            }
            aux = aux->prox;
        }
        aux = ini;
    }
}

/*>>>>> Funções da lista <<<<<*/
void inserir(int dado){
    struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE));
    novo->dado = dado;
    novo->prox = NULL;

    if (!ini)
        ini = fim = novo;
    else{
        fim->prox = novo;
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
    struct sNODE *aux = ini, *ant = NULL;

    while (aux){
        if (dado == aux->dado){
            if (aux == ini)
                    ini = ini->prox;
            else if(aux == fim){
                    ant->prox = NULL;
                    fim = ant;
            } else
                    ant->prox = aux->prox;
        
            free(aux);
            return;
        }
        
        ant = aux;
        aux = aux->prox;
    }
}

void apagar(){
    struct sNODE *aux = ini, *ant = NULL;
    
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