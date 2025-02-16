//Modifique o algoritmo insertionSort para que ele retorne a qtd de vezes que fez uma troca

#include <stdio.h>

int insertSort(int *V, int n)
{
  int i, j, atual, count = 0;

  for(i = 1; i < n; i++)
  {
    atual = V[i];
    for(j = i; (j > 0) && (atual < V[j - 1]); j--)
    {
      V[j] = V[j - 1];
      count++;
    }
    V[j] = atual;
  }

  return count;
}

int main()
{
  int V[5] = {4, 23, 67, -8, 21};
  int n = 5;
  int value = 0;
  value = insertSort(V, n);
  printf("%d ", value);
  return 0;
}
