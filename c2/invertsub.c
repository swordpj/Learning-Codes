#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define LEN 53

int StringMatcher(char *a,char *b){
    int i = 0;
    int j = 0;
    for(i = 0;i < strlen(a);i++){
        for(j = i;j < strlen(a);j++){
            if(a[j] == b[j - i]){
                if(j - i + 2 == strlen(b)){
                    return i;
                }
            }
            else if(a[j] != b[j - i]) break;
        }
    }
    return -1;
}

int main() {
    char str[LEN];
    char tmp[LEN];
    int i = 0;
    int flagpoint = 0;

    FILE *fp;
    fp = fopen("invertsub.in","r");

    fgets(str,LEN,fp);
    fgets(tmp,LEN,fp);

    if((flagpoint = StringMatcher(str,tmp)) != -1){
        for(i = 0;i < strlen(tmp) - 1;i++){
            str[flagpoint + i] = tmp[strlen(tmp) - 2 - i];
        }
        fp = fopen("invertsub.out","w");
        fputs(str,fp);
    }
    return 0;
}
