/*Dada uma pilha que armazena caracteres, crie uma função que verifique se uma palavra é um palíndromo.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 50

struct Element {
    struct Element *prox;
    char letra;
};

struct Pilha {
    int qtd;
    struct Element *topo;
};

int isPalindromo(struct Pilha *pi)
{
    char temp[MAX-1];
    struct Element *curr = pi->topo;
    int i = 0;

    while(curr != NULL)
    {
        temp[i] = curr->letra;
        curr = curr->prox;
        i++;
    }

    curr = pi->topo;
    i = 0;

    while(curr != NULL)
    {
        if(curr->letra != temp[i])
            return 0;
        i++;
        curr = curr->prox;
    }

    return 1;
}

struct PilhaEstatica{
    int qtd;
    char dados[MAX];
};

int isPalindromoEstatica(struct PilhaEstatica *pi)
{
    char temp[MAX];
    int i = 0;
    int q = pi->qtd-1;
    while(i < pi->qtd)
    {
        temp[i] = pi->dados[q];
        i++;
        q--;
    }

    q = pi->qtd-1;

    while(q > 0)
    {
        if(temp[q] != pi->dados[q])
            return 0;
        i++;
        q--;
    }

    return 1;
}



int main()
{
    // struct Pilha *p1 = (struct Pilha*)malloc(sizeof(struct Pilha));
    // p1->qtd = 0;
    // p1->topo = (struct Element*) malloc(sizeof(struct Element));
    // p1->topo->letra = 'o';
    // p1->topo->prox = (struct Element*) malloc(sizeof(struct Element));
    // p1->topo->prox->letra = 'v';
    // p1->topo->prox->prox = (struct Element*) malloc(sizeof(struct Element));
    // p1->topo->prox->prox->letra = 'o';
    // p1->topo->prox->prox->prox = NULL;

    // p1->qtd = 3;

    // int result = isPalindromo(p1);


    struct PilhaEstatica *pi = (struct PilhaEstatica *)malloc(sizeof(struct PilhaEstatica));
    *pi = (struct PilhaEstatica) {3, {'o', 'v', 'o'}};

    int result = isPalindromoEstatica(pi);
    printf("%d", result);
}



