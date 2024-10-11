#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

int main(void){
    int n, i;
    float x0;
    double a, b, h, x, eabs, erel;

    printf("# interval i quantitat de subintervals:");
    printf(" a=? b=? n=? \n");
    scanf("%le %le %d", &a, &b, &n);
    if (n<1 || a>=b) return 1;
    
    printf("# FLT_EPSILON = %+.10E \n\n", FLT_EPSILON);

    h=(b-a)/n;
    printf("#           x double                       x0"
            " float            err_abs      err_rel\n");
    
        x = a+i*h;
    for (i=0; i<=n; i++) {
        x = a+i*h;
        x0 = x;
        eabs = (x0-x);
        if (x != 0)
            erel = eabs/x;
        else 
            erel = 1e+20;
        printf(" %+.18e %+.8e %+.6e %+.6e", x, x0, eabs, erel);
        if (fabs(erel)>FLT_EPSILON) printf(" !!!");
        printf("\n");
    }
    return 0;

}

