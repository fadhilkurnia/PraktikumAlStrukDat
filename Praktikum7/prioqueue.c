/* File : prioqueue.h */
/* Definisi ADT Priority Queue dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */
/* Elemen queue terurut mengecil berdasarkan elemen prio */

#include <stdlib.h>
#include "boolean.h"
#include "prioqueue.h"
#include <stdio.h>


/* ********* Prototype ********* */
boolean IsEmpty (Queue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
	return (Head(Q)==Nil && Tail(Q)==Nil);
}
boolean IsFull (Queue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
{
	return (NBElmt(Q)==MaxEl(Q));
}

int NBElmt (Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
{
	if (IsEmpty(Q))
		return 0;
	else
		return (Tail(Q) - Head(Q) + MaxEl(Q)) % MaxEl(Q) + 1;
}

/* *** Kreator *** */
void CreateEmpty (Queue * Q, int Max)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
{
  (*Q).T = (infotype *) malloc ((Max+1)*sizeof(infotype));
  if ((*Q).T == NULL) {
    (*Q).MaxEl = 0;
  }else{
    MaxEl(*Q) = Max;
  }
  Head(*Q) = Nil;
  Tail(*Q) = Nil;
}

/* *** Destruktor *** */
void DeAlokasi(Queue * Q)
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
{
  free((*Q).T);
  MaxEl(*Q) = 0;
  Head(*Q) = Nil;
  Tail(*Q) = Nil;
}


/* *** Primitif Add/Delete *** */
void Add (Queue * Q, infotype X)
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer;
        elemen baru disisipkan pada posisi yang tepat sesuai dengan prioritas */
{

	address i,j;
 	if (IsEmpty(*Q)){
		Q->HEAD = Q->TAIL =i=1;
	}else{
		i = Tail(*Q);
		Q->TAIL = j = i % MaxEl(*Q) + 1;
		while( i != Head(*Q) && Prio(Elmt(*Q,i)) > Prio(X) ){
			Elmt(*Q,j) = Elmt(*Q,i);
			i = i-1 == 0 ? MaxEl(*Q) : i-1 ;
			j = i % MaxEl(*Q) + 1;
		}
		// if for handling if while loop until Head(*Q)
		if ( Prio(Elmt(*Q,i)) > Prio(X) )
			Elmt(*Q,j) = Elmt(*Q,i);
		else
			i = j;
	}
	Elmt(*Q,i) = X;
}


void Del (Queue * Q, infotype * X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
{

  *X = InfoHead(*Q);
  if(Head(*Q)==Tail(*Q)){
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
  }else{
    Head(*Q) = Head(*Q) % MaxEl(*Q) + 1;
  }

}


/* Operasi Tambahan */
void PrintQueue (Queue Q)
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/
{

	infotype X;
	while(!IsEmpty(Q)){
		Del(&Q,&X);
		printf("%d %d\n", Prio(X),  Info(X));
	}
	printf("#\n");

}
