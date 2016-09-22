/*
 * Nama : Fadhil Imam Kurnia - 13515146
 * File : marray.c
 * Ket	: Praktikum 3
 * 
 * */

#include <stdio.h>
#include "array.h"

int main(){
	TabInt T;
	int i,count, IdxMed;
	ElType X;
	
	MakeEmpty(&T);
	BacaIsi(&T);
	scanf("%d",&X);
	TulisIsiTab(T);
	/*tulis jumlah*/
	count=0;
	for(i=GetFirstIdx(T); i<=GetLastIdx(T); i++){
		if(Elmt(T,i)==X){
			count++;
		}
	}
	printf("\n%d",count);
		
	/*indeks pertama*/
	if(SearchB(T,X)){
		printf("\n%d\n",Search1(T,X));
		if(ValMax(T)==X){
			printf("maksimum\n");
		}
		if(ValMin(T)==X){
			printf("minimum\n");
		}
		if(NbElmt(T)%2==0){
			IdxMed = NbElmt(T)/2;
		}else{
			IdxMed = NbElmt(T)/2;
			IdxMed++;
		}
		InsSortAsc(&T);
		if(Elmt(T,IdxMed)==X){
			printf("median\n");
		}
	}else{
		printf("\n%d tidak ada\n",X);
	}
	
	
	return 0;
}
