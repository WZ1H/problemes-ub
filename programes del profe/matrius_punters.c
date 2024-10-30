/* matrius_punters.c 

relació matrius <->  punters
maneres diverses d'accedir a adreces i valors d'elements de matrius
o sigui, aritmètica de punters per a matrius

és una generalització de la relació vectors <-> punters
(tenint en compte que les matrius es guarden en memòria per files)

atenció: recordeu que C no avisa quan se surt dels rangs definits
         (per tant, els valors que hi hagi no són fiables)
*/

#include <stdio.h>

#define M 3
#define N 4

int main(void) {
   int i, j, a[M][N], *p, k;

   /* omplim a[][] amb tot d'elements diferents */
   for (i=0; i<M; i++)
      for (j=0; j<N; j++)
         a[i][j] = N*i+j+3;

   printf("\ninformacio: sizeof(int)= %lu \n", sizeof(int));

   printf("\na[][] es una matriu int de %d files i %d columnes \n", M, N);


   printf("\nadreces dels elements de la matriu a[][]: \n");
   for (i=0; i<M; i++) {
      for (j=0; j<N; j++)
         printf(" %p ", &a[i][j]);
      printf("\n");
   }

   printf("\nmaneres diverses d'accedir a les ADRECES d'elements de a[][]: \n");
   printf("a        = %p \n", a);
   printf("a[1]     = %p \n", a[1]);
   printf("a+2      = %p \n", a+2);
   printf("&a[1][2] = %p \n", &a[1][2]);
   printf("a[2]+1   = %p \n", a[2]+1);
   printf("*(a+2)+3 = %p \n", *(a+2)+3);
   printf("*(a+3)+2 = %p \n", *(a+3)+2);


   printf("\nelements de la matriu a[][]: \n");
   for (i=0; i<M; i++) {
      for (j=0; j<N; j++)
         printf(" %3d ", a[i][j]);
      printf("\n");
   }

   printf("\nmaneres diverses d'accedir als VALORS d'elements de a[][]: \n");
   printf("**a         = %d !!!, 1 sol * no va be \n", **a);
   printf("*a[1]       = %d \n", *a[1]);
   printf("*(*(a+2))   = %d !!!, 1 sol * no va be, i es poden eliminar uns () \n", *(*(a+2)));
   printf("a[1][2]     = %d \n", a[1][2]);
   printf("*(a[2]+1)   = %d \n", *(a[2]+1));
   printf("*(*(a+2)+3) = %d \n", *(*(a+2)+3));
   printf("*(*(a+3)+2) = %d \n", *(*(a+3)+2));


   printf("\nus d'un punter auxiliar p amb l'adreca d'un element de a[][]: \n");
   p = &a[1][1];
   printf("s'ha fet p = &a[1][1], llavors: \n");
   for (k=-7; k<M*N; k++)
      printf("k = %+3d  p+k = %p  *(p+k) = %d \n", k, p+k, *(p+k));

   printf("\ntambe es poden restar adreces i dona un enter (llarg) \n");
   printf("&a[2][2]-&a[1][1] = %ld \n", &a[2][2]-&a[1][1]);
   printf("&a[2][2]-a[1]     = %ld \n", &a[2][2]-a[1]);
   printf("&a[2][2]-(p+3)    = %ld \n", &a[2][2]-(p+3));


   return 0;
}

/* Resum:
      conveni: a        =     &a[0][0]
               a[i]     =     &a[i][0]
      
      i, recordem: adreça + enter -> adreça
                   l'operador * dona el valor contingut a l'adreça

      llavors:
         adreces:    &a[i][j]  =    a[i]+j    =    *(a+i)+j
         valors:      a[i][j]  =  *(a[i]+j)   =  *(*(a+i)+j) 
   
      el primer element de cada fila és particular
         adreces:   a[i]   = &a[i][0]     i també     a+i   = &a[i][0]
         valors:   *(a[i]) =  a[i][0]   però passa  *(a+i) !=  a[i][0]  !!!
                               El que és cert és *(*(a+i)) =   a[i][0] 
                               De fet, *(a+i) és un punter a  a[i][0]
*/
