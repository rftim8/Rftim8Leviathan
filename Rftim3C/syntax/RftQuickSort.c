#include "RftQuickSort.h"

static void RftSort(int* tab, int s, int d) {
	int i, j, m;
	int x, aux;

	m = (s + d) / 2;
	x = tab[m];

	i = s;
	j = d;
	do {
		while (tab[i] < x)i++;
		while (tab[j] > x)j--;
		if (i <= j) {
			aux = tab[i];
			tab[i] = tab[j];
			tab[j] = aux;
			i++;
			j--;
		}
	} while (i <= j);
	if (s < j) {
		RftSort(tab, s, j);
	}
	if (i < d) {
		RftSort(tab, i, d);
	}
}

static void Show(int* tab, int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", tab[i]);
	}
	printf("\n");
}

void RftQuickSort() {
	int t[10] = { 1, 7, 1, 4, 3, 8, 9, 10, 23, 11 };

	Show(t, 10);
	RftSort(t, 0, 9);
	Show(t, 10);
}
