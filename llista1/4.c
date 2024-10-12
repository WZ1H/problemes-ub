#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double polinomi(double x, int n, double *llista);
double derivada(double x, int n, double *llista);
double arrel(double x, int n, double *llista, double precisio);

int main(void){
int i, n;
double *llista;
double max;
double rang1, rang2;
double pas;
double precisio, posicio;

printf("Grau max, pas i precisio? \n");
scanf("%d %lf %lf", &n, &pas, &precisio);
llista = malloc(n*sizeof(double));

for (i=0; i<=n; i++){
    printf("Valor de a%d\n",i);
    scanf("%lf", llista+i);
}

max = 1;
for (i=1; i<=n; i++)
{
    if (llista[n-i]/llista[n]>max) (max = llista[n-i]/llista[n]);
}
rang1 = -max -1;
rang2 = max +1;
posicio = rang1;

while (posicio < rang2){
    if (polinomi(posicio, n, llista) * polinomi(posicio+pas, n, llista)<0){
        printf("%e\n", arrel(posicio,n,llista, precisio));
    }
    posicio += pas;
}

free(llista);
return 0;
}

double polinomi(double x, int n, double *llista){
    /* Puedo inicializar dentro de funciones? */
int i;
double valor=llista[n]*x+llista[n-1];
for (i = 2; i <= n; i++)
{
    valor = valor * x + llista[n-i];
}
return valor;

}

double derivada(double x, int n, double *llista){
    int i;
    double valor = n*llista[n]*x+(n-1)*llista[n-1];
    for (i = 2; i < n; i++){
    valor = valor * x + llista[n-i]*(n-i);
    }
    return valor;
}

/* puedo usar variables globales para no tener que pasar n y llista siempre? */
double arrel(double x, int n, double *llista, double precisio){
    double valor = x;
    double anterior_valor=valor;
    valor = valor - polinomi(valor,n,llista)/derivada(valor,n,llista);
    while (fabs(valor - anterior_valor)>precisio){
    anterior_valor=valor;
    valor = valor - polinomi(valor,n,llista)/derivada(valor,n,llista);
    }
    return valor;

}
