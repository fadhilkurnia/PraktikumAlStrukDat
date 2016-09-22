/* ********** Definisi TYPE MATRIKS dengan indeks dan elemen integer ********** */

#include "boolean.h"
#include "matriks.h"
#include <stdio.h>



/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M)
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
  if(IsIdxValid(NB,NK)){
    NBrsEff(*M) = NB;
    NKolEff(*M) = NK;
  }
}


/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j)
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
{
  return (i>=BrsMin && i<=BrsMax && j>=KolMin && j<=KolMax);
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terkecil M */
{
  return BrsMin;
}

indeks GetFirstIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terkecil M */
{
  return KolMin;
}

indeks GetLastIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terbesar M */
{
  return NBrsEff(M);
}

indeks GetLastIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terbesar M */
{
  return NKolEff(M);
}

boolean IsIdxEff (MATRIKS M, indeks i, indeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{
  return ( i >= GetFirstIdxBrs(M) && i <= GetLastIdxBrs(M) && j >= GetFirstIdxKol(M) && j <= GetLastIdxKol(M) );
}

ElType GetElmtDiagonal (MATRIKS M, indeks i)
/* Mengirimkan elemen M(i,i) */
{
  return Elmt(M,i,i);
}

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl)
/* Melakukan assignment MHsl  MIn */
{
  /*Kamus*/
  indeks i,j;

  /*Algoritma*/
  NBrsEff(*MHsl) = NBrsEff(MIn);
  NKolEff(*MHsl) = NKolEff(MIn);
  for (i = GetFirstIdxBrs(MIn); i <= GetLastIdxBrs(MIn); i++) {
    for (j = GetFirstIdxKol(MIn); j <= GetLastIdxKol(MIn); j++) {
      Elmt(*MHsl, i, j) = Elmt(MIn, i, j);
    }
  }
}

/* ********** KELOMPOK BACA/TULIS ********** */
void BacaMATRIKS (MATRIKS * M, int NB, int NK)
/* I.S. IsIdxValid(NB,NK) */
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10
*/
{
  /*Kamus*/
  indeks i,j;
  ElType x;

  /*Algpritma*/
  if (IsIdxValid(NB,NK)) {
    MakeMATRIKS(NB, NK, &(*M));
    for (i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++) {
      for (j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++) {
        scanf("%d",&x);
        Elmt(*M,i,j) = x;
      }
    }
  }
}

void TulisMATRIKS (MATRIKS M)
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
  /*Kamus*/
  indeks i,j;


  /*Algoritma*/
  for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
    for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
      printf("%d",Elmt(M,i,j));
      if(j<GetLastIdxKol(M)){
        printf(" ");
      }
    }
    if(i!=GetLastIdxBrs(M))
      printf("\n");
  }
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */
{
  /*Kamus*/
  indeks i,j;
  MATRIKS M;

  /*Algoritma*/
  MakeMATRIKS(NBrsEff(M1), NKolEff(M1), &M);
  for (i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++) {
    for (j = GetFirstIdxKol(M1); j <= GetLastIdxKol(M1); j++) {
      Elmt(M,i,j) = Elmt(M1,i,j) + Elmt(M2,i,j);
    }
  }
  return M;
}
MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */
{
  /*Kamus*/
  indeks i,j;
  MATRIKS M;

  /*Algoritma*/
  MakeMATRIKS(NBrsEff(M1), NKolEff(M1), &M);
  for (i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++) {
    for (j = GetFirstIdxKol(M1); j <= GetLastIdxKol(M1); j++) {
      Elmt(M,i,j) = Elmt(M1,i,j) - Elmt(M2,i,j);
    }
  }
  return M;
}

MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
{
  /*Kamus*/
  indeks i, j, x;
  MATRIKS M;

  /*Algoritma*/
  if (NKolEff(M1)==NBrsEff(M2)){
    MakeMATRIKS(NBrsEff(M1),NKolEff(M2),&M);
    for (i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++) {
      for (j = GetFirstIdxKol(M2); j <= GetLastIdxKol(M2); j++) {
        Elmt(M,i,j) = 0;
        for (x = GetFirstIdxKol(M1); x <= GetLastIdxKol(M1); x++) {
          Elmt(M,i,j) = Elmt(M,i,j)+(Elmt(M1,i,x) * Elmt(M2,x,j));
        }
      }
    }
  }

  return M;
}


MATRIKS KaliKons (MATRIKS M, ElType X)
/* Mengirim hasil perkalian setiap elemen M dengan X */
{
  /*Kamus*/
  indeks i,j;
  MATRIKS Mo;

  /*Algoritma*/
  MakeMATRIKS(NBrsEff(M), NKolEff(M), &Mo);
  for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
    for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
      Elmt(Mo,i,j) = Elmt(M,i,j)* X;
    }
  }
  return Mo;
}

