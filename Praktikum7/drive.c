#include <stdio.h>
#include "queue.h"

void CetakQ(Queue Q){
  int i =1;
  while (i<=MaxEl(Q)) {
    printf("%d %d",i ,Q.T[i]);
    if(Head(Q)==i)
      printf(" <= head");
    if(Tail(Q)==i)
      printf(" <= tail");
    printf("\n");
    i++;
  }
}

void PrintQueue(Queue Q){
  int i = Head(Q);
  printf("[");
  if (!IsEmpty(Q)) {
    while(i!=Tail(Q)){
      printf("%d ", Q.T[i]);
      i++;
      if(i == MaxEl(Q)+1)
        i=1;
    }
    printf("%d", Q.T[i]);
  }
  printf("]");
}

int main(){
  Queue Q;
  int i = 1,X;

  CreateEmpty(&Q, 5);
  Add(&Q, 1);
  Add(&Q, 2);
  Add(&Q, 3);
  Add(&Q, 4);

  CetakQ(Q);
  printf("--------\n");
  Del(&Q,&X);
  CetakQ(Q);

  Add(&Q, 6);
  printf("--------\n");
  CetakQ(Q);

  Del(&Q, &X);
  Del(&Q, &X);
  printf("-------- hapus 2 head\n");
  CetakQ(Q);

  Add(&Q, 99);
  printf("--------\n");
  CetakQ(Q);
  printf("isfull %d\n", IsFull(Q));

  Add(&Q, 100);
  printf("--------\n");
  CetakQ(Q);

  Add(&Q, 99);
  printf("--------\n");
  CetakQ(Q);
  printf("isfull %d\n", IsFull(Q));  Add(&Q, 99);
    printf("--------\n");
    CetakQ(Q);
    PrintQueue(Q);
    printf("isfull %d\n", IsFull(Q));
    Del(&Q, &X);
    Del(&Q, &X);
    printf("-------- hapus 1 head\n");
    CetakQ(Q);
    Add(&Q, 1000);
    printf("--------\n");
    CetakQ(Q);
    PrintQueue(Q);
    printf("isfull %d\n", IsFull(Q));

    Add(&Q, 1001  );
    printf("--------\n");
    CetakQ(Q);
    printf("isfull %d\n", IsFull(Q));
  //printf("%d\n", Q.T[1]);
  printf("%d\n", NBElmt(Q));
  PrintQueue(Q);
  DeAlokasi(&Q);
  PrintQueue(Q);
  return 0;
}
