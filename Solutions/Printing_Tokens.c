#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    //Write your logic to print the tokens of the sentence here.
    int n = strlen(s);
    char begin[n];
    int i=0,ind=0;

        while(s[i]!='\0')
        {
            begin[ind]=s[i];
            if(s[i]==' ')
                {
                    begin[ind]='\n';
                    printf("%c", begin[ind]);

                    ind=0;
                    i++;
                }
            else
            {
                printf("%c", begin[ind]);
                ind++;
                i++;
            }
        }
    /*for (int i=0; i<n; i++){
        if(s[i] != ' '){
            printf("%s", &s[i]);
        }
        else printf("\n");
    }*/
    return 0;
}
