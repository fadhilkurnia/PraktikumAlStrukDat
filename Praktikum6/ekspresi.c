/* Praktikum 6
 * Nama 	: Fadhil Imam Kurnia
 * NIM		: 13515146
 * File		: ekspresi.c
 */

#include <stdio.h>
#include <math.h>
#include "stackt.h"
#include "boolean.h"
#include "mesintoken.h"

int Operasi(int a, int b, Token K){
	  int val = 0;
	  switch (K.tkn) {
      case '-': val = a-b;
              break;
      case '+': val = a+b;
              break;
      case '*': val = a*b;
              break;
      case '/': val = a/b;
              break;
      case '^': val = (int) pow((double) a,(double) b);
              break;
    }

    return val;
}

int main(){
	Stack S;
	int temp,x,y;

	CreateEmpty(&S);
	STARTTOKEN();
	if(EndToken){
		printf("Ekspresi kosong\n");
	}else{
		while(!EndToken){
			if(CToken.tkn=='b'){
				/*jika bukan operator*/
				printf("%d\n",CToken.val);
				Push(&S,CToken.val);
			}else{
				/*jika operator*/
				Pop(&S,&x);
				Pop(&S,&y);
				printf("%d %c %d\n",y,CToken.tkn,x);
				printf("%d\n",Operasi(y,x,CToken));
				Push(&S, Operasi(y,x,CToken));
			}

			ADVTOKEN();
		}
		printf("Hasil=%d\n",InfoTop(S));
	}

	return 0;
}
