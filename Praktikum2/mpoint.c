#include "point.h"
#include <stdio.h>

int main(){
  POINT P,P2;
  float x,y;

  printf("|Uji coba MakePOINT:\n");
  printf("   Masukkan absis :");
  scanf("%f", &x);
  printf("   Masukkan ordinat :");
  scanf("%f", &y);
  TulisPOINT(MakePOINT(x,y));
  printf("\n\n");

  printf("|Uji coba BacaPOINT:\n");
  BacaPOINT(&P);
  TulisPOINT(P);
  printf("\n\n");

  printf("|Uji coba TulisPOINT:\n");
  TulisPOINT(P);
  printf("\n\n");

  printf("|Uji coba EQ:\n");
  printf("   Masukkan absis point 1 :");
  scanf("%f", &x);
  printf("   Masukkan ordinat point 1:");
  scanf("%f", &y);
  P = MakePOINT(x,y);
  printf("   Masukkan absis point 2 :");
  scanf("%f", &x);
  printf("   Masukkan ordinat point 2:");
  scanf("%f", &y);
  P2 = MakePOINT(x,y);
  printf("Apakah point1 sama dengan point2 ? %d\n", EQ(P,P2));
  printf("\n\n");

  printf("|Uji coba NEQ:\n");
  printf("   Masukkan absis point 1 :");
  scanf("%f", &x);
  printf("   Masukkan ordinat point 1:");
  scanf("%f", &y);
  P = MakePOINT(x,y);
  printf("   Masukkan absis point 2 :");
  scanf("%f", &x);
  printf("   Masukkan ordinat point 2:");
  scanf("%f", &y);
  P2 = MakePOINT(x,y);
  printf("   Apakah point1 tidak sama dengan point2 ? %d\n", NEQ(P,P2));
  printf("\n\n");

  printf("|Uji coba IsOrigin:\n   Masukkan point uji x y:");
  BacaPOINT(&P);
  printf("   Apakah point uji merupakan titik origin? %d\n\n", IsOrigin(P));

  printf("|Uji coba IsOnSbX:\n   Masukkan point uji x y:");
  BacaPOINT(&P);
  printf("   Apakah point uji ada di sb x? %d\n\n", IsOnSbX(P));

  printf("|Uji coba IsOnSbY:\n   Masukkan point uji x y:");
  BacaPOINT(&P);
  printf("   Apakah point uji ada di sb y? %d\n\n", IsOnSbY(P));

  printf("|Uji coba Kuadran:\n   Masukkan point uji x y:");
  BacaPOINT(&P);
  printf("   Point uji ada di kuadran %d.\n\n", Kuadran(P));

  printf("|Uji coba NextX:\n   Masukkan point uji x y:");
  BacaPOINT(&P);
  TulisPOINT(NextX(P));
  printf("\n\n");

  printf("|Uji coba NextY:\n   Masukkan point uji x y:");
  BacaPOINT(&P);
  TulisPOINT(NextY(P));
  printf("\n\n");

  printf("|Uji coba PlusDelta:\n   Masukkan point uji x y:");
  BacaPOINT(&P);
  printf("masukkan dx dy :");
  scanf("%f %f", &x,&y);
  TulisPOINT(PlusDelta(P,x,y));
  printf("\n\n");

  printf("|Uji coba MirrorOf:\n   Masukkan point uji x y:");
  BacaPOINT(&P);
  TulisPOINT(MirrorOf(P,true));
  printf("\n");
  TulisPOINT(MirrorOf(P,false));
  printf("\n\n");

  printf("|Uji coba Jarak0:\n   Masukkan point uji x y:");
  BacaPOINT(&P);
  printf("   Jarak dengan origin %f\n\n", Jarak0(P));

  printf("|Uji coba Panjang:\n");
  printf("   Masukkan absis point 1 :");
  scanf("%f", &x);
  printf("   Masukkan ordinat point 1:");
  scanf("%f", &y);
  P = MakePOINT(x,y);
  printf("   Masukkan absis point 2 :");
  scanf("%f", &x);
  printf("   Masukkan ordinat point 2:");
  scanf("%f", &y);
  P2 = MakePOINT(x,y);
  printf("   Jarak point1 ke point2 ? %f\n", Panjang(P,P2));
  printf("\n\n");

  printf("|Uji coba Geser:\n   Masukkan point uji x y:");
  BacaPOINT(&P);
  printf("masukkan dx dy :");
  scanf("%f %f", &x,&y);
  Geser(&P, x, y);
  printf("   Setelah digeser:");
  TulisPOINT(P);
  printf("\n\n");

  printf("|Uji coba GeserKeSbX dan GeserKeSbY:\n   Masukkan point uji x y:");
  BacaPOINT(&P);
  GeserKeSbX(&P);
  printf("Setelah digeser ke sb X :");
  TulisPOINT(P);
  printf("\nSetelah digeser ke sb Y");
  TulisPOINT(P);
  printf("\n\n");

  printf("|Uji coba Mirror:\n   Masukkan point uji x y:");
  BacaPOINT(&P);
  Mirror(&P, true);
  printf("Setelah point diceerminkan trhdp X :");
  TulisPOINT(P);
  Mirror(&P, false);
  printf("\nSetelah point diceerminkan trhdp X :");
  TulisPOINT(P);
  printf("\n\n");

  printf("|Uji coba Putar:\n   Masukkan point uji x y:");
  BacaPOINT(&P);
  printf("Masukkan sudut :");
  scanf("%f", &x);
  printf("Setelah point diputar %f derajat: ", x);
  Putar(&P, x);
  TulisPOINT(P);
  printf("\n\n");

  return 0;
}
