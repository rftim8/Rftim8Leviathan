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

// Brute Force
static int _01072_FlipColumnsForMaximumNumberOfEqualRows(vector<vector<int>> &matrix);
// Hash Map
static int _01072_FlipColumnsForMaximumNumberOfEqualRows0(vector<vector<int>> &matrix);
// Speed
static int _01072_FlipColumnsForMaximumNumberOfEqualRows1(vector<vector<int>> &matrix);

static int is_01072_FlipColumnsForMaximumNumberOfEqualRows_RunTest();

/**
 * You are given an m x n binary matrix matrix.
 * You can choose any number of columns in the matrix and flip every cell in that column
 * (i.e., Change the value of the cell from 0 to 1 or vice versa).
 * Return the maximum number of rows that have all values equal after some number of flips.
 *
 * Constraints:
 *
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 300
 * matrix[i][j] is either 0 or 1.
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_01072_FlipColumnsForMaximumNumberOfEqualRows_RunTest();
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
        cout << _01072_FlipColumnsForMaximumNumberOfEqualRows(v[i]) << "\n";
        cout << _01072_FlipColumnsForMaximumNumberOfEqualRows0(v[i]) << "\n";
        cout << _01072_FlipColumnsForMaximumNumberOfEqualRows1(v[i]) << "\n";
    }
}

static int _01072_FlipColumnsForMaximumNumberOfEqualRows(vector<vector<int>> &matrix)
{
    int numCols = matrix[0].size();
    int maxIdenticalRows = 0;

    for (auto &currentRow : matrix)
    {
        vector<int> flippedRow(numCols);
        int identicalRowCount = 0;

        for (int col = 0; col < numCols; col++)
        {
            flippedRow[col] = 1 - currentRow[col];
        }

        for (auto &compareRow : matrix)
        {
            if (compareRow == currentRow || compareRow == flippedRow)
                identicalRowCount++;
        }

        maxIdenticalRows = max(maxIdenticalRows, identicalRowCount);
    }

    return maxIdenticalRows;
}

static int _01072_FlipColumnsForMaximumNumberOfEqualRows0(vector<vector<int>> &matrix)
{
    unordered_map<string, int> patternFrequency;

    for (auto &currentRow : matrix)
    {
        string patternBuilder = "";

        for (int col = 0; col < currentRow.size(); col++)
        {
            if (currentRow[0] == currentRow[col])
                patternBuilder += "T";
            else
                patternBuilder += "F";
        }

        patternFrequency[patternBuilder]++;
    }

    int maxFrequency = 0;

    for (auto &entry : patternFrequency)
    {
        maxFrequency = max(entry.second, maxFrequency);
    }

    return maxFrequency;
}

static int _01072_FlipColumnsForMaximumNumberOfEqualRows1(vector<vector<int>> &matrix)
{
    int res = 0;
    const int n = matrix[0].size();
    unordered_map<bitset<300>, int> freq;

    for (auto &row : matrix)
    {
        bitset<300> same;
        same.set(0);

        for (int i = 1; i < row.size(); i++)
        {
            if (row[0] != row[i])
                same.flip(i);
        }

        freq[same]++;
        res = max(res, freq[same]);
    }

    return res;
}

#pragma region GTest
static int is_01072_FlipColumnsForMaximumNumberOfEqualRows_RunTest()
{
    stringstream ss;
    ss << "*_01072_FlipColumnsForMaximumNumberOfEqualRows.expected*"
       << ":"
       << "*_01072_FlipColumnsForMaximumNumberOfEqualRows0.expected*"
       << ":"
       << "*_01072_FlipColumnsForMaximumNumberOfEqualRows1.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_01072_FlipColumnsForMaximumNumberOfEqualRows, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _01072_FlipColumnsForMaximumNumberOfEqualRows(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_01072_FlipColumnsForMaximumNumberOfEqualRows0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _01072_FlipColumnsForMaximumNumberOfEqualRows0(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_01072_FlipColumnsForMaximumNumberOfEqualRows1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _01072_FlipColumnsForMaximumNumberOfEqualRows1(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
