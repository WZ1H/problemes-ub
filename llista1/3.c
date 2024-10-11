#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#ifndef  M_PI
#define  M_PI  3.1415926535897932384626433
#endif
/*int n;
double result, x;
int sign = -1;

unsigned long long factorial (int m){
    unsigned long long factor = 1;
    int j;
    for (j=2; j<=m; j++)
        factor *= j;
    return factor;
} */


int main(void){
    /*printf("x i n?\n");
    scanf("%lf %d", &x, &n);
    int i;
    for (i=1; i<=n; i+=2){
        sign *= -1;
        result += (double) sign * pow(x, i)/(factorial(i));
        };
    printf("La aprox és %g\n", result); */

    double x, prec;
    int i;
    printf("x, prec\n");
    scanf("%lf %le", &x, &prec);
    static double resultat;
    double x_stripped;
    x_stripped = fmod(x, 2*M_PI);
    resultat = x_stripped;
    static double part_x, part_fac;
    part_x = x_stripped * x_stripped * x_stripped;
    part_fac = 6;
    i = 3;
    double error = fabs(x_stripped - sin(x));
    int termes=1;
    double valor_real = sin(x);
    while (error>prec)
    {
        static int sign=-1;
        resultat += (double) sign * part_x/ part_fac;
        part_x *= x_stripped * x_stripped;
        part_fac *= (i+2)*(i+1);
        sign *= -1;
        i+=2;
        termes += 1;
        error = (double) fabs(resultat - valor_real);
    };
printf("%.15f, el número de térmes és %d\n", resultat, termes);
    return 0;
}