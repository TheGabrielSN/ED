#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sDADO{
  char nome[31];
  char cargo[31];
  float salario;
};


struct sNODE{
  struct sDADO func;
  struct sNODE *ant;
  struct sNODE *prox;
};

struct sNODE *ini = NULL, *fim = NULL;

void inserir_ord(char nome[], char cargo[], float salario);
void remover(char nome[]);
struct sNODE *buscar(char nome[]);

struct sDADO obter(struct sNODE *node);
int tamanho();
void imprimir();
void imprimir_reverso();
void apagar();

int main(){
  inserir_ord("joao", "analista junior",5000);
  inserir_ord("mario", "analista senior",8000);
  inserir_ord("alberto", "arquiteto de software",6000);
  inserir_ord("mateus", "tester",4500);

  imprimir();
  return 0;
}

void inserir_ord(char nome[], char cargo[], float salario){
  struct sNODE *aux = ini;
  struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE ));
  strcpy(novo->func.nome,nome);
  strcpy(novo->func.cargo,cargo);
  novo->func.salario = salario;
  novo->ant = NULL;
  novo->prox = NULL;

  while(aux && salario < aux->func.salario)
    aux = aux->prox;

  if (!ini)
    ini = fim = novo;
  else if (aux == ini){
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

struct sNODE *buscar(char nome[]){
  struct sNODE *aux = ini;

  while (aux){
    if (!strcmp(nome,aux->func.nome))
      return aux;
    aux = aux->prox;
  }

  return NULL;
}

void remover(char nome[]){
  struct sNODE *aux = buscar(nome);

  if (!aux)
    return;

  if (!aux->ant && !aux->prox)
    ini = fim = NULL;
  else if (aux == ini) {
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

struct sDADO obter(struct sNODE *node){
  if (!node){
    printf("Erro ao obter dado. Ponteiro invalido.");
    exit(0);
  }
 
  return node->func;
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
    printf("(%s, ", aux->func.nome);
    printf("%s, ", aux->func.cargo);
    printf("R$ %.2f) ", aux->func.salario);
    aux = aux->prox;
  }
  printf("]\n");
}

void imprimir_reverso(){
  struct sNODE *aux = fim;
 
  printf("[ ");
  while (aux){
    printf("(%s, ", aux->func.nome);
    printf("%s, ", aux->func.cargo);
    printf("R$ %.2f) ", aux->func.salario);
    aux = aux->ant;
  }
  printf("]\n");
}
