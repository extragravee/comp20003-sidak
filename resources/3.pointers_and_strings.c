#include <stdio.h>
#include <stdlib.h>

void copy_ints(int* dest, const int* array, int n);

int main(int argc, char **argv){
	/*

	//MALLOC
	http://www.pythontutor.com/c.html#mode=display


	1. Defining strings
	=============================
	- Strings are not a primitive type, they are array of chars
	- strings must ALWAYS end in nullbyte because they are an array of 
		chars and so that the compiler finds out when to stop reading
		memory
	- nullbyte is the binary 0 character written as '\0' (char type)
	- not the same as (NULL which is a macro defined in our compiler
		to assign a value not pointing anywhere)
	*/

	/* sample file
	hello darkness my old friend\n
	sad violin music\n
	covid19 \n
	\EOF\
	*/

	//==========================================
	//reading a char file into c
	char buffer[1000];
	char character;
	// char* sentences[10];

	int arr[] = {1,2,3,4,6,9};
	char arr[] = {'R', 'I', 'S', 'A', '\0'};

	// [char *][arr] -> ['M', 'i', 'n', 'm', 'a', '\0']

	char* array[6];

	// [char *] -> [hello darkness my old friend\0]
	// [char *] -> [tymara is a c guru good\0]
	// [char *] ->
	// [char *] ->
	// [char *] ->
	// [char *] ->

	// buffer = [tymara is a c guru good\0]

	// int counter = 0;
	// int sentence_counter = 0;
	// while(scanf("%c", &character)==1){
	// 	if(character==EOF){
	// 		break;
	// 	} else if (character=='\n'){
	// 		buffer[counter] = '\0';
	// 		char *temp = (char *) malloc(sizeof(char)*strlen(buffer)+1);
	// 		strcpy(temp, buffer);
	// 		sentences[sentence_counter++] = temp;

	// 		counter = 0;
	// 	}
	// 	else {
	// 		buffer[counter++] = character;
	// 	}
	// }
	//===============================

	//can define strings as either
	char my_string[40] = {'J', 'O', 'o', 'l', 's', '\0',};
	[J,O,o,l,s,\0,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,]

	//or with double quotes, which automatically addes nul,
	//also not defining the size with double quotes gives automatic size
	char my_string2[] = "JOols";
	[J,O,o,l,s,\0]

	//why are the sizes what they are??
	printf("%ld, %ld\n",sizeof(my_string), sizeof(my_string2) );

//REFER TO 3.DEMO.C

	/* 2. Copying things
	===========================
	normally copying an array of positive ints, marks the end with
	a negative int

	also it's normal to pass the number of elements too, like

	int copy_ints(int* dest_array, const int* src_array, int n );
	where nbr is the number of items that need to be copied over.


	*/

	int int_array[11] = {1,2,3,4,5,6,7,8,9,10,1000};
	int* dest = (int *)malloc(sizeof(int) * 10);
						{ , , , , , , , , , ,}
	// int* dest = (int *)malloc(sizeof(int)
	//  * sizeof(int_array)/sizeof(int_array[0]));


	//this num elements trick only works cause int_array is defined locally
	copy_ints(dest, int_array, 10);
	
	free(dest);

	/*
	==============
	ARRAY OF WORDS
	==============
	
	int array[10]; [int, int, int, int, int, int]
	int* array[10]; [int*, int*, int*, int*, int*, int*] -> integer, integer array
	char* array2[10]; [char*, char*, char*, char*, char*]



	*/
	
	return 0;
}


//the benefit with c is the whole array is not copied on stack and
//passed to the function like in some languages, but just the mem address
//c is very very efficient!
void copy_ints(int* d, const int* src, int n){
	for (int i=0; i<n; i++){
		*(d+i) = src[i];
	}

	puts("The copied elements at destination are:");

	for (int i=0; i<n; i++){
		printf("%d\n", *(d+i));
		// or we can do printf("%d", dest[i]);
	}

}
