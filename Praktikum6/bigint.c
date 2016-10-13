/* Praktikum 6
 * Nama 	: Fadhil Imam Kurnia
 * NIM		: 13515146
 * File		: bigint.c
 */

#include <stdio.h>
#include "stackt.h"

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



void TulisStack(Stack S)
/* Menulis isi Stack secara horizontal */
{
  infotype X;

  if(!IsEmpty(S)){
    InverseStack(&S);
    while (S.TOP>0) {
      printf("%d", InfoTop(S));
      Pop(&S,&X);
    }
    printf("\n");
  }else
    printf("Stack kosong\n");
}

int main(){
	char input[100];
	Stack S1,S2, SPlus;
	int i = 0, temp,x,y;

	CreateEmpty(&S1);
	scanf("%s",input);
	while(input[i]!='#'){
		Push(&S1, (input[i]-'0'));
		i++;
	}
	CreateEmpty(&S2); i =0;
	scanf("%s",input);
	while(input[i]!='#'){
		Push(&S2, (input[i]-'0'));
		i++;
	}
	CreateEmpty(&SPlus); temp =0;
	while(S1.TOP>0 && S2.TOP>0){
		Pop(&S1,&x);
		Pop(&S2,&y);
		temp += x + y;
		Push(&SPlus, temp%10);
		temp = temp/10;
	}
	if(S1.TOP>0){
		while(S1.TOP>0){
			Pop(&S1,&x);
			temp += x;
			Push(&SPlus,temp%10);
			temp = temp/10;
		}
		if(temp>0)
			Push(&SPlus,temp);
	}else{
		while(S2.TOP>0){
			Pop(&S2,&x);
			temp += x;
			Push(&SPlus,temp%10);
			temp = temp/10;
		}
		if(temp>0)
			Push(&SPlus,temp);
	}

	InverseStack(&SPlus);
	TulisStack(SPlus);
	return 0;
}
