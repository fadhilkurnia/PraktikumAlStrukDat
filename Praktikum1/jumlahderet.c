// 	==================================================================
// 	Nama file	: jumlahderet.c
//	Nama		: Fadhil Imam Kurnia
//	NIM			: 13515146
//	Deskripsi	: 	Praktikum 1 AlStrukDat
//					Soal 5: menjumlahkan jumlah angka dari 1 sampai N
// 	==================================================================

#include <stdio.h>

int main(){
	//KAMUS
		int N,i;
		int temp=0;
		
	//ALGORITMA
		scanf("%d",&N);
		for(i=1;i<=N;i++){
			temp+=i;
		}
		printf("%d\n",temp);
		return 0;
}
