//Modifique os algoritmos vistos para que ordene o array do menor para o maior valor
#include <stdio.h>
#include <cstdlib>
#include <math.h>
//Bubble Sort
void bubbleSort(int *V, int n)
{
  int i, continua, aux, fim = n;
  do{
    continua = 0;
    for (i = 0; i < fim-1; i++) {
      if(V[i] < V[i+1])
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


//Selection sort
void selectionSort(int *V, int n)
{
  int i, j, menor, troca;
  for(i = 0; i < n-1; i++){
    menor = i;
    for(j = i+1; j < n; j++)
    {
      if(V[j] > V[menor])
      {
        menor = j;
      }
    }
    if(i != menor)
    {
      troca = V[i];
      V[i] = V[menor];
      V[menor] = troca;
    }
  }
}

//Insertion sort
void insertionSort(int *V, int n)
{
  int i,j,atual;
  for(i = 1; i < n; i++)
  {
    atual = V[i];
    for(j = i; (j > 0) && (V[j - 1] < atual); j--)
    {
      V[j] = V[j - 1];
    }
    V[j] = atual;
  }
}

//Merge sort
void merge(int *V, int inicio, int meio, int fim)
{
  int *temp, p1, p2, tamanho, i, j, k;
  int fim1 = 0, fim2 = 0;
  tamanho = fim-inicio+1;
  p1 = inicio;
  p2 = meio+1;

  temp = (int *) malloc(tamanho*sizeof(int));
  if(temp != NULL)
  {
    for(i = 0; i<tamanho; i++)
    {
      if(!fim1 && !fim2){
        if(V[p1] < V[p2])
          temp[i] = V[p1++];
        else
          temp[i] = V[p2++];
        if(p1>meio) fim1=1;
        if(p2>fim) fim2=1;
      }else{
        if(!fim1)
        {
          temp[i] = V[p1++];
        }else{
          temp[i]=V[p2++];
        }
      }
        
    }
  }

  for(j=0, k = inicio; j < tamanho; j++, k++)
  {
    V[k] = temp[j];
  }
  free(temp);
}


void mergeSort(int *V, int inicio, int fim)
{
  int meio;
  if(inicio < fim)
  {
    meio = floor((inicio+fim)/2);
    mergeSort(V,inicio,meio);
    mergeSort(V,meio+1,fim);
    merge(V,inicio,meio,fim);
  }
}

//Quick sort
int particiona(int *V, int inicio, int final)
{
  int esq, dir, pivo, aux;
  esq = inicio;
  dir = final;
  pivo = V[inicio];
  while(esq < dir)
  {
    while(esq <= final && V[esq] <= pivo)
      esq++;
    while(dir >= 0 && V[dir] > pivo)
      dir--;
    if(esq > dir)
    {
      aux = V[esq];
      V[esq] = V[dir];
      V[dir] = aux;
    }
  }
  V[inicio] = V[dir];
  V[dir] = pivo;
  return dir;
}

void quickSort(int *V, int inicio, int fim)
{
  int pivo;
  if(fim > inicio)
  {
    pivo = particiona(V, inicio, fim);
    quickSort(V, inicio, pivo-1);
    quickSort(V, pivo+1, fim);
  }
}

//Testes
int main(){

  int V[5] = {23, 4, 67, -8, 21};
  int n = 5;
  
  //bubbleSort(V, n);
  //selectionSort(V, n);
  //insertionSort(V, n);
  //mergeSort(V, 0, n);
  quickSort(V, 0, n);
  for (int j = 0; j < n; j++) {
    printf("%d ", V[j]);
  }
  return 0;
}



