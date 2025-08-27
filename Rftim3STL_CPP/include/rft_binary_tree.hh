#pragma once
#include "rft_global_cpp.hh"

struct TreeNode
{
    std::optional<int> val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(std::nullopt), left(nullptr), right(nullptr) {}
    TreeNode(std::optional<int> x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(std::optional<int> x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BinaryTree
{
    TreeNode *root;

public:
    TreeNode *createTree(std::vector<std::optional<int>> &v);

    void printTreePreOrder(TreeNode *root);
    void printTreeInOrder(TreeNode *root);
    void printTreePostOrder(TreeNode *root);
    void printTreeLevelOrder(TreeNode *root);
    std::vector<std::optional<int>> getTreeLevelOrder(TreeNode *root);

    BinaryTree() : root(nullptr) {}
};

TreeNode *BinaryTree::createTree(std::vector<std::optional<int>> &v)
{
    std::queue<TreeNode *> q = {};
    TreeNode *root = new TreeNode(v[0].value());
    q.push(root);

    for (int i = 1; i < v.size(); i += 2)
    {
        TreeNode *node = q.front();
        q.pop();

        if (v[i] != std::nullopt)
        {
            node->left = new TreeNode(v[i].value());
            q.push(node->left);
        }

        if (i + 1 < v.size() && v[i + 1] != std::nullopt)
        {
            node->right = new TreeNode(v[i + 1].value());
            q.push(node->right);
        }
    }

    return root;
}

void BinaryTree::printTreePreOrder(TreeNode *root)
{
    if (root)
    {
        std::vector<std::optional<int>> v = {};
        std::stack<TreeNode *> st;
        st.push(root);

        while (st.size())
        {
            TreeNode *node = st.top();
            st.pop();

            if (node)
            {
                v.push_back(node->val);
                st.push(node->right);
                st.push(node->left);
            }
        }

        for (auto &&i : v)
        {
            std::cout << i.value() << " ";
        }
        std::cout << "\n";
    }
}

void BinaryTree::printTreeInOrder(TreeNode *root)
{
    if (root)
    {
        std::vector<std::optional<int>> v = {};
        std::stack<TreeNode *> st = {};
        TreeNode *node = root;

        while (node || st.size())
        {
            while (node)
            {
                st.push(node);
                node = node->left;
            }

            node = st.top();
            st.pop();
            v.push_back(node->val);
            node = node->right;
        }

        for (auto &&i : v)
        {
            std::cout << i.value() << " ";
        }
        std::cout << "\n";
    }
}

void BinaryTree::printTreePostOrder(TreeNode *root)
{
    if (root)
    {
        std::vector<std::optional<int>> v = {};
        std::stack<TreeNode *> st = {};
        st.push(root);

        while (st.size())
        {
            TreeNode *node = st.top();
            st.pop();

            v.push_back(node->val);

            if (node->left)
                st.push(node->left);

            if (node->right)
                st.push(node->right);
        }

        reverse(v.begin(), v.end());

        for (auto &&i : v)
        {
            std::cout << i.value() << " ";
        }
        std::cout << "\n";
    }
}

void BinaryTree::printTreeLevelOrder(TreeNode *root)
{
    if (root)
    {
        std::queue<TreeNode *> q = {};
        q.push(root);

        std::vector<std::vector<std::optional<int>>> v = {};
        while (q.size())
        {
            int n = q.size();
            std::vector<std::optional<int>> v0 = {};

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
                std::cout << j.value() << " ";
            }
            std::cout << "\n";
        }
    }
}

std::vector<std::optional<int>> BinaryTree::getTreeLevelOrder(TreeNode *root)
{
    std::vector<std::optional<int>> res = {};

    if (root)
    {
        std::queue<TreeNode *> q = {};
        q.push(root);

        std::vector<std::vector<std::optional<int>>> v = {};
        while (q.size())
        {
            int n = q.size();
            std::vector<std::optional<int>> v0 = {};

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
                res.push_back(j.value());
            }
        }
    }

    return res;
}

#pragma region BT Template
static void printBinaryTreeMain();

template <typename T>
struct BTNode
{
    T val;
    BTNode<T> *left;
    BTNode<T> *right;

    BTNode<T>() : val(0), left(nullptr), right(nullptr) {}
    BTNode<T>(T x) : val(x), left(nullptr), right(nullptr) {}
    BTNode<T>(T x, BTNode<T> *left, BTNode<T> *right) : val(x), left(left), right(right) {}
};

template <typename T>
class BinaryTree0
{
private:
public:
    BTNode<T> *root;
    BTNode<T> *createBinaryTreeFromVector(std::vector<T> &v);
    void printTreePreOrderTraversal(BTNode<T> *root);
    void printTreeInOrderTraversal(BTNode<T> *root);
    void printTreePostOrderTraversal(BTNode<T> *root);
    void printTreeLevelOrderTraversal(BTNode<T> *root);

