#include <stdio.h>

int main() {
    int N,i,j,temp;

    scanf("%d",&N);
    int outstack[N];
    for(i = 0;i < N;i++){
        scanf("%d",&outstack[i]);
    }

    for(i = 0;i < N - 1;i++){
        temp = outstack[i];
        for(j = i+1;j < N;j++){
            if(outstack[i] > outstack[j]){
                if(temp > outstack[j]){
                    temp = outstack[j];
                    continue;
                }
                else{
                    printf("NO\n");
                    return 0;
                }
            }
        }
    }
    printf("YES\n");
    return 0;

}