void PKaliKons (MATRIKS * M, ElType K)
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */
{
  /*Kamus*/
  indeks i,j;

  /*Algoritma*/
  for (i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++) {
    for (j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++) {
      Elmt(*M,i,j) = Elmt(*M,i,j) * K;
    }
  }
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2)
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
{
  /*Kamus*/
  indeks i,j;
  boolean sama = true;

  /*Algoritma*/
  if(EQSize(M1,M2)){
      i = GetFirstIdxBrs(M1);
      while(sama && i<=GetLastIdxBrs(M1)){
        j = GetFirstIdxKol(M2);
        while (sama && j<=GetLastIdxKol(M1)) {

          if (Elmt(M1,i,j)!=Elmt(M2,i,j)) {
            sama = false;
          }else{
            j++;
          }

        }
        i++;
      }
      return sama;
  }else{
      return false;
  }
}

boolean NEQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 tidak sama dengan M2 */
{
    return !EQ(M1,M2);
}

boolean EQSize (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
{
  return (NBrsEff(M1)==NBrsEff(M2) && NKolEff(M1)==NKolEff(M2));
}

/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M)
/* Mengirimkan banyaknya elemen M */
{
  return NKolEff(M)*NBrsEff(M);
}

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M)
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
{
    return (NBrsEff(M)==NKolEff(M));
}

boolean IsSimetri (MATRIKS M)
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M)
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
{
  /*Kamus*/
  indeks i,j;
  boolean simetri = true;

  /*Algoritma*/
  if (IsBujurSangkar(M)) {
    i = GetFirstIdxBrs(M);
    while(simetri && i<=GetLastIdxBrs(M)){
      j = GetFirstIdxKol(M);
      while (simetri && j<=GetLastIdxKol(M)) {

        if (Elmt(M,i,j)!=Elmt(M,j,i)) {
          simetri = false;
        }else{
          j++;
        }

      }
      i++;
    }
    return simetri;
  }else{
    return false;
  }

  /* Algoritma 2 : Simetris jika Transpose(M)==M */
  /* Dapat memakan memori lebih banyak karena dibutuhkan MATRIKS tambahan*/
  /*MATRIKS T;
  MakeMATRIKS(NBrsEff(M), NKolEff(M), &T);
  CopyMATRIKS(M, &T);
  Transpose(&T);
  return EQ(M,T);*/
}

boolean IsSatuan (MATRIKS M)
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
{
  if(IsSimetri(M)){
    boolean satuan = true;
    indeks i = GetFirstIdxBrs(M),j;

    while(satuan && i<=GetLastIdxBrs(M)){
      j = GetFirstIdxKol(M);
      while (satuan && j<=GetLastIdxKol(M)) {
        if(i==j){ /*pada diagonal*/
          if(Elmt(M,i,j)!=1)
            satuan = false;
          else
            j++;
        }else{
          if(Elmt(M,i,j)!=0)
            satuan = false;
          else
            j++;
        }
      }
      i++;
    }

    return satuan;
  }else{
    return false;
  }
}

boolean IsSparse (MATRIKS M)
/* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi:
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
{
  float batas = NBElmt(M)*0.05;
  int count = 0;
  indeks i = GetFirstIdxBrs(M),j;
  float stop = false;

  while (!stop && i<=GetLastIdxBrs(M)) {
    j = GetFirstIdxKol(M);
    while (!stop && j <= GetLastIdxKol(M)) {
      if(Elmt(M, i, j)!= 0)
        count++;
      if(count>batas){
        stop = true;
      }else{
        j++;
      }
    }
    i++;
  }

  return !stop;
}

MATRIKS Inverse1 (MATRIKS M)
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
{
  indeks i,j;
  MATRIKS Mo;
  MakeMATRIKS(NBrsEff(M),NKolEff(M), &Mo);
  for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
    for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
      Elmt(Mo, i, j) = Elmt(M, i, j)*(-1);
    }
  }

  return Mo;
}

float Determinan (MATRIKS M)
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */
{
  int x, subi, i, j, subj, pangkat;
  float det = 0;

  if (GetLastIdxBrs(M) == 1) {
    return Elmt(M,1,1);
  }else if (GetLastIdxBrs(M) == 2) { /* Basis rekursif saat matriks 2x2 */
    return ( (Elmt(M,1,1)*Elmt(M,2,2))-(Elmt(M,1,2)*Elmt(M,2,1)) );
  }else{ /*rekurens*/
    MATRIKS submat;
    MakeMATRIKS(NBrsEff(M)-1,NKolEff(M)-1,&submat);
    for (x = GetFirstIdxKol(M); x <= GetLastIdxKol(M); x++) {
      subi = BrsMin;
      for (i = GetFirstIdxBrs(M)+1; i <=GetLastIdxBrs(M); i++) {
        subj = KolMin;
        for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
          if( j==x )
            continue;
          Elmt(submat, subi, subj) = Elmt(M,i,j);
          subj++;
        }
        subi++;
      }
	
	  if(x&2==0){
		pangkat = (-1);
	  }else{
		pangkat = 1;
	  }
      det = det + ( pangkat * Elmt(M, GetFirstIdxBrs(M),x) * Determinan(submat));
    }
    return det;
  }

}

