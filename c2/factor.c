#include<stdio.h>

#define N 1000
#define MAXLENGTH 50

int a[N];
int digits, carry = 0;

void multi(int num)
{
    int i;
    for(i = 0; i < digits; i++){
        a[i] = a[i] * num + carry;
        carry = a[i] / 10;
        a[i] %= 10;
    }
    while(carry){
        a[i] = carry % 10;
        carry = carry / 10;
        i++;
    }
    digits = i;
}

void print()
{
    int i, count = 0;
    for(i = digits - 1; i >= 0; i--){
        printf("%d", a[i]);
        count++;
        if(count == MAXLENGTH){
            putchar('\n');
            count = 0;
        }
    }
}

int main()
{
    int n, i;
    freopen("factor.in", "r", stdin);
    freopen("factor.out", "w", stdout);
    scanf("%d", &n);

    a[0] = 1;
    digits = 1;

    for(i = 2; i <= n; i++){
        multi(i);
    }
    print();
    return 0;
}
