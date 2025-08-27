#pragma once
#include "rft_global_cpp.hh"

/**
 * Algebra
 * Calculus
 * Combinatorics
 * Geometry
 * Graph Theory
 * Number Theory
 * Set Theory
 * Topology
 * Trigonometry
 */

#pragma region GaussMean
static int n_g, a_g, b_g;
static float rec_a(int), rec_b(int);

static float rec_a(int n_g)
{
    if (!n)
        return a_g;

    return (rec_a(n_g - 1) + rec_b(n_g - 1)) / 2;
}

static float rec_b(int n_g)
{
    if (!n_g)
        return b_g;

    return sqrt(rec_a(n_g - 1) * rec_b(n_g - 1));
}

static void arithmeticGeometricMeanGauss()
{
    std::cout << "a = ";
    std::cin >> a_g;
    std::cout << "b = ";
    std::cin >> b_g;
    std::cout << "n = ";
    std::cin >> n;
    std::cout << "b(" << n << ")=" << rec_b(n) << " a(" << n << ")=" << rec_a(n) << "\n";
}
#pragma endregion

#pragma region Aritmetic Progression
static void sumValuesOfArithmeticProgression()
{
    std::vector<int> a = {3, 7, 11, 15};
    int diff = a[1] - a[0];

    std::cout << diff * (a.front() + a.back()) / 2 << "\n";
}

static void printArithmeticProgressionMain()
{
    std::vector<int> a = {3, 7, 11, 15};

    int diff = a[1] - a[0];
    std::cout << "Progression value: " << diff << "\n";

    std::cout << "Sum of vector values: ";
    sumValuesOfArithmeticProgression();
}
#pragma endregion

#pragma region Average
static void average()
{
    double a, s = 0;
    int n, i = 0, nr = 0;

    std::cout << "Enter number of values: ";
    std::cin >> n;

    while (i < n)
    {
        std::cout << "Enter a value: ";
        std::cin >> a;
        i++;

        if (a > 0)
        {
            s += a;
            nr++;
        }
    }

    if (nr)
        std::cout << "Average = " << s / nr << "\n";
    else
        std::cout << "Can't calculate average!\n";
}
#pragma endregion

#pragma region Catching Up
static void catchingUp()
{
    float v1, v2, t;

    std::cout << "Speed of car 1 =  ";
    std::cin >> v1;
    std::cout << "Speed of car 2 =  ";
    std::cin >> v2;
    std::cout << "Time after car 2 appears =  ";
    std::cin >> t;
    std::cout << (v2 > v1 ? v1 * t / (v2 - v1) : -1) << "\n";
}
#pragma endregion

#pragma region DecomposeToFactors
static void decomposeToFactors()
{
    int n, d, m;
    std::cout << "Enter a number: ";
    std::cin >> n;

    for (d = 2; n > 1; d++)
    {
        for (m = 0; n % d == 0; m++, n /= d)
            ;
        if (m)
            std::cout << "Divisor " << d << " multiplied " << m << "\n";
    }
}
#pragma endregion

#pragma region Factorial
static unsigned long fact0(int);
static unsigned long fact1(int);

static void factorial()
{
    int n = 5;

    std::cout << fact0(n) << "\n";
    std::cout << fact1(n) << "\n";
}

static unsigned long fact0(int n)
{
    if (!n)
        return 1;

    return n * fact0(n - 1);
}

static unsigned long fact1(int n)
{
    unsigned long f = 1;

    for (int i = 1; i <= n; i++)
    {
        f *= i;
    }

    return f;
}
#pragma endregion

#pragma region Fence Painting
static void fencesPainting()
{
    long int n, i, p, q, unp, red, blue, purple;

    std::cout << "Enter the number of fences: ";
    std::cin >> n;
    std::cout << "Enter skip step for red: ";
    std::cin >> p;
    std::cout << "Enter skip step for blue: ";
    std::cin >> q;

    unp = red = blue = purple = 0;

    for (i = 1; i <= n; i++)
    {
        if (i % p == 0 && i % q == 0)
            purple++;
        else
        {
            if (i % p == 0)
                red++;
            else
            {
                if (i % q == 0)
                    blue++;
                else
                    unp++;
            }
        }
    }

    std::cout << unp << ' ' << red << ' ' << blue << ' ' << purple << "\n";
}
#pragma endregion

#pragma region Fibonacci
static void binet(int n);
static void fibonacciArray(int n);

static void printFibonacciMain()
{
    for (int i = 0; i < 10; i++)
    {
        binet(i);
        std::cout << " ";
    }

    std::cout << "\n";

    fibonacciArray(10);
}

static void binet(int n)
{
    std::cout << (pow((1 + sqrt(5)), n) - pow((1 - sqrt(5)), n)) / (pow(2, n) * sqrt(5));
}

static void fibonacciArray(int n)
{
    std::vector<int> fibo(n, 0);

    fibo[0] = 0;
    fibo[1] = 1;

    for (int i = 2; i < n; i++)
    {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }

    for (auto &&i : fibo)
    {
        std::cout << i << " ";
    }

    std::cout << "\n";
}
#pragma endregion

#pragma region GCD
static void gcd0();
static unsigned gcd1(unsigned, unsigned);

static void GCD()
{
    unsigned x = 20, y = 15;

    // gcd0();
    std::cout << gcd1(x, y) << "\n";
}

static void gcd0()
{
    int n, m, rem;

    std::cout << "Enter first number: ";
    std::cin >> n;
    std::cout << "Enter second number: ";
    std::cin >> m;

    while (m)
    {
        rem = n % m;
        n = m;
        m = rem;
    }

    std::cout << "GCD = " << n << "\n";
}

static unsigned gcd1(unsigned x, unsigned y)
{
    if (!y)
        return x;

    return gcd1(y, x % y);
}
#pragma endregion

#pragma region GCD Euclid
#define NMax_ge 20

static unsigned a_ge[NMax_ge];
static int n_ge;
static void read_ge();
static unsigned euclid_ge(unsigned, unsigned);
static unsigned gcd_ge(unsigned, unsigned);

static void GCDEuclid()
{
    read_ge();

    std::cout << "GCD = " << gcd_ge(0, n_ge - 1) << "\n";
}

static void read_ge()
{
    std::ifstream fin("RftConstruct/GCDEuclid.in");
    fin >> n_ge;

    for (int i = 0; i < n_ge; i++)
    {
        fin >> a_ge[i];
    }

    fin.close();
}

