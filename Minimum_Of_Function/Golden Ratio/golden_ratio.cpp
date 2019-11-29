// (c) Tivole

#include <iostream>
#include <cmath>

using namespace std;

#define eps 1e-9 // accuracy
#define phi 1.618033988749894848204586834365 // Golden Ratio


double f(double);
double golden_ratio_min(double, double, double (*)(double))


int main() {
	
	double a, b, min_x;

	// scanf("%lf%lf", &a, &b);

    a = 0;
    b = 10;

    min_x = golden_ratio_min(a, b, f);

	printf("Mininum x of function f(x) is:\nx = %lg\t|\tf(x) = %lg\n", min_x, f(min_x));
	
    return 0;
}


double f(double x) {
	return sin(x);
}


double golden_ratio_min(double a, double b, double (*f)(double)) {
    
    double x1, x2, fx1, fx2;
    
    x1 = b - (b - a) / phi; 
	x2 = a + (b - a) / phi;
    fx1 = f(x1);
    fx2 = f(x2);

    while (fabs(b - a) > eps) {
        if (fx1 >= fx2) {
            a = x1;
            x1 = x2;
            fx1 = fx2;
            x2 = a + (b - a) / phi;
            fx2 = f(x2);
        } else {
            b = x2;
            x2 = x1;
            fx2 = fx1;
            x1 = b - (b - a) / phi; 
            fx1 = f(x1);
        }
	}

    return (a + b) / 2.0;
}