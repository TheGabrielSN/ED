#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sNODE{
    char *str;
    unsigned col;
    struct sNODE *prox;
};

struct sMATRIZ{
    int lin, col;
    struct sNODE **m;
};

struct sMATRIZ m;

void inicializar(unsigned lin, unsigned col);
void atribuir(unsigned lin, unsigned col, char* str);
char *acessar(unsigned lin, unsigned col);
int tamanho();
void imprimir();
void apagar();

int main(){
    inicializar(10, 10);
    atribuir(0, 0, "R");
    atribuir(4, 4, "C");
    atribuir(8, 2, "C#");
    atribuir(2, 6, "C++");
    imprimir();
    printf("String na posição (2,6): %s\n", acessar(2, 6));
    printf("Tamanho: %d\n", tamanho());
    apagar();

    return 0;  
}

void inicializar(unsigned lin, unsigned col){
    m.lin = lin;
    m.col = col;
    m.m = (struct sNODE **) malloc(sizeof(struct sNODE *) * m.lin);

    for(int i=0; i<m.lin; i++){
        m.m[i] = NULL;
    }
}

void atribuir(unsigned lin, unsigned col, char* str){
    if(lin < m.lin && col < m.col){
        struct sNODE *aux = m.m[lin], *ant = NULL;

        while(aux && col > aux->col){
            ant = aux;
            aux = aux->prox;
        }
        if(aux && aux->col == col){
            if(strcmp(str, "") == 0){
                if(ant == NULL){
                    m.m[lin] = aux->prox;
                } else {
                    ant->prox = aux->prox;
                }
                free(aux);
            } else {
                aux->str = (char *) malloc(sizeof(char)*strlen(str));
                strcpy(aux->str, str);
            }
        } else if(strcmp(str, "") != 0){
            struct sNODE *novo = (struct sNODE *) malloc(sizeof(struct sNODE));
            novo->col = col;
            novo->prox = aux;
            novo->str = (char *) malloc(sizeof(char)*strlen(str));
            strcpy(novo->str, str);
            if(ant == NULL){
                m.m[lin] = novo;
            } else {
                ant->prox = novo;
            }
        }
    } else {
        printf("Não é possível inserir elementos fora da Matriz.\n");
        exit(1);
    }
    return;
}

char *acessar(unsigned lin, unsigned col){
    if(lin < m.lin && col < m.col){
        struct sNODE *aux = m.m[lin];

        while(aux && col > aux->col){
            aux = aux->prox;
        }
        if(aux && col == aux->col){
            return aux->str;
        }
        return "";
    } else {
        printf("Não é porrsível acessar elementos fora da Matriz.\n");
        exit(1);
    }
}

int tamanho(){
    return m.lin * m.col;
}

void imprimir(){
    printf("M[\n");
    for(int l=0; l<m.lin; l++){
        struct sNODE *aux = m.m[l];
        for(int c=0; c<m.col; c++){
            if(aux && c==aux->col){
                printf("%4s ", aux->str);
                aux = aux->prox;
            } else {
                printf("%4c ", '""');
            }
        }
        printf("\n");
    }
    printf("]\n");
    return;
}

void apagar(){
    for(int i=0; i<m.lin; i++){
        struct sNODE *aux = m.m[i], *ant = NULL;

        while(aux){
            ant = aux;
            aux = aux->prox;
            free(ant);
        }
    }
    free(m.m);
    return;
}