static unsigned euclid_ge(unsigned x, unsigned y)
{
    unsigned r;

    while (y)
    {
        r = x % y;
        x = y;
        y = r;
    }

    return x;
}

static unsigned gcd_ge(unsigned p, unsigned q)
{
    if (q - p <= 1)
        return euclid_ge(a_ge[p], a_ge[q]);

    unsigned m = (p + q) / 2;

    return euclid_ge(gcd_ge(p, m), gcd_ge(m + 1, q));
}
#pragma endregion

#pragma region Geometric Progression
static void printGeometricProgressionMain()
{
    std::vector<int> a = {3, 6, 12, 24};

    int ratio = 2;

    std::cout << (a.back() * ratio - a.front()) / (ratio - 1) << "\n";
}
#pragma endregion

#pragma region GPA
static std::ifstream fin_gpa("RftConstruct/GPA.in");
static std::ofstream fout_gpa("RftConstruct/GPA.out");
static float avg, nt;
static int n_gpa[12], found;
static void print_gpa(int);
static float avg_gpa(int);
static void calc_gpa(int);
static void read_gpa();

static void GPA()
{
    read_gpa();
}

static void read_gpa()
{
    fin_gpa >> avg >> nt;
    found = 0;

    calc_gpa(1);

    if (!found)
        fout_gpa << "No solution";

    fin_gpa.close();
    fout_gpa.close();
}

static void print_gpa(int k)
{
    for (int i = 1; i <= k; i++)
    {
        fout_gpa << n_gpa[i] << ' ';
    }

    fout_gpa << "\n";
    found = 1;
}

static float avg_gpa(int k)
{
    float s, mn, mc;

    if (k > 2)
    {
        s = 0;

        for (int i = 0; i <= k; i++)
        {
            s += n_gpa[i];
        }

        mn = s / k;
        mc = (nt + 3.0f * mn) / 4.0f;

        return mc;
    }

    return 0;
}

static void calc_gpa(int k)
{
    if (k < 11)
    {
        for (int i = n_gpa[k - 1]; i <= 10; i++)
        {
            n_gpa[k] = i;

            if (avg_gpa(k) == avg)
                print_gpa(k);

            calc_gpa(k + 1);
            n_gpa[k] = 0;
        }
    }
}
#pragma endregion

#pragma region LCM
static void LCM()
{
    long int n, m, p, q, a, b, r, unp, red, blue, purple;

    std::cout << "Enter the number of fences: ";
    std::cin >> n;
    std::cout << "Enter the skip steps for red: ";
    std::cin >> p;
    std::cout << "Enter the skip steps for blue: ";
    std::cin >> q;

    a = p;
    b = q;

    while (b)
    {
        r = a % b;
        a = b;
        b = r;
    }

    m = p * q / a;
    purple = n / m;
    red = n / p - purple;
    blue = n / q - purple;
    unp = n - red - blue - purple;

    std::cout << unp << ' ' << red << ' ' << blue << ' ' << purple << "\n";
}
#pragma endregion

#pragma region Logarithm
static void genericBase();
static void naturalLogarithm();

static void printLogarithmMain()
{
    std::cout << log2(32) << "\n";
    std::cout << log2(2) + log2(16) << "\n";
    std::cout << log2(pow(4, 3)) << " = " << 3 * log2(4) << "\n";
    std::cout << log2(16 / 4) << " = " << log2(16) - log2(4) << "\n"; // quotient

    genericBase();
    naturalLogarithm();
}

static void genericBase()
{
    int base = 2;
    int x = 16;

    std::cout << log2(x) << " = " << log10(x) / log10(base) << "\n";
    std::cout << log10(x) << "\n";
    std::cout << log10(base) << "\n";
}

static void naturalLogarithm()
{
    std::cout << log(16) << "\n";
}
#pragma endregion

#pragma region Manna Pnueli
#define DimMax_mp 100

static int S_mp[DimMax_mp], x_mp, y_mp, V_mp;

static void MannaPnueli()
{
    std::cout << " x= ";
    std::cin >> x_mp;
    S_mp[V_mp] = x_mp;

    while (V_mp >= 0)
    {
        y_mp = S_mp[V_mp];

        if (y_mp >= 12)
        {
            if (--V_mp >= 0)
                S_mp[V_mp] = y_mp - 1;
        }
        else
            S_mp[++V_mp] = y_mp + 2;

        std::cout << y_mp << ' ';
    }

    std::cout << "f (" << x_mp << ") = " << y_mp - 1;
}
#pragma endregion

#pragma region Max Area 1D Vector
static int printMaxArea1DVector(std::vector<int> &height)
{
    int res = 0;
    int l = 0;
    int r = height.size() - 1;
    int maxh = 0;

    for (auto item : height)
    {
        maxh = std::max(maxh, item);
    }

    while (l < r)
    {
        int v = std::min(height[l], height[r]) * (r - l);
        res = std::max(res, v);

        if (maxh * (r - l) <= res)
            break;

        if (height[l] < height[r])
            l++;
        else
            r--;
    }

    return res;
}

static void printMaxArea1DVectorMain()
{
    std::vector<int> x = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    std::cout << printMaxArea1DVector(x) << "\n";
}
#pragma endregion

#pragma region Median 1D Vector
static double printMedian1DVector(std::vector<int> &nums1, std::vector<int> &nums2)
{
    std::vector<int> x;

    for (auto item : nums1)
        x.push_back(item);

    for (auto item : nums2)
        x.push_back(item);

    sort(x.begin(), x.end());
    int l = x.size();
    int mid = l / 2;

    return l % 2 ? x[mid] : (x[mid - 1] + x[mid]) / 2.0;
}

static void printMedian1DVectorMain()
{
    std::vector<int> nums1 = {1, 3};
    std::vector<int> nums2 = {2, 8};

    std::cout << printMedian1DVector(nums1, nums2) << "\n";
}
#pragma endregion

#pragma region Modulo M
static void printModuloMMain()
{
    int mod = 1e9 + 7;
    int x = 1;

    for (int i = 2; i <= 10; i++)
    {
        x = (x * i) % mod;
    }

    std::cout << x << "\n";
}
#pragma endregion

#pragma region Number Generator
static int c_ng[10], n_ng, lg_ng;
static unsigned long x_ng;
static std::ofstream fout_ng("RftConstruct/NumberGenerator.out");
static void digits_ng(int);
static void gen_ng(int);

