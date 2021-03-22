#include <stdio.h>
#include <stdlib.h>

const unsigned MAX = 10;
int l[MAX], ini = 0, fim = 0;

void inserir_fim(int elemento);
int remover_ini();

void inserir_ini(int elemento);
int remover_fim();

int tamanho();
void imprimir();
void apagar();

int main(void) {
  inserir_ini(3);
  inserir_fim(7);

  inserir_ini(4);
  inserir_fim(8);

  inserir_ini(5);
  inserir_fim(9);

  inserir_ini(0);
  inserir_fim(10);

  inserir_fim(11);

  inserir_ini(-1);

  imprimir();

  printf("Removendo do inicio: %d\n", remover_ini());
  imprimir();
  printf("Removendo do fim: %d\n", remover_fim());
  imprimir();

  printf("Removendo do inicio: %d\n", remover_ini());
  imprimir();
  printf("Removendo do fim: %d\n", remover_fim());
  imprimir();

  return 0;
}

void inserir_fim(int elemento){
  if ((fim + 1) != ini && !(fim + 1 == MAX && !ini) ){
    l[fim] = elemento;
    //fim = (fim + 1) % MAX;
    fim++;
    if (fim == MAX) fim = 0;
  }
  else
    printf("Não foi possível inserir %d. Fila cheia.\n",elemento);
}

int remover_ini(){
  if (ini != fim) {
    int dado = l[ini];
    //ini = (ini + 1) % MAX;
    ini++;
    if (ini == MAX) ini = 0;
    return dado;
  }
  else {
    printf("Não há elementos. Fila vazia.\n");
    exit(1);
  }
}

void inserir_ini(int elemento){
  //if ((fim + 1) != ini && !(fim + 1 == MAX && !ini) ){
  if ((ini - 1) != fim && !(ini - 1 == -1 && fim == MAX - 1) ){
    ini--;
    if (ini == -1) ini = MAX - 1;

    l[ini] = elemento;
  }
  else
    printf("Não foi possível inserir %d. Fila cheia.\n",elemento);
}

int remover_fim(){
  if (ini != fim) {

    fim--;
    if (fim == -1) fim = MAX - 1;

    return l[fim];
  }
  else {
    printf("Não há elementos. Fila vazia.\n");
    exit(1);
  }
}



int tamanho(){
  if (ini <= fim)
    return fim - ini;
  else
    return MAX - (ini - fim);
}

void imprimir(){
  printf("F[ ");
  for (int i = ini ;  ; i++) {
    if (i == MAX) i = 0;
    if (i == fim) break;
    printf("%d ",l[i]);
  }
  printf("]\n");
}

void apagar(){
  ini = fim = 0;
}
