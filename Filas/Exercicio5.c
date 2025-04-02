/*Considere uma fila que armazena números inteiros. Faça uma função que receba uma fila e exclua todos
os números negativos. Faça para fila estática e dinâmica. A ordem não deve ser alterada.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct Queue{
    int qtd;
    int dados[MAX];
    int inicio;
    int final;
};

struct Queue* deleteNegativeNumbers(struct Queue *q1)
{
    int i = q1->inicio;
    int temp[MAX];
    int qtdTemp = 0;
    while(i < q1->qtd)
    {
        if(q1->dados[i] > 0)
        {
            temp[qtdTemp] = q1->dados[i];
            qtdTemp++;
        }
        i++;
    }

    q1->inicio = qtdTemp + 1;
    q1->qtd = 0;
    q1->final = q1->inicio;
    i = 0;

    while(qtdTemp > 0)
    {
        q1->dados[q1->final] = temp[i];
        q1->final++;
        q1->qtd++;
        i++;
        qtdTemp--;
    }
    q1->final--;
    return q1;
}

struct Element{
    int val;
    struct Element *next;
};

struct QueueNode{
    int qtd;
    struct Element *inicio;
    struct Element *final;
};

struct QueueNode*  deleteNegativeNumbersQueueNode(struct QueueNode *q1)
{
    struct QueueNode *curr = q1;
    int temp[MAX];
    int qtdTemp = 0;
    while(curr->inicio != NULL)
    {
        if(curr->inicio->val >= 0)
        {
            temp[qtdTemp] = curr->inicio->val;
            qtdTemp++;
        }
        curr->inicio = curr->inicio->next;
    }

    q1->inicio = NULL;
    q1->final = NULL;
    q1->qtd = 0;
    int i = 0;

    while(qtdTemp > 0)
    {
        if(q1->inicio == NULL)
        {
            q1->inicio = (struct Element*)malloc(sizeof(struct Element));
            q1->inicio->val = temp[i];
            q1->final = q1->inicio;
            q1->inicio->next = q1->final;
        }
        else
        {
            q1->final->next = (struct Element*)malloc(sizeof(struct Element));
            q1->final->next->val = temp[i];
        }

        q1->final = q1->final->next;
        i++;
        qtdTemp--;
    }

    return q1;

}

int main()
{
    /*struct Queue *q1 = (struct Queue *)malloc(sizeof(struct Queue));
    *q1 = (struct Queue) {9, {1,2,3,4,-5,6,7,-8, 0}, 0, 8};

    q1 = deleteNegativeNumbers(q1);
    int j = q1->inicio;
    for(int i = 0; i < q1->qtd; i++)
    {
        printf("%d \n", q1->dados[j]);
        j++;
    }
    printf("Quantidade: %d \n", q1->qtd);
    printf("Início: %d \n", q1->inicio);
    printf("Final: %d \n", q1->final);
*/

    // Inicialização da fila diretamente na main
    struct QueueNode *minhaFila = (struct QueueNode*) malloc(sizeof(struct QueueNode));
    if (minhaFila == NULL) {
        printf("Erro ao alocar memória para a fila!\n");
        return 1;
    }

    // Inicialização da fila
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
        if(i < 3) novoElemento->val = i * 5; // Valores 5, 10, 15
        if(i == 4) novoElemento->val = i * -5; // Valores, -20
        if(i == 5) novoElemento->val = 12;
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

    minhaFila = deleteNegativeNumbersQueueNode(minhaFila);
    struct Element *atual = minhaFila->inicio;
    while (atual != NULL) {
        printf("%d ", atual->val);
        atual = atual->next;
    }
    printf("\n");

    return 0;
}