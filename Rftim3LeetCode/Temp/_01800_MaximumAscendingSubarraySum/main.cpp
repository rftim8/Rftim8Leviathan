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
static int _01800_MaximumAscendingSubarraySum(vector<int> &nums);

static int is_01800_MaximumAscendingSubarraySum_RunTest();

/**
 * Given an array of positive integers nums, return the maximum possible sum of an ascending subarray in nums.
 * A subarray is defined as a contiguous sequence of numbers in an array.
 * A subarray [numsl, numsl+1, ..., numsr-1, numsr] is ascending if for all i where l <= i < r, numsi  < numsi+1.
 * Note that a subarray of size 1 is ascending.
 *
 * Constraints:
 *
 * 1 <= nums.length <= 100
 * 1 <= nums[i] <= 100
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_01800_MaximumAscendingSubarraySum_RunTest();
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
        cout << _01800_MaximumAscendingSubarraySum(v[i]) << "\n";
    }
}

static int _01800_MaximumAscendingSubarraySum(vector<int> &nums)
{
    int n = nums.size();
    int c = nums[0], r = c;

    for (int i = 1; i < n; i++)
    {
        if (nums[i] > nums[i - 1])
        {
            c += nums[i];
            if (i == n - 1)
                r = max(r, c);
        }
        else
        {
            r = max(r, c);
            c = nums[i];
        }
    }

    return r;
}

#pragma region GTest
static int is_01800_MaximumAscendingSubarraySum_RunTest()
{
    stringstream ss;
    ss << "*_01800_MaximumAscendingSubarraySum.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_01800_MaximumAscendingSubarraySum, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _01800_MaximumAscendingSubarraySum(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
