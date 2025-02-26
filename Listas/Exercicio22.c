//Escreva uma função recursiva que calcule o tamanho de uma lista dinâmica encadeada

#include <stdlib.h>
#include <stdio.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

int countListElements(struct ListNode *l1)
{
    if(l1 == NULL)
    {
        return 0;
    }
    return 1 + countListElements(l1->next);
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

    int result = countListElements(lista1);
    printf("Result: %d", result);
    return 0;
}