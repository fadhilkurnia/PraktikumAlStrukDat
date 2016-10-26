#include "listdp.h"
#include <stdio.h>

int main(){
	List L;
	address P = Alokasi(354), Q = Alokasi(90);
	infotype X;
	CreateEmpty(&L);
	InsertLast(&L,P);
	InsVFirst(&L,12);
	InsVFirst(&L,13);
	DelBefore(&L,&Q,P);
	printf(">> %d",Info(Q));
	PrintForward(L);
	PrintBackward(L);
	
	return 0;
}
