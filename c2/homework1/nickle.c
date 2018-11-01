#include <stdio.h>

int main() {
    int N;
    scanf("%d",&N);
    int coin5;
    int countNum = 0;
    int num5 = N * 20;
    int Num = N * 100;
    for(coin5 = 0;coin5 <= num5;coin5++){
        countNum += ((Num - coin5 * 5)/2 + 1);
    }
    printf("%d",countNum);
    return 0;
}