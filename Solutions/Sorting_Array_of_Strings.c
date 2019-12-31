#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a, b);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(b, a);
}

int count_number_of_distinct_characters(const char* c){
    
    int quant = 0, count;
    for(int size = 0; size <= strlen(c); size++){
        count = 0;
        for(int aux_size = size+1; aux_size <= strlen(c); aux_size++){
            if(c[size] == c[aux_size]){
                count++;
            }
        }
        if(count == 0) quant++;
    }

    return quant;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    if(count_number_of_distinct_characters(a) > count_number_of_distinct_characters(b))
        return 1;
    else if(count_number_of_distinct_characters(a) == count_number_of_distinct_characters(b)) return lexicographic_sort(a, b);
    else return 0;
}

int sort_by_length(const char* a, const char* b) {
    if(strlen(a) > strlen(b)) return 1;
    else if(strlen(a) == strlen(b)) return lexicographic_sort(a, b);
    else return 0;
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    int sorted = 0;
    while (!sorted) {
        sorted = 1;
        for (int i = 0; i < len - 1; i++) {
            if (cmp_func(arr[i], arr[i + 1]) > 0) {
                char *tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                sorted = 0;
            }
        }
    }
}

int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}
