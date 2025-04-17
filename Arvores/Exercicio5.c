/*Escreva uma função de árvore binária que percorra todos os nós e exclua aqueles com valor par*/

#include <stdlib.h>
#include <stdio.h>

struct NO{
    int info;
    struct NO *esq;
    struct NO *dir;
};

typedef struct NO* ArvBin;

ArvBin* cria_ArvBin(){
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void insereDireita(struct NO* no, int valor);
void insereEsquerda(struct NO* no, int valor);

void insereDireita(struct NO* no, int valor) {
    if(no->dir == NULL) {
        struct NO *novo = (struct NO*) malloc(sizeof(struct NO));
        novo->info = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        no->dir = novo;
    } else {
        if(valor > no->dir->info)
            insereDireita(no->dir, valor);
        else
            insereEsquerda(no->dir, valor);
    }
}

void insereEsquerda(struct NO* no, int valor) {
    if(no->esq == NULL) {
        struct NO *novo = (struct NO*) malloc(sizeof(struct NO));
        novo->info = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        no->esq = novo;
    } else {
        if(valor > no->esq->info)
            insereDireita(no->esq, valor);
        else
            insereEsquerda(no->esq, valor);
    }
}

void insere_ArvBin(ArvBin* raiz, int valor){

    if(raiz == NULL || *raiz == NULL) { //Ou seja, sem filhos
        struct NO *novo = (struct NO*) malloc(sizeof(struct NO));
        novo->info = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        *raiz = novo;
    } else {
        if(valor > (*raiz)->info)
            insereDireita(*raiz, valor);
        else
            insereEsquerda(*raiz, valor);
    }
}

void excluiNoPar(ArvBin *raiz) {

    if(raiz == NULL || *raiz == NULL) {
        return;
    }

    excluiNoPar((&(*raiz)->esq));
    excluiNoPar((&(*raiz)->dir));

    if((*raiz)->info % 2 == 0) {
        struct NO* atual = *raiz;

        if(atual->esq == NULL && atual->dir == NULL) {
            free(atual);
            *raiz = NULL;
        } else if(atual->dir == NULL) {
            *raiz = atual->esq;
            free(atual);
        } else if(atual->esq == NULL) {
            *raiz = atual->dir;
            free(atual);
        } else {
            struct NO* sub = atual->esq;
            struct NO* paiSub = atual;

            while(sub->dir != NULL) {
                paiSub = sub;
                sub = sub->dir;
            }

            if(paiSub != atual) {
                paiSub->dir = sub->esq;
                sub->esq = atual->esq;
            }

            sub->dir = atual->dir;
            *raiz = sub;
            free(atual);
        }
    }
}

int main() {

    int N = 7, dados[7] = {50,100,30,32,21,40,29};

    ArvBin* raiz = cria_ArvBin();

    for(int i = 0; i < N; i++)
    {
        insere_ArvBin(raiz, dados[i]);
    }

    removeArvBin(*raiz, 30);

    // excluiNoPar(raiz);

    return 0;
}