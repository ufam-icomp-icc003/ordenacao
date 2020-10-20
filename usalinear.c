#include "stdio.h"
#include "stdlib.h"
#include "linear.h"


static int compararInt(void *e1, void *e2){
  int *ee1 = e1; int *ee2=e2;
  return (*ee1-*ee2);
}

static int recuperarInt(void *e1){
  int *ee1 = e1;
  return *ee1;
}

int **lerInt(int N){
  int **L = malloc(sizeof(int*)*N);

  for (int k, i=0;i<N;i++){
    scanf("%d",&k);
    L[i] = malloc(sizeof(int));
    *(L[i]) = k;
  };// 2 3 4 7 3 2 4 7 5 5 4 4 5 6 7 8 2 4 8 5 3 3 8 ;

  return L;
}

void imprimirInt(int *L[], int N){
  for (int i=0;i<N;i++)
      printf("%d ", *L[i]);
  printf("\n");
}

typedef struct {
  int id;
  double sent;
} TSentimento;

int compararSent(void *e1, void *e2){
    TSentimento *ee1 = e1;
    TSentimento *ee2 = e2;
    int sent = (int)((ee1->sent - ee2->sent)*100);

    return sent;
};

int recuperarSent(void *e1){
  TSentimento *ee1 = e1;
  return (int)(ee1->sent*10);
}

TSentimento **lerSent(int N){
  TSentimento **L = malloc(sizeof(TSentimento*)*N);
  double sent;
  int id;
  char header[1000];

  //scanf("%s",header); //printf("%s\n", header );
  for (int i=0;i<N;i++){
    scanf("%d|%lf",&id, &sent);
    //printf("%d|%lf\n", id, sent);

    L[i] = malloc(sizeof(TSentimento));
    L[i]->id = id;
    L[i]->sent = sent;
  };

  return L;
// id|Sentiment
// 0|0.5
// 1|0.5
// 2|0.44444
// 3|0.5
// 4|0.42708
// 5|0.375
// 6|0.41667
// 7|0.54167
// 8|0.33333
// 9|0.45833
// 10|0.47222
// 11|0.59722
// 12|0.33333
// 13|0.93056
// 14|0.80556
// 15|0.81944
// 16|0.76389
// 17|0.5
// 18|0.5
// 19|0.69444
// 20|0.5
// 21|0.75
// 22|0.29167
}

void imprimirSent(TSentimento *L[], int N){
  for (int i=0;i<N;i++)
      printf("%d|%lf\n", L[i]->id, L[i]->sent);

}

void usar_BS(){
  int N=23, NBucket=5, Interval=2;
  //int **L = lerInt(N);

  TSentimento **L = lerSent(N);
  //imprimirInt(L, N);
  imprimirSent(L,N);

  //bucketsort(L, N, NBucket, Interval, recuperarInt, compararInt);
  bucketsort(L, N, NBucket, Interval, recuperarSent, compararSent);

  //imprimirInt(L, N);
  imprimirSent(L, N);
}

void usar_CS(){
  int N=23;
  int **L = lerInt(N);

  imprimirInt(L, N);

  countingsort(L, N, 9,recuperarInt);

  imprimirInt(L, N);
}

int main(int argc, char const *argv[]) {

  usar_BS();

  return 0;
}
