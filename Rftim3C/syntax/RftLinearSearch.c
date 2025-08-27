#include "RftLinearSearch.h"

static int a[10] = {1, 7, 12, 33, 77, 44, 2, 0, 19, 14};
static int n = 10;
static int x = 14;

void RftLinearSearch()
{
	int i = 0;
	while ((i < n - 1) && (a[i] != x))
	{
		i++;
	}

	if (a[i] != x)
		printf("Not found");
	else
		printf("Found at: %d", i);
}
