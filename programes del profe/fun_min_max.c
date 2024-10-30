/* fun_min_max.c

exemple d'ús de punters com a arguments de funcions
(es practica l'ús dels operadors & i *)

- generació aleatòria d'elements d'un vector en un interval [a, b]

- càlcul del valor mínim i del valor màxim en una mateixa funció
*/

#include <stdio.h>   /* scanf, printf */
#include <stdlib.h>  /* exit, srand, rand, RAND_MAX */
#include <time.h>    /* time */

#define DIM 1000000  /* dimensió màxima permesa
                        ATENCIÓ: si es posa gaire més gran -> violació de segment */

#define N 10         /* dimensió màxima per a la qual es fa un seguiment */


void min_max(int n, double v[], int *pos_min, int *pos_max);

int main(void) {

   int n, j, pmin, pmax;
   double a, b, v[DIM];

   /* dades: dimensió i extrems d'un interval */
   printf(" n? a? b? \n");
   scanf(" %d %le %le", &n, &a, &b);
   
   /* comprovació de les dades */
   if (n<1 || a >= b) {
      printf("dades incorrectes \n");
      exit(1);
   }

   /* s'omple v[] amb nombres aleatoris de [a, b]
      (es fa escriure si n <= N)
   */
   srand((unsigned)time(NULL));            
   for (j=0; j<n; j++)
      v[j] = a+(b-a)*rand()/RAND_MAX;

   if (n <= N) {
      printf("v:");
      for (j=0; j<n; j++)
         printf(" %+.2lf,", v[j]);
      printf("\n");
   }

   /* invocació de la funció i escriptura de resultats */
   min_max(n, v, &pmin, &pmax);

   printf("valor minim = %+lf, posicio = %d \n", v[pmin], pmin);         
   printf("valor maxim = %+lf, posicio = %d \n", v[pmax], pmax);         

   return 0;
}


/* funció que calcula les posicions del valor mínim i del valor màxim
   des de (v[0], v[1], ..., v[n-1]) */
void min_max(int n, double v[], int *pos_min, int *pos_max) {

   int j;

   *pos_min = *pos_max = 0;

   for (j=1; j<n; j++) {
      
      if (v[j] < v[*pos_min]) 
         *pos_min = j;
      
      else if (v[j] > v[*pos_max])  
         *pos_max = j;
   }

   return;
}
