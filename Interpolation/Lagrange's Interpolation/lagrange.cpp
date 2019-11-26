// (c) Tivole

#include <iostream>
#include <cmath>

using namespace std;

#define N 11
#define TEST_N 31
#define FUNCTION_WITH_STRING "sin(x)"
#define SAVE_GRAPH false


double f(double);
double LP(double*, double*, double, int);


int main()  {

    int i;
    double a, b, step, x, min_y, max_y;
    double *X = new double[N], *Y = new double[N], *TEST_X = new double[TEST_N], *TEST_Y = new double[TEST_N];
    FILE *f_input_xy = fopen("input_xy.csv", "w");
    FILE *f_lagrange_xy = fopen("lagrange_xy.csv", "w");
    FILE *f_gplot = fopen("visualisation.gpl", "w");


    // The main segment
    a = 0;
    b = 10;


    // Calculating values of function in N points for using future in LP.
    step = (b - a) / double(N - 1);
    x = a;
    min_y = f(a);
    max_y = f(a);
    for (i = 0; i < N; i++, x += step) {
        X[i] = x;
        Y[i] = f(X[i]);

        if (min_y > Y[i]) min_y = Y[i];
        if (max_y < Y[i]) max_y = Y[i];

        fprintf(f_input_xy, "%lf, %lf\n", X[i], Y[i]);
    }
    fclose(f_input_xy);


    // Calculating values of LP in TEST_N points
    step = (b - a) / double(TEST_N - 1);
    x = a;
    for (i = 0; i < TEST_N; i++, x += step) {
        TEST_X[i] = x;
        TEST_Y[i] = LP(X, Y, TEST_X[i], N);
        fprintf(f_lagrange_xy, "%lf, %lf\n", TEST_X[i], TEST_Y[i]);
        // cout << "(" << TEST_X[i] << ", " << TEST_Y[i] << ")\n";
    }
    fclose(f_lagrange_xy);


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


    // Printing results
    cout << norm_1 << endl << norm_2 << endl << norm_3 << endl;


    // Visualisating of results
    fprintf(f_gplot, "#!/usr/bin/gnuplot\n\n");
    
    if (SAVE_GRAPH) {
        fprintf(f_gplot, "set terminal png size 1920, 1080\n");
        fprintf(f_gplot, "set output 'visualisation.png'\n\n");
    }

    fprintf(f_gplot, "set title \"Lagrange Polynomial\"\n");
    fprintf(f_gplot, "set xlabel \"x\"\n");
    fprintf(f_gplot, "set ylabel \"y\"\n");
    fprintf(f_gplot, "set xrange [%lf:%lf]\n", a, b);
    fprintf(f_gplot, "set yrange [%lf:%lf]\n\n", min_y, max_y);

    fprintf(f_gplot, "plot %s lc rgb '#0000ff' lw 2 lt -1 title '%s', \\\n", FUNCTION_WITH_STRING, FUNCTION_WITH_STRING);
    fprintf(f_gplot, "\t'lagrange_xy.csv' with linespoints ls 7 lc rgb '#ff0000' lw 1.2 dt 2 title 'Lagrange Polynom', \\\n");
    fprintf(f_gplot, "\t'input_xy.csv' with points ls 7 lc rgb '#00ff00' ps 1.3 title 'Input Values'\n\n");
    
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