void PInverse1 (MATRIKS * M)
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
{
  indeks i,j;
  for (i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++) {
    for (j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++) {
      Elmt(*M, i, j) = Elmt(*M, i, j)*(-1);
    }
  }
}

void Transpose (MATRIKS * M)
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
{

  if (IsBujurSangkar(*M)) {
    int i = GetFirstIdxBrs(*M);
    int j;
    int x = 1;
    ElType temp;
    while (i <= GetLastIdxBrs(*M)) {
      j = GetFirstIdxKol(*M)+x;
      while (j <= GetLastIdxKol(*M)) {
        /*tukar*/
        temp = Elmt(*M,i,j);
        Elmt(*M,i,j) = Elmt(*M,j,i);
        Elmt(*M,j,i) = temp;
        j++;
      }
      i++;
      x++;
    }
  }
}

/* Operasi berbasis baris dan per kolom */

float RataBrs (MATRIKS M, indeks i)
/* Menghasilkan rata-rata dari elemen pada baris ke-i */
/* Prekondisi: i adalah indeks baris efektif dari M */
{
	/*Kamus*/
	ElType sum =0;
	indeks j;
	
	/*Algoritma*/
	for(j = GetFirstIdxKol(M); j <=GetLastIdxKol(M); j++){
		sum += Elmt(M,i,j);
	}
	
	return ((float) sum/(float) NKolEff(M));
}

float RataKol (MATRIKS M, indeks j)
/* Menghasilkan rata-rata dari elemen pada kolom ke-j */
/* Prekondisi: j adalah indeks kolom efektif dari M */
{
	/*Kamus*/
	ElType sum =0;
	indeks i;
	
	/*Algoritma*/
	for(i = GetFirstIdxBrs(M); i <=GetLastIdxBrs(M); i++){
		sum += Elmt(M,i,j);
	}
	
	return ((float) sum/(float)NBrsEff(M));	
}

void MaxMinBrs (MATRIKS M, indeks i, ElType * max, ElType * min)
/* I.S. i adalah indeks baris efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada baris i dari M
           min berisi elemen minimum pada baris i dari M */
{
	/*Kamus*/
	indeks x;
	
	/*inisialisasi*/
	*min = Elmt(M,i,GetFirstIdxKol(M));
	*max = Elmt(M,i,GetFirstIdxKol(M));
	for(x = GetFirstIdxKol(M)+1; x<=GetLastIdxKol(M); x++){
		if(Elmt(M,i,x)<*min)
			*min = Elmt(M,i,x);
		
		if(Elmt(M,i,x)>*max)
			*max = Elmt(M,i,x);	
	}
}

void MaxMinKol (MATRIKS M, indeks j, ElType * max, ElType * min)
/* I.S. j adalah indeks kolom efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada kolom j dari M
           min berisi elemen minimum pada kolom j dari M */
{
	/*Kamus*/
	indeks y;
	
	/*inisialisasi*/
	*min = Elmt(M,GetFirstIdxBrs(M),j);
	*max = Elmt(M,GetFirstIdxBrs(M),j);
	for(y = GetFirstIdxBrs(M)+1; y<=GetLastIdxBrs(M); y++){
		if(Elmt(M,y,j)<*min)
			*min = Elmt(M,y,j);
		
		if(Elmt(M,y,j)>*max)
			*max = Elmt(M,y,j);
	}	
}

int CountXBrs (MATRIKS M, indeks i, ElType X)
/* Menghasilkan banyaknya kemunculan X pada baris i dari M */
{
	/*Kamus*/
	indeks c;
	ElType count = 0;
	
	for(c = GetFirstIdxKol(M); c<=GetLastIdxKol(M); c++){
		if(Elmt(M,i,c)==X)
			count++;
	}	
	
	return count;
}

int CountXKol (MATRIKS M, indeks j, ElType X)
/* Menghasilkan banyaknya kemunculan X pada kolom j dari M */
{
	/*Kamus*/
	indeks c;
	ElType count = 0;
	
	for(c = GetFirstIdxBrs(M); c<=GetLastIdxBrs(M); c++){
		if(Elmt(M,c,j)==X)
			count++;
	}	
	
	return count;
}
