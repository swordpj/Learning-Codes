#include<stdio.h>
#include<string.h>

int xor(char a,char b){
	if(a == b) return 0;
	else return 1;
}

void gray_to_binary(char str[], int start){
	int i;
	int bin[100];
	for(i = start;i < strlen(str);i++){
		if(i == start){
			bin[i - start] = str[i] - '0';
		}
		else{
			bin[i - start] = xor(str[i],(char)(bin[i - start - 1] + '0'));
		}
	}
	for(i = 0;i < strlen(str) - start;i++){
		printf("%d",bin[i]);
	}
	printf("\n");
}

void binary_to_gray(char str[]){
	int i;
	for(i = 2;i < strlen(str);i++){
		if(i == 2){
			printf("%d",str[i] - '0');
		}
		else{
			printf("%d",xor(str[i - 1],str[i]));
		}
	}
	printf("\n");
}

int main(){
	char ch[100];
	while(scanf("%s",&ch) != EOF){
		if(ch[0] == '-'&&ch[1] == 'g'){
			binary_to_gray(ch);
		}
		else if(ch[0] == '-'&&ch[1] == 'b'){
			gray_to_binary(ch, 2);
		}
		else{
			gray_to_binary(ch, 0);
		}
	}
	
	return 0;
}
