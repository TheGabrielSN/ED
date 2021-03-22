#include <stdlib.h>
#include <stdio.h>
#define MAX 10

int l[MAX], pos = 0;

int getTopo();
void push(int elemento);
int pop();

int tamanho();
void imprimir();
void apagar();

int main(void) {
    push(10);
    push(100);
    push(1000);
    push(10000);
    push(1);

    imprimir();
    printf("%d\n", pop());
    imprimir();
    printf("%d\n", getTopo());
    apagar();

    return 0;
}

int getTopo(){
    return l[pos-1];
}

void push(int elemento){
    if (pos < MAX)
        l[pos++] = elemento;
    else
        printf("Não foi possível inserir %d. Pilha cheia.\n",elemento);
}

int pop(){
    if (pos)
        return l[--pos];
    else {
        printf("Não há elementos. Pilha vazia.\n");
        exit(1);
    }
}

int tamanho(){
    return pos;
}

void imprimir(){
    printf("P[ ");
    for (int i = pos -1 ; i >= 0 ; i--)
        printf("%d ",l[i]);
    printf("]\n");
}

void apagar(){
    pos = 0;
}