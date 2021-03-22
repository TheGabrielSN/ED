#include <stdio.h>
#include <stdlib.h>

const unsigned MAX = 10;
int l[MAX], ini = 0, fim = 0;

void enqueue(int elemento);
int dequeue();

int tamanho();
void imprimir();
void apagar();

int getFront();
int elementoNaFila(int elemento);
int indiceNaFila(int indice);

int main(void) {
  enqueue(100);
  enqueue(50);
  enqueue(75);
  enqueue(55);
  enqueue(65);
  enqueue(95);
  enqueue(15);
  enqueue(35);
  enqueue(80);

  printf("Dequeue -> %d\n",dequeue());
  printf("Dequeue -> %d\n",dequeue());
  printf("Dequeue -> %d\n",dequeue());
  printf("Dequeue -> %d\n",dequeue());

  imprimir();

  printf("getFront -> %d\n",getFront());
  printf("%d na Fila? -> %d\n", 15, elementoNaFila(15));
  printf("%d na Fila? -> %d\n", 100, elementoNaFila(100));

  printf("indice %d na Fila? -> %d\n",0 , indiceNaFila(0));
  printf("indice %d na Fila? -> %d\n",5 , indiceNaFila(5));

  return 0;
}

void enqueue(int elemento){
  if ((fim + 1) != ini && !(fim + 1 == MAX && !ini) ){
    l[fim] = elemento;
    //fim = (fim + 1) % MAX;
    fim++;
    if (fim == MAX) fim = 0;
  }
  else
    printf("Não foi possível inserir %d. Fila cheia.\n",elemento);
}

int dequeue(){
  if (ini != fim) {
    int dado = l[ini];
    //ini = (ini + 1) % MAX;
    ini++;
    if (ini == MAX) ini = 0;
    return dado;
  }
  else {
    printf("Não há elementos. Fila vazia.\n");
    exit(1);
  }
}

int tamanho(){
  if (ini <= fim)
    return fim - ini;
  else
    return MAX - (ini - fim);
}

void imprimir(){
  printf("F[ ");
  for (int i = ini ;  ; i++) {
    if (i == MAX) i = 0;
    if (i == fim) break;
    printf("%d ",l[i]);
  }
  printf("]\n");
}

void apagar(){
  ini = fim = 0;
}

int getFront(){
  if (ini != fim) {
    return l[ini];
  }
  else {
    printf("Não há elementos. Fila vazia.\n");
    exit(1);
  }
}

int elementoNaFila(int elemento){
  for (int i = ini ;  ; i++) {
    if (i == MAX) i = 0;
    if (i == fim) break;
    else if (l[i] == elemento)
      return 1;
  }
  return 0;
}

int indiceNaFila(int indice){
  if (ini == fim)
    return 0;
  else if (ini < fim)
    return (indice >= ini && indice < fim);
  else
    return (indice < fim || indice >= ini);
}
