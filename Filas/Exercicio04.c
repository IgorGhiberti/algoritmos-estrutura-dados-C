/*Implemente uma função que receba uma fila e a inverta, faça para fila estática e dinâmica.*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct Queue{
    int qtd;
    int dados[MAX];
    int inicio;
    int final;
};

struct Queue* reverseQueue(struct Queue *q1)
{
    int temp;
    int inicio = q1->inicio;
    int final = q1->final;

    while(inicio < final)
    {
        temp = q1->dados[inicio];
        q1->dados[inicio] = q1->dados[final]; 
        q1->dados[final] = temp;
        inicio++;
        final--;
    }

    return q1;
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

struct QueueNode* reverseQueueNode(struct QueueNode *q1)
{
    struct QueueNode *curr = q1;
    struct Element *temp = q1->inicio;
    struct Element *prev = NULL;
    while(curr->inicio != NULL)
    {
        temp = curr->inicio->next;
        curr->inicio->next = prev;
        prev = curr->inicio;
        curr->inicio = temp;
    }

    curr = q1;

    while(curr->final->next != NULL)
    {
        curr->final = curr->final->next;
    }
    q1->final = curr->final;
    q1->inicio = prev;
    return q1;
}

int main()
{
    /*struct Queue *q1 = (struct Queue *)malloc(sizeof(struct Queue));
    *q1 = (struct Queue) {5, {1,2,3,4,5}, 0, 4};

    q1 = reverseQueue(q1);
    for(int i = 0; i < q1->qtd; i++)
    {
        printf("%d \n", q1->dados[i]);
    }
    */
    
    // Inicialização da fila diretamente na main
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

    // Exibindo os valores da fila
    printf("Quantidade de elementos na fila: %d\n", minhaFila->qtd);
    printf("Valores na fila:\n");

    minhaFila = reverseQueueNode(minhaFila);
    struct Element *atual = minhaFila->inicio;
    while (atual != NULL) {
        printf("%d ", atual->val);
        atual = atual->next;
    }
    printf("\n");

    return 0;
}

