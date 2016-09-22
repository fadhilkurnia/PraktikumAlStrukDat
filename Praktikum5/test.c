/* Praktikum 5
 * Nama : Fadhil Imam Kurnia
 * NIM	: 13515146
 * File	: telegram.c
 * */


#include <stdio.h>
#include "mesintoken.h"
#include "mesinkar.h"

int main(){
	STARTTOKEN();
	while(!EndToken){
		printf("%c %d\n", CToken.tkn, CToken.val);
		ADVTOKEN();
	}
	
	return 0;
}
