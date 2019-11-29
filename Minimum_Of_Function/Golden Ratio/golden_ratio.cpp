// (c) Tivole

#include <iostream>
#include <cmath>

using namespace std;

#define eps 1e-9 // accuracy
#define phi 1.618033988749894848204586834365 // Golden Ratio
#define VISUALIZE_RESULT true
#define SAVE_GRAPH false
#define FUNCTION_WITH_STRING "sin(x)"


double f(double);
double golden_ratio_min(double, double, double (*)(double));


int main() {
	
	double a, b, min_x;
    FILE *f_min_xy = fopen("minimum_xy.csv", "w");
    FILE *f_gplot = fopen("visualisation.gpl", "w");

	// scanf("%lf%lf", &a, &b);


    // The main segment
    a = 0;
    b = 10;

    min_x = golden_ratio_min(a, b, f);

    fprintf(f_min_xy, "%lf, %lf", min_x, f(min_x));
    fclose(f_min_xy);

	printf("Mininum x of function f(x) is:\n\nx = %lg\t|\tf(x) = %lg\n\n", min_x, f(min_x));
	

    // Visualisating of results
    if (VISUALIZE_RESULT) {
        fprintf(f_gplot, "#!/usr/bin/gnuplot\n\n");

        if (SAVE_GRAPH) {
            fprintf(f_gplot, "set terminal png size 1920, 1080\n");
            fprintf(f_gplot, "set output 'visualisation.png'\n\n");
        }

        fprintf(f_gplot, "set title \"Golden Ratio Minimum\"\n");
        fprintf(f_gplot, "set xlabel \"x\"\n");
        fprintf(f_gplot, "set ylabel \"y\"\n");
        fprintf(f_gplot, "set xrange [%lf:%lf]\n", a, b);

        fprintf(f_gplot, "plot %s lc rgb '#0000ff' lw 2 lt -1 title '%s', \\\n", FUNCTION_WITH_STRING, FUNCTION_WITH_STRING);
        fprintf(f_gplot, "\t'minimum_xy.csv' with points ls 7 lc rgb '#ff0000' ps 1.6 title 'Minimum'\n");

        fprintf(f_gplot, "pause -1 \"Hit any key to continue\"\n");
        fclose(f_gplot);

        system("gnuplot visualisation.gpl");
    }


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