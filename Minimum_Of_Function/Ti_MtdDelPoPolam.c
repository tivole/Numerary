// (c) Tivole

#include <stdio.h>
#include <math.h>
#define eps 1.e-15
double f(double x){
    return x*x-2*x-3;
}
double min(double a, double b, double (*f)(double)){
	double c=(a+b)/2;
	double fc=f(c);
	double fa=f(a);
	double fb=f(b);
	double d1,d2,fd1,fd2;
	if((fa<=fc)&&(fb<=fc)){
		printf("Metod ne primenim");
		return 0;
	}
	while((fabs(b-a)>eps) && (fabs(b-a)>eps*fabs(a))){
		d1=(a+c)/2;
		d2=(b+c)/2;
		fd1=f(d1);
		fd2=f(d2);
		if((fd1<=fc) && (fd1<=fd2)){
			b=c; c=d1; fc=fd1; fb=fc;
		}
		else if((fc<=fd1) && (fc<=fd2)){
			a=d1; b=d2; fa=fd1; fb=fd2;
		}
		else if((fd2<=fc) && (fd2<=fd1)){
			a=c; c=d2; fa=fc; fc=fd2;
		}
	}
	printf("%le", c);
	return 0;
}
int main(void){
	double a,b;
	scanf("%le%le", &a,&b);
	min(a,b,f);
	return 0;
}