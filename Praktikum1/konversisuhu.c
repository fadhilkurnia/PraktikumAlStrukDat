//konversisuhu.c
#include <stdio.h>

int main(){
	//KAMUS
		float T;
		char jenis;
		float hasil;
		
	//ALGORITMA
		scanf("%f\n%c",&T,&jenis);
		switch (jenis){
			case 'R':	{hasil = (4/5 * T);
						break;}
			case 'F': 	{hasil = (9/5* T)+32;
						break;}
			case 'K':	{hasil = T + 273.15;
						break;}
			
		};
		printf("%.2f\n", hasil);
		return 0;
}
