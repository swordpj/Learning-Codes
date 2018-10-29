#include<stdio.h>
#include<string.h>

typedef struct poly{
	int coef;
	int index;
}poly;

int isNum(char a){
	return (a >='0'&&a <='9');
}

int isOp(char a){
	return(a == '-'||a == '+');
}

int isx(char a){
	return a == 'x';
}

int main(){
	FILE *in;
	in = fopen("poly.in","r");
	char line[1024];
	char token[32];
	fgets(line,1024,in);
	int i,j = 0;
	for(i = 0;i < strlen(line);i++){
		if(isNum(line[i])){
			token[j] = line[i];
			j++;
			token[j] = '\0';
		}
		else if(isOp(line[i])){
			
		}
		else if(isx(line[i])){
			
		}
		else{
			
		}
	}
	printf("%s",token); 
	
	return 0;
}
