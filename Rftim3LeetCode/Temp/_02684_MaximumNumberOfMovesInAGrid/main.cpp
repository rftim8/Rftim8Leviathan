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

// BFS
static int _02684_MaximumNumberOfMovesInAGrid(vector<vector<int>> &grid);
// Top-Down DP
static int _02684_MaximumNumberOfMovesInAGrid0(vector<vector<int>> &grid);
// Bottom-Up DP
static int _02684_MaximumNumberOfMovesInAGrid1(vector<vector<int>> &grid);
// Bottom-Up DP Space Optimized
static int _02684_MaximumNumberOfMovesInAGrid2(vector<vector<int>> &grid);
// Speed
static int _02684_MaximumNumberOfMovesInAGrid3(vector<vector<int>> &grid);

static int is_02684_MaximumNumberOfMovesInAGrid_RunTest();

/**
 * You are given a 0-indexed m x n matrix grid consisting of positive integers.
 * You can start at any cell in the first column of the matrix, and traverse the grid in the
 * following way:
 *
 * From a cell (row, col), you can move to any of the cells: (row - 1, col + 1),
 * (row, col + 1) and (row + 1, col + 1) such that the value of the cell you move to,
 * should be strictly bigger than the value of the current cell.
 * Return the maximum number of moves that you can perform.
 *
 * Constraints:
 *
 * m == grid.length
 * n == grid[i].length
 * 2 <= m, n <= 1000
 * 4 <= m * n <= 10^5
 * 1 <= grid[i][j] <= 10^6
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_02684_MaximumNumberOfMovesInAGrid_RunTest();
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
        cout << _02684_MaximumNumberOfMovesInAGrid(v[i]) << "\n";
        cout << _02684_MaximumNumberOfMovesInAGrid0(v[i]) << "\n";
        cout << _02684_MaximumNumberOfMovesInAGrid1(v[i]) << "\n";
        cout << _02684_MaximumNumberOfMovesInAGrid2(v[i]) << "\n";
        cout << _02684_MaximumNumberOfMovesInAGrid3(v[i]) << "\n";
    }
}

static const int dirs[3] = {-1, 0, 1};

static int _02684_MaximumNumberOfMovesInAGrid(vector<vector<int>> &grid)
{
    int M = grid.size(), N = grid[0].size();
    queue<vector<int>> q;
    vector<vector<int>> vis(M, vector<int>(N, 0));

    for (int i = 0; i < M; i++)
    {
        vis[i][0] = 1;
        q.push({i, 0, 0});
    }

    int maxMoves = 0;

    while (!q.empty())
    {
        int sz = q.size();

        while (sz--)
        {
            vector<int> v = q.front();
            q.pop();

            int row = v[0], col = v[1], count = v[2];

            maxMoves = max(maxMoves, count);

            for (int dir : dirs)
            {
                int newRow = row + dir, newCol = col + 1;

                if (newRow >= 0 && newCol >= 0 && newRow < M &&
                    newCol < N && !vis[newRow][newCol] &&
                    grid[row][col] < grid[newRow][newCol])
                {
                    vis[newRow][newCol] = 1;
                    q.push({newRow, newCol, count + 1});
                }
            }
        }
    }

    return maxMoves;
}

#pragma region Top-Down DP
static int DFS(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    int M = grid.size(), N = grid[0].size();

    if (dp[row][col] != -1)
        return dp[row][col];

    int maxMoves = 0;

    for (int dir : dirs)
    {
        int newRow = row + dir, newCol = col + 1;

        if (newRow >= 0 && newCol >= 0 && newRow < M && newCol < N &&
            grid[row][col] < grid[newRow][newCol])
            maxMoves = max(maxMoves, 1 + DFS(newRow, newCol, grid, dp));
    }

    return dp[row][col] = maxMoves;
}

static int _02684_MaximumNumberOfMovesInAGrid0(vector<vector<int>> &grid)
{
    int M = grid.size(), N = grid[0].size();
    vector<vector<int>> dp(M, vector<int>(N, -1));
    int maxMoves = 0;

    for (int i = 0; i < M; i++)
    {
        int movesRequired = DFS(i, 0, grid, dp);

        maxMoves = max(maxMoves, movesRequired);
    }

    return maxMoves;
}
#pragma endregion

static int _02684_MaximumNumberOfMovesInAGrid1(vector<vector<int>> &grid)
{
    int M = grid.size(), N = grid[0].size();
    vector<vector<int>> dp(M, vector<int>(N, 0));

    for (int i = 0; i < M; i++)
    {
        dp[i][0] = 1;
    }

    int maxMoves = 0;

    for (int j = 1; j < N; j++)
    {
        for (int i = 0; i < M; i++)
        {
            if (grid[i][j] > grid[i][j - 1] && dp[i][j - 1] > 0)
                dp[i][j] = max(dp[i][j], dp[i][j - 1] + 1);

            if (i - 1 >= 0 && grid[i][j] > grid[i - 1][j - 1] &&
                dp[i - 1][j - 1] > 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);

            if (i + 1 < M && grid[i][j] > grid[i + 1][j - 1] &&
                dp[i + 1][j - 1] > 0)
                dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + 1);

            maxMoves = max(maxMoves, dp[i][j] - 1);
        }
    }

    return maxMoves;
}

static int _02684_MaximumNumberOfMovesInAGrid2(vector<vector<int>> &grid)
{
    int M = grid.size(), N = grid[0].size();
    vector<vector<int>> dp(M, vector<int>(2, 0));

    for (int i = 0; i < M; i++)
    {
        dp[i][0] = 1;
    }

    int maxMoves = 0;

    for (int j = 1; j < N; j++)
    {
        for (int i = 0; i < M; i++)
        {
            if (grid[i][j] > grid[i][j - 1] && dp[i][0] > 0)
                dp[i][1] = max(dp[i][1], dp[i][0] + 1);

            if (i - 1 >= 0 && grid[i][j] > grid[i - 1][j - 1] &&
                dp[i - 1][0] > 0)
                dp[i][1] = max(dp[i][1], dp[i - 1][0] + 1);

            if (i + 1 < M && grid[i][j] > grid[i + 1][j - 1] &&
                dp[i + 1][0] > 0)
                dp[i][1] = max(dp[i][1], dp[i + 1][0] + 1);

            maxMoves = max(maxMoves, dp[i][1] - 1);
        }

        for (int k = 0; k < M; k++)
        {
            dp[k][0] = dp[k][1];
            dp[k][1] = 0;
        }
    }

    return maxMoves;
}

static int _02684_MaximumNumberOfMovesInAGrid3(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    int res = 0;
    vector<int> dp(m);

    for (int j = 1; j < n; ++j)
    {
        int leftTop = 0;
        bool found = false;

        for (int i = 0; i < m; ++i)
        {
            int cur = -1;
            int nxtLeftTop = dp[i];

            if (i - 1 >= 0 && leftTop != -1 && grid[i][j] > grid[i - 1][j - 1])
                cur = max(cur, leftTop + 1);

            if (dp[i] != -1 && grid[i][j] > grid[i][j - 1])
                cur = max(cur, dp[i] + 1);

            if (i + 1 < m && dp[i + 1] != -1 && grid[i][j] > grid[i + 1][j - 1])
                cur = max(cur, dp[i + 1] + 1);

            dp[i] = cur;
            found = found || (dp[i] != -1);
            leftTop = nxtLeftTop;
        }

        if (!found)
            break;

        res = j;
    }

    return res;
}

#pragma region GTest
static int is_02684_MaximumNumberOfMovesInAGrid_RunTest()
{
    stringstream ss;
    ss << "*_02684_MaximumNumberOfMovesInAGrid.expected*"
       << ":"
       << "*_02684_MaximumNumberOfMovesInAGrid0.expected*"
       << ":"
       << "*_02684_MaximumNumberOfMovesInAGrid1.expected*"
       << ":"
       << "*_02684_MaximumNumberOfMovesInAGrid2.expected*"
       << ":"
       << "*_02684_MaximumNumberOfMovesInAGrid3.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_02684_MaximumNumberOfMovesInAGrid, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _02684_MaximumNumberOfMovesInAGrid(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02684_MaximumNumberOfMovesInAGrid0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _02684_MaximumNumberOfMovesInAGrid0(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02684_MaximumNumberOfMovesInAGrid1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _02684_MaximumNumberOfMovesInAGrid1(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02684_MaximumNumberOfMovesInAGrid2, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _02684_MaximumNumberOfMovesInAGrid2(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02684_MaximumNumberOfMovesInAGrid3, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _02684_MaximumNumberOfMovesInAGrid3(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
