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

// Unordered Map With Sets  My submission
static vector<std::optional<int>> _02349_DesignANumberContainerSystem(vector<string> commands, vector<vector<int>> v);
// Runtime
static vector<std::optional<int>> _02349_DesignANumberContainerSystem_0(vector<string> commands, vector<vector<int>> v);
// Memory
static vector<std::optional<int>> _02349_DesignANumberContainerSystem_1(vector<string> commands, vector<vector<int>> v);

static int is_02349_DesignANumberContainerSystem_RunTest();

/**
 * Design a number container system that can do the following:
 * Insert or Replace a number at the given index in the system.
 * Return the smallest index for the given number in the system.
 *
 * Implement the NumberContainers class:
 *
 * NumberContainers() Initializes the number container system.
 * void change(int index, int number) Fills the container at index with the number.
 * If there is already a number at that index, replace it.
 * int find(int number) Returns the smallest index for the given number, or -1 if there is no index
 * that is filled by number in the system.
 *
 * Constraints:
 *
 * 1 <= index, number <= 10^9
 * At most 10^5 calls will be made in total to change and find.
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_02349_DesignANumberContainerSystem_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<vector<string>> v;
static vector<vector<vector<int>>> v0;
static vector<vector<std::optional<int>>> v1;

static vector<vector<int>> stringTo2DVectorInt(string s)
{
    vector<vector<int>> res = {};
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
        vector<int> a = {};
        string t;
        stringstream ss(j);
        while (getline(ss, t, ','))
        {
            if (t != "null" &&
                t != "")
                a.push_back(stoi(t));
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
        string t;
        vector<string> d = {};
        while (getline(ss, t, ','))
        {
            d.push_back(t);
        }
        v.push_back(d);

        s = "";
        getline(cin, s);
        v0.push_back(stringTo2DVectorInt(s));

        s = "";
        getline(cin, s);
        ss.clear();
        ss.str(s);
        t = "";
        vector<std::optional<int>> d0 = {};
        while (getline(ss, t, ','))
        {
            if (t != "null")
                d0.push_back(stoi(t));
            // else
            //     d0.push_back(std::nullopt);
        }
        v1.push_back(d0);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        vector<std::optional<int>> res = _02349_DesignANumberContainerSystem(v[i], v0[i]);
        for (auto &&j : res)
        {
            if (j)
                cout << j.value() << " ";
        }
        cout << "\n";

        vector<std::optional<int>> res0 = _02349_DesignANumberContainerSystem_0(v[i], v0[i]);
        for (auto &&j : res0)
        {
            if (j)
                cout << j.value() << " ";
        }
        cout << "\n";

        vector<std::optional<int>> res1 = _02349_DesignANumberContainerSystem_1(v[i], v0[i]);
        for (auto &&j : res1)
        {
            if (j)
                cout << j.value() << " ";
        }
        cout << "\n";
    }
}

#pragma region My Submission
class NumberContainers
{
public:
    unordered_map<int, int> um;
    unordered_map<int, set<int>> num;

    NumberContainers()
    {
        um = {};
        num = {};
    }

    void change(int index, int number)
    {
        if (num.find(um[index]) != num.end())
            num[um[index]].erase(index);

        um[index] = number;
        num[number].insert(index);
    }

    int find(int number)
    {
        int res = -1;

        if (num.find(number) != num.end())
            if (!num[number].empty())
                res = *num[number].begin();

        return res;
    }
};

static vector<std::optional<int>> _02349_DesignANumberContainerSystem(vector<string> commands, vector<vector<int>> v)
{
    vector<std::optional<int>> res = {};

    NumberContainers *obj = new NumberContainers();

    for (int i = 1; i < commands.size(); i++)
    {
        if (commands[i] == "find")
        {
            std::optional<int> param = obj->find(v[i][0]);
            res.push_back(param);
        }
        else if (commands[i] == "change")
            obj->change(v[i][0], v[i][1]);
    }

    return res;
}
#pragma endregion

#pragma region Runtime
class NumberContainers0
{
public:
    void change(int index, int number)
    {
        entries[index] = number;
        number_to_indexes[number].push(index);
    }

    int find(int number)
    {
        if (auto find_it = number_to_indexes.find(number); find_it == end(number_to_indexes))
            return -1;
        else
        {
            auto &q = find_it->second;

            while (!empty(q) && entries[q.top()] != number)
                q.pop();

            return empty(q) ? -1 : q.top();
        }
    }

private:
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> number_to_indexes;
    unordered_map<int, int> entries;
};

static vector<std::optional<int>> _02349_DesignANumberContainerSystem_0(vector<string> commands, vector<vector<int>> v)
{
    vector<std::optional<int>> res = {};

    NumberContainers0 *obj = new NumberContainers0();

    for (int i = 1; i < commands.size(); i++)
    {
        if (commands[i] == "find")
        {
            std::optional<int> param = obj->find(v[i][0]);
            res.push_back(param);
        }
        else if (commands[i] == "change")
            obj->change(v[i][0], v[i][1]);
    }

    return res;
}
#pragma endregion

#pragma region Memory
class NumberContainers1
{
public:
    map<int, int> vec;
    unordered_map<int, int> idxMap;
    NumberContainers1() {}

    void change(int idx, int number)
    {
        int temp;
        bool tempset = false;

        if (vec.find(idx) != vec.end())
        {
            temp = vec[idx];
            tempset = true;
        }

        vec[idx] = number;

        if (tempset)
        {
            for (auto [k, v] : vec)
            {
                if (v == temp)
                {
                    idxMap[v] = k;
                    break;
                }
            }

            if (idxMap[temp] == idx)
                idxMap.erase(temp);
        }

        if (idxMap.find(number) == idxMap.end() || idx < idxMap[number])
            idxMap[number] = idx;
    }

    int find(int number)
    {
        if (idxMap.find(number) == idxMap.end())
            return -1;

        return idxMap[number];
    }
};

static vector<std::optional<int>> _02349_DesignANumberContainerSystem_1(vector<string> commands, vector<vector<int>> v)
{
    vector<std::optional<int>> res = {};

    NumberContainers1 *obj = new NumberContainers1();

    for (int i = 1; i < commands.size(); i++)
    {
        if (commands[i] == "find")
        {
            std::optional<int> param = obj->find(v[i][0]);
            res.push_back(param);
        }
        else if (commands[i] == "change")
            obj->change(v[i][0], v[i][1]);
    }

    return res;
}
#pragma endregion

#pragma region GTest
static int is_02349_DesignANumberContainerSystem_RunTest()
{
    stringstream ss;
    ss << "*_02349_DesignANumberContainerSystem.expected*"
       << ":"
       << "*_02349_DesignANumberContainerSystem_0.expected*"
       << ":"
       << "*_02349_DesignANumberContainerSystem_1.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_02349_DesignANumberContainerSystem, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<std::optional<int>> expected = v1[i];

        // Actual
        vector<std::optional<int>> actual = _02349_DesignANumberContainerSystem(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02349_DesignANumberContainerSystem_0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<std::optional<int>> expected = v1[i];

        // Actual
        vector<std::optional<int>> actual = _02349_DesignANumberContainerSystem_0(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02349_DesignANumberContainerSystem_1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<std::optional<int>> expected = v1[i];

        // Actual
        vector<std::optional<int>> actual = _02349_DesignANumberContainerSystem_1(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
