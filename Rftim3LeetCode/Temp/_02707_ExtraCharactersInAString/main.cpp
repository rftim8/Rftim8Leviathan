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
static int _02707_ExtraCharactersInAString(string s, vector<string> &dictionary);
static int _02707_ExtraCharactersInAString0(string s, vector<string> &dictionary);

static int is_02707_ExtraCharactersInAString_RunTest();

/**
 * You are given a 0-indexed string s and a dictionary of words dictionary.
 * You have to break s into one or more non-overlapping substrings such that each substring is present in dictionary.
 * There may be some extra characters in s which are not present in any of the substrings.
 *
 * Return the minimum number of extra characters left over if you break up s optimally.
 *
 * Constraints:
 *
 * 1 <= s.length <= 50
 * 1 <= dictionary.length <= 50
 * 1 <= dictionary[i].length <= 50
 * dictionary[i] and s consists of only lowercase English letters
 * dictionary contains distinct words
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_02707_ExtraCharactersInAString_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<string> v;
static vector<vector<string>> v0;
static vector<int> v1;

static void dataCollector()
{
    cin >> n;
    cin >> m;
    cin.get();

    for (int i = 0; i < n * m; i += m)
    {
        string s;
        cin >> s;
        cin.get();
        v.push_back(s);

        s = "";
        getline(cin, s);
        stringstream ss(s);
        string t = "";
        vector<string> vv = {};
        while (getline(ss, t, ','))
        {
            vv.push_back(t);
        }
        v0.push_back(vv);

        int s0;
        cin >> s0;
        cin.get();
        v1.push_back(s0);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        cout << _02707_ExtraCharactersInAString(v[i], v0[i]) << "\n";
        cout << _02707_ExtraCharactersInAString0(v[i], v0[i]) << "\n";
    }
}

static int _02707_ExtraCharactersInAString(string s, vector<string> &dictionary)
{
    int n = s.size();
    vector<int> r(n + 1, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        r[i] = r[i + 1] + 1;

        for (int j = i; j < n; j++)
        {
            string c = s.substr(i, j + 1 - i);

            if (find(dictionary.begin(), dictionary.end(), c) != dictionary.end())
                r[i] = min(r[i], r[j + 1]);
        }
    }

    return r[0];
}

static int _02707_ExtraCharactersInAString0(string s, vector<string> &dictionary)
{
    int const n = s.size();
    vector<int> dp(n + 1);

    for (int i = 1; i < n + 1; ++i)
    {
        dp[i] = dp[i - 1] + 1;

        for (string const &word : dictionary)
        {
            int const m = word.length();

            if (i >= m)
            {
                bool flag = true;

                for (int j = i - m; j < i; ++j)
                {
                    if (s[j] != word[j - i + m])
                    {
                        flag = false;
                        break;
                    }
                }

                if (flag)
                    dp[i] = min(dp[i], dp[i - m]);
            }
        }
    }

    return dp[n];
}

#pragma region GTest
static int is_02707_ExtraCharactersInAString_RunTest()
{
    stringstream ss;
    ss << "*_02707_ExtraCharactersInAString.expected*"
       << ":"
       << "*_02707_ExtraCharactersInAString0.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_02707_ExtraCharactersInAString, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v1[i];

        // Actual
        int actual = _02707_ExtraCharactersInAString(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02707_ExtraCharactersInAString0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v1[i];

        // Actual
        int actual = _02707_ExtraCharactersInAString0(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
