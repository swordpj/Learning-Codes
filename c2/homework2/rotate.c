#include <stdio.h>


int main() {
    int N;
    int i,j,k;
    scanf("%d",&N);
    int Rot[N][N];
    for(i = 0;i < N;i++){
        for(j = 0;j < N;j++){
            Rot[i][j] = 0;
        }
    }
    j = 0;
    k = 0;
    int flag = 1;
    for(i = 0;i < N*N;i++){
        Rot[j][k] = i+1;
        switch(flag%4){
            case 1:{
                k++;
                if(k == N||Rot[j][k]!=0){
                    k--;
                    j++;
                    flag++;
                }
                break;
            }
            case 2:{
                j++;
                if(j == N||Rot[j][k]!=0){
                    j--;
                    k--;
                    flag++;
                }
                break;
            }
            case 3:{
                k--;
                if(k == -1||Rot[j][k]!=0){
                    k++;
                    j--;
                    flag++;
                }
                break;
            }
            default:{
                j--;
                if(j == -1||Rot[j][k]!=0){
                    j++;
                    k++;
                    flag++;
                }
                break;
            }
        }

    }

    for(i = 0;i < N;i++){
        for(j = 0;j < N;j++){
            printf("    %d",Rot[i][j]);
        }
        printf("\n");
    }

    return 0;
}