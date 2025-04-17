/*Escreva uma função que percorra uma skip list e conte o número de nós com N níveis.*/
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

int countNosSkipList(struct SkipList *sk, int n) {
    if(sk == NULL) {
        return 0;
    }

    struct NO *curr;
    curr = sk->inicio->prox[0];
    int count = 0;

    struct NO *no = sk->inicio->prox[0];

        while(no != NULL) {
            int niveis_do_no = 0;
            while (niveis_do_no < sk->NivelMAX && no->prox[niveis_do_no] != NULL) {
                niveis_do_no++;
            }

            if(niveis_do_no == n)
                count++;

            no = no->prox[0];
        }

    return count;
}

int main(){

	srand((unsigned)time(0));

    SkipList* sk = criaSkipList(10, 0.5);

    int i, vet[10] = {3,6,7,9,12,19,17,26,21,25};
    for(i=0; i<10; i++){
        insereSkipList(sk, vet[i]);
    }

    int result = countNosSkipList(sk, 2);

    imprimeSkipList(sk);

    printf("%d", result);

    liberaSkipList(sk);

    return 0;
}

