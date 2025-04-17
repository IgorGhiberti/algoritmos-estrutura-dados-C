/*Duas árvores binárias são SIMILARES se possuem a mesma estrutura de nós (os valores podem ser diferentes).
Implemente uma função para verificar se duas árvores são semelhantes.*/

#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

struct NO{
    int info;
    struct NO *esq;
    struct NO *dir;
};

int ehArvoreSimilar(ArvBin *raiz1, ArvBin *raiz2) {
    if(raiz1 == NULL && raiz2 == NULL) {
        return 1;
    }

    if(raiz1 == NULL || raiz2 == NULL) {
        return 0;
    }

    if(*raiz1 == NULL && *raiz2 == NULL) {
        return 1;
    }
    if(*raiz1 == NULL || *raiz2 == NULL) {
        return 0;
    }

    int esquerdaSimilar = ehArvoreSimilar(&(*raiz1)->esq, &(*raiz2)->esq);
    int direitaSimilar = ehArvoreSimilar(&(*raiz1)->dir, &(*raiz2)->dir);

    return esquerdaSimilar && direitaSimilar;
}

int main() {
    int N = 4, dados[4] = {50,100,30,32};
    int N2 = 6, dados2[6] = {50,100,30,32,21, 40};
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

    int result = ehArvoreSimilar(raiz1, raiz2);

    printf("%d", result);

    return 0;
}
