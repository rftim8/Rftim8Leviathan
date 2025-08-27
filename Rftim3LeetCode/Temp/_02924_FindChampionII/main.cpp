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

// In-Degree Count
static int _02924_FindChampionII(int n, vector<vector<int>> &edges);
// Speed
static int _02924_FindChampionII0(int n, vector<vector<int>> &edges);

static int is_02924_FindChampionII_RunTest();

/**
 * There are n teams numbered from 0 to n - 1 in a tournament; each team is also a node in a DAG.
 * You are given the integer n and a 0-indexed 2D integer array edges of length m representing the DAG,
 * where edges[i] = [ui, vi] indicates that there is a directed edge from team ui to team vi in the graph.
 * A directed edge from a to b in the graph means that team a is stronger than team b and team b
 * is weaker than team a.
 * Team a will be the champion of the tournament if there is no team b that is stronger than team a.
 * Return the team that will be the champion of the tournament if there is a unique champion, otherwise,
 * return -1.
 *
 * Notes
 *
 * A cycle is a series of nodes a1, a2, ..., an, an+1 such that node a1 is the same node as node an+1,
 * the nodes a1, a2, ..., an are distinct, and there is a directed edge from the node ai to node ai+1
 * for every i in the range [1, n].
 * A DAG is a directed graph that does not have any cycle.
 *
 * Constraints:
 *
 * 1 <= n <= 100
 * m == edges.length
 * 0 <= m <= n * (n - 1) / 2
 * edges[i].length == 2
 * 0 <= edge[i][j] <= n - 1
 * edges[i][0] != edges[i][1]
 * The input is generated such that if team a is stronger than team b, team b is not stronger than team a.
 * The input is generated such that if team a is stronger than team b and team b is stronger than team c,
 * then team a is stronger than team c.
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_02924_FindChampionII_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<int> v, v1;
static vector<vector<vector<int>>> v0;

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
        cin.get();
        v.push_back(s);

        string s0;
        getline(cin, s0);
        v0.push_back(stringTo2DVectorInt(s0));

        cin >> s;
        cin.get();
        v1.push_back(s);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        cout << _02924_FindChampionII(v[i], v0[i]) << "\n";
        cout << _02924_FindChampionII0(v[i], v0[i]) << "\n";
    }
}

static int _02924_FindChampionII(int n, vector<vector<int>> &edges)
{
    vector<int> indegree(n, 0);

    for (auto edge : edges)
    {
        indegree[edge[1]]++;
    }

    int champ = -1, champCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            champCount++;
            champ = i;
        }
    }

    return champCount > 1 ? -1 : champ;
}

static int _02924_FindChampionII0(int n, vector<vector<int>> &edges)
{
    vector<int> indegree(n, 0);

    for (const vector<int> &edge : edges)
    {
        indegree[edge[1]]++;
    }

    int champion = -1;

    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            if (champion != -1)
                return -1;

            champion = i;
        }
    }

    return champion;
}

#pragma region GTest
static int is_02924_FindChampionII_RunTest()
{
    stringstream ss;
    ss << "*_02924_FindChampionII.expected*"
       << ":"
       << "*_02924_FindChampionII0.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_02924_FindChampionII, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v1[i];

        // Actual
        int actual = _02924_FindChampionII(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02924_FindChampionII0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v1[i];

        // Actual
        int actual = _02924_FindChampionII0(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
