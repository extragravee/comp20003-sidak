#include <stdio.h>
#include <stdlib.h>

int fib(int n);

int main(int argc, char *argv[]){
    int n = 0;
    
    puts("Please enter a number to get the fib seq at that position: ");
    scanf("%d", &n);
    
    printf("\nFib = %d\n", fib(n));
    
    return 0;
}

int fib(int n){
    if(n==1|n==2){
        return 1;
    } else if (n<1){
        return 0;
    }
    
    return fib(n-1)+fib(n-2);
}