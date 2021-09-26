#include <stdio.h>
#include <stdlib.h>

//fibonacci without recursion or dynamic memory
//only 2 ints used for memory

int fib(int n);

int main(int argc, char const *argv[]){

	//input n
	puts("Enter n: ");
	int n;
	scanf("%d", &n);

	printf("Fib of %d is %d\n",n,fib(n));

	return 0;
}

int fib(int n){

	if(n==1 || n==2){
		return 1;
	}

	//i is the i'th fib in sequence
	int i = 2;

	//calculate i and i-1 fib
	int x = 0;
	int y = 1;

	while(i<=n){
		if(y>x){
			x+=y;
		} else {
			y+=x;
		}
		i++;
	}

	//check which var is bigger
	if(x>y){
		return x;
	} else {
		return y;
	}

}
