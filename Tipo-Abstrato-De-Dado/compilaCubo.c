#include <stdio.h>
#include <stdlib.h>
#include "cubo.h"

int main()
{
  float d;
  float v;
  float a;
  float x;
  Cubo *c;

  c = Cubo_cria(10.0);

  v = calculaVolume(c);
  d = retornaLadoCubo(c);
  a = calculaArea(c);

  printf("Volume do cubo %.2f \n", v);
  printf("Área do cubo %.2f \n" , a);
  printf("Lado do cubo %.2f \n", d);

  Cubo_Libera(c);
  system("pause");
  return 0;
}
