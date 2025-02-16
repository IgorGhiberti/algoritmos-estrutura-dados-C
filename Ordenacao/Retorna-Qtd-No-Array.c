//Escreva um algoritmo que retorne quantas vezes um valor aparece em um array ordenado
#include <stdio.h>

int countValue(int *V, int tam, int elemento)
{
  int count = 0;
  for(int i = 0; i < tam; i++)
  {
    if(elemento == V[i])
    {
      count++;
    }
      else if(elemento < V[i])
    {
      return count;
    }
  }

  return count;
}


int main()
{
  int V[5] = {1, 1, 2, 3, 4};
  int tamanho = sizeof(V)/sizeof(V[0]);
  int elemento = 6;
  int value = countValue(V, tamanho, elemento);
  printf("%d", value);
  return 0;
}
