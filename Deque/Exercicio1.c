/*Utilizando um deque, escreva uma função para verificar se uma palavra é um palíndromo.*/

#include <stdlib.h>
#include <stdio.h>

struct Element  {
    struct Element *ant;
    struct Element *prox;
    char letra;
};

struct Deque {
    int qtd;
    struct Element *inicio;
    struct Element *final;
};

int isPalindromo (struct Deque *dq)
{
    struct Element *i = dq->inicio;
    struct Element *f = dq->final;

    while(i != f && i->prox == NULL && f->ant == NULL)
    {
        if(i->letra != f->letra)
        {
            return 0;
        }
        i = i->prox;
        f = f->ant;
    }

    return 1;
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
    struct Element *e6 = (struct Element *)malloc(sizeof(struct Element));

    // Inicializando elementos
    e1->letra = 'r';
    e2->letra = 'e';
    e3->letra = 'n';
    e4->letra = 'n';
    e5->letra = 'e';
    e6->letra = 'r';
    
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
    e5->prox = e6;

    e6->ant = e5;
    e6->prox = NULL;
    // Configurando o deque
    dq->inicio = e1;
    dq->final = e6;
    dq->qtd = 6;

    int result = isPalindromo(dq);

    printf("%d", result);

    return 0;
}

