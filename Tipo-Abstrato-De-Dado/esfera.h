typedef struct esfera Esfera;

Esfera* esferaCria(float diametro, float h);

void esferaLibera(Esfera* c);

int esferaAcessa(Esfera* c, float* x, float* h);

float calculaVolume(esfera* c);

float calculaArea(esfera* c);

float calculaRaio(esfera* c);
