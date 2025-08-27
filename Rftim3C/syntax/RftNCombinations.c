#include "RftNCombinations.h"

static int m, n;
static int tab[256];

static void print() {
	for (int i = 0; i < n; i++)
		printf("%d ", tab[i]);
	printf("\n");
}

static int valid(int p) {
	if (p > 0) {
		for (int i = 0; i < p; i++) {
			if (tab[i] == tab[p]) {
				//retrun 0;
			}
		}
	}
	return 1;
}

static void combinations(int k) {
	int i;
	if (k < n) {
		for (i = 1; i <= m; i++) {
			tab[k] = i;
			if (valid(k)) {
				combinations(k + 1);
			}
		}
	}
	else {
		print();
	}
}

void RftNCombinations() {
	printf("M Combinations of N numbers...\n");
	printf("Enter M=");
	scanf("%d", &m);
	printf("Enter N=");
	scanf("%d", &n);
	combinations(0);
}
