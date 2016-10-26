/* File : listdp.c */
/* ADT List dengan Double Pointer */
/* Representasi berkait dengan address adalah pointer */
/* infotype adalah integer */

/* Definisi list : */
/* List kosong : First(L) = Nil dan Last(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P), Prev(P) */
/* Elemen terakhir list: Last(L) */

#include "listdp.h"
#include <stdlib.h>
#include <stdio.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
{
	return (First(L) == Nil)&&(Last(L)== Nil);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
{
	First(*L) = Last(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
{
	address P;
	P = (address) malloc (sizeof(ElmtList));
	if (P == NULL){
		return Nil;
	}else{
		Info(P) = X;
		Next(P) = Prev(P)= Nil;
		return P;
	}	
}
void Dealokasi (address P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
	free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
	boolean found = false;
	address P = First(L);
	if(!IsEmpty(L)){
		while(P != Nil && !found){
			if(Info(P)==X){
				found = true;
			}else{
				P = Next(P);
			}
		}
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
			First(*L) = Last(*L) = P;
		}else{				
			Next(P) = First(*L);
			Prev(First(*L)) = P;
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
			First(*L) = Last(*L) = P;
		}else{					// For not empty list
			T = Last(*L);
			Next(T) = P;
			Prev(P) = T;
			Last(*L) = P;
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
	Dealokasi(First(*L));
	First(*L) = P;
	if(P==Nil)
		Last(*L)=Nil;
	else
		Prev(P)=Nil;
}

void DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
	*X = Info(Last(*L));
	address P = Prev(Last(*L));
	Dealokasi(Last(*L));
	Last(*L) = P;
	if(P==Nil)
		First(*L)=Nil;
	else
		Next(P)=Nil;
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
	if(!IsEmpty(*L))
		Prev(First(*L)) = P;
	Next(P) = First(*L);	
	First(*L) = P;
	if(Last(*L)==Nil)
		Last(*L) = P;
}
void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
	if(!IsEmpty(*L))
		Next(Last(*L)) = P;
	Prev(P) = Last(*L);	
	Last(*L) = P;
	if(First(*L)==Nil)
		First(*L) = P;
}
void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
	Next(P) = Next(Prec);
	if(Next(Prec)!=Nil)
		Prev(Next(Prec)) = P;
	else
		Last(*L) = P;
	Next(Prec) = P;
	Prev(P) = Prec;
}
void InsertBefore (List *L, address P, address Succ)
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */
{
	Prev(P) = Prev(Succ);
	if(Prev(Succ)!=Nil)
		Next(Prev(Succ)) = P;
	else
		First(*L) = P;
	Prev(Succ) = P;
	Next(P) = Succ;
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
	(*P) = First(*L);
	if(First(*L)==Last(*L))
		First(*L) = Last(*L) = Nil;
	else{
		First(*L) = Next(First(*L));
		Prev(First(*L)) = Nil;
	}
}
void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
{
	(*P) = Last(*L);
	if(First(*L)==Last(*L))
		First(*L) = Last(*L) = Nil;
	else{
		Last(*L) = Prev(Last(*L));
		Next(Last(*L)) = Nil;
	}
}

void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
	address P = Search(*L,X),Q = First(*L);
	if (P!=Nil){	// If P is in list
		// searching for element before P
		while(Next(Q)!=P && Q!=P){
			Q = Next(Q);
		}
		if(Q==P){ // P is first elmt
			DelFirst(&(*L),&Q);
		}else{
			P = Q;
			DelAfter(&(*L),&Q,P);
		}
		Dealokasi(Q);
	}
}
void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
	if(Next(Next(Prec))!=Nil){ //Pdel is not last element
		(*Pdel) = Next(Prec);
		Prev(Next(*Pdel)) = Prec;
		Next(Prec) = Next(*Pdel);
	}else{
		DelLast(&(*L),&(*Pdel));
	}
}
void DelBefore (List *L, address *Pdel, address Succ)
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
	if(Prev(Prev(Succ))!=Nil){ //Pdel is not first element
		(*Pdel) = Prev(Succ);
		Next(Prev(*Pdel)) = Succ;
		Prev(Succ) = Prev(*Pdel);
	}else{
		DelFirst(&(*L),&(*Pdel));
	}	
}

/****************** PROSES SEMUA  ELEMEN LIST ******************/
void PrintForward (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
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
void PrintBackward (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
	address P = Last(L);
	printf("[");
	if(!IsEmpty(L)){
		while(Prev(P)!=Nil){
			printf("%d,",Info(P));
			P = Prev(P);
		}
		printf("%d",Info(P));
	}
	printf("]");
}