static void numberGenerator()
{
    std::cout << "n, lg = ";
    std::cin >> n_ng >> lg_ng;
    digits_ng(n_ng);
    gen_ng(0);
    fout_ng.close();
}

static void digits_ng(int x_ng)
{
    do
    {
        c_ng[x_ng % 10] = 1;
        x_ng /= 10;
    } while (x_ng);
}

static void gen_ng(int k_ng)
{
    if (k_ng == lg_ng)
        fout_ng << x_ng << "\n";
    else
    {
        for (int i = 0; i < 10; i++)
        {
            if (c_ng[i])
            {
                x_ng = x_ng * 10 + i;
                gen_ng(k_ng + 1);
                x_ng /= 10;
            }
        }
    }
}
#pragma endregion

#pragma region Pairs
static void pairs()
{
    int n, a, b;
    std::cout << "Enter max value: ";
    std::cin >> n;

    for (a = 1; a < n; a++)
    {
        for (b = 1; a * b < n; b++)
        {
            std::cout << "Pair found: " << a << " " << a * b << "\n";
        }
    }
}
#pragma endregion

#pragma region Partitions
static int n_part, nc_part, p_part[30], np_part;
static std::ofstream fout_part("RftConstruct/Partitions.out");
static void print_part();
static void gen_part(int);

static void partitions()
{
    std::cout << "n = ";
    std::cin >> n_part;
    gen_part(1);
    fout_part.close();
}

static void print_part()
{
    fout_part << "Partition " << ++np_part << "; ";

    for (int j = 1; j <= nc_part; j++)
    {
        fout_part << " { ";

        for (int i = 1; i <= n_part; i++)
        {
            if (p_part[i] == j)
                fout_part << i << ' ';
        }

        fout_part << '}';
    }

    fout_part << "\n";
}

static void gen_part(int k_part)
{
    if (k_part - 1 == n_part)
        print_part();
    else
    {
        for (int j = 1; j <= nc_part; j++)
        {
            p_part[k_part] = j;
            gen_part(k_part + 1);
        }

        nc_part++;
        p_part[k_part] = nc_part;
        gen_part(k_part + 1);
        nc_part--;
    }
}
#pragma endregion

#pragma region Polynomial
static void linear();
static void quadratic();
static void cubic();
static void quartic();
static void quintic();
static void sextic();
static void septic();
static void octic();
static void nonic();
static void decic();

static void printPolynomialMain()
{
    // linear();
    // quadratic();
    // cubic();

    /**
     * Faulhaber's formula
     *
        quartic();
        quintic();
        sextic();
        septic();
        octic();
        nonic();
        decic();
    */
}

static void linear()
{
    int n = 4;
    int sum_n_elements = 0;

    for (int i = 1; i <= n; i++)
    {
        sum_n_elements += i;
    }

    std::cout << sum_n_elements << "\n";
    std::cout << (n * (n + 1)) / 2 << "\n";
}

static void quadratic()
{
    int n = 4;
    int sum_n_elements = 0;

    for (int i = 1; i <= n; i++)
    {
        sum_n_elements += pow(i, 2);
    }

    std::cout << sum_n_elements << "\n";
    std::cout << (n * (n + 1) * (2 * n + 1)) / 6 << "\n";
}

static void cubic()
{
    int n = 4;
    int sum_n_elements = 0;

    for (int i = 1; i <= n; i++)
    {
        sum_n_elements += pow(i, 3);
    }

    std::cout << sum_n_elements << "\n";
    std::cout << pow(n * (n + 1) / 2, 2) << "\n";
}

static void quartic()
{
    int n = 4;
    int sum_n_elements = 0;

    for (int i = 1; i <= n; i++)
    {
        sum_n_elements += pow(i, 4);
    }

    std::cout << sum_n_elements << "\n";
    std::cout << (n * (n + 1) * (2 * n + 1) * (3 * n + 1)) / 24 << "\n";
}

static void quintic()
{
    int n = 4;
    int sum_n_elements = 0;

    for (int i = 1; i <= n; i++)
    {
        sum_n_elements += pow(i, 5);
    }

    std::cout << sum_n_elements << "\n";
    std::cout << (n * (n + 1) * (2 * n + 1) * (3 * n + 1)) / 24 << "\n";
}

static void sextic()
{
    int n = 4;
    int sum_n_elements = 0;

    for (int i = 1; i <= n; i++)
    {
        sum_n_elements += pow(i, 6);
    }

    std::cout << sum_n_elements << "\n";
    std::cout << (n * (n + 1) * (2 * n + 1) * (3 * n + 1)) / 24 << "\n";
}

static void septic()
{
    int n = 4;
    int sum_n_elements = 0;

    for (int i = 1; i <= n; i++)
    {
        sum_n_elements += pow(i, 7);
    }

    std::cout << sum_n_elements << "\n";
    std::cout << (n * (n + 1) * (2 * n + 1) * (3 * n + 1)) / 24 << "\n";
}

static void octic()
{
    int n = 4;
    int sum_n_elements = 0;

    for (int i = 1; i <= n; i++)
    {
        sum_n_elements += pow(i, 8);
    }

    std::cout << sum_n_elements << "\n";
    std::cout << (n * (n + 1) * (2 * n + 1) * (3 * n + 1)) / 24 << "\n";
}

static void nonic()
{
    int n = 4;
    int sum_n_elements = 0;

    for (int i = 1; i <= n; i++)
    {
        sum_n_elements += pow(i, 9);
    }

    std::cout << sum_n_elements << "\n";
    std::cout << (n * (n + 1) * (2 * n + 1) * (3 * n + 1)) / 24 << "\n";
}

static void decic()
{
    int n = 4;
    int sum_n_elements = 0;

    for (int i = 1; i <= n; i++)
    {
        sum_n_elements += pow(i, 10);
    }

    std::cout << sum_n_elements << "\n";
    std::cout << (n * (n + 1) * (2 * n + 1) * (3 * n + 1)) / 24 << "\n";
}
#pragma endregion

#pragma region Prim
#define NMaxV_prim 100
#define Inf 10000

static int n_prim, r_prim, i_prim, vmin_prim, nv_prim;
static double g_prim[NMaxV_prim][NMaxV_prim];
static int p_prim[NMaxV_prim], z_prim[NMaxV_prim];
static double cmin_prim[NMaxV_prim], mincost_prim;
static void read_prim();
static void printMPT();

