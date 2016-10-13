/*  Fadhil Imam Kurnia - 13515146
 *
 *  File	: antrianbank.c
 * 	Tanggal	: 6 Oktober 2016
 *  Keterangan : Praktikum 7 Alstrukdat - Queue
 */

#include <stdio.h>
#include "queue.h"

float AvgElmt (Queue Q)
/* Menghasilkan rata-rata elemen dalam queue Q yang tidak kosong */
{
	int count = 0;
	int i = Head(Q);
	 while (i!=Tail(Q)) {
		count += Q.T[i];
		i++;
		if(i == MaxEl(Q)+1)
			i = 1;
	}
	count += Q.T[i];
	return ((float) count/ (float) NBElmt(Q));
}

int main(){
	int N, t, temp;
	char c = 'x';
	Queue antrian;

	scanf("%d",&N);
	CreateEmpty(&antrian,N);

	while(c!='0'){
		scanf("%c",&c);
		if(c == '1'){
			scanf("%d",&t);
			if(NBElmt(antrian)<MaxEl(antrian))
				Add(&antrian,t);
			else
				printf("Queue penuh\n");
		}else if (c == '2'){
			if(!IsEmpty(antrian))
				Del(&antrian,&temp);
			else
				printf("Queue kosong\n");
		}
	}
	printf("%d\n",NBElmt(antrian));
	if(NBElmt(antrian)!= 0)
		printf("%.2f\n",AvgElmt(antrian));
	else
		printf("Tidak bisa dihitung\n");

	return 0;
}
