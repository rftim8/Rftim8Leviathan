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
static bool _01790_CheckIfOneStringSwapCanMakeStringsEqual(string s1, string s2);

static int is_01790_CheckIfOneStringSwapCanMakeStringsEqual_RunTest();

/**
 * You are given two strings s1 and s2 of equal length.
 * A string swap is an operation where you choose two indices in a string (not necessarily different)
 * and swap the characters at these indices.
 * Return true if it is possible to make both strings equal by performing at most one string swap on
 * exactly one of the strings.
 * Otherwise, return false.
 *
 * Constraints:
 *
 * 1 <= s1.length, s2.length <= 100
 * s1.length == s2.length
 * s1 and s2 consist of only lowercase English letters.
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_01790_CheckIfOneStringSwapCanMakeStringsEqual_RunTest();
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
        cin.get();
        v1.push_back(s0);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        cout << _01790_CheckIfOneStringSwapCanMakeStringsEqual(v[i], v0[i]) << "\n";
    }
}

static bool _01790_CheckIfOneStringSwapCanMakeStringsEqual(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();

    if (n != m)
        return false;

    int c = 0;
    pair<char, char> l = {' ', ' '};
    pair<char, char> r = {' ', ' '};

    for (int i = 0; i < n; i++)
    {
        if (s1[i] != s2[i])
        {
            if (c == 0)
            {
                l.first = s1[i];
                l.second = s2[i];
            }
            else
            {
                r.first = s1[i];
                r.second = s2[i];
            }
            c++;
        }
        
        if (c > 2)
            return false;
    }

    if (l.first != r.second || l.second != r.first)
        return false;

    return true;
}

#pragma region GTest
static int is_01790_CheckIfOneStringSwapCanMakeStringsEqual_RunTest()
{
    stringstream ss;
    ss << "*_01790_CheckIfOneStringSwapCanMakeStringsEqual.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_01790_CheckIfOneStringSwapCanMakeStringsEqual, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        bool expected = v1[i];

        // Actual
        bool actual = _01790_CheckIfOneStringSwapCanMakeStringsEqual(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
