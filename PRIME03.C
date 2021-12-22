/***************************************************/
/* PRIME03.c                                       */
/*           : Erastothenes's sieve                */
/*                                                 */
/*                        PGMD by TH               */
/***************************************************/

#include <stdio.h>
#include <alloc.h>
#include <stdlib.h>

#define MAX 10000

void main(void) {
	int* iptr;
	int i, j;

	iptr = (int*)calloc(MAX, sizeof(int));
	if(iptr == NULL) {
		puts("\n Memory allocation ERROR!");
		exit(1);
	}
	for(i=2; i<MAX; i++) {
		if(iptr[i] ==1)
			continue;
		j=i;
		while((j += i) <= MAX)
			iptr[j] = 1;
	}
	for(i=2; i <= MAX ; i++)
		if(iptr[i] == 0)
			printf("\t%6d", i);
	getch();
}