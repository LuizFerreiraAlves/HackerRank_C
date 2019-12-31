#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    int i, quantidade[10], len=0; 
    
    for(int aux=0; aux <= 9; aux++){
        i = 0;
        len = 0;
        while(s[i] != '\0'){

            if(s[i] == (aux + '0')) len++;
            i++;
        }
        printf("%d ", len);
    }
    
    return 0;
}
