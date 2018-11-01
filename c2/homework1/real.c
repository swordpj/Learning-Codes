#include <stdio.h>
#include <string.h>

#define N 25

int main() {
    char c[N];
    FILE *fp;
    fp = fopen("real.in","r");
    fgets(c,N,fp);
    int i;
    short int PNsigns = 0,Delsigns = 0,Esign = 0;
    short int WrongFlag = 0,NormalFlag = 0,ScienceFlag = 0;
    for(i = 0;i < strlen(c) - 1;i++){
        if(c[i] == '+'||c[i] == '-'){
            if((i == 0&&c[1] >= '0'&&c[1] <= '9')||
            (c[i-1] == 'E'&&c[i+1] >= '0'&&c[i+1] <= '9')) PNsigns++;
            else WrongFlag = 1;
        }
        else if(c[i] == 'E'){
            if((!Esign)&&i != 0&&((c[i+1] >= '0'&&c[i+1] <='9') || c[i+1] == '+'||c[i+1] == '-')) {
                ScienceFlag = 1;
                Esign = i;
            }
            else WrongFlag = 1;
        }
        else if(c[i] == '.'){
            Delsigns++;
            if((Esign == 0&&Delsigns == 1&&(c[i+1] >= '0'&&c[i+1] <='9')&&(c[i-1] >= '0'&&c[i-1] <='9')));
            else{
                WrongFlag = 1;
                break;
            }
        }
        else if(c[i] >= '0'&&c[i] <= '9') continue;
        else{
            WrongFlag = 1;
            break;
        }
    }

    fp = fopen("real.out","w");

    if(!WrongFlag){
        if(!Esign) fprintf(fp,"Format1\n");
        else fprintf(fp,"Format2\n");
    }
    else fprintf(fp,"Wrong\n");

    return 0;
}