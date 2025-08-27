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

// Greedy - My submission
static string _03174_ClearDigits(string s);
// Runtime - stack
static string _03174_ClearDigits_0(string s);
// Memory - stack
static string _03174_ClearDigits_1(string s);

static int is_03174_ClearDigits_RunTest();

/**
 * You are given a string s.
 * Your task is to remove all digits by doing this operation repeatedly:
 * Delete the first digit and the closest non-digit character to its left.
 * Return the resulting string after removing all digits.
 *
 * Constraints:
 *
 * 1 <= s.length <= 100
 * s consists only of lowercase English letters and digits.
 * The input is generated such that it is possible to delete all digits.
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_03174_ClearDigits_RunTest();
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
        v0.push_back(s == "\"\"" ? "" : s);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        cout << _03174_ClearDigits(v[i]) << "\n";
        cout << _03174_ClearDigits_0(v[i]) << "\n";
        cout << _03174_ClearDigits_1(v[i]) << "\n";
    }
}

static string _03174_ClearDigits(string s)
{
    vector<char> v = {};
    for (auto &&i : s)
    {
        v.push_back(i);
    }

    int n = v.size();
    for (int i = 0; i < n - 1; i++)
    {
        if (!isdigit(v[i]) && isdigit(v[i + 1]))
        {
            v.erase(v.begin() + i);
            v.erase(v.begin() + i);
            if (i > 0)
                i -= 2;
            else
                i--;
            n -= 2;
        }
    }

    return string(v.begin(), v.end());
}

static string _03174_ClearDigits_0(string s)
{
    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        if (!isdigit(s[i]))
            st.push(s[i]);
        else
            st.pop();
    }

    string ans = "";

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

static string _03174_ClearDigits_1(string s)
{
    string ans = "";

    for (char c : s)
    {
        if (isdigit(c))
            ans.pop_back();
        else
            ans.push_back(c);
    }

    return ans;
}

#pragma region GTest
static int is_03174_ClearDigits_RunTest()
{
    stringstream ss;
    ss << "*_03174_ClearDigits.expected*"
       << ":"
       << "*_03174_ClearDigits_0.expected*"
       << ":"
       << "*_03174_ClearDigits_1.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_03174_ClearDigits, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        string expected = v0[i];

        // Actual
        string actual = _03174_ClearDigits(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_03174_ClearDigits_0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        string expected = v0[i];

        // Actual
        string actual = _03174_ClearDigits_0(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_03174_ClearDigits_1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        string expected = v0[i];

        // Actual
        string actual = _03174_ClearDigits_1(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
