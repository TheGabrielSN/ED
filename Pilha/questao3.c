#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
    int pos, MAX, erro;
    char *arr;
} PILHA;

void criar(PILHA *p);
void apagar(PILHA *p);
void push(PILHA *p, char *str);
char *pop(PILHA *p);
void comparar(PILHA *p);
void imprimir(PILHA *p);

int main(){
    PILHA pilha;
    criar(&pilha);
    char str[100];
    printf("Digite sua string: \n");
    scanf( "%[^\n]s", str);
    int cont = 0;
    while(cont < strlen(str)){
        push(&pilha, &str[cont]);
        cont++;
    }
    comparar(&pilha);
    apagar(&pilha);

    return 0;
}

void criar(PILHA *p){
    p->arr = (char*) malloc(sizeof(char)*100);
    if(p->arr == NULL){
        exit(1);
    }
    p->MAX = 0;
    p->pos = 0;
    p->erro = 0;

    return;
}

void apagar(PILHA *p){
    p->pos = 0;
    p->MAX = 0;
    p->erro = 0;
    free(p->arr);

    return;
}

void push(PILHA *p, char *str){
    if (p->pos < 100){
        p->arr[p->pos] = *str;
        p->pos++;
        p->MAX++;
    } else {
        printf("Não foi possível inserir %c. Pilha cheia.\n",*str);
    }

    return;
}

char *pop(PILHA *p){
    if(p->pos){
        return &p->arr[--p->pos];
    } else {
        printf("Remoção impossivel de ser realizada, pilha vazia!");
        exit(1);
    }
}

void comparar(PILHA *p){
    int par = 0, col = 0, cha = 0;
    while(p->pos > 0){
        char *str = pop(p);
        /*-----> contoler parenteses <-----*/
        if(par == 0 && str[0] == ')'){
            par = 1;
        } else if(par == 0 && str[0] == '('){
            p->erro++;
        }
        if(par == 1 && str[0] == '('){
            par = 0;
        }
        /*-----> contoler colchetes <-----*/
        if(col == 0 && str[0] == ']'){
            col = 1;
        } else if(col == 0 && str[0] == '['){
            p->erro++;
        }
        if(col == 1 && str[0] == '['){
            col = 0;
        }
        /*-----> contoler chaves <-----*/
        if(cha == 0 && str[0] == '}'){
            cha = 1;
        } else if(cha == 0 && str[0] == '{'){
            p->erro++;
        }
        if(cha == 1 && str[0] == '{'){
            cha = 0;
        }
    }

    if(p->erro > 0){
        printf("Não Balanceada\n");
    } else {
        printf("Balanceada\n");
    }

    return;
}

void imprimir(PILHA *p){
    printf("P[ ");
    for (int i = p->pos -1 ; i >= 0 ; i--)
        printf("%c ",p->arr[i]);
    printf("]\n");
}