#include "RftBubbleSort.h"

static void RftSort(int* tab, int n) {
	int i, b;
	int aux;
	do {
		b = 0;
		for (i = 0; i < n - 1; i++) {
			if (tab[i] > tab[i + 1]) {
				aux = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = aux;
				b = 1;
			}
		}
	} while (b == 1);
}

static void Show(int* tab, int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", tab[i]);
	}
	printf("\n");
}

void RftBubbleSort() {
	int t[10] = { 1, 7, 1, 4, 3, 8, 9, 10, 23, 11 };

	Show(t, 10);
	RftSort(t, 10);
	Show(t, 10);
}
