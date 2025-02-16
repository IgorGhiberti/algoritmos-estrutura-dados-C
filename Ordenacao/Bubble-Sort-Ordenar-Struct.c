//Modifique o algoritmo bubble sort para que o mesmo possa ordenar um conjunto de alunos por seu nome. Cada aluno é representado por uma estrutura contendo seu nome e número de matrícula.


#include <stdio.h>
#include <string.h>

struct aluno{
  int mat;
  char nome[30];
};

void bubbleSort(struct aluno *V, int n)
{
  int i, continua, fim = n;
  struct aluno aux;
  do{
    continua = 0;
    for (i = 0; i < fim-1; i++) {
      if(strcmp(V[i].nome,V[i+1].nome) > 0)
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
  struct aluno V[4] = {{2, "Andre"}, {3, "João"}, {4, "Pedro"}, {5, "Luís"}};
  int n = 4;

  bubbleSort(V, n);

  for(int j = 0; j < n; j++)
      {
    printf("%s ", V[j].nome);
  }

  return 0;
}
