#include <stdio.h>
#include <dos.h>
#include "project\timer.h"

int gcd_minus(int u, int v) {
	int t;
	while (u) {
		if (u < v) {
			t=u;u=v;v=t;
		}
		u = u - v;
	}
	return v;
}

int gcd_modulus(int u, int v) {
	int t;
	while (v) {
		t = u % v;
		u = v;v = t;
	}
	return u;
}

int gcd_recursion(int u, int v) {
	if(v == 0)
		return u;
	else
		return gcd_recursion(v, u%v);

}

#define LOOP 1000000

void main(void) {
	int u, v, gcd;
	long t1, t2;
	int i;

	puts("\n EUCLID2 : Get GCD with time checking..."
	     "\n         Input 0 to end program");

	while (1) {
		puts("\n\n INPUT 2 positive integer -> ");
		scanf("%d %d", &u, &v);

		if( u < 0 || v < 0)
			continue;
		if( u == 0 || v == 0)
			break;

		t1 = get_tick();
		for(i = 0; i< LOOP; i++)
			gcd = gcd_minus(u, v);
		t2 = get_tick();
		printf("\n Minus methods : GCD of %d and %d is %d. in %d ticks"
			 , u, v, gcd, diff_tick(t1,t2));

		t1 = get_tick();
		for(i = 0; i< LOOP; i++)
			gcd = gcd_modulus(u, v);
		t2 = get_tick();
		printf("\n Modulus methods : GCD of %d and %d is %d. in %d ticks"
			 , u, v, gcd, diff_tick(t1,t2));

		t1 = get_tick();
		for(i = 0; i< LOOP; i++)
			gcd = gcd_recursion(u, v);
		t2 = get_tick();
		printf("\n Recursion methods : GCD of %d and %d is %d. in %d ticks"
			 , u, v, gcd, diff_tick(t1,t2));
	}
}