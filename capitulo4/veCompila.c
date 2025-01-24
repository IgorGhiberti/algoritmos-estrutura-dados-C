#include <stdio.h>
#include <stdlib.h>
#include "vetorInteiros.h"

int main()
{
  int x[10];
  List *l;

  x = listCria({10, 21, 23, 25});

  for(int i = 0; i < 4; i++)
  {
    printf("%d ", x[i]);
  }

  return 0;
}
