/*Implemente funções não recursivas para realizar os três tipos de percurso em uma árvore binária.*/

#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

struct NO{
    int info;
    struct NO *esq;
    struct NO *dir;
};

void emOrdemIterativo(ArvBin *raiz) {
    if(raiz == NULL || *raiz == NULL) {
        return;
    }

    struct NO *pilha[100];
    struct NO *curr;
    int topo = 0;
    curr = *raiz;

    while(curr != NULL || topo > 0) {
        if(curr != NULL) {
            pilha[topo] = curr;
            curr = curr->esq;
            topo++;
        }
        else {
            curr = pilha[topo-1];
            printf("%d\n", curr->info);
            curr = curr->dir;
            topo--;
        }
    }
    
}

void preOrdemIterativo(ArvBin *raiz) {
    if(raiz == NULL || *raiz == NULL) {
        return;
    }

    struct NO *pilha[50];
    struct NO *curr;
    curr = *raiz;
    int topo = 0;

    while(curr != NULL || topo > 0) {
        if(curr != NULL) {
            printf("%d \n", curr->info);
            pilha[topo] = curr;
            curr = curr->esq;
            topo++;
        }
        else {
            curr = pilha[topo - 1];
            curr = curr->dir;
            topo--;
        }
        
    }
}

void posOrdemIterativo(ArvBin *raiz) {
    if(raiz == NULL || *raiz == NULL) {
        return;
    }

    struct NO *pilha[100];
    struct NO *curr;
    struct NO *last_visited = NULL;
    int topo = 0;
    curr = *raiz;

    while(curr != NULL || topo > 0) {
        if(curr != NULL) {
            pilha[topo++] = curr;
            curr = curr->esq;
        }
        else {
            struct NO *peek = pilha[topo-1];
            if(peek->dir != NULL && last_visited != peek->dir) {
                curr = peek->dir;
            }
            else {
                printf("%d\n", peek->info);
                last_visited = peek;
                topo--;
            }
        }
    }
}

int main() {
    int N = 6, dados[6] = {50,100,30,32,35,29};

    ArvBin* raiz = cria_ArvBin();

    for(int i = 0; i < N; i++)
    {
        insere_ArvBin(raiz, dados[i]);
    }

    posOrdemIterativo(raiz);

    return 0;
}