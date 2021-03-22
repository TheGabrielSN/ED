#include <stdio.h>
#include <stdlib.h>

struct sNODE{
    unsigned col;
    unsigned dado;
    struct sNODE *prox;
};

struct sMATRIZ{
    int lin, col;
    struct sNODE **m;
};

struct sMATRIZ m;

/***** Funções adicionadas *****/
int getMax();           //a
int getMin();           //b
void diagonalP();       //c
void diagonalS();       //"
int count(int valor);   //d
/*--*/

void inicializar(unsigned t_lin, unsigned t_col);

void atribuir(unsigned lin, unsigned col, int dado);
int acessar(unsigned lin, unsigned col);

int tamanho();
void imprimir();
void apagar();

int main(void) {
    inicializar(10, 10);
    for(int l = 0; l<10; l++){
        for(int c = 0; c<10; c++){
            atribuir(l, c, l*c);
        }
    }
    imprimir();

    printf("Valor maximo: %d\n", getMax());
    printf("Valor minimo: %d\n", getMin());
    diagonalP();
    diagonalS();
    printf("10 parece %d vezes\n", count(10));

    apagar();
    return 0;
}

//a
int getMax(){
    int max = 0;
    for (int i = 0; i < m.lin; i++) {
        struct sNODE *aux = m.m[i];
        while(aux) {
            if (max > aux->dado) {
                max = aux->dado;
            }
            aux = aux->prox;
        }
    }
    return max;
}

//b
int getMin(){
    int min = 0;
    for (int i = 0; i < m.lin; i++) {
        struct sNODE *aux = m.m[i];
        while(aux) {
            if (min < aux->dado) {
                min = aux->dado;
            }
            aux = aux->prox;
        }
    }
    return min;
}

//c
void diagonalP(){
    char spc = ' ';
    printf("M[\n");
    for (int i = 0; i < m.lin; i++) {
        struct sNODE *aux = m.m[i];

        for (int j = 0; j < m.col; j++){
            if (aux && j == aux->col) {
                if(i == j){
                    printf("%4d ",aux->dado);
                } else {
                    printf("%2c ", spc);
                }
                aux = aux->prox;
            } else {
                if(i == j){
                    printf("%4d ",0);
                } else {
                    printf("%2c ", spc);
                };
            }
        }
        printf("\n");
    }
    printf("]\n");
}

//c
void diagonalS(){
    char spc = ' ';
    printf("M[\n");
    for (int i = 0; i < m.lin; i++) {
        struct sNODE *aux = m.m[i];

        for (int j = 0; j < m.col; j++){
            if (aux && j == aux->col) {
                if(i+j == m.lin-1){
                    printf("%4d ",aux->dado);
                } else {
                    printf("%2c ", spc);
                }
                aux = aux->prox;
            } else {
                if(i+j == m.lin-1){
                    printf("%4d ",0);
                } else {
                    printf("%2c ", spc);
                };
            }
        }
        printf("\n");
    }
    printf("]\n");
}

//d
int count(int valor){
    int count = 0;
    for(int i = 0; i < m.lin; i++){
        struct sNODE *aux = m.m[i];
        while(aux){
            if(aux->dado == valor){
                count++;
            }
            aux = aux->prox;
        }
    }
    return count;
}

void inicializar(unsigned t_lin, unsigned t_col){
    m.lin = t_lin;
    m.col = t_col;
    m.m = (struct sNODE **) malloc(sizeof(struct sNODE *) * m.lin);

    for (int i = 0 ; i < m.lin ; i++)
        m.m[i] = NULL;
}

void atribuir(unsigned lin, unsigned col, int dado) {
    if (lin < m.lin && col < m.col) {
        struct sNODE *aux = m.m[lin], *ant = NULL;

        while (aux && col > aux->col) {
            ant = aux;
            aux = aux->prox;
        }

        if (aux && aux->col == col){
            if (dado == 0) {
                if (ant == NULL)m.m[lin] = aux->prox;
                else ant->prox = aux->prox;
                free(aux);
            } else aux->dado = dado;
        } else if (dado != 0) {
            struct sNODE *novo = (struct sNODE *) malloc(sizeof(struct sNODE));
            novo->col = col;
            novo->dado = dado;
            novo->prox = aux;
            if (ant == NULL) m.m[lin] = novo;
            else ant->prox = novo;
        }

    } else {
        printf("Não é possível inserir elementos fora da Matriz.\n");
        exit(0);
    }
}

int acessar(unsigned lin, unsigned col) {
    if (lin < m.lin && col < m.col) {
        struct sNODE *aux = m.m[lin];

        while (aux && col > aux->col)
        aux = aux->prox;
        
        if (aux && col == aux->col)
        return aux->dado;
        
        return 0;
    } else {
        printf("Não é possível acessar elementos fora da Matriz.\n");
        exit(0);
    }
}

int tamanho() {
    return m.lin * m.col;
}

void imprimir(){
    printf("M[\n");
    for (int i = 0 ; i < m.lin ; i++) {
        struct sNODE *aux = m.m[i];

        for (int j = 0 ; j < m.col ; j++) {
            if (aux && j == aux->col) {
                printf("%4d ",aux->dado);
                aux = aux->prox;
            } else printf("%4d ",0);
        }
        printf("\n");
    }
    printf("]\n");
}

void apagar(){
    for (int i = 0 ; i < m.lin ; i++) {
        struct sNODE *aux = m.m[i], *ant = NULL;

        while (aux) {
            ant = aux;
            aux = aux->prox;
            free(ant);
        }
    }
    free(m.m);
}