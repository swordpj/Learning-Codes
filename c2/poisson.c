#include<stdio.h>
#include<math.h>

long double m_k(double m, double k)
{
    long double result = 1.0;
    if(k == 0){
        return exp(-1 * m);
    }
    else if(m == 0){
        return 0.0;
    }
    else{
        if(m > k){
            result /= exp(m - k);
        }
        else if(m < k){
            result *= exp(k - m);
        }
        while(k > 0){
            result *= m * 1.0 / k / exp(1);
            k--;
        }
        return result;
    }
}

int main(void){
	double m,k;
	FILE *in;
	FILE *out;
	in = freopen("poisson.in","r",stdin);
	out = freopen("poisson.out","w",stdout);
	
	scanf("%lf %lf",&m,&k);
	long double a = m_k(m,k);
	printf("%.6e\n",(double)a);
	return 0;
}
