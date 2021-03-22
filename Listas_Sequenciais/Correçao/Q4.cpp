#include <stdio.h>
#include <stdlib.h>

typedef struct {
 unsigned MAX;
 int *arr, pos;
} LISTA;

void criar(LISTA *lst, int tam_MAX);
void apagar(LISTA *lst);

void inserir_ord(LISTA *lst, int elemento);
void remover(LISTA *lst, int elemento);
int buscar(LISTA *lst, int elemento);

int obter(LISTA *lst, int indice);
int tamanho(LISTA *lst);
void imprimir(LISTA *lst);

int main(void) {
  LISTA l1, l2; //declarando 2 listas
  criar(&l1,50); //criando lista com max de 50 elementos
  criar(&l2,20); //criando lista com max de 20 elementos

  printf("LISTA 1:\n");
  inserir_ord(&l1,10); //inserindo elemento 10 na l1
  inserir_ord(&l1,5); //inserindo elemento 5 na l1
  inserir_ord(&l1,1); //inserindo elemento  na l1
  imprimir(&l1);

  remover(&l1,5);
  imprimir(&l1);

  apagar(&l1);
  imprimir(&l1);

  criar(&l1,10);
  inserir_ord(&l1,200);
  inserir_ord(&l1,100);
  imprimir(&l1);

  printf("LISTA 2:\n");
  inserir_ord(&l2,11); //inserindo elemento 10 na l1
  inserir_ord(&l2,51); //inserindo elemento 5 na l1
  inserir_ord(&l2,11); //inserindo elemento  na l1
  imprimir(&l2);

  apagar(&l1);

  apagar(&l2);
  return 0;
}

void criar(LISTA *lst, int tam_MAX){
  lst->pos = 0;
  lst->MAX = tam_MAX;
  lst->arr = (int*) malloc(sizeof(int)*tam_MAX);
}

void inserir_ord(LISTA *lst, int elemento){
  int i, p;
  if (lst->pos < lst->MAX) {
    for (i = 0 ; i < lst->pos ; i++)
          if (lst->arr[i] >= elemento)
                break;
    
    for (p = lst->pos ; p > i ; p--)
          lst->arr[p] = lst->arr[p-1];
    
    lst->arr[i] = elemento;

    lst->pos ++;
  }
  else {
    printf("Não foi possível inserir %d. Lista cheia.\n",elemento);
  }
}

int buscar(LISTA *lst, int elemento){
  for (int i = 0 ; i < lst->pos ; i++){
    if (lst->arr[i] == elemento)
      return i;
  }
  return -1;
}

void remover(LISTA *lst, int elemento){
  int p = buscar(lst, elemento);
 
  if (p == -1)
    return;
 
  for (int i = p ; i < lst->pos -1; i++)
    lst->arr[i] = lst->arr[i+1];
  lst->pos--;
}

int obter(LISTA *lst, int indice){
  if (indice < 0 || indice >= lst->pos) {
    printf("Indice %d fora dos limites da Lista.\n", indice);
    exit(1);
  }
  return lst->arr[indice];
}

int tamanho(LISTA *lst){
  return lst->pos;
}

void imprimir(LISTA *lst){
  for (int i = 0 ; i < lst->pos ; i++)
    printf("%d ",lst->arr[i]);
  printf("\n");
}

void apagar(LISTA *lst){
  lst->pos = 0;
  lst->MAX = 0;
  free(lst->arr);
}
