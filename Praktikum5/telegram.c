/* Praktikum 5
 * Nama : Fadhil Imam Kurnia
 * NIM	: 13515146
 * File	: telegram.c
 * */


#include <stdio.h>
#include "mesinkar.h"
#include "mesinkata.h"
#include "boolean.h"

boolean IsKataSama (Kata K1, Kata K2);
void CetakKata(Kata K);

int main(){
	Kata Titik,Koma;
	Titik.TabKata[1] = 'T';
	Titik.TabKata[2] = 'I';
	Titik.TabKata[3] = 'T';
	Titik.TabKata[4] = 'I';
	Titik.TabKata[5] = 'K';
	Titik.TabKata[6] = '\0';
	Titik.Length = 5;
	Koma.TabKata[1] = 'K';
	Koma.TabKata[2] = 'O';
	Koma.TabKata[3] = 'M';
	Koma.TabKata[4] = 'A';
	Koma.TabKata[5] = '\0';
	Koma.Length = 4;
	int CountReguler =0, CountPanjang =0, CountKata =0;
	int harga;

	STARTKATA();
	while(!EndKata){
		CountKata++;
		if(IsKataSama(CKata,Titik)){
			printf(".");
		}else if(IsKataSama(CKata,Koma)){
			printf(",");
		}else{
			if (CountKata==1){
				CetakKata(CKata);
			}else{
				printf(" ");
				CetakKata(CKata);
			}

			if(CKata.Length<10)
				CountReguler++;
			else
				CountPanjang++;

		}
		ADVKATA();
	}

	printf("\n%d\n%d\n",CountReguler,CountPanjang);
	harga = (CountReguler*1000) + (CountPanjang*1500);
	if(CountKata>10){
		harga = harga*9/10;
	}
	printf("%d\n",harga);

	return 0;
}

boolean IsKataSama (Kata K1, Kata K2){
	int i = 1;
	boolean sama = true;

	if(K1.Length == K2.Length){
		while(sama && i<=K1.Length){
			if(K1.TabKata[i] != K2.TabKata[i])
				sama = false;
			else
				i++;
		}

		return sama;

	}else{
		return false;
	}
}

void CetakKata(Kata K){
	int i;
	for (i = 1; i <= K.Length; i++) {
		printf("%c", K.TabKata[i]);
	}
}
