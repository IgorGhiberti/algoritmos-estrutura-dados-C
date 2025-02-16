#include <stdio.h>
#include <stdlib.h>
#include "vetorInteiros.h"

int main()
{
  List *l;
  List *l2;
  List *l3;
  l = listCria(10);
  l2 = listCria(10);

  /*
  listAdd(l, 5);
  listAdd(l, 12);
  listAdd(l2, 6);
  listAdd(l2, 13);

  l3 = listUne(l, l2);
  
  listRemove(l3, 3);

  for(int i = 0; i < 10; i++)
  {
    printf("Posição: %d valor: %d, ", i, acessaList(l3, i));
  }
  */

  //int isEmpity = listEmpity(l);
  //printf("%d ", isEmpity);
  
  //int tamanho = tamanhoList(l);
  //printf("%d", tamanho);
  
  //listAdd(l, 3);
  //listAdd(l, 12);
  //listAdd(l, 1);

  //int maior = maiorValor(l);

  //printf("O maior valor é: %d", maior);
  //int isEquals = listEquals(l, l2);
  //printf("%d", isEquals);

  //int isIn = listPertence(l, 25);
  //printf("%d", isIn);
  
  listAdd(l, 1);
  listAdd(l, 2);
  listAdd(l, 3);
  listAdd(l, 4);
  listAdd(l, 5);
  listAdd(l2, 1);
  listAdd(l2, 2);
  listAdd(l2, 3);
  
  l3 = listDif(l, l2);

  for(int i = 0; i < 10; i++)
  {
    printf("%d ", acessaList(l3, i));
  }

  destroiList(l);
  destroiList(l2);
  destroiList(l3);

  return 0;
}
