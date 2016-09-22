/*
 * Nama	: Fadhil Imam Kurnia
 * NIM	: 13515146
 * File	: nilaikelas.c
 * Desc	: Praktikum 4 Algoritma & Struktur Data
 */

#include <stdio.h>
#include "matriks.h"

void TulisNilaiX(MATRIKS M, indeks j, ElType X);
void TulisStatistikMhs (MATRIKS M, indeks i);
void TulisStatistikMK (MATRIKS M, indeks j);

int main(){
	MATRIKS MNilai;
	int m,n;
	indeks i,j;
	
	scanf("%d",&n); /*banyak mahasiswa*/
	scanf("%d",&m); /*banyak matkul*/
	
	MakeMATRIKS(n,m,&MNilai);
	
	BacaMATRIKS(&MNilai,n,m);
	
	printf("STATISTIK PER MAHASISWA\n");
	for(i = GetFirstIdxBrs(MNilai); i <= n; i++){
		TulisStatistikMhs(MNilai,i);
		printf("\n");
	}
	
	printf("STATISTIK PER MATA KULIAH\n");
	for(j = GetFirstIdxKol(MNilai); j <= m; j++){
		TulisStatistikMK(MNilai,j);
		printf("\n");
	}	
	return 0;
}

void TulisNilaiX(MATRIKS M, indeks j, ElType X){
	/*Kamus*/
	indeks i;
	int count =0;
	
	printf("[");
	for(i = GetFirstIdxBrs(M); i <=GetLastIdxBrs(M); i++){
		if(Elmt(M,i,j) == X){
			printf("%d",i);
			count++;
			if(count!=CountXKol(M,j,X))
				printf(",");
		}
	}
	printf("]");
}

void TulisStatistikMhs (MATRIKS M, indeks i){
	/*kamus*/
	ElType min,max;
	
	MaxMinBrs(M, i, &max, &min);
	printf("[%d] %.2f %d %d",i,RataBrs(M,i),max,min);
}

void TulisStatistikMK (MATRIKS M, indeks j){
	/*kamus*/
	ElType min,max;	
	
	MaxMinKol(M, j, &max, &min);
	printf("[%d] %.2f [%d %d ",j,RataKol(M,j),max, CountXKol(M,j,max));
	TulisNilaiX(M,j,max);
	printf("] [%d %d ", min, CountXKol(M,j,min));
	TulisNilaiX(M,j,min);
	printf("]");
}
