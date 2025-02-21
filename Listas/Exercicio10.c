/* Dada uma lista contendo números inteiros positivos, escreva uma função que calcule
-Quantos números pares existem
-A média da lista
-O maior valor
-O menor valor
-A posição do maior valor
-A posição do menor valor
-O número de nós com valor maior do que x
-A soma da lista
-O número de nós da lista que possuem um número primo
*/

#include <stdlib.h>
#include <stdio.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

int qntEvenNumbers(struct ListNode *l1)
{
    struct ListNode *curr = l1;
    int count = 0;
    while(curr != NULL)
    {
        if(curr->val % 2 == 0) count++;
        curr = curr->next;
    }

    return count;
}

float averageValues(struct ListNode *l1)
{
    struct ListNode *curr = l1;
    float average = 0;
    int count = 0;
    while(curr != NULL)
    {
        average += curr->val;  
        curr = curr->next;
        count++;
    }

    return average / count;
}

int biggestVal(struct ListNode *l1)
{
    struct ListNode *curr = l1;
    int biggestValue = 0;
    while(curr != NULL)
    {
        if(curr->val > biggestValue) biggestValue = curr->val;
        curr = curr->next;
    }

    return biggestValue;
}

int smallestVal(struct ListNode *l1)
{
    struct ListNode *curr = l1;
    int smallestValue = l1->val;
    while(curr != NULL)
    {
        if(curr->val < smallestValue) smallestValue = curr->val;
        curr = curr->next;
    }

    return smallestValue;
}

int positionBiggestVal(struct ListNode *l1)
{
    struct ListNode *curr = l1->next;
    int biggestValue = l1->val;
    int position = 0;
    while(curr != NULL)
    {
        if(curr->val > biggestValue)
        {
            biggestValue = curr->val;
        }
        curr = curr->next;
    }

    curr = l1;
    while(biggestValue != curr->val)
    {
        position++;
        curr = curr->next;
    }

    return position;
}

int positionSmallestVal(struct ListNode *l1)
{
    struct ListNode *curr = l1->next;
    int smallestValue = l1->val;
    int position = 0;
    while(curr != NULL)
    {
        if(curr->val < smallestValue)
        {
            smallestValue = curr->val;
        }
        curr = curr->next;
    }

    curr = l1;
    while(smallestValue != curr->val)
    {
        position++;
        curr = curr->next;
    }

    return position;
}

int valsBiggestThanX(struct ListNode *l1, int x)
{
    struct ListNode *curr = l1;
    int quantity = 0;
    while(curr != NULL)
    {
        if(curr->val > x) quantity++;
        curr = curr->next;
    }
    return quantity;
}

int sumList(struct ListNode *l1)
{
    struct ListNode *curr = l1;
    int sum = 0;
    while(curr != NULL)
    {
        sum += curr->val;
        curr = curr->next;
    }
    return sum;
}


int main()
{
    struct ListNode *lista1 = (struct ListNode*)malloc(sizeof(struct ListNode));

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

    int evenNumbers = qntEvenNumbers(lista1);
    float avarage = averageValues(lista1);
    int big = biggestVal(lista1);
    int small = smallestVal(lista1);
    int positionB = positionBiggestVal(lista1);
    int positionS = positionSmallestVal(lista1);
    int values = valsBiggestThanX(lista1, 10);
    int sum = sumList(lista1);
    printf("%d", sum);
    return 0;
}

