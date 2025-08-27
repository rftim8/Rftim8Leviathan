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

// Two Pointer
static long long _02938_SeparateBlackAndWhiteBalls(string s);
// Counter
static long long _02938_SeparateBlackAndWhiteBalls0(string s);
// Speed
static long long _02938_SeparateBlackAndWhiteBalls1(string s);

static int is_02938_SeparateBlackAndWhiteBalls_RunTest();

/**
 * There are n balls on a table, each ball has a color black or white.
 * You are given a 0-indexed binary string s of length n, where 1 and 0 represent black and white balls, respectively.
 * In each step, you can choose two adjacent balls and swap them.
 * Return the minimum number of steps to group all the black balls to the right and all the white balls to the left.
 *
 * Constraints:
 *
 * 1 <= n == s.length <= 10^5
 * s[i] is either '0' or '1'.
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_02938_SeparateBlackAndWhiteBalls_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<string> v;
static vector<long long> v0;

static void dataCollector()
{
    cin >> n;
    cin >> m;
    cin.get();

    for (int i = 0; i < n * m; i += m)
    {
        string s;
        cin >> s;
        v.push_back(s);

        long long s0;
        cin >> s0;
        cin.get();
        v0.push_back(s0);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        cout << _02938_SeparateBlackAndWhiteBalls(v[i]) << "\n";
        cout << _02938_SeparateBlackAndWhiteBalls0(v[i]) << "\n";
        cout << _02938_SeparateBlackAndWhiteBalls1(v[i]) << "\n";
    }
}

static long long _02938_SeparateBlackAndWhiteBalls(string s)
{
    int whitePosition = 0;
    long long totalSwaps = 0;

    for (int currentPos = 0; currentPos < s.length(); currentPos++)
    {
        if (s[currentPos] == '0')
        {
            totalSwaps += currentPos - whitePosition;
            whitePosition++;
        }
    }

    return totalSwaps;
}

static long long _02938_SeparateBlackAndWhiteBalls0(string s)
{
    long long totalSwaps = 0;
    int blackBallCount = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '0')
            totalSwaps += (long long)blackBallCount;
        else
            blackBallCount++;
    }

    return totalSwaps;
}

static long long _02938_SeparateBlackAndWhiteBalls1(string s)
{
    long long res = 0, cur = 0;

    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == '0')
        {
            res += i - cur;
            ++cur;
        }
    }

    return res;
}

#pragma region GTest
static int is_02938_SeparateBlackAndWhiteBalls_RunTest()
{
    stringstream ss;
    ss << "*_02938_SeparateBlackAndWhiteBalls.expected*"
       << ":"
       << "*_02938_SeparateBlackAndWhiteBalls0.expected*"
       << ":"
       << "*_02938_SeparateBlackAndWhiteBalls1.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_02938_SeparateBlackAndWhiteBalls, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        long long expected = v0[i];

        // Actual
        long long actual = _02938_SeparateBlackAndWhiteBalls(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02938_SeparateBlackAndWhiteBalls0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        long long expected = v0[i];

        // Actual
        long long actual = _02938_SeparateBlackAndWhiteBalls0(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02938_SeparateBlackAndWhiteBalls1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        long long expected = v0[i];

        // Actual
        long long actual = _02938_SeparateBlackAndWhiteBalls1(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
