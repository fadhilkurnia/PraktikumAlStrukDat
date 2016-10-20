/* 
 * NIM/Nama 	: 1351546 / Fadhil Imam Kurnia
 * Nama file 	: mlist.c
 * Topik 		: Linked List
 * Tanggal 		: 20 Oktober 2016
 * Deskripsi 	: Praktikum 8
 */
#include <stdio.h>
#include "listlinier.h"

void InverseList(List *L){
	if (!IsEmpty(*L) && NbElmt(*L)>1){
		int count = 1;
		int Y = NbElmt(*L);
		address X;
		address P = First(*L);
		address pre = Nil;
		while(count <= Y){
			X = Next(P);
			Next(P) = pre;
			pre = P;
			First(*L) = P;
			P = X;			
			count++;
		}
	}
}

int NbX(infotype X, List L){
	address P = First(L);
	int count = 0;
	while(P!=Nil){
		if(Info(P)==X)
			count++;
		P = Next(P);
	}
	return count;
}

int Jarak(List L, infotype X, infotype Y){
	address P = First(L);
	boolean isXFirst=false, isYFirst= false, start = false;
	int count = 0;
	while(P != Nil){
		if((Info(P)==X||Info(P)==Y)&&!isXFirst&&!isYFirst){
			start = true;
			if(Info(P)==X)
				isXFirst = true;
			else
				isYFirst = true;
		}else if(Info(P)==X&&!isXFirst){
			start = false;
		}else if(Info(P)==Y&&!isYFirst){
			start = false;
		}
		if (start)
			count++;
		P = Next(P);
	}
	return --count;
}

int main(){
	List L;
	address P;
	infotype X;
	CreateEmpty(&L);
	InsVFirst(&L,4);
	InsVFirst(&L,1);
	InsVFirst(&L,2);
	InsVFirst(&L,3);
	InsVFirst(&L,4);
	InsVFirst(&L,4);
	InsVFirst(&L,4);
	InsVFirst(&L,4);
	InsVFirst(&L,4);
	PrintInfo(L);
	printf("%d", Jarak(L,1,4));
	return 0;
}
