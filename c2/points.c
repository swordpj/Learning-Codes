#include<stdio.h>
#include<math.h>

typedef struct points{
	double x;
	double y;
}points;

double square(double a, double  b, double c){
	double p = (a + b + c)/2;
	double S = sqrt(p * (p - a) * (p - b) * (p - c));
	return S;
}

int main(void){
	int i = 0;
	points p[18];
	while(scanf("%lf %lf",&p[i].x,&p[i].y) != EOF){
		i++;
	}
	int num = i;
	double a,b,c;
	double sumS = 0;
	for(i = 1;i < num - 1;i++){
		a = sqrt((p[0].x - p[i].x)*(p[0].x - p[i].x) + (p[0].y - p[i].y)*(p[0].y - p[i].y));
		b = sqrt((p[0].x - p[i+1].x)*(p[0].x - p[i+1].x) + (p[0].y - p[i+1].y)*(p[0].y - p[i+1].y));
		c = sqrt((p[i].x - p[i+1].x)*(p[i].x - p[i+1].x) + (p[i].y - p[i+1].y)*(p[i].y - p[i+1].y));
		sumS += square(a,b,c);
	}
	printf("%.2lf",sumS);
	
	return 0;
}
