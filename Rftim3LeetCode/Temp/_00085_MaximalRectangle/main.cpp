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
static int _00085_MaximalRectangle(vector<vector<char>> &matrix);

static int is_00085_MaximalRectangle_RunTest();

/**
 * Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
 *
 * Constraints:
 *
 * rows == matrix.length
 * cols == matrix[i].length
 * 1 <= row, cols <= 200
 * matrix[i][j] is '0' or '1'.
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_00085_MaximalRectangle_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<vector<vector<char>>> v;
static vector<int> v0;

static vector<vector<char>> stringTo2DVectorChar(string s)
{
    vector<vector<char>> res = {};
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
        vector<char> a = {};
        string t;
        stringstream ss(j);
        while (getline(ss, t, ','))
        {
            if (t != "null" &&
                t != "")
                a.push_back(t[0]);
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
        getline(cin, s);
        v.push_back(stringTo2DVectorChar(s));

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
        cout << _00085_MaximalRectangle(v[i]) << "\n";
    }
}

static int _00085_MaximalRectangle(vector<vector<char>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int r = 0;
    vector<int> h(m, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == '1')
                h[j] += 1;
            else
                h[j] = 0;
        }

        stack<int> s;

        for (int j = 0; j <= m; j++)
        {
            int c = j == m ? 0 : h[j];

            while (!s.empty() && h[s.top()] > c)
            {
                int l = h[s.top()];
                s.pop();
                int w = j - 1 - (s.empty() ? -1 : s.top());

                r = max(r, l * w);
            }

            s.push(j);
        }
    }

    return r;
}

#pragma region GTest
static int is_00085_MaximalRectangle_RunTest()
{
    stringstream ss;
    ss << "*_00085_MaximalRectangle.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_00085_MaximalRectangle, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _00085_MaximalRectangle(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
