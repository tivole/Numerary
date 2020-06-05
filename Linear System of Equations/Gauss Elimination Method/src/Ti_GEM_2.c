// (c) Tivole

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void VandermondeMatrix(double **, int);
void HilbertMatrix(double **, int);
void HilbertMatrixPlusE(double **, int);
void ZeroingTheCornerOfMatrix(double **, int, int, int);
void GaussMethod(double **, double *, double *, int);

int main(int argc, char const *argv[]) {
  int i, j, n, length;
  double errorNorm1, errorNorm2, errorNorm3, discrNorm1, discrNorm2, discrNorm3, clockTimer, m, **A = NULL, *y = NULL, *x1 = NULL, *y1 = NULL, *x2 = NULL, *y2 = NULL;
  n = 0;
  length = strlen(argv[1]);
  for(i = length - 1; i >= 0; i--) {
    n += ((int)argv[1][i] - 48) * (int) pow(10, length - 1 - i);
  }

  srand(time(NULL));

  y2 = (double*)malloc(n * sizeof(double));
  x2 = (double*)malloc(n * sizeof(double));
  y1 = (double*)malloc(n * sizeof(double));
  x1 = (double*)malloc(n * sizeof(double));
  y  = (double*)malloc(n * sizeof(double));
  A  = (double**)malloc(n * sizeof(double*));
  for(i = 0; i < n; i++) A[i] = (double*)malloc(n * sizeof(double));

  // HilbertMatrix(A, n);
  VandermondeMatrix(A, n);
  // HilbertMatrixPlusE(A, n);
  // ZeroingTheCornerOfMatrix(A, 3, 500, n);

  for(i = 0; i < n; i++) {
    x1[i] = rand() % 10;
    // x1[i] = 1;
    y2[i] = 0;
    y1[i] = 0;
    y[i]  = 0;
  }

  for(i = 0; i < n; i++) {
    for(j = 0; j < n; j++) {
      y1[i] += A[j][i] * x1[j];
    }
    y[i] = y1[i];
  }

  clockTimer = clock();
  GaussMethod(A, y, x2, n);
  clockTimer = clock() - clockTimer;
  clockTimer /= CLOCKS_PER_SEC;
  free(y);

  // HilbertMatrix(A, n);
  VandermondeMatrix(A, n);
  // HilbertMatrixPlusE(A, n);
  // ZeroingTheCornerOfMatrix(A, 3, 500, n);

  for(i = 0; i < n; i++)
  	for(j = 0; j < n; j++)
  		y2[i] += A[j][i] * x2[j];

  /* --- Норма погрешности --- */

  m = fabs(x2[0] - x1[0]);
  errorNorm1 = m;
  errorNorm2 = m;
  errorNorm3 = m*m;
  for(i = 1; i < n; i++) {
  	m = fabs(x2[i] - x1[i]);
  	errorNorm2 += m;
  	errorNorm3 += m*m;
  	if(m > errorNorm1)
  		errorNorm1 = m;
  }
  errorNorm3 = sqrt(errorNorm3);

  /* --- Норма невязки --- */

  m = fabs(y2[0] - y1[0]);
  discrNorm1 = m;
  discrNorm2 = m;
  discrNorm3 = m*m;
  for(i = 1; i < n; i++) {
  	m = fabs(y2[i] - y1[i]);
  	discrNorm2 += m;
  	discrNorm3 += m*m;
  	if(m > discrNorm1)
  		discrNorm1 = m;
  }
  discrNorm3 = sqrt(discrNorm3);

  printf("\nN = %d\n", n);
  printf("\nError Norm1 = %le", errorNorm1);
  printf("\nError Norm2 = %le", errorNorm2);
  printf("\nError Norm3 = %le\n", errorNorm3);
  printf("\nDiscrepancy Norm1 = %le", discrNorm1);
  printf("\nDiscrepancy Norm2 = %le", discrNorm2);
  printf("\nDiscrepancy Norm3 = %le\n", discrNorm3);
  printf("\nOperating time Gauss method = %lf\n", clockTimer);

  free(x1);
  free(x2);
  free(y1);
  free(y2);
  for(i = 0; i < n; i++) free(A[i]);
  free(A);

  return 0;
}

void VandermondeMatrix(double **A, int n) {
  int i, j;
  double *x = NULL;
  x = (double*)malloc(n * sizeof(double));
  for(i = 0; i < n; i++)
      x[i] = (double) i / (n - 1);
  for(i = 0; i < n; i++) {
    for(j = 0; j < n; j++) {
      if(j == 0) A[j][i] = 1.0;
      else A[j][i] = pow(x[i], j);
    }
  }
}

void HilbertMatrix(double **A, int n) {
  int i, j;
  for(i = 0; i < n; i++)
    for(j = 0; j < n; j++)
      A[j][i] = (double) 1 / (i + j + 1);
  return;
}

void HilbertMatrixPlusE(double **A, int n) {
  int i, j;
  for(i = 0; i < n; i++)
    for(j = 0; j < n; j++) {
      A[j][i] = (double) 1 / (i + j + 1);
      if(i == j) A[j][i] += 1;
    }
  return;
}

void ZeroingTheCornerOfMatrix(double **A, int corner, int h, int n) {
  int i, j;
  for(i = 0; i < n; i++) {
    for(j = 0; j < n; j++) {
      if((i <= (h - 1 - j)) && (corner == 1))  A[j][i] = 0;
      else if((j >= (n - h + i)) && (corner == 2))  A[j][i] = 0;
      else if((i >= (n - h + j)) && (corner == 3))  A[j][i] = 0;
      else if(((i + j) >= (2*n - h - 1)) && (corner == 4))  A[j][i] = 0;
    }
  }
  return;
}

void GaussMethod(double **a, double *y, double *x, int n) {
  double maxElement, temp1, *temp2;
  int i, j, k, indexI, indexJ;
  for(k = 0; k < n; k++) {
    maxElement = fabs(a[k][k]);
    indexI = k;
    indexJ = k;
    for (i = k; i < n; i++)
      for(j = k; j < n; j++) {
        if (fabs(a[j][i]) > maxElement) {
          maxElement = fabs(a[j][i]);
          indexI = i;
          indexJ = j;
        }
      }

    for(i = 0; i < n; i++) {
      temp1 = a[i][k];
      a[i][k] = a[i][indexI];
      a[i][indexI] = temp1;
    }

    temp2 = a[k];
    a[k] = a[indexJ];
    a[indexJ] = temp2;

    temp1 = y[k];
    y[k] = y[indexI];
    y[indexI] = temp1;

    temp1 = x[k];
    x[k] = x[indexJ];
    x[indexJ] = temp1;

    temp1 = a[k][k];
    for (j = k; j < n; j++)
      a[j][k] = a[j][k] / temp1;
    y[k] = y[k] / temp1;
    for (i = (k + 1); i < n; i++) {
      temp1 = a[k][i];
      for(j = k; j < n; j++)
        a[j][i] = a[j][i] - (temp1 * a[j][k]);
      y[i] = y[i] - temp1 * y[k];
    }
  }

  for (k = n - 1; k >= 0; k--) {
    x[k] = y[k];
    for (i = 0; i < k; i++)
      y[i] = y[i] - a[k][i] * x[k];
  }
  return;
}
