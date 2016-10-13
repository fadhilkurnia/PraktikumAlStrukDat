/*  Fadhil Imam Kurnia - 13515146
 *
 *  File	: main.c
 * 	Tanggal	: 6 Oktober 2016
 *  Keterangan : Praktikum 7 Alstrukdat - Queue
 */

#include <stdio.h>
#include "prioqueue.h"

int main(){
	Queue Q;
	infotype X;
	printf("Semangat!\n");
	CreateEmpty(&Q,10);
	X.prio = 1;
	X.info = 99;
	Add(&Q,X);
	PrintQueue(Q);
	printf(">>>%d\n", NBElmt(Q));

  X.prio = 1;
	X.info = 100;
	Add(&Q,X);
	PrintQueue(Q);
	printf(">>>%d\n", NBElmt(Q));

  X.prio = 3;
	X.info = 101;
	Add(&Q,X);
	PrintQueue(Q);
	printf(">>>%d\n", NBElmt(Q));

	X.prio = 1;
	X.info = 3;
	Add(&Q,X);
	PrintQueue(Q);
	printf(">>>%d\n", NBElmt(Q));

	X.prio = 2;
	X.info = 5;
	Add(&Q,X);
	PrintQueue(Q);
	printf(">>>%d\n", NBElmt(Q));

  DeAlokasi(&Q);
	return 0;
}
