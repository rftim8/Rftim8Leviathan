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

// LeetCode problem
static vector<vector<int>> _00040_CombinationSumII(vector<int> &candidates, int target);
// LeetCode problem
static vector<vector<int>> _00040_CombinationSumII0(vector<int> &candidates, int target);

static int is_00040_CombinationSumII_RunTest();

/**
 * Given a collection of candidate numbers (candidates) and a target number (target),
 * find all unique combinations in candidates where the candidate numbers sum to target.
 * Each number in candidates may only be used once in the combination.
 * Note: The solution set must not contain duplicate combinations.
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_00040_CombinationSumII_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<vector<int>> v;
static vector<int> v0;
static vector<vector<vector<int>>> v1;

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
        string t = "";
        vector<int> vv = {};
        while (getline(ss, t, ','))
        {
            vv.push_back(stoi(t));
        }
        v.push_back(vv);

        int s0;
        cin >> s0;
        cin.get();
        v0.push_back(s0);

        string s1;
        getline(cin, s1);
        v1.push_back(stringTo2DVectorInt(s1));
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        vector<vector<int>> res = _00040_CombinationSumII(v[i], v0[i]);
        for (auto &&j : res)
        {
            for (auto &&k : j)
            {
                cout << k << " ";
            }
            cout << "\n";
        }

        vector<vector<int>> res0 = _00040_CombinationSumII0(v[i], v0[i]);
        for (auto &&j : res0)
        {
            for (auto &&k : j)
            {
                cout << k << " ";
            }
            cout << "\n";
        }
    }
}

static void backtracking(vector<int> candidates, int target, int start, vector<int> list, vector<vector<int>> &x)
{
    if (target < 0)
        return;
    else if (target == 0)
    {
        x.push_back(vector<int>(list));
        return;
    }
    else
    {
        for (int i = start; i < candidates.size(); i++)
        {
            if (i > start && candidates[i] == candidates[i - 1])
                continue;

            list.push_back(candidates[i]);
            backtracking(candidates, target - candidates[i], i + 1, list, x);
            list.pop_back();
        }
    }
}

static vector<vector<int>> _00040_CombinationSumII(vector<int> &candidates, int target)
{
    vector<vector<int>> x = {};
    sort(candidates.begin(), candidates.end());

    backtracking(candidates, target, 0, vector<int>(), x);

    return x;
}

static void backtrack(vector<int> &candidates, int &sum, vector<vector<int>> &output, vector<int> &ans, int i, int target)
{

    if (sum == target)
    {
        output.push_back(ans);
        return;
    }

    if (i >= candidates.size() ||
        sum + candidates[i] > target)
        return;

    sum += candidates[i];
    ans.push_back(candidates[i]);
    backtrack(candidates, sum, output, ans, i + 1, target);
    ans.pop_back();
    sum -= candidates[i];

    while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1])
        i++;

    backtrack(candidates, sum, output, ans, i + 1, target);
}

static vector<vector<int>> _00040_CombinationSumII0(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> output;
    vector<int> ans;
    int sum = 0;

    backtrack(candidates, sum, output, ans, 0, target);

    return output;
}

#pragma region GTest
static int is_00040_CombinationSumII_RunTest()
{
    stringstream ss;
    ss << "*_00040_CombinationSumII.expected*"
       << ":"
       << "*_00040_CombinationSumII0.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_00040_CombinationSumII, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<vector<int>> expected = v1[i];

        // Act
        vector<vector<int>> actual = _00040_CombinationSumII(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_00040_CombinationSumII0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<vector<int>> expected = v1[i];

        // Act
        vector<vector<int>> actual = _00040_CombinationSumII0(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
