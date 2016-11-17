#include <stdio.h>
#include "stacklist.h"
#include "boolean.h"

int main(){
	Stack data;
	char c;
	int x;
	boolean fail = false;
	
	CreateEmpty(&data);
	Push(&data,9);
	scanf("%c",&c);
	while(c!='\n' && !fail){
		if(c=='{'){
			Push(&data,1);
		}else if(c=='}'){
			if(InfoTop(data)==9)
				fail = true;
			else
				Pop(&data,&x);
		}
		scanf("%c",&c);
	}
	
	if(fail || InfoTop(data)!=9)
		printf("salah\n");
	else
		printf("ok\n");
		
	return 0;
}
