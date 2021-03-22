#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sINFO {
  int n_voo, n_passageiros;
  char aeronave[100], piloto[100];
};

struct sNODE{
  struct sINFO info;
  struct sNODE *prox;
};

struct sFILA{
  struct sNODE *ini, *fim;
};

typedef struct sFILA FILA;

void criar(FILA *fi);
void apagar(FILA *fi);

void enqueue(FILA *fi, int n_voo, char *aeronave, char *piloto, int n_passageiros);
struct sINFO dequeue(FILA *fi);
struct sINFO getFront(FILA *fi);

int tamanho(FILA *fi);
void imprimir(FILA *fi);

int main(){
  FILA fila_aviao;
  criar(&fila_aviao);

  enqueue(&fila_aviao, 1000, "Model1", "Nome1",50);
  enqueue(&fila_aviao, 1001, "Model2", "Nome2",300);
  enqueue(&fila_aviao, 1002, "Model3", "Nome3",250);
  enqueue(&fila_aviao, 1005, "Model4", "Nome4",180);
  enqueue(&fila_aviao, 1008, "Model5", "Nome5",230);

  imprimir(&fila_aviao);

  printf("Quantidade de aviões em espera %d\n",tamanho(&fila_aviao));

  struct sINFO aviao = getFront(&fila_aviao);

  printf("Aviao da frente: \n\tVoo %d\n\tPiloto %s\n\tModelo %s\n\tNum Passageiros %d\n",aviao.n_voo,aviao.piloto,aviao.aeronave,aviao.n_passageiros);

  aviao = dequeue(&fila_aviao);

  printf("Decolando: \n\tVoo %d\n\tPiloto %s\n\tModelo %s\n\tNum Passageiros %d\n",aviao.n_voo,aviao.piloto,aviao.aeronave,aviao.n_passageiros);

  aviao = dequeue(&fila_aviao);

  printf("Decolando: \n\tVoo %d\n\tPiloto %s\n\tModelo %s\n\tNum Passageiros %d\n",aviao.n_voo,aviao.piloto,aviao.aeronave,aviao.n_passageiros);

  apagar(&fila_aviao);

  return 0;
}

void criar(FILA *fi){
  fi->ini = fi->fim = NULL;
}

void enqueue(FILA *fi, int n_voo, char *aeronave, char *piloto, int n_passageiros){
  struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE));

  novo->info.n_voo = n_voo;
  novo->info.n_passageiros = n_passageiros;
  strcpy(novo->info.aeronave,aeronave);
  strcpy(novo->info.piloto,piloto);

  novo->prox = NULL;

  if (!fi->ini)
    fi->ini = fi->fim = novo;
  else{
    fi->fim->prox = novo;
    fi->fim = novo;
  }
}

struct sINFO dequeue(FILA *fi){
  if (fi->ini) {
    struct sINFO dado = fi->ini->info;
    struct sNODE *tmp = fi->ini;
    
    if (fi->ini == fi->fim)
      fi->ini = fi->fim = NULL;
    else
      fi->ini = fi->ini->prox;

    free(tmp);

    return dado;
  } 
  else {
    printf("Não há elementos. Fila vazia.\n");
    exit(1);
  }
}

struct sINFO getFront(FILA *fi){
  if (fi->ini) {
    struct sINFO dado = fi->ini->info;
    struct sNODE *tmp = fi->ini;
    
    if (fi->ini == fi->fim)
      fi->ini = fi->fim = NULL;
    else
      fi->ini = fi->ini->prox;

    free(tmp);

    return fi->ini->info;
  } 
  else {
    printf("Não há elementos. Fila vazia.\n");
    exit(1);
  }
}

void apagar(FILA *fi){
  struct sNODE *aux = fi->ini, *ant = NULL;
 
  while (aux){
    ant = aux;
    aux = aux->prox;
    free(ant);
  }
  fi->ini = fi->fim = NULL;
}

int tamanho(FILA *fi){
  struct sNODE *aux = fi->ini;
  int tam = 0;
 
  while (aux){
    tam++;
    aux = aux->prox;
  }
 
  return tam;
}

void imprimir(FILA *fi){
  struct sNODE *aux = fi->ini;
 
  printf("F[ ");
  while (aux){
    printf("(%d %s) ", aux->info.n_voo, aux->info.piloto);
    aux = aux->prox;
  }
  printf("]\n");
}
