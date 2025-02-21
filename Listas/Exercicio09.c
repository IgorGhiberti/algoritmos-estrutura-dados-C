/*Escreva uma função que receba a posição de dois elementos em uma lista e os troque de lugar, faça isso
para todos os tipos de listas vistos até então.
*/

#include <stdlib.h>
#include <stdio.h>
#define MAX 100

//Definição para lista sequencial estática
struct List {
    int qtd;
    int dados[MAX];
};

int changePositions(struct List *l1, int n, int y)
{
    if(y > (l1->qtd-1) || n > (l1->qtd-1)) return 0;

    int temp = l1->dados[n];
    l1->dados[n] = l1->dados[y];
    l1->dados[y] = temp;

    return 0;
}

//Definição para lista dinâmica encadeada
struct ListNode{
    int val;
    struct ListNode *next;
    int qtd;
};

int changePositionsLinkedList(struct ListNode *l1, int n, int y)
{
    if(y > (l1->qtd) || n > (l1->qtd) || y == n || y < 0 || n < 0) return 0;

    struct ListNode *curr = l1;
    int i = 1;
    struct ListNode *menor = (struct ListNode*)malloc(sizeof(struct ListNode));
    
    if(y > n)
    {
        while(curr != NULL && i != y)
        {
            if(n == i)
            {
                menor = curr;
            } 
            curr = curr->next;
            i++; 
        }
        int temp = 0;
        temp = curr->val; //valor do maior é armazenado em temp
        curr->val = menor->val; //valor do maior passa a ser o valor do menor
        menor->val = temp; //o valor do menor passa a ser o valor do maior, agora falta colocar isso na lista
    }
    else
    {
        while(curr != NULL && i != n)
        {
            if(y == i)
            {
                menor = curr;
            } 
            curr = curr->next;
            i++; 
        }
        int temp = 0;
        temp = curr->val; //valor do maior é armazenado em temp
        curr->val = menor->val; //valor do maior passa a ser o valor do menor
        menor->val = temp; //o valor do menor passa a ser o valor do maior, agora falta colocar isso na lista
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

int changePositionsCircularList(struct ListNodeCircular *l1, int n, int y)
{
    if(y > (l1->qtd) || n > (l1->qtd) || y == n || y < 0 || n < 0) return 0;

    struct ListNodeCircular *curr = l1;
    int i = 1;
    struct ListNodeCircular *menor = (struct ListNodeCircular*)malloc(sizeof(struct ListNodeCircular));
    
    if(y > n)
    {
        do{
            if(i == n)
            {
                menor = curr;
            } 
            curr = curr->next;
            i++; 
        }
        while(curr != l1 && i != y);
        int temp = 0;
        temp = curr->val; //valor do maior é armazenado em temp
        curr->val = menor->val; //valor do maior passa a ser o valor do menor
        menor->val = temp; //o valor do menor passa a ser o valor do maior, agora falta colocar isso na lista
    }
    else
    {   
        do{
            if(y == i)
            {
                menor = curr;
            } 
            curr = curr->next;
            i++; 
        }
        while(curr != l1 && i != n);
        int temp = 0;
        temp = curr->val; //valor do maior é armazenado em temp
        curr->val = menor->val; //valor do maior passa a ser o valor do menor
        menor->val = temp; //o valor do menor passa a ser o valor do maior, agora falta colocar isso na lista
    }

    curr = l1;
    do{
        printf("%d \n", curr->val);
        curr = curr->next;
    }while(curr != l1);
}

//Definição para lista duplamente encadeada
struct DoubleListNode{
    int val;
    struct DoubleListNode *next;
    struct DoubleListNode *previus;
    int qtd;
};

int changePositionsDoubleListNode(struct DoubleListNode *l1, int n, int y)
{
    if(y > (l1->qtd) || n > (l1->qtd) || y == n || y < 1 || n < 1) return 0;

    struct DoubleListNode *curr = l1;
    int i = 1;
    struct DoubleListNode *menor = (struct DoubleListNode*)malloc(sizeof(struct DoubleListNode));
    
    if(y > n)
    {
        while(curr != NULL && i != y)
        {
            if(n == i)
            {
                menor = curr;
            } 
            curr = curr->next;
            i++; 
        }
        int temp = 0;
        temp = curr->val; //valor do maior é armazenado em temp
        curr->val = menor->val; //valor do maior passa a ser o valor do menor
        menor->val = temp; //o valor do menor passa a ser o valor do maior, agora falta colocar isso na lista
    }
    else
    {
        while(curr != NULL && i != n)
        {
            if(y == i)
            {
                menor = curr;
            } 
            curr = curr->next;
            i++; 
        }
        int temp = 0;
        temp = curr->val; //valor do maior é armazenado em temp
        curr->val = menor->val; //valor do maior passa a ser o valor do menor
        menor->val = temp; //o valor do menor passa a ser o valor do maior, agora falta colocar isso na lista
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
    //Para testar lista dinâmica estática
    struct List *lista1 = (struct List *)malloc(sizeof(struct List));
    *lista1 = (struct List) {5, {1,2,3,4,5}};
    int result = changePositions(lista1, 4, 2);

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
    lista1->qtd = 5;

    int result = changePositionsLinkedList(lista1, 4, 2);

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
    int result = changePositionsCircularList(lista1, 2, 5);
    

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
    int result = changePositionsDoubleListNode(lista1, 3, 2);
    return 0;
}