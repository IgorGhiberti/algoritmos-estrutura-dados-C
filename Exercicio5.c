//Dado um número  e um array ordenado, escreva um algoritmo para inserir esse array na sua posição correta.

#include <stdio.h>

void sortExercise(int *V, int n, int tam)
{
  int currentSize = 0;
    while (currentSize < tam && V[currentSize] != 0) {
        currentSize++;
    }

  for(int i = 0; i < currentSize; i++)
  {
    if(V[i] > n)
    {
        for(int j = currentSize - 1; j >= i; j++){
          V[j + 1] = V[j];
      }
      V[i] = n;
      return;
    }
  }

  V[currentSize] = n;
}

int main()
{
  int V[5] = {1, 2, 4, 5};
  int tam = sizeof(V)/sizeof(V[0]); 
  int n = 3;
  sortExercise(V, n, tam);

  for(int p = 0; p < 5; p++)
  {
    printf("%d ", V[p]);
  }

  return 0;
}
