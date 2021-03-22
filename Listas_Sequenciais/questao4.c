#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned MAX;
    int *arr, pos;
} List;

void criar(List *lst, int tam_MAX);
void apagar(List *lst);

void inserir_ord(List *lst, int elemento);
void remover(List *lst, int elemento);
int buscar(List *lst, int elemento);

int obter(List *lst, int indice);
int tamanho(List *lst);
void imprimir(List *lst);

int main(void){
    int aux;
    List listaI;
    printf("Bem-Vindo a Listas!!\n");
    printf("Digite o valor do tamanho máximo da lista: ");
    scanf("%d", &aux);
    criar(&listaI, aux);
    printf("Digite 0 para insernção automatica ou 1 para inserção manual: ");
    scanf(" %d", &aux);
    if(aux == 1){
        printf("Digite os valores da Lista: ");
        for(int i = 0; i < listaI.MAX; i++){
            scanf(" %d", &aux);
            inserir_ord(&listaI, aux);
        }
    } else if(aux == 0){
        for(int i = 0; i < listaI.MAX; i++){
            inserir_ord(&listaI, i);
        }
    }
    imprimir(&listaI);

    printf("Digite um elemento para a remoção: ");
    scanf("%d", &aux);
    remover(&listaI, aux);

    imprimir(&listaI);
    
    printf("Digite um item que deseja buscar: ");
    scanf("%d", &aux);
    printf("Index: %d Item: %d\n", buscar(&listaI, aux), obter(&listaI, buscar(&listaI, aux)));

    apagar(&listaI);

    return 0;
}

void criar(List *lst, int tam_MAX){
    lst->arr = (int*)malloc(sizeof(int) * tam_MAX);
    if(lst->arr == NULL){
        exit(1);
    }
    lst->MAX = tam_MAX;
    lst->pos = 0;
}
void apagar(List *lst){
    free(lst->arr);
    printf("Exclusão da lista feita!\n");
}

void inserir_ord(List *lst, int elemento){
    int i, p;
    if(lst->pos < lst->MAX){
        for(i = 0; i < lst->pos; i++){
            if(lst->arr[i] == elemento){ break; }
        }
        for(p = lst->pos; p > i; p--){
            lst->arr[p] = lst->arr[p-1];
        }
        lst->arr[i] = elemento;
        lst->pos++;
    } else {
        printf("Erro Insert Item In List.\n");
    }
}
void remover(List *lst, int elemento){
    int p = buscar(lst, elemento);
    if(p == -1) { return; }
    for(int i = p; i < lst->pos; i++){
        lst->arr[i] = lst->arr[i+1];
    }
    lst->pos--;
}
int buscar(List *lst, int elemento){
    for(int i = 0; i < lst->pos; i++){
        if(lst->arr[i] == elemento){ return i;}
    }
    return -1;
}

int obter(List *lst, int indice){
    if(indice < 0 || indice >= lst->pos){
        printf("Index Out The Range.\n");
        exit(1);
    }
    return lst->arr[indice];
}

int tamanho(List *lst){
    return lst->pos;
}

void imprimir(List *lst){
    for(int i = 0; i < lst->pos; i++){
        printf("%d ", lst->arr[i]);
    }
    printf("\n");
}