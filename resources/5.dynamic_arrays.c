#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char** argv){

	//FIRST, LET'S ATTEMPT THE KAHOOT AGAIN, SEE HOW
	//FAR WE HAVE COME :>

	int numbers[5] = {0};
	//draw out how this looks

	char word[6] = "Julie";
	//why is this 6 letters
	//draw this out

	/*
	What happens if I want an array of an array?
	Let's say for example we have nest array [] []
	where we have student scores for their subjects this semester,
	for 4 students.

	So we have a data structure such as this
	-----------------------------------------------------
	|77,84,90,67| |33,56,23,87| |....      | |....      |
	-----------------------------------------------------
	One container block (outer array), and semi-blocks which hold
	a student's scores for the semester (inner arrays)

	We would define this as:

	int student_scores[#num_of_students][#num_of_scores];
	int student_scores[4][4] in our case.

	this should be visualised as the following in memory:
	[ [  ,	,	,	],
	  [	,	,	,	],
	  [	,	,	,	],
	  [	,	,	,	]]

	So why am I laboring this point? :thinking:
	================
	STRING ARRAYS
	================

	Now comes the issue of the string arrays, what if I want to define
	an array of words?
	*/
	char sentence[5][10] = {"My", "Secret?", "I'm", "Always", "Angry"};

	/*
	What does this look like?
	Well it is an array of an array. The inner array each, is a char[],
	meaning the inner array is a string / word. The outer array is a collection
	of these words, so it is a sentence.

	[
		[ M,Y ,\0 ,    x, x, x, x, x, x, x]
		[ S,E ,C ,R ,E ,T ,? ,    \0, x, x]
		[ I,',M , \0,  x, x, x, x, x, x, x]
		[ A, L, W, A, Y, S,\0 ,x , x, x, x]
		[ A, N, G, R, Y,\0 , x, x, x, x, x]
	]
	
	See any issues with this approach? what do the Xs represent?
	What if we get a word longer than 9 LETTERS / 10 BYTES?

	What we want, is to be able to malloc space for each word based
	on how many letters it is. This is done by first counting the 
	letters of a word being read (use strlen()), then allocating memory
	for this word.

	So we use an ARRAY of CHAR POINTERS. For each char pointer, we can
	call a malloc, because malloc allocates some memory and returns its
	memory address, and a pointer points to a memory address.
	

	//draw out how it should look.
	*/

	char* word_pointers[10];
	//this array holds 10 char pointers 

	/*
	=============================
	EXTENSION TO OTHER DATA TYPES
	=============================

	Naturally, this concept can also be applied to other data types
	I don't know how many subjects a student has completed, so how will I 
	allocate memory for his scores?

	I can count his scores, set aside that many int blocks:

	[
	[int*] -> {   }
	[int*] -> {                     }
	[int*] -> {            }
	]
	

	no memory waste here! Very efficient!

	===========================
	POINTERS AND DYNAMIC ARRAYS
	===========================
	okay so we also know, that names of arrays are constant pointers.
	student_scores[0] refers to a single int array.
	so we can do int* ptr = student_scores[0] which is valid
	and we can allocate double pointers to point to array of an array
	*/

	int** dbl_ptr = student_scores.

	/*
	What happens when you dereference a pointer?
	//draw this out, extend it to double pointers

	*/

	return 0;
}