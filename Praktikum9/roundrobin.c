#include "listsirkuler.h"
#include <stdio.h>

void DeleteRR (List *L, infotype TQ)
/* Jika L tidak kosong, "menghapus" elemen terakhir list L, misal last, sesuai aturan round robin, yaitu:
- jika Info(last)>TQ, maka last "diantrikan" kembali sebagai first elemen dengan Info(last)=Info(last)-TQ
- jika Info(last)<=TQ, maka DeleteLast(L,X) dan menampilkan X ke layar */
/* Jika L kosong, cetak "List kosong" */
/* I.S. TQ terdefinisi sebagai nilai time slice pemrosesan.
L terdefinisi, mungkin kosong. */
/* F.S. Elemen terakhir L diproses sesuai aturan round-robin.
L mungkin menjadi kosong. */
{
	address P;
	
	if(!IsEmpty(*L)){
		P = First(*L);
		while(Next(P)!=First(*L)){
			P = Next(P);
		}// P is last element
		if(Info(P)>TQ){
			Info(P)=Info(P)-TQ;
			printf("%d\n",TQ);
			First(*L)=P;
		}else{
			DelLast(&(*L),&P);
			printf("%d\n",Info(P));
			Dealokasi(P);
		}
	}else{
		printf("List kosong\n");
	}
}

float Average (List L)
/* Menghasilkan nilai rata-rata elemen L. L tidak kosong. */
{
	infotype sum=0;
	int count =0;
	address P = First(L);
	sum += Info(P);
	count++;
	P=Next(P);
	while(P!=First(L)){
		sum += Info(P);
		count++;
		P = Next(P);
	}
	return (float) sum / (float) count;
}

int main(){
	int q,t;
	char c;
	List L;
	
	CreateEmpty(&L);
	scanf("%d",&q);
	while(q<=0){
		scanf("%d",&q);
	}
	
	scanf("\n%c",&c);
	while(c!='F'){
		if(c == 'A'){
			scanf("%d",&t);
			if(t>0)
				InsVFirst(&L,t);
		}else if(c == 'D'){
			DeleteRR(&L,q);
		}else{
			printf("Kode salah\n");
		}
		scanf("\n%c",&c);
	}
	
	if(!IsEmpty(L)){
		printf("%.2f\n",Average(L));
	}else
		printf("Proses selesai\n");
	return 0;
}
