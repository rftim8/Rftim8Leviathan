#pragma once
#include "rft_global_c.h"

static int initializeDynamicArray()
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

    while (scanf_s("%d", buf + i) == 1)
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

static void fibonacciGenerate(int n)
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

static void defineIntArray(int n, int *parray)
{
    for (int i = 0; i < n; i++)
    {
        printf("Value at [%d]: ", i);
        scanf_s(" %d", &parray[i]);
    }
}

static void displayIntArray(int n, int *parray)
{

    printf("Array values:  ");
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", parray[i]);
    }
}

static void findIntKeyInArray(int n, int *parray)
{

    int key, step_found = 0, step_count = 0;
    printf("Enter key to find: ");
    scanf_s(" %d", &key);

    for (int i = 0; i < n; i++)
    {
        if (key == parray[i])
        {
            step_count++;
            printf("Step: %d;\t Key found at: (%d)\n", step_count, i);
            step_found++;
        }
        else
            step_count++;
    }

    printf("Total steps performed: %d", step_count);
    SEPARATOR

    if (step_found == 0)
        printf("Entered key was not found!");
}

#pragma region StackArray
static int tab_st[100];
static int n_st = 0;

static void push(int x)
{
    tab_st[n_st++] = x;
}

static int pop()
{
    int x = tab_st[--n_st];

    return x;
}

static int top()
{
    return tab_st[n_st - 1];
}

static void stackArray()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    printf("%d\n", top());
    printf("%d\n", pop());
    printf("%d\n", top());
}
#pragma endregion

// -----------------------------------  SEARCHING  ----------------------------------------
static void binarySearch()
{
    int a[10] = {1, 7, 12, 33, 77, 84, 92, 100, 119, 124};
    int n = 10;
    int x = 92;
    int s, d, m;
    int found;

    s = 0;
    d = n - 1;
    found = 0;

    while ((s <= d) && (!found))
    {
        m = (s + d) / 2; /*any value between s and d*/

        if (a[m] == x)
            found = 1;
        else
        {
            if (a[m] < x)
                s = m + 1;
            else
                d = m - 1;
        }
    }

    if (found)
        printf("found at: %d", m);
}

static int boyerMooreSearch(char *s, int n, char *p, int m)
{
    int d[256];
    int i, j, k;

    for (i = 0; i < 256; i++)
        d[i] = m;

    for (j = 0; j < m - 1; j++)
        d[p[j]] = m - j - 1;

    i = m;
    j = m;

    while ((j > 0) && (i <= n))
    {
        j = m;
        k = i;

        while ((j > 0) && (s[k - 1] == p[j - 1]))
        {
            k--;
            j--;
        }

        if (j > 0)
            i = i + d[s[k - 1]];
    }

    return j == 0 ? i - m : -1;
}

static void boyerMooreSearch_0()
{
    char string[100];
    char model[20];
    int pos;

    // strcpy(sir,"mare e marea marmara");
    // strcpy(model,"marmara");

    strcpy_s(string, sizeof(string), "papara pare papapagal");
    strcpy_s(model, sizeof(model), "papagal");

    printf("Boyer-Moore Search...\n");
    pos = boyerMooreSearch(string, strlen(string), model, strlen(model));

    if (pos != -1)
        printf("Model found at: %d...\n", pos);
    else
        printf("Model not found...\n");
}

static void sort(int *tab, int n)
{
    int i, b;
    int aux;

    do
    {
        b = 0;

        for (i = 0; i < n - 1; i++)
        {
            if (tab[i] > tab[i + 1])
            {
                aux = tab[i];
                tab[i] = tab[i + 1];
                tab[i + 1] = aux;
                b = 1;
            }
        }
    } while (b == 1);
}

static void show(int *tab, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("%d ", tab[i]);
    }

    printf("\n");
}

static void bubbleSort()
{
    int t[10] = {1, 7, 1, 4, 3, 8, 9, 10, 23, 11};

    show(t, 10);
    sort(t, 10);
    show(t, 10);
}

static int search(char *s, int n, char *p, int m)
{
    int i, j;
    i = -1;

    do
    {
        i++;
        j = 0;
        while ((j < m) && (s[i + j] == p[j]))
            j++;
    } while ((j < m) && (i < n - m));

    return j == m ? i : -1;
}

static void directSearch()
{
    char string[100];
    char model[20];
    int pos;

    // strcpy(sir, "mare e marea marmara");
    // strcpy(model, "marmara");

    strcpy_s(string, sizeof(string), "papara pare papapagal");
    strcpy_s(model, sizeof(model), "papagal");

    printf("Cautare directa...\n");

    if ((pos = search(string, strlen(string), model, strlen(model))) != -1)
        printf("Model found at: %d...\n", pos);
    else
        printf("Model not found...\n");
}

