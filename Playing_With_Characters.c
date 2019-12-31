#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX_LEN 20

int main() 
{

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    char ch, s[MAX_LEN], sen[MAX_LEN];
    scanf("%c", &ch);
    scanf("%s", s);
    scanf("\n");
    scanf("%[^\n]%*c", sen);

    printf("%c\n%s\n%s\n", ch, s, sen);


    return 0;
}
