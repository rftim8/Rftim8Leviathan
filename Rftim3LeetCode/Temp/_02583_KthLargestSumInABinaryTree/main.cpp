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

// Level Order Traversal + Max Heap
static long long _02583_KthLargestSumInABinaryTree(TreeNode *root, int k);
// Level Order Traversal + Min Heap
static long long _02583_KthLargestSumInABinaryTree0(TreeNode *root, int k);

static int is_02583_KthLargestSumInABinaryTree_RunTest();

/**
 * You are given the root of a binary tree and a positive integer k.
 * The level sum in the tree is the sum of the values of the nodes that are on the same level.
 * Return the kth largest level sum in the tree (not necessarily distinct).
 * If there are fewer than k levels in the tree, return -1.
 * Note that two nodes are on the same level if they have the same distance from the root.
 *
 * Constraints:
 *
 * The number of nodes in the tree is n.
 * 2 <= n <= 10^5
 * 1 <= Node.val <= 10^6
 * 1 <= k <= n
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_02583_KthLargestSumInABinaryTree_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<vector<int>> v;
static vector<int> v0;
static vector<long long> v1;

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

        int s0;
        cin >> s0;
        v0.push_back(s0);

        long long s1;
        cin >> s1;
        cin.get();
        v1.push_back(s1);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        BinaryTree bt;
        TreeNode *head = bt.createTree(v[i]);
        cout << _02583_KthLargestSumInABinaryTree(head, v0[i]) << "\n";

        BinaryTree bt0;
        TreeNode *head0 = bt0.createTree(v[i]);
        cout << _02583_KthLargestSumInABinaryTree(head0, v0[i]) << "\n";
    }
}

static long long _02583_KthLargestSumInABinaryTree(TreeNode *root, int k)
{
    priority_queue<long> pq;
    queue<TreeNode *> bfsQueue;
    bfsQueue.push(root);

    while (!bfsQueue.empty())
    {
        long size = bfsQueue.size();
        long sum = 0;

        for (int i = 0; i < size; i++)
        {
            TreeNode *poppedNode = bfsQueue.front();
            bfsQueue.pop();
            sum += poppedNode->val;

            if (poppedNode->left != nullptr)
                bfsQueue.push(poppedNode->left);

            if (poppedNode->right != nullptr)
                bfsQueue.push(poppedNode->right);
        }
        pq.push(sum);
    }

    if (pq.size() < k)
        return -1;

    for (int i = 0; i < k - 1; i++)
        pq.pop();

    return pq.top();
}

static long long _02583_KthLargestSumInABinaryTree0(TreeNode *root, int k)
{
    priority_queue<long, vector<long>, greater<long>> pq;
    queue<TreeNode *> bfsQueue;
    bfsQueue.push(root);

    while (!bfsQueue.empty())
    {
        int size = bfsQueue.size();
        long sum = 0;

        for (int i = 0; i < size; i++)
        {
            TreeNode *poppedNode = bfsQueue.front();
            bfsQueue.pop();
            sum += poppedNode->val;

            if (poppedNode->left != NULL)
                bfsQueue.push(poppedNode->left);

            if (poppedNode->right != NULL)
                bfsQueue.push(poppedNode->right);
        }

        pq.push(sum);

        if (pq.size() > k)
            pq.pop();
    }

    if (pq.size() < k)
        return -1;

    return pq.top();
}

#pragma region GTest
static int is_02583_KthLargestSumInABinaryTree_RunTest()
{
    stringstream ss;
    ss << "*_02583_KthLargestSumInABinaryTree.expected*"
       << ":"
       << "*_02583_KthLargestSumInABinaryTree0.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_02583_KthLargestSumInABinaryTree, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        long long expected = v1[i];

        // Actual
        BinaryTree bt;
        TreeNode *head = bt.createTree(v[i]);
        long long actual = _02583_KthLargestSumInABinaryTree(head, v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02583_KthLargestSumInABinaryTree0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        long long expected = v1[i];

        // Actual
        BinaryTree bt;
        TreeNode *head = bt.createTree(v[i]);
        long long actual = _02583_KthLargestSumInABinaryTree0(head, v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
