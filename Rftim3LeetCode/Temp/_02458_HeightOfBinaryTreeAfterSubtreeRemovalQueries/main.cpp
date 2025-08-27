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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BinaryTree
{
    TreeNode *root;

public:
    TreeNode *createTree(vector<int> &v);

    void printTreeLevelOrder(TreeNode *root);

    BinaryTree() : root(nullptr) {}
};

TreeNode *BinaryTree::createTree(vector<int> &v)
{
    if (v.size() == 0)
        return new TreeNode();

    queue<TreeNode *> q = {};
    TreeNode *root = new TreeNode(v[0]);
    q.push(root);

    for (int i = 1; i < v.size(); i += 2)
    {
        TreeNode *node = q.front();
        q.pop();

        if (v[i] != -1)
        {
            node->left = new TreeNode(v[i]);
            q.push(node->left);
        }

        if (i + 1 < v.size() && v[i + 1] != -1)
        {
            node->right = new TreeNode(v[i + 1]);
            q.push(node->right);
        }
    }

    return root;
}

void BinaryTree::printTreeLevelOrder(TreeNode *root)
{
    if (root)
    {
        queue<TreeNode *> q = {};
        q.push(root);

        vector<vector<int>> v = {};
        while (q.size())
        {
            int n = q.size();
            vector<int> v0 = {};

            while (n != 0)
            {
                TreeNode *node = q.front();
                q.pop();

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);

                v0.push_back(node->val);
                n--;
            }

            v.push_back(v0);
        }

        for (auto &&i : v)
        {
            for (auto &&j : i)
            {
                cout << j << " ";
            }
            cout << "\n";
        }
    }
}

static void dataCollector();

static void solve();

// Left and Right Traversal
static vector<int> _02458_HeightOfBinaryTreeAfterSubtreeRemovalQueries(TreeNode *root, vector<int> &queries);
// Single Traversal
static vector<int> _02458_HeightOfBinaryTreeAfterSubtreeRemovalQueries0(TreeNode *root, vector<int> &queries);
// Subtree Size
static vector<int> _02458_HeightOfBinaryTreeAfterSubtreeRemovalQueries1(TreeNode *root, vector<int> &queries);
// Eulerian Tour
static vector<int> _02458_HeightOfBinaryTreeAfterSubtreeRemovalQueries2(TreeNode *root, vector<int> &queries);
// Two Largest Cousins
static vector<int> _02458_HeightOfBinaryTreeAfterSubtreeRemovalQueries3(TreeNode *root, vector<int> &queries);

static int is_02458_HeightOfBinaryTreeAfterSubtreeRemovalQueries_RunTest();

