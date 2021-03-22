#include <stdio.h>
#include <stdlib.h>

struct sNODE{
  int dado;
  struct sNODE *esq, *dir;
};

struct sNODE *raiz = NULL;

struct sNODE *inserir(struct sNODE *no, int dado);
struct sNODE *remover(struct sNODE *no, int dado);

void emOrdem(struct sNODE *no);
void preOrdem(struct sNODE *no);
void posOrdem(struct sNODE *no);

struct sNODE *buscar(struct sNODE *no, int dado);
int obter(struct sNODE *no);

struct sNODE *apagar(struct sNODE *no);

//--------------------------------------------------//
int getMax(struct sNODE *no);
int getMin(struct sNODE *no);
void mostrarFolhas(struct sNODE *no);
int distanciaDaRaiz(struct sNODE *no, int dado);
int distanciaDaRaizV2(struct sNODE *no, int dado);
int alturaArvore(struct sNODE *no);
int alturaArvoreV2(struct sNODE *no);
int distanciaEntre(struct sNODE *no, int a, int b);


int main(){
  raiz = inserir(raiz,6);
  raiz = inserir(raiz,2);
  raiz = inserir(raiz,8);
  raiz = inserir(raiz,1);
  raiz = inserir(raiz,4);
  raiz = inserir(raiz,3);
  raiz = inserir(raiz,9);

  printf("Max: %d \n",getMax(raiz));
  printf("Min: %d \n",getMin(raiz));

  printf("Folhas: ");
  mostrarFolhas(raiz);
  printf("\n");

  printf("Distancia entre raiz e %d é %d saltos\n",4,distanciaDaRaiz(raiz,4));

  printf("Distancia entre raiz e %d é %d saltos\n",6,distanciaDaRaiz(raiz,6));

  printf("Distancia entre raiz e %d é %d saltos\n",4,distanciaDaRaiz(raiz,15));

  printf("Altura da árvore: %d\n",alturaArvore(raiz));

  printf("Distancia entre %d e %d é %d saltos\n",4,3,distanciaEntre(raiz,4,3));

  printf("Distancia entre %d e %d é %d saltos\n",4,4,distanciaEntre(raiz,4,4));

  return 0;
}

//------------------------------------------------//

int getMax(struct sNODE *no) {
  if (!no) {
    printf("Não há árvore!");
    exit(0);
  } else {
    if (no->dir)
      return getMax(no->dir);
    else
      return no->dado;
  }
}

int getMin(struct sNODE *no) {
  if (!no) {
    printf("Não há árvore!");
    exit(0);
  } else {
    if (no->esq)
      return getMin(no->esq);
    else
      return no->dado;
  }
}

void mostrarFolhas(struct sNODE *no) {
  if (no) {
    mostrarFolhas(no->esq);
    if (!no->esq && !no->dir) 
      printf("%d ",no->dado);
    mostrarFolhas(no->dir);
  }
}

int distanciaDaRaiz(struct sNODE *no, int dado) {
  if (!no) 
    return -1;
  else {
    if (dado == no->dado) return 0;
    else if (dado < no->dado) {
      int d = distanciaDaRaiz(no->esq, dado);
      if (d == -1) return -1;
      else return d + 1;
    }
    else {
      int d = distanciaDaRaiz(no->dir, dado);
      if (d == -1) return -1;
      else return d + 1;
    }
  }
}

int distanciaDaRaizV2(struct sNODE *no, int dado) {
  if (!no) 
    return -1;
  else {
    if (dado == no->dado) return 0;
    else if (dado < no->dado)
      return 1 + distanciaDaRaizV2(no->esq, dado);
    else
      return 1 + distanciaDaRaizV2(no->dir, dado);
  }
}

int alturaArvore(struct sNODE *no) {
  if (!no)
    return -1;
  else {
    if (no->esq == no->dir)
      return 0;
    else {
      int le = 1 + alturaArvore(no->esq);
      int ld = 1 + alturaArvore(no->dir);
      if (le > ld)
        return le;
      else 
        return ld;
    }
  }
}

#define MAX(a,b) ((a>b)?a:b)

int alturaArvoreV2(struct sNODE *no) {
  if (!no)
    return -1;
  else {
    if (no->esq == no->dir)
      return 0;
    else {
      return MAX(1 + alturaArvoreV2(no->esq), 1 + alturaArvoreV2(no->dir));
    }
  }
}

int distanciaEntre(struct sNODE *no, int a, int b) {
  if (a < no->dado && b < no->dado)
    return distanciaEntre(no->esq, a,  b);
  else if (a > no->dado && b > no->dado)
    return distanciaEntre(no->dir, a,  b);
  else 
    return distanciaDaRaiz(no,a) + distanciaDaRaiz(no,b);
}


//------------------------------------------------//



struct sNODE *inserir(struct sNODE *no, int dado){
  if (!no) {
    no = (struct sNODE*) malloc(sizeof(struct sNODE));
    no->dado = dado;
    no->esq = no->dir = NULL;
  } else if (dado < no->dado) 
    no->esq = inserir(no->esq,dado);
  else
    no->dir = inserir(no->dir,dado);

  return no;  
}

struct sNODE *remover(struct sNODE *no, int dado){
  struct sNODE *aux = NULL, *aux2 = NULL;

  if (no) {
    if (no->dado == dado) {
      if (no->esq == no->dir) {
        free(no);
        return NULL;
      }
      else if (!no->esq) {
        aux = no->dir;
        free(no);
        return aux;
      }
      else if (!no->dir) {
        aux = no->esq;
        free(no);
        return aux;
      } else {
        aux = aux2 = no->dir;
        while (aux->esq)
          aux = aux->esq;
        aux->esq = no->esq;
        free(no);
        return aux2;
      }
    }
    else {
      if (dado < no->dado)
        no->esq = remover(no->esq, dado);
      else
        no->dir = remover(no->dir, dado);
    }
  }
  return no;
}

void emOrdem(struct sNODE *no){
  if (no) {
    emOrdem(no->esq);
    printf("%d ",no->dado);
    emOrdem(no->dir);
  }
}

void preOrdem(struct sNODE *no){
  if (no) {
    printf("%d ",no->dado);
    preOrdem(no->esq);
    preOrdem(no->dir);
  }
}

void posOrdem(struct sNODE *no){
  if (no) {
    posOrdem(no->esq);
    posOrdem(no->dir);
    printf("%d ",no->dado);
  }
}

struct sNODE *buscar( struct sNODE *no, int dado){
  if (no) {
    if (no->dado == dado)
      return no;
    else if (dado < no->dado)
      return buscar(no->esq, dado);
    else
      return buscar(no->dir, dado);
  }
  
  return NULL;
}

int obter(struct sNODE *no) {
  if (no)
    return no->dado;
  else {
    printf("Nenhum dado para retornar.");
    exit(0);
  }
}

struct sNODE *apagar(struct sNODE *no){
  if (no) {
    no->esq = apagar(no->esq);
    no->dir = apagar(no->dir);
    free(no);
  }
  return NULL;
}
