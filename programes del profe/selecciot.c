/* selecciot.c

algorisme de selecció per a ordenar un vector

- n elements de tipus "float"
- generats ALEATÒRIAMENT en un interval [a, b]
- es compta el TEMPS D'EXECUCIÓ de l'algorisme 
- l'algorisme es programa en una funció
- només s'escriuen resultats (de comprovació) quan n <= M (petit)

objectius:
practicar generació aleatòria
practicar el càlcul del temps d'execució
comprovar que temps d'execució = O(n^2)
*/

#include <stdio.h>
#include <stdlib.h>     /* exit(), srand(), rand(), RAND_MAX */
#include <time.h>       /* time(), clock(), CLOCK_PER_SEC */

#define a -1.
#define b +2.

#define M 20            /* dimensió màxima d'escriptura */

#define N 2000000    /* quantitat màxima d'elements a ordenar
                        si es posa gaire més gran -> violació de segment!
                        per això serà útil l'ASSIGNACIÓ DINÀMICA DE MEMÒRIA
                     */

void selec(int, float []);

int main(void) {

   float v[N];
   int n, j;
   clock_t t0, t1;

   printf("quantitat n = ? \n");
   scanf("%d", &n);
   if (n<1 || n>N) exit(1);

   /* generació dels nombres a ordenar a l'interval [a, b] */
   srand(time(NULL));            /* "seed" o llavor */
   for (j=0; j<n; j++)
      v[j] = a+(b-a)*rand()/RAND_MAX;

   /* escriptura del vector inicial (només quan n <= M) */
   if (n <= M) {
      printf("vector inicial: \n");
      for (j=0; j<n; j++)
         printf("%+5.2f ", v[j]);
      printf("\n");
   }

   /* algorisme d'ordenació per selecció i temps usat */
   t0 = clock();
   selec(n, v);
   t1 = clock();

   /* escriptura del vector final (només quan n <= M) */
   if (n <= M) {
      printf("vector final: \n");
      for (j=0; j<=n-1; j++)
         printf("%+5.2f ", v[j]);
      printf("\n");
   }

   /* escriptura del temps d'execució de l'algorisme */
   printf("temps = %.3f seg \n\n", (float)(t1-t0)/CLOCKS_PER_SEC);

   return 0;
}

/* implementació de l'algorisme de selecció 
   (es va seleccionant el mínim, es podria fer amb el màxim) */
void selec(int n, float v[]) {

   int j, pos, k;
   float aux;

   for (j=0; j<n-1; j++) {
      
      /* càlcul de pos = posició de l'element mínim entre 
                         els elements v[j], v[j+1], ..., v[n-1] 
      */
      pos = j;
      for (k=j+1; k<n; k++)
         if (v[k] < v[pos]) pos = k;
      
      /* intercanvi de l'element mínim trobat 
         amb el de la posició definitiva que li correspon 
      */
      if (pos > j) {             /* aquest "if" es pot suprimir */
         aux = v[j];
         v[j] = v[pos];
         v[pos] = aux;
      }
   }

   return;
}
