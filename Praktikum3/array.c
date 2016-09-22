/* MODUL TABEL INTEGER */
/* Berisi definisi dan semua primitif pemrosesan tabel integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi I : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori tabel statik */
/* Nama : Fadhil Imam Kurnia - 13515146 */
/* File : array.c */

#include "array.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>



/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty (TabInt * T)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
{
  Neff(*T)=0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
{
  return Neff(T);
}

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
  return (IdxMin);
}

IdxType GetLastIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */
{
  return (NbElmt(T));
}


/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
  return ((i>=IdxMin)&&(i<=IdxMax));
}

boolean IsIdxEff (TabInt T, IdxType i)
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
  return ((i>=GetFirstIdx(T))&&(i<=GetLastIdx(T)));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
{
  return (Neff(T)==0);
}

boolean IsFull (TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
  return (NbElmt(T)==MaxNbEl(T));
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
  IdxType N;
  ElType x;
  int i;
  scanf("%d", &N);
  while (!IsIdxValid(*T,N)) {
    scanf("%d", &N);
  }
  for (i = GetFirstIdx(*T); i <= N; i++) {
    scanf("%d", &x);
    Elmt(*T, i) = x;
    Neff(*T)++;
  }
}

void BacaIsiTab (TabInt * T)
/* I.S. T sembarang */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca elemen T sampai dimasukkan nilai -9999 */
/* Dibaca elemen satu per satu dan disimpan mulai dari IdxMin */
/* Pembacaan dihentikan jika pengguna memasukkan nilai -9999 */
/* Jika dari pertama dimasukkan nilai -9999 maka terbentuk T kosong */
{
  ElType x;
  int i;

  i = GetFirstIdx(*T);
  scanf("%d", &x);

  if (x==(-9999)) {
    Neff(*T)=0;
  }

  while ((x!=(-9999))&&(!IsFull(*T))) {
    Elmt(*T,i) = x;
    Neff(*T)++;
    i++;
    scanf("%d", &x);
  }
}

