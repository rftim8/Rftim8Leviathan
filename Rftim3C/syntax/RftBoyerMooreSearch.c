#include "RftBoyerMooreSearch.h"

static int RftBMSearch(char* s, int n, char* p, int m) {
	int d[256];
	int i, j, k;

	for (i = 0; i < 256; i++)
		d[i] = m;

	for (j = 0; j < m - 1; j++)
		d[p[j]] = m - j - 1;

	i = m;
	j = m;
	while ((j > 0) && (i <= n)) {
		j = m;
		k = i;
		while ((j > 0) && (s[k - 1] == p[j - 1])) {
			k--;
			j--;
		}
		if (j > 0) {
			i = i + d[s[k - 1]];
		}
	}
	return j == 0 ? i - m : -1;
}

void RftBoyerMooreSearch() {
	char string[100];
	char model[20];
	int pos;

	//strcpy(sir,"mare e marea marmara");
	//strcpy(model,"marmara");

	strcpy(string, "papara pare papapagal");
	strcpy(model, "papagal");

	printf("Boyer-Moore Search...\n");
	pos = RftBMSearch(string, strlen(string), model, strlen(model));
	if (pos != -1) {
		printf("Model found at: %d...\n", pos);
	}
	else {
		printf("Model not found...\n");
	}
}
