// (c) Tivole

#include <stdio.h>
#include <math.h>

#define eps 1.e-15

double f(double);
int sgn(double);
double find_root(double, double, double (*)(double), double*);

int main(void) {
	
	double a, b, root_x;

	scanf("%lf%lf", &a, &b);

	if (!find_root(a, b, f, &root_x)) {
		printf("(!) Method is not allowed.\n");
	} else {
		printf("Root x of function f is: %lg\n", root_x);
	}
	
	return 0;
}


double f(double x) {
    return cos(x);
}


int sgn(double x) {
	if (x > 0) return 1;
	else if (x < 0) return -1;
	else return 0;
}


double find_root(double a, double b, double (*f)(double), double *root_x) {
	double fa, fb, sgn_fa, sgn_fb, x, fx, sgn_fx;

	fa = f(a);
	fb = f(b);

	sgn_fa = sgn(fa);
	sgn_fb = sgn(fb);
	
	if (sgn_fa == 0) { 
		*root_x = a;
		return 1;
	} else if (sgn_fb == 0) {
		*root_x = b;
		return 1;
	} else if (sgn_fa == sgn_fb) {
		return 0;
	}

	while ((fabs(b - a) > eps) && (fabs(b - a) > eps*fabs(a))) {
		x = (a + b)/2;
		fx = f(x);
		sgn_fx = sgn(fx);

		if (sgn_fa == sgn_fx) {
			a = x;
		} else if (sgn_fb == sgn_fx) {
			b = x;
		} else {
			break;
		}
	}
	
	*root_x = x;

	return 1;
}