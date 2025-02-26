//Crie uma função recursiva para imprimir uma lista dinâmica encadeada

#include <stdlib.h>
#include <stdio.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

void printListNode(struct ListNode *l1)
{
    if(l1 == NULL)
    {
        printf("Lista vazia");
    }

    printf("Valor: %d \n", l1->val);
    printListNode(l1->next);
}

int main()
{
    struct ListNode *lista1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    lista1->val = 6;
    lista1->next = (struct ListNode*) malloc(sizeof(struct ListNode));
    lista1->next->val = 12;
    lista1->next->next = (struct ListNode*) malloc(sizeof(struct ListNode));
    lista1->next->next->val = 4;
    lista1->next->next->next = (struct ListNode*) malloc(sizeof(struct ListNode));
    lista1->next->next->next->val = 3;
    lista1->next->next->next->next = (struct ListNode*) malloc(sizeof(struct ListNode));
    lista1->next->next->next->next->val = 2;
    lista1->next->next->next->next->next = (struct ListNode*) malloc(sizeof(struct ListNode));
    lista1->next->next->next->next->next->val = 1;
    lista1->next->next->next->next->next->next = NULL;

    printListNode(lista1);

    return 0;
}