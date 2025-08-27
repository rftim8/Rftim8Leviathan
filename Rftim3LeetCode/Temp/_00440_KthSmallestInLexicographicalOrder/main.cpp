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

// Prefix Tree
static int _00440_KthSmallestInLexicographicalOrder(int n, int k);
static int _00440_KthSmallestInLexicographicalOrder0(int n, int k);

static int is_00440_KthSmallestInLexicographicalOrder_RunTest();

/**
 * Given two integers n and k, return the kth lexicographically smallest integer in the range [1, n].
 *
 * Constraints:
 *
 * 1 <= k <= n <= 10^9
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_00440_KthSmallestInLexicographicalOrder_RunTest();
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

        s;
        cin >> s;
        v0.push_back(s);

        s;
        cin >> s;
        cin.get();
        v1.push_back(s);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        cout << _00440_KthSmallestInLexicographicalOrder(v[i], v0[i]) << "\n";
        cout << _00440_KthSmallestInLexicographicalOrder0(v[i], v0[i]) << "\n";
    }
}

static int countSteps(int n, long prefix1, long prefix2)
{
    int steps = 0;

    while (prefix1 <= n)
    {
        steps += min((long)(n + 1), prefix2) - prefix1;
        prefix1 *= 10;
        prefix2 *= 10;
    }

    return steps;
}

static int _00440_KthSmallestInLexicographicalOrder(int n, int k)
{
    int curr = 1;
    k--;

    while (k > 0)
    {
        int step = countSteps(n, curr, curr + 1);

        if (step <= k)
        {
            curr++;
            k -= step;
        }
        else
        {
            curr *= 10;
            k--;
        }
    }

    return curr;
}

static int _00440_KthSmallestInLexicographicalOrder0(int n, int k)
{
    auto getGap = [&n](long a, long b)
    {
        long gap = 0;

        while (a <= n)
        {
            gap += min((long)n + 1, b) - a;
            a *= 10;
            b *= 10;
        }

        return gap;
    };

    long currNum = 1;

    for (int i = 1; i < k;)
    {
        long gap = getGap(currNum, currNum + 1);

        if (i + gap <= k)
        {
            i += gap;
            ++currNum;
        }
        else
        {
            ++i;
            currNum *= 10;
        }
    }

    return currNum;
}

#pragma region GTest
static int is_00440_KthSmallestInLexicographicalOrder_RunTest()
{
    stringstream ss;
    ss << "*_00440_KthSmallestInLexicographicalOrder.expected*"
       << ":"
          "*_00440_KthSmallestInLexicographicalOrder0.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_00440_KthSmallestInLexicographicalOrder, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v1[i];

        // Actual
        int actual = _00440_KthSmallestInLexicographicalOrder(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_00440_KthSmallestInLexicographicalOrder0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v1[i];

        // Actual
        int actual = _00440_KthSmallestInLexicographicalOrder0(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
