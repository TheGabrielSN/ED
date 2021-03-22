#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100

typedef struct TAluno{
    char nome[max];
    int idade; 
    float altura;
} TAluno;

TAluno* criarAluno (char* nome, int idade, float altura);
void liberarAluno (TAluno* a);
void imprimirDados (TAluno* a);
void modificarDados (TAluno* a, char* novo_nome, int nova_idade, float nova_altura);

int main(){
    TAluno *aluno = criarAluno("Gabriel", 20, 1.80f);
    imprimirDados(aluno);
    modificarDados(aluno, "Jhon", 19, 1.85f);
    imprimirDados(aluno);
    liberarAluno(aluno);
    return 0;
}

TAluno* criarAluno (char* nome, int idade, float altura){
    TAluno *aluno = (TAluno*)(malloc(sizeof(TAluno)));
    strcpy(aluno->nome, nome);
    aluno->idade = idade;
    aluno->altura = altura;

    return aluno;
}

void liberarAluno (TAluno* a){
    free(a);
    return;
}
void imprimirDados (TAluno* a){
    printf("Nome: %s\t", a->nome);
    printf("Idade: %d\t", a->idade);
    printf("Altura: %.2f\n", a->altura);
    printf("-----------\n");
    return;
}
void modificarDados (TAluno* a, char* novo_nome, int nova_idade, float nova_altura){
    strcpy(a->nome, novo_nome);
    a->idade = nova_idade;
    a->altura = nova_altura;
    return;
}