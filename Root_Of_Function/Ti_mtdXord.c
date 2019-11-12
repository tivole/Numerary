// (c) Tivole

#include <stdio.h>
#include <math.h>

#define eps 1.e-15

double sgn(double);
double f(double);
double find_root(double, double, double (*)(double), double*);


int main(void){

	double a, b, root_x;

	scanf("%lf%lf", &a, &b);
	
	if (!find_root(a, b, f, &root_x)) {
		printf("(!) Method is not allowed.\n");
	} else {
		printf("Root x of function f is: %lg\n", root_x);
	}

	return 0;
}


double sgn(double x) {
	if (x > 0) return 1;
	else if (x < 0) return -1;
	else return 0;
}


double f(double x) {
	return sin(x);
}


double find_root(double a, double b, double (*f)(double), double *root_x) {
	double fa, fb, sgn_fa, sgn_fb, c, fc, sgn_fc;
	
	fa = f(a);
	fb = f(b);
	
	sgn_fa = sgn(fa);
	sgn_fb = sgn(fb);

	if (sgn_fa == sgn_fb) return 0;
	
	while ((fabs(b - a) > eps) && (fabs(b - a) > eps*fabs(a))) {
		if (fabs(fa) < eps) {
			*root_x = a;
			return 1;
		} else if (fabs(fb) < eps) {
			*root_x = b;
			return 1;
		}
		
		c = b - (fb*(b - a)) / (fb - fa);
		fc = f(c);
		sgn_fc = sgn(fc);

		if (fa > fb) {
			if (sgn_fc > 0){
				a = c;
				fa = fc;
			} else if (sgn_fc < 0) {
				b = c;
				fb = fc;
			} else if (sgn_fc == 0) {
				*root_x = c;
				return 1;
			}
		} else if (fa < fb) {
			if (sgn_fc > 0) {
				b = c;
				fb = fc;
			} else if (sgn_fc < 0) {
				a = c;
				fa = fc;
			} else if (sgn_fc == 0) {
				*root_x = c;
				return 1;
			}
		}
	}

	return 0;
}