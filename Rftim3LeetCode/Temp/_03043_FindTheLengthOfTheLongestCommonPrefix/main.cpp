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

// Greedy - TLE
static int _03043_FindTheLengthOfTheLongestCommonPrefix(vector<int> &arr1, vector<int> &arr2);
// Hash Table
static int _03043_FindTheLengthOfTheLongestCommonPrefix0(vector<int> &arr1, vector<int> &arr2);
// Trie
static int _03043_FindTheLengthOfTheLongestCommonPrefix1(vector<int> &arr1, vector<int> &arr2);

static int is_03043_FindTheLengthOfTheLongestCommonPrefix_RunTest();

/**
 * You are given two arrays with positive integers arr1 and arr2.
 * A prefix of a positive integer is an integer formed by one or more of its digits, starting from its leftmost digit.
 * For example, 123 is a prefix of the integer 12345, while 234 is not.
 *
 * A common prefix of two integers a and b is an integer c, such that c is a prefix of both a and b.
 * For example, 5655359 and 56554 have a common prefix 565 while 1223 and 43456 do not have a common prefix.
 *
 * You need to find the length of the longest common prefix between all pairs of integers (x, y) such that
 * x belongs to arr1 and y belongs to arr2.
 *
 * Return the length of the longest common prefix among all pairs. If no common prefix exists among them, return 0.
 *
 * Constraints:
 *
 * 1 <= arr1.length, arr2.length <= 5 * 10^4
 * 1 <= arr1[i], arr2[i] <= 10^8
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_03043_FindTheLengthOfTheLongestCommonPrefix_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<vector<int>> v, v0;
static vector<int> v1;

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
        string t = "";
        vector<int> vv = {};
        while (getline(ss, t, ','))
        {
            vv.push_back(stoi(t));
        }
        v.push_back(vv);

        s = "";
        getline(cin, s);
        ss.clear();
        ss.str(s);
        t = "";
        vv = {};
        while (getline(ss, t, ','))
        {
            vv.push_back(stoi(t));
        }
        v0.push_back(vv);

        int s0;
        cin >> s0;
        cin.get();
        v1.push_back(s0);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        cout << _03043_FindTheLengthOfTheLongestCommonPrefix(v[i], v0[i]) << "\n";
        cout << _03043_FindTheLengthOfTheLongestCommonPrefix0(v[i], v0[i]) << "\n";
        cout << _03043_FindTheLengthOfTheLongestCommonPrefix1(v[i], v0[i]) << "\n";
    }
}

static int _03043_FindTheLengthOfTheLongestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
{
    int res = 0;
    vector<string> v = {};

    for (auto &&i : arr1)
    {
        v.push_back(to_string(i));
    }

    for (int i = 0; i < arr2.size(); i++)
    {
        string t = to_string(arr2[i]);
        int n = t.size();

        for (int j = 0; j < v.size(); j++)
        {
            int c = 0;
            int m = min(n, (int)v[j].size());

            for (int k = 0; k < m; k++)
            {
                if (v[j][k] == t[k])
                    c++;
                else
                    break;
            }

            res = max(res, c);
        }
    }

    return res;
}

static int _03043_FindTheLengthOfTheLongestCommonPrefix0(vector<int> &arr1, vector<int> &arr2)
{
    unordered_set<int> arr1Prefixes;

    for (int val : arr1)
    {
        while (!arr1Prefixes.count(val) && val > 0)
        {
            arr1Prefixes.insert(val);
            val /= 10;
        }
    }

    int longestPrefix = 0;

    for (int val : arr2)
    {
        while (!arr1Prefixes.count(val) && val > 0)
        {
            val /= 10;
        }

        if (val > 0)
            longestPrefix = max(longestPrefix, static_cast<int>(log10(val) + 1));
    }

    return longestPrefix;
}

class TrieNode
{
public:
    TrieNode *children[10];

    TrieNode()
    {
        for (int i = 0; i < 10; ++i)
        {
            children[i] = nullptr;
        }
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie() { root = new TrieNode(); }

    void insert(int num)
    {
        TrieNode *node = root;
        string numStr = to_string(num);

        for (char digit : numStr)
        {
            int idx = digit - '0';

            if (!node->children[idx])
                node->children[idx] = new TrieNode();

            node = node->children[idx];
        }
    }

    int findLongestPrefix(int num)
    {
        TrieNode *node = root;
        string numStr = to_string(num);
        int len = 0;

        for (char digit : numStr)
        {
            int idx = digit - '0';

            if (node->children[idx])
            {
                len++;
                node = node->children[idx];
            }
            else
                break;
        }

        return len;
    }
};

static int _03043_FindTheLengthOfTheLongestCommonPrefix1(vector<int> &arr1, vector<int> &arr2)
{
    Trie trie;

    for (int num : arr1)
    {
        trie.insert(num);
    }

    int longestPrefix = 0;

    for (int num : arr2)
    {
        int len = trie.findLongestPrefix(num);
        longestPrefix = max(longestPrefix, len);
    }

    return longestPrefix;
}

#pragma region GTest
static int is_03043_FindTheLengthOfTheLongestCommonPrefix_RunTest()
{
    stringstream ss;
    ss << "*_03043_FindTheLengthOfTheLongestCommonPrefix.expected*"
       << ":"
       << "*_03043_FindTheLengthOfTheLongestCommonPrefix0.expected*"
       << ":"
       << "*_03043_FindTheLengthOfTheLongestCommonPrefix1.expected*";

    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_03043_FindTheLengthOfTheLongestCommonPrefix, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v1[i];

        // Actual
        int actual = _03043_FindTheLengthOfTheLongestCommonPrefix(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_03043_FindTheLengthOfTheLongestCommonPrefix0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v1[i];

        // Actual
        int actual = _03043_FindTheLengthOfTheLongestCommonPrefix0(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_03043_FindTheLengthOfTheLongestCommonPrefix1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v1[i];

        // Actual
        int actual = _03043_FindTheLengthOfTheLongestCommonPrefix1(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
