// (c) Tivole

#include <stdio.h>
#include <math.h>
#define eps 1.e-15

double znak(double x) {
	if(x>0) return 1;
	else if(x<0) return -1;
	else return 0;
}

double f(double x) {
	return sin(x);
}

double koren(double a, double b, double (*f)(double)) {
	double fa,fb,zfa,zfb;
	fa=f(a); fb=f(b);
	zfa = znak(fa);
	zfb = znak(fb);

	if(zfa == zfb){
		printf("Metod ne primenim");
		return 0;
	}
	
	double c, fc, zfc;
	while((fabs(b - a) > eps) && (fabs(b-a) > eps*fabs(a))) {
		if(fabs(fa) < eps){
			printf("%lf", a);
			return 0;
		}
		if(fabs(fb) < eps){
			printf("%lf", a);
			return 0;
		}
		c = b-((fb*(b-a))/(fb-fa));
		fc = f(c);
		zfc = znak(fc);
		printf("%le\n", c);
		if(fa>fb) {
			if(zfc > 0){
				a = c;
				fa = fc;
			}
			else if(zfc < 0) {
				b = c;
				fb = fc;
			}
			else if(zfc == 0) {
				printf("%le", c);
				return 0;
			}
		}
		else if(fa < fb) {
			if(zfc > 0) {
				b = c;
				fb = fc;
			}
			else if(zfc < 0) {
				a = c;
				fa = fc;
			} else if(zfc == 0) {
				printf("%le", c);
				return 0;
			}
		}
	}
	return 0;
}

int main(void){

	double a,b;
	scanf("%le%le", &a,&b);
	koren(a,b,f);

	return 0;
}
