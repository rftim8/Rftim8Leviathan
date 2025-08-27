#include "RftBinarySearch.h"

static int a[10] = { 1,7,12,33,77,84,92,100,119,124 };
static int n = 10;
static int x = 92;
static int s, d, m;
static int found;

void RftBinarySearch() {
	s = 0;
	d = n - 1;
	found = 0;
	while ((s <= d) && (!found)) {
		m = (s + d) / 2; /*any value between s and d*/
		if (a[m] == x) {
			found = 1;
		}
		else {
			if (a[m] < x) {
				s = m + 1;
			}
			else {
				d = m - 1;
			}
		}
	}
	if (found) {
		printf("found at: %d", m);
	}
}
