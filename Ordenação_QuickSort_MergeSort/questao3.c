#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void intercala(char *l[],int ini, int fim, int meio) {
  char **aux = (char**) malloc(sizeof(char) * (fim-ini+1));
  int ini1 = ini, ini2 = meio + 1, p_aux = 0;

  while( (ini1 <= meio) && (ini2 <= fim) ) {
    if (strcmp(l[ini2],l[ini1]) >= 0){
      aux[p_aux] = l[ini1++];
    } else {
      aux[p_aux] = l[ini2++];
    }
    p_aux++;
  }

  for (int i = ini1 ; i <= meio ; i++)
    aux[p_aux++] = l[i];
  
  for (int i = ini2 ; i <= fim ; i++)
    aux[p_aux++] = l[i];
  
  for (int i = ini, j = 0 ; i <= fim ; i++,j++)
    l[i] = aux[j];
  
  free(aux);
}

void mergeSort(char *l[], int ini, int fim) {
  if (ini < fim) {
    int meio = (ini + fim) / 2;
    mergeSort(l,ini,meio);
    mergeSort(l,meio+1,fim);
    intercala(l,ini,fim,meio);
  }
}

int main(void) {
  char *l[5] = {"xyzz","bca","bac","zxy","abc"};
  mergeSort(l, 0, 4);

  for (int i = 0 ; i <= 4 ; i++)
    printf("%s ",l[i]);

  return 0;
}

