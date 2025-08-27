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

// Greedy
static int _02914_MinimumNumberOfChangesToMakeBinaryStringBeautiful(string s);
// Greedy - Optimized
static int _02914_MinimumNumberOfChangesToMakeBinaryStringBeautiful0(string s);
// Speed
static int _02914_MinimumNumberOfChangesToMakeBinaryStringBeautiful1(string s);

static int is_02914_MinimumNumberOfChangesToMakeBinaryStringBeautiful_RunTest();

/**
 * You are given a 0-indexed binary string s having an even length.
 * A string is beautiful if it's possible to partition it into one or more substrings such that:
 * Each substring has an even length.
 * Each substring contains only 1's or only 0's.
 * You can change any character in s to 0 or 1.
 * Return the minimum number of changes required to make the string s beautiful.
 *
 * Constraints:
 *
 * 2 <= s.length <= 10^5
 * s has an even length.
 * s[i] is either '0' or '1'.
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_02914_MinimumNumberOfChangesToMakeBinaryStringBeautiful_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<string> v;
static vector<int> v0;

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

        int s0;
        cin >> s0;
        v0.push_back(s0);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        cout << _02914_MinimumNumberOfChangesToMakeBinaryStringBeautiful(v[i]) << "\n";
        cout << _02914_MinimumNumberOfChangesToMakeBinaryStringBeautiful0(v[i]) << "\n";
        cout << _02914_MinimumNumberOfChangesToMakeBinaryStringBeautiful1(v[i]) << "\n";
    }
}

static int _02914_MinimumNumberOfChangesToMakeBinaryStringBeautiful(string s)
{
    char currentChar = s[0];
    int consecutiveCount = 0;
    int minChangesRequired = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == currentChar)
        {
            consecutiveCount++;
            continue;
        }

        if (consecutiveCount % 2 == 0)
            consecutiveCount = 1;
        else
        {
            consecutiveCount = 0;
            minChangesRequired++;
        }

        currentChar = s[i];
    }

    return minChangesRequired;
}

static int _02914_MinimumNumberOfChangesToMakeBinaryStringBeautiful0(string s)
{
    int minChangesRequired = 0;

    for (int i = 0; i < s.length(); i += 2)
    {
        if (s[i] != s[i + 1])
            minChangesRequired++;
    }

    return minChangesRequired;
}

static int _02914_MinimumNumberOfChangesToMakeBinaryStringBeautiful1(string s)
{
    char currentChar = s[0];
    int consecutiveCount = 0;
    int minChangesRequired = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == currentChar)
        {
            consecutiveCount++;
            continue;
        }

        if (consecutiveCount % 2 == 0)
            consecutiveCount = 1;
        else
        {
            consecutiveCount = 0;
            minChangesRequired++;
        }

        currentChar = s[i];
    }

    return minChangesRequired;
}

#pragma region GTest
static int is_02914_MinimumNumberOfChangesToMakeBinaryStringBeautiful_RunTest()
{
    stringstream ss;
    ss << "*_02914_MinimumNumberOfChangesToMakeBinaryStringBeautiful.expected*"
       << ":"
       << "*_02914_MinimumNumberOfChangesToMakeBinaryStringBeautiful0.expected*"
       << ":"
       << "*_02914_MinimumNumberOfChangesToMakeBinaryStringBeautiful1.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_02914_MinimumNumberOfChangesToMakeBinaryStringBeautiful, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _02914_MinimumNumberOfChangesToMakeBinaryStringBeautiful(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02914_MinimumNumberOfChangesToMakeBinaryStringBeautiful0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _02914_MinimumNumberOfChangesToMakeBinaryStringBeautiful0(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02914_MinimumNumberOfChangesToMakeBinaryStringBeautiful1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _02914_MinimumNumberOfChangesToMakeBinaryStringBeautiful1(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
