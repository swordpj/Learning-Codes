#include <stdio.h>

int isPrime(int a){
    int i;
    for(i = 2;i < 10000&&i < a;i++){
        if(a%i == 0) return 0;
    }
    return 1;
}

int main() {
    int N,i,j,k,m = 0;
    scanf("%d",&N);
    int prime[10000][N];
    prime[0][0] = 2;
    prime[1][0] = 3;
    prime[2][0] = 5;
    prime[3][0] = 7;
    prime[4][0] = -1;
    for(i = 1;i < N;i++){
        for(j = 0;prime[j][i-1] != -1;j++){
            for(k = 1;k < 10;k+=2){
                if(isPrime(10 * prime[j][i-1] + k)){
                    prime[m][i] = 10 * prime[j][i-1] + k;
                    m++;
                }
            }
        }
        prime[m][i] = -1;
        m = 0;
    }

    for(i = 0;prime[i][N-1] != -1;i++){
        printf("%d\n",prime[i][N-1]);
    }
    return 0;
}