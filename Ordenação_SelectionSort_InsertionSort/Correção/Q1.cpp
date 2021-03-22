#include <stdio.h>
#include <stdlib.h>

void insertionSort(int l[], int tam){
  for (int i = 1 ; i < tam ; i++) {
    int eleito = l[i];
    int j = i - 1;

    //mudança acontece no sinal de desigualdade
    while (j >= 0 && l[j] < eleito) {
      l[j+1] = l[j];
      j = j - 1;
    }
    l[j+1] = eleito;
  }
}

int main(void) {
  int l[] = {1,2,3,4,5}, tam = 5;

  insertionSort(l, tam);

  for (int i = 0 ; i < tam ; i++)
    printf("%d ",l[i]);
  return 0;
}


