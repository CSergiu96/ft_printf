#include "ftprintf.h"

/****************/
#include <stdio.h>
/****************/

int	main(void)
{
	char *ptr = "Hello world!";
    char *np = 0;
    int i = 5;
    unsigned int bs = sizeof(int)*8;
    int mi;

    mi = (1 << (bs-1)) + 1;
    
	printf ("Characters: %c %c \n", 'a', 65);
	printf ("Decimals: %d %ld\n", 1977, 650000L);
   	printf ("Preceding with blanks: %10d \n", 1977);
   	printf ("Preceding with zeros: %010d \n", 1977);
   	printf ("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
   	printf ("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
   	printf ("Width trick: %*d \n", 5, 10);
   	printf ("%s \n", "A string");

   	printf("%s\n", ptr);
    printf("printf test\n");
    printf("%s is null pointer\n", np);
    printf("%d = 5\n", i);
    printf("%d = - max int\n", mi);
    printf("char %c = 'a'\n", 'a');
    printf("hex %x = ff\n", 0xff);
    printf("hex %02x = 00\n", 0);
    printf("signed %d = unsigned %u = hex %x\n", -3, -3, -3);
    printf("%d %s(s)", 0, "message");
    printf("\n");
    printf("%d %s(s) with %%\n", 0, "message");
   	/**************************************************/

	return(0);
}