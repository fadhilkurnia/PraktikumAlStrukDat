#include "stackt.h"
#include "boolean.h"
#include "mesinkata.h"
#include <stdio.h>


void CopyStack(Stack Sin, Stack * Sout) {
  Stack Stemp;
  infotype X;

  CreateEmpty(&Stemp);
  CreateEmpty(*(&Sout));
  while (Sin.TOP>0) {
    Pop(&Sin,&X);
    Push(&Stemp,X);
  }
  while (Stemp.TOP>0) {
    Pop(&Stemp,&X);
    Push(&(*Sout),X);
  }
}

void InverseStack(Stack *S) {
  Stack Stemp;
  infotype X;

  CreateEmpty(&Stemp);
  while ((*S).TOP>0) {
    Pop(&(*S),&X);
    Push(&Stemp,X);
  }
  CopyStack(Stemp, &(*S));

}


void IsiStack(Stack *S)
/* Input stack hingga masukkan meerupakan angka 999 atau
   hingga stack penuh */
{
  infotype X;

  do {
    scanf("%d", &X);
    if(X!=999)
      Push(&(*S),X);
  } while(X!=999 && (*S).TOP<MaxEl);


}

void TulisStack(Stack S)
/* Menulis isi Stack secara horizontal */
{
  infotype X;

  if(!IsEmpty(S)){
    InverseStack(&S);
    while (S.TOP>0) {
      if (S.TOP==1)
        printf("%d", InfoTop(S));
      else
        printf("%d ", InfoTop(S));
      Pop(&S,&X);
    }
    printf("\n");
  }else
    printf("Stack kosong\n");
}

void FilterStack(Stack * S) {
  Stack Stemp;
  infotype X;

  CreateEmpty(&Stemp);
  while ((*S).TOP>0) {
    Pop(&(*S), &X);
    Push(&Stemp, X);
  }
  while (Stemp.TOP>0) {
    Pop(&Stemp, &X);
    if(X%2!=1)
      Push(&(*S), X);
  }
}

boolean IsOperator(Kata K){
  return (K.TabKata[1]=='*' || K.TabKata[1]=='/' || K.TabKata[1]=='+' || K.TabKata[1]=='-' || K.TabKata[1]=='^' );
}

void PrintKata(Kata K) {
  int i;
  for (i = 1; i <= K.Length; i++) {
    printf("%c",K.TabKata[i]);
  }
}

int KataToInt(Kata K){
  int val = 0, i;

  for (i = 1; i <= K.Length; i++) {
    val = val*10 + (K.TabKata[i] - '0');
  }

  return val;
}

Kata IntToKata(int x){
  int pembagi = 1;
  int temp;
  Kata K;

  K.Length = 0;
  while(x / pembagi > 9)
    pembagi *=10;
  while (pembagi>0) {
    temp = (x / pembagi)%10;
    K.Length++;
    switch (temp) {
      case 1: K.TabKata[K.Length] = '1';
              break;
      case 2: K.TabKata[K.Length] = '2';
              break;
      case 3: K.TabKata[K.Length] = '3';
              break;
      case 4: K.TabKata[K.Length] = '4';
              break;
      case 5: K.TabKata[K.Length] = '5';
              break;
      case 6: K.TabKata[K.Length] = '6';
              break;
      case 7: K.TabKata[K.Length] = '7';
              break;
      case 8: K.TabKata[K.Length] = '8';
              break;
      case 9: K.TabKata[K.Length] = '9';
              break;
    }
    pembagi /=10;
  }
  K.TabKata[K.Length+1]='\0';
  return K;
}

int main(){
  Stack Sin;

  CreateEmpty(&Sin);
  // printf("Hello, ayo isi stack \n");
  // IsiStack(&Sin);
  // TulisStack(Sin);
  // printf("Setelah dibuang bilangan ganjilnya \n");
  // FilterStack(&Sin);
  // TulisStack(Sin);

  printf("Bermain dengan pita token\n");
  STARTKATA();
  PrintKata(CKata);
  printf("\n");
  printf("%d\n", (KataToInt(CKata)/10));
  PrintKata(IntToKata(123));
  return 0;
}
