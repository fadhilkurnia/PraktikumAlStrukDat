#include "listrek.h"
#include "boolean.h"
#include <stdlib.h>
#include <stdio.h>
/* 
 * Alokasi
 * Mengirimkan address hasil alokasi sebuah elemen
 * Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P, 
   maka Info(P) = X, Next(P) = Nil
 * Jika alokasi gagal, mengirimkan Nil
 */
address Alokasi (infotype X) {
	address P = (address) malloc(sizeof(infotype));
	if (P != Nil) {
		Info(P) = X;
		Next(P) = Nil;
	}
	return P;
}	
/* 
 * Dealokasi
 * I.S. P terdefinisi
 * F.S. P dikembalikan ke sistem
 * Melakukan dealokasi/pengembalian address P
 */
void Dealokasi (address P) {
	free(P);
}
/* 
 * IsEmpty
 * Mengirimkan 1 jika L kosong dan 0 jika L tidak kosong
 */
int IsEmpty(List L) {
	return L == Nil;
}
/* 
 * IsOneElmt
 * Mengirimkan 1 jika L berisi 1 elemen dan 0 jika > 1 elemen atau kosong
 */
int IsOneElmt(List L) {
	if (!IsEmpty(L))
		return Next(L) == Nil;
	else
		return 0;
}
/* 
 * FirstElmt
 * Mengirimkan elemen pertama sebuah list L yang tidak kosong
 */
infotype FirstElmt (List L) {
	return Info(L);
}
/* 
 * Tail
 * Mengirimkan list L tanpa elemen pertamanya, mungkin menjadi list kosong
 */
List Tail(List L) {
	return Next(L);
}
/* 
 * Konso
 * Mengirimkan list L dengan tambahan e sebagai elemen pertamanya. 
 * e dialokasi terlebih dahulu. Jika alokasi gagal, mengirimkan L.
 */
List Konso(infotype e, List L) {
	address P = Alokasi(e);
	if (P == Nil)
		return L;
	else {
		Next(P) = L;
		return P;
	}
}
/* 
 * KonsB
 * Mengirimkan list L dengan tambahan e sebagai elemen pertamanya
 * e harus dialokasi terlebih dahulu
 * Jika alokasi e gagal, mengirimkan L
 */ 
List KonsB(List L, infotype e) {
	address P = Alokasi(e);
	if (P != Nil) {
		if (IsEmpty(L))
			return P;
		else {
			address i = L;
			address last = Nil;
			while (i != Nil) {
				last = i;
				i = Next(i);
			}
			Next(last) = P;
		}
	}
	return L;
}
/* 
 * Copy
 * Mengirimkan salinan list L (menjadi list baru)
 * Jika ada alokasi gagal, mengirimkan L
 */ 
List Copy (List L) {
	if (IsEmpty(L))
		return Nil;
	else
		return Konso(Info(L), Tail(L));
}
/* 
 * MCopy
 * I.S. Lin terdefinisi
 * F.S. Lout berisi salinan dari Lin
 * Proses : menyalin Lin ke Lout
 */
void MCopy (List Lin, List *Lout) {
	List cp = Copy(Lin);
	*Lout = cp;
}
/* 
 * Concat
 * Mengirimkan salinan hasil konkatenasi list L1 dan L2 (menjadi list baru)
 * Jika ada alokasi gagal, menghasilkan Nil
 */
List Concat (List L1, List L2) {
	if (IsEmpty(L2))
		return L1;
	else if (IsEmpty(L1))
		return L2;
	else
		return Concat(KonsB(L1, Info(L2)), Tail(L2));
}
/* 
 * MConcat
 * I.S. L1, L2 terdefinisi
 * F.S. LHsl adalah hasil melakukan konkatenasi L1 dan L2 dengan cara "disalin"
 * Proses : Menghasilkan salinan hasil konkatenasi list L1 dan L2
 */
void MConcat (List L1, List L2, List *LHsl) {
	*LHsl = Concat(L1,L2);
}
/* 
 * PrintList
 * I.S. L terdefinisi.
 * F.S. Setiap elemen list dicetak.
 */
void PrintList (List L) {
	if (!IsEmpty(L)) {
		printf("%d\n", FirstElmt(L));
		PrintList(Tail(L));
	}
}
/* 
 * NbElmtList
 * Mengirimkan banyaknya elemen list L, Nol jika L kosong
 */
int NbElmtList (List L) {
	if (IsEmpty(L))
		return 0;
	else
		return 1 + NbElmtList(Tail(L));
}
/* 
 * Search
 * Mengirim true jika X adalah anggota list, false jika tidak
 */
boolean Search (List L, infotype X) {
	if (IsEmpty(L))
		return false;
	else if (Info(L) == X)
		return true;
	else
		return Search(Tail(L), X);
}
/* 
 * Inverse
 * Mengirimkan list baru, hasil invers dari L dengan menyalin semua elemen list.
   Semua elemen list baru harus dialokasi
 * Jika alokasi gagal, hasilnya list kosong
 */
