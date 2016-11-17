#include "prioqueue.h"
#include <stdio.h>

int main(){
	int N,T,I,M,D, i=0;
	int currentTime=0;
	infotype siswa,X;
	PrioQueue antrian;

	CreateEmpty(&antrian);
	scanf("%d",&N);
	while(i<N){
		scanf("%d %d %d %d",&T,&I,&M,&D);
		siswa.tKedatangan = T;
		siswa.id = I;
		siswa.nMat = M;
		siswa.dLayanan = D;
		
		
		//menambah ke dalam proses
		while(!IsEmpty(antrian) && currentTime < siswa.tKedatangan){
			Del(&antrian, &X);
			printf("%d %d %d\n", currentTime, X.id, currentTime - X.tKedatangan);
			currentTime += X.dLayanan;
		}	
		
		//menambah kedalam antrian
		Add(&antrian,siswa);
		
		if(currentTime < siswa.tKedatangan)
			currentTime = siswa.tKedatangan;
			
		i++;
	}
	
	//menghabiskan antrian
	while(!IsEmpty(antrian)){
			Del(&antrian, &X);
			printf("%d %d %d\n", currentTime, X.id, currentTime - X.tKedatangan);
			currentTime += X.dLayanan;
	}	

	if(N==0)
		printf("Tidak ada layanan\n");

	return 0;
}
