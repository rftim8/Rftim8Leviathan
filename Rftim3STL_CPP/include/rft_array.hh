#pragma once
#include "rft_global_cpp.hh"

// --------------------------------------------------------- Searching ---------------------------------------------------------
static void binarySearch()
{
    int a[] = {123, 12, 1, 34, 324, 345, 35, 4534, 3, 2};
    int n = std::size(a), x = 345;
    int left = 0;
    int right = n - 1;
    int mid;
    int found = 0;

    while ((left <= right) && (!found))
    {
        mid = (left + right) / 2;

        if (a[mid] == x)
            found = 1;
        else
        {
            if (a[mid] < x)
                left = mid + 1;
            else
                right = mid - 1;
        }
    }

    // if (found)
    //     cout << "Found at: " << mid;
}

static void binarySearchEfficient()
{
    int n = 10;
    std::vector<int> array = {123, 12, 1, 34, 324, 345, 35, 4534, 3, 2};
    int x = 345;
    int k = 0;

    for (int b = n / 2; b >= 1; b /= 2)
    {
        while (k + b < n && array[k + b] <= x)
            k += b;
    }

    if (array[k] == x)
        std::cout << "Flag found at: " << k << "\n";
}

static void printBinarySearchMain()
{
    binarySearch();
    double t0 = getCurrentTime();
    std::cout << t0 << "\n";
    RFT_SEPARATOR

    binarySearchEfficient();
    double t1 = getCurrentTime();
    std::cout << t1 << "\n";
    RFT_SEPARATOR

    double t2 = t1 - t0;
    std::cout << std::fixed << std::setprecision(10) << t2 << "\n";
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

static void printBoyerMooreSearchMain()
{
    char s[100] = "trala lsls tralalalal";
    char t[20] = "alal";

    std::cout << boyerMooreSearch(s, std::size(s), t, std::size(t));
    RFT_SEPARATOR
}

static int directSearch(char *bm, int n, char *model, int m)
{
    int i, j;
    i = -1;

    do
    {
        i++;
        j = 0;

        while ((j < m) && (bm[i + j] == model[j]))
            j++;
    } while ((j < m) && (i < n - m));

    return j == m ? i : -1;
}

static void printDirectSearchMain()
{
    char bm[100];
    char model[20];

    std::cout << directSearch(bm, 100, model, 20) << "\n";
}

#define NMax 1000
#define MMax 255

static int next1[MMax];
static char t[NMax], p[MMax];
static int n, m;

static void next0(char *p)
{
    int k = -1, x;
    next1[0] = 0;

    for (x = 1; x < m; x++)
    {
        while (k > 0 && p[k + 1] != p[x])
        {
            k = next1[k];
        }

        if (p[k + 1] == p[x])
            k++;

        next1[x] = k;
    }
}

static void KnuthMorrisPratt()
{
    int i, x = -1;
    std::ifstream fin("RftConstruct/KnuthMorrisPratt.in");
    std::ofstream fout("RftConstruct/KnuthMorrisPratt.out");
    fin.getline(t, 1000);
    fin.getline(p, 255);
    n = strlen(t);
    m = strlen(p);
    next0(p);

    for (i = 0; i < n; i++)
    {
        while (x > 0 && p[x + 1] != t[i])
        {
            x = next1[x];
        }

        if (p[x + 1] == t[i])
            x++;

        if (x == m - 1)
        {
            fout << "Found substring at position: " << i - m + 1 << "\n";
            x = next1[x];
        }
    }

    fout.close();
}

static void linearSearch(int *array, int n)
{
    int i = 0;
    int x = 33;

    while ((i < n - 1) && (array[i] != x))
    {
        i++;
    }

    if (array[i] != x)
        std::cout << "Flag not found!\n";
    else
        std::cout << "Flag found at position: " << i;
}

static void printLinearSearchMain()
{
    int arr[] = {123, 2, 5, 5, 56, 8, 95, 3};

    linearSearch(arr, 5);
}

static void linearSearchFlag(int *array, int n)
{
    int x = 33;
    array[n] = x;
    int i = 0;

    while (array[i] != x)
    {
        i++;
    }

    if (i == n)
        std::cout << "Flag not found!\n";
    else
        std::cout << "Flag found at position: " << i << "\n";
}

static void printLinearSearchFlagMain()
{
    int arr[] = {123, 324, 435, 9, 54, 5647, 5, 1, 2};

    linearSearchFlag(arr, 5);
}
// -----------------------------------------------------------------------------------------------------------------------------

// ---------------------------------------------------------- Sorting ----------------------------------------------------------
static void sort1DArray(int n, int *p)
{
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (p[j] > p[j + 1])
            {
                int x = p[j];
                p[j] = p[j + 1];
                p[j + 1] = x;
            }
        }
    }
}

