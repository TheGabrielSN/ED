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

struct sNODE *ini = NULL, *fim = NULL;

void inserir_ord(float salario, char *name, char *ocupacao);
void remover(char *name);
struct sNODE *buscar(char *name);

char* obter(struct sNODE *node);
int tamanho();
void imprimir();
void apagar();

int main(){
    inserir_ord(1938.50, "Random 1", "gerente");
    inserir_ord(1038.50, "Random 2", "peao");
    inserir_ord(10538.50, "Random 3", "dono");
    inserir_ord(538.50, "Random 4", "estagiario");
    inserir_ord(1938.50, "Random 5", "gerente");

    imprimir();

    printf("Nome: %s\n", obter(buscar("Random 3")));

    remover("Random 5");

    imprimir();

    apagar();

    return 0;
}

void inserir_ord(float salario, char *name, char *ocupacao){
    struct sNODE *aux = ini;
    struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE ));
    novo->salario = salario;
    strcpy(novo->name, name);
    strcpy(novo->ocupacao, ocupacao);
    novo->ant = NULL;
    novo->prox = NULL;

    while(aux && salario < aux->salario){
        aux = aux->prox;
    }
    if(!ini){
        ini = fim = novo;
    } else if(aux == ini){
        novo->prox = ini;
        ini->ant = novo;
        ini = novo;
    } else if (!aux){
        fim->prox = novo;
        novo->ant = fim;
        fim = novo;
    } else {
        aux->ant->prox = novo;
        novo->ant = aux->ant;
        novo->prox = aux;
        aux->ant = novo;
    }
}

void remover(char *name){
    struct sNODE *aux = buscar(name);

    if (!aux){
        return;
    }
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

struct sNODE *buscar(char *name){
    struct sNODE *aux = ini;
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

void apagar(){
    struct sNODE *aux = ini, *ant;
    
    while (aux){
        ant = aux;
        aux = aux->prox;
        free(ant);
    }
    ini = fim = NULL;  
}
