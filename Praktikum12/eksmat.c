#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"
#include <math.h>
#include <string.h>

void BuildTreeFromString (BinTree *T, char *st, int *idx)
{  
	if(st[*idx]=='\0'){
		*T = Nil;
	}else{
		if(st[*idx]=='-'){
			*T = AlokNode(-1);
			
			(*idx)++;
			if(st[*idx]!='-' && st[*idx]!='+' && st[*idx]!='*' && st[*idx]!='/' && st[*idx]!='^' && st[*idx]!='%')
				Left(*T) = AlokNode(st[*idx]-'0');
			else
				BuildTreeFromString(&Left(*T),st,&(*idx));
				
			(*idx)++;
			if(st[*idx]!='-' && st[*idx]!='+' && st[*idx]!='*' && st[*idx]!='/' && st[*idx]!='^' && st[*idx]!='%')
				Right(*T) = AlokNode(st[*idx]-'0');
			else
				BuildTreeFromString(&Right(*T),st,&(*idx));
		}else if(st[*idx]=='+'){
			*T = AlokNode(-2);
			(*idx)++;
			if(st[*idx]!='-' && st[*idx]!='+' && st[*idx]!='*' && st[*idx]!='/' && st[*idx]!='^' && st[*idx]!='%')
				Left(*T) = AlokNode(st[*idx]-'0');
			else
				BuildTreeFromString(&Left(*T),st,&(*idx));
			(*idx)++;
			if(st[*idx]!='-' && st[*idx]!='+' && st[*idx]!='*' && st[*idx]!='/' && st[*idx]!='^' && st[*idx]!='%')
				Right(*T) = AlokNode(st[*idx]-'0');
			else
				BuildTreeFromString(&Right(*T),st,&(*idx));			
		}else if(st[*idx]=='*'){
			*T = AlokNode(-3);
			(*idx)++;
			if(st[*idx]!='-' && st[*idx]!='+' && st[*idx]!='*' && st[*idx]!='/' && st[*idx]!='^' && st[*idx]!='%')
				Left(*T) = AlokNode(st[*idx]-'0');
			else
				BuildTreeFromString(&Left(*T),st,&(*idx));
			(*idx)++;
			if(st[*idx]!='-' && st[*idx]!='+' && st[*idx]!='*' && st[*idx]!='/' && st[*idx]!='^' && st[*idx]!='%')
				Right(*T) = AlokNode(st[*idx]-'0');
			else
				BuildTreeFromString(&Right(*T),st,&(*idx));			
		}else if(st[*idx]=='/'){
			*T = AlokNode(-4);
			(*idx)++;
			if(st[*idx]!='-' && st[*idx]!='+' && st[*idx]!='*' && st[*idx]!='/' && st[*idx]!='^' && st[*idx]!='%')
				Left(*T) = AlokNode(st[*idx]-'0');
			else
				BuildTreeFromString(&Left(*T),st,&(*idx));
			(*idx)++;
			if(st[*idx]!='-' && st[*idx]!='+' && st[*idx]!='*' && st[*idx]!='/' && st[*idx]!='^' && st[*idx]!='%')
				Right(*T) = AlokNode(st[*idx]-'0');
			else
				BuildTreeFromString(&Right(*T),st,&(*idx));			
		}else if(st[*idx]=='^'){
			*T = AlokNode(-5);
			(*idx)++;
			if(st[*idx]!='-' && st[*idx]!='+' && st[*idx]!='*' && st[*idx]!='/' && st[*idx]!='^' && st[*idx]!='%')
				Left(*T) = AlokNode(st[*idx]-'0');
			else
				BuildTreeFromString(&Left(*T),st,&(*idx));
			(*idx)++;
			if(st[*idx]!='-' && st[*idx]!='+' && st[*idx]!='*' && st[*idx]!='/' && st[*idx]!='^' && st[*idx]!='%')
				Right(*T) = AlokNode(st[*idx]-'0');
			else
				BuildTreeFromString(&Right(*T),st,&(*idx));			
		}else if(st[*idx]=='%'){
			*T = AlokNode(-6);
			(*idx)++;
			if(st[*idx]!='-' && st[*idx]!='+' && st[*idx]!='*' && st[*idx]!='/' && st[*idx]!='^' && st[*idx]!='%')
				Left(*T) = AlokNode(st[*idx]-'0');
			else
				BuildTreeFromString(&Left(*T),st,&(*idx));
			(*idx)++;
			if(st[*idx]!='-' && st[*idx]!='+' && st[*idx]!='*' && st[*idx]!='/' && st[*idx]!='^' && st[*idx]!='%')
				Right(*T) = AlokNode(st[*idx]-'0');
			else
				BuildTreeFromString(&Right(*T),st,&(*idx));			
		}else{
			*T = AlokNode(st[*idx]-'0');
		}			
		
	}
}

void PrintPostfix(BinTree T){
	if(!IsTreeEmpty(T)){
		PrintPostfix(Left(T));
		PrintPostfix(Right(T));
		if(Akar(T) == (-1))
			printf("-");
		else if (Akar(T) == (-2))
			printf("+");
		else if (Akar(T) == (-3))
			printf("*");
		else if (Akar(T) == (-4))
			printf("/");
		else if (Akar(T) == (-5))
			printf("^");
		else if (Akar(T) == (-6))
			printf("%%");
		else
			printf("%d",Akar(T));
		
	}
}

int HitungTree(BinTree T){
	if(IsTreeOneElmt(T))
		return Akar(T);
	else{
		if(Akar(T)==(-1))
			return HitungTree(Left(T)) - HitungTree(Right(T));
		else if (Akar(T) == (-2))
			return HitungTree(Left(T)) + HitungTree(Right(T));
		else if (Akar(T) == (-3))
			return HitungTree(Left(T)) * HitungTree(Right(T));
		else if (Akar(T) == (-4))
			return HitungTree(Left(T)) / HitungTree(Right(T));
		else if (Akar(T) == (-5))
			return (int) pow(HitungTree(Left(T)),HitungTree(Right(T)));
		else //Akar(T) == (-6))
			return HitungTree(Left(T)) % HitungTree(Right(T));
	}
}

int main(){
	BinTree T;
	char c[1000];
	char *S = c;
	int idx =0, i = 0;	
	
	while ((S[i] = (char) getchar()) != EOF && S[i] != '\n' && S[i] != '\r')
		i++;
	S[i] = '\0';
	
	if(strlen(S)==0)
		printf("Ekspresi kosong\n");
	else{
		BuildTreeFromString(&T, S, &idx);
		PrintPostfix(T);
		printf("\n");
		printf("=%d\n",HitungTree(T));
	}
	return 0;
}
