#include "RftCombinations.h"

static int n = 0, p = 0;
static int tab[256];

static void print() {
	int i, j;
	p++;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (tab[i] == j) {
				printf("D");
			}
			else {
				printf("*");
			}
		}
		printf("\n");
	}
	printf("\n");
}

static int absolute(int x) {
	return x > 0 ? x : -x;
}

static int valid(int k, int i) {
	int j;
	for (j = 0; j < k; j++) {
		if (tab[j] == i) {
			return 0;
		}
		if (abs(j - k) == abs(tab[j] - i)) {
			return 0;
		}
	}
	return 1;
}

static void numbers(int k) {
	int i;
	if (k < n) {
		for (i = 0; i < n; i++) {
			if (valid(k, i)) {
				tab[k] = i;
				numbers(k + 1);
			}
		}
	}
	else {
		print();
	}
}

void RftCombinations() {
	printf("Enter number: ");
	scanf("%d", &n);
	numbers(0);
	printf("There are %d posibilities.\n", p);
}
