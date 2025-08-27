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
    vector<string> exportTreeToVectorString(TreeNode *root);

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

vector<string> BinaryTree::exportTreeToVectorString(TreeNode *root)
{
    vector<string> res = {};

    if (root)
    {
        queue<TreeNode *> q = {};
        q.push(root);

        vector<vector<string>> v = {};
        while (q.size())
        {
            int n = q.size();
            vector<string> v0 = {};

            while (n != 0)
            {
                TreeNode *node = q.front();
                q.pop();

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);

                v0.push_back(to_string(node->val));
                n--;
            }

            v.push_back(v0);
        }

        for (auto &&i : v)
        {
            for (auto &&j : i)
            {
                res.push_back(j);
            }
        }
    }

    return res;
}

static void dataCollector();

static void solve();

// Two Pass BFS
static TreeNode *_02641_CousinsInBinaryTreeII(TreeNode *root);
// Two Pass DFS
static TreeNode *_02641_CousinsInBinaryTreeII0(TreeNode *root);
// Single BFS with Running Sum
static TreeNode *_02641_CousinsInBinaryTreeII1(TreeNode *root);

static int is_02641_CousinsInBinaryTreeII_RunTest();

/**
 * Given the root of a binary tree, replace the value of each node in the tree with the sum
 * of all its cousins' values.
 * Two nodes of a binary tree are cousins if they have the same depth with different parents.
 * Return the root of the modified tree.
 * Note that the depth of a node is the number of edges in the path from the root node to it.
 *
 * Constraints:
 *
 * The number of nodes in the tree is in the range [1, 10^5].
 * 1 <= Node.val <= 10^4
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_02641_CousinsInBinaryTreeII_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<vector<int>> v;
static vector<vector<string>> v0;

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
        vector<string> vv = {};
        while (getline(ss, t, ','))
        {
            if (t != "null")
                vv.push_back(t);
        }
        v0.push_back(vv);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        BinaryTree bt;
        TreeNode *head = bt.createTree(v[i]);
        TreeNode *res = _02641_CousinsInBinaryTreeII(head);
        bt.printTreeLevelOrder(res);

        BinaryTree bt0;
        TreeNode *head0 = bt0.createTree(v[i]);
        TreeNode *res0 = _02641_CousinsInBinaryTreeII(head0);
        bt0.printTreeLevelOrder(res0);

        BinaryTree bt1;
        TreeNode *head1 = bt1.createTree(v[i]);
        TreeNode *res1 = _02641_CousinsInBinaryTreeII(head1);
        bt1.printTreeLevelOrder(res1);
    }
}

static TreeNode *_02641_CousinsInBinaryTreeII(TreeNode *root)
{
    if (!root)
        return root;

    queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);
    vector<int> levelSums;

    while (!nodeQueue.empty())
    {
        int levelSum = 0;
        int levelSize = nodeQueue.size();

        for (int i = 0; i < levelSize; ++i)
        {
            TreeNode *currentNode = nodeQueue.front();
            nodeQueue.pop();
            levelSum += currentNode->val;

            if (currentNode->left)
                nodeQueue.push(currentNode->left);

            if (currentNode->right)
                nodeQueue.push(currentNode->right);
        }

        levelSums.push_back(levelSum);
    }

    nodeQueue.push(root);
    int levelIndex = 1;
    root->val = 0;

    while (!nodeQueue.empty())
    {
        int levelSize = nodeQueue.size();

        for (int i = 0; i < levelSize; ++i)
        {
            TreeNode *currentNode = nodeQueue.front();
            nodeQueue.pop();

            int siblingSum =
                (currentNode->left ? currentNode->left->val : 0) +
                (currentNode->right ? currentNode->right->val : 0);

            if (currentNode->left)
            {
                currentNode->left->val = levelSums[levelIndex] - siblingSum;
                nodeQueue.push(currentNode->left);
            }

            if (currentNode->right)
            {
                currentNode->right->val =
                    levelSums[levelIndex] - siblingSum;
                nodeQueue.push(currentNode->right);
            }
        }
        ++levelIndex;
    }

    return root;
}

#pragma region Two Pass DFS
int levelSums[100000];

static void calculateLevelSum(TreeNode *node, int level)
{
    if (node == nullptr)
        return;

    levelSums[level] += node->val;
    calculateLevelSum(node->left, level + 1);
    calculateLevelSum(node->right, level + 1);
}

static void replaceValueInTreeInternal(TreeNode *node, int siblingSum, int level)
{
    if (node == nullptr)
        return;

    int leftChildVal = node->left == nullptr ? 0 : node->left->val;
    int rightChildVal = node->right == nullptr ? 0 : node->right->val;

    if (level == 0 || level == 1)
        node->val = 0;
    else
        node->val = levelSums[level] - node->val - siblingSum;

    replaceValueInTreeInternal(node->left, rightChildVal, level + 1);
    replaceValueInTreeInternal(node->right, leftChildVal, level + 1);
}

static TreeNode *_02641_CousinsInBinaryTreeII0(TreeNode *root)
{
    calculateLevelSum(root, 0);
    replaceValueInTreeInternal(root, 0, 0);

    return root;
}
#pragma endregion

static TreeNode *_02641_CousinsInBinaryTreeII1(TreeNode *root)
{
    if (root == nullptr)
        return root;

    queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);
    int previousLevelSum = root->val;

    while (!nodeQueue.empty())
    {
        int levelSize = nodeQueue.size();
        int currentLevelSum = 0;

        for (int i = 0; i < levelSize; i++)
        {
            TreeNode *currentNode = nodeQueue.front();
            nodeQueue.pop();
            currentNode->val = previousLevelSum - currentNode->val;

            int siblingSum = (currentNode->left != nullptr ? currentNode->left->val : 0) +
                             (currentNode->right != nullptr ? currentNode->right->val : 0);

            if (currentNode->left != nullptr)
            {
                currentLevelSum += currentNode->left->val;
                currentNode->left->val = siblingSum;
                nodeQueue.push(currentNode->left);
            }

            if (currentNode->right != nullptr)
            {
                currentLevelSum += currentNode->right->val;
                currentNode->right->val = siblingSum;
                nodeQueue.push(currentNode->right);
            }
        }

        previousLevelSum = currentLevelSum;
    }

    return root;
}

#pragma region GTest
static int is_02641_CousinsInBinaryTreeII_RunTest()
{
    stringstream ss;
    ss << "*_02641_CousinsInBinaryTreeII.expected*"
       << ":"
       << "*_02641_CousinsInBinaryTreeII0.expected*"
       << ":"
       << "*_02641_CousinsInBinaryTreeII1.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_02641_CousinsInBinaryTreeII, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<string> expected = v0[i];

        // Actual
        BinaryTree bt;
        TreeNode *head = bt.createTree(v[i]);
        TreeNode *res = _02641_CousinsInBinaryTreeII(head);
        vector<string> actual = bt.exportTreeToVectorString(res);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02641_CousinsInBinaryTreeII0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<string> expected = v0[i];

        // Actual
        BinaryTree bt;
        TreeNode *head = bt.createTree(v[i]);
        TreeNode *res = _02641_CousinsInBinaryTreeII0(head);
        vector<string> actual = bt.exportTreeToVectorString(res);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02641_CousinsInBinaryTreeII1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<string> expected = v0[i];

        // Actual
        BinaryTree bt;
        TreeNode *head = bt.createTree(v[i]);
        TreeNode *res = _02641_CousinsInBinaryTreeII1(head);
        vector<string> actual = bt.exportTreeToVectorString(res);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
