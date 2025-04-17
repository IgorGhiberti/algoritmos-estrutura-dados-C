/*Implemente uma função que adicione os elementos de um multiconjunto ao fim de outro*/

#include <stdio.h>
#include <stdlib.h>
#include "Bag.h"

struct NO{
    int valor;
    struct NO *prox;
};

struct descritor{
    struct NO *inicio;
    struct NO *iterator;
    int qtd;
};

void insereNoFinalConjunto(Bag *a, Bag *b) {
    if(a == NULL || b == NULL) {
        return;
    }

    struct NO *no = a->inicio;
    while(no->prox != NULL) {
        no = no->prox;
    }

    no->prox = b->inicio;
}

int main() {
    int numeros[3] = {5,5,6};
    int numeros3[4] = {7,8,15};
    int numeros2[3] = {6,7,19};

    Bag *b = criaBag();

    for(int i = 0; i < 3; i++) {
        insereBag(b, numeros[i]);
    }

    Bag *b2 = criaBag();

    for(int i = 0; i < 3; i++) {
        insereBag(b2, numeros2[i]);
    }

    insereNoFinalConjunto(b, b2);

    imprimeBag(b);

    return 0;
}