/* ADT Pohon Biner */
/* Implementasi dengan menggunakan pointer */
/* Penamaan type infotype, type addrNode, dan beberapa fungsi disesuikan 
   karena melibatkan modul list rekursif. */

#include "bintree.h"
#include <stdlib.h>
#include <stdio.h>

/* *** Definisi Type Pohon Biner *** */
/* typedef int infotype; */ /* type infotype sesuai pada modul listrek */


/* Definisi PohonBiner : */
/* Pohon Biner kosong : P = Nil */


/* *** Konstruktor *** */
BinTree Tree (infotype Akar, BinTree L, BinTree R)
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */
{
	BinTree P;
	
	P = AlokNode(Akar);
	if(P!=Nil){
		Left(P) = L;
		Right(P) = R;
	}else{
		P = Nil;
	}
	
	return P;
}

void MakeTree (infotype Akar, BinTree L, BinTree R, BinTree *P)
/* I.S. Akar, L, R terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R 
		jika alokasi berhasil. P = Nil jika alokasi gagal. */
{
	*P = AlokNode(Akar);
	if(*P!=Nil){
		Left(*P) = L;
		Right(*P) = R;
	}else{
		*P = Nil;
	}
}
		
/* Manajemen Memory */
addrNode AlokNode (infotype X)
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak Nil, dan misalnya menghasilkan P, 
  maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
	addrNode P = (addrNode) malloc (sizeof(addrNode));
	if(P!=Nil){
		Akar(P) = X;
		Right(P) = Nil;
		Left(P) = Nil;
		return P;
	}else
		return Nil;
}

