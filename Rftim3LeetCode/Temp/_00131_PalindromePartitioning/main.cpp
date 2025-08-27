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
static vector<vector<string>> _00131_PalindromePartitioning(string s);

static int is_00131_PalindromePartitioning_RunTest();

/**
 * Given a string s, partition s such that every substring of the partition is a palindrome.
 * Return all possible palindrome partitioning of s.
 *
 * Constraints:
 *
 * 1 <= s.length <= 16
 * s contains only lowercase English letters.
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_00131_PalindromePartitioning_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<string> v;
static vector<vector<vector<string>>> v0;

static vector<vector<string>> stringTo2DVectorString(string s)
{
    s.erase(remove(s.begin(), s.end(), '\"'), s.end());
    vector<vector<string>> res = {};
    int l = 0, r = 0;
    string a = "";
    vector<string> vv = {};
    for (auto &&j : s)
    {
        if (j == '[')
            l++;
        else if (j == ']')
        {
            r++;
            if (l > r)
            {
                vv.push_back(a);
                a = "";
            }
        }
        else
            a += j;
    }

    for (auto &&j : vv)
    {
        vector<string> a = {};
        string t;
        stringstream ss(j);
        while (getline(ss, t, ','))
        {
            if (t != "null" &&
                t != "")
                a.push_back(t);
        }
        res.push_back(a);
    }

    return res;
}

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
        v0.push_back(stringTo2DVectorString(s));
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        vector<vector<string>> res = _00131_PalindromePartitioning(v[i]);
        for (auto &&j : res)
        {
            for (auto &&k : j)
            {
                cout << k << " ";
            }
            cout << "\n";
        }
    }
}

static vector<vector<string>> res;

static bool isPalindrome(string s)
{
    int l = 0, r = s.size() - 1;

    while (l < r)
    {
        if (s[l++] != s[r--])
            return false;
    }

    return true;
}

static void backtrack(string s, vector<string> l)
{
    if (s.empty())
    {
        res.push_back(vector<string>(l));
        return;
    }

    for (int i = 1; i <= s.size(); i++)
    {
        string c = s.substr(0, i);
        if (!isPalindrome(c))
            continue;

        l.push_back(c);
        backtrack(s.substr(i), l);
        l.erase(l.end() - 1);
    }
}

static vector<vector<string>> _00131_PalindromePartitioning(string s)
{
    res = {};
    backtrack(s, {});

    return res;
}

#pragma region GTest
static int is_00131_PalindromePartitioning_RunTest()
{
    stringstream ss;
    ss << "*_00131_PalindromePartitioning.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_00131_PalindromePartitioning, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<vector<string>> expected = v0[i];

        // Actual
        vector<vector<string>> actual = _00131_PalindromePartitioning(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
