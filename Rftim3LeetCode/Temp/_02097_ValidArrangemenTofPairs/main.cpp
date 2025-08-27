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

// Eulerian Path
static vector<vector<int>> _02097_ValidArrangemenTofPairs(vector<vector<int>> &pairs);
// Hierholzer's Algorithm
static vector<vector<int>> _02097_ValidArrangemenTofPairs0(vector<vector<int>> &pairs);
// Speed
static vector<vector<int>> _02097_ValidArrangemenTofPairs1(vector<vector<int>> &pairs);

static int is_02097_ValidArrangemenTofPairs_RunTest();

/**
 * You are given a 0-indexed 2D integer array pairs where pairs[i] = [starti, endi].
 * An arrangement of pairs is valid if for every index i where 1 <= i < pairs.length,
 * we have endi-1 == starti.
 * Return any valid arrangement of pairs.
 * Note: The inputs will be generated such that there exists a valid arrangement of pairs.
 *
 * Constraints:
 *
 * 1 <= pairs.length <= 10^5
 * pairs[i].length == 2
 * 0 <= starti, endi <= 10^9
 * starti != endi
 * No two pairs are exactly the same.
 * There exists a valid arrangement of pairs.
 */
int main()
{
    offline();
    dataCollector();

    solve();
    return 0;

    ::testing::InitGoogleTest();
    is_02097_ValidArrangemenTofPairs_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<vector<vector<int>>> v, v0;

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
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        vector<vector<int>> res = _02097_ValidArrangemenTofPairs(v[i]);
        for (auto &&j : res)
        {
            for (auto &&k : j)
            {
                cout << k << " ";
            }
            cout << "\n";
        }

        vector<vector<int>> res0 = _02097_ValidArrangemenTofPairs0(v[i]);
        for (auto &&j : res0)
        {
            for (auto &&k : j)
            {
                cout << k << " ";
            }
            cout << "\n";
        }

        vector<vector<int>> res1 = _02097_ValidArrangemenTofPairs1(v[i]);
        for (auto &&j : res1)
        {
            for (auto &&k : j)
            {
                cout << k << " ";
            }
            cout << "\n";
        }
    }
}

static vector<vector<int>> _02097_ValidArrangemenTofPairs(vector<vector<int>> &pairs)
{
    unordered_map<int, deque<int>> adjacencyMatrix;
    unordered_map<int, int> inDegree, outDegree;

    for (const auto &pair : pairs)
    {
        int start = pair[0], end = pair[1];
        adjacencyMatrix[start].push_back(end);
        outDegree[start]++;
        inDegree[end]++;
    }

    vector<int> result;

    function<void(int)> visit = [&](int node)
    {
        while (!adjacencyMatrix[node].empty())
        {
            int nextNode = adjacencyMatrix[node].front();
            adjacencyMatrix[node].pop_front();
            visit(nextNode);
        }

        result.push_back(node);
    };

    int startNode = -1;

    for (const auto &entry : outDegree)
    {
        int node = entry.first;

        if (outDegree[node] == inDegree[node] + 1)
        {
            startNode = node;
            break;
        }
    }

    if (startNode == -1)
        startNode = pairs[0][0];

    visit(startNode);

    reverse(result.begin(), result.end());
    vector<vector<int>> pairedResult;

    for (int i = 1; i < result.size(); ++i)
    {
        pairedResult.push_back({result[i - 1], result[i]});
    }

    return pairedResult;
}

static vector<vector<int>> _02097_ValidArrangemenTofPairs0(vector<vector<int>> &pairs)
{
    unordered_map<int, deque<int>> adjacencyMatrix;
    unordered_map<int, int> inDegree, outDegree;

    for (const auto &pair : pairs)
    {
        int start = pair[0], end = pair[1];
        adjacencyMatrix[start].push_back(end);
        outDegree[start]++;
        inDegree[end]++;
    }

    vector<int> result;
    int startNode = -1;

    for (const auto &entry : outDegree)
    {
        int node = entry.first;

        if (outDegree[node] == inDegree[node] + 1)
        {
            startNode = node;
            break;
        }
    }

    if (startNode == -1)
        startNode = pairs[0][0];

    stack<int> nodeStack;
    nodeStack.push(startNode);

    while (!nodeStack.empty())
    {
        int node = nodeStack.top();

        if (!adjacencyMatrix[node].empty())
        {
            int nextNode = adjacencyMatrix[node].front();
            adjacencyMatrix[node].pop_front();
            nodeStack.push(nextNode);
        }
        else
        {
            result.push_back(node);
            nodeStack.pop();
        }
    }

    reverse(result.begin(), result.end());
    vector<vector<int>> pairedResult;

    for (int i = 1; i < result.size(); ++i)
    {
        pairedResult.push_back({result[i - 1], result[i]});
    }

    return pairedResult;
}

static vector<vector<int>> _02097_ValidArrangemenTofPairs1(vector<vector<int>> &pairs)
{
    unordered_map<int, vector<int>> adjacencyList;
    unordered_map<int, int> inOutDegree;

    for (const auto &pair : pairs)
    {
        adjacencyList[pair[0]].push_back(pair[1]);
        inOutDegree[pair[0]]++;
        inOutDegree[pair[1]]--;
    }

    int startNode = pairs[0][0];

    for (const auto &[node, degree] : inOutDegree)
    {
        if (degree == 1)
        {
            startNode = node;
            break;
        }
    }

    vector<int> path;
    stack<int> nodeStack;
    nodeStack.push(startNode);

    while (!nodeStack.empty())
    {
        auto &neighbors = adjacencyList[nodeStack.top()];
        if (neighbors.empty())
        {
            path.push_back(nodeStack.top());
            nodeStack.pop();
        }
        else
        {
            int nextNode = neighbors.back();
            nodeStack.push(nextNode);
            neighbors.pop_back();
        }
    }

    vector<vector<int>> arrangement;
    int pathSize = path.size();
    arrangement.reserve(pathSize - 1);

    for (int i = pathSize - 1; i > 0; --i)
    {
        arrangement.push_back({path[i], path[i - 1]});
    }

    return arrangement;
}

#pragma region GTest
static int is_02097_ValidArrangemenTofPairs_RunTest()
{
    stringstream ss;
    ss << "*_02097_ValidArrangemenTofPairs.expected*"
       << ":"
       << "*_02097_ValidArrangemenTofPairs0.expected*"
       << ":"
       << "*_02097_ValidArrangemenTofPairs1.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_02097_ValidArrangemenTofPairs, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<vector<int>> expected = v0[i];

        // Actual
        vector<vector<int>> actual = _02097_ValidArrangemenTofPairs(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02097_ValidArrangemenTofPairs0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<vector<int>> expected = v0[i];

        // Actual
        vector<vector<int>> actual = _02097_ValidArrangemenTofPairs0(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02097_ValidArrangemenTofPairs1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<vector<int>> expected = v0[i];

        // Actual
        vector<vector<int>> actual = _02097_ValidArrangemenTofPairs1(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
