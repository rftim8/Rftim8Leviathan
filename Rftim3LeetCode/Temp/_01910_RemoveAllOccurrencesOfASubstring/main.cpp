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

// Runtime - My submission
static string _01910_RemoveAllOccurrencesOfASubstring(string s, string part);
// Memory
static string _01910_RemoveAllOccurrencesOfASubstring_0(string s, string part);

static int is_01910_RemoveAllOccurrencesOfASubstring_RunTest();

/**
 * Given two strings s and part, perform the following operation on s until all occurrences of the substring
 * part are removed:
 * Find the leftmost occurrence of the substring part and remove it from s.
 * Return s after removing all occurrences of part.
 * A substring is a contiguous sequence of characters in a string.
 *
 * Constraints:
 *
 * 1 <= s.length <= 1000
 * 1 <= part.length <= 1000
 * s​​​​​​ and part consists of lowercase English letters.
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_01910_RemoveAllOccurrencesOfASubstring_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<string> v, v0, v1;

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

        s = "";
        cin >> s;
        cin.get();
        v1.push_back(s);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        cout << _01910_RemoveAllOccurrencesOfASubstring(v[i], v0[i]) << "\n";
        cout << _01910_RemoveAllOccurrencesOfASubstring_0(v[i], v0[i]) << "\n";
    }
}

static string _01910_RemoveAllOccurrencesOfASubstring(string s, string part)
{
    string result = s;
    int pos = 0;

    while ((pos = result.find(part, pos)) != string::npos)
    {
        result.replace(pos, part.length(), "");
        pos = 0;
    }

    return result;
}

static string _01910_RemoveAllOccurrencesOfASubstring_0(string s, string part)
{
    while (s.find(part) != string::npos)
    {
        s.erase(s.find(part), part.length());
    }

    return s;
}

#pragma region GTest
static int is_01910_RemoveAllOccurrencesOfASubstring_RunTest()
{
    stringstream ss;
    ss << "*_01910_RemoveAllOccurrencesOfASubstring.expected*"
       << ":"
       << "*_01910_RemoveAllOccurrencesOfASubstring_0.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_01910_RemoveAllOccurrencesOfASubstring, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        string expected = v1[i];

        // Actual
        string actual = _01910_RemoveAllOccurrencesOfASubstring(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_01910_RemoveAllOccurrencesOfASubstring_0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        string expected = v1[i];

        // Actual
        string actual = _01910_RemoveAllOccurrencesOfASubstring_0(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
