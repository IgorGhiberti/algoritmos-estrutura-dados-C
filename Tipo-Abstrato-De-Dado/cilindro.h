typedef struct cilindro Cilindro;

Cilindro* cilindroCria(float diametro, float h);

void cilindroLibera(Cilindro* c);

int cilindroAcessa(Cilindro* c, float* x, float* h);

float calculaVolume(Cilindro* c);

float calculaArea(Cilindro* c);

float calculaRaio(Cilindro* c);
