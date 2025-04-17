/*Duas árvores binárias são IGUAIS se possuem a mesma estrutura de nós e valores.
Implemente uma função para verificar se duas árvores são iguais.*/

#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

struct NO{
    int info;
    struct NO *esq;
    struct NO *dir;
};

int ehArvoreIgual(ArvBin *raiz1, ArvBin *raiz2) {
    if(raiz1 == NULL && raiz2 == NULL) {
        return 1;
    }

    if(*raiz1 == NULL && *raiz2 == NULL) {
        return 1;
    }

    if(*raiz1 == NULL || *raiz2 == NULL) {
        return 0;
    }

    int ehIgualEsq = 1;
    int ehIgualDir = 1;
    if((*raiz1)->info == (*raiz2)->info){
        if((*raiz1)->esq != NULL || (*raiz2)->esq != NULL) {
            ehIgualEsq = ehArvoreIgual((&(*raiz1)->esq), (&(*raiz2)->esq));
        }
        if((*raiz1)->dir != NULL || (*raiz2)->dir != NULL) {
            ehIgualDir = ehArvoreIgual((&(*raiz1)->dir), (&(*raiz2)->dir));
        }
    }
    else {
        return 0;
    }

    return ehIgualEsq == ehIgualDir;
}

int main() {
    int N = 6, dados[6] = {50,100,30,32,35, 29};
    int N2 = 5, dados2[5] = {50,100,30,32,35};
    ArvBin* raiz1 = cria_ArvBin();

    for(int i = 0; i < N; i++)
    {
        insere_ArvBin(raiz1, dados[i]);
    }

    ArvBin* raiz2 = cria_ArvBin();

    for(int i = 0; i < N2; i++)
    {
        insere_ArvBin(raiz2, dados2[i]);
    }

    int result = ehArvoreIgual(raiz1, raiz2);

    printf("%d", result);

    return 0;
}