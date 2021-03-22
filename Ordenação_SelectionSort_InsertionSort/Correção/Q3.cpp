#include <stdio.h>
#include <stdlib.h>
//inclusão do cabeçalho <string.h>
#include <string.h>


//Mudança de int para char * no parametro
void insertionSort(char *l[], int tam){
  for (int i = 1 ; i < tam ; i++) {
    //Mudança de int para char * na var eleito
    char *eleito = l[i];
    int j = i - 1;

    //usando strcmp para comparar strings
    while (j >= 0 && strcmp(l[j], eleito) > 0) {
      l[j+1] = l[j];
      j = j - 1;
    }
    l[j+1] = eleito;
  }
}

int main(void) {
  char *l[] = {"So", "sei", "que", "nada", "sei"}, tam = 5;

  insertionSort(l, tam);

  for (int i = 0 ; i < tam ; i++)
    printf("%s ",l[i]);
  return 0;
}


