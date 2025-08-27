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

// Top-Down DP
static int _01277_CountSquareSubmatricesWithAllOnes(vector<vector<int>> &matrix);
// Bottom-Up DP
static int _01277_CountSquareSubmatricesWithAllOnes0(vector<vector<int>> &matrix);
// Speed
static int _01277_CountSquareSubmatricesWithAllOnes1(vector<vector<int>> &matrix);

static int is_01277_CountSquareSubmatricesWithAllOnes_RunTest();

/**
 * Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.
 * Constraints:
 *
 * 1 <= arr.length <= 300
 * 1 <= arr[0].length <= 300
 * 0 <= arr[i][j] <= 1
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_01277_CountSquareSubmatricesWithAllOnes_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<vector<vector<int>>> v;
static vector<int> v0;

static vector<vector<int>> stringTo2DVectorInt(string s)
{
    vector<vector<int>> res = {};
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
        vector<int> a = {};
        string t;
        stringstream ss(j);
        while (getline(ss, t, ','))
        {
            if (t != "null" &&
                t != "")
                a.push_back(stoi(t));
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
        v.push_back(stringTo2DVectorInt(s));

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
        cout << _01277_CountSquareSubmatricesWithAllOnes(v[i]) << "\n";
        cout << _01277_CountSquareSubmatricesWithAllOnes0(v[i]) << "\n";
        cout << _01277_CountSquareSubmatricesWithAllOnes1(v[i]) << "\n";
    }
}

#pragma region Top-Down DP
static int solve(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (i >= grid.size() || j >= grid[0].size())
        return 0;

    if (grid[i][j] == 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int right = solve(i, j + 1, grid, dp);
    int diagonal = solve(i + 1, j + 1, grid, dp);
    int below = solve(i + 1, j, grid, dp);

    return dp[i][j] = 1 + min(right, min(diagonal, below));
}

static int _01277_CountSquareSubmatricesWithAllOnes(vector<vector<int>> &matrix)
{
    int ans = 0;
    vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            ans += solve(i, j, matrix, dp);
        }
    }

    return ans;
}
#pragma endregion

static int _01277_CountSquareSubmatricesWithAllOnes0(vector<vector<int>> &matrix)
{
    int row = matrix.size(), col = matrix[0].size();
    vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
    int ans = 0;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == 1)
            {
                dp[i + 1][j + 1] = min({dp[i][j + 1], dp[i + 1][j], dp[i][j]}) + 1;
                ans += dp[i + 1][j + 1];
            }
        }
    }

    return ans;
}

static int _01277_CountSquareSubmatricesWithAllOnes1(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = matrix[i][0];
        ans += dp[i][0];
    }

    for (int j = 1; j < m; j++)
    {
        dp[0][j] = matrix[0][j];
        ans += dp[0][j];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][j] == 1)
                dp[i][j] = 1 + min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]});

            ans += dp[i][j];
        }
    }

    return ans;
}

#pragma region GTest
static int is_01277_CountSquareSubmatricesWithAllOnes_RunTest()
{
    stringstream ss;
    ss << "*_01277_CountSquareSubmatricesWithAllOnes.expected*"
       << ":"
       << "*_01277_CountSquareSubmatricesWithAllOnes0.expected*"
       << ":"
       << "*_01277_CountSquareSubmatricesWithAllOnes1.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_01277_CountSquareSubmatricesWithAllOnes, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _01277_CountSquareSubmatricesWithAllOnes(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_01277_CountSquareSubmatricesWithAllOnes0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _01277_CountSquareSubmatricesWithAllOnes0(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_01277_CountSquareSubmatricesWithAllOnes1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _01277_CountSquareSubmatricesWithAllOnes1(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
