#include "RftLinearSearchFlag.h"

static int a[11] = { 1,7,12,33,77,44,2,0,19,14 };
static int n = 10;
static int x = 14;

void RftLinearSearchFlag() {
	a[n] = x;
	int i = 0;
	while (a[i] != x) {
		i++;
	}
	if (i == n) {
		printf("Flag not found");
	}
	else {
		printf("Flag found at: %d", i);
	}
}
