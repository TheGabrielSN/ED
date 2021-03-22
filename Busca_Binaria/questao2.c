#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/***** Busca *****/
int buscaBin(char *l[], int tam, char *str);

/***** Ordenação do array *****/
void intercala(char *l[],int ini, int fim, int meio);
void mergeSort(char *l[], int ini, int fim);

int main(){
    char *l[] = {"xyzz","bca","bac","zxy","abc"};
    int tam = 5;
    
    mergeSort(l, 0, 4);
    printf("Lista ordenada: ");
    for (int i = 0 ; i <= 4 ; i++)
        printf("%s ",l[i]);
    printf("\n");
    printf("Achei bca em %d \n",buscaBin(l, tam, "bca"));
    printf("Achei xyzz em %d \n",buscaBin(l, tam, "xyzz"));
    
    return 0;
}

/***** Busca *****/
int buscaBin(char *l[], int tam, char *str){
    int ini = 0, fim = tam-1;
    int meio = (ini+fim)/2;

    while (ini <= fim){
        if (strcmp(l[meio], str)==0){
            return meio;
        } else {
            if (strcmp(str, l[meio])<0){
                fim = meio - 1;
            } else {
                ini = meio + 1;
            }
            meio = (ini+fim)/2;
        }
    }
    return -1;
}


/***** Ordenação do array *****/
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