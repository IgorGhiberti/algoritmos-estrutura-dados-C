/*Faça uma função para remover os n primeiros elementos de uma lista, faça para todos os tipos de listas visto
até então.*/

#include <stdlib.h>
#include <stdio.h>
#define MAX 100

//Definição para lista sequencial estática
struct List {
    int qtd;
    int dados[MAX];
  };

int RemoverList(struct List *l1, int n)
{
    if(n > l1->qtd) return 0;

    while(n > 0)
    {
        for(int i = 1; i < l1->qtd; i++)
        {
            int z = i - 1;
            l1->dados[z] = l1->dados[i];
        }
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

int RemoveLinkedList(struct ListNode *l1, int n)
{
    l1->qtd = 5;
    if(n > l1->qtd) return 0;

    while(n > 0)
    {
        l1 = l1->next;
        n--;
    }

    struct ListNode *curr = l1;

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

int RemoveCircularList(struct ListNodeCircular *l1, int n)
{
    l1->qtd = 4;
    if(n > l1->qtd) return 0;
    struct ListNodeCircular *curr = l1;

    do{
        curr = curr->next;
    }while(curr->next != l1);

    struct ListNodeCircular *tail = curr;

    while(n > 0)
    {
        tail->next = tail->next->next;
        n--;
    }

    l1 = tail->next;

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

int RemoveDoubleLinked(struct DoubleListNode *l1, int n)
{
    l1->qtd = 3;
    if(n > l1->qtd) return 0;

    while(n > 0)
    {
        l1 = l1->next;
        l1->previus = NULL;
        n--;
    }

    struct DoubleListNode *curr = l1;

    while(curr != NULL)
    {
        printf("%d \n", curr->val);
        curr = curr->next;
    }

    return 1;
}

int main()
{
    
    struct List *lista1 = (struct List *)malloc(sizeof(struct List));
    *lista1 = (struct List) {5, {1,2,3,4,5}};
    int remove = 2;

    int result = RemoverList(lista1, remove);

    for(int j = 0; j < lista1->qtd; j++)
    {
        printf("Nova lista: %d \n", lista1->dados[j]);
    }
        

    
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
    int resultado = RemoveLinkedList(lista1, 3);
    
    
    //Para testar ListNodeCircular
    
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
    int result = RemoveCircularList(lista1, 4);
    
    
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

    int result = RemoveDoubleLinked(lista1, 1);

    return 0;
}