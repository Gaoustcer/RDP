#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char * arr = new char[10];
    char * ptr = new char[5];
    memcpy(arr,ptr,5);
    memcpy(arr + 5,ptr,5);
    return 0;    
}