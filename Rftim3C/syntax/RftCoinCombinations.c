#include "RftCoinCombinations.h"

static int s = 150;
static int n = 6;
static int mod[6];
static int m[6] = { 500,100,50,10,5,1 };
static int sol = 0;

static void Show() {
	int i;
	sol++;

	printf("Coins:   ");
	for (i = 0; i < n; i++)
		printf("%03d  ", m[i]);
	printf("\n");

	printf("Solution %d:  ", sol);
	for (i = 0; i < n; i++)
		printf("%03d ", mod[i]);

	printf("\n");
	printf("\n");
}

static int valid() {
	int sum = 0;

	for (int i = 0; i < n; i++)
		sum = sum + mod[i] * m[i];

	return sum == s;
}

static void back(int k) {
	int j;

	if (k < n) {
		for (j = 0; j < s; j++) {
			mod[k] = j;
			back(k + 1);
		}
	}
	else {
		if (valid())
			Show();
	}
}

void RftCoinCombinations() {
	back(0);
}
