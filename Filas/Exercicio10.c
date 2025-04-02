/*Implemente uma função para unir filas: recebe duas filas, tudo deve ficar na primeira fila,
a segunda deve ficar vazia, não pode conter repetições.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct Queue{
    int qtd;
    int dados[MAX];
    int inicio;
    int final;
};

struct Queue* unionQueues(struct Queue *q1, struct Queue *q2)
{
    int temp[MAX];
    int contains = 0;
    int qtdTemp = 0;
    int i1 = q1->inicio;

    while(i1 < q1->qtd)
    {
        if(qtdTemp > 0)
        {
            for(int j = 0; j < qtdTemp; j++)
            {
                if(q1->dados[i1] == temp[j]) contains = 1;
            }
            if(contains != 1)
            {
                temp[qtdTemp] = q1->dados[i1];
                qtdTemp++;
            }
        }
        else
        {
            temp[qtdTemp] = q1->dados[i1];
            qtdTemp++;
        }
        contains = 0;
        i1++;
        q1->inicio++;
    }

    int i2 = q2->inicio;
    while(i2 < q2->qtd)
    {
        if(qtdTemp > 0)
        {
            for(int j = 0; j < qtdTemp; j++)
            {
                if(q1->dados[i2] == temp[j]) contains = 1;
            }
            if(contains != 1)
            {
                temp[qtdTemp] = q1->dados[i2];
                qtdTemp++;
            }
        }
        else
        {
            temp[qtdTemp] = q2->dados[i2];
            qtdTemp++;
        }
        contains = 0;
        i2++;
        q2->inicio++;
    }

    q2->qtd = 0;
    q1->qtd = 0;


    int i = 0;
    while(qtdTemp > 0)
    {
        q1->dados[q1->inicio] = temp[i];
        q1->qtd++;
        q1->final++;
        i++;
        qtdTemp--;
    }



    return q1;

}

struct Element{
    int val;
    struct Element *next;
};
struct QueueNode{
    int qtd;
    struct Element *inicio;
    struct Element *final;
};

struct QueueNode* unionQueuesNode(struct QueueNode *q1, struct QueueNode *q2)
{
    int temp[MAX];
    int qtdTemp = 0;
    int contains = 0;
    struct Element *curr = q1->inicio;

    while(curr != NULL)
    {
        if(qtdTemp > 0)
        {
            for(int j = 0; j < qtdTemp; j++)
            {
                if(curr->val == temp[j]) contains = 1;
            }
            if(contains != 1)
            {
                temp[qtdTemp] = curr->val;
                qtdTemp++;
            }
        }
        else
        {
            temp[qtdTemp] = curr->val;
            qtdTemp++;
        }
        contains = 0;
        curr = curr->next;
    }

    struct Element *curr2 = q2->inicio;
    contains = 0;

    while(curr2 != NULL)
    {
        if(qtdTemp > 0)
        {
            for(int j = 0; j < qtdTemp; j++)
            {
                if(curr2->val == temp[j]) contains = 1;
            }
            if(contains != 1)
            {
                temp[qtdTemp] = curr2->val;
                qtdTemp++;
            }
        }
        else
        {
            temp[qtdTemp] = curr2->val;
            qtdTemp++;
        }
        contains = 0;
        curr2 = curr2->next;
    }

    q1->inicio = NULL;
    q1->final = NULL;
    q1->qtd = 0;
    q2->inicio = NULL;
    q2->final = NULL;
    q2->qtd = 0;

    int i = 0;

    while(qtdTemp > 0)
    {
        if(q1->inicio == NULL)
        {
            q1->inicio = (struct Element*)malloc(sizeof(struct Element));
            q1->inicio->val = temp[i];
            q1->final = q1->inicio;
            q1->inicio->next = q1->final;
        }
        else
        {
            q1->final->next = (struct Element*)malloc(sizeof(struct Element));
            q1->final->next->val = temp[i];
        }

        q1->final = q1->final->next;
        i++;
        qtdTemp--;
    }

    curr = q1->inicio;

    while(curr != NULL)
    {
        printf("%d \n", curr->val);
        curr = curr->next;
    }

    return q1;
}

int main()
{
    /*struct Queue *q1 = (struct Queue *)malloc(sizeof(struct Queue));
    *q1 = (struct Queue) {5, {1,2,3,4,2}, 0, 4};

    struct Queue *q2 = (struct Queue *)malloc(sizeof(struct Queue));
    *q2 = (struct Queue) {5, {6, 7, 8, 9, 9}, 0, 4};

    q1 = unionQueues(q1, q2);
    for(int i = 0; i < q1->qtd; i++)
    {
        printf("%d \n", q1->dados[i]);
    }*/

    struct QueueNode *minhaFila = (struct QueueNode*) malloc(sizeof(struct QueueNode));
    minhaFila->qtd = 0;
    minhaFila->inicio = NULL;
    minhaFila->final = NULL;

    for (int i = 1; i <= 5; i++) {
        struct Element *novoElemento = (struct Element*) malloc(sizeof(struct Element));
        novoElemento->val = i * 10;
        novoElemento->next = NULL;

        if (minhaFila->inicio == NULL) {
            minhaFila->inicio = novoElemento;
            minhaFila->final = novoElemento;
        } else {
            minhaFila->final->next = novoElemento;
            minhaFila->final = novoElemento;
        }

        minhaFila->qtd++;
    }

    struct QueueNode *minhaFila2 = (struct QueueNode*) malloc(sizeof(struct QueueNode));
    minhaFila2->qtd = 0;
    minhaFila2->inicio = NULL;
    minhaFila2->final = NULL;

    for (int i = 1; i <= 5; i++) {
        struct Element *novoElemento = (struct Element*) malloc(sizeof(struct Element));
        if(i < 3) novoElemento->val = 5;
        if(i == 4) novoElemento->val = 25;
        if(i == 5) novoElemento->val = 12;
        novoElemento->next = NULL;

        if (minhaFila2->inicio == NULL) {
            minhaFila2->inicio = novoElemento;
            minhaFila2->final = novoElemento;
        } else {
            minhaFila2->final->next = novoElemento;
            minhaFila2->final = novoElemento;
        }

        minhaFila2->qtd++;
    }

    minhaFila = unionQueuesNode(minhaFila, minhaFila2);
        
    return 0;
}