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

// Brute Force - TLE
static bool _02825_MakeStringASubsequenceUsingCyclicIncrements(string str1, string str2);
// Two Pointer
static bool _02825_MakeStringASubsequenceUsingCyclicIncrements0(string str1, string str2);
// Speed
static bool _02825_MakeStringASubsequenceUsingCyclicIncrements1(string str1, string str2);

static int is_02825_MakeStringASubsequenceUsingCyclicIncrements_RunTest();

/**
 * You are given two 0-indexed strings str1 and str2.
 * In an operation, you select a set of indices in str1, and for each index i in the set,
 * increment str1[i] to the next character cyclically.
 * That is 'a' becomes 'b', 'b' becomes 'c', and so on, and 'z' becomes 'a'.
 * Return true if it is possible to make str2 a subsequence of str1 by performing the operation at most once, and false otherwise.
 *
 * Note: A subsequence of a string is a new string that is formed from the original string by deleting some (possibly none) of the characters without disturbing the relative positions of the remaining characters.
 *
 * Constraints:
 *
 * 1 <= str1.length <= 10^5
 * 1 <= str2.length <= 10^5
 * str1 and str2 consist of only lowercase English letters.
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_02825_MakeStringASubsequenceUsingCyclicIncrements_RunTest();
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

        s = "";
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
        cout << _02825_MakeStringASubsequenceUsingCyclicIncrements(v[i], v0[i]) << "\n";
        cout << _02825_MakeStringASubsequenceUsingCyclicIncrements0(v[i], v0[i]) << "\n";
        cout << _02825_MakeStringASubsequenceUsingCyclicIncrements1(v[i], v0[i]) << "\n";
    }
}

#pragma region Brute Force
static char getNextChar(char str1Char)
{
    return str1Char == 'z' ? 'a' : str1Char + 1;
}

static bool isSubsequence(string &str1, string &str2)
{
    int str1Index = 0, str2Index = 0;
    int lengthStr1 = str1.size(), lengthStr2 = str2.size();

    while (str1Index < lengthStr1 && str2Index < lengthStr2)
    {
        if (str1[str1Index] == str2[str2Index])
            str2Index++;

        str1Index++;
    }

    return str2Index == lengthStr2;
}

static bool _02825_MakeStringASubsequenceUsingCyclicIncrements(string str1, string str2)
{
    int lengthStr1 = str1.length();

    for (int mask = 0; mask < (1 << lengthStr1); mask++)
    {
        string temp = str1;

        for (int str1Index = 0; str1Index < lengthStr1; str1Index++)
        {
            if (mask & (1 << str1Index))
                temp[str1Index] = getNextChar(temp[str1Index]);
        }

        if (isSubsequence(temp, str2))
            return true;
    }

    return false;
}
#pragma endregion

static bool _02825_MakeStringASubsequenceUsingCyclicIncrements0(string str1, string str2)
{
    int str2Index = 0;
    int lengthStr1 = str1.size(), lengthStr2 = str2.size();

    for (int str1Index = 0;
         str1Index < lengthStr1 && str2Index < lengthStr2; ++str1Index)
    {
        if (str1[str1Index] == str2[str2Index] ||
            (str1[str1Index] + 1 == str2[str2Index]) ||
            (str1[str1Index] - 25 == str2[str2Index]))
            str2Index++;
    }

    return str2Index == lengthStr2;
}

static bool _02825_MakeStringASubsequenceUsingCyclicIncrements1(string str1, string str2)
{
    int m = str1.size(), n = str2.size();

    if (m < n)
        return false;

    int idx2 = 0;

    for (int idx1 = 0; idx1 < m && idx2 < n; idx1++)
    {
        if (str1[idx1] == str2[idx2] ||
            str1[idx1] + 1 == str2[idx2] ||
            str1[idx1] - 25 == str2[idx2])
            idx2++;
    }

    return idx2 == n;
}

#pragma region GTest
static int is_02825_MakeStringASubsequenceUsingCyclicIncrements_RunTest()
{
    stringstream ss;
    ss << "*_02825_MakeStringASubsequenceUsingCyclicIncrements.expected*"
       << ":"
       << "*_02825_MakeStringASubsequenceUsingCyclicIncrements0.expected*"
       << ":"
       << "*_02825_MakeStringASubsequenceUsingCyclicIncrements1.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_02825_MakeStringASubsequenceUsingCyclicIncrements, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        bool expected = v1[i];

        // Actual
        bool actual = _02825_MakeStringASubsequenceUsingCyclicIncrements(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02825_MakeStringASubsequenceUsingCyclicIncrements0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        bool expected = v1[i];

        // Actual
        bool actual = _02825_MakeStringASubsequenceUsingCyclicIncrements0(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02825_MakeStringASubsequenceUsingCyclicIncrements1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        bool expected = v1[i];

        // Actual
        bool actual = _02825_MakeStringASubsequenceUsingCyclicIncrements1(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
