// (c) Tivole

#include <iostream>
#include <cmath>

using namespace std;

#define N 11
#define TEST_N 21
#define FUNCTION_WITH_STRING "sin(x)"


double f(double);
double LP(double*, double*, double, int);


int main()  {

    int i;
    double a, b, step, x;
    double *X = new double[N], *Y = new double[N], *TEST_X = new double[TEST_N], *TEST_Y = new double[TEST_N];
    FILE *f_input_xy = fopen("input_xy.csv", "w");
    FILE *f_gplot = fopen("visualisation.gpl", "w");

    // The main segment
    a = 0;
    b = 1;

    // Calculating values of function in N points for using future in LP.
    step = (b - a) / double(N - 1);
    x = a;
    for (i = 0; i < N; i++, x += step) {
        X[i] = x;
        Y[i] = f(X[i]);
        fprintf(f_input_xy, "%lf, %lf\n", X[i], Y[i]);
    }

    fclose(f_input_xy);

    // Calculating values of LP in TEST_N points
    step = (b - a) / double(TEST_N - 1);
    x = a;
    for (i = 0; i < TEST_N; i++, x += step) {
        TEST_X[i] = x;
        TEST_Y[i] = LP(X, Y, TEST_X[i], N);
        // cout << "(" << TEST_X[i] << ", " << TEST_Y[i] << ")\n";
    }

    // Calculating norm_1, norm_2, norm_3
    double norm_1, norm_2, norm_3;
    norm_1 = abs(TEST_Y[0] - f(TEST_X[0])); // max abs
    norm_2 = abs(TEST_Y[0] - f(TEST_X[0])); // sum abs
    norm_3 = (TEST_Y[0] - f(TEST_X[0]))*(TEST_Y[0] - f(TEST_X[0])); // sqrt of sum of sqr

    for (i = 1; i < TEST_N; i ++) {
        x = abs(TEST_Y[i] - f(TEST_X[i]));
        if (x > norm_1) norm_1 = x;
        norm_2 += x;
        norm_3 += (x*x);
    }
    norm_3 = sqrt(norm_3);


    cout << norm_1 << endl << norm_2 << endl << norm_3 << endl;


    // TODO: visualisation with gnuplot and test with N*10 points (max_delta_abs)
    fprintf(f_gplot, "#!/usr/bin/gnuplot\n\n");
    
    fprintf(f_gplot, "set title \"Lagrange Polynomial\"\n");
    fprintf(f_gplot, "set xlabel \"x\"\n");
    fprintf(f_gplot, "set ylabel \"y\"\n");
    fprintf(f_gplot, "set xrange [%lf:%lf]\n", a, b);
    fprintf(f_gplot, "set yrange [%lf:%lf]\n\n", a, b);

    fprintf(f_gplot, "plot %s%s", FUNCTION_WITH_STRING, ", \\\n");
    fprintf(f_gplot, "\t'input_xy.csv' with points ls 7\n\n");

    fprintf(f_gplot, "pause -1 \"Hit any key to continue\"\n");
    fclose(f_gplot);

    system("gnuplot visualisation.gpl");


    
    return 0; 
}


double LP(double *X, double *Y, double x, int n) {
    double mult, result = 0;
  
    for (int i = 0; i < n; i++) {
        mult = Y[i];
        for (int j = 0; j < n; j++) {
            if (j != i)
                mult *= (x - X[j]) / (X[i] - X[j]);
        }
        result += mult;
    }
  
    return result; 
}


double f(double x) {
    return sin(x);
}