//Escreva uma função que, dada uma lista l1, inverta e armazene em uma lista l2.

#include <stdlib.h>
#include <stdio.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode* reverseListNode(struct ListNode *l1)
{
    struct ListNode *curr = l1;
    struct ListNode *prev = NULL;
    struct ListNode *temp = l1;

    while(curr != NULL)
    {
        temp = curr->next; 
        curr->next = prev; 
        prev = curr; 
        curr = temp; 
    }

    struct ListNode *l2 = prev;
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
    lista1->val = 25;
    lista1->next = (struct ListNode*) malloc(sizeof(struct ListNode));
    lista1->next->val = 2;
    lista1->next->next = (struct ListNode*) malloc(sizeof(struct ListNode));
    lista1->next->next->val =3;
    lista1->next->next->next = (struct ListNode*) malloc(sizeof(struct ListNode));
    lista1->next->next->next->val =200;
    lista1->next->next->next->next = (struct ListNode*) malloc(sizeof(struct ListNode));
    lista1->next->next->next->next->val =1;
    lista1->next->next->next->next->next = (struct ListNode*) malloc(sizeof(struct ListNode));
    lista1->next->next->next->next->next->val = 12;
    lista1->next->next->next->next->next->next = NULL;

    lista2 = reverseListNode(lista1);
}