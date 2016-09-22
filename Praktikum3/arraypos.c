/* MODUL TABEL INTEGER DENGAN ELEMEN POSITIF */
/* Berisi definisi dan semua primitif pemrosesan tabel integer dengan elemen positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori tabel statik */
/*
 * Nama : Fadhil Imam Kurnia - 13515146
 * File : arraypos.c
 * Ket	: Praktikum 3
 * 
 * */
#include "boolean.h"
#include "arraypos.h"
#include <stdio.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty (TabInt * T)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
/* Proses: Inisialisasi semua elemen tabel T dengan ValUndef */
{
	int i;
	for(i=IdxMin; i <= IdxMax; i++){
		Elmt(*T,i)=ValUndef;
	}
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{
	int count=0;
	IdxType i = IdxMin;
	while(Elmt(T,i)!=ValUndef){
		count++;
	}
	
	return count;
}

/* *** Daya tampung container *** */
int MaxNbEl (TabInt T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
	return (IdxMax-IdxMin+1);
}

/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
{
	return IdxMin;
}

IdxType GetLastIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
	IdxType i = IdxMin;
	while(Elmt(T,i)!=ValUndef && i<IdxMax){
		i++;
	}
	i = i-1;
	return i;
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
	return ( i >= IdxMin && i <=IdxMax);
}

boolean IsIdxEff (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
	return ( i >= GetFirstIdx(T) && i <=GetLastIdx(T));
}


/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
	return (Elmt(T, IdxMin) == ValUndef);
}