static void prim()
{
    read_prim();

    while (nv_prim)
    {
        mincost_prim = Inf;

        for (i_prim = 1; i_prim <= n; i_prim++)
        {
            if (z_prim[i_prim] && mincost_prim > cmin_prim[i_prim])
            {
                mincost_prim = cmin_prim[i_prim];
                vmin_prim = i_prim;
            }
        }

        z_prim[vmin_prim] = 0;
        nv_prim--;

        for (i_prim = 1; i_prim <= n_prim; i_prim++)
        {
            if (z_prim[i_prim] && g_prim[i_prim][vmin_prim] < cmin_prim[i_prim])
            {
                p_prim[i_prim] = vmin_prim;
                cmin_prim[i_prim] = g_prim[i_prim][vmin_prim];
            }
        }
    }

    printMPT();
}

static void read_prim()
{
    int i, j, k;
    double c;
    std::ifstream fin("RftConstruct/Prim.in");
    fin >> n >> r_prim;

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            g_prim[i][j] = Inf;
        }
    }

    for (i = 1; i <= n; i++)
    {
        g_prim[i][i] = 0;
        fin >> nv_prim;

        for (j = 1; j <= nv_prim; j++)
        {
            fin >> k >> c;
            g_prim[i][k] = c;
        }
    }

    for (i = 1; i <= n; i++)
    {
        cmin_prim[i] = g_prim[r_prim][i];
        p[i] = r_prim;
        z_prim[i] = 1;
    }

    z_prim[r_prim] = 0;
    p[r_prim] = 0;
    nv_prim = n - 1;
    fin.close();
}

static void printMPT()
{
    int i;
    double cost = 0;
    std::cout << "Edges MPT are: ";

    for (i = 1; i <= n_prim; i++)
    {
        if (i != r_prim)
        {
            std::cout << '[' << p_prim[i] << ',' << i << "]  ";
            cost += g_prim[i][p[i]];
        }
    }

    std::cout << "\nCost MPT " << cost << "\n";
}
#pragma endregion

#pragma region Prime
static bool isPrime(int number);
static bool isPrime0(int number);

static void printPrimeMain()
{
    isPrime0(11);
}

static bool isPrime(int number)
{
    if (number == 1)
        return false;

    for (int i = 2; i <= sqrt(number); i++)
    {
        if (number % i == 0)
            return false;
    }

    return true;
}

static bool isPrime0(int number)
{
    if (number <= 1)
        return false;

    if (number % 2 == 0)
        return number == 2;

    for (int i = 3;; i += 2)
    {
        if (i > number / i)
            break;

        if (number % i == 0)
            return false;
    }

    return true;
}
#pragma endregion

#pragma region Primes
static void primeNumbers()
{
    int n, d, root;
    bool prime = true;
    std::cout << "Enter a number: ";
    std::cin >> n;

    if (n > 2)
    {
        if (n % 2 == 0)
            prime = false;
        else
        {
            for (d = 3, root = sqrt(n); d <= root && prime; d += 2)
            {
                if (n % d == 0)
                    prime = false;
            }
        }
    }

    if (prime)
        std::cout << "Prime number: " << prime << "\n";
    else
        std::cout << "Not a prime!\n";
}
#pragma endregion

#pragma region Quadratic Equation
static void quadraticEquation()
{
    float a, b, c, d;

    std::cout << "Enter a: ";
    std::cin >> a;
    std::cout << "Enter b: ";
    std::cin >> b;
    std::cout << "Enter c: ";
    std::cin >> c;

    d = b * b - 4 * a * c;

    if (d < 0)
        std::cout << "Equation has no real roots!\n";
    else
    {
        if (!d)
            std::cout << "x1 = x2 = " << -b / (2 * a) << "\n";
        else
            std::cout << "x1 = " << (-b + sqrt(d)) / (2 * a) << "x2 = " << (-b - sqrt(d)) / (2 * a) << "\n";
    }
}
#pragma endregion

#pragma region Sum Of Digits
static void sumOfDigits()
{
    int n, s = 0;
    std::cout << "Enter a number: ";
    std::cin >> n;

    while (n)
    {
        s += n % 10;
        n /= 10;
    }

    std::cout << "Sum of digits = " << s << "\n";
}
#pragma endregion

#pragma region Sum Of Power Of Roots
static float sum_root(int);
static float s_root, p_root;

static void sumOfPowersOfRoots()
{
    int n;

    std::cout << "Enter coeficient s = ";
    std::cin >> s_root;
    std::cout << "Enter coeficient p = ";
    std::cin >> p_root;
    std::cout << "n = ";
    std::cin >> n;
    std::cout << "S(" << n << ")=" << sum_root(n) << "\n";
}

static float sum_root(int n)
{
    if (!n)
        return 2;

    if (n == 1)
        return s_root;

    return s_root * sum_root(n - 1) - p_root * sum_root(n - 2);
}
#pragma endregion

#pragma region Surjective Functions
#define DMax_surj 20

static int n_surj, m_surj, f_surj[DMax_surj], im_surj[DMax_surj];
static std::ofstream fout_surj("RftConstruct/SurjectiveFunctions.out");
static void print_surj();
static void gen_surj(int);

static void surjectiveFunctions()
{
    std::cout << "n, m = ";
    std::cin >> n_surj >> m_surj;
    gen_surj(0);
    fout_surj.close();
}

static void print_surj()
{
    for (int i = 1; i <= m_surj; i++)
    {
        if (!im_surj[i])
            return;
    }

    for (int i = 0; i < n_surj; i++)
    {
        fout_surj << f_surj[i] << ' ';
    }

    fout_surj << "\n";
}

static void gen_surj(int k)
{
    if (k == n_surj)
        print_surj();
    else
    {
        for (int j = 1; j <= m_surj; j++)
        {
            f_surj[k] = j;
            im_surj[j]++;
            gen_surj(k + 1);
            im_surj[j]--;
        }
    }
}
#pragma endregion

#pragma region ThreeSum 1D Vector
static std::vector<std::vector<int>> printThreeSum1DVector(std::vector<int> &nums)
{
    std::vector<std::vector<int>> res;

    if (nums.size() < 3)
        return res;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 2; ++i)
    {
        if (i != 0 && nums[i] == nums[i - 1])
            continue;

        int a = i + 1;
        int b = nums.size() - 1;
        int t;

        while (a < b)
        {
            t = nums[i] + nums[a] + nums[b];

            if (t > 0)
                b--;
            else if (t < 0)
                a++;
            else
            {
                res.push_back({nums[i], nums[a], nums[b]});
                a++;
                b--;

                while (nums[a] == nums[a - 1] && a < b)
                    a++;

                while (nums[b] == nums[b + 1] && a < b)
                    b--;
            }
        }
    }

    return res;
}

