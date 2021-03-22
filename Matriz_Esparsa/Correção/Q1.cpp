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

void inicializar(unsigned t_lin, unsigned t_col);

void atribuir(unsigned lin, unsigned col, int dado);
int acessar(unsigned lin, unsigned col);

unsigned getMax();
unsigned getMin();
void diagonalP();
void diagonalS();
int count(unsigned num);

int tamanho();
void imprimir();
void apagar();

int main(void) {
  inicializar(4,4);

  atribuir(0, 0, 4);
  atribuir(0, 1, 3);
  atribuir(0, 3, 5);
  atribuir(3, 2, 3);
  atribuir(1, 0, 7);
  atribuir(3, 0, 6);
  atribuir(1, 1, 1);
  atribuir(3, 3, 9);

  imprimir();

  printf("Max: %d\n",getMax());
  printf("Min: %d\n",getMin());

  printf("Diagonal Principal: ");
  diagonalP();
  printf("Diagonal Secundária: ");
  diagonalS();

  printf("Count 0: %d\n",count(0));
  printf("Count 3: %d\n",count(3));

  printf("Tamanho da matriz: %d \n",tamanho());

  return 0;
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
        if (ant == NULL) m.m[lin] = aux->prox;
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

unsigned getMax() {
  unsigned maior = acessar(0,0);

  for (int i = 0 ; i < m.lin ; i++) {
    struct sNODE *aux = m.m[i];

    while (aux) {
      if (aux->dado > maior)
        maior = aux->dado;
      aux = aux->prox;
    }
  }
  return maior;
}

unsigned getMin() {
  unsigned menor = acessar(0,0);

  for (int i = 0 ; i < m.lin ; i++) {
    struct sNODE *aux = m.m[i];
    int cont = 0;

    while (aux) {
      if (aux->dado < menor)
        menor = aux->dado;
      aux = aux->prox;
      cont++;
    }

    if (cont < m.col) {
      menor = 0;
      break;
    }
  }
  return menor;
}

void diagonalP() {
  if (m.lin == m.col) {
    for (int i = 0 ; i < m.lin ; i++) 
      printf("%d ",acessar(i,i));
  } else {
    printf("Matriz não quadrada!");
  }
  printf("\n");
}

void diagonalS() {
  if (m.lin == m.col) {
    for (int i = 0 ; i < m.lin ; i++) 
      printf("%d ",acessar(i,m.col - i - 1));
  } else {
    printf("Matriz não quadrada!");
  }
  printf("\n");
}

int count(unsigned num) {
  int ocorr = 0;
  int t_ele = 0;
  for (int i = 0 ; i < m.lin ; i++) {
    struct sNODE *aux = m.m[i];
    while (aux) {
      if (num == aux->dado)
        ocorr++;
      aux = aux->prox;
      t_ele++;
    }
  }
  if (num > 0)
    return ocorr;
  else
    return m.lin * m.col - t_ele;
}
