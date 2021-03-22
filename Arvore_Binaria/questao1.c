#include <stdio.h>
#include <stdlib.h>

struct sNODE{
  int dado;
  struct sNODE *esq, *dir;
};

struct sNODE *raiz = NULL;

/***** Início dos modulos das funções adicionadas *****/
struct sNODE *getMax(struct sNODE *no);                                 //a
struct sNODE *getMin(struct sNODE *no);                                 //b
void mostrarFolhas(struct sNODE *no);                                   //c
int distanciaDaRaiz(struct sNODE *no, int dado);                        //d
int alturaArvore(struct sNODE *raizIni, struct sNODE *no, int dis);     //e
int distanciaEntre(struct sNODE *no, int p1, int p2, int dis);          //f
/***** Fim dos modulos das funções adicionadas *****/

struct sNODE *inserir(struct sNODE *no, int dado);
struct sNODE *remover(struct sNODE *no, int dado);

void emOrdem(struct sNODE *no);
void preOrdem(struct sNODE *no);
void posOrdem(struct sNODE *no);

struct sNODE *buscar(struct sNODE *no, int dado);
int obter(struct sNODE *no);

struct sNODE *apagar(struct sNODE *no);


int main(){
    raiz = inserir(raiz, 4);
    raiz = inserir(raiz, 3);
    raiz = inserir(raiz, 5);
    raiz = inserir(raiz, 1);
    raiz = inserir(raiz, 6);
    raiz = inserir(raiz, 2);
    raiz = inserir(raiz, 7);
    raiz = inserir(raiz, 0);
    raiz = inserir(raiz, -1);

    emOrdem(raiz);
    printf("\n");
    preOrdem(raiz);
    printf("\n");
    posOrdem(raiz);
    printf("\n");

    printf("Valor Maximo da Arvore: %d\n", obter(getMax(raiz)));
    printf("Valor Minimo da Arvore: %d\n", obter(getMin(raiz)));
    printf("Folhas da Arvore: ");
    mostrarFolhas(raiz);
    printf("\n");
    printf("Distancia da raiz ate o no 6: %d\n", distanciaDaRaiz(raiz, 6));
    printf("Altura da Arvore: %d\n", alturaArvore(raiz, raiz, 0));
    printf("Distancia Entre -1 e 7: %d\n", distanciaEntre(raiz, -1, 7, 0));

    raiz = apagar(raiz);

    return 0;
}

/***** Início das funções adicionadas *****/
// a
struct sNODE *getMax(struct sNODE *no){
    if(no->dir == NULL){
        return no;
    } else {
        no = getMax(no->dir);
    }
}

//b
struct sNODE *getMin(struct sNODE *no){
    if(no->esq == NULL){
        return no;
    } else {
        no = getMin(no->esq);
    }
}

//c
void mostrarFolhas(struct sNODE *no){
    if (no) {
        mostrarFolhas(no->esq);
        if(no->esq == no->dir){
            printf("%d ",no->dado);}
        mostrarFolhas(no->dir);
    }
}

//d
int distanciaDaRaiz(struct sNODE *no, int dado){
    struct sNODE *aux = no;
    int dis = 0;
    while(1){
        if(no){
            if(aux->dado == dado){
                return dis;
            } else if(aux->dir == aux->esq){
                printf("Dado não encontrado, impossível saber a distância.\n");
                exit(1);
            } else if(dado < aux->dado){
                aux = aux->esq;
                dis++;
            } else {
                aux = aux->dir;
                dis++;
            }
        }
    }
}

//e
int alturaArvore(struct sNODE *raizIni, struct sNODE *no, int dis){
    int aux;
    if (no) {
        dis = alturaArvore(raizIni, no->esq, dis);
        if(no->esq == no->dir){
            aux = distanciaDaRaiz(raizIni, no->dado);
            if(aux>dis){ dis = aux; }
        }
        dis = alturaArvore(raizIni, no->dir, dis);
    } else {
        return dis;
    }
}

//f
int distanciaEntre(struct sNODE *no, int p1, int p2, int dis){
    if(p1>p2){
        int aux = p1;
        p1 = p2;
        p2 = aux;
    }
    if(no){
        if(no->dado > p1 && no->dado > p2){
            dis = distanciaEntre(no->esq, p1, p2, dis);
        } else if(no->dado < p1 && no->dado < p2){
            dis = distanciaEntre(no->dir, p1, p2, dis);
        } else {
            dis = distanciaDaRaiz(no, p1);
            dis = dis + distanciaDaRaiz(no, p2);
            return dis;
        }
    }
}
/***** Fim das funções adicionadas *****/

struct sNODE *inserir(struct sNODE *no, int dado){
    if (!no) {
        no = (struct sNODE*) malloc(sizeof(struct sNODE));
        no->dado = dado;
        no->esq = no->dir = NULL;
    } else if (dado < no->dado)
        no->esq = inserir(no->esq,dado);
    else
        no->dir = inserir(no->dir,dado);

    return no;  
}

struct sNODE *remover(struct sNODE *no, int dado){
    struct sNODE *aux = NULL, *aux2 = NULL;

    if (no) {
        if (no->dado == dado) {
        if (no->esq == no->dir) {
                free(no);
                return NULL;
        }
        else if (!no->esq) {
                aux = no->dir;
                free(no);
                return aux;
        }
        else if (!no->dir) {
                aux = no->esq;
                free(no);
                return aux;
        } else {
                aux = aux2 = no->dir;
                while (aux->esq)
            aux = aux->esq;
                aux->esq = no->esq;
                free(no);
                return aux2;
        }
        }
        else {
        if (dado < no->dado)
                no->esq = remover(no->esq, dado);
        else
                no->dir = remover(no->dir, dado);
        }
    }
    return no;
}

void emOrdem(struct sNODE *no){
    if (no) {
        emOrdem(no->esq);
        printf("%d ",no->dado);
        emOrdem(no->dir);
    }
}

void preOrdem(struct sNODE *no){
    if (no) {
        printf("%d ",no->dado);
        preOrdem(no->esq);
        preOrdem(no->dir);
    }
}

void posOrdem(struct sNODE *no){
    if (no) {
        posOrdem(no->esq);
        posOrdem(no->dir);
        printf("%d ",no->dado);
    }
}

struct sNODE *buscar( struct sNODE *no, int dado){
    if (no) {
        if (no->dado == dado)
        return no;
        else if (dado < no->dado)
        return buscar(no->esq, dado);
        else
        return buscar(no->dir, dado);
    }
    
    return NULL;
}

int obter(struct sNODE *no) {
    if (no)
        return no->dado;
    else {
        printf("Nenhum dado para retornar.");
        exit(0);
    }
}

struct sNODE *apagar(struct sNODE *no){
    if (no) {
        no->esq = apagar(no->esq);
        no->dir = apagar(no->dir);
        free(no);
    }
    return NULL;
}