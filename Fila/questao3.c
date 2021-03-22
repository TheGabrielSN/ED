#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100

struct sNODE{
    int nVoo, nPass, pos;
    char modelo[max], nomeP[max];
    struct sNODE *prox;
};
typedef struct sNODE NODE;

NODE *ini =NULL, *fim = NULL;

void enqueue(int voo, int pass, char *modelo, char *nome);
NODE* dequeue();

void apagar();
void emespera();
void impressdequeue(NODE *aux);

int main(){
    char modelo[max], nome[max];
    int pass, nvoo;
    for(int i = 0; i<2; i++){
        scanf(" %[^\n]s", modelo);
        scanf(" %[^\n]s", nome);
        scanf(" %d", &pass);
        scanf(" %d", &nvoo);

        enqueue(nvoo, pass, modelo, nome);
    }
    impressdequeue(dequeue());
    impressdequeue(dequeue());
    impressdequeue(dequeue());
    return 0;
}

void enqueue(int voo, int pass, char *modelo, char *nome){
    NODE *novo = (NODE*) malloc(sizeof(NODE));
    strcpy(novo->modelo, modelo);
    strcpy(novo->nomeP, nome);
    novo->nVoo = voo;
    novo->nPass = pass;

    if(!ini){
        novo->pos = 0;
        ini = fim = novo;
    } else {
        novo->pos = fim->pos + 1;
        fim->prox = novo;
        fim = novo;
    }
    return;
}

NODE* dequeue(){
    if(ini){
        NODE *aux = ini;
        if(ini==fim){
            ini = fim = NULL;
        } else {
            ini = ini->prox;
        }
        aux->prox = NULL;
        return aux;
    } else {
        printf("Impossível remover elemento, lista vazia!\n");
        exit(1);
    }
}

void apagar(){
    NODE *aux = ini, *ant;
    while(aux){
        ant = aux;
        aux = aux->prox;
        free(ant);
    }
    ini = fim = NULL;
}

void emespera(){
    struct sNODE *aux = ini;
    
    printf("Lista de aviões no aeroporto:\n");
    while (aux){
        printf("> Número do vôo: %d\n>>Modelo da aeronave: %s\n>>Nome do piloto: %s \n>>Número de passageiros:%d\n", aux->nVoo, aux->modelo, aux->nomeP, aux->nPass);
        aux = aux->prox;
    }

    return;
}

void impressdequeue(NODE *aux){
    printf("> Número do vôo: %d\n>>Modelo da aeronave: %s\n>>Nome do piloto: %s \n>>Número de passageiros:%d\n", aux->nVoo, aux->modelo, aux->nomeP, aux->nPass);
    printf("<---------->\n");
    free(aux);
}