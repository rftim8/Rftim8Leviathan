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

// LeetCode problem - Memory
static vector<int> _00001_TwoSum(vector<int> &nums, int target);
// Speed
static vector<int> _00001_TwoSum0(vector<int> &nums, int target);

static int is_00001_TwoSum_RunTest();

/**
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * You can return the answer in any order.
 *
 * Constraints:
 *
 * 2 <= nums.length <= 10^4
 * -10^9 <= nums[i] <= 10^9
 * -10^9 <= target <= 10^9
 * Only one valid answer exists.

 * Follow-up: Can you come up with an algorithm that is less than O(n^2) time complexity?
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_00001_TwoSum_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<vector<int>> v;
static vector<int> v0;
static vector<vector<int>> v1;

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

        int s0;
        cin >> s0;
        cin.get();
        v0.push_back(s0);

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
        v1.push_back(vv);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        vector<int> res = _00001_TwoSum(v[i], v0[i]);
        for (auto &&j : res)
        {
            cout << j << " ";
        }
        cout << "\n";

        vector<int> res0 = _00001_TwoSum0(v[i], v0[i]);
        for (auto &&j : res0)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
}

static vector<int> _00001_TwoSum(vector<int> &nums, int target)
{
    vector<int> res = {};
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                res.push_back(i);
                res.push_back(j);

                return res;
            }
        }
    }

    return res;
}

static vector<int> _00001_TwoSum0(vector<int> &nums, int target)
{
    unordered_map<int, int> mp;

    int n = nums.size();
    for (int i = 0; i < n; ++i)
    {
        int pair = target - nums[i];
        if (mp.find(pair) != mp.end())
        {
            return {mp[pair], i};
        }
        mp[nums[i]] = i;
    }

    return {};
}

#pragma region GTest
static int is_00001_TwoSum_RunTest()
{
    stringstream ss;
    ss << "*_00001_TwoSum.expected*"
       << ":"
       << "*_00001_TwoSum0.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();   
    return 0;
}

TEST(_00001_TwoSum, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<int> expected = v1[i];

        // Actual
        vector<int> actual = _00001_TwoSum(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_00001_TwoSum0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<int> expected = v1[i];

        // Actual
        vector<int> actual = _00001_TwoSum0(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
