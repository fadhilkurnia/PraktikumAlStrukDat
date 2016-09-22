#include "jam.h"
#include <stdio.h>

int main(){
	int N,i;
	JAM j1,j2,Jawal,Jakhir;
	
	
	scanf("%d",&N);
	
	printf("[1]\n");
	BacaJAM(&j1);
	BacaJAM(&j2);
	//inisialisasi
	Jawal = j1; Jakhir =j1;
	
	if(JLT(j1,Jawal)){
		Jawal = j1;
	}else if(JLT(j2,Jawal)){
		Jawal = j2;
	}
	if(JGT(j1,Jakhir)){
		Jakhir = j1;
	}else if(JGT(j2,Jakhir)){
		Jakhir = j2;
	}
	if(JLT(j1,j2)){
		printf("%d\n",Durasi(j1,j2));
	}else{
		printf("%d\n",Durasi(j2,j1));
	}
	
	for(i=2;i<=N;i++){
		printf("[%d]\n",i);
		BacaJAM(&j1);
		BacaJAM(&j2);
		if(JLT(j1,Jawal)){
			Jawal = j1;
		}else if(JLT(j2,Jawal)){
			Jawal = j2;
		}
		if(JGT(j1,Jakhir)){
			Jakhir = j1;
		}else if(JGT(j2,Jakhir)){
			Jakhir = j2;
		}
		if(JLT(j1,j2)){
			printf("%d\n",Durasi(j1,j2));
		}else{
			printf("%d\n",Durasi(j2,j1));
		}
	}
	
	TulisJAM(Jawal);
	printf("\n");
	TulisJAM(Jakhir);
	printf("\n");
	
	return 0;
}
