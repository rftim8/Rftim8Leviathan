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

// Using Doubly Linked List
static vector<string> _00432_AllOOneDataStructure(vector<string> v, vector<vector<string>> v0);
// Speed
static vector<string> _00432_AllOOneDataStructure0(vector<string> v, vector<vector<string>> v0);

static int is_00432_AllOOneDataStructure_RunTest();

/**
 * Design a data structure to store the strings' count with the ability to return the strings with minimum and maximum counts.
 *
 * Implement the AllOne class:
 *
 * - AllOne() Initializes the object of the data structure.
 * - inc(String key) Increments the count of the string key by 1.
 * If key does not exist in the data structure, insert it with count 1.
 * - dec(String key) Decrements the count of the string key by 1.
 * If the count of key is 0 after the decrement, remove it from the data structure.
 * It is guaranteed that key exists in the data structure before the decrement.
 * - getMaxKey() Returns one of the keys with the maximal count.
 * If no element exists, return an empty string "".
 * - getMinKey() Returns one of the keys with the minimum count.
 * If no element exists, return an empty string "".
 *
 * Note that each function must run in O(1) average time complexity.
 *
 * Constraints:
 *
 * 1 <= key.length <= 10
 * key consists of lowercase English letters.
 * It is guaranteed that for each call to dec, key is existing in the data structure.
 * At most 5 * 10^4 calls will be made to inc, dec, getMaxKey, and getMinKey.
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_00432_AllOOneDataStructure_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<vector<string>> v, v1;
static vector<vector<vector<string>>> v0;

static vector<vector<string>> stringTo2DVectorString(string s)
{
    vector<vector<string>> res = {};
    int l = 0, r = 0;
    string a = "";
    vector<string> vv = {};
    for (auto &&j : s)
    {
        if (j == '[')
            l++;
        else if (j == ']')
        {
            r++;
            if (l > r)
            {
                vv.push_back(a);
                a = "";
            }
        }
        else
            a += j;
    }

    for (auto &&j : vv)
    {
        vector<string> a = {};
        string t;
        stringstream ss(j);
        while (getline(ss, t, ','))
        {
            if (t != "null" &&
                t != "")
                a.push_back(t);
        }
        res.push_back(a);
    }

    return res;
}

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
        vector<string> vv = {};
        while (getline(ss, t, ','))
        {
            vv.push_back(t);
        }
        v.push_back(vv);

        s = "";
        getline(cin, s);
        v0.push_back(stringTo2DVectorString(s));

        s = "";
        getline(cin, s);
        ss.clear();
        ss.str(s);
        t = "";
        vv = {};
        while (getline(ss, t, ','))
        {
            vv.push_back(t);
        }
        v1.push_back(vv);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        vector<string> res = _00432_AllOOneDataStructure(v[i], v0[i]);
        for (auto &&j : res)
        {
            cout << j << " ";
        }
        cout << "\n";

        vector<string> res0 = _00432_AllOOneDataStructure0(v[i], v0[i]);
        for (auto &&j : res0)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
}

class Node
{
public:
    int freq;
    Node *prev;
    Node *next;
    unordered_set<string> keys;

    Node(int freq) : freq(freq), prev(nullptr), next(nullptr) {}
};

class AllOne
{
private:
    Node *head;
    Node *tail;
    unordered_map<string, Node *> map;

    void removeNode(Node *node)
    {
        Node *prevNode = node->prev;
        Node *nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        delete node;
    }

public:
    AllOne()
    {
        head = new Node(0);
        tail = new Node(0);
        head->next = tail;
        tail->prev = head;
    }

    void inc(string key)
    {
        if (map.find(key) != map.end())
        {
            Node *node = map[key];
            int freq = node->freq;
            node->keys.erase(key);
            Node *nextNode = node->next;

            if (nextNode == tail || nextNode->freq != freq + 1)
            {
                Node *newNode = new Node(freq + 1);
                newNode->keys.insert(key);
                newNode->prev = node;
                newNode->next = nextNode;
                node->next = newNode;
                nextNode->prev = newNode;
                map[key] = newNode;
            }
            else
            {
                nextNode->keys.insert(key);
                map[key] = nextNode;
            }

            if (node->keys.empty())
                removeNode(node);
        }
        else
        {
            Node *firstNode = head->next;

            if (firstNode == tail || firstNode->freq > 1)
            {
                Node *newNode = new Node(1);
                newNode->keys.insert(key);
                newNode->prev = head;
                newNode->next = firstNode;
                head->next = newNode;
                firstNode->prev = newNode;
                map[key] = newNode;
            }
            else
            {
                firstNode->keys.insert(key);
                map[key] = firstNode;
            }
        }
    }

    void dec(string key)
    {
        if (map.find(key) == map.end())
            return;

        Node *node = map[key];
        node->keys.erase(key);
        int freq = node->freq;

        if (freq == 1)
            map.erase(key);
        else
        {
            Node *prevNode = node->prev;

            if (prevNode == head || prevNode->freq != freq - 1)
            {
                Node *newNode = new Node(freq - 1);
                newNode->keys.insert(key);
                newNode->prev = prevNode;
                newNode->next = node;
                prevNode->next = newNode;
                node->prev = newNode;
                map[key] = newNode;
            }
            else
            {
                prevNode->keys.insert(key);
                map[key] = prevNode;
            }
        }

        if (node->keys.empty())
            removeNode(node);
    }

    string getMaxKey()
    {
        if (tail->prev == head)
            return "";

        return *(tail->prev->keys.begin());
    }

    string getMinKey()
    {
        if (head->next == tail)
            return "";

        return *(head->next->keys.begin());
    }
};

static vector<string> _00432_AllOOneDataStructure(vector<string> v, vector<vector<string>> v0)
{
    vector<string> res = {};

    AllOne *obj = new AllOne();
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == "AllOne")
            res.push_back("null");
        else
        {
            if (v[i] == "inc")
            {
                obj->inc(v0[i][0]);
                res.push_back("null");
            }
            else if (v[i] == "dec")
            {
                obj->dec(v0[i][0]);
                res.push_back("null");
            }
            else if (v[i] == "getMinKey")
            {
                string param = obj->getMinKey();
                res.push_back(param);
            }
            else if (v[i] == "getMaxKey")
            {
                string param = obj->getMaxKey();
                res.push_back(param);
            }
        }
    }

    return res;
}

class AllOne0
{
public:
    unordered_map<string, int> m;

    AllOne0()
    {
    }

    void updateMin()
    {
        _min.second = INT_MAX;

        for (auto &nd : m)
        {
            if (_min.second > nd.second)
            {
                _min.second = nd.second;
                _min.first = nd.first;
            }
        }
    }

    void updateMax()
    {
        _max.second = INT_MIN;

        for (auto &nd : m)
        {
            if (_max.second < nd.second)
            {
                _max.second = nd.second;
                _max.first = nd.first;
            }
        }
    }

    void inc(string key)
    {
        auto &v = m[key];
        ++v;

        if (v > _max.second)
        {
            _max.second = v;
            _max.first = key;
        }

        if (key == _min.first)
            updateMin();

        if (_min.second > v || _min.first.empty())
        {
            _min.first = key;
            _min.second = v;
        }
    }

    void dec(string key)
    {
        m[key]--;

        if (m[key] == 0)
            m.erase(key);

        _min.first = _max.first = "";
    }

    string getMaxKey()
    {
        if (!_max.first.empty())
            return _max.first;

        updateMax();

        return _max.first;
    }

    string getMinKey()
    {
        if (!_min.first.empty())
            return _min.first;

        updateMin();

        return _min.first;
    }

    pair<string, int> _min{{}, 0};
    pair<string, int> _max{{}, 0};
};

static vector<string> _00432_AllOOneDataStructure0(vector<string> v, vector<vector<string>> v0)
{
    vector<string> res = {};

    AllOne0 *obj = new AllOne0();
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == "AllOne")
            res.push_back("null");
        else
        {
            if (v[i] == "inc")
            {
                obj->inc(v0[i][0]);
                res.push_back("null");
            }
            else if (v[i] == "dec")
            {
                obj->dec(v0[i][0]);
                res.push_back("null");
            }
            else if (v[i] == "getMinKey")
            {
                string param = obj->getMinKey();
                res.push_back(param);
            }
            else if (v[i] == "getMaxKey")
            {
                string param = obj->getMaxKey();
                res.push_back(param);
            }
        }
    }

    return res;
}

#pragma region GTest
static int is_00432_AllOOneDataStructure_RunTest()
{
    stringstream ss;
    ss << "*_00432_AllOOneDataStructure.expected*"
       << ":"
       << "*_00432_AllOOneDataStructure0.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_00432_AllOOneDataStructure, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<string> expected = v1[i];

        // Actual
        vector<string> actual = _00432_AllOOneDataStructure(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_00432_AllOOneDataStructure0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<string> expected = v1[i];

        // Actual
        vector<string> actual = _00432_AllOOneDataStructure0(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
