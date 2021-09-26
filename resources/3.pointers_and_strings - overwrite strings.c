
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	/* code */
	char str1[] = "helloworld";
	char str2[] = "abcde";

	char* pA = str1;
	char* pB = str2;

	strcpy(pA,pB);

	printf("%s %s\n", pA, pB);

	char *find_nullbyte = str1;

	while(*find_nullbyte!='\0'){
		find_nullbyte++;
	}

	find_nullbyte+=1;

	//print one char at that pointer
	putchar(*find_nullbyte);
	puts(find_nullbyte);


	return 0;
}