static void printThreeSum1DVectorMain()
{
    std::vector<int> y = {-1, 0, 1, 2, -1, -4};
    std::vector<std::vector<int>> x = printThreeSum1DVector(y);

    for (auto item : x)
    {
        for (auto item1 : item)
        {
            std::cout << item1 << " ";
        }

        std::cout << "\n";
    }
}
#pragma endregion

#pragma region Combinations
static int s_comb = 150;
static int n_comb = 6;
static int mod_comb[6];
static int m_comb[6] = {500, 100, 50, 10, 5, 1};
static int sol_comb = 0;

static void show_comb()
{
    sol_comb++;

    std::cout << "Coins:\t\t";

    for (int i = 0; i < n_comb; i++)
        std::cout << " " << m_comb[i];

    std::cout << "\n";
    std::cout << "Solution " << sol_comb << ":\t";

    for (int i = 0; i < n_comb; i++)
        std::cout << " " << mod_comb[i];

    RFT_SEPARATOR
}

static int valid_comb()
{
    int sum = 0;

    for (int i = 0; i < n_comb; i++)
        sum = sum + mod_comb[i] * m_comb[i];

    return sum == s_comb;
}

static void back_comb(int k)
{
    if (k < n)
    {
        for (int j = 0; j < s_comb; j++)
        {
            mod_comb[k] = j;
            back_comb(k + 1);
        }
    }
    else
    {
        if (valid_comb())
            show_comb();
    }
}

static void printCombinationsMain()
{
    // back(0); // Research0
}
#pragma endregion

#pragma region Combinations 0
static int n_comb0, m_comb0, c_comb0[40];
static std::ofstream fout_comb0("RftConstruct/Combinations.out");
static void print_comb0();
static void gen_comb0(int);

// n!/m!*(n-m)!
static void combinations_comb0()
{
    std::cout << "n = ";
    std::cin >> n_comb0;
    std::cout << "m = ";
    std::cin >> m_comb0;
    gen_comb0(1);
    fout_comb0.close();
}

static void print_comb0()
{
    for (int i = 1; i <= m_comb0; i++)
    {
        fout_comb0 << c_comb0[i] << ' ';
    }

    fout_comb0 << "\n";
}

static void gen_comb0(int k)
{
    if (k - 1 == m_comb0)
        print_comb0();
    else
    {
        for (int i = c_comb0[k - 1] + 1; i <= n_comb0 - m_comb0 + k; i++)
        {
            c_comb0[k] = i;
            gen_comb0(k + 1);
        }
    }
}
#pragma endregion

#pragma region Combination Of Payment
#define MaxCoins_combp 20

static unsigned v_combp[MaxCoins_combp], m_combp[MaxCoins_combp], p_combp[MaxCoins_combp];
static unsigned s_combp, sum_combp, nsol_combp;
static int n_combp;
static std::ofstream fout_combp("RftConstruct/CombinationsOfPayment.out");
static void read_combp();
static void print_combp();
static void payment_combp(int);

static void combinationsOfPayment()
{
    read_combp();
    payment_combp(0);
    fout_combp.close();
}

static void read_combp()
{
    std::ifstream fin("RftConstruct/CombinationsOfPayment.in");
    fin >> n_combp >> s_combp;

    for (int i = 0; i < n_combp; i++)
    {
        fin >> v_combp[i] >> m_combp[i];
    }

    fin.close();
}

static void print_combp()
{
    fout_combp << "Solution nr: " << ++nsol_combp << "\n";

    for (int i = 0; i < n_combp; i++)
    {
        if (p_combp[i])
            fout_combp << p_combp[i] << " coin with value " << v_combp[i] << "\n";
    }
}

static void payment_combp(int k)
{
    if (k == n_combp)
    {
        if (sum_combp == s_combp)
            print_combp();
        else
        {
        }
    }
    else
    {
        for (int j = 0; j <= m_combp[k] && sum_combp + j * v_combp[k] <= s_combp; j++)
        {
            p_combp[k] = j;
            sum_combp += j * v_combp[k];
            payment_combp(k + 1);
            sum_combp -= j * v_combp[k];
        }
    }
}
#pragma endregion

#pragma region Permutations
static int n_perm, p_perm[40], used_perm[40];
static std::ofstream fout_perm("RftConstruct/Permutations.out");
static void print_perm();
static void gen_perm(int);

// n!
static void permutations()
{
    std::cout << "n = ";
    std::cin >> n_perm;
    gen_perm(1);
    fout_perm.close();
}

static void print_perm()
{
    for (int i = 1; i <= n_perm; i++)
    {
        fout_perm << p_perm[i] << ' ';
    }

    fout_perm << "\n";
}

static void gen_perm(int k)
{
    if (k - 1 == n_perm)
        print_perm();
    else
    {
        for (int i = 1; i <= n_perm; i++)
        {
            if (!used_perm[i])
            {
                p_perm[k] = i;
                used_perm[i] = 1;
                gen_perm(k + 1);
                used_perm[i] = 0;
            }
        }
    }
}
#pragma endregion

#pragma region Permutations With Repetitions
#define NMax_permr 20

static int n_permr, m_permr[NMax_permr], s_permr[NMax_permr], used_permr[NMax_permr], p_permr;
static std::ofstream fout_permr("RftConstruct/PermutationsWithRepetitions.out");
static void gen_permr(int);

// p! / m1!*m2!*...*mn!
static void permutationsWithRepetitions()
{
    std::cout << "n = ";
    std::cin >> n_permr;
    std::cout << "Factors: ";

    for (int i = 1; i <= n_permr; i++)
    {
        std::cin >> m_permr[i];
        p_permr += m_permr[i];
    }

    gen_permr(1);
    fout_permr.close();
}

static void gen_permr(int k)
{
    if (k == p_permr + 1)
    {
        for (int i = 1; i <= p_permr; i++)
        {
            fout_permr << s_permr[i] << ' ';
        }

        fout_permr << "\n";
    }
    else
    {
        for (int i = 1; i <= n_permr; i++)
        {
            if (used_permr[i] < m_permr[i])
            {
                s_permr[k] = i;
                used_permr[i]++;
                gen_permr(k + 1);
                used_permr[i]--;
            }
        }
    }
}
#pragma endregion