void TulisIsi (TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/*      Jika T kosong : Hanya menulis "Tabel kosong" */
/* Contoh: Jika isi Tabel: [1, 20, 30, 50]
   Maka tercetak di layar:
   [1]1
   [2]20
   [3]30
   [4]50
*/
{
  int i;
  if (IsEmpty(T)) {
    printf("Tabel kosong\n");
  }else{
    for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++) {
      printf("[%d]%d\n", i, Elmt(T,i));
    }
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
TabInt PlusTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
{
  TabInt T;
  int i;

  MakeEmpty(&T);

  for (i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++) {
    Elmt(T,i) = Elmt(T1,i) + Elmt(T2,i);
  }
  Neff(T) = Neff(T1);
  return T;
}

TabInt MinusTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */
{
  TabInt T;
  int i;

  MakeEmpty(&T);
  for (i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++) {
    Elmt(T,i) = Elmt(T1,i) - Elmt(T2,i);
  }
  Neff(T) = Neff(T1);
  return T;
}

TabInt KaliTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 * T2 dengan definisi setiap elemen dengan indeks yang sama dikalikan */
{
  TabInt T;
  int i;
  for (i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++) {
    Elmt(T,i) = Elmt(T1,i) * Elmt(T2,i);
  }
  Neff(T) = Neff(T1);
  return T;
}

TabInt KaliKons (TabInt Tin, ElType c)
/* Prekondisi : Tin tidak kosong */
/* Mengirimkan tabel dengan setiap elemen Tin dikalikan c */
{
  TabInt T;
  int i;
  MakeEmpty(&T);
  for (i = GetFirstIdx(Tin); i <= GetLastIdx(Tin); i++) {
    Elmt(T,i) = Elmt(Tin,i) * c;
  }
  Neff(T) = Neff(Tin);
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
    IdxType i = GetFirstIdx(T1);
    while (i < GetLastIdx(T1) && Elmt(T1,i) == Elmt(T2,i)){
      i++;
    }

    if (i == GetLastIdx(T1)){
      return Elmt(T1,i) == Elmt(T2,i);
    }else{
      return false;
    }
  } else{
    return false;
  }
}

boolean IsLess (TabInt T1, TabInt T2)
/* Mengirimkan true jika T1 < T2, */
/* yaitu : sesuai dg analogi 'Ali' < Badu'{} maka [0, 1] < [2, 3] */
{
  if (IsEmpty(T1)&&IsEmpty(T2)) {
    return false;
  }else{
    if (IsEmpty(T1)) {
      return true;
    }else{
      if (IsEmpty(T2)) {
        return false;
      }else{
        int i = GetFirstIdx(T1);
        while ((i<=GetLastIdx(T1))&&(i<=GetLastIdx(T2))) {
          if (Elmt(T1,i)!=Elmt(T2,i)) {
            return (Elmt(T1,i)<Elmt(T2,i));
          }
          i++;
        }
        return (i>GetLastIdx(T1));
      }

    }

  }
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1 (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search TANPA boolean */
{
  /*KAMUS*/
  int i = GetFirstIdx(T);
  /*ALGORTIMA*/
  if (!IsEmpty(T)) {
    /* Jika tabel T tidak kosong*/
    while ((i<=GetLastIdx(T))&&(Elmt(T,i)!=X)) {
      i++;
    }
    if (i>GetLastIdx(T)) {
      return IdxUndef;
    }else{
      return i;
    }
  }else{
    /* Jika tabel T kosong*/
    return IdxUndef;
  }
}


IdxType Search2 (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search DENGAN boolean Found */
{
  /*KAMUS*/
  int i = GetFirstIdx(T);
  boolean Found = false;
  /*ALGORTIMA*/
  if (!IsEmpty(T)) {
    /* Jika tabel T tidak kosong*/
    Found = (Elmt(T,GetFirstIdx(T))==X);
    while ((i<GetLastIdx(T))&&(!Found)) {
      i++;
      Found = (Elmt(T,i)==X);
    }
    if (!Found) {
      return IdxUndef;
    }else{
      return i;
    }
  }else{
    /* Jika tabel T kosong*/
    return IdxUndef;
  }
}


boolean SearchB (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Memakai Skema search DENGAN boolean */
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

boolean SearchSentinel (TabInt T, ElType X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* dengan metoda sequential search dengan sentinel */
/* Untuk sentinel, manfaatkan indeks ke-0 dalam definisi array dalam Bahasa C
   yang tidak dipakai dalam definisi tabel */
{
  /*KAMUS*/
  int i = GetLastIdx(T);

  /*ALGORTIMA*/


  /*Inserting sentinel in idx 0*/
  if (!IsEmpty(T)) {
    Elmt(T,0)=X;

    /*Search from right to left, and X must be found, at least at idx 0*/
    while (Elmt(T,i)!=X) {
      i--;
    }
    return (i>0);
  }else{
    return false;
  }


}

/* ********** NILAI EKSTREM ********** */
ElType ValMax (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai maksimum tabel */
{
  int i;
  ElType MAX = Elmt(T, GetFirstIdx(T)); /*inisialisasi*/

  for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++) {
    if (Elmt(T,i)>=MAX) {
      MAX = Elmt(T,i);
    }
  }
  return MAX;
}

ElType ValMin (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai minimum tabel */
/* *** Mengirimkan indeks elemen bernilai ekstrem *** */
{
  int i;
  ElType MIN = Elmt(T, GetFirstIdx(T)); /*inisialisasi*/

  for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++) {
    if (Elmt(T,i)<=MIN) {
      MIN = Elmt(T,i);
    }
  }
  return MIN;
}

IdxType IdxMaxTab (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai maksimum pada tabel */
{
  return Search1(T, ValMax(T));
}

IdxType IdxMinTab (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i terkecil dengan nilai elemen merupakan nilai minimum pada tabel */
{
  return Search1(T, ValMin(T));
}

/* ********** OPERASI LAIN ********** */
void CopyTab (TabInt Tin, TabInt * Tout)
/* I.S. Tin terdefinisi, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (elemen dan ukuran identik) */
/* Proses : Menyalin isi Tin ke Tout */
{
  int i;
  Neff(*Tout)= Neff(Tin);
  if (!IsEmpty(Tin)) {
    for (i = GetFirstIdx(Tin); i <= GetLastIdx(Tin); i++) {
      Elmt(*Tout, i) = Elmt(Tin, i);
    }
  }
}

TabInt InverseTab (TabInt T)
/* Menghasilkan tabel dengan urutan tempat yang terbalik, yaitu : */
/* elemen pertama menjadi terakhir, */
/* elemen kedua menjadi elemen sebelum terakhir, dst.. */
/* Tabel kosong menghasilkan tabel kosong */
{
  TabInt Tout;
  Neff(Tout) = Neff(T);
  IdxType i;
  for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++){
    Elmt(Tout,i) = Elmt(T, GetLastIdx(T)-i+GetFirstIdx(T));
  }
  return Tout;

}

boolean IsSimetris (TabInt T)
/* Menghasilkan true jika tabel simetrik */
/* Tabel disebut simetrik jika: */
/*      elemen pertama = elemen terakhir, */
/*      elemen kedua = elemen sebelum terakhir, dan seterusnya */
/* Tabel kosong adalah tabel simetris */
{
  int ix, iy;
  boolean simetris = true;
  ix = GetFirstIdx(T);
  iy = GetLastIdx(T);
  if (!IsEmpty(T)) {
    while ((ix<=(GetLastIdx(T)/2))&&(simetris)) {
      simetris = (Elmt(T,ix)==Elmt(T,iy));
      iy--;
      ix++;
    }
    return simetris;
  }else{
    return true; /*jika kosong*/
  }
}


/* ********** SORTING ********** */
void MaxSortDesc (TabInt * T)
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menurun dengan Maximum Sort */
/* Proses : mengurutkan T sehingga elemennya menurun/mengecil */
/*          tanpa menggunakan tabel kerja */
{
  ElType temp,max;
  IdxType i,imax;

  if (!IsEmpty(*T)) {
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


void InsSortAsc (TabInt * T)
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menaik dengan Insertion Sort */
/* Proses : mengurutkan T sehingga elemennya menaik/membesar */
/*          tanpa menggunakan tabel kerja */
{
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
}

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void AddAsLastEl (TabInt * T, ElType X)
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
{
  if (!IsFull(*T)) {
    Neff(*T)++;
    Elmt(*T,(GetLastIdx(*T)))=X;
  }
}

void AddEli (TabInt * T, ElType X, IdxType i)
/* Menambahkan X sebagai elemen ke-i tabel tanpa mengganggu kontiguitas
   terhadap elemen yang sudah ada */
/* I.S. Tabel tidak kosong dan tidak penuh */
/*      i adalah indeks yang valid. */
/* F.S. X adalah elemen ke-i T yang baru */
/* Proses : Geser elemen ke-i+1 s.d. terakhir */
/*          Isi elemen ke-i dengan X */
{
  int ix;

  for (ix = GetLastIdx(*T); ix >= i; ix--) {
    Elmt(*T,(ix+1)) = Elmt(*T,ix);
  }
  Elmt(*T,i)=X;
  Neff(*T)++;
}

/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl (TabInt * T, ElType * X)
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
{
  *X = Elmt(*T,GetLastIdx(*T));
  Neff(*T)--;
}
void DelEli (TabInt * T, IdxType i, ElType * X)
/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */
/*          Kurangi elemen efektif tabel */
{
  int ix;
  *X = Elmt(*T,i);
  for (ix = i; ix <= GetLastIdx(*T); ix++) {
    Elmt(*T,ix) = Elmt(*T,(ix+1));
  }
  Neff(*T)--;
}


/* ********** TABEL DGN ELEMEN UNIK (SETIAP ELEMEN HANYA MUNCUL 1 KALI) ********** */
void AddElUnik (TabInt * T, ElType X)
/* Menambahkan X sebagai elemen terakhir tabel, pada tabel dengan elemen unik */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/*      dan semua elemennya bernilai unik, tidak terurut */
/* F.S. Jika tabel belum penuh, menambahkan X sbg elemen terakhir T,
        jika belum ada elemen yang bernilai X.
		Jika sudah ada elemen tabel yang bernilai X maka I.S. = F.S.
		dan dituliskan pesan "nilai sudah ada" */
/* Proses : Cek keunikan dengan sequential search dengan sentinel */
/*          Kemudian tambahkan elemen jika belum ada */
{
  if (SearchB(*T,X)) {
    printf("nilai sudah ada");
  }else{
    Elmt(*T, (GetLastIdx(*T)+1))=X;
    Neff(*T)++;
  }
}

/* ********** TABEL DGN ELEMEN TERURUT MEMBESAR ********** */
IdxType SearchUrut (TabInt T, ElType X)
/* Prekondisi: Tabel T boleh kosong. Jika tidak kosong, elemen terurut membesar. */
/* Mengirimkan indeks di mana harga X dengan indeks terkecil diketemukan */
/* Mengirimkan IdxUndef jika tidak ada elemen tabel bernilai X */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel kosong */
{
  int i = GetFirstIdx(T);
  if (!IsEmpty(T)) {
    while((Elmt(T,i)<X)&&(i<=GetLastIdx(T))){
      i++;
    }

    if (Elmt(T,i)==X) {
      return i;
    }else{
      return IdxUndef;
    }

  }else{
    return IdxUndef;
  }
}
ElType MaxUrut (TabInt T)
/* Prekondisi : Tabel tidak kosong, elemen terurut membesar */
/* Mengirimkan nilai maksimum pada tabel */
{
  return Elmt(T, GetLastIdx(T));
}

ElType MinUrut (TabInt T)
/* Prekondisi : Tabel tidak kosong, elemen terurut membesar */
/* Mengirimkan nilai minimum pada tabel*/
{
  return Elmt(T, GetFirstIdx(T));
}

void MaxMinUrut (TabInt T, ElType * Max, ElType * Min)
/* I.S. Tabel T tidak kosong, elemen terurut membesar */
/* F.S. Max berisi nilai maksimum T{}
        Min berisi nilai minimum T */
{
  *Max = MaxUrut(T);
  *Min = MinUrut(T);
}
void Add1Urut (TabInt * T, ElType X)
/* Menambahkan X tanpa mengganggu keterurutan nilai dalam tabel */
/* Nilai dalam tabel tidak harus unik. */
/* I.S. Tabel T boleh kosong, boleh penuh. */
/*      Jika tabel isi, elemennya terurut membesar. */
/* F.S. Jika tabel belum penuh, menambahkan X. */
/*      Jika tabel penuh, maka tabel tetap. */
/* Proses : Search tempat yang tepat sambil geser */
/*          Insert X pada tempat yang tepat tersebut tanpa mengganggu keterurutan */
{
  int i = GetFirstIdx(*T);
  if(!IsFull(*T)){
    if (!IsEmpty(*T)) {
      /*mencari starting idx*/
      while((i<=GetLastIdx(*T))&&(Elmt(*T,i)<X)){
        i++;
      }
      AddEli(&(*T),X,i);
    }else{
      Elmt(*T,GetFirstIdx(*T))=X;
      Neff(*T)++;
    }
  }
}

void Del1Urut (TabInt * T, ElType X)
/* Menghapus X yang pertama kali (pada indeks terkecil) yang ditemukan */
/* I.S. Tabel tidak kosong */
/* F.S. Jika ada elemen tabel bernilai X , */
/*      maka banyaknya elemen tabel berkurang satu. */
/*      Jika tidak ada yang bernilai X, tabel tetap. */
/*      Setelah penghapusan, elemen tabel tetap kontigu! */
/* Proses : Search indeks ke-i dengan elemen ke-i = X. */
/*          Delete jika ada. */
{
  int i;
  if(SearchB(*T,X)){
    for (i = Search1(*T,X); i < GetLastIdx(*T); i++) {
      Elmt(*T,i) = Elmt(*T,(i+1));
    }
    Neff(*T)--;
  }
}
