#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


void calculate_the_maximum(int n, int k) {
  //Write your code here.
    int a, b, aux_or=0, aux_and=0, aux_xor=0;
    for(a=1; a<n; a++){
        for(b=a+1; b<=n; b++){
            if((a | b) > aux_or && (a | b) < k) aux_or = (a | b);
            if((a & b) > aux_and && (a & b) < k) aux_and = (a & b);
            if((a ^ b) > aux_xor && (a ^ b) < k) aux_xor = (a ^ b);
        }
    }
    printf("%d\n", aux_and);
    printf("%d\n", aux_or);
    printf("%d\n", aux_xor);

}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}
