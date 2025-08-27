#include "RftSelectSort.h"

static void RftSort(int* tab, int n) {
	int i, j, posmin;
	int min;
	for (i = 0; i < n; i++) {
		min = tab[i];
		posmin = i;
		for (j = i + 1; j < n; j++) {
			if (min > tab[j]) {
				min = tab[j];
				posmin = j;
			}
		}
		tab[posmin] = tab[i];
		tab[i] = min;
	}
}

static void Show(int* tab, int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", tab[i]);
	}
	printf("\n");
}

void RftSelectSort() {
	int t[10] = { 1, 7, 1, 4, 3, 8, 9, 10, 23, 11 };

	Show(t, 10);
	RftSort(t, 10);
	Show(t, 10);
}
