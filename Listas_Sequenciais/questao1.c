#include <stdio.h>
#include <stdlib.h>
#define MAX 10
//const unsigned MAX = 10; -> isso estava dando erro para ser usado na lista de inteiro.
int l[MAX], pos = 0;

void inserir_ini(int elemento);
void inserir(int elemento);
void remover(int elemento);
int buscar(int elemento);

int obter(int indice);
int tamanho();
void imprimir();
void apagar();

int main(void) {
    int aux;
    printf("Digite os valores da lista: ");
    for(int i = 0; i<10; i++){
        scanf(" %d", &aux);
        inserir(aux);
    }

    imprimir();

    printf("Digite o númeor a ser removida: ");
    scanf(" %d", &aux);
    remover(aux);

    imprimir();

    printf("Digite o númeor a ser inserido no início: ");
    scanf(" %d", &aux);
    inserir_ini(aux);

    imprimir();

    printf("Digite o númeor que deseja buscar: ");
    scanf(" %d", &aux);
    printf("Index: %d Item: %d\n", buscar(aux), obter(buscar(aux)));

    apagar();
}

void inserir_ini(int elemento){
    int p;
    if (pos < MAX){
        for (p = pos ; p > 0 ; p--){
            l[p] = l[p-1];
        }
	    l[0] = elemento;
	    pos ++;
    } else {
	    printf("Nao foi possivel inserir %d no inicio. Lista cheia.\n",elemento);
    }
}

void inserir(int elemento){
  if (pos < MAX)
	l[pos++] = elemento;
  else {
	printf("Não foi possível inserir %d. Lista cheia.\n",elemento);
  }
}

int buscar(int elemento){
  for (int i = 0 ; i < pos ; i++){
	if (l[i] == elemento)
  	return i;
  }
  return -1;
}

void remover(int elemento){
  int p = buscar(elemento);
 
  if (p == -1)
	return;
 
  for (int i = p ; i < pos -1; i++)
	l[i] = l[i+1];
  pos--;
}

int obter(int indice){
  if (indice < 0 || indice >= pos) {
	printf("Indice %d fora dos limites da Lista.\n", indice);
	exit(1);
  }
  return l[indice];
}

int tamanho(){
  return pos;
}

void imprimir(){
  for (int i = 0 ; i < pos ; i++)
	printf("%d ",l[i]);
  printf("\n");
}

void apagar(){
  pos = 0;
}