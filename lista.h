#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tipoElem
{
    int valor;
    struct tipoElem *prox;

}TElem;

typedef struct tipoNo
{
    int valor;
    struct tipoNo *pai;
    struct tipoNo *esq, *dir;

}TNo;

TNo *raiz;

int menu();
TElem *inserir(TNo **raiz);
TNo *inicializaArvore();
TNo *criarNo(TElem *atual);
TNo *insereArvore(TNo **nodo, TElem *atual);
TNo *removerArvore(TNo **nodo, int *argumento);
void caminhamento_em_ordem(TNo *nodo);
void caminhamento_pre_ordem(TNo *nodo);
void caminhamento_pos_ordem(TNo *nodo);
void buscarArvore(TNo *nodo, int *argumento);

