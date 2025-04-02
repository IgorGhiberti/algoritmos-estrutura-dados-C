/*Escreva um programa que faça a conversão numérica da base 10 para a base escolhida usando uma pilha:
Decimal para Binário
Decimal para Octal*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 50

struct Pilha {
    int qtd;
    int dados[MAX];
};

struct Pilha* decimalParaBinario(struct Pilha *pi, int n)
{
    while(n != 0)
    {
        pi->dados[pi->qtd] = n % 2;
        n = n / 2;
        pi->qtd++;
    }

    return pi;
}

struct Pilha* decimalParaOctal(struct Pilha *pi, int n)
{
    while(n != 0)
    {
        pi->dados[pi->qtd] = n % 8;
        n = n / 8;
        pi->qtd++;
    }

    return pi;
}

int main()
{
    struct Pilha *pi = (struct Pilha *)malloc(sizeof(struct Pilha));
    *pi = (struct Pilha) {0, {}};

    decimalParaHexa(pi, 200);

    int j = pi->qtd-1;
    for(int i = 0; i < pi->qtd; i++)
    {
        printf("%d \n", pi->dados[j]);
        j--;
    }
}