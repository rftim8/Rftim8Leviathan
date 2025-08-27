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
static int _03203_FindMinimumDiameterAfterMergingTwoTrees(vector<vector<int>> &edges1, vector<vector<int>> &edges2);
// DFS
static int _03203_FindMinimumDiameterAfterMergingTwoTrees0(vector<vector<int>> &edges1, vector<vector<int>> &edges2);
// Speed
static int _03203_FindMinimumDiameterAfterMergingTwoTrees1(vector<vector<int>> &edges1, vector<vector<int>> &edges2);

static int is_03203_FindMinimumDiameterAfterMergingTwoTrees_RunTest();

/**
 * There exist two undirected trees with n and m nodes, numbered from 0 to n - 1 and from 0 to m - 1, respectively.
 * You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m - 1, respectively,
 * where edges1[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the first tree and
 * edges2[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the second tree.
 * You must connect one node from the first tree with another node from the second tree with an edge.
 * Return the minimum possible diameter of the resulting tree.
 * The diameter of a tree is the length of the longest path between any two nodes in the tree.
 *
 * Constraints:
 *
 * 1 <= n, m <= 10^5
 * edges1.length == n - 1
 * edges2.length == m - 1
 * edges1[i].length == edges2[i].length == 2
 * edges1[i] = [ai, bi]
 * 0 <= ai, bi < n
 * edges2[i] = [ui, vi]
 * 0 <= ui, vi < m
 * The input is generated such that edges1 and edges2 represent valid trees.
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_03203_FindMinimumDiameterAfterMergingTwoTrees_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<vector<vector<int>>> v, v0;
static vector<int> v1;

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

        s = "";
        getline(cin, s);
        v0.push_back(stringTo2DVectorInt(s));

        int s0;
        cin >> s0;
        cin.get();
        v1.push_back(s0);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        cout << _03203_FindMinimumDiameterAfterMergingTwoTrees(v[i], v0[i]) << "\n";
        cout << _03203_FindMinimumDiameterAfterMergingTwoTrees0(v[i], v0[i]) << "\n";
        cout << _03203_FindMinimumDiameterAfterMergingTwoTrees1(v[i], v0[i]) << "\n";
    }
}

#pragma region BFS
static vector<vector<int>> buildAdjList(int size, vector<vector<int>> &edges)
{
    vector<vector<int>> adjList(size);

    for (auto edge : edges)
    {
        adjList[edge[0]].push_back(edge[1]);
        adjList[edge[1]].push_back(edge[0]);
    }

    return adjList;
}

static pair<int, int> findFarthestNode(int n, vector<vector<int>> &adjList, int sourceNode)
{
    queue<int> nodesQueue;
    vector<bool> visited(n, false);
    nodesQueue.push(sourceNode);
    visited[sourceNode] = true;
    int maximumDistance = 0, farthestNode = sourceNode;

    while (!nodesQueue.empty())
    {
        int size = nodesQueue.size();

        for (int i = 0; i < size; ++i)
        {
            int currentNode = nodesQueue.front();
            nodesQueue.pop();
            farthestNode = currentNode;

            for (int neighbor : adjList[currentNode])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    nodesQueue.push(neighbor);
                }
            }
        }

        if (!nodesQueue.empty())
            maximumDistance++;
    }

    return {farthestNode, maximumDistance};
}

static int findDiameter(int n, vector<vector<int>> &adjList)
{
    auto [farthestNode, _] = findFarthestNode(n, adjList, 0);
    auto [__, diameter] = findFarthestNode(n, adjList, farthestNode);

    return diameter;
}

static int _03203_FindMinimumDiameterAfterMergingTwoTrees(vector<vector<int>> &edges1, vector<vector<int>> &edges2)
{
    int n = edges1.size() + 1;
    int m = edges2.size() + 1;
    vector<vector<int>> adjList1 = buildAdjList(n, edges1);
    vector<vector<int>> adjList2 = buildAdjList(m, edges2);
    int diameter1 = findDiameter(n, adjList1);
    int diameter2 = findDiameter(m, adjList2);
    int combinedDiameter = ceil(diameter1 / 2.0) + ceil(diameter2 / 2.0) + 1;

    return max({diameter1, diameter2, combinedDiameter});
}
#pragma endregion

#pragma region DFS
static vector<vector<int>> buildAdjList0(int size, vector<vector<int>> &edges)
{
    vector<vector<int>> adjList(size);

    for (auto &edge : edges)
    {
        adjList[edge[0]].push_back(edge[1]);
        adjList[edge[1]].push_back(edge[0]);
    }

    return adjList;
};

static pair<int, int> findDiameter(vector<vector<int>> &adjList, int node, int parent)
{
    int maxDepth1 = 0, maxDepth2 = 0;
    int diameter = 0;

    for (int neighbor : adjList[node])
    {
        if (neighbor == parent)
            continue;

        auto [childDiameter, depth] = findDiameter(adjList, neighbor, node);
        diameter = max(diameter, childDiameter);
        depth++;

        if (depth > maxDepth1)
        {
            maxDepth2 = maxDepth1;
            maxDepth1 = depth;
        }
        else if (depth > maxDepth2)
            maxDepth2 = depth;
    }

    diameter = max(diameter, maxDepth1 + maxDepth2);

    return {diameter, maxDepth1};
}

static int _03203_FindMinimumDiameterAfterMergingTwoTrees0(vector<vector<int>> &edges1, vector<vector<int>> &edges2)
{
    int n = edges1.size() + 1;
    int m = edges2.size() + 1;
    vector<vector<int>> adjList1 = buildAdjList0(n, edges1);
    vector<vector<int>> adjList2 = buildAdjList0(m, edges2);
    int diameter1 = findDiameter(adjList1, 0, -1).first;
    int diameter2 = findDiameter(adjList2, 0, -1).first;
    int combinedDiameter = ceil(diameter1 / 2.0) + ceil(diameter2 / 2.0) + 1;

    return max({diameter1, diameter2, combinedDiameter});
}
#pragma endregion

#pragma region Speed
static int diameter(int root, int parent, vector<vector<int>> &graph, int &ans)
{
    int mx1 = -1, mx2 = -1;

    for (auto &child : graph[root])
    {
        if (child != parent)
        {
            int m = diameter(child, root, graph, ans);

            if (m >= mx1)
            {
                mx2 = mx1;
                mx1 = m;
            }
            else if (m > mx2)
                mx2 = m;
        }
    }

    if (mx2 != -1)
        ans = max(ans, 2 + mx1 + mx2);

    if (mx1 != -1)
        ans = max(ans, 1 + mx1);

    if (mx1 != -1)
        return 1 + mx1;

    return 0;
}

static int _03203_FindMinimumDiameterAfterMergingTwoTrees1(vector<vector<int>> &edges1, vector<vector<int>> &edges2)
{
    int m = edges1.size() + 1;
    int n = edges2.size() + 1;

    vector<vector<int>> graph1(m), graph2(n);

    for (auto &edge : edges1)
    {
        graph1[edge[0]].push_back(edge[1]);
        graph1[edge[1]].push_back(edge[0]);
    }
    for (auto &edge : edges2)
    {
        graph2[edge[0]].push_back(edge[1]);
        graph2[edge[1]].push_back(edge[0]);
    }

    int dia1 = 0, dia2 = 0;
    diameter(0, -1, graph1, dia1);
    diameter(0, -1, graph2, dia2);
    // cout << dia1 << " " << dia2 << endl;

    int ans = max({dia1, dia2, (dia1 / 2) + (dia1 % 2) + (dia2 / 2) + (dia2 % 2) + 1});

    return ans;
}
#pragma endregion

#pragma region GTest
static int is_03203_FindMinimumDiameterAfterMergingTwoTrees_RunTest()
{
    stringstream ss;
    ss << "*_03203_FindMinimumDiameterAfterMergingTwoTrees.expected*"
       << ":"
       << "*_03203_FindMinimumDiameterAfterMergingTwoTrees0.expected*"
       << ":"
       << "*_03203_FindMinimumDiameterAfterMergingTwoTrees1.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_03203_FindMinimumDiameterAfterMergingTwoTrees, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v1[i];

        // Actual
        int actual = _03203_FindMinimumDiameterAfterMergingTwoTrees(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_03203_FindMinimumDiameterAfterMergingTwoTrees0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v1[i];

        // Actual
        int actual = _03203_FindMinimumDiameterAfterMergingTwoTrees0(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_03203_FindMinimumDiameterAfterMergingTwoTrees1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v1[i];

        // Actual
        int actual = _03203_FindMinimumDiameterAfterMergingTwoTrees1(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
