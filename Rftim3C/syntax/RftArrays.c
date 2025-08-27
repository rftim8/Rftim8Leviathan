#include "RftArrays.h"

int RftArrays()
{
	size_t len = 4;
	int *buf = malloc(len * sizeof *buf);

	if (buf == NULL)
	{
		printf("Not enough memory to allocate.\n");
		return 1;
	}

	size_t i = 0;
	int *temp;

	while (scanf("%d", buf + i) == 1)
	{
		i++;

		if (i == len)
		{
			temp = buf;
			len *= 2;
			buf = realloc(buf, len * sizeof *buf);

			if (buf == NULL)
			{
				printf("Not enough memory to reallocate.\n");
				buf = temp;
				break;
			}
		}
	}

	if (i == 0)
	{
		printf("No input read\n");
		return 1;
	}

	for (size_t j = 0; j < i; j++)
	{
		printf("%d ", buf[j]);
	}

	free(buf);
	buf = NULL;

	return 0;
}

static void RftFibonacciGenerate(int n)
{
	if (n < 101)
	{
		int fibo[100];

		fibo[0] = 0;
		fibo[1] = 1;

		for (int i = 2; i < n; i++)
		{
			fibo[i] = fibo[i - 1] + fibo[i - 2];
		}

		for (int j = 0; j < n; j++)
		{
			printf(" %d\n", fibo[j]);
		}
	}
	else
	{
		printf("n must be smaller than 100!");
	}
}

static void RftDefineIntArray(int n, int *parray)
{

	for (int i = 0; i < n; i++)
	{
		printf("Value at [%d]: ", i);
		scanf(" %d", &parray[i]);
	}
}

static void RftDisplayIntArray(int n, int *parray)
{

	printf("Array values:  ");
	for (int i = 0; i < n; i++)
	{
		printf("%d  ", parray[i]);
	}
}

static void RftFindIntKeyInArray(int n, int *parray)
{

	int key, step_found = 0, step_count = 0;
	printf("Enter key to find: ");
	scanf(" %d", &key);

	for (int i = 0; i < n; i++)
	{
		if (key == parray[i])
		{
			step_count++;
			printf("Step: %d;\t Key found at: (%d)\n", step_count, i);
			step_found++;
		}
		else
		{
			step_count++;
		}
	}

	printf("Total steps performed: %d", step_count);
	SEPARATOR

	if (step_found == 0)
		printf("Entered key was not found!");
}

// ------------------------------------  SORTING  -----------------------------------------
static void RftBubbleSortIntArray(int n, int *parray)
{

	printf("Array sorted: ");
	SEPARATOR
	int x;
	for (int i = n - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (parray[j] > parray[j + 1])
			{
				x = parray[j];
				parray[j] = parray[j + 1];
				parray[j + 1] = x;
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		printf(" %d\n", parray[i]);
	}
}

static int RftCompareFunction(const void *x, const void *y)
{

	int xx, yy;

	xx = *(int *)x;
	yy = *(int *)y;

	return (xx - yy);
}

static void RftQsortIntArray(int n, int *parray)
{

	printf("Sorted array: ");
	qsort(parray, (size_t)n, sizeof(int), RftCompareFunction);
	for (int i = 0; i < n; i++)
	{
		printf(" %d", parray[i]);
	}
}
//-----------------------------------------------------------------------------------------

static void RftDefineInt2DArray(int rows, int columns, int (*array)[5])
{

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			printf("Value at [%d][%d]: ", i, j);
			scanf(" %d", &array[i][j]);
		}
	}
}

static void RftDisplayInt2DArray(int rows, int columns, int (*array)[5])
{

	printf("Matrix values:");
	SEPARATOR
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			printf(" %d\t", array[i][j]);
		}
		printf("\n");
	}
}

static void RftDisplayMainDiagonalInt2DArray(int rows, int columns, int (*array)[5])
{

	printf("Main diagonal display: ");
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (i == j)
			{
				printf(" %d  ", array[i][i]);
			}
		}
	}
}

