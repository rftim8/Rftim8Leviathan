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

// LeetCode problem
static bool _00796_RotateString(string s, string goal);

static int is_00796_RotateString_RunTest();

/**
 * Given two strings s and goal, return true if and only if s can become goal after some
 * number of shifts on s.
 * A shift on s consists of moving the leftmost character of s to the rightmost position.
 * For example, if s = "abcde", then it will be "bcdea" after one shift.
 *
 * Constraints:
 *
 * 1 <= s.length, goal.length <= 100
 * s and goal consist of lowercase English letters.
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_00796_RotateString_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<string> v, v0;
static vector<bool> v1;

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

        cin >> s;
        v0.push_back(s);

        bool s0;
        cin >> s0;
        v1.push_back(s0);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        cout << _00796_RotateString(v[i], v0[i]) << "\n";
    }
}

static bool _00796_RotateString(string s, string goal)
{
    int n = s.size();
    int m = goal.size();

    if (n != m)
        return false;

    string x = s;

    for (int i = 0; i < n; i++)
    {
        x += x[0];
        x.erase(0, 1);
        if (x == goal)
            return true;
    }

    return false;
}

#pragma region GTest
static int is_00796_RotateString_RunTest()
{
    stringstream ss;
    ss << "*_00796_RotateString.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_00796_RotateString, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        bool expected = v1[i];

        // Actual
        bool actual = _00796_RotateString(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
