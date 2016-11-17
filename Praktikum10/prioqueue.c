/* File : prioqueue.c */
/* Representasi priority queue dengan list berkait dengan first (HEAD) sebagai alamat penghapusan elemen */
/* Queue terurut mengecil berdasarkan elemen nMat (nilai matematika) */
/* Jika nMat sama, diurutkan membesar berdasarkan tKedatangan (waktu kedatangan) */

#include "prioqueue.h"
#include "boolean.h"

/* Prototype manajemen memori */
void Alokasi (address *P, infotype X)
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan Next(P)=Nil */
/*      P=Nil jika alokasi gagal */
{
	*P = (address) malloc (sizeof(address));
	if(P != NULL){
		Info(*P) = X;
		Next(*P) = Nil;
	}else{
		*P = Nil;
	}
}

void Dealokasi (address  P)
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
{
	free(P);
}

boolean IsEmpty (PrioQueue Q)
/* Mengirim true jika Q kosong: HEAD(Q)=Nil */
{
	return Head(Q) == Nil;
}

int NbElmt(PrioQueue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
{
	int count = 0;
	address P = Head(Q);

	if (IsEmpty(Q)) {
		return count;
	}else{
		while(P!=Nil)
			count++;
		return count;
	}
}

/*** Kreator ***/
void CreateEmpty(PrioQueue * Q)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */
{
	Head(*Q) = Nil;
}
/*** Primitif Add/Delete ***/
void Add (PrioQueue * Q, infotype X)
/* Proses: Mengalokasi X dan menambahkan X sesuai aturan priority queue
   jika alokasi berhasil; jika alokasi gagal Q tetap */
/* I.S. Q mungkin kosong */
{
	address P,K;
	Alokasi(&P,X);
	if(P!=Nil){
		if(IsEmpty(*Q))
			Head(*Q) = P;
		else{
			K = Head(*Q);
			if(Next(K)==Nil){
				if(Info(K).nMat>=X.nMat)
					Next(K) = P;
				else{
					Next(P) = K;
					Head(*Q) = P;
				}
			}else{
				// KALO 2 ELEMENT ATAU LEBIH
				if(Info(K).nMat < X.nMat){
					Next(P) = K;
					Head(*Q) = P;
				}else{
					while(Next(Next(K))!=Nil && Info(Next(K)).nMat>=X.nMat){
						K = Next(K);
					}
					if(Info(Next(K)).nMat>=X.nMat){
						K = Next(K);
						Next(P) = Next(K);
						Next(K) = P;
					}else{
						Next(P) = Next(K);
						Next(K) = P;
					}
				}
			}
		}
	}
}

void Del(PrioQueue * Q, infotype * X)
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */
{
	*X = InfoHead(*Q);
	Head(*Q) = Next(Head(*Q));
}
