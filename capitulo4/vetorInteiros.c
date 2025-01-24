#include <stdio.h>
#include <stdlib.h>
#include "vetorInteiros.h"

List* listCria(int x[])
{
  Lis* l = (List*) malloc(sizeof(List));
  if(l != NULL)
  {
    l->x = x;
  }
  
  return l;
}

int listAdd(List* l, int n)
{
  int tam = sizeof(l)/sizeof(l[0]);
  if(l == NULL || l[tam] != NULL)
    return 0;

  l[tam] = n;
  return 1;
}

int[] acessaList(List* l, int* x[])
{
  if(l == NULL)
    return 0;

  *x = l->x;
  return x;
}
