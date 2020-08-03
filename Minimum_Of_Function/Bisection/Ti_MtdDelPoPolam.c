// (c) Tivole

#include <stdio.h>
#include <math.h>

#define eps 1.e-15

double f(double);
int find_min(double, double, double (*)(double), double*);

int main(void) {

	double a, b, min_x;

	scanf("%lf%lf", &a, &b);

	if (!find_min(a, b, f, &min_x)) {
		printf("(!) Method is not allowed.\n");
	} else {
		printf("Mininum x of function f is: %lg\n", min_x);
	}

	return 0;
}


double f(double x) {
    return x*x-2*x-3;
}


int find_min(double a, double b, double (*f)(double), double *min_x){
	double c = (a + b)/2, fc = f(c), fa = f(a), fb = f(b), d1, d2, fd1, fd2;

	// Check is method allowed or not.
	if ((fa <= fc) && (fb <= fc)) return 0;
	
	while ((fabs(b - a) > eps) && (fabs(b - a) > eps*fabs(a))) {
		d1 = (a + c)/2;
		d2 = (b + c)/2;

		fd1 = f(d1);
		fd2 = f(d2);
		
		if ((fd1 <= fc) && (fd1 <= fd2)) {
			b = c;
			fb = fc;
			c = d1;
			fc = fd1;
		} else if ((fc <= fd1) && (fc <= fd2)) {
			a = d1;
			b = d2;
			fa = fd1;
			fb = fd2;
		} else if ((fd2 <= fc) && (fd2 <= fd1)) {
			a = c;
			c = d2;
			fa = fc;
			fc = fd2;
		}
	}

	*min_x = c;
	
	return 1;
}
