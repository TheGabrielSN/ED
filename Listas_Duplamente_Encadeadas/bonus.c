#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 31

struct sNODE{
    char name[max], ocupacao[max];
    float salario;
    struct sNODE *ant;
    struct sNODE *prox;
};

typedef struct{
    struct sNODE *ini, *fim;
} LISTA;

typedef struct{
    LISTA list, Gerente, Supervisor, Peao;
    int tam;
}pList;

//struct sNODE *ini = NULL, *fim = NULL;

void inicializar(pList *lst);
void apagar(pList *lst);
void controler(pList *lst, float salario, char *name, char *ocupacao);
void unionList(pList *lst);

void inserir_ord(LISTA *lst, float salario, char *name, char *ocupacao);
void remover(LISTA *lst, char *name); //Só passar pList.list e o nome.
struct sNODE *buscar(LISTA *lst, char *name); //"
char* obter(struct sNODE *node);
int tamanho(pList *lst);
void imprimir(pList *lst);

int main(){
    pList lst;
    inicializar(&lst);

    controler(&lst, 1938.50, "Random 1", "Supervisor");
    controler(&lst, 1038.50, "Random 2", "Peão");
    controler(&lst, 2500.50, "Random 6", "Peão");
    controler(&lst, 10538.50, "Random 3", "Gerente");
    controler(&lst, 538.50, "Random 4", "Supervisor");
    controler(&lst, 1938.50, "Random 5", "Gerente");

    unionList(&lst);

    imprimir(&lst);

    apagar(&lst);

    return 0;
}

void inicializar(pList *lst){
    lst->list.ini = NULL;
    lst->list.fim = NULL;
    lst->Gerente.ini = NULL;
    lst->Gerente.fim = NULL;
    lst->Supervisor.ini = NULL;
    lst->Supervisor.fim = NULL;
    lst->Peao.ini = NULL;
    lst->Peao.fim = NULL;
    lst->tam = 0;
}

void apagar(pList *lst){
    struct sNODE *aux = lst->list.ini, *ant;
    
    while (aux){
        ant = aux;
        aux = aux->prox;
        free(ant);
    }
    lst->list.ini = NULL;
    lst->list.fim = NULL;
    lst->Gerente.ini = NULL;
    lst->Gerente.fim = NULL;
    lst->Supervisor.ini = NULL;
    lst->Supervisor.fim = NULL;
    lst->Peao.ini = NULL;
    lst->Peao.fim = NULL;
}

void controler(pList *lst, float salario, char *name, char *ocupacao){
    lst->tam++;
    if(strcmp(ocupacao, "Gerente") == 0){
        inserir_ord(&lst->Gerente, salario, name, ocupacao);
    }
    if(strcmp(ocupacao, "Supervisor") == 0){
        inserir_ord(&lst->Supervisor, salario, name, ocupacao);
    }
    if(strcmp(ocupacao, "Peão") == 0){
        inserir_ord(&lst->Peao, salario, name, ocupacao);
    }

}

void unionList(pList *lst){
    lst->list.ini = lst->Gerente.ini;
    lst->Gerente.fim->prox = lst->Supervisor.ini;
    lst->Supervisor.ini->ant = lst->Gerente.fim;
    lst->Supervisor.fim->prox = lst->Peao.ini;
    lst->Peao.ini->ant = lst->Supervisor.fim;
    lst->list.fim = lst->Peao.fim;
}

void inserir_ord(LISTA *lst, float salario, char *name, char *ocupacao){
    struct sNODE *aux = lst->ini;
    struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE ));
    novo->salario = salario;
    strcpy(novo->name, name);
    strcpy(novo->ocupacao, ocupacao);
    novo->ant = NULL;
    novo->prox = NULL;

    while(aux && salario < aux->salario){
        aux = aux->prox;
    }
    if(!lst->ini){
        lst->ini = lst->fim = novo;
    } else if(aux == lst->ini){
        novo->prox = lst->ini;
        lst->ini->ant = novo;
        lst->ini = novo;
    } else if (!aux){
        lst->fim->prox = novo;
        novo->ant = lst->fim;
        lst->fim = novo;
    } else {
        aux->ant->prox = novo;
        novo->ant = aux->ant;
        novo->prox = aux;
        aux->ant = novo;
    }
}

void remover(LISTA *lst, char *name){
    struct sNODE *aux = buscar(lst, name);

    if (!aux){
        return;
    }
    if (!aux->ant && !aux->prox){
        lst->ini = lst->fim = NULL;
    } else if (aux == lst->ini) {
        lst->ini = lst->ini->prox;
        lst->ini->ant = NULL;
    } else if (aux == lst->fim) {
        lst->fim = lst->fim->ant;
        lst->fim->prox = NULL;
    } else {
        aux->ant->prox = aux->prox;
        aux->prox->ant = aux->ant;
    }
    free(aux);
}

struct sNODE *buscar(LISTA *lst, char *name){
    struct sNODE *aux = lst->ini;
    while (aux){
        if(strcmp(name, aux->name)==0){
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}

char* obter(struct sNODE *node){
    if (!node){
        printf("Erro ao obter dado. Ponteiro invalido.");
        exit(0);
    }
    
    return node->name;
}

int tamanho(pList *lst){
    return lst->tam;
}

void imprimir(pList *lst){
    struct sNODE *aux = lst->list.ini;
    printf("Dados dos Funcionarios: \n");
    while(aux){
        printf("Nome: %s\t", aux->name);
        printf("Ocupação: %s\t", aux->ocupacao);
        printf("Salario: %.2f\n", aux->salario);
        printf("----------\n");
        aux = aux->prox;
    }
    printf("Finalização dos dados!\n");
}

