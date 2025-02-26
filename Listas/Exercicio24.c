/*Modifique o algortimo de ordenação bubble sort para que o mesmo possa ser utilizado para armazenar
uma lista dinâmica encadeada contendo números inteiros. Faça o mesmo para a lista duplamente encadeada.
*/

#include <stdlib.h>
#include <stdio.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode* bubbleSortLinkedList(struct ListNode *l1)
{
    struct ListNode *curr = l1;
    int aux = 0;
    while(curr != NULL)
    {
        struct ListNode *curr2 = l1;
        while(curr2->next != NULL)
        {
            if(curr2->val > curr2->next->val)
            {
                aux = curr2->val;
                curr2->val = curr2->next->val;
                curr2->next->val = aux;
            }
            curr2 = curr2->next;
        }
        curr = curr->next;
    }

    curr = l1;
    while(curr != NULL)
    {
        printf("%d \n", curr->val);
        curr = curr->next;
    }

    return l1;
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

    lista1 = bubbleSortLinkedList(lista1);
    return 0;
}