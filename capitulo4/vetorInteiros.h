typedef struct{
  int *dados;
  int n;
  int tam;
} List;

List* listCria (int tam);

List* listUne(List* l, List *l2);

int listAdd(List* l, int n);

int listRemove(List* l, int indice);

int acessaList(List* l, int indice);

void destroiList(List* l);

List* listIntersect(List* l, List* n);

List* listDif(List* l, List* n);

int listPertence(List* l, int x);

int menorValor(List* l);

int maiorValor(List *l);

int listEquals(List *l, List *n);

int listTam(List *l);

int listEmpity(List *l);

int tamanhoList(List *l);


