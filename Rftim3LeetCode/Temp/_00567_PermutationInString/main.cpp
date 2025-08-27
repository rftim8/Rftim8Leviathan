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
static bool _00567_PermutationInString(string s1, string s2);
// Speed
static bool _00567_PermutationInString0(string s1, string s2);
// Speed
static bool _00567_PermutationInString1(string s1, string s2);

static int is_00567_PermutationInString_RunTest();

/**
 * Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
 * In other words, return true if one of s1's permutations is the substring of s2.
 *
 * Constraints:
 *
 * 1 <= s1.length, s2.length <= 10^4
 * s1 and s2 consist of lowercase English letters.
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_00567_PermutationInString_RunTest();
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
        cout << _00567_PermutationInString(v[i], v0[i]) << "\n";
        cout << _00567_PermutationInString0(v[i], v0[i]) << "\n";
        cout << _00567_PermutationInString1(v[i], v0[i]) << "\n";
    }
}

static bool _00567_PermutationInString(string s1, string s2)
{
    int n = s2.size();
    int x = 0;
    int y = s1.size();
    vector<char> z1(s1.begin(), s1.end());
    sort(z1.begin(), z1.end());

    for (int i = 0; i <= n - y; i++)
    {
        vector<char> z(s2.begin() + x, s2.begin() + x + y);
        sort(z.begin(), z.end());

        if (z1 == z)
            return true;

        x++;
    }

    return false;
}

static bool allZero(int *arr)
{
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] != 0)
            return false;
    }

    return true;
}

static bool _00567_PermutationInString0(string s1, string s2)
{
    if (s2.length() < s1.length())
        return false;

    int arr[26] = {0};

    for (int i = 0; i < s1.length(); i++)
    {
        arr[s1[i] - 'a']++;
    }

    int len = s1.length();

    for (int i = 0; i < s2.length(); i++)
    {
        arr[s2[i] - 'a']--;

        if (i - len >= 0)
            arr[s2[i - len] - 'a']++;

        if (allZero(arr))
            return true;
    }

    return false;
}

static bool _00567_PermutationInString1(string s1, string s2)
{
    if (s1.length() > s2.length())
        return false;

    map<char, int> c1, c2;

    for (int i = 0; i < s1.length(); i++)
    {
        c1[s1[i]]++;
    }

    for (int i = 0; i < s2.length(); i++)
    {
        c2[s2[i]]++;

        if (i >= (s1.length() - 1))
        {
            if (i >= s1.length())
                c2[s2[i - s1.length()]]--;

            int f = 1;

            for (char x = 'a'; x <= 'z'; x++)
            {
                if (c1[x] != c2[x])
                {
                    f = 0;
                    break;
                }
            }

            if (f)
                return true;
        }
    }

    return false;
}

#pragma region GTest
static int is_00567_PermutationInString_RunTest()
{
    stringstream ss;
    ss << "*_00567_PermutationInString.expected*"
       << ":"
       << "*_00567_PermutationInString0.expected*"
       << ":"
       << "*_00567_PermutationInString1.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_00567_PermutationInString, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        bool expected = v1[i];

        // Actual
        bool actual = _00567_PermutationInString(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_00567_PermutationInString0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        bool expected = v1[i];

        // Actual
        bool actual = _00567_PermutationInString0(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_00567_PermutationInString1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        bool expected = v1[i];

        // Actual
        bool actual = _00567_PermutationInString1(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
