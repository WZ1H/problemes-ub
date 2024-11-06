#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(void){
double **A;
int n, i, j;
FILE *in, *out;
in = fopen("matrius.in", "r");
if (in == NULL){
    printf("Problema fichero input\n");
    exit(1);
}
out = fopen("matrius.out", "w");
fscanf(in,"%d", &n);
    A = (double**) malloc(n*sizeof(double*));
    for (i=0; i<n; i++){
        A[i] = malloc(n*sizeof(double));
    }
    for (i=0; i<n; i++){
        for (j=0; j<n; j++){
            fscanf(in, "%lf", (*(A+i)+j));
        }
    }



for (i=0; i<n; i++){
    for (j=0; j<n; j++){
    fprintf(out, "%.16e ", *(*(A+i)+j));
    }
    fprintf(out, "\n");
}
fprintf(out, "Esto es una matriz jaja.");

for (i=0; i<n; i++){
    for (j=0; j<n; j++){
        printf("%f ", A[i][j]);
    }
    printf("\n");


}
for (i=0; i<n; i++){
    free(A[i]);
}
free(A);
fclose(in);
fclose(out);

return 0;
}