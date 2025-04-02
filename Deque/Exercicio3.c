/*Implemente uma função que retorna se as duas metades do Deque são simétricas. Exemplo: ABAABA -> verdadeiro
ABCXYA -> falso*/

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

int isSymetric(struct Deque *dq)
{
    struct Element *i = dq->inicio;
    struct Element *f = dq->final;

    if(i->letra != f->letra)
        return 0;
    
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
    //struct Element *e6 = (struct Element *)malloc(sizeof(struct Element));

    // Inicializando elementos
    e1->letra = 'a';
    e2->letra = 'b';
    e3->letra = 'a';
    e4->letra = 'a';
    e5->letra = 'b';
    //e6->letra = 'a';
    
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

    //e6->ant = e5;
    //e6->prox = NULL;
    // Configurando o deque
    dq->inicio = e1;
    dq->final = e5;
    dq->qtd = 5;

    int result = isSymetric(dq);

    printf("%d", result);

    return 0;
}