#pragma region ASCII Cube 3D
static float A, B, C;
static float cubeWidth = 15;
static int width = 160, height = 44;
static float zBuffer[160 * 44];
static char buffer[160 * 44];
static int backgorundASCIICode = ' ';
static int distanceFromCam = 100;
static float K1 = 40;
static int idx;
static float incrementSpeed = 0.6;
static float x, y, z;
static float ooz;
static int xp, yp;

static float calculateX(int i, int j, int k)
{
    return j * sin(A) * sin(B) * cos(C) - k * cos(A) * sin(B) * cos(C) +
           j * cos(A) * sin(C) + k * sin(A) * sin(C) + i * cos(B) * cos(C);
}

static float calculateY(int i, int j, int k)
{
    return j * cos(A) * cos(C) + k * sin(A) * cos(C) -
           j * sin(A) * sin(B) * sin(C) + k * cos(A) * sin(B) * sin(C) -
           i * cos(B) * sin(C);
}

static float calculateZ(int i, int j, int k)
{
    return k * cos(A) * cos(B) - j * sin(A) * cos(B) + i * sin(B);
}

static void calculateForSurface(float cubeX, float cubeY, float cubeZ, int ch)
{
    x = calculateX(cubeX, cubeY, cubeZ);
    y = calculateY(cubeX, cubeY, cubeZ);
    z = calculateZ(cubeX, cubeY, cubeZ) + distanceFromCam;

    ooz = 1 / z;

    xp = (int)(width / 2 - 2 * cubeWidth + K1 * ooz * x * 2);
    yp = (int)(height / 2 + K1 * ooz * y);

    idx = xp + yp * width;

    if (idx >= 0 && idx < width * height)
    {
        if (ooz > zBuffer[idx])
        {
            zBuffer[idx] = ooz;
            buffer[idx] = ch;
        }
    }
}

static int printASCIICube3DMain()
{
    std::cout << "\x1b[2J";

    int c = 0;

    while (c < 1000)
    {
        memset(buffer, backgorundASCIICode, width * height);
        memset(zBuffer, 0, width * height * 4);

        for (float cubeX = -cubeWidth; cubeX < cubeWidth; cubeX += incrementSpeed)
        {
            for (float cubeY = -cubeWidth; cubeY < cubeWidth; cubeY += incrementSpeed)
            {
                calculateForSurface(cubeX, cubeY, -cubeWidth, '.');
                calculateForSurface(cubeWidth, cubeY, cubeX, '$');
                calculateForSurface(-cubeWidth, cubeY, -cubeX, '~');
                calculateForSurface(-cubeX, cubeY, cubeWidth, '#');
                calculateForSurface(cubeX, -cubeWidth, -cubeY, ';');
                calculateForSurface(cubeX, cubeWidth, cubeY, '+');
            }
        }

        std::cout << "\x1b[H";

        for (int k = 0; k < width * height; k++)
        {
            putchar(k % width ? buffer[k] : 10);
        }

        A += 0.005;
        B += 0.005;
        c++;
    }

    return 0;
}
#pragma endregion

#pragma region ASCII Doughnut 3D
static int k;
// static double sin(), cos();

static int printASCIIDoughnut3DMain()
{
    float A = 0, B = 0, i, j, z[1760];
    char b[1760];
    printf("\n1b[2J");

    for (;;)
    {
        memset(b, 32, 1760);
        memset(z, 0, 7040);

        for (j = 0; 6.28 > j; j += 0.005)
        {
            for (i = 0; 6.28 > i; i += 0.05)
            {
                float c = sin(i), d = cos(j), e = sin(A), f = sin(j), g = cos(A),
                      h = d + 2, D = 1 / (c * h * e + f * g + 5), l = cos(i),
                      m = cos(B), n = sin(B),
                      t = c * h * g - f * e;

                int x = 40 + 30 * D * (l * h * m - t * n);
                int y = 12 + 15 * D * (l * h * n + t * m);
                int o = x + 80 * y;
                int N = 8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n);

                if (22 > y && y > 0 && 80 > x && x > 0 && D > z[o])
                {
                    z[o] = D;
                    b[o] = ".,-~:;=!*#$@:"[N > 0 ? N : 0];
                }
            }
        }

        printf("\x1b[H");

        for (k = 0; 1761 > k; k++)
        {
            putchar(k % 80 ? b[k] : 10);
        }

        A += 0.04;
        B += 0.02;
    }
}
#pragma endregion

#pragma region Cartesian Product
#define DMax_cart 20

static int n_cart, l_cart[DMax_cart], e_cart[DMax_cart];
static std::ofstream fout_cart("CartesianProduct.out");
static void read_cart();
static void gen_cart(int);
static void print_cart();

static void cartesianProduct()
{
    read_cart();
    gen_cart(1);
    fout_cart.close();
}

static void read_cart()
{
    std::ifstream fin("CartesianProduct.in");
    fin >> n_cart;

    for (int i = 1; i <= n_cart; i++)
    {
        fin >> l_cart[i];
    }

    fin.close();
}

static void gen_cart(int k)
{
    if (k == n_cart + 1)
        print_cart();
    else
    {
        for (int j = 1; j <= l_cart[k]; j++)
        {
            e_cart[k] = j;
            gen_cart(k + 1);
        }
    }
}

static void print_cart()
{
    for (int i = 1; i <= n_cart; i++)
    {
        fout_cart << e_cart[i] << ' ';
    }

    fout_cart << "\n";
}
#pragma endregion

#pragma region Circle Area And Perimeter
static void CircleAreaAndPerimeter()
{
    double r;
    std::cout << "Enter radius: ";
    std::cin >> r;
    std::cout << "Area = " << M_PI * r * r << " Perimeter = " << 2 * M_PI * 2;
}
#pragma endregion

#pragma region Cube Root With Precision
#define PREC 0.0001

static void CubeRootWithPrecision()
{
    double x, r1, r2 = 1;
    std::cout << "x = ";
    std::cin >> x;

    do
    {
        r1 = r2;
        r2 = (2 * r1 + x / (r1 * r1)) / 3;
        std::cout << "r1 = " << r1 << "; r2 = " << r2 << "\n";
    } while (fabs(r2 - r1) >= PREC);

    std::cout << r2 << "\n";
}
#pragma endregion

