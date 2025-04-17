/*Escreva uma função que percorra uma skip list e delete todos os nós menor que N.*/
#include <stdio.h>
#include <stdlib.h>
#include "SkipList.h"
#include <time.h>

struct NO{
    int chave;
    struct NO **prox;
};

struct SkipList{
	int NivelMAX;
	float P;
	int nivel;
	struct NO *inicio;
};

void deletaNosMenorNSkipList(struct SkipList *sk, int n) {
    if(sk == NULL) {
        return;
    }

    struct NO *ant, *atual;

    for(int i = 0; i < sk->nivel; i++) {
        ant = sk->inicio;
        atual = sk->inicio->prox[i];

        while(atual != NULL) {
            if(atual->chave < n) {
                ant->prox[i] = atual->prox[i];
                atual = atual->prox[i];
            }
            else {
                ant = atual;
                atual = atual->prox[i];
            }
        }
    }
}

int main(){

	srand((unsigned)time(0));

    SkipList* sk = criaSkipList(10, 0.5);

    int i, vet[10] = {3,6,7,9,12,19,17,26,21,25};
    for(i=0; i<10; i++){
        insereSkipList(sk, vet[i]);
    }

    deletaNosMenorNSkipList(sk, 10);
    imprimeSkipList(sk);

    liberaSkipList(sk);

    return 0;
}