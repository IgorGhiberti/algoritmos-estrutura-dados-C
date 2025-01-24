typedef struct list List;

List* listCria (int x[]);

int* listUne(List* l, int x[], int y[]);

int listAdd(List* l, int n);

int listRemove(List* l, int indice);

int* acessaList(List* l, int* x[]);

int* listInterse(List* l, List* n);

int* listDif(List* l, int x[], int y[]);

int listPertence(List* l, int x);

int menorValor(List* l);

int maiorValor(List *l);

bool listEquals(List *l, List *n);

int listTam(List *l);

bool listEmpity(List *l);


