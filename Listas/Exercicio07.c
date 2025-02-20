/*Faça uma função para remover os n últimos elementos de uma lista, faça isso para todos os tipos de lista
vistos.
*/

#include <stdlib.h>
#include <stdio.h>
#define MAX 100

//Definição para lista sequencial estática
struct List {
    int qtd;
    int dados[MAX];
};

int RemoveLastList(struct List *l1, int n)
{
    if(l1->qtd < n) return 0;

    while(n > 0)
    {
        l1->qtd--;
        n--;
    }

    return 1;
}

//Definição para lista dinâmica encadeada
struct ListNode{
    int val;
    struct ListNode *next;
    int qtd;
};

int RemoveLastLinkedList(struct ListNode *l1, int n)
{
    l1->qtd = 5;
    if(l1->qtd < n) return 0;

    struct ListNode *curr = l1;
    struct ListNode *prev = l1;
    while(n > 0)
    {
        curr = l1;
        while(curr->next != NULL)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = NULL;
        n--;
    }

    curr = l1;
    while(curr != NULL)
    {
        printf("%d \n", curr->val);
        curr = curr->next;
    }
    
    return 1;
}

//Definição para lista circular
struct ListNodeCircular{
    int val;
    struct ListNodeCircular *next;
    int qtd;
};

int RemoveLastCircularList(struct ListNodeCircular *l1, int n)
{
    if(l1->qtd < n) return 0;

    struct ListNodeCircular *curr = l1;
    struct ListNodeCircular *prev = l1;
    struct ListNodeCircular *tail = l1;
    while(n > 0)
    {
        curr = l1;
        do{
            prev = curr;
            curr = curr->next;
        }while(curr->next != l1);
    
        tail = curr;
        tail->next = NULL;
        prev->next = l1;
        n--;
    }

    curr = l1;
    do{
        printf("%d \n", curr->val);
        curr = curr->next;
    }while(curr != l1);
    return 1;
    
}

//Definição para lista duplamente encadeada
struct DoubleListNode{
    int val;
    struct DoubleListNode *next;
    struct DoubleListNode *previus;
    int qtd;
};

int RemoveLastDoubleLinkedList(struct DoubleListNode *l1, int n)
{
    if(l1->qtd < n) return 0;

    struct DoubleListNode *curr = l1;

    while(n > 0)
    {
        curr = l1;
        while(curr->next != NULL)
        {
            curr = curr->next;
        }
    
        struct DoubleListNode *tail = curr;
    
        tail->previus->next = NULL;
        n--;
    }

    curr = l1;
    while(curr != NULL)
    {
        printf("%d \n", curr->val);
        curr = curr->next;
    }

    return 1;
    
}

int main()
{
    //Para testar a Lista Estática
    struct List *lista1 = (struct List *)malloc(sizeof(struct List));
    *lista1 = (struct List) {5, {1,2,3,4,5}};

    int result = RemoveLastList(lista1, 3);

    for(int j = 0; j < lista1->qtd; j++)
    {
        printf("Nova lista: %d \n", lista1->dados[j]);
    }
        

    //Para testar a Lista Encadeada    
    struct ListNode *lista1 = (struct ListNode*)malloc(sizeof(struct ListNode));

    lista1->val = 1;
    lista1->next = (struct ListNode*) malloc(sizeof(struct ListNode));
    lista1->next->val = 2;
    lista1->next->next = (struct ListNode*) malloc(sizeof(struct ListNode));
    lista1->next->next->val =3;
    lista1->next->next->next = (struct ListNode*) malloc(sizeof(struct ListNode));
    lista1->next->next->next->val =4;
    lista1->next->next->next->next = (struct ListNode*) malloc(sizeof(struct ListNode));
    lista1->next->next->next->next->val =5;
    lista1->next->next->next->next->next = NULL;
    int resultado = RemoveLastLinkedList(lista1, 2);  
    

    //Para testar a Lista Circular Encadeada
    struct ListNodeCircular *lista1 = (struct ListNodeCircular*)malloc(sizeof(struct ListNodeCircular)); 
    
    lista1->val = 1;
    lista1->next = (struct ListNodeCircular*) malloc(sizeof(struct ListNodeCircular));
    lista1->next->val = 2;
    lista1->next->next = (struct ListNodeCircular*) malloc(sizeof(struct ListNodeCircular));
    lista1->next->next->val =3;
    lista1->next->next->next = (struct ListNodeCircular*) malloc(sizeof(struct ListNodeCircular));
    lista1->next->next->next->val =4;
    lista1->next->next->next->next = (struct ListNodeCircular*) malloc(sizeof(struct ListNodeCircular));
    lista1->next->next->next->next->val =5;
    lista1->next->next->next->next->next = lista1;
    lista1->qtd = 5;
    int result = RemoveLastCircularList(lista1, 4);
    

    //Para testar a Lista Duplamente Encadeada
    struct DoubleListNode *lista1 = (struct DoubleListNode*)malloc(sizeof(struct DoubleListNode)); 
    
    lista1->val = 2;
    lista1->previus = NULL;
    lista1->next = (struct DoubleListNode*) malloc(sizeof(struct DoubleListNode));
    lista1->next->previus = lista1;
    lista1->next->val = 6;
    lista1->next->next = (struct DoubleListNode*) malloc(sizeof(struct DoubleListNode));
    lista1->next->next->previus = lista1->next;
    lista1->next->next->val = 12;
    lista1->next->next->next = NULL;

    lista1->qtd = 3;

    int result = RemoveLastDoubleLinkedList(lista1, 2);

    return 0;
}