#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void troca(char **a, char **b) {
  char *t = *a;
  *a = *b;
  *b = t;
}

void bubbleSort(char *l[], int tam){
  int trocou = 1;
  for (int i = 0 ; i < tam && trocou; i++) {
    trocou = 0;
    for (int j = 0 ; j < tam - 1 - i; j++)
      if (strcmp(l[j], l[j+1]) > 0) {
        troca(&l[j],&l[j+1]);
        trocou = 1;
      }
  }
}

int main(void) {
  char *l[] = {"Um","Exemplo","De","String","!"}, tam = 5;

  printf("Nao ordenado:\n");
  for (int i = 0 ; i < tam ; i++)
    printf("%s ",l[i]);
  
  bubbleSort(l, tam);

  printf("\n\nOrdenado:\n");
  for (int i = 0 ; i < tam ; i++)
    printf("%s ",l[i]);
  return 0;
}


