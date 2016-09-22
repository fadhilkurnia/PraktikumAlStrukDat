#include <stdio.h>

int main(){
	//KAMUS
		int a,b,c;
	
	//ALGORITMA
		scanf("%d\n%d\n%d",&a, &b, &c);
		if ((a>=b)&&(a>=c)){
			printf("%d\n", a);
		}else if((b>=a)&&(b>=c)){
			printf("%d\n", b);
		}else{
			printf("%d\n", c);
		}
		
		return 0;
}
