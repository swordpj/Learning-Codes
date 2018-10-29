#include<stdio.h>

typedef struct sortnum{
	int input_num;
	int input_place;
	int sort_place;
}sortnum;

int cmp1(const void *a, const void *b){
	return ((*(sortnum *)a).input_num > (*(sortnum *)b).input_num)? 1:-1;
}

int cmp2(const void *a, const void *b){
	return ((*(sortnum *)a).input_place - (*(sortnum *)b).input_place);
}

int main(){
	char c = ' ';
	int i = 0,j = 0;
	sortnum a[200001];
	while(scanf("%d",&a[i].input_num) != EOF){
		i++;
		a[i].input_place = i;
	}
	int num = i;
	qsort(a,num,sizeof(sortnum),cmp1);
	j = 1;
	for(i = 0;i < num;i++){
		a[i].sort_place = j;
		if(i != num-1){
			if(a[i].input_num == a[i+1].input_num);
			else j++;
		}
	}
	qsort(a,num,sizeof(sortnum),cmp2);
	for(i = 0;i < num;i++){
		printf("%d ",a[i].sort_place);
	}
}
