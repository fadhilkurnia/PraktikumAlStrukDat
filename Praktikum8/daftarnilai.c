#include "listlinier.h"
#include <stdio.h>

int main(){
	infotype X;
	List DN,CDN;
	CreateEmpty(&DN);
	CreateEmpty(&CDN);
	
	scanf("%d",&X);
	while(X>=0 && X<=100){
		InsVFirst(&DN,X);
		scanf("%d",&X);
	}
	if(NbElmt(DN)>0){
		printf("%d\n",NbElmt(DN));
		printf("%d\n",Max(DN));
		printf("%d\n",Min(DN));
		printf("%.2f\n",Average(DN));
		CDN = FCopyList(DN);
		InversList(&CDN);
		PrintInfo(CDN);
		printf("\n");
		PrintInfo(DN);
		printf("\n");
	}else{
		printf("Daftar nilai kosong\n");
	}
	
	return 0;
}