void DealokNode (addrNode P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */
{
	free(P);
}

/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty (BinTree P)
/* Mengirimkan true jika P adalah pohon biner kosong */
{
	return (P == Nil);
}

boolean IsTreeOneElmt (BinTree P)
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */
{
	if(P==Nil)
		return false;
	else
		return ((Right(P)==Nil)&&(Left(P)==Nil));
}

boolean IsUnerLeft (BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri */
{	
	return ((Left(P)!=Nil)&&(Right(P)==Nil));
}

boolean IsUnerRight (BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan*/
{	
	return ((Left(P)==Nil)&&(Right(P)!=Nil));
}

boolean IsBiner (BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan*/
{	
	return ((Left(P)!=Nil)&&(Right(P)!=Nil));
}

/* *** Traversal *** */
void PrintPreorder (BinTree P)
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara preorder: akar, pohon kiri, dan pohon kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (A()()) adalah pohon dengan 1 elemen dengan akar A
   (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */
{
	printf("(");
	if(!IsTreeEmpty(P)){
		printf("%d",Akar(P));
		PrintPreorder(Left(P));
		PrintPreorder(Right(P));
	}
	printf(")");
}

   
void PrintInorder (BinTree P)
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara inorder: pohon kiri, akar, dan pohon kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (()A()) adalah pohon dengan 1 elemen dengan akar A
   ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C()) */
{
	printf("(");
	if(!IsTreeEmpty(P)){
		PrintInorder(Left(P));
		printf("%d",Akar(P));
		PrintInorder(Right(P));
	}
	printf(")");
}   
   
void PrintPostorder (BinTree P)
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara postorder: pohon kiri, pohon kanan, dan akar. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (()()A) adalah pohon dengan 1 elemen dengan akar A
   ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */
{
	printf("(");
	if(!IsTreeEmpty(P)){
		PrintPostorder(Left(P));
		PrintPostorder(Right(P));
		printf("%d",Akar(P));
	}
	printf(")");
}   


void PrintTree (BinTree P, int h)
/* I.S. P terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul P sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2: 
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
*/
{
	int i,j;
	
	if(!IsTreeEmpty(P)){
		printf("%d\n",Akar(P));
		i = j = h;
		if(Left(P)!=Nil){
			while(i--)
				printf(" ");
			PrintTree(Left(P),2*h);
		}
		if(Right(P)!=Nil){
			while(j--)
				printf(" ");
			PrintTree(Right(P),2*h);
		}
	}
	
}


/* *** Searching *** */
boolean SearchTree (BinTree P, infotype X)
/* Mengirimkan true jika ada node dari P yang bernilai X */
{
	if(IsTreeEmpty(P)){
		return false;
	}else{
		if(Akar(P)==X)
			return true;
		else
			return (SearchTree(Left(P),X)||SearchTree(Right(P),X));
	}
}

/* *** Fungsi-Fungsi Lain *** */
int NbElmt (BinTree P)
/* Mengirimkan banyaknya elemen (node) pohon biner P */
{
	if(IsTreeEmpty(P))
		return 0;
	else
		return (1+NbElmt(Left(P))+NbElmt(Right(P)));
}
int NbDaun (BinTree P)
/* Mengirimkan banyaknya daun (node) pohon biner P */
/* Prekondisi: P tidak kosong */
{
	if(IsTreeOneElmt(P))
		return 1;
	else
		if(IsBiner(P))
			return (NbDaun(Left(P))+NbDaun(Right(P)));
		else if(IsUnerLeft(P))
			return (NbDaun(Left(P)));
		else
			return (NbDaun(Right(P)));
}

boolean IsSkewLeft (BinTree P)
/* Mengirimkan true jika P adalah pohon condong kiri */
/* Pohon kosong adalah pohon condong kiri */
{
	if(IsTreeEmpty(P))
		return true;
	else
		if(IsBiner(P)||IsUnerRight(P))
			return false;
		else
			return IsSkewLeft(Left(P));
}

boolean IsSkewRight (BinTree P)
/* Mengirimkan true jika P adalah pohon condong kanan */
/* Pohon kosong adalah pohon condong kanan */
{
	if(IsTreeEmpty(P))
		return true;
	else
		if(IsBiner(P)||IsUnerLeft(P))
			return false;
		else
			return IsSkewRight(Left(P));
}

int Level (BinTree P, infotype X)
/* Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P. 
   Akar(P) level-nya adalah 1. Pohon P tidak kosong dan elemen-elemennya unik. */
{
	if((IsTreeOneElmt(P))||(Akar(P)==X))
		return 1;
	else
		if(SearchTree(Right(P),X))
			return 1 + Level(Right(P),X);
		else
			return 1 + Level(Left(P),X);
}

int Tinggi (BinTree P)
/* Pohon Biner mungkin kosong. Tinggi pohon kosong = 0.
   Mengirim "height" yaitu tinggi dari pohon */
{
	if(IsTreeEmpty(P))
		return 0;
	else{
		if(NbElmt(Right(P)) > NbElmt(Left(P)) )
			return 1 + Tinggi(Right(P));
		else
			return 1 + Tinggi(Left(P));
	}
}

/* *** Operasi lain *** */
void AddDaunTerkiri (BinTree *P, infotype X)
/* I.S. P boleh kosong */
/* F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri */
{
	if(IsTreeEmpty(*P))
		*P = AlokNode(X);
	else
		AddDaunTerkiri(&(Left(*P)),X);
}

void AddDaun (BinTree *P, infotype X, infotype Y, boolean Kiri)
/* I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P */
/* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri = true), atau 
        sebagai anak Kanan X (jika Kiri = false) */
/*		Jika ada > 1 daun bernilai X, diambil daun yang paling kiri */
{
	if(IsTreeOneElmt(*P)){
		if(Kiri)
			Left(*P) = AlokNode(Y);
		else
			Right(*P) = AlokNode(Y);
	}else{
		if(SearchTree(Left(*P),X))
			AddDaun(&(Left(*P)),X,Y,Kiri);
		else
			AddDaun(&(Right(*P)),X,Y,Kiri);
	}
}

void DelDaunTerkiri (BinTree *P, infotype *X)
/* I.S. P tidak kosong */
/* F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang semula 
        disimpan pada daun terkiri yang dihapus */
{
	addrNode N;
	if(IsTreeOneElmt(*P)){
		*X = Akar(*P);
		N = *P;
		*P = Nil;
		DealokNode(N);
	}else{
		if(Left(*P)!=Nil)
			DelDaunTerkiri(&(Left(*P)),&(*X));
		else
			DelDaunTerkiri(&(Right(*P)),&(*X));
	}
}
        
void DelDaun (BinTree *P, infotype X)
/* I.S. P tidak kosong, minimum ada 1 daun bernilai X. */
/* F.S. Semua daun bernilai X dihapus dari P. */
{
	addrNode N;
	if(IsTreeOneElmt(*P) && Akar(*P)==X){
		N = *P;
		DealokNode(N);
		*P = Nil;
	}else{
		if(Left(*P)!=Nil)
			DelDaun(&(Left(*P)), X);
		if(Right(*P)!=Nil)
		DelDaun(&(Right(*P)), X);
	}
}

List MakeListDaun (BinTree P)
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua daun pohon P,
   jika semua alokasi list berhasil.
   Daun terkiri menjadi elemen pertama dari list, diikuti elemen kanannya, dst.
   Menghasilkan list kosong jika ada alokasi yang gagal. */
{	
	if(IsTreeEmpty(P))
		return Nil;
	else{
		if(IsTreeOneElmt(P)){
			return Alokasi(Akar(P));
		}else{
			return Concat(MakeListDaun(Left(P)), MakeListDaun(Right(P)));
		}
	}
		
}

List MakeListPreorder (BinTree P)
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua elemen pohon P 
   dengan urutan preorder, jika semua alokasi berhasil.   
   Menghasilkan list kosong jika ada alokasi yang gagal. */
{
	if(IsTreeEmpty(P))
		return Nil;
	else{
		if(IsTreeOneElmt(P))
			return Alokasi(Akar(P));
		else
			return Konso(Akar(P),Concat(MakeListPreorder(Left(P)), MakeListPreorder(Right(P))));
	}
}	
List MakeListLevel (BinTree P, int N)
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua elemen pohon P 
   yang levelnya=N, jika semua alokasi berhasil. 
   Elemen terkiri menjadi elemen pertama dari list, diikuti elemen kanannya, dst.
   Menghasilkan list kosong jika ada alokasi yang gagal. */
{
	if(IsTreeEmpty(P))
		return Nil;
	else{
		if(N==1){
			return Alokasi(Akar(P));
		}else{
			return Concat(MakeListLevel(Left(P),N-1), MakeListLevel(Right(P),N-1));
		}
	}
}
   
