#include <stdio.h>
#include <stdlib.h>
#include "vetorInteiros.h"

List* listCria(int tam)
{
  List* l = (List*) malloc(sizeof(List));
  if(l != NULL)
  {
    l->dados = (int*) malloc(tam * sizeof(int));
    l->n = 0;
    l->tam = tam;
  }
  
  return l;
}

List* listUne(List *l, List *l2)
{
  List* l3 = (List*) malloc(sizeof(List));
  int tam = 100;
  l3->dados = (int*) malloc(tam * sizeof(int));
  l3->n = 0;
  int contador = 0;
  int contador2 = 0;

  while(contador < l->n)
  {
    l3->dados[l3->n] = l->dados[contador];
    contador++;
    l3->n++;
  }

  while(contador2 < l2->n)
  {
    l3->dados[l3->n] = l2->dados[contador2];
    contador2++;
    l3->n++;
  }

  return l3;
 }

int listAdd(List* l, int x)
{
  l->dados[l->n] = x;
  l->n++;
  return 1;
}

int listRemove(List* l, int indice)
{
  l->dados[indice] = 0;
  l->n--;
  return 1;
}

void destroiList(List *l)
{
  free(l->dados);
  free(l);
}

int acessaList(List* l, int x)
{
  return l->dados[x];  
}

int listEmpity(List* l)
{
  if(l->n == 0)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int tamanhoList(List* l)
{
  return l->tam;
}

int menorValor(List* l)
{
  int menor = l->dados[0];

  for(int i = 0; i < l-> tam; i++)
  {
    if(menor > l->dados[i])
    {
      menor = l->dados[i];
    }
  }

  return menor;
}

int maiorValor(List* l)
{
  int maior = l->dados[0];

  for(int i = 0; i < l-> tam; i++)
  {
    if(maior < l->dados[i])
    {
      maior = l->dados[i];
    }
  }

  return maior;
}

int listPertence(List* l, int x)
{
  for(int i = 0; i < l-> tam; i++)
  {
    if(x == l->dados[i])
    {
      return 1;
    }
  }

  return 0;
}

int listEquals(List *l, List* l2)
{
  for(int i = 0; i < (l->tam + l2->tam); i++)
  {
    if(l->dados[i] != l2->dados[i])
    {
      return 0;
    }

    if(l->dados[i] == 0 && l2->dados[i] == 0)
    {
      return 1;
    }
  }

  return 1;
}

List* listIntersect(List *l, List *l2)
{
  List* l3 = (List*) malloc(sizeof(List));
  int tam = 100;
  l3->dados = (int*) malloc(tam * sizeof(int));
  l3->n = 0;
  l3->tam = tam;
  
  for(int i = 0; i < l->tam; i++)
  {
    for(int j = 0; j < l2->tam; j++)
    {
      if(l->dados[i] == l2->dados[j])
      {
        l3->dados[l3->n] = l2->dados[j];
        l3->n++;
      }
    }
  }

  return l3;

}

List* listDif(List *l, List *l2)
{
  List* l3 = (List*) malloc(sizeof(List));
  int tam = 100;
  l3->dados = (int*) malloc(tam * sizeof(int));
  l3->n = 0;
  l3->tam = tam;
  for(int i = 0; i < l->tam; i++)
  {
    int found = 0;
    for(int j = 0; j < l2->tam; j++)
    {
      if(l->dados[i] == l2->dados[j])
      {
         found =1; 
      }
    }

    if(found == 0)
      {
        l3->dados[l3->n] = l->dados[i];
        l3->n++;
      }
  }

  return l3;

}
