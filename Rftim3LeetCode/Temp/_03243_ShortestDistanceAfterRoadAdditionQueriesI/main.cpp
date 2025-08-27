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
static vector<int> _03243_ShortestDistanceAfterRoadAdditionQueriesI(int n, vector<vector<int>> &queries);
// Recursive DP (TD)
static vector<int> _03243_ShortestDistanceAfterRoadAdditionQueriesI0(int n, vector<vector<int>> &queries);
// Speed
static vector<int> _03243_ShortestDistanceAfterRoadAdditionQueriesI1(int n, vector<vector<int>> &queries);

static int is_03243_ShortestDistanceAfterRoadAdditionQueriesI_RunTest();

/**
 * You are given an integer n and a 2D integer array queries.
 * There are n cities numbered from 0 to n - 1. Initially, there is a unidirectional road from city i
 * to city i + 1 for all 0 <= i < n - 1.
 * queries[i] = [ui, vi] represents the addition of a new unidirectional road from city ui to city vi.
 * After each query, you need to find the length of the shortest path from city 0 to city n - 1.
 * Return an array answer where for each i in the range [0, queries.length - 1],
 * answer[i] is the length of the shortest path from city 0 to city n - 1 after processing
 * the first i + 1 queries.
 *
 * Constraints:
 *
 * 3 <= n <= 500
 * 1 <= queries.length <= 500
 * queries[i].length == 2
 * 0 <= queries[i][0] < queries[i][1] < n
 * 1 < queries[i][1] - queries[i][0]
 * There are no repeated roads among the queries.
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_03243_ShortestDistanceAfterRoadAdditionQueriesI_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<int> v;
static vector<vector<vector<int>>> v0;
static vector<vector<int>> v1;

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

        s0 = "";
        getline(cin, s0);
        stringstream ss(s0);
        string t;
        vector<int> d = {};
        while (getline(ss, t, ','))
        {
            d.push_back(stoi(t));
        }
        v1.push_back(d);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        vector<int> res = _03243_ShortestDistanceAfterRoadAdditionQueriesI(v[i], v0[i]);
        for (auto &&j : res)
        {
            cout << j << " ";
        }
        cout << "\n";

        vector<int> res0 = _03243_ShortestDistanceAfterRoadAdditionQueriesI0(v[i], v0[i]);
        for (auto &&j : res0)
        {
            cout << j << " ";
        }
        cout << "\n";

        vector<int> res1 = _03243_ShortestDistanceAfterRoadAdditionQueriesI1(v[i], v0[i]);
        for (auto &&j : res1)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
}

#pragma region BFS
static int bfs(int n, vector<vector<int>> &adjList)
{
    vector<bool> visited(n, false);
    queue<int> nodeQueue;
    nodeQueue.push(0);
    visited[0] = true;
    int currentLayerNodeCount = 1;
    int nextLayerNodeCount = 0;
    int layersExplored = 0;

    while (!nodeQueue.empty())
    {
        for (int i = 0; i < currentLayerNodeCount; ++i)
        {
            int currentNode = nodeQueue.front();
            nodeQueue.pop();

            if (currentNode == n - 1)
                return layersExplored;

            for (auto neighbor : adjList[currentNode])
            {
                if (visited[neighbor])
                    continue;

                nodeQueue.push(neighbor);
                nextLayerNodeCount++;
                visited[neighbor] = true;
            }
        }

        currentLayerNodeCount = nextLayerNodeCount;
        nextLayerNodeCount = 0;
        layersExplored++;
    }

    return -1;
}

static vector<int> _03243_ShortestDistanceAfterRoadAdditionQueriesI(int n, vector<vector<int>> &queries)
{
    vector<int> answer;
    vector<vector<int>> adjList(n, vector<int>(0));

    for (int i = 0; i < n - 1; i++)
    {
        adjList[i].push_back(i + 1);
    }

    for (auto &road : queries)
    {
        int u = road[0];
        int v = road[1];
        adjList[u].push_back(v);
        answer.push_back(bfs(n, adjList));
    }

    return answer;
}
#pragma endregion

#pragma region Recursive DP (TD)
static int findMinDistance(vector<vector<int>> &adjList, int n, int currentNode, vector<int> &dp)
{
    if (currentNode == n - 1)
        return 0;

    if (dp[currentNode] != -1)
        return dp[currentNode];

    int minDistance = n;

    for (int neighbor : adjList[currentNode])
    {
        minDistance = min(minDistance, findMinDistance(adjList, n, neighbor, dp) + 1);
    }

    return dp[currentNode] = minDistance;
}

static vector<int> _03243_ShortestDistanceAfterRoadAdditionQueriesI0(int n, vector<vector<int>> &queries)
{
    vector<int> dp(n, -1);
    vector<vector<int>> adjList(n, vector<int>(0));

    for (int i = 0; i < n - 1; i++)
    {
        adjList[i].push_back(i + 1);
    }

    vector<int> answer;

    for (auto &road : queries)
    {
        int u = road[0];
        int v = road[1];
        adjList[u].push_back(v);
        answer.push_back(findMinDistance(adjList, n, 0, dp));
        dp.clear();
        dp.resize(n, -1);
    }

    return answer;
}
#pragma endregion

#pragma region Speed
static void dfs(vector<vector<int>> &tree, int c, vector<int> &dp)
{
    int d = dp[c] + 1;
    
    for (int x : tree[c])
    {
        if (dp[x] <= d)
            continue;
    
        dp[x] = d;
        dfs(tree, x, dp);
    }
}

static vector<int> _03243_ShortestDistanceAfterRoadAdditionQueriesI1(int n, vector<vector<int>> &queries)
{
    vector<int> dp(n);
    
    for (int i = 0; i < n; ++i)
        dp[i] = n - 1 - i;
    
    vector<vector<int>> tree(n);
    
    for (int i = 0; i + 1 < n; ++i)
        tree[i + 1].push_back(i);
    
    int m = int(queries.size());
    vector<int> res(m);
    int i = 0;
    
    for (auto &q : queries)
    {
        int a = q[0], b = q[1];
        tree[b].push_back(a);
        dp[a] = min(dp[a], dp[b] + 1);
        dfs(tree, a, dp);
        res[i] = dp[0];
        ++i;
    }
    
    return res;
}
#pragma endregion

#pragma region GTest
static int is_03243_ShortestDistanceAfterRoadAdditionQueriesI_RunTest()
{
    stringstream ss;
    ss << "*_03243_ShortestDistanceAfterRoadAdditionQueriesI.expected*"
       << ":"
       << "*_03243_ShortestDistanceAfterRoadAdditionQueriesI0.expected*"
       << ":"
       << "*_03243_ShortestDistanceAfterRoadAdditionQueriesI1.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_03243_ShortestDistanceAfterRoadAdditionQueriesI, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<int> expected = v1[i];

        // Actual
        vector<int> actual = _03243_ShortestDistanceAfterRoadAdditionQueriesI(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_03243_ShortestDistanceAfterRoadAdditionQueriesI0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<int> expected = v1[i];

        // Actual
        vector<int> actual = _03243_ShortestDistanceAfterRoadAdditionQueriesI0(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_03243_ShortestDistanceAfterRoadAdditionQueriesI1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<int> expected = v1[i];

        // Actual
        vector<int> actual = _03243_ShortestDistanceAfterRoadAdditionQueriesI1(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
