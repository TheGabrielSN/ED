#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct{
    int pos;
    char *arr;
} PILHA;

void criar(PILHA *p);
void apagar(PILHA *p);
void push(PILHA *p, char *str);
char pop(PILHA *p);
void verificar(PILHA *p);

int main(){
    PILHA equa;
    criar(&equa);
    char ent[1];
    while(1){
        ent[0] = getchar();
		if(ent[0]=='\n'){ break; }
        push(&equa, ent);
    }

    verificar(&equa);

    apagar(&equa);
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

char pop(PILHA *p){
    if(p->pos){
        return p->arr[--p->pos];
    } else {
        printf("Remoção impossivel de ser realizada, pilha vazia!");
        exit(1);
    }
}

void verificar(PILHA *p){
    char pri[1], item[1];
    int a=0, f=0, max = p->pos;
    for(int i=0; i<max; i++){
        item[0] = pop(p);
        if(i==0){pri[0]=item[0];}
        if(item[0]=='('){ a++; }
        if(item[0]==')'){ f++; }
    }
    if(a != f || pri[0]=='(' || item[0]==')'){ printf("Não OK"); } else {printf("OK");}
}