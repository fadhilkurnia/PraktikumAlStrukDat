#include "bintree.h"
#include <stdio.h>

int main(){
	infotype X;
	List Li,Li2,Li3;
	
	BinTree L = AlokNode(5);
	AddDaunTerkiri(&L,9);
	BinTree R = AlokNode(4);
	AddDaun(&R,4,2,false);
	AddDaunTerkiri(&R,7);
	BinTree P;
	BinTree Q = Nil;
	MakeTree(3,L,R,&P);
	PrintTree(P,2);
	printf("NbElmt >> %d\n",NbElmt(P));
	printf("NbDaun >> %d\n",NbDaun(P));
	printf("IsSkewLeft >> %d\n",IsSkewLeft(P));
	printf("IsSkewRight >> %d\n",IsSkewRight(P));
	printf("Level >> %d\n",Level(P,7));
	printf("Tinggi >> %d\n",Tinggi(P));
	//DelDaun(&P,9);
	//printf("DelDaun :\n");
	//PrintTree(P,2);
	//DelDaunTerkiri(&P,&X);
	//printf("DelDaunTerkiri >> %d\n",X);
	//PrintTree(P,2);
	Li = Li2 = Li3 = Nil;
	printf("MakeListDaun :\n");
	Li = MakeListDaun(P);
	PrintList(Li);
	printf("MakeListPreOrder :\n");
	Li2 = MakeListPreorder(P);
	PrintList(Li2);
	printf("MakeListLevel :\n");
	Li3 = MakeListLevel(P,3);
	PrintList(Li3);
}
