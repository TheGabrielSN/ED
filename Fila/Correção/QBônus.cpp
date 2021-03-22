#include <stdio.h>
#include <stdlib.h>

struct sNODE{
  int dado;
  struct sNODE *prox;
};

struct sNODE *ini = NULL, *fim = NULL;

void inserir_fim(int dado);
int remover_ini();

void inserir_ini(int dado);
int remover_fim();

int tamanho();
void imprimir();
void apagar();

int main(void) {
  inserir_fim(100);
  inserir_fim(50);
  inserir_fim(75);

  inserir_ini(80);
  inserir_ini(70);
  inserir_ini(40);

  imprimir();

  printf("Remover_ini -> %d\n",remover_ini());
  printf("Remover_fim -> %d\n",remover_fim());

  imprimir();

  printf("Remover_ini -> %d\n",remover_ini());
  printf("Remover_fim -> %d\n",remover_fim());

  imprimir();

  printf("Remover_ini -> %d\n",remover_ini());
  printf("Remover_fim -> %d\n",remover_fim());

  imprimir();

  return 0;
}

void inserir_fim(int dado){
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

void inserir_ini(int dado){
  struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE));
  novo->dado = dado;
  novo->prox = NULL;

  if (!ini)
    ini = fim = novo;
  else{
    novo->prox = ini;
    ini = novo;
  }
}

int remover_ini(){
  if (ini) {
    int dado = ini->dado;
    struct sNODE *tmp = ini;
    
    if (ini == fim)
      ini = fim = NULL;
    else
      ini = ini->prox;

    free(tmp);

    return dado;
  } 
  else {
    printf("Não há elementos. Fila vazia.\n");
    exit(1);
  }
}

int remover_fim(){
  if (fim) {
    int dado = fim->dado;
    struct sNODE *tmp = fim;
    
    if (ini == fim)
      ini = fim = NULL;
    else {
      struct sNODE *aux = ini, *ant = NULL;
      while (aux != fim) {
        ant = aux;
        aux = aux->prox;
      }
      ant->prox = NULL;
      fim = ant;
    } 

    free(tmp);

    return dado;
  } 
  else {
    printf("Não há elementos. Fila vazia.\n");
    exit(1);
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
 
  printf("D[ ");
  while (aux){
    printf("%d ", aux->dado);
    aux = aux->prox;
  }
  printf("]\n");
}
