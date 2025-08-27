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

// Hash Map
static int _02471_MinimumNumberOfOperationsToSortaBinaryTreeByLevel(TreeNode *root);
// Bit Manipulation
static int _02471_MinimumNumberOfOperationsToSortaBinaryTreeByLevel0(TreeNode *root);

static int is_02471_MinimumNumberOfOperationsToSortaBinaryTreeByLevel_RunTest();

/**
 * You are given the root of a binary tree with unique values.
 * In one operation, you can choose any two nodes at the same level and swap their values.
 * Return the minimum number of operations needed to make the values at each level sorted in a strictly increasing order.
 * The level of a node is the number of edges along the path between it and the root node.
 *
 * Constraints:
 *
 * The number of nodes in the tree is in the range [1, 10^5].
 * 1 <= Node.val <= 10^5
 * All the values of the tree are unique.
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_02471_MinimumNumberOfOperationsToSortaBinaryTreeByLevel_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<vector<int>> v;
static vector<int> v0;

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

        int s0;
        cin >> s0;
        cin.get();
        v0.push_back(s0);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        BinaryTree bt;
        TreeNode *res = bt.createTree(v[i]);
        cout << _02471_MinimumNumberOfOperationsToSortaBinaryTreeByLevel(res) << "\n";

        BinaryTree bt0;
        TreeNode *res0 = bt0.createTree(v[i]);
        cout << _02471_MinimumNumberOfOperationsToSortaBinaryTreeByLevel(res0) << "\n";
    }
}

#pragma region Hash Map
static int getMinSwaps(vector<int> &original)
{
    int swaps = 0;
    vector<int> target = original;
    sort(target.begin(), target.end());
    unordered_map<int, int> pos;
    for (int i = 0; i < original.size(); i++)
    {
        pos[original[i]] = i;
    }

    for (int i = 0; i < original.size(); i++)
    {
        if (original[i] != target[i])
        {
            swaps++;
            int curPos = pos[target[i]];
            pos[original[i]] = curPos;
            swap(original[curPos], original[i]);
        }
    }

    return swaps;
}

static int _02471_MinimumNumberOfOperationsToSortaBinaryTreeByLevel(TreeNode *root)
{
    queue<TreeNode *> queue;
    queue.push(root);
    int totalSwaps = 0;

    while (!queue.empty())
    {
        int levelSize = queue.size();
        vector<int> levelValues(levelSize);

        for (int i = 0; i < levelSize; i++)
        {
            TreeNode *node = queue.front();
            queue.pop();
            levelValues[i] = node->val;

            if (node->left != nullptr)
                queue.push(node->left);

            if (node->right != nullptr)
                queue.push(node->right);
        }

        totalSwaps += getMinSwaps(levelValues);
    }

    return totalSwaps;
}
#pragma endregion

#pragma region Bit Manipulation
static const int SHIFT = 20;
static const int MASK = 0xFFFFF;

static int _02471_MinimumNumberOfOperationsToSortaBinaryTreeByLevel0(TreeNode *root)
{
    queue<TreeNode *> queue;
    queue.push(root);
    int swaps = 0;

    while (!queue.empty())
    {
        int levelSize = queue.size();
        vector<long long> nodes(levelSize);

        for (int i = 0; i < levelSize; i++)
        {
            TreeNode *node = queue.front();
            queue.pop();
            nodes[i] = (static_cast<long long>(node->val) << SHIFT) + i;

            if (node->left != nullptr)
                queue.push(node->left);

            if (node->right != nullptr)
                queue.push(node->right);
        }

        sort(nodes.begin(), nodes.end());

        for (int i = 0; i < levelSize; i++)
        {
            int origPos = static_cast<int>(nodes[i] & MASK);

            if (origPos != i)
            {
                swap(nodes[i], nodes[origPos]);
                swaps++;
                i--;
            }
        }
    }

    return swaps;
}
#pragma endregion

#pragma region GTest
static int is_02471_MinimumNumberOfOperationsToSortaBinaryTreeByLevel_RunTest()
{
    stringstream ss;
    ss << "*_02471_MinimumNumberOfOperationsToSortaBinaryTreeByLevel.expected*"
       << ":"
       << "*_02471_MinimumNumberOfOperationsToSortaBinaryTreeByLevel0.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_02471_MinimumNumberOfOperationsToSortaBinaryTreeByLevel, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        BinaryTree bt;
        TreeNode *res = bt.createTree(v[i]);
        int actual = _02471_MinimumNumberOfOperationsToSortaBinaryTreeByLevel(res);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02471_MinimumNumberOfOperationsToSortaBinaryTreeByLevel0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        BinaryTree bt;
        TreeNode *res = bt.createTree(v[i]);
        int actual = _02471_MinimumNumberOfOperationsToSortaBinaryTreeByLevel0(res);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
