/*4)Uma sequência de inserções (I) e remoções (R) é considerada validada se ela tem igual número de Is e Rs.
Além disso, todas as operações devem ser possíveis, isto é, a remoções só pode ocorrer se houver elementos na pilha.
Crie um algoritmo para validar se uma sequência (Ex: IRIIRR) é válida.*/

#include <stdio.h>
#include <stdlib.h>


int inserir(int isPossible, int n)
{
    if(isPossible <= 5)
    {
        printf("Número: %d inserido com sucesso! \n", n);
        return 1;
    }
    else
    {
        printf("Memória ou pilha cheia!\n");
        return 0;
    }
}

int remover(int isPossible, int n)
{
    if(isPossible > 0)
    {
        printf("Número: %d removido com sucesso!\n", n);
        return 1;
    }
    else
    {
        printf("Pilha vazia!\n");
        return 0;
    }
}


int sequenciaValida(char seq[20])
{
    int countI = 0;
    int countR = 0;
    for(int i = 0; i < 20-1; i++)
    {
        if(seq[i] == 'I')
            countI++;

        if(seq[i] == 'R')
            countR++;
    }

    if(countI != countR)
    {
        return 0;
    }

    int i = 0;

    while(i < countI)
    {
        int ok = inserir(i, i);
        if(!ok)
            return 0;
        i++;
    }

    i = 1;

    while(i < countR)
    {
        int ok = remover(i, i);
        if(!ok)
            return 0;
        i++;
    }

    return 1;
}

int main()
{
    int result = sequenciaValida("IIIIIIIIIIIIRRRRRRRRRRRR");
    printf("%d", result);
    return 0;
}