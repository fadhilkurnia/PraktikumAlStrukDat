/* File : listlinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* infotype adalah integer */

#include "listlinier.h"
#include <stdlib.h>
#include <stdio.h>

/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)=Nil */

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong */
{
	return First(L) == Nil;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
	First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
	address P;
	P = (address) malloc (sizeof(ElmtList));
	if (P == NULL){
		return Nil;
	}else{
		Info(P) = X;
		Next(P) = Nil;
		return P;
	}
}
void Dealokasi (address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
	free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
	boolean found = false;
	address P = First(L);
	if(!IsEmpty(L)){
		while(Next(P) != Nil && !found){
			if(Info(P)==X){
				found = true;
			}else{
				P = Next(P);
			}
		}
		// checking last element
		if(Info(P)==X)
			found = true;	
	}	
	return found? P : Nil;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
	address P = Alokasi(X);
	if (P!=NULL) {
		if(First(*L)==Nil){ // For empty list
			First(*L) = P;
		}else{				// For not empty list
			Next(P) = First(*L);
			First(*L) = P;
		}
	}
}

void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
	address P = Alokasi(X);
	address T;
	if (P != Nil){
		if (First(*L)==Nil){	// For empty list
			First(*L) = P;
		}else{					// For not empty list
			T = First(*L);
			while(Next(T)!=Nil){
				T = Next(T);
			} // T is last element
			Next(T) = P;
		}
	}
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
	*X = Info(First(*L));
	address P = Next(First(*L));
	Dealokasi(&First(*L));
	First(*L) = P;
}

void DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
	address P = First(*L);
	if(Next(P)==Nil){			// For list with one element
		*X = Info(First(*L));
		Dealokasi(&First(*L));
		First(*L) = Nil;
	}else{						// For list with more than one elements (min 2 elmts)
		while(Next(Next(P))!=Nil){
			P = Next(P);
		}// P is an element before last element
		*X = Info(Next(P));
		Dealokasi(&Next(P));
		Next(P) = Nil;
	}
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
	Next(P) = First(*L);
	First(*L) = P;
}

void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
	Next(P) = Next(Prec);
	Next(Prec) = P;
}

void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
	address D = First(*L);
	if (D == Nil){	// For empty list
		First(*L) = P;
	}else{			// For not empty list
		while(Next(D) != Nil){
			D = Next(D);
		} // D is last element
		Next(D) = P;
	}
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
	(*P) = First(*L);
	if(NbElmt(*L)==1)
		First(*L) = Nil;
	else
		First(*L) = Next(First(*L));
}
void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
	address P = Search(*L,X);
	if (P!=Nil){	// If P is in list
		// searching for element before P
		address T = First(*L);
		while(Next(T)!=P && T!=P){
			T = Next(T);
		}
		if(T==P){ // P is first elmt
			address Q = First(*L);
			First(*L) = Next(First(*L));
			Dealokasi(&Q);
		}else{
			address Q = Next(T);
			Next(T) = Next(Next(T));
			Dealokasi(&Q);
		}
	}
}

void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
{
	address Q = First(*L);
	if(NbElmt(*L)==1){			// For list with one element
		*P = Q;
		First(*L) = Nil;
	}else{						// For list with more than one elements (min 2 elmts)
		while(Next(Next(Q))!=Nil){
			Q = Next(Q);
		}// Q is an element before last element
		*P = Next(Q);
		Next(Q) = Nil;
	}
}



void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
	if(Next(Prec)==Nil){
		*Pdel = Nil;
	}else{
		*Pdel = Next(Prec);
		Next(Prec) = Next(Next(Prec));
	}
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
	address P = First(L);
	printf("[");
	if(!IsEmpty(L)){
		while(Next(P)!=Nil){
			printf("%d,",Info(P));
			P = Next(P);
		}
		printf("%d",Info(P));
	}
	printf("]");
}
int NbElmt (List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
	address P = First(L);
	int count = 0;
	if(!IsEmpty(L)){
		while(Next(P)!=Nil){
			count++;
			P = Next(P);
		}
		count++;
	}
	return count;
}

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L)
/* Mengirimkan nilai Info(P) yang maksimum */
{
	address P = First(L);
	infotype MAX;
	if(!IsEmpty(L)){
		MAX = Info(First(L));
		while(Next(P)!=Nil){
			if(Info(P)>MAX)
				MAX = Info(P);
			P = Next(P);
		}
		if(Info(P)>MAX)
			MAX = Info(P);
	}
	return MAX;
}

/****************** PROSES TERHADAP LIST ******************/
void Konkat1 (List *L1, List *L2, List *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
	CreateEmpty(&(*L3));
	if(!IsEmpty(*L1)){
		First(*L3) = First(*L1);
	}
	First(*L1) = Nil;
	if(!IsEmpty(*L3)){
		address P = First(*L3);
		while(Next(P) != Nil){
			P = Next(P);
		} // P is last element
		Next(P) = First(*L2);
	}else{
		First(*L3) = First(*L2);
	}
	First(*L2) = Nil;
}
