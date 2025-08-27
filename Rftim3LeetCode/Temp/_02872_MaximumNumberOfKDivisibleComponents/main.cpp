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
static int _02872_MaximumNumberOfKDivisibleComponents(int n, vector<vector<int>> &edges, vector<int> &values, int k);
// BFS
static int _02872_MaximumNumberOfKDivisibleComponents0(int n, vector<vector<int>> &edges, vector<int> &values, int k);
// Speed
static int _02872_MaximumNumberOfKDivisibleComponents1(int n, vector<vector<int>> &edges, vector<int> &values, int k);
// Topological Sort / Onion Sort
static int _02872_MaximumNumberOfKDivisibleComponents2(int n, vector<vector<int>> &edges, vector<int> &values, int k);

static int is_02872_MaximumNumberOfKDivisibleComponents_RunTest();

/**
 * There is an undirected tree with n nodes labeled from 0 to n - 1.
 * You are given the integer n and a 2D integer array edges of length n - 1,
 * where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.
 * You are also given a 0-indexed integer array values of length n, where values[i] is the value
 * associated with the ith node, and an integer k.
 * A valid split of the tree is obtained by removing any set of edges, possibly empty,
 * from the tree such that the resulting components all have values that are divisible by k,
 * where the value of a connected component is the sum of the values of its nodes.
 * Return the maximum number of components in any valid split.
 *
 * Constraints:
 *
 * 1 <= n <= 3 * 10^4
 * edges.length == n - 1
 * edges[i].length == 2
 * 0 <= ai, bi < n
 * values.length == n
 * 0 <= values[i] <= 10^9
 * 1 <= k <= 10^9
 * Sum of values is divisible by k.
 * The input is generated such that edges represents a valid tree.
 */
int main()
{
    system("clear");
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_02872_MaximumNumberOfKDivisibleComponents_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<int> v, v2, v3;
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

        string s1;
        getline(cin, s1);
        stringstream ss(s1);
        string t;
        vector<int> d = {};
        while (getline(ss, t, ','))
        {
            d.push_back(stoi(t));
        }
        v1.push_back(d);

        cin >> s;
        v2.push_back(s);

        cin >> s;
        cin.get();
        v3.push_back(s);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        cout << _02872_MaximumNumberOfKDivisibleComponents(v[i], v0[i], v1[i], v2[i]) << "\n";
        cout << _02872_MaximumNumberOfKDivisibleComponents0(v[i], v0[i], v1[i], v2[i]) << "\n";
        cout << _02872_MaximumNumberOfKDivisibleComponents1(v[i], v0[i], v1[i], v2[i]) << "\n";
        cout << _02872_MaximumNumberOfKDivisibleComponents2(v[i], v0[i], v1[i], v2[i]) << "\n";
    }
}

#pragma region DFS
static int dfs(int currentNode, int parentNode, vector<int> adjList[], vector<int> &nodeValues, int k, int &componentCount)
{
    int sum = 0;

    for (auto neighborNode : adjList[currentNode])
    {
        if (neighborNode != parentNode)
        {
            sum += dfs(neighborNode, currentNode, adjList, nodeValues, k, componentCount);
            sum %= k;
        }
    }

    sum += nodeValues[currentNode];
    sum %= k;

    if (sum == 0)
        componentCount++;

    return sum;
}

static int _02872_MaximumNumberOfKDivisibleComponents(int n, vector<vector<int>> &edges, vector<int> &values, int k)
{
    vector<int> adjList[n];

    for (auto edge : edges)
    {
        int node1 = edge[0];
        int node2 = edge[1];
        adjList[node1].push_back(node2);
        adjList[node2].push_back(node1);
    }

    int componentCount = 0;
    dfs(0, -1, adjList, values, k, componentCount);

    return componentCount;
}
#pragma endregion

