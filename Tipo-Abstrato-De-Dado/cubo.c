#include <stdio.h>
#include "cubo.h"
#include <math.h>
#include <stdlib.h>

struct cubo{
  float x;
};

Cubo* Cubo_cria(float x)
{
  Cubo* c = (Cubo*) malloc(sizeof(Cubo));
  if(c != NULL)
  {
    c->x = x;
  }
  return c;
}

void Cubo_Libera(Cubo* c)
{
  free(c);
}

float calculaVolume(Cubo* c)
{
  float lado = c->x;
  int volume = pow(lado, 3);
  return volume;
}

float retornaLadoCubo(Cubo* c)
{
  if(c == NULL)
    return -1;
  
  float lado = c->x;

  return lado;
}

float calculaArea(Cubo* c)
{
  if(c == NULL)
    return -1;
  
  float lado = c->x;
  float area = 6 * (pow(lado, 2));

  return area;
}