#pragma region Diagonals
static void printMainDiagonalInt2DArray(int rows, int columns, int (*p)[5]);
static void printMainUpperTriangleInt2DArray(int rows, int columns, int (*p)[5]);
static void printMainLowerTriangleInt2DArray(int rows, int columns, int (*p)[5]);

static void printSecondaryDiagonalInt2DArray(int rows, int columns, int (*p)[5]);
static void printSecondaryUpperTriangleInt2DArray(int rows, int columns, int (*p)[5]);
static void printSecondaryLowerTriangleInt2DArray(int rows, int columns, int (*p)[5]);

static void printDiagonals1DArrayMain()
{
    int a0[][5] = {
        {123, 12, 3, 1234, 23},
        {234, 32, 4, 32, 24},
        {45, 4, 67, 67, 4},
        {1, 1, 1, 1, 1},
        {4, 4, 4, 4, 2}};

    printMainDiagonalInt2DArray(std::size(a0), std::size(a0[0]), a0);
    RFT_SEPARATOR

    printMainUpperTriangleInt2DArray(std::size(a0), std::size(a0[0]), a0);
    RFT_SEPARATOR

    printMainLowerTriangleInt2DArray(std::size(a0), std::size(a0[0]), a0);
    RFT_SEPARATOR

    printSecondaryDiagonalInt2DArray(std::size(a0), std::size(a0[0]), a0);
    RFT_SEPARATOR

    printSecondaryUpperTriangleInt2DArray(std::size(a0), std::size(a0[0]), a0);
    RFT_SEPARATOR

    printSecondaryLowerTriangleInt2DArray(std::size(a0), std::size(a0[0]), a0);
    RFT_SEPARATOR
}

static void printMainDiagonalInt2DArray(int rows, int columns, int (*p)[5])
{
    for (int i = 0; i < rows; i++)
    {
        // cout << p[i][i] << " ";

        for (int j = 0; j < columns; j++)
        {
            if (i == j)
                std::cout << p[i][j] << "\t";
            else
                std::cout << "\t";
        }

        std::cout << "\n\n";
    }
}

static void printMainUpperTriangleInt2DArray(int rows, int columns, int (*p)[5])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (j > i)
                std::cout << p[i][j] << "\t";
            else
                std::cout << "\t";
        }

        std::cout << "\n\n";
    }
}

static void printMainLowerTriangleInt2DArray(int rows, int columns, int (*p)[5])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (j < i)
                std::cout << p[i][j] << "\t";
            else
                std::cout << "\t";
        }

        std::cout << "\n\n";
    }
}

static void printSecondaryDiagonalInt2DArray(int rows, int columns, int (*p)[5])
{
    for (int i = 0; i < rows; i++)
    {
        // cout << p[i][rows - i - 1] << " ";

        for (int j = 0; j < columns; j++)
        {
            if (i == columns - j - 1)
                std::cout << p[i][j] << "\t";
            else
                std::cout << "\t";
        }

        std::cout << "\n\n";
    }
}

static void printSecondaryUpperTriangleInt2DArray(int rows, int columns, int (*p)[5])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns - i - 1; j++)
        {
            std::cout << p[i][j] << "\t";
        }

        std::cout << "\n\n";
    }
}

static void printSecondaryLowerTriangleInt2DArray(int rows, int columns, int (*p)[5])
{
    for (int i = 0; i < rows; i++)
    {
        for (int k = 0; k < rows - i; k++)
        {
            std::cout << "\t";
        }

        for (int j = columns - i; j < columns; j++)
        {
            std::cout << p[i][j] << "\t";
        }

        std::cout << "\n\n";
    }
}
#pragma endregion

#pragma region Maximum Rectangle Cut
#define NMaxHoles_maxrc 20

static int n_maxrc;
static int x_maxrc[NMaxHoles_maxrc], y_maxrc[NMaxHoles_maxrc];
static int wp_maxrc, hp_maxrc, amax_maxrc, wmax_maxrc, hmax_maxrc, xmax_maxrc, ymax_maxrc;
static void read_maxrc();
static int inner_maxrc(int, int, int, int, int);
static void cut_maxrc(int, int, int, int);

static void maximumRectangleCut()
{
    read_maxrc();
    cut_maxrc(0, 0, wp_maxrc, hp_maxrc);
    std::cout << "Origin at 0,0 (down-left).\n";
    std::cout << xmax_maxrc << ", " << ymax_maxrc << "\n";
    std::cout << "Width = " << wmax_maxrc << "; Height = " << hmax_maxrc << "\n";
}

static void read_maxrc()
{
    std::ifstream fin("RftConstruct/MaximumRectangleCut.in");
    fin >> wp_maxrc >> hp_maxrc >> n_maxrc;

    for (int i = 0; i < n_maxrc; i++)
    {
        fin >> x_maxrc[i] >> y_maxrc[i];
    }

    fin.close();
}

static int inner_maxrc(int i, int xs, int ys, int w, int h)
{
    if ((x_maxrc[i] > xs) && (x_maxrc[i] < xs + w) && (y_maxrc[i] > ys) && (y_maxrc[i] < ys + h))
        return 1;

    return 0;
}

static void cut_maxrc(int xs, int ys, int w, int h)
{
    int i = 0;

    while ((i < n) && !inner_maxrc(i, xs, ys, w, h))
    {
        i++;
    }

    if (i == n_maxrc)
    {
        if (w * h > amax_maxrc)
        {
            amax_maxrc = w * h;
            wmax_maxrc = w;
            hmax_maxrc = h;
            xmax_maxrc = xs;
            ymax_maxrc = ys;
        }
        else
        {
            cut_maxrc(xs, ys, w, y_maxrc[i] - ys);
            cut_maxrc(xs, y_maxrc[i], w, ys + h - y_maxrc[i]);
            cut_maxrc(xs, ys, x_maxrc[i] - xs, h);
            cut_maxrc(x_maxrc[i], ys, xs + 1 - x_maxrc[i], h);
        }
    }
}
#pragma endregion

#pragma region Photo
#define DimMax_p 50

static int dx_p[4] = {-1, 0, 1, 0}, dy_p[4] = {0, 1, 0, -1};
static int a_p[DimMax_p][DimMax_p], m_p, n_p, nobj_p;
static void read_p();
static void erase_p(int, int);

