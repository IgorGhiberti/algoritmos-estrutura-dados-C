/*Dada uma lista contendo números inteiros positivos, implemente uma função que receba como parâmetro uma lista e um valor n.
Em seguida, a fu8nção divide a lista em duas, de modo que a segunda lista contenha os elementos que vêm depois de n.
A função deve retornar à segunda lista.
*/
#include <stdlib.h>
#include <stdio.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode* listAfterN(struct ListNode *l1, int n)
{
    struct ListNode *curr = l1;
    while(curr != NULL && curr->val != n)
    {
        curr = curr->next;
    }

    struct ListNode *l2 = curr->next;

    curr = l2;

    while(curr != NULL)
    {
        printf("%d \n", curr->val);
        curr = curr->next;
    }
    return l2;
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

    lista2 = listAfterN(lista1, 12);
    return 0;
}