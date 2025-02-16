#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "cilindro.h"

int main()
{
  float d;
  float v;
  float a;
  float r;
  Cilindro *c;

  c = cilindroCria(50.5, 20.5);

  v = calculaVolume(c);

  a = calculaArea(c);

  r = calculaRaio(c);

  printf("Volume do cilindro: %.2f, área de cilindro: %.2f, raio do cilindro %.2f", v,a,r);

  return 0;


}