/**
 * You are given the root of a binary tree with n nodes.
 * Each node is assigned a unique value from 1 to n.
 * You are also given an array queries of size m.
 * You have to perform m independent queries on the tree where in the ith query you do the following:
 * Remove the subtree rooted at the node with the value queries[i] from the tree.
 * It is guaranteed that queries[i] will not be equal to the value of the root.
 * Return an array answer of size m where answer[i] is the height of the tree after performing
 * the ith query.
 *
 * Note:
 *
 * The queries are independent, so the tree returns to its initial state after each query.
 * The height of a tree is the number of edges in the longest simple path from the root to some node
 * in the tree.
 *
 * Constraints:
 *
 * The number of nodes in the tree is n.
 * 2 <= n <= 10^5
 * 1 <= Node.val <= n
 * All the values in the tree are unique.
 * m == queries.length
 * 1 <= m <= min(n, 10^4)
 * 1 <= queries[i] <= n
 * queries[i] != root.val
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_02458_HeightOfBinaryTreeAfterSubtreeRemovalQueries_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<vector<int>> v, v0, v1;

static void dataCollector()
{
    cin >> n;
    cin >> m;
    cin.get();

    for (int i = 0; i < n * m; i += m)
    {
        string s;
        getline(cin, s);
        stringstream ss(s);
        string t;
        vector<int> d = {};
        while (getline(ss, t, ','))
        {
            d.push_back(t == "null" ? -1 : stoi(t));
        }
        v.push_back(d);

        s = "";
        getline(cin, s);
        ss.clear();
        ss.str(s);
        t = "";
        d = {};
        while (getline(ss, t, ','))
        {
            d.push_back(stoi(t));
        }
        v0.push_back(d);

        s = "";
        getline(cin, s);
        ss.clear();
        ss.str(s);
        t = "";
        d = {};
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
        BinaryTree bt;
        TreeNode *head = bt.createTree(v[i]);
        vector<int> res = _02458_HeightOfBinaryTreeAfterSubtreeRemovalQueries(head, v0[i]);
        for (auto &&j : res)
        {
            cout << j << " ";
        }
        cout << "\n";

        BinaryTree bt0;
        TreeNode *head0 = bt0.createTree(v[i]);
        vector<int> res0 = _02458_HeightOfBinaryTreeAfterSubtreeRemovalQueries(head0, v0[i]);
        for (auto &&j : res0)
        {
            cout << j << " ";
        }
        cout << "\n";

        BinaryTree bt1;
        TreeNode *head1 = bt1.createTree(v[i]);
        vector<int> res1 = _02458_HeightOfBinaryTreeAfterSubtreeRemovalQueries(head1, v0[i]);
        for (auto &&j : res1)
        {
            cout << j << " ";
        }
        cout << "\n";

        BinaryTree bt2;
        TreeNode *head2 = bt2.createTree(v[i]);
        vector<int> res2 = _02458_HeightOfBinaryTreeAfterSubtreeRemovalQueries(head2, v0[i]);
        for (auto &&j : res2)
        {
            cout << j << " ";
        }
        cout << "\n";

        BinaryTree bt3;
        TreeNode *head3 = bt3.createTree(v[i]);
        vector<int> res3 = _02458_HeightOfBinaryTreeAfterSubtreeRemovalQueries(head3, v0[i]);
        for (auto &&j : res3)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
}

#pragma region Left and Right Traversal
static int maxHeightAfterRemoval[100001];
static int currentMaxHeight;

static void traverseLeftToRight(TreeNode *node, int currentHeight)
{
    if (node == nullptr)
        return;

    maxHeightAfterRemoval[node->val] = currentMaxHeight;
    currentMaxHeight = max(currentMaxHeight, currentHeight);
    traverseLeftToRight(node->left, currentHeight + 1);
    traverseLeftToRight(node->right, currentHeight + 1);
}

static void traverseRightToLeft(TreeNode *node, int currentHeight)
{
    if (node == nullptr)
        return;

    maxHeightAfterRemoval[node->val] = max(maxHeightAfterRemoval[node->val], currentMaxHeight);
    currentMaxHeight = max(currentHeight, currentMaxHeight);
    traverseRightToLeft(node->right, currentHeight + 1);
    traverseRightToLeft(node->left, currentHeight + 1);
}

static vector<int> _02458_HeightOfBinaryTreeAfterSubtreeRemovalQueries(TreeNode *root, vector<int> &queries)
{
    maxHeightAfterRemoval[100001] = {};
    currentMaxHeight = 0;
    traverseLeftToRight(root, 0);
    currentMaxHeight = 0;
    traverseRightToLeft(root, 0);
    int queryCount = queries.size();
    vector<int> queryResults(queryCount);

    for (int i = 0; i < queryCount; i++)
    {
        queryResults[i] = maxHeightAfterRemoval[queries[i]];
    }

    return queryResults;
}
#pragma endregion

#pragma region Single Traversal
static int height(TreeNode *node, unordered_map<TreeNode *, int> &heightCache)
{
    if (node == nullptr)
        return -1;

    if (heightCache.count(node))
        return heightCache[node];

    int h = 1 + max(height(node->left, heightCache), height(node->right, heightCache));
    heightCache[node] = h;

    return h;
}

static void dfs(TreeNode *node, int depth, int maxVal, unordered_map<int, int> &resultMap, unordered_map<TreeNode *, int> &heightCache)
{
    if (node == nullptr)
        return;

    resultMap[node->val] = maxVal;

    dfs(node->left, depth + 1, max(maxVal, depth + 1 + height(node->right, heightCache)), resultMap, heightCache);
    dfs(node->right, depth + 1, max(maxVal, depth + 1 + height(node->left, heightCache)), resultMap, heightCache);
}

static vector<int> _02458_HeightOfBinaryTreeAfterSubtreeRemovalQueries0(TreeNode *root, vector<int> &queries)
{
    unordered_map<int, int> resultMap;
    unordered_map<TreeNode *, int> heightCache;
    dfs(root, 0, 0, resultMap, heightCache);
    vector<int> result(queries.size());

    for (int i = 0; i < queries.size(); i++)
    {
        result[i] = resultMap[queries[i]];
    }

    return result;
}
#pragma endregion

#pragma region Subtree Size
static void dfs(TreeNode *root, int depth, unordered_map<int, int> &nodeIndexMap, vector<int> &nodeDepths)
{
    if (root == nullptr)
        return;

    nodeIndexMap[root->val] = nodeDepths.size();
    nodeDepths.push_back(depth);

    dfs(root->left, depth + 1, nodeIndexMap, nodeDepths);
    dfs(root->right, depth + 1, nodeIndexMap, nodeDepths);
}

static int calculateSubtreeSize(TreeNode *root, unordered_map<int, int> &subtreeSize)
{
    if (root == nullptr)
        return 0;

    int leftSize = calculateSubtreeSize(root->left, subtreeSize);
    int rightSize = calculateSubtreeSize(root->right, subtreeSize);
    int totalSize = leftSize + rightSize + 1;
    subtreeSize[root->val] = totalSize;

    return totalSize;
}

static vector<int> _02458_HeightOfBinaryTreeAfterSubtreeRemovalQueries1(TreeNode *root, vector<int> &queries)
{
    unordered_map<int, int> nodeIndexMap;
    unordered_map<int, int> subtreeSize;
    vector<int> nodeDepths;
    vector<int> maxDepthFromLeft;
    vector<int> maxDepthFromRight;

    dfs(root, 0, nodeIndexMap, nodeDepths);
    int totalNodes = nodeDepths.size();
    calculateSubtreeSize(root, subtreeSize);

    maxDepthFromLeft.push_back(nodeDepths[0]);
    maxDepthFromRight.push_back(nodeDepths[totalNodes - 1]);

    for (int i = 1; i < totalNodes; i++)
    {
        maxDepthFromLeft.push_back(max(maxDepthFromLeft[i - 1], nodeDepths[i]));
        maxDepthFromRight.push_back(max(maxDepthFromRight[i - 1], nodeDepths[totalNodes - i - 1]));
    }

    reverse(maxDepthFromRight.begin(), maxDepthFromRight.end());
    vector<int> results(queries.size());

    for (int i = 0; i < queries.size(); i++)
    {
        int queryNode = queries[i];
        int startIndex = nodeIndexMap[queryNode] - 1;
        int endIndex = startIndex + 1 + subtreeSize[queryNode];
        int maxDepth = maxDepthFromLeft[startIndex];

        if (endIndex < totalNodes)
            maxDepth = max(maxDepth, maxDepthFromRight[endIndex]);

        results[i] = maxDepth;
    }

    return results;
}
#pragma endregion

#pragma region Eulerian Tour
static void dfs(TreeNode *root, int height, vector<int> &eulerTour,
                unordered_map<int, int> &nodeHeights,
                unordered_map<int, int> &firstOccurrence,
                unordered_map<int, int> &lastOccurrence)
{
    if (root == nullptr)
        return;

    nodeHeights[root->val] = height;
    firstOccurrence[root->val] = eulerTour.size();
    eulerTour.push_back(root->val);

    dfs(root->left, height + 1, eulerTour, nodeHeights, firstOccurrence,
        lastOccurrence);
    dfs(root->right, height + 1, eulerTour, nodeHeights, firstOccurrence,
        lastOccurrence);

    lastOccurrence[root->val] = eulerTour.size();
    eulerTour.push_back(root->val);
}

static vector<int> _02458_HeightOfBinaryTreeAfterSubtreeRemovalQueries2(TreeNode *root, vector<int> &queries)
{
    vector<int> eulerTour;
    unordered_map<int, int> nodeHeights, firstOccurrence, lastOccurrence;

    dfs(root, 0, eulerTour, nodeHeights, firstOccurrence, lastOccurrence);

    int tourSize = eulerTour.size();
    vector<int> maxDepthLeft(tourSize), maxDepthRight(tourSize);
    maxDepthLeft[0] = maxDepthRight[tourSize - 1] = nodeHeights[root->val];

    for (int i = 1; i < tourSize; i++)
    {
        maxDepthLeft[i] = max(maxDepthLeft[i - 1], nodeHeights[eulerTour[i]]);
    }

    for (int i = tourSize - 2; i >= 0; i--)
    {
        maxDepthRight[i] = max(maxDepthRight[i + 1], nodeHeights[eulerTour[i]]);
    }

    vector<int> results(queries.size());

    for (int i = 0; i < queries.size(); i++)
    {
        int queryNode = queries[i];
        int leftMax = (firstOccurrence[queryNode] > 0)
                          ? maxDepthLeft[firstOccurrence[queryNode] - 1]
                          : 0;
        int rightMax = (lastOccurrence[queryNode] < tourSize - 1)
                           ? maxDepthRight[lastOccurrence[queryNode] + 1]
                           : 0;
        results[i] = max(leftMax, rightMax);
    }

    return results;
}
#pragma endregion

#pragma region Two Largest Cousins
static int dfs(TreeNode *node, int level, vector<int> &nodeDepths,
               vector<int> &subtreeHeights, vector<int> &firstLargestHeight,
               vector<int> &secondLargestHeight)
{
    if (node == nullptr)
        return 0;

    nodeDepths[node->val] = level;

    int leftHeight = dfs(node->left, level + 1, nodeDepths, subtreeHeights, firstLargestHeight, secondLargestHeight);
    int rightHeight = dfs(node->right, level + 1, nodeDepths, subtreeHeights, firstLargestHeight, secondLargestHeight);
    int currentHeight = 1 + max(leftHeight, rightHeight);

    subtreeHeights[node->val] = currentHeight;

    if (currentHeight > firstLargestHeight[level])
    {
        secondLargestHeight[level] = firstLargestHeight[level];
        firstLargestHeight[level] = currentHeight;
    }
    else if (currentHeight > secondLargestHeight[level])
    {
        secondLargestHeight[level] = currentHeight;
    }

    return currentHeight;
}

static vector<int> _02458_HeightOfBinaryTreeAfterSubtreeRemovalQueries3(TreeNode *root, vector<int> &queries)
{
    int n = 100000;
    vector<int> nodeDepths(n + 1, 0);
    vector<int> subtreeHeights(n + 1, 0);
    vector<int> firstLargestHeight(n + 1, 0);
    vector<int> secondLargestHeight(n + 1, 0);

    dfs(root, 0, nodeDepths, subtreeHeights, firstLargestHeight,
        secondLargestHeight);

    vector<int> results;
    results.reserve(queries.size());

    for (int queryNode : queries)
    {
        int nodeLevel = nodeDepths[queryNode];

        if (subtreeHeights[queryNode] == firstLargestHeight[nodeLevel])
            results.push_back(nodeLevel + secondLargestHeight[nodeLevel] - 1);
        else
            results.push_back(nodeLevel + firstLargestHeight[nodeLevel] - 1);
    }

    return results;
}
#pragma endregion

#pragma region GTest
static int is_02458_HeightOfBinaryTreeAfterSubtreeRemovalQueries_RunTest()
{
    stringstream ss;
    ss << "*_02458_HeightOfBinaryTreeAfterSubtreeRemovalQueries.expected*"
       << ":"
       << "*_02458_HeightOfBinaryTreeAfterSubtreeRemovalQueries0.expected*"
       << ":"
       << "*_02458_HeightOfBinaryTreeAfterSubtreeRemovalQueries1.expected*"
       << ":"
       << "*_02458_HeightOfBinaryTreeAfterSubtreeRemovalQueries2.expected*"
       << ":"
       << "*_02458_HeightOfBinaryTreeAfterSubtreeRemovalQueries3.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_02458_HeightOfBinaryTreeAfterSubtreeRemovalQueries, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<int> expected = v1[i];

        // Actual
        BinaryTree bt;
        TreeNode *head = bt.createTree(v[i]);
        vector<int> actual = _02458_HeightOfBinaryTreeAfterSubtreeRemovalQueries(head, v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02458_HeightOfBinaryTreeAfterSubtreeRemovalQueries0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<int> expected = v1[i];

        // Actual
        BinaryTree bt;
        TreeNode *head = bt.createTree(v[i]);
        vector<int> actual = _02458_HeightOfBinaryTreeAfterSubtreeRemovalQueries0(head, v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02458_HeightOfBinaryTreeAfterSubtreeRemovalQueries1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<int> expected = v1[i];

        // Actual
        BinaryTree bt;
        TreeNode *head = bt.createTree(v[i]);
        vector<int> actual = _02458_HeightOfBinaryTreeAfterSubtreeRemovalQueries1(head, v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02458_HeightOfBinaryTreeAfterSubtreeRemovalQueries2, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<int> expected = v1[i];

        // Actual
        BinaryTree bt;
        TreeNode *head = bt.createTree(v[i]);
        vector<int> actual = _02458_HeightOfBinaryTreeAfterSubtreeRemovalQueries2(head, v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02458_HeightOfBinaryTreeAfterSubtreeRemovalQueries3, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<int> expected = v1[i];

        // Actual
        BinaryTree bt;
        TreeNode *head = bt.createTree(v[i]);
        vector<int> actual = _02458_HeightOfBinaryTreeAfterSubtreeRemovalQueries3(head, v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion


