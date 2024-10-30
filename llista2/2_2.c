#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int invertir(int *);

int main(void){
    int numero;
    int *vecnumero = (int *)malloc(sizeof(int)*10);
    int i = 0, aux;
    int digits;
    int sign;

    printf("Dame el numero \n");
    scanf("%d", &numero);
    if (numero <0) sign = -1;
    numero = abs(numero);
    aux = numero;
    while(1){
        *(vecnumero + i) = aux % 10;
        aux = aux/10;
        if (aux == 0) {
            digits = i + 1;
            break;
            }
        i = i+1;
    }
    for (i = digits; i<=10; i++){
        vecnumero[i] = -1;
    }
    if (sign == -1) printf("-");
    invertir(vecnumero);
    
    free(vecnumero);

    return 0;
}

int invertir(int* m){
    int n=0, i=0;
    for (i=0; i<10; i++){
        if (m[i]==0) n++;
        else break;
    }

    for (i=0; i<10; i++){
        if (m[i]>=0){
            printf("%d", m[i]);
        }
    }
    printf("\n");
    return n;
}