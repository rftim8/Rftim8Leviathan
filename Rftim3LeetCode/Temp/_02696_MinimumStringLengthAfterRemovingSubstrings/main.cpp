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
static int _02696_MinimumStringLengthAfterRemovingSubstrings(string s);
// Speed
static int _02696_MinimumStringLengthAfterRemovingSubstrings0(string s);

static int is_02696_MinimumStringLengthAfterRemovingSubstrings_RunTest();

/**
 * You are given a string s consisting only of uppercase English letters.
 * You can apply some operations to this string where, in one operation,
 * you can remove any occurrence of one of the substrings "AB" or "CD" from s.
 * Return the minimum possible length of the resulting string that you can obtain.
 * Note that the string concatenates after removing the substring and could produce new "AB" or "CD" substrings.
 *
 * Constraints:
 *
 * 1 <= s.length <= 100
 * s consists only of uppercase English letters.
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_02696_MinimumStringLengthAfterRemovingSubstrings_RunTest();
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
        cout << _02696_MinimumStringLengthAfterRemovingSubstrings(v[i]) << "\n";
        cout << _02696_MinimumStringLengthAfterRemovingSubstrings0(v[i]) << "\n";
    }
}

static int _02696_MinimumStringLengthAfterRemovingSubstrings(string s)
{
    vector<char> r(s.begin(), s.end());
    bool f = true;

    while (f)
    {
        f = false;
        int n = r.size() - 1;

        for (int i = 0; i < n; i++)
        {
            if ((r[i] == 'A' && r[i + 1] == 'B') ||
                (r[i] == 'C' && r[i + 1] == 'D'))
            {
                r.erase(r.begin() + i + 1);
                r.erase(r.begin() + i);
                f = true;
            }

            n = r.size() - 1;
        }
    }

    return r.size() > 0 ? r.size() : 0;
}

static int _02696_MinimumStringLengthAfterRemovingSubstrings0(string s)
{
    stack<char> st;
    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        if (!st.empty() && ((st.top() == 'A' && s[i] == 'B') ||
                            (st.top() == 'C' && s[i] == 'D')))
            st.pop();
        else
            st.push(s[i]);
    }

    return st.size();
}

#pragma region GTest
static int is_02696_MinimumStringLengthAfterRemovingSubstrings_RunTest()
{
    stringstream ss;
    ss << "*_02696_MinimumStringLengthAfterRemovingSubstrings.expected*"
       << ":"
       << "*_02696_MinimumStringLengthAfterRemovingSubstrings0.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_02696_MinimumStringLengthAfterRemovingSubstrings, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _02696_MinimumStringLengthAfterRemovingSubstrings(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02696_MinimumStringLengthAfterRemovingSubstrings0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _02696_MinimumStringLengthAfterRemovingSubstrings0(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
