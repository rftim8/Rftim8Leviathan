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
static vector<vector<int>> _00078_Subsets(vector<int> &nums);
// LeetCode problem
static vector<vector<int>> _00078_Subsets0(vector<int> &nums);
// LeetCode problem
static vector<vector<int>> _00078_Subsets1(vector<int> &nums);

static int is_00078_Subsets_RunTest();

/**
 * Given an integer array nums of unique elements, return all possible subsets (the power set).
 * The solution set must not contain duplicate subsets. Return the solution in any order.
 *
 * Constraints:
 *
 * 1 <= nums.length <= 10
 * -10 <= nums[i] <= 10
 * All the numbers of nums are unique.
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_00078_Subsets_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<vector<int>> v;
static vector<vector<vector<int>>> v0;

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
        vector<int> vv = {};
        while (getline(ss, t, ','))
        {
            vv.push_back(stoi(t));
        }
        v.push_back(vv);

        s = "";
        getline(cin, s);
        v0.push_back(stringTo2DVectorInt(s));
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        vector<vector<int>> res = _00078_Subsets(v[i]);
        sort(res.begin(), res.end());
        for (auto &&j : res)
        {
            for (auto &&k : j)
            {
                cout << k << " ";
            }
            cout << "\n";
        }
 
        vector<vector<int>> res0 = _00078_Subsets0(v[i]);
        sort(res0.begin(), res0.end());
        for (auto &&j : res0)
        {
            for (auto &&k : j)
            {
                cout << k << " ";
            }
            cout << "\n";
        }
 
        vector<vector<int>> res1 = _00078_Subsets1(v[i]);
        sort(res1.begin(), res1.end());
        for (auto &&j : res1)
        {
            for (auto &&k : j)
            {
                cout << k << " ";
            }
            cout << "\n";
        }
    }
}

static vector<vector<int>> _00078_Subsets(vector<int> &nums)
{
    vector<vector<int>> x = {};
    x.push_back(vector<int>());

    for (auto &&i : nums)
    {
        vector<vector<int>> y = {};

        for (auto &&j : x)
        {
            vector<int> v = {j};
            v.push_back(i);
            y.push_back(v);
        }

        for (auto &&j : y)
        {
            x.push_back(j);
        }
    }

    return x;
}

static void subs(vector<int> &nums, vector<vector<int>> &finans, vector<int> &ans, int i, int n)
{
    if (i >= n)
    {
        finans.push_back(ans);
 
        return;
    }

    ans.push_back(nums[i]);
    subs(nums, finans, ans, i + 1, n);
    ans.pop_back();
    subs(nums, finans, ans, i + 1, n);
}

static vector<vector<int>> _00078_Subsets0(vector<int> &nums)
{
    vector<vector<int>> finans;
    vector<int> ans;
    int n = nums.size();
    int i = 0;

    subs(nums, finans, ans, i, n);

    return finans;
}

static vector<vector<int>> _00078_Subsets1(vector<int> &nums)
{
    int n = 1 << (int)nums.size();
    vector<vector<int>> v;
    v.resize(n);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < nums.size(); ++j)
        {
            if ((i >> j) & 0b1)
                v[i].push_back(nums[j]);
        }
    }

    return v;
}

#pragma region GTest
static int is_00078_Subsets_RunTest()
{
    stringstream ss;
    ss << "*_00078_Subsets.expected*"
       << ":"
       << "*_00078_Subsets0.expected*"
       << ":"
       << "*_00078_Subsets1.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_00078_Subsets, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<vector<int>> expected = v0[i];
        sort(expected.begin(), expected.end());

        // Actual
        vector<vector<int>> actual = _00078_Subsets(v[i]);
        sort(actual.begin(), actual.end());

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_00078_Subsets0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<vector<int>> expected = v0[i];
        sort(expected.begin(), expected.end());

        // Actual
        vector<vector<int>> actual = _00078_Subsets0(v[i]);
        sort(actual.begin(), actual.end());

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_00078_Subsets1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<vector<int>> expected = v0[i];
        sort(expected.begin(), expected.end());

        // Actual
        vector<vector<int>> actual = _00078_Subsets1(v[i]);
        sort(actual.begin(), actual.end());

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
