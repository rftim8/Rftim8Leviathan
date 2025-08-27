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

// Recursion (Top-Down Traversal)
static bool _00951_FlipEquivalentBinaryTrees(TreeNode *root1, TreeNode *root2);
// Iterative DFS (using a Stack)
static bool _00951_FlipEquivalentBinaryTrees0(TreeNode *root1, TreeNode *root2);
// Canonical Forms
static bool _00951_FlipEquivalentBinaryTrees1(TreeNode *root1, TreeNode *root2);

static int is_00951_FlipEquivalentBinaryTrees_RunTest();

/**
 * For a binary tree T, we can define a flip operation as follows: choose any node,
 * and swap the left and right child subtrees.
 * A binary tree X is flip equivalent to a binary tree Y if and only if we can make
 * X equal to Y after some number of flip operations.
 * Given the roots of two binary trees root1 and root2, return true if the two trees
 * are flip equivalent or false otherwise.
 *
 * Constraints:
 *
 * The number of nodes in each tree is in the range [0, 100].
 * Each tree will have unique node values in the range [0, 99].
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_00951_FlipEquivalentBinaryTrees_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<vector<int>> v, v0;
static vector<bool> v1;

static void dataCollector()
{
    cin >> n;
    cin >> m;
    cin.get();

    for (int i = 0; i < n * m; i += m)
    {
        string s;
        getline(cin, s);
        s.erase(remove(s.begin(), s.end(), '['), s.end());
        s.erase(remove(s.begin(), s.end(), ']'), s.end());
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
        s.erase(remove(s.begin(), s.end(), '['), s.end());
        s.erase(remove(s.begin(), s.end(), ']'), s.end());
        ss.clear();
        ss.str(s);
        t = "";
        d = {};
        while (getline(ss, t, ','))
        {
            d.push_back(t == "null" ? -1 : stoi(t));
        }
        v0.push_back(d);

        bool s0;
        cin >> s0;
        cin.get();
        v1.push_back(s0);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        BinaryTree bt;
        TreeNode *head = bt.createTree(v[i]);
        TreeNode *flip = bt.createTree(v0[i]);
        cout << _00951_FlipEquivalentBinaryTrees(head, flip) << "\n";

        BinaryTree bt0;
        TreeNode *head0 = bt0.createTree(v[i]);
        TreeNode *flip0 = bt0.createTree(v0[i]);
        cout << _00951_FlipEquivalentBinaryTrees(head0, flip0) << "\n";

        BinaryTree bt1;
        TreeNode *head1 = bt1.createTree(v[i]);
        TreeNode *flip1 = bt1.createTree(v0[i]);
        cout << _00951_FlipEquivalentBinaryTrees(head1, flip1) << "\n";
    }
}

#pragma region Recursion (Top-Down Traversal)
static bool _00951_FlipEquivalentBinaryTrees(TreeNode *root1, TreeNode *root2)
{
    if (root1 == nullptr && root2 == nullptr)
        return true;

    if (root1 == nullptr || root2 == nullptr)
        return false;

    if (root1->val != root2->val)
        return false;

    bool noSwap = _00951_FlipEquivalentBinaryTrees(root1->left, root2->left) &&
                  _00951_FlipEquivalentBinaryTrees(root1->right, root2->right);

    bool swap = _00951_FlipEquivalentBinaryTrees(root1->left, root2->right) &&
                _00951_FlipEquivalentBinaryTrees(root1->right, root2->left);

    return swap || noSwap;
}
#pragma endregion

#pragma region Iterative DFS (using a Stack)
static bool checkNodeValues(TreeNode *node1, TreeNode *node2)
{
    if (node1 == nullptr && node2 == nullptr)
        return true;

    if (node1 && node2 && node1->val == node2->val)
        return true;

    return false;
}

static bool _00951_FlipEquivalentBinaryTrees0(TreeNode *root1, TreeNode *root2)
{
    stack<pair<TreeNode *, TreeNode *>> nodePairStack;
    nodePairStack.push({root1, root2});

    while (!nodePairStack.empty())
    {
        auto [node1, node2] = nodePairStack.top();
        nodePairStack.pop();

        if (!node1 && !node2)
            continue;

        if (!node1 || !node2)
            return false;

        if (node1->val != node2->val)
            return false;

        if (checkNodeValues(node1->left, node2->left) &&
            checkNodeValues(node1->right, node2->right))
        {
            nodePairStack.push({node1->left, node2->left});
            nodePairStack.push({node1->right, node2->right});
        }
        else if (checkNodeValues(node1->left, node2->right) &&
                 checkNodeValues(node1->right, node2->left))
        {
            nodePairStack.push({node1->left, node2->right});
            nodePairStack.push({node1->right, node2->left});
        }
        else
            return false;
    }

    return true;
}
#pragma endregion

#pragma region Canonical Forms
static void findCanonicalForm(TreeNode *root)
{
    if (!root)
        return;

    findCanonicalForm(root->left);
    findCanonicalForm(root->right);

    if (!root->right)
        return;

    if (!root->left)
    {
        root->left = root->right;
        root->right = NULL;

        return;
    }

    TreeNode *left = root->left;
    TreeNode *right = root->right;

    if (left->val > right->val)
    {
        root->left = right;
        root->right = left;
    }
}

static bool areEquivalent(TreeNode *root1, TreeNode *root2)
{
    if (!root1 && !root2)
        return true;

    if (!root1 || !root2)
        return false;

    if (root1->val != root2->val)
        return false;

    return areEquivalent(root1->left, root2->left) &&
           areEquivalent(root1->right, root2->right);
}

static bool _00951_FlipEquivalentBinaryTrees1(TreeNode *root1, TreeNode *root2)
{
    findCanonicalForm(root1);
    findCanonicalForm(root2);

    return areEquivalent(root1, root2);
}
#pragma endregion

#pragma region GTest
static int is_00951_FlipEquivalentBinaryTrees_RunTest()
{
    stringstream ss;
    ss << "*_00951_FlipEquivalentBinaryTrees.expected*"
       << ":"
       << "*_00951_FlipEquivalentBinaryTrees0.expected*"
       << ":"
       << "*_00951_FlipEquivalentBinaryTrees1.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_00951_FlipEquivalentBinaryTrees, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        bool expected = v1[i];

        // Actual
        BinaryTree bt;
        TreeNode *head = bt.createTree(v[i]);
        TreeNode *flip = bt.createTree(v0[i]);
        bool actual = _00951_FlipEquivalentBinaryTrees(head, flip);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_00951_FlipEquivalentBinaryTrees0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        bool expected = v1[i];

        // Actual
        BinaryTree bt;
        TreeNode *head = bt.createTree(v[i]);
        TreeNode *flip = bt.createTree(v0[i]);
        bool actual = _00951_FlipEquivalentBinaryTrees0(head, flip);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_00951_FlipEquivalentBinaryTrees1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        bool expected = v1[i];

        // Actual
        BinaryTree bt;
        TreeNode *head = bt.createTree(v[i]);
        TreeNode *flip = bt.createTree(v0[i]);
        bool actual = _00951_FlipEquivalentBinaryTrees1(head, flip);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
