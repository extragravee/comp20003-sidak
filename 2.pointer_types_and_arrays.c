#include <stdio.h>
#include <stdlib.h>

int main(int argc, char**argv){

	int num = 0;
	int *ptr = NULL;

	ptr = &num;

	*ptr = 7;

	*(&ptr) = &num;
	ptr = &num;

	*ptr;
	/*
	1. Pointer types
	===========================
	- now when we dereference ptr, compiler will know how many bytes to copy
		into this memory location pointed to by ptr
	- this happens because we defined the pointer as an 'int' pointer
	- if this was a different type, different number of bytes would be copied in
	
	Now let's say we have this situation:

	- Each int takes by 4 bytes
	- we have 10 digits in a block of memory
	-----------------------------------------------------------
    |1	 |7	  |8	|9	  |14  	|75	  |3	|2	  |1	|0	  |  Object values
   	-----------------------------------------------------------
	100	  104  108   112   116   120   124   128   132   136     Memory addresses
	
	^
	my_arr
	ptr

	*my_arr = 1
	my_array[0] -> *(my_array + 0)

	const int* my_arr = 100;
	my_arr = NULL;

	int *ptr = NULL;
	ptr = &my_array[0];
	ptr = NULL;
	ptr = 100;


	ptr+1 => move up one INTEGER size block


	When we do *(ptr + 1), what gets printed? Why?	
			      ptr[1] -> indexing
	*** This is called POINTER ARITHMETIC! ***


	2. Arrays
	===========================
	- contiguous blocks of memory
	- very interesting implications for how we retrieve stuff
	- can do indexing or pointer arithmetic + derefrencing
	*/

	const int* special_ptr = NULL;

	int my_array[] = {1,7,8};

	my_array = NULL; // NOPE


	int *ptr = &my_array[0];
	         = &(*(my_array+0))
	         = my_array + 0
	         = my_array

	int *ptr2 = my_array;

	int i;
	ptr = &my_array[0]; /* point our pointer to the first // or we can do ptr = myarray
	&(*(my_array+0))
	&(*(my_array))
	my_array		   element of the array */
	ptr = my_array;

	printf("\n\n");
	
	for (i = 0; i < 3; i++){
		printf("my_array[%d] = %d | ",i,*(my_array+i)); /*<-- A */ //my_array[i]
		printf("ptr + %d = %d\n",i, *(ptr+i));    //or we can do ptr[i]
	}	//*(ptr+i)

	for (i = 0; i<3; i++){
		printf("%d\n", ptr[i]); // my_array[i]
	}


	int *ptr = my_array;


	/*
	note here that ptr is a variable, that it can point to different memory addresses
	but my_array is a CONSTANT, and we can never change the memory address it points to
	so it's an unmodifiable lvalue! 
	it's called a CONSTANT POINTER
	
	-----------------------------------------------------------
    |4	 |6	  |8	|9	  |14  	|75	  |3	|2	  |1	|0	  |  Object values
   	-----------------------------------------------------------
	100	  104  108   112   116   120   124   128   132   136     Memory addresses
	
	^
	my_array
	^
	ptr

	int *ptr = &my_array[0];
	???? how would you print 8 using indexing and pointer arithmetic?
	printf("%d\n", ?????????????? ) *(ptr+2) -> ptr[2]
	printf("%d\n", ?????????????? ) 

	int n;
	ptr = &n;

	printf("%p", my_array); 100
	printf("%p", &my_array[7]);  -> 128

	printf("%p", my_array+7); -> 128

	3. Segments of memory
	===========================
	- variables stores in the memory when the program runs
	- int k = 2, k is a variable that occupies data segment of the memory
		but 2 is a constant that occupies code segment of the memory
	- if we did int i = k, at run time, the compiler looks at address of k, 
		to determine the value to be moved to i, whereas i = 2 just assigns
		2 to the code segment of the memory, there is no dereferencing involved
	- therefore both i and k are objects (as they have specific data stores within
		their locations), but 2 is not, 2 is just data

	- AND as we know my_array is a constant, the value is just stored in the code
		segment of the memory, no dereferncing happens if we did
		int* ptr = my_array, compiler just looks at the stored code segment and
		assigns the value

	4. Void pointer
	===========================
	
	- different pointers can be of different sizes! can run into trouble
		if we try to assign a long type pointer address to an int* ptr!
	- to avoid these issues, we have
		(void*) vptr

	- C won't allow us to compare (int *) and (long *), both of these
		can be compared to a void pointer
		(void *) int, (void *) long, (void *) ch
	
	*/


	return 0;

}
