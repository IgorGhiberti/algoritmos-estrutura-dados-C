//Escreva uma função que receba duas listas e retorne uma terceira contendo as duas primeiras concatenadas. Faça isso para todos os tipos de lista (encadeada, estática e duplamente encadeada).
#include <stdlib.h>
#include <stdio.h>
#define MAX 100

//Definição para lista sequencial estática
struct List {
  int qtd;
  int dados[MAX];
};

struct List* ConcatenarList(struct List *l1, struct List *l2)
{

  struct List *l3 = (struct List*) malloc(sizeof(struct List));
  l3->qtd = 0;

  for(int i = 0; i < l2->qtd; i++)
  {
    l1->dados[l1->qtd] = l2->dados[i];
    l1->qtd++;
  }

  for(int j = 0; j < l1->qtd; j++)
  {
    l3->dados[l3->qtd] = l1->dados[j];
    printf("valor l3: %d \n", l3->dados[l3->qtd]);
    l3->qtd++;
  }

  return l3;
}

//Definição para lista dinâmica encadeada
struct ListNode{
  int val;
  struct ListNode *next;
};

struct ListNode* ConcatenarListNode(struct ListNode *l1, struct ListNode *l2)
{
  struct ListNode *l3 = (struct ListNode*) malloc(sizeof(struct ListNode));
  struct ListNode *tail = l3; 
  struct ListNode *curr = l1;

  while(curr->next != NULL)
  {
    curr = curr->next;  
  }

  tail = curr;

  tail->next = l2;

  l3->next = l1;

  struct ListNode *currl3 = l3;

  while(currl3 != NULL)
  {
    printf("Valor de l3: %d \n", currl3->val);
    currl3 = currl3->next;
  }

  return l3->next;
}

//Definição para lista circular
struct ListNodeCircular{
  int val;
  struct ListNodeCircular *next;
};

struct ListNodeCircular* ConcatenarListNodeCircular(struct ListNodeCircular *l1, struct ListNodeCircular *l2)
{
  struct ListNodeCircular *l3 = (struct ListNodeCircular*) malloc(sizeof(struct ListNodeCircular));
  struct ListNodeCircular *tail = l3;
  struct ListNodeCircular *curr = l1;
  struct ListNodeCircular *taill2 = l2;
  struct ListNodeCircular *currl2 = l2;

  while(curr->next != l1)
  {
    curr = curr->next;
  }

  tail = curr;

  tail->next = l2;

  while(currl2->next != l2)
  {
    currl2 = currl2->next;
  }

  taill2 = currl2;

  taill2->next = l1;

  l3 = l1;

  struct ListNodeCircular *currl3 = l3;

  do{
    printf("Valor de l3: %d \n", currl3->val);
    currl3 = currl3->next;
  } while(currl3 != l3);

  return l3;

}

//Definição para lista duplamente encadeada
struct DoubleListNode{
  int val;
  struct DoubleListNode *next;
  struct DoubleListNode *previus;
};

struct DoubleListNode* ConcatenarDouble(struct DoubleListNode *l1, struct DoubleListNode *l2)
{
  struct DoubleListNode *l3 = (struct DoubleListNode*) malloc(sizeof(struct DoubleListNode));
  struct DoubleListNode *tail = l3;
  struct DoubleListNode *curr = l1;

  while(curr->next != NULL)
  {
    curr = curr->next;
  }

  tail = curr;

  tail->next = l2;
  l2->previus = tail;

  l3 = l1;

  struct DoubleListNode *currl3 = l3;
  while(currl3 != NULL)
  {
    printf("Valor de l3: %d \n", currl3->val);
    currl3 = currl3->next;
  }

  return l3;
}


int main()
{
  //Para testar o List
  /*struct List *lista1 = (struct List *)malloc(sizeof(struct List));
  struct List *lista2 = (struct List *)malloc(sizeof(struct List));
  *lista1 = (struct List) {5, {1,2,3,4,5}};
  *lista2 = (struct List) {4, {9, 3, 4, 6}};

  struct List *l3 = ConcatenarList(lista1, lista2);
  */
  
  //Para testar ListNode
  /*struct ListNode *lista1 = (struct ListNode*)malloc(sizeof(struct ListNode));
  struct ListNode *lista2 = (struct ListNode*)malloc(sizeof(struct ListNode));

  lista1->val = 1;
  lista1->next = (struct ListNode*) malloc(sizeof(struct ListNode));
  lista1->next->val = 2;
  lista1->next->next = (struct ListNode*) malloc(sizeof(struct ListNode));
  lista1->next->next->val =3;
  lista1->next->next->next = NULL;
  
  lista2->val = 8;
  lista2->next = (struct ListNode*) malloc(sizeof(struct ListNode));
  lista2->next->val = 72;
  lista2->next->next = (struct ListNode*) malloc(sizeof(struct ListNode));
  lista2->next->next->val = 93;
  lista2->next->next->next = NULL;
  struct ListNode *l3 = ConcatenarListNode(lista1, lista2);
  */
  
  //Para testar ListNodeCircular
  /*
  struct ListNodeCircular *lista1 = (struct ListNodeCircular*)malloc(sizeof(struct ListNodeCircular)); 
  struct ListNodeCircular *lista2 = (struct ListNodeCircular*)malloc(sizeof(struct ListNodeCircular)); 
  
  lista1->val = 1;
  lista1->next = (struct ListNodeCircular*) malloc(sizeof(struct ListNodeCircular));
  lista1->next->val = 2;
  lista1->next->next = (struct ListNodeCircular*) malloc(sizeof(struct ListNodeCircular));
  lista1->next->next->val =3;
  lista1->next->next->next = lista1;
  
  lista2->val = 8;
  lista2->next = (struct ListNodeCircular*) malloc(sizeof(struct ListNodeCircular));
  lista2->next->val = 72;
  lista2->next->next = (struct ListNodeCircular*) malloc(sizeof(struct ListNodeCircular));
  lista2->next->next->val = 93;
  lista2->next->next->next = lista2;
  struct ListNodeCircular *l3 = ConcatenarListNodeCircular(lista1, lista2);
  */

  //Para testar a Lista Duplamente Encadeada
  struct DoubleListNode *lista1 = (struct DoubleListNode*)malloc(sizeof(struct DoubleListNode)); 
  struct DoubleListNode *lista2 = (struct DoubleListNode*)malloc(sizeof(struct DoubleListNode)); 
  
  lista1->val = 2;
  lista1->previus = NULL;
  lista1->next = (struct DoubleListNode*) malloc(sizeof(struct DoubleListNode));
  lista1->next->previus = lista1;
  lista1->next->val = 6;
  lista1->next->next = (struct DoubleListNode*) malloc(sizeof(struct DoubleListNode));
  lista1->next->next->previus = lista1->next;
  lista1->next->next->val = 12;
  lista1->next->next->next = NULL;
  
  lista2->val = 8;
  lista2->previus = NULL;
  lista2->next = (struct DoubleListNode*) malloc(sizeof(struct DoubleListNode));
  lista2->next->previus = lista2;
  lista2->next->val = 72;
  lista2->next->next = (struct DoubleListNode*) malloc(sizeof(struct DoubleListNode));
  lista2->next->next->previus = lista2->next;
  lista2->next->next->val = 93;
  lista2->next->next->next = NULL;

  struct DoubleListNode *l3 = ConcatenarDouble(lista1, lista2);
  return 0;
}




