/*Implemente uma função para inverter a posição dos elementos de uma pilha. Faça a função para as pilhas
estáticas e dinâmicas.*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 50

struct Element {
    struct Element *prox;
    int val;
};

struct Pilha {
    int qtd;
    struct Element *topo;
};

void reversePilha(struct Pilha *pi)
{
    struct Element *curr = pi->topo;
    struct Element *prev = NULL;

    while(curr != NULL)
    {
        struct Element *temp = curr->prox;
        curr->prox = prev;
        prev = curr;
        curr = temp;
    }

    pi->topo = prev;
}

struct PilhaEstatica{
    int qtd;
    int dados[MAX];
};

void reversePilhaEstatica(struct PilhaEstatica *pi)
{
    int temp[MAX];
    int qtdTemp = 0;
    int j = pi->qtd-1;

    for(int i = 0; i < pi->qtd; i++)
    {
        temp[i] = pi->dados[j];
        j--;
        qtdTemp++;
    }

    pi->qtd = 0;
    j = MAX-1;

    for(int i = 0; i < qtdTemp; i++)
    {
        pi->dados[j] = temp[i];
        pi->qtd++;
        j--;
    }
}

int main()
{
    // struct Pilha *p1 = (struct Pilha*)malloc(sizeof(struct Pilha));
    // p1->qtd = 0;
    // p1->topo = (struct Element*) malloc(sizeof(struct Element));
    // p1->topo->val = 1;
    // p1->topo->prox = (struct Element*) malloc(sizeof(struct Element));
    // p1->topo->prox->val = 2;
    // p1->topo->prox->prox = (struct Element*) malloc(sizeof(struct Element));
    // p1->topo->prox->prox->val = 3;
    // p1->topo->prox->prox->prox = NULL;

    // p1->qtd = 3;

    // reverseStack(p1);

    struct PilhaEstatica *pi = (struct PilhaEstatica *)malloc(sizeof(struct PilhaEstatica));
    *pi = (struct PilhaEstatica) {3, {1,2,3}};

    reversePilhaEstatica(pi);

    int j = pi->qtd-1;
    for(int i = 0; i < pi->qtd; i++)
    {
        printf("%d \n", pi->dados[j]);
        j--;
    }

    return 0;
}