#include <stdio.h>
#include <stdlib.h>

struct sNODE{
  int dado;
  struct sNODE *prox;
};

struct sNODE *ini = NULL, *fim = NULL;

void inserir(int dado);
void inserir_ini(int dado);
void remover(int dado);
struct sNODE *buscar(int dado);

int obter(struct sNODE *node);
int tamanho();
void imprimir();
void apagar();

int main(){
    int value = 0;
    printf("Bem vindo ao programa Listas Simplesmente encadeada!\n");
    for(int i = 1; i<=100; i++){
        inserir(i);
    }
    imprimir();
    printf("Insira no Inicio: ");
    scanf(" %d", &value);
    inserir_ini(value);
    imprimir();
    apagar();
    return 0;
}

void inserir_ini(int dado){
  struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE));
  struct sNODE *ant = (struct sNODE*) malloc(sizeof(struct sNODE));
  novo->dado = dado;
  novo->prox = ini;

  if (!ini)
	ini = fim = novo;
  else{
    ant = ini->prox;
	ini->prox = ant;
	ini = novo;
  }
}

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