/*Dada uma lista que armazena a seguinte struct: struct produto
{ int codigo, char nome[30], float preco, int qtd}; escreva uma função que busca o produto de menor preço.
Faça para lista sequencial estática e dinâmica encadeada.
*/

#include <stdlib.h>
#include <stdio.h>
#define MAX 100

//Definição de produto
struct Produto{
    int codigo;
    char nome[30];
    float preco;
    int qtd;
};

//Definição para lista sequencial estática
struct List {
    int qtd;
    struct Produto *produtos[MAX];
};

struct Produto* searchLessValue(struct List *l1)
{
    struct Produto *menor = l1->produtos[0];
    for(int i = 1; i < l1->qtd; i++)
    {
        if(menor->preco > l1->produtos[i]->preco)
        {
            menor = l1->produtos[i];
        }
    }
    return menor;
}

//Definição para lista dinâmica encadeada
struct ListNode{
    struct Produto *produto;
    struct ListNode *next;
};

struct Produto* searchLessValueLinkedList(struct ListNode *l1)
{
    struct ListNode *curr = l1;
    struct Produto *menor = l1->produto;
    while(curr != NULL)
    {
        if(menor->preco > curr->produto->preco)
        {
            menor = curr->produto;
        }
        curr = curr->next;
    }

    return menor;
}



int main()
{
    struct List *l1 = (struct List*) malloc(sizeof(struct List));
    l1->qtd = 0;

    struct Produto *p1 = (struct Produto*) malloc(sizeof(struct Produto));
    struct Produto *p2 = (struct Produto*) malloc(sizeof(struct Produto));
    struct Produto *p3 = (struct Produto*) malloc(sizeof(struct Produto));
    struct Produto *p4 = (struct Produto*) malloc(sizeof(struct Produto));
    struct Produto *p5 = (struct Produto*) malloc(sizeof(struct Produto));

    *p1 = (struct Produto) {1, "Caneta", 2.50, 10};
    *p2 = (struct Produto) {2, "Caderno", 15.90, 5};
    *p3 = (struct Produto) {3, "Lápis", 1.20, 20};
    *p4 = (struct Produto) {4, "Borracha", 0.5, 30};
    *p5 = (struct Produto) {5, "Régua", 0.3, 8};

    l1->produtos[l1->qtd++] = p1;
    l1->produtos[l1->qtd++] = p2;
    l1->produtos[l1->qtd++] = p3;
    l1->produtos[l1->qtd++] = p4;
    l1->produtos[l1->qtd++] = p5;

    struct Produto *p6 = (struct Produto*) malloc(sizeof(struct Produto));

    //p6 = searchLessValue(l1);

    /*printf("Código: %d, Nome: %s, Preço: R$%.2f, Quantidade: %d\n",
        p6->codigo,
        p6->nome,
        p6->preco,
        p6->qtd);
        */

    //Para testar a Lista Encadeada    
    struct ListNode *lista1 = (struct ListNode*)malloc(sizeof(struct ListNode));

    lista1->produto = p1;
    lista1->next = (struct ListNode*) malloc(sizeof(struct ListNode));
    lista1->next->produto = p2;
    lista1->next->next = (struct ListNode*) malloc(sizeof(struct ListNode));
    lista1->next->next->produto =p3;
    lista1->next->next->next = (struct ListNode*) malloc(sizeof(struct ListNode));
    lista1->next->next->next->produto =p4;
    lista1->next->next->next->next = (struct ListNode*) malloc(sizeof(struct ListNode));
    lista1->next->next->next->next->produto =p5;
    lista1->next->next->next->next->next = NULL;

    p6 = searchLessValueLinkedList(lista1);

    printf("Código: %d, Nome: %s, Preço: R$%.2f, Quantidade: %d\n",
        p6->codigo,
        p6->nome,
        p6->preco,
        p6->qtd);
    
    return 0;
}
