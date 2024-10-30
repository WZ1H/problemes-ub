/* vectors_punters.c 

relació vectors <--> punters
(aritmètica de punters)

maneres diverses d'accedir a adreces i valors dels elements d'un vector
-----------------------------------------------------------------------

Resum
   El nom d'un vector (sol, sense []) és l'adreça del seu primer element
   Es verifica: adreça + enter -> adreça
   Posant * al davant s'obté el valor contingut en l'adreça
   Exemples:
            v    <->  &v[0]  
           v+2   <->  &v[2]
         *(v+2)  <->   v[2] 

A més, usant una variable p punter a int i assignant-li alguna adreça de v[]
       també es pot accedir al vector v[] a través del punter p
----------------------------------------------------------------------------

Comentaris:
   1) En execucions diferents, les adreces són diferents
   
   2) Si s'accedeix a components d'índex fora del rang correcte -> 
         -> Les adreces continuen existint
         -> Els valors que hi ha són desconeguts
      C NO AVISA DE LES SORTIDES DE RANG
      CAL VIGILAR QUE AIXO NO PASSI

   3) v, &v[i], v+i són CONSTANTS punter. No es poden canviar
*/
#include <stdio.h>

int main(void) {

   int i, v[5], *p;

   for (i=0; i<5; i++)
      v[i] = i*i+1;

   p = &v[2];

   printf("\n");
   printf("s'han declarat   int i, v[5], *p; \n");
   printf("s'ha omplert v[] amb els valors v[i] = i*i+1; (i=0,1,2,3,4)\n");
   printf("s'ha assignat p = &v[2]; \n");
   printf("recordem que sizeof(int) = %lu \n", sizeof(int));


   printf("\n");
   printf("exemples d'acces a ADRECES dels elements de  v[]: \n");

   printf("usant l'operador & \n");
   printf("&v[0] = %p \n", &v[0]);
   printf("&v[1] = %p \n", &v[1]);
   printf("&v[5] = %p \n", &v[5]);

   printf("usant aritmetica de punters: punter + enter -> punter \n");
   printf("v   = %p \n", v);
   printf("v+1 = %p \n", v+1);
   printf("v+5 = %p \n", v+5);

   printf("a traves del punter auxiliar p = &v[2] \n");
   printf("p-2 = %p \n", p-2);
   printf("p-1 = %p \n", p-1);
   printf("p+3 = %p \n", p+3);

   
   printf("\n");
   printf("exemples d'acces a VALORS dels elements de  v[]: \n");

   printf("usant el nom del vector i un index \n");
   printf("v[0] = %d \n", v[0]);
   printf("v[1] = %d \n", v[1]);
   printf("v[5] = %d \n", v[5]);

   printf("usant l'adreca constant v, l'aritmetica de punters i l'operador * \n");
   printf("*v     = %d \n", *v);
   printf("*(v+1) = %d \n", *(v+1));
   printf("*(v+5) = %d \n", *(v+5));

   printf("a traves del punter auxiliar p = &v[2] i l'operador * \n");
   printf("*(p-2) = %d \n", *(p-2));
   printf("*(p-1) = %d \n", *(p-1));
   printf("*(p+3) = %d \n", *(p+3));


   printf("\n");
   printf("exemples d'aritmètica \n");
   printf("quan es resten 2 adreces, dona un enter (llarg): \n");
   printf("&v[4]-&v[1] = %ld \n", &v[4]-&v[1]);
   printf("(v+2)-(v+4) = %ld \n", (v+2)-(v+4));
   printf("(p+4)-(p-1) = %ld \n", (p+4)-(p-1));

   return 0;
}