static void linearSearch()
{
    static int a[10] = {1, 7, 12, 33, 77, 44, 2, 0, 19, 14};
    static int n = 10;
    static int x = 14;
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

static void linearSearchFlag()
{
    int a[11] = {1, 7, 12, 33, 77, 44, 2, 0, 19, 14};
    int n = 10;
    int x = 14;
    a[n] = x;
    int i = 0;

    while (a[i] != x)
    {
        i++;
    }

    if (i == n)
        printf("Flag not found");
    else
        printf("Flag found at: %d", i);
}

//-----------------------------------------------------------------------------------------

// ------------------------------------  SORTING  -----------------------------------------
static void bubbleSortIntArray(int n, int *parray)
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

static int compareFunction(const void *x, const void *y)
{
    int xx, yy;

    xx = *(int *)x;
    yy = *(int *)y;

    return (xx - yy);
}

static void qsortIntArray(int n, int *parray)
{
    printf("Sorted array: ");
    qsort(parray, (size_t)n, sizeof(int), compareFunction);

    for (int i = 0; i < n; i++)
    {
        printf(" %d", parray[i]);
    }
}

static void sort_q(int *tab, int s, int d)
{
    int i, j, m;
    int x, aux;

    m = (s + d) / 2;
    x = tab[m];
    i = s;
    j = d;

    do
    {
        while (tab[i] < x)
            i++;

        while (tab[j] > x)
            j--;

        if (i <= j)
        {
            aux = tab[i];
            tab[i] = tab[j];
            tab[j] = aux;
            i++;
            j--;
        }
    } while (i <= j);

    if (s < j)
        sort_q(tab, s, j);

    if (i < d)
        sort_q(tab, i, d);
}

static void show_q(int *tab, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", tab[i]);
    }

    printf("\n");
}

static void quickSort()
{
    int t[10] = {1, 7, 1, 4, 3, 8, 9, 10, 23, 11};

    show_q(t, 10);
    sort_q(t, 0, 9);
    show_q(t, 10);
}

static void sort_ins(int *tab, int n)
{
    int i, j;
    int aux;

    for (i = 1; i < n; i++)
    {
        aux = tab[i];
        j = i - 1;

        while (tab[j] > aux && j >= 0)
        {
            tab[j + 1] = tab[j];
            j--;
        }

        tab[j + 1] = aux;
    }
}

static void show_ins(int *tab, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", tab[i]);
    }

    printf("\n");
}

static void insertSort()
{
    int t[10] = {1, 7, 1, 4, 3, 8, 9, 10, 23, 11};

    show_ins(t, 10);
    sort_ins(t, 10);
    show_ins(t, 10);
}

static void sort_select(int *tab, int n)
{
    int i, j, posmin;
    int min;

    for (i = 0; i < n; i++)
    {
        min = tab[i];
        posmin = i;

        for (j = i + 1; j < n; j++)
        {
            if (min > tab[j])
            {
                min = tab[j];
                posmin = j;
            }
        }

        tab[posmin] = tab[i];
        tab[i] = min;
    }
}

static void show_select(int *tab, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", tab[i]);
    }

    printf("\n");
}

static void selectSort()
{
    int t[10] = {1, 7, 1, 4, 3, 8, 9, 10, 23, 11};

    show_select(t, 10);
    sort_select(t, 10);
    show_select(t, 10);
}

//-----------------------------------------------------------------------------------------

static void defineInt2DArray(int rows, int columns, int (*array)[5])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("Value at [%d][%d]: ", i, j);
            scanf_s(" %d", &array[i][j]);
        }
    }
}

static void displayInt2DArray(int rows, int columns, int (*array)[5])
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

static void displayMainDiagonalInt2DArray(int rows, int columns, int (*array)[5])
{
    printf("Main diagonal display: ");

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (i == j)
                printf(" %d  ", array[i][i]);
        }
    }
}

static void displayUpperTriangleMainInt2DArray(int rows, int columns, int (*array)[5])
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
            printf("\t");
    }
}

static void displayLowerTriangleMainInt2DArray(int rows, int columns, int (*array)[5])
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

static void displaySecondaryDiagonalInt2DArray(int rows, int columns, int (*array)[5])
{
    printf("Secondary diagonal: ");
    SEPARATOR
    int n = COMPARE_VALUES(rows, columns);

    if (rows == columns)
        n = rows;

    for (int i = n; i > 0; i--)
    {
        printf(" %d\t", array[i - 1][n - i]);
    }
}

static void displaySecondaryUpperTriangleInt2DArray(int rows, int columns, int (*array)[5])
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

static void displaySecondaryLowerTriangleInt2DArray(int rows, int columns, int (*array)[5])
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

static void sumOfVectorsInt2DArray(int rows, int columns, int (*array)[5])
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

static void averageOfVectorsInt2DArray(int rows, int columns, int (*array)[5])
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

static void smallestVectorInt2DArray(int rows, int columns, int (*array)[5])
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
                r = z;
        }
    }

    printf(" %d", r);
}

static void greatestVectorInt2DArray(int rows, int columns, int (*array)[5])
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
                r = z;
        }
    }

    printf(" %d", r);
}

static void findIntKeyIn2DArray(int rows, int columns, int (*array)[5])
{
    int key, step_found = 0, step_count = 0;
    printf("Enter key to find: ");
    scanf_s(" %d", &key);

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
                step_count++;
        }
    }

    printf("Total steps performed: %d", step_count);
    SEPARATOR

    if (step_found == 0)
        printf("Entered key was not found!");
}
