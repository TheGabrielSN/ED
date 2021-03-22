#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertionSort(char *l[], int tam){
    for (int i = 1 ; i < tam ; i++) {
        char *eleito = (char*) malloc(sizeof(l[i]));
        eleito = l[i];
        int j = i - 1;

        while (j >= 0 && strcmp(l[j], eleito)==1) {
            l[j+1] = l[j];
            j = j - 1;
        }
        l[j+1] = eleito;
    }
}

int main(void) {
    char *l[] = {"xyzz","bca","bac","zxy","abc"};
    int tam = 5;

    insertionSort(l, tam);

    for (int i = 0 ; i < tam ; i++){
        printf("%s ",l[i]);
    }
    return 0;
}


