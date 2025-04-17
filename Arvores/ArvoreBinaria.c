#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h" //inclui os Prot�tipos

struct NO{
    int info;
    struct NO *esq;
    struct NO *dir;
};



ArvBin* cria_ArvBin(){
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void libera_NO(struct NO* no){
    if(no == NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}

void libera_ArvBin(ArvBin* raiz){
    if(raiz == NULL)
        return;
    libera_NO(*raiz);//libera cada n�
    free(raiz);//libera a raiz
}

void insereDireita(struct NO* no, int valor) {
    if(no->dir == NULL) {
        struct NO *novo = (struct NO*) malloc(sizeof(struct NO));
        novo->info = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        no->dir = novo;
    } else {
        if(valor > no->dir->info)
            insereDireita(no->dir, valor);
        else
            insereEsquerda(no->dir, valor);
    }
}

void insereEsquerda(struct NO* no, int valor) {
    if(no->esq == NULL) {
        struct NO *novo = (struct NO*) malloc(sizeof(struct NO));
        novo->info = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        no->esq = novo;
    } else {
        if(valor > no->esq->info)
            insereDireita(no->esq, valor);
        else
            insereEsquerda(no->esq, valor);
    }
}

void insere_ArvBin(ArvBin* raiz, int valor){

    if(raiz == NULL || *raiz == NULL) { //Ou seja, sem filhos
        struct NO *novo = (struct NO*) malloc(sizeof(struct NO));
        novo->info = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        *raiz = novo;
    } else {
        if(valor > (*raiz)->info)
            insereDireita(*raiz, valor);
        else
            insereEsquerda(*raiz, valor);
    }
}

struct NO* remove_atual(struct NO* atual) {
    struct NO *no1, *no2;
    if(atual->esq == NULL){
        no2 = atual->dir;
        free(atual);
        return no2;
    }
    no1 = atual;
    no2 = atual->esq;
    while(no2->dir != NULL){
        no1 = no2;
        no2 = no2->dir;
    }
    // no2 � o n� anterior a r na ordem e-r-d
    // no1 � o pai de no2
    if(no1 != atual){
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return no2;
}

int remove_ArvBin(ArvBin *raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* ant = NULL;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info){
            if(atual == *raiz)
                *raiz = remove_atual(atual);
            else{
                if(ant->dir == atual)
                    ant->dir = remove_atual(atual);
                else
                    ant->esq = remove_atual(atual);
            }
            return 1;
        }
        ant = atual;
        if(valor > atual->info)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

struct NO* removeArvBin(struct NO *no, int valor)
{
    if(no == NULL) {
        return NULL;
    }
    else {
        if(no->info == valor) {
            if(no->esq == NULL && no->dir == NULL) { //Não tem filhos
                free(no);
                return NULL;
            }
            else if(no->esq != NULL && no->dir == NULL) { //Tem filho apenas a esquerda
                struct NO *ant = (struct NO*) malloc(sizeof(struct NO));
                ant = no->esq;
                free(no);
                return ant;
            }
            else if(no->dir != NULL && no->esq == NULL) { //Tem filho apenas a direita
                struct NO *ant = (struct NO*) malloc(sizeof(struct NO));
                ant = no->esq;
                free(no);
                return ant;
            }
            else { //Tem dois filhos
                struct NO *atual = (struct NO*) malloc(sizeof(struct NO));
                atual = no;
                atual = no->dir;
                while(atual->esq != NULL) {
                    no = no->esq;
                }
                no->info = atual->info;
                free(atual);
            }
        }
        else {
            if(valor > no->info)
                removeArvBin(no->dir, valor);
            else
                removeArvBin(no->esq, valor);
            return no;
        }
    }
}

int estaVazia_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return 1;
    if(*raiz == NULL)
        return 1;
    return 0;
}

int totalNO_ArvBin(ArvBin *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = totalNO_ArvBin(&((*raiz)->esq));
    int alt_dir = totalNO_ArvBin(&((*raiz)->dir));
    return(alt_esq + alt_dir + 1);
}

int altura_ArvBin(ArvBin *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = altura_ArvBin(&((*raiz)->esq));
    int alt_dir = altura_ArvBin(&((*raiz)->dir));
    if (alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return(alt_dir + 1);
}

int consulta_ArvBin(ArvBin *raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info){
            return 1;
        }
        if(valor > atual->info)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

void preOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        printf("%d\n",(*raiz)->info);
        preOrdem_ArvBin(&((*raiz)->esq));
        preOrdem_ArvBin(&((*raiz)->dir));
    }
}

void emOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        emOrdem_ArvBin(&((*raiz)->esq));
        printf("%d\n",(*raiz)->info);
        emOrdem_ArvBin(&((*raiz)->dir));
    }
}

void posOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        posOrdem_ArvBin(&((*raiz)->esq));
        posOrdem_ArvBin(&((*raiz)->dir));
        printf("%d\n",(*raiz)->info);
    }
}
