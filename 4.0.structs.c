#include <stdio.h> 
#include <stdlib.h> 

typedef struct student{
	int age;
	char* name;
	short student_number;
}stud;

int x;
stud phebe;
stud sidak;

int array[10];
char array2[10];
stud array3[10];

// array3[0] = phebe;
// array[1] = sidak;
// array[2].........

// for(int i=0; i<10; i++){
// 	printf("%s\n", array3[i].name);
// }

sidak.age = 22;
sidak.student_number = 000;
strcpy(sidak.name,"Sidak");

phebe.age = 19;
phebe.name = "Phebe";
phebe.student_number = 911;

graduate(phebe);

void graduate(struct student stud){
	printf("%s has graduated.", stud.name);
	printf("This student graduated at the young age of %d", stud.age)
	remove_from_current_students(stud);
}
//typedef
typedef int height;

//explain typedef
typedef struct student{
	int number;          //4bytes
	char name[15];       //15bytes
	int age;             //4bytes
	char lastname[15];   //15bytes
	int isFailing;       //4bytes
	char* temp;
}stud;

int x;
char y;

//we are creating our own type!
stud s1;
struct student s1;

//each student struct is actually 42 bytes
//but each student pointer is only 8 bytes

int x = 7;
int* ptr_x = &x;

stud* ptr_std = &s1;


int main (int argc, char **argv){ 

	//dot notation accessing things in structs
	stud s1;
	s1.number = 900900;
	strcpy(s1.name,"Minma");

	//collections
	int x;
	int xes[10];

	stud s1;
	stud students[10];
	[ [42bytes]     [42bytes]         [42bytes]...
	         []      [] 	[]    []    []      []   ]            ]


	//everytime there is a new student, we wish to reserve memory for the student
	stud* s1 = (stud *)malloc(sizeof(stud));
	int*   x = (int  *)malloc(sizeof(int ));

	//to get to the actual struct from the pointer
	(*s1).age = 10; //gives the age of the student

	//pointer notation - we retireve the VALUE of that attribute
	s1->age = 10;

	free(s1);


	//collections
	//just like this is a collection of ints
	int array1[10];

	//this is a collection of the stud structs
	stud* student_array[7];

	//[
	// 	[stud*] -> 
	// 	[stud*] -> 
	// 	[stud*] ->
	// 	[stud*] ->
	// 	[stud*]
	// 	[stud*]
	// 	[stud*]
	// 			]

	//first we have to malloc space for each student
	for (int i=0;i<7;i++){
		student_array[i] = (stud *)malloc(sizeof(stud));
	}
	
	//let's pretend that we have already recorded all the names
	// strcpy(student_array[0]->name, "grace");

	//does all the looping itself
	//strcpy(char *destination, char* source);

	//to access students from the array, and free
	for (int i=0; i<7; i++){
		printf("%s",student_array[i]->name);
		//or
		printf("%s",(*student_array[i]).name);
		free(student_array[i]);
	}


	//TESTING
	//=======

	//full struct
	stud s3;

	//struct pointer
	stud* temp = &s3;

	//sizeof returns to us, how many BYTES is being used to store this object
	printf("Sizeof S3 is %ld, Sizeof temp is %ld\n", sizeof(*temp), sizeof(temp));

	/*
	in your mind, just replace struct with int and see if it makes sense
	int x = 7;
	int* ptr_x = &x;
	*/

	
	return 0;
}
