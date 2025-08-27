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

// BFS
static vector<int> _00515_FindLargestValueInEachTreeRow(TreeNode *root);
// DFS
static vector<int> _00515_FindLargestValueInEachTreeRow0(TreeNode *root);
// DFS Iterative
static vector<int> _00515_FindLargestValueInEachTreeRow1(TreeNode *root);

static int is_00515_FindLargestValueInEachTreeRow_RunTest();

/**
 * Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).
 * Constraints:
 *
 * The number of nodes in the tree will be in the range [0, 10^4].
 * -2^31 <= Node.val <= 2^31 - 1
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_00515_FindLargestValueInEachTreeRow_RunTest();
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
        TreeNode *t = bt.createTree(v[0]);
        vector<int> res = _00515_FindLargestValueInEachTreeRow(t);
        for (auto &&j : res)
        {
            cout << j << " ";
        }
        cout << "\n";

        BinaryTree bt0;
        TreeNode *t0 = bt0.createTree(v[0]);
        vector<int> res0 = _00515_FindLargestValueInEachTreeRow0(t);
        for (auto &&j : res0)
        {
            cout << j << " ";
        }
        cout << "\n";

        BinaryTree bt1;
        TreeNode *t1 = bt1.createTree(v[0]);
        vector<int> res1 = _00515_FindLargestValueInEachTreeRow(t1);
        for (auto &&j : res1)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
}

static vector<int> _00515_FindLargestValueInEachTreeRow(TreeNode *root)
{
    if (root == nullptr)
        return vector<int>{};

    vector<int> ans;
    queue<TreeNode *> queue;
    queue.push(root);

    while (!queue.empty())
    {
        int currentLength = queue.size();
        int currMax = INT_MIN;

        for (int i = 0; i < currentLength; i++)
        {
            TreeNode *node = queue.front();
            queue.pop();
            currMax = max(currMax, node->val);

            if (node->left)
                queue.push(node->left);

            if (node->right)
                queue.push(node->right);
        }

        ans.push_back(currMax);
    }

    return ans;
}

#pragma region DFS
static vector<int> ans;

static void dfs(TreeNode *node, int depth)
{
    if (node == nullptr)
        return;

    if (depth == ans.size())
        ans.push_back(node->val);
    else
        ans[depth] = max(ans[depth], node->val);

    dfs(node->left, depth + 1);
    dfs(node->right, depth + 1);
}

static vector<int> _00515_FindLargestValueInEachTreeRow0(TreeNode *root)
{
    ans = {};

    dfs(root, 0);

    return ans;
}
#pragma endregion

static vector<int> _00515_FindLargestValueInEachTreeRow1(TreeNode *root)
{
    if (root == nullptr)
        return vector<int>{};

    vector<int> ans;
    stack<pair<TreeNode *, int>> stack;
    stack.push(make_pair(root, 0));

    while (!stack.empty())
    {
        pair<TreeNode *, int> pair = stack.top();
        stack.pop();
        TreeNode *node = pair.first;
        int depth = pair.second;

        if (depth == ans.size())
            ans.push_back(node->val);
        else
            ans[depth] = max(ans[depth], node->val);

        if (node->left)
            stack.push(make_pair(node->left, depth + 1));

        if (node->right)
            stack.push(make_pair(node->right, depth + 1));
    }

    return ans;
}

#pragma region GTest
static int is_00515_FindLargestValueInEachTreeRow_RunTest()
{
    stringstream ss;
    ss << "*_00515_FindLargestValueInEachTreeRow.expected*"
       << ":"
       << "*_00515_FindLargestValueInEachTreeRow0.expected*"
       << ":"
       << "*_00515_FindLargestValueInEachTreeRow1.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_00515_FindLargestValueInEachTreeRow, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<int> expected = v0[i];

        // Actual
        BinaryTree bt;
        TreeNode *t = bt.createTree(v[i]);
        vector<int> actual = _00515_FindLargestValueInEachTreeRow(t);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_00515_FindLargestValueInEachTreeRow0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<int> expected = v0[i];

        // Actual
        BinaryTree bt;
        TreeNode *t = bt.createTree(v[i]);
        vector<int> actual = _00515_FindLargestValueInEachTreeRow0(t);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_00515_FindLargestValueInEachTreeRow1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<int> expected = v0[i];

        // Actual
        BinaryTree bt;
        TreeNode *t = bt.createTree(v[i]);
        vector<int> actual = _00515_FindLargestValueInEachTreeRow1(t);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
