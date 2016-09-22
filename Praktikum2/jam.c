/* File: jam.c */
#include "jam.h"
#include "boolean.h"
/* DEFINISI PRIMITIF                                                 */
#include <stdio.h>


/* ***************************************************************** */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsJAMValid (int H, int M, int S)
/* Mengirim true  jika H,M,S dapat membentuk J yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */
{
  return ((H>=0)&&(H<=23))&&((M>=0)&&(M<=59))&&((S>=0)&&(S<=59));
}

/* *** Konstruktor: Membentuk sebuah JAM dari komponen-komponennya *** */
JAM MakeJAM (int HH, int MM, int SS)
/* Membentuk sebuah JAM dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk JAM */
{
  JAM j;
  Hour(j) = HH;
  Minute(j) = MM;
  Second(j) = SS;
  return j;
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaJAM (JAM * J)
/* I.S. : J tidak terdefinisi */
/* F.S. : J terdefinisi dan merupakan jam yang valid */
/* Proses : mengulangi membaca komponen HH, MM, SS sehingga membentuk J */
/* yang valid. Tidak mungkin menghasilkan J yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen HH, MM, SS
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika JAM tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
   diulangi hingga didapatkan jam yang valid. */
/* Contoh:
   60 3 4
   Jam tidak valid
   1 3 4
   --> akan terbentuk JAM <1,3,4> */
{
  int a,b,c;
  scanf("%d %d %d",&a,&b,&c);
  while (!IsJAMValid(a,b,c)) {
    printf("Jam tidak valid\n");
    scanf("%d %d %d",&a,&b,&c);
  }
  Hour(*J) = a;
  Minute(*J) = b;
  Second(*J) = c;
}

void TulisJAM (JAM J)
/* I.S. : J sembarang */
/* F.S. :   Nilai J ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen J ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/
{
  printf("%d:%d:%d", Hour(J), Minute(J), Second(J));
}

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long JAMToDetik (JAM J)
/* Diberikan sebuah JAM, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
/* Nilai maksimum = 3600*23+59*60+59 */
{
  return ((3600*Hour(J)) + (60*Minute(J)) + Second(J));
}

JAM DetikToJAM (long N)
/* Mengirim  konversi detik ke JAM */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang
   mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus:
   N1 = N mod 86400, baru N1 dikonversi menjadi JAM */
{
  /* KAMUS */
  JAM J;
  long temp;

  /* ALGORITMA */
  N = N % 86400;
  Hour(J) = N / 3600;
  Minute(J) = (N - (Hour(J)*3600))/60;
  Second(J) = N - (Hour(J)*3600) - (Minute(J)*60);

  return J;
}

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean JEQ (JAM J1, JAM J2)
/* Mengirimkan true jika J1=J2, false jika tidak */
{
  return ((Hour(J1)==Hour(J2))&&(Minute(J1)==Minute(J2))&&(Second(J1)&&(Second(J2))));
}

boolean JNEQ (JAM J1, JAM J2)
/* Mengirimkan true jika J1 tidak sama dengan J2 */
{
  return !((Hour(J1)==Hour(J2))&&(Minute(J1)==Minute(J2))&&(Second(J1)&&(Second(J2))));
}

boolean JLT (JAM J1, JAM J2)
/* Mengirimkan true jika J1<J2, false jika tidak */
{
  return ((JAMToDetik(J1))<(JAMToDetik(J2)));
}

boolean JGT (JAM J1, JAM J2)
/* Mengirimkan true jika J1>J2, false jika tidak */
{
  return ((JAMToDetik(J1))>(JAMToDetik(J2)));
}

/* *** Operator aritmatika JAM *** */
JAM NextDetik (JAM J)
/* Mengirim 1 detik setelah J dalam bentuk JAM */
{
  if (Second(J)<59) {
    Second(J)++;
  }else{
    if (Minute(J)<59) {
      Minute(J)++;
    }else{
      if (Hour(J)<23) {
        Hour(J)++;
      }else{
        Hour(J)=0;
        Minute(J)=0;
        Second(J)=0;
      }
    }
  }

  return J;
}

JAM NextNDetik (JAM J, int N)
/* Mengirim N detik setelah J dalam bentuk JAM */
{
  JAM J2;
  int temp;
  J2 = DetikToJAM(N);
  Second(J) += Second(J2);
  Minute(J) += Minute(J2);
  Hour(J) += Hour(J2);

  if (Second(J)>59) {
    temp = Second(J);
    Second(J) = temp % 60;
    Minute(J) += temp / 60;
  }
  if (Minute(J)>59) {
    temp = Minute(J);
    Minute(J) = temp % 60;
    Hour(J) += temp/60;
  }
  if (Hour(J)>23) {
    temp = Hour(J);
    Hour(J) = temp % 24;
  }

  return J;
}

JAM PrevDetik (JAM J)
/* Mengirim 1 detik sebelum J dalam bentuk JAM */
{
  if (Second(J)== 0) {
    Second(J)=59;
    Minute(J)-=1;
  }else{
    Second(J)--;
  }

  return J;
}

JAM PrevNDetik (JAM J, int N)
/* Mengirim N detik sebelum J dalam bentuk JAM */
/* *** Kelompok Operator Aritmetika *** */
{
  JAM J2 = DetikToJAM(N);
  int temp;

  Second(J) -= Second(J2);
  Minute(J) -= Minute(J2);
  Hour(J) -= Hour(J2);

  if (Second(J)<0) {
    temp = Second(J)*(-1);
    Second(J) =60 - (temp%60);
    temp = temp / 60;
    Minute(J) -= (temp+1);
  }
  if (Minute(J)<0) {
    temp = Minute(J)*(-1);
    Minute(J) = 60 - (temp%60);
    temp = temp / 60;
    Hour(J) -= (temp+1);
  }
  if (Hour(J)<0) {
    temp = Hour(J)*(-1);
    Hour(J) = 24 - (temp%24);
  }

  return J;
}

long Durasi (JAM JAw, JAM JAkh)
/* Mengirim JAkh-JAw dlm Detik, dengan kalkulasi */
/* Jika JAw > JAkh, maka JAkh adalah 1 hari setelah JAw */
{
  long temp;
  if (JAMToDetik(JAw)>JAMToDetik(JAkh)) {
    temp = JAMToDetik(JAkh)+86400-JAMToDetik(JAw);
  }else{
    temp = JAMToDetik(JAkh)-JAMToDetik(JAw);
  }
  return temp%86400;
}