List InverseList (List L) {
	if (L == Nil)
		return Nil;
	else
		return KonsB(InverseList(Tail(L)), FirstElmt(L));
}
/* 
 * SplitPosNeg
 * I.S. L mungkin kosong
 * F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2
 * L1 berisi semua elemen L yang positif atau 0, sedangkan L2 berisi
   semua elemen L yang negatif; semua dengan urutan yang sama seperti di L
 * L tidak berubah: Semua elemen L1 dan L2 harus dialokasi
 * Jika L kosong, maka L1 dan L2 kosong
 */
void SplitPosNeg (List L, List *L1, List *L2) {
	if (L != Nil) {
		if (FirstElmt(L) >= 0)
			*L1 = KonsB(*L1, FirstElmt(L));
		else
			*L2 = KonsB(*L2, FirstElmt(L));
		SplitPosNeg(Tail(L), L1, L2);
	}
}
/* 
 * SplitOnX
 * I.S. L dan X terdefinisi, L1 dan L2 sembarang.
 * F.S. L1 berisi semua elemen L yang lebih kecil dari X, dengan urutan
   kemunculan yang sama, L2 berisi semua elemen L yang tidak masuk ke
   L1, dengan urutan kemunculan yang sama.
 */
void SplitOnX (List L, infotype X, List *L1, List *L2) {
	if (L != Nil) {
		if (FirstElmt(L) < X)
			*L1 = KonsB(*L1, FirstElmt(L));
		else
			*L2 = KonsB(*L2, FirstElmt(L));
		SplitOnX(Tail(L), X, L1, L2);
	}
}
/* 
 * ListCompare
 * Menghasilkan: -1 jika L1 < L2, 0 jika L1 = L2, dan 1 jika L1 > L2
 * Jika L[i] adalah elemen L pada urutan ke-i dan |L| adalah panjang L:
 * L1 = L2: |L1| = |L2| dan untuk semua i, L1[i] = L2[i]
 * L1 < L2: Jika i adalah urutan elemen yang berbeda yang terkecil
   dari L1 dan L2, L1[i] < L2[i] atau: Jika pada semua elemen pada
   urutan i yang sama, L1[i]=L2[i], namun |L1| < |L2|
 * Contoh: [3,5,6,7] < [4,4,5,6]; [1,2,3] < [1,2,3,4]
 * L1 > L2: kebalikan dari L1 < L2
 */
int ListCompare (List L1, List L2) {
	if (L1 == Nil && L2 == Nil)
		return 0;
	else if (L1 == Nil)
		return -1;
	else if (L2 == Nil)
		return 1;
	else if (FirstElmt(L1) < FirstElmt(L2))
		return -1;
	else if (FirstElmt(L1) == FirstElmt(L2))
		return ListCompare(Tail(L1), Tail(L2));
	else
		return 1;
}
/* 
 * IsAllExist
 * Menghasilkan true jika semua elemen dalam L1 terdapat dalam L2
 * (tanpa memperhatikan urutan ataupun banyaknya elemen).
 * Kedua list mungkin kosong. Jika L1 kosong, maka hasilnya false.
 */
boolean IsAllExist (List L1, List L2) {
	if (L1 == Nil)
		return true;
	else
		return Search(L2, FirstElmt(L1)) && IsAllExist(Tail(L1), L2);
}
/* 
 * Max
 * Mengirimkan nilai info(P) yang maksimum
 * Prekondisi untuk Max/Min/Sum/Average : List tidak kosong
 */
infotype MaxList (List L) {
	if (IsOneElmt(L))
		return FirstElmt(L);
	else {
		infotype x = MaxList(Tail(L));
		if (x > FirstElmt(L))
			return x;
		else
			return FirstElmt(L);
	}
}
/* 
 * Min
 * Mengirimkan nilai info(P) yang minimum
 * Prekondisi untuk Max/Min/Sum/Average : List tidak kosong
 */
infotype MinList (List L) {
	if (IsOneElmt(L))
		return FirstElmt(L);
	else {
		infotype x = MinList(Tail(L));
		if (x < FirstElmt(L))
			return x;
		else
			return FirstElmt(L);
	}
}
/* 
 * SumList
 * Mengirimkan total jumlah elemen List L
 * Prekondisi untuk Max/Min/Sum/Average : List tidak kosong
 */
infotype SumList (List L) {
	if (L == Nil)
		return 0;
	else
		return FirstElmt(L) + SumList(Tail(L));
}
/* 
 * Average
 * Mengirimkan nilai rata-rata elemen list L
 * Prekondisi untuk Max/Min/Sum/Average : List tidak kosong
 */
float AverageList (List L) {
	return (float) SumList(L)/ (float) NbElmtList(L);
}
