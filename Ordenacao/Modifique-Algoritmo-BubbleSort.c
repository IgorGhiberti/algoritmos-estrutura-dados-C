//Modifique o bubble sort para receber uma string e colocar as suas letras em ordem crescente


#include <stdio.h>
#include <string.h>

void bubbleSort(char *V, int n)
{
  int i, continua, fim = n;
  char aux;
  do{
    continua = 0;
    for (i = 0; i < fim-1; i++) {
      if(V[i] > V[i+1])
      {
        aux = V[i];
        V[i] = V[i+1];
        V[i+1] = aux;
        continua = i;
      }
    }
    fim--;
  }while(continua != 0);
}

int main()
{
  char V[5] = "dacb";
  int n = 4;
  bubbleSort(V, n);

  for(int j = 0; j < n; j++)
      {
    printf("%c ", V[j]);
  }
  return 0;
}
