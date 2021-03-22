#include <stdio.h>
#include <stdlib.h>

struct sNODE{
    int dado;
    struct sNODE *prox;
};

struct sNODE *ini = NULL, *fim = NULL;

/*>>>>> funções do BubbleSort <<<<<*/
void troca(struct sNODE *a,struct sNODE *b);
struct sNODE* indexMin(struct sNODE *ini);
void selectionSort(int tam);

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

    selectionSort(tamanho());
    imprimir();

    apagar();
    return 0;
}

/*>>>>> funções do SelectionSort <<<<<*/
void troca(struct sNODE *a, struct sNODE *b) {
    int t = a->dado;
    a->dado = b->dado;
    b->dado = t;
}

struct sNODE* indexMin(struct sNODE *ini){
    struct sNODE *aux = ini, *im;
    int menor = aux->dado;
    while(aux){
        if(aux->dado < menor){
            im = aux;
            menor = aux->dado;
        }
        aux = aux->prox;
    }
    
    return im;
}

void selectionSort(int tam){
    struct sNODE *aux = ini, *im;
    for (int i = 0 ; i < tam - 1 ; i++){
        im = indexMin(aux->prox);
        if (im->dado < aux->dado){
            troca(im,aux);}
        aux = aux->prox;
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


