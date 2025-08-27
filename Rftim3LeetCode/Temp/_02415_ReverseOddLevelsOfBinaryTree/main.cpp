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

    vector<int> binaryTreeToVectorInt(TreeNode *root);


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

vector<int> BinaryTree::binaryTreeToVectorInt(TreeNode *root)
{
    vector<int> res = {};

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
                res.push_back(j);
            }
        }
    }

    return res;
}

static void dataCollector();

static void solve();

// DFS
static TreeNode *_02415_ReverseOddLevelsOfBinaryTree(TreeNode *root);
// BFS
static TreeNode *_02415_ReverseOddLevelsOfBinaryTree0(TreeNode *root);

static int is_02415_ReverseOddLevelsOfBinaryTree_RunTest();

/**
 * Given the root of a perfect binary tree, reverse the node values at each odd level of the tree.
 * For example, suppose the node values at level 3 are [2,1,3,4,7,11,29,18], then it should become [18,29,11,7,4,3,1,2].
 * Return the root of the reversed tree.
 * A binary tree is perfect if all parent nodes have two children and all leaves are on the same level.
 * The level of a node is the number of edges along the path between it and the root node.
 *
 * Constraints:
 *
 * The number of nodes in the tree is in the range [1, 2^14].
 * 0 <= Node.val <= 10^5
 * root is a perfect binary tree.
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_02415_ReverseOddLevelsOfBinaryTree_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<vector<int>> v, v0;

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
            d.push_back(stoi(t));
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
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        BinaryTree bt;
        TreeNode *t = bt.createTree(v[i]);
        TreeNode *res = _02415_ReverseOddLevelsOfBinaryTree(t);
        bt.printTreeLevelOrder(res);

        BinaryTree bt0;
        TreeNode *t0 = bt0.createTree(v[i]);
        TreeNode *res0 = _02415_ReverseOddLevelsOfBinaryTree(t0);
        bt0.printTreeLevelOrder(res0);
    }
}

#pragma region DFS
static void traverseDFS(TreeNode *leftChild, TreeNode *rightChild, int level)
{
    if (leftChild == nullptr || rightChild == nullptr)
        return;

    if (level % 2 == 0)
    {
        int temp = leftChild->val;
        leftChild->val = rightChild->val;
        rightChild->val = temp;
    }

    traverseDFS(leftChild->left, rightChild->right, level + 1);
    traverseDFS(leftChild->right, rightChild->left, level + 1);
}

static TreeNode *_02415_ReverseOddLevelsOfBinaryTree(TreeNode *root)
{
    traverseDFS(root->left, root->right, 0);
    return root;
}
#pragma endregion

#pragma region BFS
static TreeNode *_02415_ReverseOddLevelsOfBinaryTree0(TreeNode *root)
{
    if (!root)
        return nullptr;

    queue<TreeNode *> q;
    q.push(root);
    int level = 0;

    while (!q.empty())
    {
        int size = q.size();
        vector<TreeNode *> currentLevelNodes;

        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            currentLevelNodes.push_back(node);

            if (node->left)
                q.push(node->left);

            if (node->right)
                q.push(node->right);
        }

        if (level % 2 == 1)
        {
            int left = 0, right = currentLevelNodes.size() - 1;

            while (left < right)
            {
                int temp = currentLevelNodes[left]->val;
                currentLevelNodes[left]->val = currentLevelNodes[right]->val;
                currentLevelNodes[right]->val = temp;
                left++;
                right--;
            }
        }

        level++;
    }

    return root;
}
#pragma endregion

#pragma region GTest
static int is_02415_ReverseOddLevelsOfBinaryTree_RunTest()
{
    stringstream ss;
    ss << "*_02415_ReverseOddLevelsOfBinaryTree.expected*"
       << ":"
       << "*_02415_ReverseOddLevelsOfBinaryTree0.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_02415_ReverseOddLevelsOfBinaryTree, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<int> expected = v0[i];

        // Actual
        BinaryTree bt;
        TreeNode *t = bt.createTree(v[i]);
        vector<int> actual = bt.binaryTreeToVectorInt(_02415_ReverseOddLevelsOfBinaryTree(t));

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02415_ReverseOddLevelsOfBinaryTree0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<int> expected = v0[i];

        // Actual
        BinaryTree bt;
        TreeNode *t = bt.createTree(v[i]);
        vector<int> actual = bt.binaryTreeToVectorInt(_02415_ReverseOddLevelsOfBinaryTree0(t));

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
