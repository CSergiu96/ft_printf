#include "ftprintf.h"

/****************/
#include <stdio.h>
/****************/

int	main(void)
{
	/**************************************************/
	printf("-------Escape Character 2 times-------\n");
	print_mod("%%%%sAA");
	printf("\n");
	printf("%%%%sAA");
	printf("\n######################################\n\n");
	/**************************************************/
	printf("-------------Print a string-----------\n");
	//add string print
	printf("----> add string print\n");
	print_mod("%ssAA"); 
	printf("\n");
	printf("%sAA","abc");
	printf("\n######################################\n\n");
	/**************************************************/
	printf("-------Print 'a' and a new line------\n");
	print_mod("a\n");
	printf("a\n");
	printf("\n######################################\n\n");
	/**************************************************/
	printf("-------Print %% and a space after------\n");
	print_mod("% ");
	printf("Should not work");
	printf("\n######################################\n\n");
	/**************************************************/
	printf ("Characters: %c %c \n", 'a', 65);
	printf ("Decimals: %d %ld\n", 1977, 650000L);
   	printf ("Preceding with blanks: %10d \n", 1977);
   	printf ("Preceding with zeros: %010d \n", 1977);
   	printf ("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
   	printf ("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
   	printf ("Width trick: %*d \n", 5, 10);
   	printf ("%s \n", "A string");
   	/**************************************************/

	return(0);
}