static void photo_p()
{
    read_p();

    for (int i = 1; i <= n_p; i++)
    {
        for (int j = 1; j <= m_p; j++)
        {
            if (a_p[i][j])
            {
                nobj_p++;
                erase_p(i, j);
            }
        }
    }

    std::cout << "Number of objects = " << nobj_p << "\n";
}

static void read_p()
{
    std::ifstream fin("RftConstruct/Photo.in");
    fin >> n_p >> m_p;

    for (int i = 1; i <= n_p; i++)
    {
        for (int j = 1; j <= m_p; j++)
        {
            fin >> a_p[i][j];
        }
    }

    fin.close();
}

static void erase_p(int x, int y)
{
    if (a_p[x][y])
    {
        a_p[x][y] = 0;

        for (int dir = 0; dir < 4; dir++)
        {
            erase_p(x + dx_p[dir], y + dy_p[dir]);
        }
    }
}
#pragma endregion

#pragma region Pseudo Diagonals
static void PseudoDiagonals()
{
    int n = 5, m = 8, i, j, d, s;
    int a[5][8] = {
        {1, 2, 3, 4, 5, 8, 21, 3},
        {5, 4, 3, 1, 3, 4, 5, 2},
        {8, 6, 5, 4, 3, 8, 4, 3},
        {9, 6, 4, 3, 2, 6, 2, 7},
        {1, 7, 3, 8, 3, 1, 9, 20}};

    for (d = 0; d < m - n + 1; d++)
    {
        s = 0;

        for (i = 0; i < n; i++)
        {
            s += a[i][i + d];
            std::cout << a[i][i + d] << ' ';
        }

        std::cout << "Sum of elements on the main pseudodiagonal " << d << " is " << s << "\n";
    }

    std::cout << "\n";

    for (d = 0; d < m - n + 1; d++)
    {
        s = 0;

        for (i = 0; i < n; i++)
        {
            s += a[i][m - d - i - 1];
            std::cout << a[i][m - d - i - 1] << ' ';
        }

        std::cout << "Sum of elements on the secondary pseudodiagonal " << d << " is " << s << "\n";
    }
}
#pragma endregion

#pragma region Pyramid Of Five
static void pyramidOutOfFiveNumbers()
{
    unsigned long x;
    unsigned x0, x1, x2, x3;

    std::cout << "Enter five digit number: ";
    std::cin >> x;
    x0 = x % 10;
    x /= 10;
    x1 = x % 10;
    x /= 10;
    x2 = x % 10;
    x /= 10;
    x3 = x % 10;
    x /= 10;

    std::cout << "  " << x2 << "  " << "\n";
    std::cout << " " << x3 << x2 << x1 << " " << "\n";
    std::cout << x << x3 << x2 << x1 << x0 << "\n";
}
#pragma endregion

#pragma region Rectangle Split Two Squares
#define NMaxShapes_ts 100

static int a_ts, b_ts, nmin_ts, dmin_ts[NMaxShapes_ts];
static void split_ts(int, int, int[NMaxShapes_ts], int &);

static void rectangleSplitTwoSquares()
{
    std::cout << "a, b (a<b) = ";
    std::cin >> a_ts >> b_ts;

    split_ts(a_ts, b_ts, dmin_ts, nmin_ts);

    std::cout << "Minimum number of shapes: " << nmin_ts << "\n";

    for (int i = 0; i < nmin_ts + 1; i++)
    {
        std::cout << dmin_ts[i] << ' ';
    }
}

static void split_ts(int x, int y, int d[NMaxShapes_ts], int &n)
{
    int n1, n2, i, d1[NMaxShapes_ts], d2[NMaxShapes_ts];

    if ((y - x >= x) || (x == y))
    {
        n = 1;
        d[0] = x;
        d[1] = y;
    }
    else
    {
        if (y - x < 2 * x - y)
            split_ts(y - x, 2 * x - y, d1, n1);
        else
            split_ts(2 * x - y, y - x, d1, n1);

        if (x % 2 == 0)
        {
            if (x < y - x / 2)
                split_ts(x, y - x / 2, d2, n2);
            else
                split_ts(y - x / 2, x, d2, n2);
        }
        else
            n2 = NMaxShapes_ts;

        if (n1 <= n2)
        {
            n = n1 + 2;
            d[0] = x;
            d[1] = y - x;

            for (i = 2; i < n + 2; i++)
            {
                d[i] = d1[i - 2];
            }
        }
        else
        {
            n = n2 + 2;
            d[0] = x / 2;
            d[1] = x / 2;

            for (i = 2; i < n + 2; i++)
            {
                d[i] = d2[i - 2];
            }
        }
    }
}
#pragma endregion

#pragma region Row Generator
static int s_rg[NMax];
static int n_rg, lg_rg;
static long nsol_rg;
static std::ofstream fout_rg("RftConstruct/RowGenerator.out");
static void print_rg();
static void gen_rg(int);

static void rowGenerator()
{
    std::cout << "n, lg = ";
    std::cin >> n_rg >> lg_rg;
    s_rg[0] = n_rg;
    gen_rg(1);

    if (!nsol_rg)
        fout_rg << "No solutions\n";

    fout_rg.close();
}

static void print_rg()
{
    int i;

    if (s_rg[lg_rg - 1] == n)
    {
        nsol_rg++;

        for (i = 0; i < lg_rg; i++)
        {
            fout_rg << s_rg[i] << ' ';
        }

        fout_rg << "\n";
    }
}

static void gen_rg(int k)
{
    if (k == lg_rg)
        print_rg();
    else
    {
        if (s_rg[k - 1] > 1)
        {
            s_rg[k] = s_rg[k - 1] - 1;
            gen_rg(k + 1);
        }

        s_rg[k] = s_rg[k - 1] + 1;
        gen_rg(k + 1);
    }
}
#pragma endregion

#pragma region Triangle Area
static void triangleArea()
{
    double x, y, z, p, area;

    std::cout << "Enter point x: ";
    std::cin >> x;
    std::cout << "Enter point y: ";
    std::cin >> y;
    std::cout << "Enter point z: ";
    std::cin >> z;

    if (x <= 0 || y <= 0 || z <= 0)
        std::cout << "Wrong values!";
    else
    {
        if (z >= x + y || y >= x + z || x >= y + z)
            std::cout << "Wrong values!";
        else
        {
            p = (x + y + z) / 2; // semiperimeter
            area = sqrt(p * (p - x) * (p - y) * (p - z));
            std::cout << area << "\n";
        }
    }
}
#pragma endregion
