#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
	/*
	1. Variables:
	=============================
	- Value varies 
	- memory block depends on the range the variable is allowed to vary
	- int k = 8 -> can be 2 or 4 bytes depending on system, so a 
		2 byte system allocates a smaller range of values that the int can take

	- variable 'k' here is an object, as during runtime, 8 is stored in the memory
		allocated towards k, and therefore it is an object (object is a named
		region of a storage)

	- int k 		 = 8
	  lvalue 		 = rvalue
	  memory address = value stored

	- ALWAYS INITIALISE YOUR VARIABLES, C HATES YOU
	*/


	int j = 7; //j is on the left side, so we take l value (memory address)
	int k = 8;
	k = j; //here j is on the right hand side, so we take the value stored in j

	/*
	2. Pointers
	=============================
	- Wish to store lvalues / memory addresses in a variable, need Pointers
	- pointers are just variables that store memory addresses (lvalues)
	- assigning pointer variable tells the compiler to store the number of bytes
		needed to store a memory address
	*/

	int* ptr = NULL; //pointer variable that stores the memory address of an integer

	/*=============================
	1. Which one throws an error?

	int *ptr = j; (j is an int)
	int *ptr = &j;

	2. True or false?

	sizeof(int) == sizeof(int*)


==============
*****
 ****
  ***
   **
    *
==============


	
	*ptr = &ptr2;


	*/

	int *ptr = NULL;
	int k = 5;

	ptr = &k; 
	(*ptr) = k; 
	


	//is the size of an int pointer bigger than an int variable?
	printf("%d\n", (sizeof(int) < sizeof(int*)));

	printf("Value of ptr is: %d\n", (*ptr));



	// DO POINTERS AND SUBFUNCTIONS EXERCISE, CHANGE VALUE OF 
	// INT WITH POINTERS INSIDE A FUNCTION

	//subfunctions have LOCAL copies of the variable
	//use pointers to change the values of the variable inside a subfunc

	return 0;
}
