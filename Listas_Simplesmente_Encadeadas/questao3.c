#include <stdio.h>
#include <stdlib.h>

struct sNODE{
  int dado;
  struct sNODE *prox;
};

struct sLISTA{
  struct sNODE *ini, *fim;
};

typedef struct sLISTA LISTA;

void inicializar(LISTA *lst);
void apagar(LISTA *lst);

void inserir_ord(LISTA *lst, int dado);
void remover(LISTA *lst, int dado);
struct sNODE *buscar(LISTA *lst, int dado);

int obter(struct sNODE *node);
int tamanho(LISTA *lst);
void imprimir(LISTA *lst);

int main(void){
    LISTA lista;
    inicializar(&lista);
    for(int i = 0; i<50; i++){
        inserir_ord(&lista, i);
    }
    imprimir(&lista);
    remover(&lista, 5);
    inserir_ord(&lista, 17);  
    inserir_ord(&lista, 100);    
    inserir_ord(&lista, -1);   
    imprimir(&lista);
    printf("obter: %d\n", obter(buscar(&lista, 18)));
    printf("tamanho: %d\n", tamanho(&lista));
    apagar(&lista);

    return 0;
}


void inicializar(LISTA *lst){
    lst->fim = NULL;
    lst->ini = NULL;
}

void apagar(LISTA *lst){
    struct sNODE *aux = lst->ini, *ant = NULL;

    while(aux){
        ant = aux;
        aux = aux->prox;
        free(ant);
    }
    lst->ini = lst->fim = NULL;
}

void inserir_ord(LISTA *lst, int dado){
    struct sNODE *aux = lst->ini, *ant = NULL;
    struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE));
    novo->dado = dado;
    novo->prox = NULL;

    while(aux && dado > aux->dado){
        ant = aux;
        aux = aux->prox;
    }

    if(!lst->ini){
        lst->ini = lst->fim = novo;
    } else if(aux == lst->ini){
        novo->prox = lst->ini;
        lst->ini = novo;
    } else if(aux == lst->fim){
        lst->fim->prox = novo;
        lst->fim = novo;
    } else {
        ant->prox = novo;
        novo->prox = aux;
    }
}

void remover(LISTA *lst, int dado){
    struct sNODE *aux = lst->ini, *ant = NULL;
    while(aux){
        if(dado == aux->dado){
            if(aux == lst->ini){
                lst->ini = lst->ini->prox;
            } else if(aux == lst->fim){
                ant->prox = NULL;
                lst->fim = ant;
            } else {
                ant->prox = aux->prox;
            }
            free(aux);
            return;
        }
        ant = aux;
	    aux = aux->prox;
    }
}

struct sNODE *buscar(LISTA *lst, int dado){
    struct sNODE *aux = lst->ini;

    while(aux){
        if(dado == aux->dado){
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}

int obter(struct sNODE *node){
    if(!node){
        printf("Erro. Ponteiro invalido.\n");
        exit(0);
    }
    return node->dado;
}

int tamanho(LISTA *lst){
    struct sNODE *aux = lst->ini;
    int tam = 0;

    while(aux){
        tam++;
        aux = aux->prox;
    }

    return tam;
}

void imprimir(LISTA *lst){
    struct sNODE *aux = lst->ini;
    while(aux){
        printf("%d ", aux->dado);
        aux = aux->prox;
    }
    printf("\n");
}