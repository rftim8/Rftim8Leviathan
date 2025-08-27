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

// Dijkstra
static int _02290_MinimumObstacleRemovalToReachCorner(vector<vector<int>> &grid);
// BFS
static int _02290_MinimumObstacleRemovalToReachCorner0(vector<vector<int>> &grid);
// Speed
static int _02290_MinimumObstacleRemovalToReachCorner1(vector<vector<int>> &grid);

static int is_02290_MinimumObstacleRemovalToReachCorner_RunTest();

/**
 * You are given a 0-indexed 2D integer array grid of size m x n. Each cell has one of two values:
 * 0 represents an empty cell,
 * 1 represents an obstacle that may be removed.
 * You can move up, down, left, or right from and to an empty cell.
 * Return the minimum number of obstacles to remove so you can move from the upper left corner (0, 0)
 * to the lower right corner (m - 1, n - 1).
 *
 * Constraints:
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 10^5
 * 2 <= m * n <= 10^5
 * grid[i][j] is either 0 or 1.
 * grid[0][0] == grid[m - 1][n - 1] == 0
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_02290_MinimumObstacleRemovalToReachCorner_RunTest();
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
        cout << _02290_MinimumObstacleRemovalToReachCorner(v[i]) << "\n";
        cout << _02290_MinimumObstacleRemovalToReachCorner0(v[i]) << "\n";
        cout << _02290_MinimumObstacleRemovalToReachCorner1(v[i]) << "\n";
    }
}

#pragma region Dijkstra
static vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

static bool isValid(vector<vector<int>> &grid, int row, int col)
{
    return row >= 0 &&
           col >= 0 &&
           row < grid.size() &&
           col < grid[0].size();
}

static int _02290_MinimumObstacleRemovalToReachCorner(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> minObstacles(m, vector<int>(n, INT_MAX));
    minObstacles[0][0] = grid[0][0];
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({minObstacles[0][0], 0, 0});

    while (!pq.empty())
    {
        vector<int> current = pq.top();
        pq.pop();
        int obstacles = current[0], row = current[1], col = current[2];

        if (row == m - 1 && col == n - 1)
            return obstacles;

        for (vector<int> &dir : directions)
        {
            int newRow = row + dir[0], newCol = col + dir[1];

            if (isValid(grid, newRow, newCol))
            {
                int newObstacles = obstacles + grid[newRow][newCol];

                if (newObstacles < minObstacles[newRow][newCol])
                {
                    minObstacles[newRow][newCol] = newObstacles;
                    pq.push({newObstacles, newRow, newCol});
                }
            }
        }
    }

    return minObstacles[m - 1][n - 1];
}
#pragma endregion

#pragma region BFS
static int _02290_MinimumObstacleRemovalToReachCorner0(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> minObstacles(m, vector<int>(n, INT_MAX));
    minObstacles[0][0] = 0;
    deque<array<int, 3>> deque;
    deque.push_back({0, 0, 0});

    while (!deque.empty())
    {
        auto current = deque.front();
        deque.pop_front();
        int obstacles = current[0], row = current[1], col = current[2];

        for (auto &dir : directions)
        {
            int newRow = row + dir[0], newCol = col + dir[1];

            if (isValid(grid, newRow, newCol) &&
                minObstacles[newRow][newCol] == INT_MAX)
            {
                if (grid[newRow][newCol] == 1)
                {
                    minObstacles[newRow][newCol] = obstacles + 1;
                    deque.push_back({obstacles + 1, newRow, newCol});
                }
                else
                {
                    minObstacles[newRow][newCol] = obstacles;
                    deque.push_front({obstacles, newRow, newCol});
                }
            }
        }
    }

    return minObstacles[m - 1][n - 1];
}
#pragma endregion

static int _02290_MinimumObstacleRemovalToReachCorner1(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size();
    int dp[n][m];
    memset(dp, -1, sizeof(dp));
    dp[0][0] = grid[0][0];
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    queue<pair<int, int>> q, q1;
    q.push({0, 0});

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int x = p.first + dx[i], y = p.second + dy[i];

            if (x >= 0 &&
                x < n &&
                y >= 0 &&
                y < m &&
                dp[x][y] == -1)
            {
                dp[x][y] = dp[p.first][p.second] + grid[x][y];

                if (grid[x][y])
                    q1.push({x, y});
                else
                    q.push({x, y});
            }
        }

        if (q.empty())
            swap(q, q1);
    }

    return dp[n - 1][m - 1];
}

#pragma region GTest
static int is_02290_MinimumObstacleRemovalToReachCorner_RunTest()
{
    stringstream ss;
    ss << "*_02290_MinimumObstacleRemovalToReachCorner.expected*"
       << ":"
       << "*_02290_MinimumObstacleRemovalToReachCorner0.expected*"
       << ":"
       << "*_02290_MinimumObstacleRemovalToReachCorner1.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_02290_MinimumObstacleRemovalToReachCorner, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _02290_MinimumObstacleRemovalToReachCorner(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02290_MinimumObstacleRemovalToReachCorner0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _02290_MinimumObstacleRemovalToReachCorner0(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02290_MinimumObstacleRemovalToReachCorner1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _02290_MinimumObstacleRemovalToReachCorner1(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
