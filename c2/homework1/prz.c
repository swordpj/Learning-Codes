
#include <stdio.h>
#include <stdlib.h>

typedef struct przs{
    int start,end;
}Przs;

int cmp(const void *a,const void *b){
    return ( (*(Przs*)a).start - (*(Przs*)b).start );
}

int main() {
    freopen("prz.in","r",stdin);
    freopen("prz.out","w",stdout);
    Przs ps[50001];
    int i = 0,j = 0,num;
    while(scanf("%d %d", &ps[i].start, &ps[i].end) != EOF) i++;
    num = i;
    qsort(ps,num, sizeof(Przs),cmp);
    int left = ps[0].start;
    int right = ps[0].end;
    for(i = 1;i < num+1;i++){
        if(right < ps[i].start||i==num){
            printf("%d %d\n",left,right);
            left = ps[i].start;
            right = ps[i].end;
        }
        else if(right <= ps[i].end) right = ps[i].end;
    }
    return 0;
}