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

void inserir(LISTA *lst, int dado);
void remover(LISTA *lst, int dado);
struct sNODE *buscar(LISTA *lst, int dado);

int obter(struct sNODE *node);
int tamanho(LISTA *lst);
void imprimir(LISTA *lst);

// Algoritmo SelectionSort
void troca(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

//mudanças nos parâmetros. Função agora só recebe ponteiro sNODE
struct sNODE *indexMin(struct sNODE *ini){
  //Ao invés de índice, armazenamos o ponteiro
  struct sNODE *im = ini;
  //Indexamos pelo ponteiro
  int menor = ini->dado;

  //varremos a lista em busca do menor
  for (struct sNODE *i = ini->prox; i != NULL ; i = i->prox)
    if (i->dado < menor) {
      im = i;
      menor = i->dado;
    }
  
  return im;
}

//A função só precisa receber a LISTA
void selectionSort(LISTA *lst){
  //Varremos a LISTA até o penúltiimo elemento
  for (struct sNODE *i = lst->ini ; i && i->prox != NULL ; i = i->prox){
    int eleito = i->dado;
    //Pegamos o ponteiro para o menor elemento após eleito
    struct sNODE *im = indexMin(i->prox);
    if (im->dado < eleito)
      troca(&i->dado,&im->dado);
  }
}


// -------------------------


int main(){
  LISTA lst;
  inicializar(&lst);
  
  inserir(&lst,5);
  inserir(&lst,4);
  inserir(&lst,3);
  inserir(&lst,2);
  inserir(&lst,1);

  imprimir(&lst);
  selectionSort(&lst);
  imprimir(&lst);

  apagar(&lst);
  return 0;
}

void inicializar(LISTA *lst){
  lst->ini = lst->fim = NULL;
}

void inserir(LISTA *lst, int dado){
  struct sNODE *novo = (struct sNODE*) malloc(sizeof(struct sNODE));
  novo->dado = dado;
  novo->prox = NULL;

  if (!lst->ini)
    lst->ini = lst->fim = novo;
  else{
    lst->fim->prox = novo;
    lst->fim = novo;
  }
}

struct sNODE *buscar(LISTA *lst, int dado){
  struct sNODE *aux = lst->ini;

  while (aux){
    if (dado == aux->dado)
          return aux;
    aux = aux->prox;
  }

  return NULL;
}

void remover(LISTA *lst, int dado){
  struct sNODE *aux = lst->ini, *ant = NULL;

  while (aux){
    if (dado == aux->dado){
          if (aux == lst->ini)
                lst->ini = lst->ini->prox;
          else if(aux == lst->fim){
                ant->prox = NULL;
                lst->fim = ant;
          } else
                ant->prox = aux->prox;
      
          free(aux);
          return;
    }
    
    ant = aux;
    aux = aux->prox;
  }
}

void apagar(LISTA *lst){
  struct sNODE *aux = lst->ini, *ant;
 
  while (aux){
    ant = aux;
    aux = aux->prox;
    free(ant);
  }
  lst->ini = lst->fim = NULL;
}

int obter(struct sNODE *node){
  if (!node){
    printf("Erro ao obter dado. Ponteiro invalido.");
    exit(0);
  }
 
  return node->dado;
}

int tamanho(LISTA *lst){
  struct sNODE *aux = lst->ini;
  int tam = 0;
 
  while (aux){
    tam++;
    aux = aux->prox;
  }
 
  return tam;
}

void imprimir(LISTA *lst){
  struct sNODE *aux = lst->ini;
 
  printf("[ ");
  while (aux){
    printf("%d ", aux->dado);
    aux = aux->prox;
  }
  printf("]\n");
}