    BinaryTree0() : root(nullptr) {}
};

//            1
//       2        3
//    4    5        7
//        6

static void printBinaryTreeMain()
{
    std::vector<int> v = {1, 2, 3, 4, 5, NULL, 7, NULL, NULL, 6};
    BinaryTree0<int> tree;

    // tree.printTreePreOrderTraversal(tree.createBinaryTreeFromVector(v));
    // tree.printTreeInOrderTraversal(tree.createBinaryTreeFromVector(v));
    // tree.printTreePostOrderTraversal(tree.createBinaryTreeFromVector(v));
    // tree.printTreeLevelOrderTraversal(tree.createBinaryTreeFromVector(v));
}

template <typename T>
BTNode<T> *BinaryTree0<T>::createBinaryTreeFromVector(std::vector<T> &v)
{
    std::queue<BTNode<T> *> q = {};
    BTNode<T> *root = new BTNode<T>(v[0]);
    q.push(root);

    for (int i = 1; i < v.size(); i += 2)
    {
        BTNode<T> *parent = q.front();
        q.pop();

        if (v[i] != 0)
        {
            parent->left = new BTNode<T>(v[i]);
            q.push(parent->left);
        }

        if (i + 1 < v.size() && v[i + 1] != 0)
        {
            parent->right = new BTNode<T>(v[i + 1]);
            q.push(parent->right);
        }
    }

    return root;
}

template <typename T>
void BinaryTree0<T>::printTreePreOrderTraversal(BTNode<T> *root)
{
    if (root)
    {
        std::vector<T> v = {};
        std::stack<BTNode<T> *> st;
        st.push(root);

        while (st.size())
        {
            BTNode<T> *t = st.top();
            st.pop();

            if (t)
            {
                v.push_back(t->val);
                st.push(t->right);
                st.push(t->left);
            }
        }

        for (auto &&i : v)
        {
            std::cout << i << " ";
        }

        std::cout << "\n";
    }
}

template <typename T>
void BinaryTree0<T>::printTreeInOrderTraversal(BTNode<T> *root)
{
    if (root)
    {
        std::vector<T> v = {};
        std::stack<BTNode<T> *> st = {};
        BTNode<T> *node = root;

        while (node || st.size())
        {
            while (node)
            {
                st.push(node);
                node = node->left;
            }

            node = st.top();
            st.pop();
            v.push_back(node->val);
            node = node->right;
        }

        for (auto &&i : v)
        {
            std::cout << i << " ";
        }

        std::cout << "\n";
    }
}

template <typename T>
void BinaryTree0<T>::printTreePostOrderTraversal(BTNode<T> *root)
{
    if (root)
    {
        std::vector<T> v = {};
        std::stack<BTNode<T> *> st = {};
        st.push(root);

        while (st.size())
        {
            BTNode<T> *node = st.top();
            st.pop();

            v.push_back(node->val);

            if (node->left)
                st.push(node->left);

            if (node->right)
                st.push(node->right);
        }

        reverse(v.begin(), v.end());

        for (auto &&i : v)
        {
            std::cout << i << " ";
        }

        std::cout << "\n";
    }
}

template <typename T>
void BinaryTree0<T>::printTreeLevelOrderTraversal(BTNode<T> *root)
{
    if (root)
    {
        int levels = 0;

        std::queue<BTNode<T> *> q = {};
        q.push(root);

        std::vector<std::vector<T>> v = {};
        std::vector<T> allNodes = {};
        allNodes.push_back(root->val);

        while (q.size())
        {
            int n = q.size();
            std::vector<T> v0 = {};

            while (n != 0)
            {
                BTNode<T> *c = q.front();
                q.pop();

                if (c->left)
                {
                    allNodes.push_back(c->left->val);
                    q.push(c->left);
                }
                else
                    allNodes.push_back(0);

                if (c->right)
                {
                    allNodes.push_back(c->right->val);
                    q.push(c->right);
                }
                else
                    allNodes.push_back(0);

                v0.push_back(c->val);
                n--;
            }

            levels++;
            v.push_back(v0);
        }

#pragma region Partition Graph by Levels
        int m = pow(2, levels) - 1;
        std::vector<std::vector<T>> graph(levels, vector<T>(m, 0));

        int c = 0;
        int step = m, skip = m / 2;

        for (int i = 0; i < levels; i++)
        {
            for (int j = skip; j < m - skip; j += step + 1)
            {
                graph[i][j] = allNodes[c];
                c++;
            }

            skip /= 2;
            step /= 2;
        }
#pragma endregion

#pragma region Print Graph
        for (auto &&i : graph)
        {
            for (auto &&j : i)
            {
                if (j != 0)
                    std::cout << j;
                else
                    std::cout << " ";

                // cout << j << " ";
            }

            std::cout << "\n";
        }
#pragma endregion

#pragma region Print Nodes by Levels
// for (auto &&i : v)
// {
//     for (auto &&j : i)
//     {
//         cout << j << " ";
//     }
//     cout << "\n";
// }
#pragma endregion

#pragma region Print all nodes
// for (auto &&i : allNodes)
// {
//     cout << i << " ";
// }
// cout << "\n";
#pragma endregion
    }
}
#pragma endregion