/* *** Test tabel penuh *** */
boolean IsFull (TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
	return (Elmt(T, IdxMax) != ValUndef);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi (TabInt * T)
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxNbEl(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxNbEl(T){} Lakukan N kali: Baca elemen mulai dari indeks 
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0{} hanya terbentuk T kosong */
{
	IdxType N,i;
	ElType X;
	do{
		scanf("%d",&N);
	}while( N < 0 || N > MaxNbEl(*T) );
	MakeEmpty(&(*T));
	i = IdxMin;
	while(N>0 && i <= N){
		scanf("%d",&X);
		Elmt(*T,i)=X;

		i++;
	}
}

void TulisIsiTab (TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku{} 
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
{
	IdxType i;

	if (IsEmpty(T)) {
		printf("[]");
	}else{
		printf("[%d",Elmt(T,GetFirstIdx(T)));
		for (i = GetFirstIdx(T)+1; i <= GetLastIdx(T); i++) {
			printf(",%d", Elmt(T,i));
		}
		printf("]");
	}
}


/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusMinusTab (TabInt T1, TabInt T2, boolean plus)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
{
	TabInt T;
	int i;
	MakeEmpty(&T);
	
	if(plus){
		for (i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++) {
			Elmt(T,i) = Elmt(T1,i) + Elmt(T2,i);
		}
	}else{
		for (i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++) {
			Elmt(T,i) = Elmt(T1,i) - Elmt(T2,i);
		}
	}
	return T;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ (TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika ukuran T1 = T2 dan semua elemennya sama */
{
	if (IsEmpty(T1) && IsEmpty(T2)){
		return true;
	}else if (NbElmt(T1) == NbElmt(T2)) {
		IdxType i = IdxMin;
		boolean sama = true;
		for(i= IdxMin; i <=IdxMax; i++){
			sama = (Elmt(T1,i) == Elmt(T2,1))&&(sama);
		}
		return sama;
	} else{
		return false;
	}	
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1 (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */
{
	if(!IsEmpty(T)){
		int i = GetFirstIdx(T);
		while ((i<=GetLastIdx(T))&&(Elmt(T,i)!=X)) {
			i++;
		}
		if (i>GetLastIdx(T)) {
			return IdxUndef;
		}else{
			return i;
		}
	}else{
		return IdxUndef;
	}
}


boolean SearchB (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */
{
  /*KAMUS*/
  int i = GetFirstIdx(T);
  boolean Found = false;
  /*ALGORTIMA*/
  if (!IsEmpty(T)) {
    /* Jika tabel T tidak kosong - hati hati jangan mengecek hingga keluar LastIdx*/
    Found = (Elmt(T,GetFirstIdx(T))==X);
    while ((i<GetLastIdx(T))&&(!Found)) {
      i++;
      Found = (Elmt(T,i)==X);
    }
    return Found;
  }else{
    /* Jika tabel T kosong*/
    return false;
  }
}

/* ********** NILAI EKSTREM ********** */
void MaxMin (TabInt T, ElType * Max, ElType * Min)
/* I.S. Tabel T tidak kosong */
/* F.S. Max berisi nilai maksimum T{}
        Min berisi nilai minimum T */
{
  int i;
  *Max = Elmt(T, GetFirstIdx(T)); /*inisialisasi*/
  for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++) {
    if (Elmt(T,i)>=*Max) {
      *Max = Elmt(T,i);
    }
  }
  
  *Min = Elmt(T, GetFirstIdx(T)); /*inisialisasi*/
  for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++) {
    if (Elmt(T,i)<=*Min) {
      *Min = Elmt(T,i);
    }
  }
}

/* ********** OPERASI LAIN ********** */
ElType SumTab (TabInt T)
/* Menghasilkan hasil penjumlahan semua elemen T */
/* Jika T kosong menghasilkan 0 */
{
	if(!IsEmpty(T)){
		IdxType i;
		int count = 0;
		for(i = GetFirstIdx(T); i<=GetLastIdx(T);i++){
			count += Elmt(T,i);
		}
	}else{
		return 0;
	}
}
int CountX (TabInt T, ElType X)
/* Menghasilkan berapa banyak kemunculan X di T */
/* Jika T kosong menghasilkan 0 */
{
	if(!IsEmpty(T)){
		IdxType i;
		int count = 0;
		for(i = GetFirstIdx(T); i<=GetLastIdx(T);i++){
			if(Elmt(T,i)==X){
				count++;
			}
		}
		return count;	
	}else{
		return 0;
	}
}

boolean IsAllGenap (TabInt T)
/* Menghailkan true jika semua elemen T genap */
{
	if(!IsEmpty(T)){
		boolean genap = true; /*inisialisai*/
		IdxType i = GetFirstIdx(T);
		while( genap && i<=GetLastIdx(T) ){
			genap = (Elmt(T,i)%2==0);
			i++;
		}
		return genap;		
	}else{
		return false;
	}
}


/* ********** SORTING ********** */
void Sort (TabInt * T, boolean asc)
/* I.S. T boleh kosong */
/* F.S. Jika asc = true, T terurut membesar */
/*      Jika asc = false, T terurut mengecil */
/* Proses : Mengurutkan T dengan salah satu algoritma sorting,
   algoritma bebas */
{
	if(!IsEmpty(*T)){
		/*tidak kosong*/
		
		if(asc){
		  int i,ix;
		  ElType temp, temp2;
		  if (!IsEmpty(*T)) {
			for (i = GetFirstIdx(*T)+1; i <= GetLastIdx(*T); i++) {
			  temp = Elmt(*T, i);
			  ix = i-1;
			  while ((ix>=GetFirstIdx(*T))&&(Elmt(*T,ix)>temp)) {
				Elmt(*T,(ix+1))=Elmt(*T,ix);
				ix--;
			  }
			  Elmt(*T,(ix+1))=temp;
			}
		  }
		}else{
			ElType temp,max;
			IdxType i,imax;
				
			i = GetFirstIdx(*T);
			while (i<GetLastIdx(*T)) {
			  max = Elmt(*T,i);
			  for (imax = i; imax <= GetLastIdx(*T); imax++) {
				if (Elmt(*T,imax)>max) {
				  max = Elmt(*T, imax);
				}
			  }

			  imax = Search1(*T, max);

			  /*tukar elemen*/
			  temp = Elmt(*T, imax);
			  Elmt(*T, imax) = (Elmt(*T,i));
			  Elmt(*T,i) = temp;

			  i++;
			}
		}
		
	}
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl (TabInt * T, ElType X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
	if(!IsFull(*T)){
		if(!IsEmpty(*T)){
			Elmt(*T, GetLastIdx(*T)+1) = X;
		}else{
			Elmt(*T, IdxMin) = X;
		}
	}
}

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl (TabInt * T, ElType * X)
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{
	Elmt(*T, GetLastIdx(*T))= ValUndef;
}
