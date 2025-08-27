#include <bits/stdc++.h>
#include <fstream>
#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <string_view>

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

// Using Set
static vector<string> _01223_DiceRollSimulation(vector<string> &folder);
// Using Sorting
static vector<string> _01223_DiceRollSimulation0(vector<string> &folder);
// Using Trie
static vector<string> _01223_DiceRollSimulation1(vector<string> &folder);
// Speed
static vector<string> _01223_DiceRollSimulation2(vector<string> &folder);

static int is_01223_DiceRollSimulation_RunTest();

/**
 * Given a list of folders folder, return the folders after removing all sub-folders in those folders.
 * You may return the answer in any order.
 * If a folder[i] is located within another folder[j], it is called a sub-folder of it.
 * A sub-folder of folder[j] must start with folder[j], followed by a "/".
 * For example, "/a/b" is a sub-folder of "/a", but "/b" is not a sub-folder of "/a/b/c".
 * The format of a path is one or more concatenated strings of the form: '/' followed by one
 * or more lowercase English letters.
 * For example, "/leetcode" and "/leetcode/problems" are valid paths while an empty string and
 * "/" are not.
 *
 * Constraints:
 *
 * 1 <= folder.length <= 4 * 10^4
 * 2 <= folder[i].length <= 100
 * folder[i] contains only lowercase letters and '/'.
 * folder[i] always starts with the character '/'.
 * Each folder name is unique.
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_01223_DiceRollSimulation_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<vector<string>> v, v0;

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
        vector<string> d = {};
        while (getline(ss, t, ','))
        {
            d.push_back(t);
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
            d.push_back(t);
        }
        v0.push_back(d);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        vector<string> res = _01223_DiceRollSimulation(v[i]);
        for (auto &&j : res)
        {
            cout << j << " ";
        }
        cout << "\n";

        vector<string> res0 = _01223_DiceRollSimulation0(v[i]);
        for (auto &&j : res0)
        {
            cout << j << " ";
        }
        cout << "\n";

        vector<string> res1 = _01223_DiceRollSimulation1(v[i]);
        for (auto &&j : res1)
        {
            cout << j << " ";
        }
        cout << "\n";

        vector<string> res2 = _01223_DiceRollSimulation2(v[i]);
        for (auto &&j : res2)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
}

static vector<string> _01223_DiceRollSimulation(vector<string> &folder)
{
    unordered_set<string> folderSet(folder.begin(), folder.end());
    vector<string> result;

    for (string &f : folder)
    {
        bool isSubFolder = false;
        string prefix = f;

        while (!prefix.empty())
        {
            size_t pos = prefix.find_last_of('/');
            if (pos == string::npos)
                break;

            prefix = prefix.substr(0, pos);

            if (folderSet.count(prefix))
            {
                isSubFolder = true;
                break;
            }
        }

        if (!isSubFolder)
            result.push_back(f);
    }

    return result;
}

static vector<string> _01223_DiceRollSimulation0(vector<string> &folder)
{
    sort(folder.begin(), folder.end());
    vector<string> result;
    result.push_back(folder[0]);

    for (int i = 1; i < folder.size(); i++)
    {
        string lastFolder = result.back();
        lastFolder += '/';

        if (folder[i].compare(0, lastFolder.size(), lastFolder) != 0)
            result.push_back(folder[i]);
    }

    return result;
}

#pragma region Using Trie
struct TrieNode
{
    bool isEndOfFolder;
    unordered_map<string, TrieNode *> children;
    TrieNode() : isEndOfFolder(false) {}
};

static TrieNode *root;

static void deleteTrie(TrieNode *node)
{
    if (node == nullptr)
        return;

    for (auto &pair : node->children)
    {
        deleteTrie(pair.second);
    }

    delete node;
}

static vector<string> _01223_DiceRollSimulation1(vector<string> &folder)
{
    root = new TrieNode();

    for (string &path : folder)
    {
        TrieNode *currentNode = root;
        istringstream iss(path);
        string folderName;

        while (getline(iss, folderName, '/'))
        {
            if (folderName.empty())
                continue;

            if (currentNode->children.find(folderName) ==
                currentNode->children.end())
                currentNode->children[folderName] = new TrieNode();

            currentNode = currentNode->children[folderName];
        }

        currentNode->isEndOfFolder = true;
    }

    vector<string> result;

    for (string &path : folder)
    {
        TrieNode *currentNode = root;
        istringstream iss(path);
        string folderName;
        bool isSubFolder = false;

        while (getline(iss, folderName, '/'))
        {
            if (folderName.empty())
                continue;

            TrieNode *nextNode = currentNode->children[folderName];

            if (nextNode->isEndOfFolder && iss.rdbuf()->in_avail() != 0)
            {
                isSubFolder = true;
                break;
            }
            currentNode = nextNode;
        }

        if (!isSubFolder)
            result.push_back(path);
    }

    return result;
}
#pragma endregion

static vector<string> _01223_DiceRollSimulation2(vector<string> &folder)
{
    sort(folder.begin(), folder.end());

    vector<string> ans;
    ans.reserve(folder.size());
    ans.push_back(move(folder.front()));

    size_t i{1};
    while (i < folder.size())
    {
        if (!folder[i].starts_with(ans.back() + '/'))
            ans.push_back(std::move(folder[i]));

        ++i;
    }

    return ans;
}

#pragma region GTest
static int is_01223_DiceRollSimulation_RunTest()
{
    stringstream ss;
    ss << "*_01223_DiceRollSimulation.expected*"
       << ":"
       << "*_01223_DiceRollSimulation0.expected*"
       << ":"
       << "*_01223_DiceRollSimulation1.expected*"
       << ":"
       << "*_01223_DiceRollSimulation2.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_01223_DiceRollSimulation, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<string> expected = v0[i];

        // Actual
        vector<string> actual = _01223_DiceRollSimulation(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_01223_DiceRollSimulation0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<string> expected = v0[i];

        // Actual
        vector<string> actual = _01223_DiceRollSimulation0(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_01223_DiceRollSimulation1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<string> expected = v0[i];

        // Actual
        vector<string> actual = _01223_DiceRollSimulation1(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_01223_DiceRollSimulation2, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<string> expected = v0[i];

        // Actual
        vector<string> actual = _01223_DiceRollSimulation2(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
