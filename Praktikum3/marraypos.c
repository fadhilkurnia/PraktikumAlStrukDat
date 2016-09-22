/*
 * Nama : Fadhil Imam Kurnia - 13515146
 * File : arraypos.c
 * Ket	: Praktikum 3
 * 
 * */
 
 #include <stdio.h>
 #include "arraypos.h"
 
 int main(){
	TabInt T,T2;
	MakeEmpty(&T);
	BacaIsi(&T);
	TulisIsiTab(T);
	printf("\n-----------\n");
	BacaIsi(&T2);
	TulisIsiTab(T2);
	printf("\n-----------\n");
	printf("%d",IsEQ(T,T2));
	return 0;
 }
