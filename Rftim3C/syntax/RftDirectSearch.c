#include "RftDirectSearch.h"

static int RftSearch(char* s, int n, char* p, int m) {
	int i, j;
	i = -1;
	do {
		i++;
		j = 0;
		while ((j < m) && (s[i + j] == p[j])) j++;
	} while ((j < m) && (i < n - m));

	return j == m ? i : -1;
}

void RftDirectSearch() {
	char string[100];
	char model[20];
	int pos;

	//strcpy(sir, "mare e marea marmara");
	//strcpy(model, "marmara");

	strcpy(string, "papara pare papapagal");
	strcpy(model, "papagal");

	printf("Cautare directa...\n");
	if ((pos = RftSearch(string, strlen(string), model, strlen(model))) != -1) {
		printf("Model found at: %d...\n", pos);
	}
	else {
		printf("Model not found...\n");
	}
}
