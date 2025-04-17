/*Escreva uma função que encontre o maior valor existente em uma árvore binária de busca*/

#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

struct NO{
    int info;
    struct NO *esq;
    struct NO *dir;
};

struct NO* buscaMaiorNo(ArvBin *raiz) {
    if(raiz == NULL || *raiz == NULL) {
        return NULL;
    }

    if((*raiz)->dir != NULL) {
        buscaMaiorNo((&(*raiz)->dir));
    }
    else {
        return (*raiz);
    }
    
}

int main() {
    int N = 12, dados[12] = {50,100,30,32,21,40,29,200, 300, 20000, 500, 350};

    ArvBin* raiz = cria_ArvBin();

    for(int i = 0; i < N; i++)
    {
        insere_ArvBin(raiz, dados[i]);
    }

    struct NO *novo = (struct NO*) malloc(sizeof(struct NO));

    novo = buscaMaiorNo(raiz);

    printf("%d ", novo->info);

    return 0;
}

