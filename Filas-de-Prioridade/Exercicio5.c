/*Implemente uma função que receba uma fila de prioridades e a inverta (a maior prioridade, passa a ser a menor).
Faça isso para array ordenado e heap binária.*/

#include <stdlib.h>
#include <stdio.h>
#define MAX 100

//Implementação para array ordenado
struct Array {
    int val;
    int prio;
};

struct PriorityQueueArray {
    int qtd;      
    struct Array *dados[MAX];
};

struct PriorityQueueArray* reverseQueue(struct PriorityQueueArray *pq1)
{
    int temp[MAX];
    int qtdTemp = 0;
    int i = pq1->qtd-1;

    while(i >= 0)
    {
        temp[qtdTemp] = pq1->dados[i]->val;
        i--;
        qtdTemp++;
    }

    i = 0;

    while(qtdTemp > 0)
    {
        pq1->dados[i]->val = temp[i];
        i++;
        qtdTemp--;
    }

    return pq1;
}

//Implementação heap
struct PriorityQueueHeap {
    int qtd;      
    struct Array *dados[MAX];
};

//Função de troca dois elementos no heap
void swap(struct Array **a, struct Array **b)
{
    struct Array *temp = *a;
    *a = *b;
    *b = temp;
}

//Função para restaurar a propriedade da heap
void heapify(struct PriorityQueueHeap *pq, int i, int isMiniHeap)
{
    int left = 2*i+1;
    int right = 2*i+2;
    int pai = i;

    if(left < pq->qtd && (isMiniHeap && pq->dados[left]->prio < pq->dados[pai]->prio))
    {
        pai = left;
    }

    if(right < pq->qtd && (isMiniHeap && pq->dados[right]->prio < pq->dados[pai]->prio))
    {
        pai = right;
    }

    if(pai != i)
    {
        swap(&pq->dados[i], &pq->dados[pai]);
        heapify(pq, pai, isMiniHeap);
    }
}

//Função para construir um heap válido após a inversão das prioridades
void BuildHeap(struct PriorityQueueHeap *pq, int isMiniHeap)
{
    for(int i = (pq->qtd / 2) - 1; i >= 0; i--) 
    {
        heapify(pq, i, isMinHeap);
    }
}

//Função principal para inverter a fila
void reversePriorityQueue(struct PriorityQueueHeap *pq)
{
    for(int i = 0; i < pq->qtd; i++) 
    {
        pq->dados[i]->prio *= -1;
    }

    buildHeap(pq, 1);
}


int main()
{
    struct PriorityQueueHeap *pq1 = (struct PriorityQueueHeap*) malloc(sizeof(struct PriorityQueueHeap));

    pq1->qtd = 0;
    struct Array *a1 = (struct Array*) malloc(sizeof(struct Array));
    struct Array *a2 = (struct Array*) malloc(sizeof(struct Array));
    struct Array *a3 = (struct Array*) malloc(sizeof(struct Array));
    struct Array *a4 = (struct Array*) malloc(sizeof(struct Array));
    struct Array *a5 = (struct Array*) malloc(sizeof(struct Array));
    // struct Array *a6 = (struct Array*) malloc(sizeof(struct Array));
    // struct Array *a7 = (struct Array*) malloc(sizeof(struct Array));
    // struct Array *a8 = (struct Array*) malloc(sizeof(struct Array));

    *a1 = (struct Array) {1, 4};
    *a2 = (struct Array) {2, 5};
    *a3 = (struct Array) {3, 6};
    *a4 = (struct Array) {4, 7};
    *a5 = (struct Array) {5, 8};
    // *a6 = (struct Array) {6, 3};
    // *a7 = (struct Array) {7, 2};
    // *a8 = (struct Array) {8, 1};

    pq1->dados[pq1->qtd++] = a1;
    pq1->dados[pq1->qtd++] = a2;
    pq1->dados[pq1->qtd++] = a3;
    pq1->dados[pq1->qtd++] = a4;
    pq1->dados[pq1->qtd++] = a5;
    // pq1->dados[pq1->qtd++] = a6;
    // pq1->dados[pq1->qtd++] = a7;
    // pq1->dados[pq1->qtd++] = a8;

    pq1 = invertQueueHeap(pq1);

    for(int i = 0; i < pq1->qtd; i++)
    {
        printf("%d \n", pq1->dados[i]->val);
    }
    return 0;
}
