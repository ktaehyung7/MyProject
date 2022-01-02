/*   HANOI.C : Hanoi tower recursive version */
/*                                           */
/*                              PGMD by TH   */

#include <stdio.h>

static unsigned long count = 0;

void move(int from, int to) {
	printf("\n[%ld]Move from %d to %d",count++, from, to);
}

void hanoi(int n, int from, int by, int to) {
	if(n==1)
		move(from, to);
	else {
		hanoi(n-1, from, to, by);
		move(from, to);
		hanoi(n-1, by, from, to);
	}
}


void main(void) {
	int i = 0;
	printf("\nIf you want to quit, enter minus integer.");
	while(1) {
		printf("\nEnter height of HANOI tower -> ");
		scanf("%d", &i);
		if ( i <= 0) break;
		hanoi(i, 1, 2, 3);
	}
	getch();
}