#pragma region BFS
static int _02872_MaximumNumberOfKDivisibleComponents0(int n, vector<vector<int>> &edges, vector<int> &values, int k)
{
    if (n < 2)
        return 1;

    int componentCount = 0;
    unordered_map<int, unordered_set<int>> graph;

    for (const auto &edge : edges)
    {
        int node1 = edge[0], node2 = edge[1];
        graph[node1].insert(node2);
        graph[node2].insert(node1);
    }

    vector<long long> longValues(values.begin(), values.end());
    queue<int> queue;

    for (const auto &[node, neighbors] : graph)
    {
        if (neighbors.size() == 1)
            queue.push(node);
    }

    while (!queue.empty())
    {
        int currentNode = queue.front();
        queue.pop();
        int neighborNode = -1;

        if (!graph[currentNode].empty())
            neighborNode = *graph[currentNode].begin();

        if (neighborNode >= 0)
        {
            graph[neighborNode].erase(currentNode);
            graph[currentNode].erase(neighborNode);
        }

        if (longValues[currentNode] % k == 0)
            componentCount++;
        else if (neighborNode >= 0)
            longValues[neighborNode] += longValues[currentNode];

        if (neighborNode >= 0 && graph[neighborNode].size() == 1)
            queue.push(neighborNode);
    }

    return componentCount;
}
#pragma endregion

#pragma region Speed
typedef long long int ll;
const int N = 3e4 + 5;

vector<vector<int>> g(N);
vector<ll> val(N);
int result;
int K;

static int MaxComponents(int src, int par)
{
    ll leftOver = val[src];

    for (auto i : g[src])
    {
        if (i == par)
            continue;
        leftOver += MaxComponents(i, src);
    }

    if (leftOver % K == 0)
    {
        result++;
        leftOver = 0;
    }

    return leftOver;
}

static int _02872_MaximumNumberOfKDivisibleComponents1(int n, vector<vector<int>> &edges, vector<int> &values, int k)
{
    result = 0;
    K = k;

    for (int j = 0; j < n; j++)
    {
        g[j].clear();
        val[j] = values[j];
    }

    for (auto e : edges)
    {
        g[e[0]].push_back(e[1]);
        g[e[1]].push_back(e[0]);
    }

    ll leftOver = MaxComponents(0, -1);

    if (leftOver != 0)
        result++;

    return result;
}
#pragma endregion

#pragma region Topological Sort / Onion Sort
static int _02872_MaximumNumberOfKDivisibleComponents2(int n, vector<vector<int>> &edges, vector<int> &values, int k)
{
    if (n < 2)
        return 1;

    int componentCount = 0;
    vector<vector<int>> graph(n);
    vector<int> inDegree(n, 0);

    for (const auto &edge : edges)
    {
        int node1 = edge[0], node2 = edge[1];
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
        inDegree[node1]++;
        inDegree[node2]++;
    }

    vector<long long> longValues(values.begin(), values.end());
    queue<int> queue;

    for (int node = 0; node < n; node++)
    {
        if (inDegree[node] == 1)
            queue.push(node);
    }

    while (!queue.empty())
    {
        int currentNode = queue.front();
        queue.pop();
        inDegree[currentNode]--;
        long long addValue = 0;

        if (longValues[currentNode] % k == 0)
            componentCount++;
        else
            addValue = longValues[currentNode];

        for (int neighborNode : graph[currentNode])
        {
            if (inDegree[neighborNode] == 0)
                continue;

            inDegree[neighborNode]--;
            longValues[neighborNode] += addValue;

            if (inDegree[neighborNode] == 1)
                queue.push(neighborNode);
        }
    }

    return componentCount;
}
#pragma endregion

#pragma region GTest
static int is_02872_MaximumNumberOfKDivisibleComponents_RunTest()
{
    stringstream ss;
    ss << "*_02872_MaximumNumberOfKDivisibleComponents.expected*"
       << ":"
       << "*_02872_MaximumNumberOfKDivisibleComponents0.expected*"
       << ":"
       << "*_02872_MaximumNumberOfKDivisibleComponents1.expected*"
       << ":"
       << "*_02872_MaximumNumberOfKDivisibleComponents2.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_02872_MaximumNumberOfKDivisibleComponents, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v3[i];

        // Actual
        int actual = _02872_MaximumNumberOfKDivisibleComponents(v[i], v0[i], v1[i], v2[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02872_MaximumNumberOfKDivisibleComponents0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v3[i];

        // Actual
        int actual = _02872_MaximumNumberOfKDivisibleComponents0(v[i], v0[i], v1[i], v2[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02872_MaximumNumberOfKDivisibleComponents1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v3[i];

        // Actual
        int actual = _02872_MaximumNumberOfKDivisibleComponents1(v[i], v0[i], v1[i], v2[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02872_MaximumNumberOfKDivisibleComponents2, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v3[i];

        // Actual
        int actual = _02872_MaximumNumberOfKDivisibleComponents2(v[i], v0[i], v1[i], v2[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
