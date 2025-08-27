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
static string _01957_DeleteCharactersToMakeFancyString(string s);
// Speed
static string _01957_DeleteCharactersToMakeFancyString0(string s);

static int is_01957_DeleteCharactersToMakeFancyString_RunTest();

/**
 * A fancy string is a string where no three consecutive characters are equal.
 * Given a string s, delete the minimum possible number of characters from s to make it fancy.
 * Return the final string after the deletion. It can be shown that the answer will always be unique.
 *
 * Constraints:
 *
 * 1 <= s.length <= 10^5
 * s consists only of lowercase English letters.
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_01957_DeleteCharactersToMakeFancyString_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<string> v, v0;

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
        cin.get();
        v0.push_back(s);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        cout << _01957_DeleteCharactersToMakeFancyString(v[i]) << "\n";
        cout << _01957_DeleteCharactersToMakeFancyString0(v[i]) << "\n";
    }
}

static string _01957_DeleteCharactersToMakeFancyString(string s)
{
    int n = s.size();
    string sb = "";
    int c = 1;
    sb += (s[0]);

    for (int i = 1; i < n; i++)
    {
        if (s[i - 1] == s[i])
        {
            c++;
            if (c < 3)
                sb += (s[i]);
        }
        else
        {
            sb += (s[i]);
            c = 1;
        }
    }

    return sb;
}

static string _01957_DeleteCharactersToMakeFancyString0(string s)
{
    if (s.length() < 3)
        return s;

    int j = 2;

    for (int i = 2; i < s.size(); ++i)
        if (s[i] != s[j - 1] || s[i] != s[j - 2])
            s[j++] = s[i];

    s.resize(j);

    return s;
}

#pragma region GTest
static int is_01957_DeleteCharactersToMakeFancyString_RunTest()
{
    stringstream ss;
    ss << "*_01957_DeleteCharactersToMakeFancyString.expected*"
       << ":"
       << "*_01957_DeleteCharactersToMakeFancyString0.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_01957_DeleteCharactersToMakeFancyString, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        string expected = v0[i];

        // Actual
        string actual = _01957_DeleteCharactersToMakeFancyString(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_01957_DeleteCharactersToMakeFancyString0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        string expected = v0[i];

        // Actual
        string actual = _01957_DeleteCharactersToMakeFancyString0(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
