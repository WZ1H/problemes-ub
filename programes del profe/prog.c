    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    
    int main(){
    int i,n;
    int *v;
    
    n=10;
    
    v=(int*)malloc(n*sizeof(int));
    if(v==NULL){ printf("No memory\n"); exit(1);}
    
    for(i=0;i<=n;i++) v[i]+=1; /*ULL rang bucles*/
    
    /*free(v);*/ /*Important!!*/
    return 0;
    }
    
    
    /*
    Valgrind -> serveix per detectar problemes de memoria en el programa
    Basicament detecta:
      1) Zones de memoria mal reservades (malloc en rang incorrecte, o que 
         estem accedint fora de rang)
      2) Memoria no alliberada (malloc <-> free).
    
    Compilacio: flag "-g"
      gcc -g prog.c -o prog.exe -lm -Wall
    
    Execucio:
      valgrind --leak-check=full ./prog.exe
    
    L'opcio -v -> dona mes detalls
    */
