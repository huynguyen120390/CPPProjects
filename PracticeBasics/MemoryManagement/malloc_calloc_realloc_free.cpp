#include <stdio.h> 
#include <stdlib.h> 

int main()
{
    // (X) 3
    int *m = (int*)malloc(sizeof(int)); 
    m = NULL; //memory leak

    // (Y) 1
    int *n = (int*)malloc(sizeof(int)); 
    free(n);
    *n = 23;  //dangling pointer

    // (Z)
    char *o;
    *o = 'a';  //uninit pointer

    return 0;
}