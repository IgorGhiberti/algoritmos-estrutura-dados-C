/*Implemente uma função que receba uma Deque e a inverta. Faça para Deque encadeado e estático.*/

#include <stdlib.h>
#include <stdio.h>
#define MAX 100

struct Element  {
    struct Element *ant;
    struct Element *prox;
    int val;
};

struct Deque {
    int qtd;
    struct Element *inicio;
    struct Element *final;

};

void reverseDeque (struct Deque *dq)
{
    struct Element *i = dq->inicio;
    struct Element *f = dq->final;
    struct Element *tempI;
    struct Element *tempF;

    while(i != f && i->prox != f)
    {
        tempI = i->prox;
        i->prox = i->ant;
        i->ant = tempI;
        tempF = f->ant;
        f->ant = f->prox;
        f->prox = tempF;
        tempI = i;
        tempF = f;
        i = i->ant;
        f = f->prox;
    }

    if(dq->qtd % 2 != 0)
    {
        i->prox = tempI;
        i->ant = tempF;
        tempF = dq->inicio;
    }
    else
    {
        tempI = i->prox;
        i->prox = i->ant;
        i->ant = tempI;
        tempF = f->ant;
        f->ant = f->prox;
        f->prox = tempF;
    }
    
    dq->inicio = dq->final;
    dq->final = tempF;
}

struct DequeStatic {
    int qtd;
    int inicio;
    int final;
    int dados[MAX];
};

void reverseDequeStatic (struct DequeStatic *dq)
{
    int i = dq->inicio;
    int f = dq->final;

    while(i != f && f > i)
    {
        int temp = dq->dados[f];
        dq->dados[f] = dq->dados[i];
        dq->dados[i] = temp;
        i++;
        f--;
    }
}

int main()
{
    struct Deque *dq = (struct Deque*)malloc(sizeof(struct Deque)); 
    
    dq->qtd = 0;
    dq->inicio = NULL;
    dq->final = NULL;

    // Criando elementos
    struct Element *e1 = (struct Element *)malloc(sizeof(struct Element));
    struct Element *e2 = (struct Element *)malloc(sizeof(struct Element));
    struct Element *e3 = (struct Element *)malloc(sizeof(struct Element));
    struct Element *e4 = (struct Element *)malloc(sizeof(struct Element));
    struct Element *e5 = (struct Element *)malloc(sizeof(struct Element));
    //struct Element *e6 = (struct Element *)malloc(sizeof(struct Element));

    // Inicializando elementos
    e1->val = 1;
    e2->val = 2;
    e3->val = 3;
    e4->val = 4;
    e5->val = 5;
    //e6->val = 6;
    
    // Ligando elementos
    e1->ant = NULL;
    e1->prox = e2;
    
    e2->ant = e1;
    e2->prox = e3;
    
    e3->ant = e2;
    e3->prox = e4;

    e4->ant = e3;
    e4->prox = e5;

    e5->ant = e4;
    e5->prox = NULL;

    // e6->ant = e5;
    // e6->prox = NULL;
    //Configurando o deque
    dq->inicio = e1;
    dq->final = e5;
    dq->qtd = 5;

    //reverseDeque(dq);

    struct Element *curr = dq->inicio;

    // while(curr != NULL)
    // {
    //     printf("%d \n", curr->val);
    //     curr = curr->prox;
    // }

    struct DequeStatic *dqs = (struct DequeStatic*)malloc(sizeof(struct DequeStatic)); 

    *dqs = (struct DequeStatic) {6, 0, 5, {1,2,3,4,5,6}};

    reverseDequeStatic(dqs);

    for(int i = 0; i < dqs->qtd; i++)
    {
        printf("%d \n", dqs->dados[i]);
    }

    return 0;
}