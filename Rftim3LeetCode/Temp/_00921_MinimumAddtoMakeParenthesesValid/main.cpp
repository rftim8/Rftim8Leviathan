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
static int _00921_MinimumAddtoMakeParenthesesValid(string s);

static int is_00921_MinimumAddtoMakeParenthesesValid_RunTest();

/**
 * A parentheses string is valid if and only if:
 *
 * It is the empty string,
 * It can be written as AB (A concatenated with B), where A and B are valid strings, or
 * It can be written as (A), where A is a valid string.
 * You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.
 *
 * For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".
 * Return the minimum number of moves required to make s valid.
 *
 * Constraints:
 *
 * 1 <= s.length <= 1000
 * s[i] is either '(' or ')'.
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_00921_MinimumAddtoMakeParenthesesValid_RunTest();
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
        cin.get();
        v0.push_back(s0);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        cout << _00921_MinimumAddtoMakeParenthesesValid(v[i]) << "\n";
    }
}

static int _00921_MinimumAddtoMakeParenthesesValid(string s)
{
    int openBrackets = 0;
    int minAddsRequired = 0;

    for (char c : s)
    {
        if (c == '(')
            openBrackets++;
        else
            openBrackets > 0 ? openBrackets-- : minAddsRequired++;
    }

    return minAddsRequired + openBrackets;
}

#pragma region GTest
static int is_00921_MinimumAddtoMakeParenthesesValid_RunTest()
{
    stringstream ss;
    ss << "*_00921_MinimumAddtoMakeParenthesesValid.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_00921_MinimumAddtoMakeParenthesesValid, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _00921_MinimumAddtoMakeParenthesesValid(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
