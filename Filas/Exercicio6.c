/*Crie uma função que imprima os elementos de uma fila*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct Queue{
    int qtd;
    int dados[MAX];
    int inicio;
    int final;
};

void printQueueElements(struct Queue *q1)
{
    if(q1->final < q1->inicio)
    {
        return;
    }
    printf("%d\n", q1->dados[q1->inicio]);
    q1->inicio++;
    q1->qtd--;
    printQueueElements(q1);
}

struct Element{
    int val;
    struct Element *next;
};
struct QueueNode{
    int val;
    int qtd;
    struct Element *inicio;
    struct Element *final;
};

void printQueueElementsNode(struct Element *e1)
{
    if(e1 == NULL)
    {
        return;
    }
    printf("%d\n", e1->val);
    printQueueElementsNode(e1->next);
}

int main()
{
    /*struct Queue *q1 = (struct Queue *)malloc(sizeof(struct Queue));
    *q1 = (struct Queue) {9, {1,2,3,4,-5,6,7,-8, 2}, 0, 8};

    printQueueElements(q1);
    */

    struct QueueNode *minhaFila = (struct QueueNode*) malloc(sizeof(struct QueueNode));
    if (minhaFila == NULL) {
        printf("Erro ao alocar memória para a fila!\n");
        return 1;
    }

    // Inicialização da fila
    minhaFila->val = 0;       // Valor inicial da fila
    minhaFila->qtd = 0;       // Quantidade de elementos na fila (inicialmente 0)
    minhaFila->inicio = NULL; // Ponteiro para o início da fila (inicialmente NULL)
    minhaFila->final = NULL;  // Ponteiro para o final da fila (inicialmente NULL)

    // Adicionando 5 valores à fila
    for (int i = 1; i <= 5; i++) {
        // Aloca memória para um novo elemento
        struct Element *novoElemento = (struct Element*) malloc(sizeof(struct Element));
        if (novoElemento == NULL) {
            printf("Erro ao alocar memória para o elemento!\n");
            return 1;
        }

        // Define o valor e o próximo ponteiro do novo elemento
        novoElemento->val = i * 10; // Valores 10, 20, 30, 40, 50
        novoElemento->next = NULL;

        // Se a fila estiver vazia, o novo elemento será o início e o final
        if (minhaFila->inicio == NULL) {
            minhaFila->inicio = novoElemento;
            minhaFila->final = novoElemento;
        } else {
            // Caso contrário, adiciona o novo elemento ao final da fila
            minhaFila->final->next = novoElemento;
            minhaFila->final = novoElemento;
        }

        // Atualiza a quantidade de elementos na fila
        minhaFila->qtd++;
    }

    printQueueElementsNode(minhaFila->inicio);
    return 0;
}
