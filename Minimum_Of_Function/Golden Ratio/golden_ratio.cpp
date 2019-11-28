// (c) Tivole

#include <iostream>
#include <cmath>

using namespace std;

#define eps 1e-9 // accuracy
#define phi 1.618033988749894848204586834365 // Golden Ratio


double f(double);
 
 
int main() {
	double a, b, x1, x2, fx1, fx2;
	
    a = 0;
    b = 10;

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
	
    cout << "(" << (a + b) / 2 << ", " << f((a + b) / 2) << ")"; 
	
    return 0;
}


double f(double x) {
	return sin(x);
}