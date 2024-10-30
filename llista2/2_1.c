#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void swap(int*, int*);
void canvi(int*, int*);


int main(void){
int x, y;



printf("Escriu dos numeros ");
scanf("%d %d",&x,&y);
if (x < 0 || y < 0) exit(1);
swap(&x, &y);
canvi(&x, &y);
printf("%d %d\n", x, y);

return 0;   
}

void swap(int *a, int *b){
if (*a<*b){
int aux;
aux = *a; *a=*b; *b=aux;
}
}

void canvi(int *a, int *b){
    int rest = *a % *b;
    int gcd, lcm;
    /* aa i bb son auxiliars */
    int aa = *a; 
    int bb = *b;
    while (rest != 0){
        aa = *b;
        bb = rest;
        rest = aa % bb;
    }
    gcd = bb;
    lcm = (*a * *b)/gcd;
    *a = gcd;
    *b = lcm;
}