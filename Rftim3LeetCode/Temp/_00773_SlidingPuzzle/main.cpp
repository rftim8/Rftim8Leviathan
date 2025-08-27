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

// DFS
static int _00773_SlidingPuzzle(vector<vector<int>> &board);
// BFS
static int _00773_SlidingPuzzle0(vector<vector<int>> &board);

static int is_00773_SlidingPuzzle_RunTest();

/**
 * On an 2 x 3 board, there are five tiles labeled from 1 to 5, and an empty square represented by 0.
 * A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.
 * The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].
 * Given the puzzle board board, return the least number of moves required so that the state of the board
 * is solved.
 * If it is impossible for the state of the board to be solved, return -1.
 *
 * Constraints:
 *
 * board.length == 2
 * board[i].length == 3
 * 0 <= board[i][j] <= 5
 * Each value board[i][j] is unique.
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_00773_SlidingPuzzle_RunTest();
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
        cout << _00773_SlidingPuzzle(v[i]) << "\n";
        cout << _00773_SlidingPuzzle0(v[i]) << "\n";
    }
}

#pragma region DFS
static vector<vector<int>> directions = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {3, 5, 1}, {4, 2}};

static void dfs(string state, unordered_map<string, int> &visited, int zeroPos, int moves)
{
    if (visited.count(state) && visited[state] <= moves)
        return;

    visited[state] = moves;

    for (int nextPos : directions[zeroPos])
    {
        swap(state[zeroPos], state[nextPos]);
        dfs(state, visited, nextPos, moves + 1);
        swap(state[zeroPos], state[nextPos]);
    }
}

static int _00773_SlidingPuzzle(vector<vector<int>> &board)
{
    string startState;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            startState += to_string(board[i][j]);
        }
    }

    unordered_map<string, int> visited;
    dfs(startState, visited, startState.find('0'), 0);

    return visited.count("123450") ? visited["123450"] : -1;
}
#pragma endregion

#pragma region BFS
static int _00773_SlidingPuzzle0(vector<vector<int>> &board)
{
    vector<vector<int>> directions = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
    string target = "123450";
    string startState;

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            startState += to_string(board[i][j]);
        }
    }

    unordered_set<string> visited;
    queue<string> queue;
    queue.push(startState);
    visited.insert(startState);
    int moves = 0;

    while (!queue.empty())
    {
        int size = queue.size();

        while (size-- > 0)
        {
            string currentState = queue.front();
            queue.pop();

            if (currentState == target)
                return moves;

            int zeroPos = currentState.find('0');

            for (int newPos : directions[zeroPos])
            {
                string nextState = currentState;
                swap(nextState[zeroPos], nextState[newPos]);

                if (visited.count(nextState))
                    continue;

                visited.insert(nextState);
                queue.push(nextState);
            }
        }

        moves++;
    }

    return -1;
}
#pragma endregion

#pragma region GTest
static int is_00773_SlidingPuzzle_RunTest()
{
    stringstream ss;
    ss << "*_00773_SlidingPuzzle.expected*"
       << ":"
       << "*_00773_SlidingPuzzle0.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_00773_SlidingPuzzle, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _00773_SlidingPuzzle(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_00773_SlidingPuzzle0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _00773_SlidingPuzzle0(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
