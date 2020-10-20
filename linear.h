typedef int(*TCompararBS)(void *e1, void *e2);
typedef int(*TRecuperarChaveBS)(void *e1);

void bucketsort(void **L, int N, int K, int interval, TRecuperarChaveBS recuperarChave, TCompararBS comparar);


typedef int(*TRecuperarChaveCS)(void*);
void countingsort(void **A, int N, int K, TRecuperarChaveCS recuperarChave);
