#include<stdio.h>

long long pow(int a,int b){
	
	long long m = 1;
	int i;
	for(i = 0;i < b;i++){
		m = (long long)a * m;
	}
	return m;
}

int main(){
	FILE *in;
	in = freopen("sigma.in","r",stdin);
	int k,x,m,n;
	char tmp[20] = {0};
	scanf("%d %d %d %d", &k,&x,&m,&n);
	if(x == 1){
		printf("%d",k *(m + n + 1));
		printf(".00000000000000");
	}
	else {
		long long int_part = (pow(x,n+1) - 1) * k/(x - 1);
		double LDK = (double) k;
		double ld = LDK/(double)pow(x,m);
		
		double dou_part = (LDK - ld)/(double)(x - 1);
		
		while(dou_part >=1.0){
			dou_part--;
			int_part++;
		}
		
		printf("%lld",int_part);
		sprintf(tmp,"%.14lf",dou_part);
		puts(tmp+1);
	}
	
}
