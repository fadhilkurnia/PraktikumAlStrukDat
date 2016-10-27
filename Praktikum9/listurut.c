#include "listdp.h"
#include <stdio.h>

address SearchPrec (List L, infotype X);
/* Mengirimkan address elemen sebelum elemen yang nilainya>=X */
/* Mencari apakah ada elemen list dengan Info(P)>=X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P dan Info(P)>=X pertama. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */

void InsertUrut (List *L, infotype X);
/* Menambahkan elemen pada list L tanpa mengganggu keterurutan L.
Manfaatkan fungsi SearchPrec. */
/* I.S. X terdefinisi. L terdefinisi, mungkin kosong.
Jika tidak kosong, L terurut membesar. */
/* F.S. X dialokasi. Jika alokasi berhasil, maka X dimasukkan sebagai salah
satu elemen L tanpa mengganggu keterurutan L. Insert elemen baru
dapat dilakukan di awal, di tengah, maupun di akhir.
Jika alokasi gagal, L tetap. */

infotype Max (List L);
/* Menghasilkan nilai terbesar dari elemen list L. L tidak kosong. */

infotype Min (List L);
/* Menghasilkan nilai terkecil dari elemen list L. L tidak kosong. */

float Average (List L);
/* Menghasilkan nilai rata-rata elemen L. L tidak kosong. */




int main(){
	int x;
	List L;
	CreateEmpty(&L);
	scanf("%d",&x);
	while(x!=-9999){
		InsertUrut(&L,x);
		scanf("%d",&x);
	}
	if(!IsEmpty(L)){
		printf("%d\n",Max(L));
		printf("%d\n",Min(L));
		printf("%.2f\n",Average(L));
		PrintForward(L);
		printf("\n");
	}
	PrintBackward(L);
	printf("\n");
	return 0;
}

address SearchPrec (List L, infotype X)
/* Mengirimkan address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan Info(P)>=X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P dan Info(P)>=X pertama. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
{
	address P = First(L);
	if(!IsEmpty(L)){
		if(Info(P)>=X){
			return Nil;
		}else{
			while(Next(P)!=Nil && Info(Next(P))<X){
				P=Next(P);
			}
			return P;
		}
	}else
		return Nil;
}

void InsertUrut (List *L, infotype X)
/* Menambahkan elemen pada list L tanpa mengganggu keterurutan L.
Manfaatkan fungsi SearchPrec. */
/* I.S. X terdefinisi. L terdefinisi, mungkin kosong.
Jika tidak kosong, L terurut membesar. */
/* F.S. X dialokasi. Jika alokasi berhasil, maka X dimasukkan sebagai salah
satu elemen L tanpa mengganggu keterurutan L. Insert elemen baru
dapat dilakukan di awal, di tengah, maupun di akhir.
Jika alokasi gagal, L tetap. */
{
	address P = Alokasi(X),Q;
	if(P!=Nil){
		Q = SearchPrec(*L,X);
		if(Q!=Nil)
			InsertAfter(&(*L),P,Q);
		else
			InsertFirst(&(*L),P);
	}
}

infotype Max (List L)
/* Menghasilkan nilai terbesar dari elemen list L. L tidak kosong. */
{
	return Info(Last(L));
}

infotype Min (List L)
/* Menghasilkan nilai terkecil dari elemen list L. L tidak kosong. */
{
	return Info(First(L));
}

float Average (List L)/* Menghasilkan nilai rata-rata elemen L. L tidak kosong. */
{
	address P = First(L);
	int count = 0;
	infotype sum = 0;
	while(P!=Nil){
		sum+=Info(P);
		count++;
		P = Next(P);
	}
	return (float) sum / (float) count;
}
