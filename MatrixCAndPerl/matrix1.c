#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

void print_matrix(double **a, int n) {
    int i,j;
    for (i = 0 ; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%f ", a[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n = 5;   
    clock_t t;
    double **a = (double **) malloc(n * sizeof(double));
    double **b = (double **) malloc(n * sizeof(double));
    double **c = (double **) malloc(n * sizeof(double));
    int i,j,k;
    for(i = 0; i < n; i++) {
    	a[i] = (double *)malloc(n * sizeof(double));
	b[i] = (double *)malloc(n * sizeof(double));
	c[i] = (double *)malloc(n * sizeof(double));
    }    
    
    for (i = 0 ; i < n; i++){
        for(j = 0; j < n; j++){
            a[i][j] = rand() % 10;
            b[i][j] = rand() % 10;
        }
    }
//Multiply matrix
    t = clock();
    for (i = 0 ; i < n; i++) {
        for (j = 0; j < n; j++) {
            for(k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    t = clock() - t;
   // printf("Matrix A:\n");
   // print_matrix(a,n);
   // printf("Matrix B:\n");
   // print_matrix(b,n);
    printf("Result matrix C:\n");
    print_matrix(c,n);
    printf ("Elapsed time %e seconds.\n",((double)t)/CLOCKS_PER_SEC);
    free(a);
    free(b);
    free(c);
    return 0;
}
