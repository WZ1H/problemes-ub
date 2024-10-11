#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#ifndef  M_PI
#define  M_PI  3.1415926535897932384626433
#endif
    double* point() {
        int r = rand();      /* Returns a pseudo-random integer between 0 and RAND_MAX */
        double random_number1 = (double) r/RAND_MAX;
        int t = rand();      /* Returns a pseudo-random integer between 0 and RAND_MAX */
        double random_number2 = (double) t/RAND_MAX;
        double* x = (double*) malloc(2 * sizeof(double));
        x[0] = random_number1;
        x[1] = random_number2;

        return x;
    };
int main(void){
    srand(time(NULL));   /* Initialization, should only be called once. */
    int i;
    int counter=0;
    int n;
    printf("#Quants punts vols?\n");
    scanf("%d",&n);
    double* mypoint;
    for (i=1; i<=n; i++){
        mypoint = point();
        /* printf("%f %f\n", mypoint[0], mypoint[1]); */
        if (mypoint[0]*mypoint[0]+mypoint[1]* mypoint[1]<1)
            counter++;
        printf("%d      %f      %f\n", i, (double) 4*counter/i, (double) 4*counter/i - M_PI);
    }
free(mypoint);
    return 0;
}