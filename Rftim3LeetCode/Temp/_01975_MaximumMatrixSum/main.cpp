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

// Journey From Minus To Plus
static long long _01975_MaximumMatrixSum(vector<vector<int>> &matrix);
// Speed
static long long _01975_MaximumMatrixSum0(vector<vector<int>> &matrix);

static int is_01975_MaximumMatrixSum_RunTest();

/**
 * You are given an n x n integer matrix. You can do the following operation any number of times:
 * Choose any two adjacent elements of matrix and multiply each of them by -1.
 * Two elements are considered adjacent if and only if they share a border.
 * Your goal is to maximize the summation of the matrix's elements.
 * Return the maximum sum of the matrix's elements using the operation mentioned above.
 *
 * Constraints:
 *
 * n == matrix.length == matrix[i].length
 * 2 <= n <= 250
 * -10^5 <= matrix[i][j] <= 10^5
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_01975_MaximumMatrixSum_RunTest();
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
        cout << _01975_MaximumMatrixSum(v[i]) << "\n";
        cout << _01975_MaximumMatrixSum0(v[i]) << "\n";
    }
}

static long long _01975_MaximumMatrixSum(vector<vector<int>> &matrix)
{
    long long totalSum = 0;
    int minAbsVal = INT_MAX;
    int negativeCount = 0;

    for (auto &row : matrix)
    {
        for (int val : row)
        {
            totalSum += abs(val);

            if (val < 0)
                negativeCount++;

            minAbsVal = min(minAbsVal, abs(val));
        }
    }

    if (negativeCount % 2 != 0)
        totalSum -= 2 * minAbsVal;

    return totalSum;
}

static long long _01975_MaximumMatrixSum0(vector<vector<int>> &matrix)
{
    long long neg_cnt = 0, ans = 0, size = matrix.size(), minn = 1000000;

    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
        {
            ans += abs(matrix[i][j]);

            if (matrix[i][j] < 0)
                neg_cnt++;

            minn = minn < abs(matrix[i][j]) ? minn : abs(matrix[i][j]);
        }

    if (neg_cnt % 2 == 0)
        return ans;
    else
        return ans - 2 * minn;
}

#pragma region GTest
static int is_01975_MaximumMatrixSum_RunTest()
{
    stringstream ss;
    ss << "*_01975_MaximumMatrixSum.expected*"
       << ":"
       << "*_01975_MaximumMatrixSum0.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_01975_MaximumMatrixSum, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        long long expected = v0[i];

        // Actual
        long long actual = _01975_MaximumMatrixSum(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_01975_MaximumMatrixSum0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        long long expected = v0[i];

        // Actual
        long long actual = _01975_MaximumMatrixSum0(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
