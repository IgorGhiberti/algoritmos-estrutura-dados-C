/*Implemente a estrutura de dados conjunto, utilizando como base um multiconjunto*/

#include <stdio.h>
#include <stdlib.h>

struct NO{
    int valor;
    struct NO *prox;
};

struct descritor{
    struct NO *inicio;
    struct NO *iterator;
    int qtd;
};

typedef struct descritor Conjunto;

Conjunto* criaConjunto() {
    Conjunto* c = (Conjunto*) malloc(sizeof(Conjunto));

    if(c != NULL) {
        c->inicio = NULL;
        c->iterator = NULL;
        c->qtd = 0;
    }
    return c;
}

void liberaConjunto(Conjunto *c) {
    if(c == NULL) {
        return;
    }

    struct NO *no;

    while(c->iterator != NULL) {
        no = c->iterator;
        c->iterator = c->iterator->prox;
        free(no);
    }
    free(c);
}

int existeNoConjunto(Conjunto *c, int val) {
    if(c == NULL) {
        return 0;
    }

    struct NO *no;
    no = c->inicio;
    while(no != NULL) {
        if(no->valor == val)
            return 1;
        no = no->prox;
    }

    return 0;
}

int insereConjunto(Conjunto *c, int valor) {
    if(c == NULL) {
        return 0;
    }

    if(existeNoConjunto(c, valor)) {
        printf("O valor %d já existe no conjunto!\n", valor);
        return 0;
    }

    if(c ->inicio == NULL){ //Conjunto vazio
        struct NO *no = (struct NO*) malloc(sizeof(struct NO));
        no->prox = NULL;
        no->valor = valor;
        c->inicio = no;
    }
    else { //Conjunto não é vazio
        struct NO *no = (struct NO*) malloc(sizeof(struct NO));
        no->prox = c->inicio;
        no->valor = valor;
        c->inicio = no;
    }

    c->iterator = c->inicio;
    return 1;
}

int removeConjunto(Conjunto *c, int valor) {
    if(c == NULL) {
        return 0;
    }

    if(c->inicio == NULL) { //Conjunto vazio
        printf("Conjunto vazio!");
        return 0;
    }
    else {
        struct NO *no = (struct NO*) malloc(sizeof(struct NO));
        struct NO *ant = (struct NO*) malloc(sizeof(struct NO));
        no = c->inicio;
        while(no != NULL && no->valor != valor) {
            ant = no;
            no = no->prox;
        }
        if(no == c->inicio) { //É o primeiro elemento do conjunto
            c->inicio = NULL;
            c->iterator = NULL;
            free(no);
        }
        if(no->prox == NULL){ //É o último
            ant->prox = NULL;
            free(no);
        }
        else { //Ta no meio
            ant->prox = no->prox;
            free(no);
        }
    }
}

void imprimeConjunto(Conjunto *c) {
    if(c == NULL) {
        return;
    }

    struct NO *no;
    no = c->inicio;
    while(no != NULL) {
        printf("%d \n", no->valor);
        no = no->prox;
    }
}

int tamanhoConjunto(Conjunto *c) {
    if(c == NULL) {
        return 0;
    }
    int count = 0;
    struct NO *no;
    no = c->inicio;
    while(no != NULL) {
        count++;
        no = no->prox;
    }
    return count;
}

Conjunto* uneConjunto(Conjunto *c1, Conjunto *c2) {
    if(c1 == NULL || c2 == NULL) {
        return NULL;
    }

    Conjunto *c3 = criaConjunto();

    struct NO *no1 = c1->inicio;
    struct NO *no2 = c2->inicio;
    while(no1 != NULL) {
        insereConjunto(c3, no1->valor);
        no1 = no1->prox;
    }

    while(no2 != NULL) {
        insereConjunto(c3, no2->valor);
        no2 = no2->prox;
    }

    return c3;
}

Conjunto* intersescaoConjunto(Conjunto *c1, Conjunto *c2) {
    if(c1 == NULL || c2 == NULL) {
        return NULL;
    }

    Conjunto *c3 = criaConjunto();
    struct NO *no1;
    struct NO *no2;
    if(tamanhoConjunto(c1) < tamanhoConjunto(c2)) {
        no1 = c1->inicio;
        no2 = c2->inicio;
        while(no1 != NULL) {
            int result = existeNoConjunto(c2, no1->valor);
            if(result)
                insereConjunto(c3, no1->valor);
            no1 = no1->prox;
        }
    }
    else {
        no1 = c1->inicio;
        no2 = c2->inicio;
        while(no2 != NULL) {
            int result = existeNoConjunto(c1, no2->valor);
            if(result)
                insereConjunto(c3, no2->valor);
            no2 = no2->prox;
        }
    }

    return c3;
}

int main() {
    int numeros[10] = {5,6,7,12,13,98,54,32, 90, 87};
    int numeros2[12] = {5,6,7,12,13,98,54,32, 90, 89, 92, 95};
    Conjunto* c = criaConjunto();

    for(int i = 0; i < 10; i++) {
        insereConjunto(c, numeros[i]);
    }

    // removeConjunto(c, 7);
    // imprimeConjunto(c);

    Conjunto* c2 = criaConjunto();

    for(int i = 0; i < 12; i++) {
        insereConjunto(c2, numeros2[i]);
    }

    Conjunto* c3 = criaConjunto();

    //c3 = uneConjunto(c, c2);
    c3 = intersescaoConjunto(c, c2);
    imprimeConjunto(c3);
    
    return 0;
}



