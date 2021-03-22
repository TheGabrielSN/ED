#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 100
#define controler 20

typedef struct{
    int pos;
    char *arr;
} PILHA;

void criar(PILHA *p);
void apagar(PILHA *p);
void push(PILHA *p, char *str);
char *pop(PILHA *p);
void organizar(PILHA *p);
void imprimir(PILHA *p);

int main(){
    PILHA pilha;
    criar(&pilha);
    char str[MAX];
    printf("Digite sua string: \n");
    scanf( "%[^\n]s", str);
    int cont = 0;
    while(cont < strlen(str)){
        push(&pilha, &str[cont]);
        cont++;
    }
    organizar(&pilha);
    imprimir(&pilha);
    apagar(&pilha);

    return 0;
}

void criar(PILHA *p){
    p->arr = (char*) malloc(sizeof(char)*100);
    if(p->arr == NULL){
        exit(1);
    }
    p->pos = 0;
}

void apagar(PILHA *p){
    p->pos = 0;
    free(p->arr);
}

void push(PILHA *p, char *str){
    if (p->pos < MAX){
        p->arr[p->pos] = *str;
        p->pos++;
    } else {
        printf("Não foi possível inserir %c. Pilha cheia.\n",*str);
    }
}

char *pop(PILHA *p){
    if(p->pos){
        return &p->arr[--p->pos];
    } else {
        printf("Remoção impossivel de ser realizada, pilha vazia!");
        exit(1);
    }
}

void organizar(PILHA *p){
    struct lista{ char elemento[controler]; };
    struct lista *lista = (struct lista*) malloc(sizeof(struct lista)*controler);
    char newarr[MAX], str[MAX], aux = ' ';
    int c = p->pos-1, cc=0, ccc=0;
    while(c>-1){
        if(p->arr[c] != ' '){
            str[cc] = p->arr[c];
            str[cc+1] = '\0';
            cc++; c--;
        } else if(p->arr[c] == ' '){
            strcpy(lista[ccc].elemento, str);
            strcpy(lista[ccc].elemento, &aux);
            ccc++; cc=0; c--;
        }
    }

    strcpy(lista[ccc].elemento, str);

    for(;ccc>-1;ccc--){
        strcat(newarr, lista[ccc].elemento);
    }
    strcat(newarr, &aux);
    newarr[strlen(p->arr)]='\0';
    strcpy(p->arr, newarr);
    free(lista);
}

void imprimir(PILHA *p){
    printf("%s\n", p->arr);
}