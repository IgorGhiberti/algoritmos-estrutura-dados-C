/*Escreva uma função que percorra uma árvore binária e conte seu número de nós.*/
#include <stdlib.h>
#include <stdio.h>
#include "ArvoreBinaria.h"

struct NO{
    int info;
    struct NO *esq;
    struct NO *dir;
};

ArvBin* cria_ArvBin(){
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

int insere_ArvBin(ArvBin* raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* novo;
    novo = (struct NO*) malloc(sizeof(struct NO));
    if(novo == NULL)
        return 0;
    novo->info = valor;
    novo->dir = NULL;
    novo->esq = NULL;

    if(*raiz == NULL)
        *raiz = novo;
    else{
        struct NO* atual = *raiz;
        struct NO* ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(valor == atual->info){
                free(novo);
                return 0;
            }

            if(valor > atual->info)
                atual = atual->dir;
            else
                atual = atual->esq;
        }
        if(valor > ant->info)
            ant->dir = novo;
        else
            ant->esq = novo;
    }
    return 1;
}


int contaNos(ArvBin *raiz) {
    if(raiz == NULL) {
        return 0;
    }

    if(*raiz == NULL) {
        return 0;
    }

    int altEsq = contaNos(&((*raiz)->esq));
    int altDir = contaNos(&((*raiz)->dir));

    return (altEsq + altDir + 1);
}

int main() {

    int N = 8, dados[8] = {50,100,30,20,40,45,35,37};

    ArvBin* raiz = cria_ArvBin();

    for(int i = 0; i < N; i++)
    {
        insere_ArvBin(raiz, dados[i]);
    }

    int res = contaNos(raiz);

    printf("%d", res);

    return 0;
}



