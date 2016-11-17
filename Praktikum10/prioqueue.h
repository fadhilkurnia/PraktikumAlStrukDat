/* File : prioqueue.h */
/* Representasi priority queue dengan list berkait dengan first (HEAD) sebagai alamat penghapusan elemen */
/* Queue terurut mengecil berdasarkan elemen nMat (nilai matematika) */
/* Jika nMat sama, diurutkan membesar berdasarkan tKedatangan (waktu kedatangan) */
#ifndef _PRIOQUEUE_H
#define _PRIOQUEUE_H
#include "boolean.h"
#include <stdlib.h>

/* Konstanta */
#define Nil NULL

/* Deklarasi infotype */
typedef struct {
	int id;          /* id siswa */
	int tKedatangan; /* waktu kedatangan */
	int nMat;        /* nilai matematika */
	int dLayanan;    /* durasi/lama persiapan makanan untuk siswa */
} infotype;

/* Queue dengan representasi berkait dengan pointer */
typedef struct tElmtQueue * address;
typedef struct tElmtQueue { 
	infotype Info;
	address Next; 
} ElmtQueue; 

/* Type queue dengan ciri HEAD : */
typedef struct { 
	address HEAD;  /* alamat penghapusan */
} PrioQueue;

/* Selektor */
#define Head(Q) (Q).HEAD
#define InfoHead(Q) (Q).HEAD->Info
#define Next(P) (P)->Next
#define Info(P) (P)->Info

/* Prototype manajemen memori */
void Alokasi (address *P, infotype X);
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan Next(P)=Nil */
/*      P=Nil jika alokasi gagal */
void Dealokasi (address  P);
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
boolean IsEmpty (PrioQueue Q);
/* Mengirim true jika Q kosong: HEAD(Q)=Nil */
int NbElmt(PrioQueue Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
/*** Kreator ***/
void CreateEmpty(PrioQueue * Q);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */
/*** Primitif Add/Delete ***/
void Add (PrioQueue * Q, infotype X);
/* Proses: Mengalokasi X dan menambahkan X sesuai aturan priority queue
   jika alokasi berhasil; jika alokasi gagal Q tetap */
/* I.S. Q mungkin kosong */
void Del(PrioQueue * Q, infotype * X);
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */

#endif
