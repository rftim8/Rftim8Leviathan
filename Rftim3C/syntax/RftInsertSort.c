#include "RftInsertSort.h"

static void RftSort(int* tab, int n) {
	int i, j;
	int aux;
	for (i = 1; i < n; i++) {
		aux = tab[i];
		j = i - 1;
		while (tab[j] > aux && j >= 0) {
			tab[j + 1] = tab[j];
			j--;
		}
		tab[j + 1] = aux;
	}
}

static void Show(int* tab, int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", tab[i]);
	}
	printf("\n");
}

void RftInsertSort() {
	int t[10] = { 1,7,1,4,3,8,9,10,23,11 };
	Show(t, 10);
	RftSort(t, 10);
	Show(t, 10);
}
