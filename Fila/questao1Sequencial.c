#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int l[MAX], pos = 0;

int getFront();

void enqueue(int elemento);
int dequeue();

int tamanho();
void imprimir();
void apagar();

int main(void) {
    enqueue(100);
    enqueue(50);
    enqueue(200);
    imprimir();
    
    printf("Dequeue em Fila1 -> %d\n",getFront());

    printf("Dequeue em Fila1 -> %d\n",dequeue());

    printf("Dequeue em Fila1 -> %d\n",getFront());

    imprimir();

    apagar();
    return 0;
}

int getFront(){
    return l[0];
}

void enqueue(int elemento){
    if (pos < MAX)
        l[pos++] = elemento;
    else
        printf("Não foi possível inserir %d. Fila cheia.\n",elemento);
}

int dequeue(){
    if (pos) {
        int dado = l[0];
        for (int i = 0 ; i < pos -1 ; i++)
        l[i] = l[i+1];
        pos--;
        return dado;
    }
    else {
        printf("Não há elementos. Fila vazia.\n");
        exit(1);
    }
}

int tamanho(){
    return pos;
}

void imprimir(){
    printf("F[ ");
    for (int i = 0 ; i < pos ; i++)
        printf("%d ",l[i]);
    printf("]\n");
}

void apagar(){
    pos = 0;
}