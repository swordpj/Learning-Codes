#include <stdio.h>

#define NUM 60000

int prime[30001];
short int isPrime[NUM + 3];

void CalPrime(int N){
    int i,j;
    isPrime[0] = 0;
    isPrime[1] = 0;
    for(i = 2;i <= N;i++){
        isPrime[i] = 1;
    }

    for(i = 2;i <= N;i++){
        if(isPrime[i] == 1){
            for(j = i + i;j <= N;j+=i){
                isPrime[j] = 0;
            }
        }
    }
    j = 0;
    for(i = 0;i <= N;i++){
        if(isPrime[i] == 1) prime[j++] = i;
    }
}

int count(int N,int n){
    int num = 0;
    while(N){
        num+=N/n;
        N/=n;
    }

    return num;
}

int main() {
    int N,i,j;
    scanf("%d",&N);
    int Factor[30001];
    for(i = 0;i <= N;i++){
        Factor[i] = 0;
    }
    CalPrime(N);

    for(i =0;prime[i] != 0;i++){
        Factor[i] = count(N,prime[i]);
        if(Factor[i] == 1){
            printf("%d",prime[i]);
        }
        else if(Factor[i] >= 2){
            printf("%d^%d",prime[i],Factor[i]);
        }
        if(prime[i+1] != 0){
            printf("*");
        }
        else{
            printf("\n");
        }
    }

    return 0;
}