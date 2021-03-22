#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20
//const unsigned MAX = 20; -> isso estava dando erro para ser usado na lista de inteiro.
int pos = 0;
char l[MAX];

void inserir_ord(char *elemento);
void inserir(char *elemento);
void remover(char *elemento);
int buscar(char *elemento);

char obter(int indice);
int tamanho();
void imprimir();
void apagar();

int main(void) {
    char aux[2];
    printf("Digite as letras da string: ");
    for(int i = 0; i<20; i++){
        scanf(" %c", aux);
        inserir_ord(aux);
    }

    imprimir();

    printf("Digite a letra a ser removida: ");
    scanf(" %c", aux);
    remover(aux);

    imprimir();

    printf("Digite a letra que deseja buscar: ");
    scanf(" %c", &aux);
    printf("Index: %d Item: %c\n", buscar(aux), obter(buscar(aux)));

    apagar();
}

void inserir_ord(char *elemento){
    int i, p;
    if(pos < MAX){
        for(i = 0; i < pos; i++){
            if(l[i] == elemento[0]){ break; }
        }
        for(p = pos; p > i; p--){
            l[p] = l[p-1];
        }
        l[i] = elemento[0];
        l[pos+1] = '\0';
        pos++;
    } else {
        printf("Erro Insert Item In List.\n");
    }

}

void inserir(char *elemento){
    if(pos < MAX){
        l[pos++] = elemento[0];
        l[pos] = '\0';
    } else {
        printf("Erro Insert Item In List.\n");
    }
}

int buscar(char *elemento){
    for(int i = 0; i < pos; i++){
        if(l[i] == elemento[0]){ return i;}
    }
    return -1;
}

void remover(char *elemento){
    int p = buscar(elemento);
    if(p == -1) { return; }
    for(int i = p; i < pos; i++){
        l[i] = l[i+1];
    }
    pos--;
}

char obter(int indice){
    if(indice < 0 || indice >= pos){
        printf("Index Out The Range.\n");
        exit(1);
    }
    return l[indice];
}

int tamanho(){
    return pos;
}

void imprimir(){
    printf("%s\n",l);
}

void apagar(){
    pos = 0;
}