#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

//Função tem que procurar o índice do maior elemento
int indexMax(int l[], int ini, int tam){
  int im = ini;
  int maior = l[ini];

  for (int i = ini + 1 ; i < tam ; i++)
    if (l[i] > maior) {
      im = i;
      maior = l[i];
    }
  
  return im;
}

void selectionSort(int l[], int tam){
  for (int i = 0 ; i < tam - 1 ; i++) {
    int eleito = l[i];
    int im = indexMax(l, i+1, tam);
    //inverter sinal de desigualdade
    if (l[im] > eleito)
      troca(&l[i],&l[im]);
  }
}

int main(void) {
  int l[] = {1,2,3,4,5}, tam = 5;

  selectionSort(l, tam);

  for (int i = 0 ; i < tam ; i++)
    printf("%d ",l[i]);
  return 0;
}