#pragma region BubbleSort
static void printBubbleSortMain()
{
    int a0[] = {23, 32, 24312, 31, 24, 32, 324, 23, 4, 898};

    sort1DArray(std::size(a0), a0);

    for (auto &&i : a0)
    {
        std::cout << i << " ";
    }
    RFT_SEPARATOR
}
#pragma endregion

#define Max 1000
#define MaxNr 10000
static int n_hanoi, V[Max], a[MaxNr];

#pragma region CountSort
static void countingSort()
{
    int x, i, j, nr;
    std::cout << "n = ";
    std::cin >> n_hanoi;

    for (i = 0; i < n_hanoi; i++)
    {
        std::cout << "Enter a new value: ";
        std::cin >> x;
        V[x]++;
    }

    for (nr = i = 0; i < Max; i++)
    {
        for (j = 0; j < V[i]; j++)
        {
            a[nr++] = i;
        }
    }

    for (i = 0; i < n_hanoi; i++)
    {
        std::cout << a[i] << ' ';
    }
}
#pragma endregion

#pragma region HanoiTower
static std::ofstream fout("RftConstruct/HanoiTowers.out");

static void moveDisc(int x, int i, int j)
{
    if (x > 1)
    {
        moveDisc(x - 1, i, 6 - i - j);
        fout << i << "  ->  " << j << "\n";
        moveDisc(x - 1, 6 - i - j, j);
    }
    else
        fout << i << "  ->  " << j << "\n";
}

static void hanoiTowers()
{
    int n;
    std::cout << "n = ";
    std::cin >> n;
    moveDisc(n, 1, 2);
    fout.close();
}
#pragma endregion

#pragma region InsertSort
static void insertSort()
{
    int i, n = 10, pos, v;
    int a[10] = {34, 43, 786, 98, 3, 25, 7, 8, 3, 2};

    for (i = 1; i < n; i++)
    {
        v = a[i];

        for (pos = i; pos && a[pos - 1] > v; pos--)
        {
            a[pos] = a[pos - 1];
        }

        a[pos] = v;
    }

    for (int j = 0; j < 10; j++)
    {
        std::cout << a[j] << ' ';
    }
}

