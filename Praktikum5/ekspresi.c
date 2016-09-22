/* Praktikum 5
 * Nama : Fadhil Imam Kurnia
 * NIM	: 13515146
 * File	: ekspresi.c
 * */


#include <stdio.h>
#include "mesintoken.h"
#include "mesinkar.h"

int main(){
	STARTTOKEN();
	if(EndToken){
		printf("Ekspresi kosong\n");
	}else{
		while(!EndToken){			
			if(CToken.tkn != 'b')
				printf("%c\n",CToken.tkn);
			else
				printf("%d\n",CToken.val);
			
			ADVTOKEN();
		}	
	}

	return 0;
}
