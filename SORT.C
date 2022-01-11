/* SORT.C : Sorting LIb                 */
/*                                      */
/*                      pgmd by TH      */

#include <stdio.h>
#include <alloc.h>
#include <stdlib.h>
#include <mem.h>
#include "PROJECT\SORT.H"

#define STACK_SIZE	20000
#define BASE(i)	((char*)base+(i)*width)


int top;
int far *stack;

int make_stack(void) {
	if((stack = (int far*)farmalloc(sizeof(int)*STACK_SIZE)) == NULL)
		return 0;
	else
		return 1;
}

void remove_stack(void) {
	farfree(stack);
}

void select_sort(void *base, size_t nelem, size_t width, FCMP fcmp) {
	void *min;
	int minindex;
	int i, j;

	min = malloc(width);
	for(i = 0; i < nelem -1; i++) {
		minindex = i;
		memcpy(min, BASE(i), width);
		for(j = i+1; j < nelem; j++) {
			if(fcmp(min, BASE(j)) > 0) {
				memcpy(min, BASE(j), width);
				minindex = j;
			}
		}
		memcpy(BASE(minindex), BASE(j), width);
		memcpy(BASE(i), min, width);
	}
	free(min);
}