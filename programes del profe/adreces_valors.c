/* adreces_valors.c 

una variable qualsevol té: 
   nom         (constant, definit en la declaració) 
   tipus       (constant, definit en la declaració)
   adreça      (constant, assignada en la declaració)
   valor       (variable, canvia cada vegada que es fa una assignació)

una variable punter també té les coses anteriors
   però els valor és una adreça d'una altra variable
es diu que la variable punter apunta a l'altra variable

l'operador & dona una adreça 
(per tant, cal aplicar-lo a una cosa que tingui adreça)

l'operador * dona el valor de l'adreça on apunta un punter
(per tant, cal aplicar-lo a un punter)

-----------------------------------------------------------------------
exemples d'ús de & i *

es fan escriure adreces i valors

atenció als format de cada cosa (per a adreces, format %p)
*/

#include <stdio.h>

int main(void) {

   double x, *px;
  
   printf("\n");
   printf("adreces i valors després d'haver declarat double x, *px; \n");
   printf("   &x  = %p \n", &x);
   printf("    x  = %lf \n", x);
   printf("  &px  = %p \n", &px);
   printf("   px  = %p \n", px);
   printf("  *px  = %lf \n", *px);

   x = 1.2;

   printf("\n");
   printf("adreces i valors havent fet nomes x = 1.2; \n");
   printf("   &x  = %p \n", &x);
   printf("    x  = %lf \n", x);
   printf("  &px  = %p \n", &px);
   printf("   px  = %p \n", px);
   printf("  *px  = %lf \n", *px);
   
   px = &x;
   
   printf("\n");
   printf("adreces i valors havent fet tambe px = &x; \n");
   printf("   &x  = %p \n", &x);
   printf("    x  = %lf \n", x);
   printf("  &px  = %p \n", &px);
   printf("   px  = %p \n", px);
   printf("  *px  = %lf \n", *px);

   *px = 3.4;
   
   printf("\n");
   printf("adreces i valors havent fet tambe *px = 3.4; \n");
   printf("   &x  = %p \n", &x);
   printf("    x  = %lf \n", x);
   printf("  &px  = %p \n", &px);
   printf("   px  = %p \n", px);
   printf("  *px  = %lf \n", *px);

   px = NULL;

   printf("\n");
   printf("adreces i valors havent fet tambe px = NULL; \n");
   printf("   &x  = %p \n", &x);
   printf("    x  = %lf \n", x);
   printf("  &px  = %p \n", &px);
   printf("   px  = %p \n", px);
   printf("  *px  = %lf \n", *px);

   return 0;
}
