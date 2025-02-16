typedef struct cubo Cubo;

//Atribui um valor de lado a um cubo
Cubo* Cubo_cria(float x);

void Cubo_Libera(Cubo* c);

float calculaVolume(Cubo* c);

float retornaLadoCubo(Cubo* c);

float calculaArea(Cubo* c);
