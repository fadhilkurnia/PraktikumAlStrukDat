#include <stdio.h>
#include "listrek.h"

int main(){
	List L1,LP,LN;
	
	L1 = LP = LN = Nil;
	
	L1 = KonsB(L1,(-99));
	L1 = KonsB(L1,0);
	L1 = KonsB(L1,2);
	L1 = KonsB(L1,(-1));
	L1 = KonsB(L1,(-90));
	
	SplitOnX(L1,-1,&LP,&LN);
	
	PrintList(L1);
	printf("positif \n");
	PrintList(LP);
	printf("negatif \n");
	PrintList(LN);

	return 0;
}
