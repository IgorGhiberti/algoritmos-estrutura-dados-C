#include <stdlib.h>
#include <math.h>
#include "cilindro.h"

struct cilindro{
  float d;
  float h;
};

Cilindro* cilindroCria(float d, float h)
{
  Cilindro* c = (Cilindro*) malloc(sizeof(cilindro));
  if(c != NULL)
  {
    c->d = d;
    c->h = h;
  }
  return c;
}

void cilindroLibera(Cilindro* c)
{
  free(c);
}

int cilindroAcessa(Cilindro* c, float* d, float* h)
{
  if(c == NULL)
    return -1;

  *d = c->d;
  *h = c->h;
  return 1;
}

float calculaVolume(Cilindro* c)
{
  float raio = c->d/2;
  float altura = c->h;
  float v = 3.14 * pow(raio, 2) * altura;
  return v;
}

float calculaArea(Cilindro* c)
{
  float raio = c->d/2;
  float altura = c->h;
  float areaBase = 3.14 * pow(raio, 2);
  float areaLateral = 2 * 3.14 * raio * altura;
  float areaTotal = (2*areaLateral) + areaBase;
  return areaTotal;
}

float calculaRaio(Cilindro* c)
{
  float raio = c->d/2;
  return raio;
}
