#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    
    puts("Enter n: ");
    scanf("%d", &n);
    
    long array[n];
    
    if((n==1) || (n==2)){
        return 1;
    }
    
    array[0] = 0;
    array[1] = 1;
    array[2] = 1;
    
    long i=0;
    
    for(i=3; i<n; i++){
        array[i] = array[i-1] + array[i-2];
    }
    puts("");
    printf("Fib: %ld\n", array[i-1]+array[i-2]);
    
    return 0;
}