static void RftDisplayUpperTriangleMainInt2DArray(int rows, int columns, int (*array)[5])
{

	printf("Upper triangle main diagonal: ");
	SEPARATOR
	int counter = 0;
	for (int m = 0; m < rows; m++)
	{
		for (int i = m + 1; i < columns; i++)
		{
			printf(" %d\t", array[m][i]);
		}
		counter++;
		printf("\n\t");
		if (counter == 2)
		{
			printf("\t");
		}
	}
}

static void RftDisplayLowerTriangleMainInt2DArray(int rows, int columns, int (*array)[5])
{

	printf("Lower triangle main diagonal: ");
	SEPARATOR
	for (int j = 0; j < rows; j++)
	{
		for (int i = 0; i < j; i++)
		{
			printf(" %d\t", array[j][i]);
		}
		printf("\n");
	}
}

static void RftDisplaySecondaryDiagonalInt2DArray(int rows, int columns, int (*array)[5])
{

	printf("Secondary diagonal: ");
	SEPARATOR
	int n = COMPARE_VALUES(rows, columns);
	if (rows == columns)
	{
		n = rows;
	}
	for (int i = n; i > 0; i--)
	{
		printf(" %d\t", array[i - 1][n - i]);
	}
}

static void RftDisplaySecondaryUpperTriangleInt2DArray(int rows, int columns, int (*array)[5])
{

	printf("Secondary upper triangle: ");
	SEPARATOR
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < rows - i - 1; j++)
		{
			printf(" %d\t", array[i][j]);
		}
		printf("\n");
	}
}

static void RftDisplaySecondaryLowerTriangleInt2DArray(int rows, int columns, int (*array)[5])
{

	printf("Lower triangle secondary: ");
	SEPARATOR
	int counter = 3;
	for (int i = 0; i < rows; i++)
	{
		for (int j = rows - i; j < rows; j++)
		{
			printf(" %d\t", array[i][j]);
		}
		printf("\n");
		switch (counter)
		{
		case 3:
			printf("\t\t\t");
			counter--;
			break;
		case 2:
			printf("\t\t");
			counter--;
			break;
		case 1:
			printf("\t");
			counter--;
			break;
		default:
			break;
		}
	}
}

static void RftSumOfVectorsInt2DArray(int rows, int columns, int (*array)[5])
{

	printf("Sum of all vectors: ");
	int sum = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			sum = sum + array[i][j];
		}
	}
	printf(" %d", sum);
}

static void RftAverageOfVectorsInt2DArray(int rows, int columns, int (*array)[5])
{

	printf("Average of vectors: ");
	SEPARATOR
	int sum = 0;
	int nrVectors = 0;
	float averageResult;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			sum = sum + array[i][j];
			nrVectors++;
		}
	}
	averageResult = (float)sum / (float)nrVectors;
	printf(" %.2f", averageResult);
}

static void RftSmallestVectorInt2DArray(int rows, int columns, int (*array)[5])
{

	printf("Smallest vector in array: ");
	SEPARATOR
	int z = 0, r = array[0][0];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			z = array[i][j];
			if (r < z)
			{
				r = z;
			}
		}
	}
	printf(" %d", r);
}

static void RftGreatestVectorInt2DArray(int rows, int columns, int (*array)[5])
{

	printf("Greatest vector in array: ");
	SEPARATOR
	int z = 0, r = array[0][0];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			z = array[i][j];
			if (z > r)
			{
				r = z;
			}
		}
	}
	printf(" %d", r);
}

static void RftFindIntKeyIn2DArray(int rows, int columns, int (*array)[5])
{

	int key, step_found = 0, step_count = 0;
	printf("Enter key to find: ");
	scanf(" %d", &key);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (key == array[i][j])
			{
				step_count++;
				printf("Step: %d;\t Key found at: (%d,%d)\n", step_count, i, j);
				step_found++;
			}
			else
			{
				step_count++;
			}
		}
	}

	printf("Total steps performed: %d", step_count);
	SEPARATOR

	if (step_found == 0)
		printf("Entered key was not found!");
}
