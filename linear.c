#include "../obasico/listase.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "linear.h"

void countingsort(void **A, int N, int K, TRecuperarChaveCS recuperarChave){
    void **B = malloc(sizeof(void*)*N);

    int contagem[K];
    memset(contagem,0,K*sizeof(int));

    for (int i=0; i<N; i++){
      int j = recuperarChave(A[i]);
      contagem[j]++;
    }

    for(int j=1;j<K;j++){
      contagem[j] += contagem[j-1];
    }

    for (int i=N-1;i>=0;i--){
      int j = recuperarChave(A[i]);
      B[contagem[j]-1] = A[i];
      contagem[j]--;
    }

    for(int i=0;i<N;i++)
      A[i] = B[i];

    free(B);
}


void bucketsort(void **L, int N, int K, int interval, TRecuperarChaveBS recuperarChave, TCompararBS comparar){
  TListaSE **bucket = malloc(sizeof(TListaSE*)*K);

  for (int i=0;i<K;i++){
    bucket[i] = criarLSE();
  }

  for (int i=0;i<N;i++){
    int j = recuperarChave(L[i]) / interval;
    printf("%d %d\n", j, recuperarChave(L[i]));

    inserirOrdenadoLSE(bucket[j], L[i], comparar );
  }

  int i=0;
  for (int j=0;j<K;j++){
    TListaSE *lse = bucket[j];

    while( ! vaziaLSE(lse) ){
        void *chave = removerInicioLSE(lse);
        L[i++] = chave;
    }

    destruirLSE(lse);
  }
}
