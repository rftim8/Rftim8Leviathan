#include "RftFactorial.h"

//0!=1
//n!=n*(n-1)!

static int factorial(int n) {
	int i = 1;
	if (n == 0) {
		return i;
	}
	else {
		return n * factorial(n - 1);
	}
}

void RftFactorial() {
	int n = 0;
	printf("Enter N=");
	scanf("%d", &n);
	printf("%d\n", factorial(n));
}
