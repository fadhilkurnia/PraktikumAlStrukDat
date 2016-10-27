#include "listdp.h"
#include <stdio.h>

int NbX(infotype X, List L){
	int count = 0;
	address P = First(L);
	if(!IsEmpty(L)){
		while(P!=Nil){
			if(Info(P)==X)
				count++;
			P = Next(P);
		}
	}
	return count;
}

int Jarak(List L, infotype X, infotype Y){
	int jarak = 0;
	address P = First(L);
	boolean firstX = false, firstY = false;
	// tidak perlu menangani kasus kosong karena minimal ada X dan Y
	while(!firstX && !firstY){
		if(Info(P)==X)
			firstX = true;
		else if (Info(P)==Y)
			firstY = true;
		else
			P = Next(P);
	}
	if (firstX)
		while(Info(Next(P))!=Y){
			jarak++;
			P = Next(P);
		}
	else
		while(Info(Next(P))!=X){
			jarak++;
			P = Next(P);
		}
	return jarak;
}

int NbElmt(List L){
	int count = 0;
	address P = First(L);
	if(!IsEmpty(L)){
		while(P!=Nil){
			count++;
			P = Next(P);
		}
	}
	return count;
}

void InverseList(List *L){
	address P = First(*L),Q;
	int nb = NbElmt(*L);
	if(nb>1){
		while(P!=Nil){
			Q = Prev(P);
			Prev(P) = Next(P);
			Next(P) = Q;
			P = Prev(P);
		}
		Q = First(*L);
		First(*L) = Last(*L);
		Last(*L) = Q;
	}
}

void RemAllX(List *L, infotype X){
	address P = Search(*L,X);
	while(P!=Nil){
		DelP(&(*L),X);
		P = Search(*L,X);
	}
}

void MakeEmpty(List *L){
	address P;
	while(!IsEmpty(*L)){
		DelFirst(&(*L),&P);
		Dealokasi(P);
	}
}

void SubList(List L1, int start, int count, int arah, List * L2){
	address P = First(L1),Q;
	int i = 1;
	boolean fail = false, pass = false;
	CreateEmpty(&(*L2));
	pass = true;
	if(start > NbElmt(L1))
		pass = false;
	
	if(!IsEmpty(L1) && pass){
		if(arah==1){
			while(P!=Nil && i<=count+start-1 && !fail){
				if(i>=start){
					Q = Alokasi(Info(P));
					if(Q!=Nil){
						InsertLast(&(*L2),Q);
					}else
						fail = true;
				}
				i++;
				P = Next(P);
			}
		}else{
			while(P!=Nil && i<start+count-1){
				i++;
				P = Next(P);
			}// P adalah element ke-start+count-1
			while(P!=Nil && count>0 &&!fail){
				Q = Alokasi(Info(P));
				if(Q!=Nil){
					InsertLast(&(*L2),Q);
				}else
					fail = true;
				P = Prev(P);
			}
		}
	}
	
	if (fail)
		MakeEmpty(&(*L2));
}

int main(){
	List L,L2;
	CreateEmpty(&L);
	InsVLast(&L,1);
	InsVLast(&L,2);
	InsVLast(&L,3);
	InsVLast(&L,4);
	InsVLast(&L,5);
	InsVLast(&L,6);
	InsVLast(&L,7);
	InsVLast(&L,8);
	PrintForward(L);
	SubList(L,1,9,-1,&L2);
	PrintForward(L2);
	return 0;
}