static void insertSort0(int *array, int n)
{
    int i, j;
    int aux;

    for (i = 1; i < n; i++)
    {
        aux = array[i];
        j = i - 1;

        while (array[j] > aux && j >= 0)
        {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = aux;
    }
}
#pragma endregion

#pragma region MergeSort
static void mergeSort()
{
    int i, j, k, n = 5, m = 5;
    int a[5] = {3, 5, 12, 34, 89};
    int b[5] = {3, 9, 17, 29, 35};
    int c[10] = {};

    for (i = j = k = 0; i < n && j < m;)
    {
        if (a[i] < b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }

    for (; i < n; i++)
    {
        c[k++] = a[i];
    }

    for (; j < m; j++)
    {
        c[k++] = b[j];
    }

    for (int l = 0; l < 10; l++)
    {
        std::cout << c[l] << ' ';
    }
}
#pragma endregion

#pragma region Merge Sort Divide And Conquer
static int a_msdc[100], n_msdc;
static void read0();
static void print0();
static void sort0(int, int, int);
static void msort(int, int);

static void read0()
{
    std::ifstream fin("MergeSortDivideAndConquer.in");
    fin >> n_msdc;

    for (int i = 0; i < n_msdc; i++)
    {
        fin >> a_msdc[i];
    }

    fin.close();
}

static void print0()
{
    std::cout << "Sorted vector = ";

    for (int i = 0; i < n_msdc; i++)
    {
        std::cout << a_msdc[i] << ' ';
    }

    std::cout << "\n";
}

static void sort0(int p, int m, int q)
{
    int i = p, j = m + 1, k = 0;
    int b[100]{};

    while (i <= m && j <= q)
    {
        if (a_msdc[i] < a_msdc[j])
            b[k++] = a_msdc[i++];
        else
            b[k++] = a_msdc[j++];
    }

    while (i <= m)
    {
        b[k++] = a_msdc[i++];
    }

    while (j <= q)
    {
        b[k++] = a_msdc[j++];
    }

    for (i = p; i <= q; i++)
    {
        a_msdc[i] = b[i - p];
    }
}

static void msort(int p, int q)
{
    if (q > p)
    {
        int m = (p + q) / 2;
        msort(p, m);
        msort(m + 1, q);
        sort0(p, m, q);
    }
}

static void mergeSortDivideAndConquer()
{
    read0();
    msort(0, n_msdc - 1);
    print0();
}
#pragma endregion

#pragma region QuickSort
static int compareFunctions(const void *x, const void *y)
{
    int xx, yy;

    xx = *(int *)x;
    yy = *(int *)y;

    return (xx - yy);
}

static void quickSortInt1DArray(int n, int *p)
{
    qsort(p, (size_t)n, sizeof(int), compareFunctions);
}

static void printQuickSortMain()
{
    int a0[] = {234, 324, 23, 4, 23, 4, 53, 45, 56, 65, 778, 1};
    quickSortInt1DArray(std::size(a0), a0);

    for (auto &&i : a0)
    {
        std::cout << i << " ";
    }

    RFT_SEPARATOR
}
#pragma endregion

#pragma region QuickSort
static int a_qs[100], n_qs;

static void read1()
{
    std::ifstream fin("QuickSortExplicit.in");
    fin >> n_qs;

    for (int i = 0; i < n_qs; i++)
    {
        fin >> a_qs[i];
    }

    fin.close();
}

static void print1()
{
    std::cout << "Sorted vector = ";

    for (int i = 0; i < n_qs; i++)
    {
        std::cout << a_qs[i] << ' ';
    }

    std::cout << "\n";
}

static int divide1(int p, int q)
{
    int left = p, right = q, x = a_qs[p];

    while (left < right)
    {
        while (left < right && a_qs[right] >= x)
        {
            right--;
        }

        a_qs[left] = a_qs[right];

        while (left < right && a_qs[left] <= x)
        {
            left++;
        }

        a_qs[right] = a_qs[left];
    }

    a_qs[left] = x;

    return left;
}

static void qsort1(int p, int q)
{
    int m = divide1(p, q);

    if (m - 1 > p)
        qsort1(p, m - 1);

    if (m + 1 < q)
        qsort1(m + 1, q);
}

static void quickSort1(int *array, int left, int right)
{
    int i, j, m;
    int x, aux;
    m = (left + right) / 2;
    x = array[m];
    i = left;
    j = right;

    do
    {
        while (array[i] < x)
            i++;

        while (array[j] > x)
            j--;

        if (i <= j)
        {
            aux = array[i];
            array[i] = array[j];
            array[j] = aux;
            i++;
            j--;
        }
    } while (i <= j);

    if (left < j)
        quickSort1(array, left, j);

    if (i < right)
        quickSort1(array, i, right);
}

static void quickSort()
{
    read1();
    qsort1(0, n_qs - 1);
    print1();
}
#pragma endregion

#pragma region SelectSort
static void selectSort()
{
    int dr, n = 10, i, max, posmax;
    int a[10] = {23, 3, 12, 34, 2, 6, 8, 5, 1, 4};

    for (dr = n - 1; dr > 0; dr--)
    {
        for (max = a[0], posmax = 0, i = 1; i <= dr; i++)
        {
            if (a[i] > max)
            {
                max = a[i];
                posmax = i;
            }
        }

        a[posmax] = a[dr];
        a[dr] = max;
    }

    for (int j = 0; j < 10; j++)
    {
        std::cout << a[j] << ' ';
    }

    std::cout << "\n";
}

static void selectionSort0(int *array, int n)
{
    int i, j, posmin;
    int min;

    for (i = 0; i < n; i++)
    {
        min = array[i];
        posmin = i;

        for (j = i + 1; j < n; j++)
        {
            if (min > array[j])
            {
                min = array[j];
                posmin = j;
            }
        }

        array[posmin] = array[i];
        array[i] = min;
    }
}
#pragma endregion

#pragma region Kruskal
#define NMaxV 50
#define NMaxE NMaxV *(NMaxV - 1) / 2

struct Edge
{
    int e1, e2, cost;
};

static Edge g_k[NMaxE];
static int a_k[NMaxV], c_k[NMaxV];
static int n_k, m_k;

static void read2()
{
    int i;
    std::ifstream fin("RftConstruct/Kruskal.in");
    fin >> n_k >> m_k;

    for (i = 1; i <= m_k; i++)
    {
        fin >> g_k[i].e1 >> g_k[i].e2 >> g_k[i].cost;
    }

    for (i = 1; i <= n_k; i++)
    {
        c_k[i] = i;
    }

    fin.close();
}

static void print2()
{
    int i, costMPT = 0;
    std::cout << "Minimum cost partial tree = ";

    for (i = 1; i < n_k; i++)
    {
        std::cout << "[" << g_k[a_k[i]].e1 << "," << g_k[a_k[i]].e2 << "]	cost = " << g_k[a_k[i]].cost << "\n";
        costMPT += g_k[a_k[i]].cost;
    }

    std::cout << "Cost MPT = " << costMPT << "\n";
}

static void sortEdges(int left, int right)
{
    int i, j;
    Edge x;

    if (left < right)
    {
        x = g_k[left];
        i = left;
        j = right;

        while (i < j)
        {
            while (i < j && g_k[j].cost >= x.cost)
            {
                j--;
            }

            g_k[i] = g_k[j];

            while (i < j && g_k[i].cost <= x.cost)
            {
                i++;
            }

            g_k[j] = g_k[i];
        }

        g_k[i] = x;
        sortEdges(left, i - 1);
        sortEdges(i + 1, right);
    }
}

static void kruskal()
{
    int i, j, min{}, max{}, NMsel;
    read2();
    sortEdges(1, m_k);
    NMsel = 0;

    for (i = 1; NMsel < n_k - 1; i++)
    {
        if (c_k[g_k[i].e1] != c_k[g_k[i].e2])
        {
            a_k[++NMsel] = i;

            if (c_k[g_k[i].e1] < c_k[g_k[i].e2])
            {
                min = c_k[g_k[i].e1];
                max = c_k[g_k[i].e2];
            }
            else
            {
                min = c_k[g_k[i].e2];
                max = c_k[g_k[i].e1];
            }
        }

        for (j = 1; j <= n_k; j++)
        {
            if (c_k[j] == max)
                c_k[j] = min;
        }
    }

    print2();
}
#pragma endregion

#pragma region Backpack
#define NMax_b 101
#define MaxG_b 301

static int n_b, gmax, c_b[NMax_b], g_b[NMax_b], cmax[MaxG_b], used[MaxG_b][NMax_b];

static void read3()
{
    std::ifstream fin("RftConstruct/Backpack.in");
    int i;
    fin >> n_b >> gmax;

    for (i = 1; i <= n_b; i++)
    {
        fin >> g_b[i];
    }

    for (i = 1; i <= n_b; i++)
    {
        fin >> c_b[i];
    }

    fin.close();
}

static void solve3()
{
    int s, k, i;

    for (s = 1; s <= gmax; s++)
    {
        cmax[s] = -1;
    }

    for (s = 1; s <= gmax; s++)
    {
        for (i = 1; i <= n_b; i++)
        {
            if (g_b[i] <= s && cmax[s - g_b[i]] != -1 && !used[s - g_b[i]][i])
            {
                if (cmax[s] < c_b[i] + cmax[s - g_b[i]])
                {
                    cmax[s] = c_b[i] + cmax[s - g_b[i]];

                    for (k = 1; k <= n_b; k++)
                    {
                        used[s][k] = used[s - g_b[i]][k];
                    }

                    used[s][i] = i;
                }
            }
        }
    }
}

static void print3()
{
    std::ofstream fout("RftConstruct/Backpack.out");

    if (cmax[gmax] == -1)
        fout << "Not posible";
    else
    {
        fout << cmax[gmax] << "\n";

        for (int k = 1; k <= n_b; k++)
        {
            if (used[gmax][k])
                fout << k << " ";
        }
    }

    fout.close();
}

static void backpack()
{
    read3();
    solve3();
    print3();
}
#pragma endregion
// -----------------------------------------------------------------------------------------------------------------------------
