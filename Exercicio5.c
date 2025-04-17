//Dado um número  e um array ordenado, escreva um algoritmo para inserir esse array na sua posição correta.

#include <stdio.h>

void sortExercise(int *V, int n, int tam)
{
  
  for(int i = 0; i < tam; i++)
  {
    if(V[i] > n)
    {
        for(int j = i; j < tam - 1; j++){
          V[j] = V[j + 1];
      }
        V[i] = n;      
    }
  }
}

int main()
{
  int V[5] = {1, 2, 4, 5};
  int tam = sizeof(V)/sizeof(V[0]);
  int n = 3;

  sortExercise(V, n);

  for(int p = 0; p < 5; p++)
  {
    printf("%d ", V[p]);
  }

  return 0;
}
