// (c) Tivole

#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;


#define N 101
#define eps 1e-1
#define VISUALIZE true
#define SAVE_GRAPH true


double *linear_regression(double*, double*, int);
double get_rand(double min_val, double max_val) {
    return (max_val - min_val) * ( (double)rand() / (double)RAND_MAX ) + min_val;
}

int main() {

    int i;
    double a, b, k, c, step, x, *X = new double[N], *Y = new double[N], *predicted_kc = new double[2];
    FILE *f_input_xy = fopen("input_xy.csv", "w");
    FILE *f_gplot = fopen("visualisation.gpl", "w");
    
    srand(time(NULL));

    // k*x + c
    k = get_rand(0, 10);
    c = get_rand(0, 10);
    
    // segment [a, b]
    a = 0;
    b = 1;

    step = (b - a) / double(N - 1);
    for (i = 0; i < N; i++, x += step) {
        X[i] = rand() % 2 == 0 ? x + eps: x - eps;
        Y[i] = rand() % 2 == 0 ? (k * X[i] + c) + eps * get_rand(1, 3) : (k * X[i] + c) - eps * get_rand(1, 3);
        // cout << "X[" << i << "] = " << X[i] << "\tY[" << i << "] = " << Y[i] << endl;
    }

    predicted_kc = linear_regression(X, Y, N);

    if (VISUALIZE) {
        for (i = 0; i < N; i ++) fprintf(f_input_xy, "%lf, %lf\n", X[i], Y[i]);
        fclose(f_input_xy);

        fprintf(f_gplot, "#!/usr/bin/gnuplot\n\n");

        fprintf(f_gplot, "set title \"Linear Regression\"\n");
        fprintf(f_gplot, "set xlabel \"x\"\n");
        fprintf(f_gplot, "set ylabel \"y\"\n");
        fprintf(f_gplot, "set xrange [%lf:%lf]\n\n", a, b);

        fprintf(f_gplot, "set for [i=1:3] linetype i dt i\n\n");

        if (SAVE_GRAPH) {
            fprintf(f_gplot, "set term pngcairo dashed\n");
            fprintf(f_gplot, "set output 'visualisation.png'\n\n");
        }

        fprintf(f_gplot, "plot (x*%lf + %lf) ls 1 lc rgb '#00bb00' lw 1.4 title 'x*%lf + %lf',\\\n", predicted_kc[1], predicted_kc[0], predicted_kc[1], predicted_kc[0]);
        fprintf(f_gplot, "\t(x*%lf + %lf) ls 2 lc rgb '#0000ff' lw 1.4 title 'x*%lf + %lf',\\\n", k, c, k, c);
        fprintf(f_gplot, "\t'input_xy.csv' with points ls 7 lc rgb '#ff0000' ps 1 title 'Input Values'\n\n");

        fprintf(f_gplot, "pause -1 \"Hit any key to continue\"\n");

        fclose(f_gplot);

        system("gnuplot visualisation.gpl");
    }

    return 0;
}


double *linear_regression(double *X, double *Y, int n) {
    int i;
    double E_X = 0, E_Y = 0, E_XY = 0, E_X2 = 0, *ab = new double[2];

    for (i = 0; i < n; i++) {
        E_X     += X[i];
        E_X2    += (X[i]*X[i]);
        E_Y     += Y[i];
        E_XY    += (X[i]*Y[i]);
    }

    ab[1] = (n*E_XY - E_X*E_Y) / (n*E_X2 - E_X*E_X);
    ab[0] = (E_Y - ab[1]*E_X) / ((double) n);
    
    return ab;
}