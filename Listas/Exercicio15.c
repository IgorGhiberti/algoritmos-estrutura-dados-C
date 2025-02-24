//Escreva uma função para verificar se uma lista de inteiros está ordenada ou não. A ordenação pode ser crescente ou decrescente.

#include <stdlib.h>
#include <stdio.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

int checkListNodeOrder(struct ListNode *l1)
{
    struct ListNode *curr = l1;
    struct ListNode *prev = l1;
    int isOrdered = 1;
    while(curr != NULL && curr->next != NULL)
    {
        struct ListNode *nxt = curr->next;
        if((curr->val > prev->val && curr->val > nxt->val) || (curr->val < prev->val && curr->val < nxt->val)) isOrdered = 0;
        prev = curr;
        curr = curr->next;
    }

    return isOrdered;
}

int main()
{
    struct ListNode *lista1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *lista2 = (struct ListNode*)malloc(sizeof(struct ListNode));
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

    int result = checkListNodeOrder(lista1);
    printf("%d", result);

    return 0;
}