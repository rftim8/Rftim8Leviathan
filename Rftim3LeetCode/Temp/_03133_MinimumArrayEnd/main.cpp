#include <bits/stdc++.h>
#include <fstream>
#include <gtest/gtest.h>

using namespace std;

static const auto speedup = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}();

void offline()
{
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

#endif
}

static void dataCollector();

static void solve();

// Consecutive ORing
static long long _03133_MinimumArrayEnd(int n, int x);
// Bit Manipulation and Binary Construction
static long long _03133_MinimumArrayEnd0(int n, int x);
// Bitmasking with Logical Operations
static long long _03133_MinimumArrayEnd1(int n, int x);
// Speed
static long long _03133_MinimumArrayEnd2(int n, int x);

static int is_03133_MinimumArrayEnd_RunTest();

/**
 * You are given two integers n and x. You have to construct an array of positive integers nums
 * of size n where for every 0 <= i < n - 1, nums[i + 1] is greater than nums[i],
 * and the result of the bitwise AND operation between all elements of nums is x.
 * Return the minimum possible value of nums[n - 1].
 *
 * Constraints:
 * 1 <= n, x <= 10^8
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_03133_MinimumArrayEnd_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<int> v, v0, v1;

static void dataCollector()
{
    cin >> n;
    cin >> m;
    cin.get();

    for (int i = 0; i < n * m; i += m)
    {
        int s;
        cin >> s;
        v.push_back(s);

        cin >> s;
        v0.push_back(s);

        cin >> s;
        v1.push_back(s);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        cout << _03133_MinimumArrayEnd(v[i], v0[i]) << "\n";
        cout << _03133_MinimumArrayEnd0(v[i], v0[i]) << "\n";
        cout << _03133_MinimumArrayEnd1(v[i], v0[i]) << "\n";
        cout << _03133_MinimumArrayEnd2(v[i], v0[i]) << "\n";
    }
}

static long long _03133_MinimumArrayEnd(int n, int x)
{
    long long result = x;

    while (--n)
    {
        result = (result + 1) | x;
    }

    return result;
}

static long long _03133_MinimumArrayEnd0(int n, int x)
{
    long long result = 0, bit;
    --n;

    vector<int> binaryX(64, 0);
    vector<int> binaryN(64, 0);

    long long longX = x;
    long longN = n;

    for (int i = 0; i < 64; ++i)
    {
        bit = (longX >> i) & 1;
        binaryX[i] = bit;

        bit = (longN >> i) & 1;
        binaryN[i] = bit;
    }

    int posX = 0, posN = 0;

    while (posX < 63)
    {
        while (binaryX[posX] != 0 && posX < 63)
        {
            ++posX;
        }

        binaryX[posX] = binaryN[posN];
        ++posX;
        ++posN;
    }

    for (int i = 0; i < 64; ++i)
    {
        if (binaryX[i] == 1)
            result += pow(2, i);
    }

    return result;
}

static long long _03133_MinimumArrayEnd1(int n, int x)
{
    long long result = x, mask;
    --n;

    for (mask = 1; n > 0; mask <<= 1)
    {
        if ((mask & x) == 0)
        {
            result |= (n & 1) * mask;
            n >>= 1;
        }
    }

    return result;
}

static long long _03133_MinimumArrayEnd2(int n, int x)
{
    vector<short> shifts;
    long long cur = x;
    long long calc = n - 1;

    for (int i = 0; i < 32; i++)
        if (!((1 << i) & x))
            shifts.push_back(i);

    for (int i = 32; i < 64; i++)
        shifts.push_back(i);

    for (int i = 0; calc > 0; i++, calc >>= 1)
    {
        cur += (calc & 1) << shifts[i];
    }

    return cur;
}

#pragma region GTest
static int is_03133_MinimumArrayEnd_RunTest()
{
    stringstream ss;
    ss << "*_03133_MinimumArrayEnd.expected*"
       << ":"
       << "*_03133_MinimumArrayEnd0.expected*"
       << ":"
       << "*_03133_MinimumArrayEnd1.expected*"
       << ":"
       << "*_03133_MinimumArrayEnd2.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_03133_MinimumArrayEnd, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        long long expected = v1[i];

        // Actual
        long long actual = _03133_MinimumArrayEnd(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_03133_MinimumArrayEnd0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        long long expected = v1[i];

        // Actual
        long long actual = _03133_MinimumArrayEnd0(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_03133_MinimumArrayEnd1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        long long expected = v1[i];

        // Actual
        long long actual = _03133_MinimumArrayEnd1(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_03133_MinimumArrayEnd2, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        long long expected = v1[i];

        // Actual
        long long actual = _03133_MinimumArrayEnd2(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
