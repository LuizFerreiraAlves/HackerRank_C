#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n;
    scanf("%d", &n);
  	// Complete the code to print the pattern.
    int aux_i, aux_j;
    for(int i=1; i<=(2*n-1); i++){
        aux_i = abs(i-n);
        for(int j=1; j<=(2*n-1); j++){
            aux_j = abs(j-n);
            
            int aux;
            aux_i >= aux_j ? (aux=aux_i) : (aux=aux_j);

            printf("%d ", aux+1);       
        }
        printf("\n");
    }
    return 0;
}
