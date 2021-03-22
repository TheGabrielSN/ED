#include <stdio.h>
#include <stdlib.h>

int buscaBin(int l[], int ini, int fim, int num) {
    int meio = (ini + fim) / 2;

    if(l[meio] == num){
        return meio;
    } else if(ini != fim){
        if(num < l[meio]){
            fim = meio - 1;
        } else {
            ini = meio + 1;
        }
        return buscaBin(l, ini, fim, num);
    }

    return -1;
}

int main(){
    int l[] = {1,3,5,7,9,11,13,15};
  
    printf("Achei 15 em %d \n",buscaBin(l, 0, 7, 15));
    printf("Achei 5 em %d \n",buscaBin(l, 0, 7, 5));
    printf("Achei 11 em %d \n",buscaBin(l, 0, 7, 110));

    return 0;
}

