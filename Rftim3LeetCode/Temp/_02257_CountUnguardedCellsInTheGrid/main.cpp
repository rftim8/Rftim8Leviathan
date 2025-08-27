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

// Iteratve Simulation
static int _02257_CountUnguardedCellsInTheGrid(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls);
// Recursive Way
static int _02257_CountUnguardedCellsInTheGrid0(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls);
// Speed
static int _02257_CountUnguardedCellsInTheGrid1(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls);

static int is_02257_CountUnguardedCellsInTheGrid_RunTest();

/**
 * You are given two integers m and n representing a 0-indexed m x n grid.
 * You are also given two 2D integer arrays guards and walls where guards[i] = [rowi, coli] and
 * walls[j] = [rowj, colj] represent the positions of the ith guard and jth wall respectively.
 * A guard can see every cell in the four cardinal directions (north, east, south, or west) starting
 * from their position unless obstructed by a wall or another guard.
 * A cell is guarded if there is at least one guard that can see it.
 * Return the number of unoccupied cells that are not guarded.
 *
 * Constraints:
 *
 * 1 <= m, n <= 10^5
 * 2 <= m * n <= 10^5
 * 1 <= guards.length, walls.length <= 5 * 10^4
 * 2 <= guards.length + walls.length <= m * n
 * guards[i].length == walls[j].length == 2
 * 0 <= rowi, rowj < m
 * 0 <= coli, colj < n
 * All the positions in guards and walls are unique.
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_02257_CountUnguardedCellsInTheGrid_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<int> v, v0, v3;
static vector<vector<vector<int>>> v1, v2;

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
        int s;
        cin >> s;
        v.push_back(s);

        cin >> s;
        cin.get();
        v0.push_back(s);

        string s0;
        getline(cin, s0);
        v1.push_back(stringTo2DVectorInt(s0));

        s0 = "";
        getline(cin, s0);
        v2.push_back(stringTo2DVectorInt(s0));

        cin >> s;
        v3.push_back(s);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        cout << _02257_CountUnguardedCellsInTheGrid(v[i], v0[i], v1[i], v2[i]) << "\n";
        cout << _02257_CountUnguardedCellsInTheGrid0(v[i], v0[i], v1[i], v2[i]) << "\n";
        cout << _02257_CountUnguardedCellsInTheGrid1(v[i], v0[i], v1[i], v2[i]) << "\n";
    }
}

static const int UNGUARDED = 0;
static const int GUARDED = 1;
static const int GUARD = 2;
static const int WALL = 3;

#pragma region Iterative Simulation
static void markguarded(int row, int col, vector<vector<int>> &grid)
{
    for (int r = row - 1; r >= 0; r--)
    {
        if (grid[r][col] == WALL || grid[r][col] == GUARD)
            break;

        grid[r][col] = GUARDED;
    }

    for (int r = row + 1; r < grid.size(); r++)
    {
        if (grid[r][col] == WALL || grid[r][col] == GUARD)
            break;

        grid[r][col] = GUARDED;
    }

    for (int c = col - 1; c >= 0; c--)
    {
        if (grid[row][c] == WALL || grid[row][c] == GUARD)
            break;

        grid[row][c] = GUARDED;
    }

    for (int c = col + 1; c < grid[row].size(); c++)
    {
        if (grid[row][c] == WALL || grid[row][c] == GUARD)
            break;

        grid[row][c] = GUARDED;
    }
}

static int _02257_CountUnguardedCellsInTheGrid(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls)
{
    vector<vector<int>> grid(m, vector<int>(n, UNGUARDED));

    for (const auto &guard : guards)
    {
        grid[guard[0]][guard[1]] = GUARD;
    }

    for (const auto &wall : walls)
    {
        grid[wall[0]][wall[1]] = WALL;
    }

    for (const auto &guard : guards)
    {
        markguarded(guard[0], guard[1], grid);
    }

    int count = 0;

    for (const auto &row : grid)
    {
        for (const auto &cell : row)
        {
            if (cell == UNGUARDED)
                count++;
        }
    }

    return count;
}
#pragma endregion

#pragma region Recursive
void recurse(int row, int col, vector<vector<int>> &grid, char direction)
{
    if (row < 0 || row >= grid.size() || col < 0 ||
        col >= grid[row].size() || grid[row][col] == GUARD ||
        grid[row][col] == WALL)
        return;

    grid[row][col] = GUARDED;

    if (direction == 'U')
        recurse(row - 1, col, grid, 'U');

    if (direction == 'D')
        recurse(row + 1, col, grid, 'D');

    if (direction == 'L')
        recurse(row, col - 1, grid, 'L');

    if (direction == 'R')
        recurse(row, col + 1, grid, 'R');
}

static int _02257_CountUnguardedCellsInTheGrid0(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls)
{
    vector<vector<int>> grid(m, vector<int>(n, UNGUARDED));

    for (const auto &guard : guards)
    {
        grid[guard[0]][guard[1]] = GUARD;
    }

    for (const auto &wall : walls)
    {
        grid[wall[0]][wall[1]] = WALL;
    }

    for (const auto &guard : guards)
    {
        recurse(guard[0] - 1, guard[1], grid, 'U');
        recurse(guard[0] + 1, guard[1], grid, 'D');
        recurse(guard[0], guard[1] - 1, grid, 'L');
        recurse(guard[0], guard[1] + 1, grid, 'R');
    }

    int count = 0;

    for (const auto &row : grid)
    {
        for (const auto &cell : row)
        {
            if (cell == UNGUARDED)
                count++;
        }
    }

    return count;
}
#pragma endregion

static int _02257_CountUnguardedCellsInTheGrid1(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls)
{
    int g[m][n];
    memset(g, 0, sizeof(g));

    for (auto &e : guards)
    {
        g[e[0]][e[1]] = 2;
    }

    for (auto &e : walls)
    {
        g[e[0]][e[1]] = 2;
    }

    int dirs[5] = {-1, 0, 1, 0, -1};

    for (auto &e : guards)
    {
        for (int k = 0; k < 4; ++k)
        {
            int x = e[0], y = e[1];
            int a = dirs[k], b = dirs[k + 1];

            while (x + a >= 0 && x + a < m && y + b >= 0 && y + b < n && g[x + a][y + b] < 2)
            {
                x += a;
                y += b;
                g[x][y] = 1;
            }
        }
    }

    int ans = 0;

    for (auto &row : g)
    {
        ans += count(row, row + n, 0);
    }

    return ans;
}

#pragma region GTest
static int is_02257_CountUnguardedCellsInTheGrid_RunTest()
{
    stringstream ss;
    ss << "*_02257_CountUnguardedCellsInTheGrid.expected*"
       << ":"
       << "*_02257_CountUnguardedCellsInTheGrid0.expected*"
       << ":"
       << "*_02257_CountUnguardedCellsInTheGrid1.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_02257_CountUnguardedCellsInTheGrid, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v3[i];

        // Actual
        int actual = _02257_CountUnguardedCellsInTheGrid(v[i], v0[i], v1[i], v2[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02257_CountUnguardedCellsInTheGrid0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v3[i];

        // Actual
        int actual = _02257_CountUnguardedCellsInTheGrid0(v[i], v0[i], v1[i], v2[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02257_CountUnguardedCellsInTheGrid1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v3[i];

        // Actual
        int actual = _02257_CountUnguardedCellsInTheGrid1(v[i], v0[i], v1[i], v2[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
