/********************************/
/* PRIME01.c : prime test PGM 1 */
/*                              */
/*          Programmed by TH    */
/********************************/

#include <stdio.h>

#define TRUE 1
int is_prime(int n) {
	int i;
	for(i=2; i< n ;i++) {
		if(n%i == 0)
			return !TRUE;
	}
	return TRUE;
}

void main(void) {
	int n;
	puts("\n Prime01 : Test that input number is prime or not."
	     "\n          Input 0 to End program.");

	while(TRUE) {
		puts("\nInput number -->");
		scanf("%d", &n);
		if(n<0)
			continue;
		if(n==0)
			break;
		printf("\n\n  Answer : %d is %s prime number"
			, n, is_prime(n) ? "" : " not");
		getch();
	}
}