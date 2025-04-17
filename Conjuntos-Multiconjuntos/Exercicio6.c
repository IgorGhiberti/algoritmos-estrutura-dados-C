/*Implemente uma função para verificar se dois multiconjuntos são iguais. Eles são iguais se:
tiverem o mesmo número de elementos e cada elemento aparecer a mesma quantidade de vezes.*/

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

int consultaMulti(Bag *b, int val) {
    if(b == NULL) {
        return 0;
    }
    int count = 0;
    struct NO *no = b->inicio;
    while(no != NULL) {
        if(no->valor == val)
            count++;
        no = no->prox;
    }
    return count;
}

int ehIgualMulticonjunto(Bag *a, Bag *b) {
    if(a == NULL || b == NULL) {
        return 1;
    }

    if(a->qtd != b->qtd) {
        return 0;
    }

    struct NO *no = a->inicio;
    while(no != NULL) {
        int resultA = consultaMulti(a, no->valor);
        int resultB = consultaMulti(b, no->valor);
        if(resultA != resultB)
            return 0;
        no = no->prox;
    }
    return 1;
}

int main() {
    int numeros[10] = {5,5,7,12,13,98,54,32, 90, 87};
    int numeros3[10] = {87,5,5,12,13,98,54,7, 90, 5};
    int numeros2[12] = {5,6,7,12,13,98,54,32, 90, 89, 92, 95};

    Bag *b = criaBag();

    for(int i = 0; i < 10; i++) {
        insereBag(b, numeros[i]);
    }

    Bag *b2 = criaBag();

    for(int i = 0; i < 10; i++) {
        insereBag(b2, numeros3[i]);
    }

    int result = ehIgualMulticonjunto(b, b2);
    printf("%d", result);

    return 0;
}