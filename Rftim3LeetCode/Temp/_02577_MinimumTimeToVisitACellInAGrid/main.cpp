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
static int _02577_MinimumTimeToVisitACellInAGrid(vector<vector<int>> &grid);
// Speed
static int _02577_MinimumTimeToVisitACellInAGrid0(vector<vector<int>> &grid);

static int is_02577_MinimumTimeToVisitACellInAGrid_RunTest();

/**
 * You are given a m x n matrix grid consisting of non-negative integers where grid[row][col]
 * represents the minimum time required to be able to visit the cell (row, col),
 * which means you can visit the cell (row, col) only when the time you visit it is greater than
 * or equal to grid[row][col].
 * You are standing in the top-left cell of the matrix in the 0th second,
 * and you must move to any adjacent cell in the four directions: up, down, left, and right.
 * Each move you make takes 1 second.
 * Return the minimum time required in which you can visit the bottom-right cell of the matrix.
 * If you cannot visit the bottom-right cell, then return -1.
 *
 * Constraints:
 *
 * m == grid.length
 * n == grid[i].length
 * 2 <= m, n <= 1000
 * 4 <= m * n <= 10^5
 * 0 <= grid[i][j] <= 10^5
 * grid[0][0] == 0
 */
int main()
{
    offline();
    dataCollector();

    solve();
    return 0;

    ::testing::InitGoogleTest();
    is_02577_MinimumTimeToVisitACellInAGrid_RunTest();
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
        cout << _02577_MinimumTimeToVisitACellInAGrid(v[i]) << "\n";
        cout << _02577_MinimumTimeToVisitACellInAGrid0(v[i]) << "\n";
    }
}

#pragma region Dijkstra
static bool isValid(vector<vector<bool>> &visited, int row, int col)
{
    return row >= 0 &&
           col >= 0 &&
           row < visited.size() &&
           col < visited[0].size() &&
           !visited[row][col];
}

static int _02577_MinimumTimeToVisitACellInAGrid(vector<vector<int>> &grid)
{
    if (grid[0][1] > 1 && grid[1][0] > 1)
        return -1;

    int rows = grid.size(), cols = grid[0].size();
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
    pq.push({grid[0][0], 0, 0});

    while (!pq.empty())
    {
        auto curr = pq.top();
        pq.pop();
        int time = curr[0], row = curr[1], col = curr[2];

        if (row == rows - 1 && col == cols - 1)
            return time;

        if (visited[row][col])
            continue;

        visited[row][col] = true;

        for (auto &d : directions)
        {
            int nextRow = row + d[0], nextCol = col + d[1];

            if (!isValid(visited, nextRow, nextCol))
                continue;

            int waitTime = ((grid[nextRow][nextCol] - time) % 2 == 0) ? 1 : 0;
            int nextTime = max(grid[nextRow][nextCol] + waitTime, time + 1);
            pq.push({nextTime, nextRow, nextCol});
        }
    }

    return -1;
}
#pragma endregion

static int _02577_MinimumTimeToVisitACellInAGrid0(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<int> visited(m * n, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 0});
    visited[0] = 0;
    vector<int> dir = {0, -1, 0, 1, 0};

    if (grid[1][0] > 1 && grid[0][1] > 1)
        return -1;

    while (q.size() > 0)
    {
        auto node = q.top();
        q.pop();

        int row = node.second / n;
        int col = node.second % n;
        int val = node.second;
        int t = node.first;

        if (row == m - 1 && col == n - 1)
            return t;

        for (int j = 0; j < 4; j++)
        {
            int new_row = row + dir[j];
            int new_col = col + dir[j + 1];

            if (new_row < 0 || new_row >= m || new_col < 0 || new_col >= n)
                continue;

            int val = new_row * n + new_col;

            if (visited[val] != -1)
                continue;

            if (grid[new_row][new_col] <= t + 1)
                visited[val] = t + 1;
            else if ((t + 1) % 2 != grid[new_row][new_col] % 2)
                visited[val] = grid[new_row][new_col] + 1;
            else
                visited[val] = grid[new_row][new_col];

            q.push({visited[val], val});
        }
    }

    return -1;
}

#pragma region GTest
static int is_02577_MinimumTimeToVisitACellInAGrid_RunTest()
{
    stringstream ss;
    ss << "*_02577_MinimumTimeToVisitACellInAGrid.expected*"
       << ":"
       << "*_02577_MinimumTimeToVisitACellInAGrid0.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_02577_MinimumTimeToVisitACellInAGrid, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _02577_MinimumTimeToVisitACellInAGrid(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02577_MinimumTimeToVisitACellInAGrid0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _02577_MinimumTimeToVisitACellInAGrid0(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
