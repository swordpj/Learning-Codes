#include<stdio.h>

int linenum(int n){
	int i;
	for(i = 0;i < n;i++){
		if(i*(i+1)/2 >= n) return i;
	}
} 

int main(void){
	int n,a,b;
	scanf("%d",&n);
	int line = linenum(n);
	if(line %2 == 0){
		a = line - (line *(line + 1)/2 - n);
		b = line + 1 - a;
	}
	else{
		a = 1 + (line *(line + 1)/2 - n);
		b = line + 1- a;
	}
	
	printf("%d/%d",a,b);
	
	
	return 0;
}
