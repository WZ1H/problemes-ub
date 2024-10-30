#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double f(double);

int main(void){
    double a, b, valor, h;
    int n;
    printf("a, b, n?");
    scanf("%lf %lf %lf",&a,&b,&n);
    h = (b-a)/n;
    valor = 


}

double f(double x){
    return log(x)*log(x-1);
}