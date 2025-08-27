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

// Stack
static int _01963_MinimumNumberOfSwapsToMakeTheStringBalanced(string s);
// Space-Optimized Stack
static int _01963_MinimumNumberOfSwapsToMakeTheStringBalanced0(string s);
// Speed
static int _01963_MinimumNumberOfSwapsToMakeTheStringBalanced1(string s);

static int is_01963_MinimumNumberOfSwapsToMakeTheStringBalanced_RunTest();

/**
 * You are given a 0-indexed string s of even length n. The string consists of exactly n / 2 opening brackets '[' and
 * n / 2 closing brackets ']'.
 * A string is called balanced if and only if:
 * It is the empty string, or
 * It can be written as AB, where both A and B are balanced strings, or
 * It can be written as [C], where C is a balanced string.
 * You may swap the brackets at any two indices any number of times.
 * Return the minimum number of swaps to make s balanced.
 *
 * Constraints:
 *
 * n == s.length
 * 2 <= n <= 10^6
 * n is even.
 * s[i] is either '[' or ']'.
 * The number of opening brackets '[' equals n / 2, and the number of closing brackets ']' equals n / 2.
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_01963_MinimumNumberOfSwapsToMakeTheStringBalanced_RunTest();
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
        getline(cin, s);
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
        cout << _01963_MinimumNumberOfSwapsToMakeTheStringBalanced(v[i]) << "\n";
        cout << _01963_MinimumNumberOfSwapsToMakeTheStringBalanced0(v[i]) << "\n";
        cout << _01963_MinimumNumberOfSwapsToMakeTheStringBalanced1(v[i]) << "\n";
    }
}

static int _01963_MinimumNumberOfSwapsToMakeTheStringBalanced(string s)
{
    stack<char> stack;
    int unbalanced = 0;

    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];

        if (ch == '[')
            stack.push(ch);
        else
        {
            if (!stack.empty())
                stack.pop();
            else
                unbalanced++;
        }
    }

    return (unbalanced + 1) / 2;
}

static int _01963_MinimumNumberOfSwapsToMakeTheStringBalanced0(string s)
{
    int stackSize = 0;
    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        char ch = s[i];

        if (ch == '[')
            stackSize++;
        else
        {
            if (stackSize > 0)
                stackSize--;
        }
    }

    return (stackSize + 1) / 2;
}

static int _01963_MinimumNumberOfSwapsToMakeTheStringBalanced1(string s)
{
    int lb = 0;
    int moves = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ']')
        {
            if (lb == 0)
            {
                moves++;
                lb++;
            }
            else
                lb--;
        }
        else
            lb++;
    }

    return moves;
}

#pragma region GTest
static int is_01963_MinimumNumberOfSwapsToMakeTheStringBalanced_RunTest()
{
    stringstream ss;
    ss << "*_01963_MinimumNumberOfSwapsToMakeTheStringBalanced.expected*"
       << ":"
       << "*_01963_MinimumNumberOfSwapsToMakeTheStringBalanced0.expected*"
       << ":"
       << "*_01963_MinimumNumberOfSwapsToMakeTheStringBalanced1.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_01963_MinimumNumberOfSwapsToMakeTheStringBalanced, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _01963_MinimumNumberOfSwapsToMakeTheStringBalanced(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_01963_MinimumNumberOfSwapsToMakeTheStringBalanced0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _01963_MinimumNumberOfSwapsToMakeTheStringBalanced0(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_01963_MinimumNumberOfSwapsToMakeTheStringBalanced1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _01963_MinimumNumberOfSwapsToMakeTheStringBalanced1(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
