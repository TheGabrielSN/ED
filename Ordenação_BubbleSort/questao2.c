#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubbleSort(char *l[], int tam){
    int trocou = 1;
    for (int i = 0 ; i < tam && trocou; i++) {
        trocou = 0;
        for (int j = 0 ; j < tam - 1 ; j++){
            if(strcmp(l[j],l[j+1])==1){
                char *t = (char*) malloc(sizeof(char)*strlen(l[j]));
                t = l[j];
                l[j] = l[j+1];
                l[j+1] = t;
                free(t);
                trocou = 1;
            }
        }
    }
}

int main(void) {
    char *l[5] = {"xyzz","bca","bac","zxy","abc"};
    int tam = 5;
    bubbleSort(l, tam);

    for (int i = 0 ; i < tam ; i++){
        printf("%s ",l[i]);}
    return 0;
}
