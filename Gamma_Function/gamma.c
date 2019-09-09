#include <stdio.h>
#include <math.h>
#define eps 1e-12


double incgamma (double x, double a){
	double term=1.0/a, sum = 0;
	int n=1;
	while (term > eps) {
		sum = sum + term;
		term = term*(x/(a+n));
		n++;
	}
	printf("\nn = {%d}\n", n);
	return pow(x,a)*exp(-1*x)*sum;
}

int main() {
	
	int n;
	scanf("%d", &n);
	printf("%.15lf\n", incgamma(1, (double) n) - incgamma(0, (double) n)); 
	
	return main();
}
