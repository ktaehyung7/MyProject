/*******************************************/
/* PRIME02.C : PRIME algorithm  time check */
/*                                         */
/*                              PGMD by TH */
/*******************************************/

#include <stdio.h>
#include <math.h>
#include "project\TIMER.H"

#define TRUE 1

int is_prime1(int n) {
	int i;
	for(i = 2; i < n; i++)
		if (n % i == 0)
			return !TRUE;
	return TRUE;
}

int is_prime2(int n) {
	int i, sqrn;
	sqrn = (int)sqrt(n);
	for(i = 2; i < sqrn; i++)
		if( n % i == 0 )
			return !TRUE;
	return TRUE;
}

void result(int i, int n, int r, long t) {
	printf("\n  Prime%d Answer: %d is %s prime number in %ld ticks."
		, i, n, r ? "" : " not", t);
}

#define LOOP 1000

void main(void) {
	int n;
	long t1, t2;
	int r;
	int i;

	puts("\n PRIME02 : Prime algorithm time checking."
	     "\n          Input 0 to end program.");

	while(TRUE) {
		puts("\nInput number to test --> ");
		scanf("%d", &n);
		if(n < 0)
			continue;
		if(n == 0)
			break;

		t1=get_tick();
		for(i = 0; i < LOOP; i++)
			r = is_prime1(n);
		t2 = get_tick();
		result(1,n,r,diff_tick(t1,t2));

		t1=get_tick();
		for(i = 0; i < LOOP; i++)
			r = is_prime2(n);
		t2 = get_tick();
		result(2,n,r,diff_tick(t1,t2));
	}
}