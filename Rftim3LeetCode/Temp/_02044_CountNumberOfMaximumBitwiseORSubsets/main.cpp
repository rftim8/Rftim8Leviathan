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

// Recursion
static int _02044_CountNumberOfMaximumBitwiseORSubsets(vector<int> &nums);
// Memoization
static int _02044_CountNumberOfMaximumBitwiseORSubsets0(vector<int> &nums);
// Bit Manipulation
static int _02044_CountNumberOfMaximumBitwiseORSubsets1(vector<int> &nums);
// Bit Manipulation + DP
static int _02044_CountNumberOfMaximumBitwiseORSubsets2(vector<int> &nums);

static int is_02044_CountNumberOfMaximumBitwiseORSubsets_RunTest();

/**
 * Given an integer array nums, find the maximum possible bitwise OR of a subset of nums and return
 * the number of different non-empty subsets with the maximum bitwise OR.
 * An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b.
 * Two subsets are considered different if the indices of the elements chosen are different.
 * The bitwise OR of an array a is equal to a[0] OR a[1] OR ... OR a[a.length - 1] (0-indexed).
 *
 * Constraints:
 *
 * 1 <= nums.length <= 16
 * 1 <= nums[i] <= 10^5
 */
int main()
{
    offline();
    dataCollector();

    solve();
    return 0;

    ::testing::InitGoogleTest();
    is_02044_CountNumberOfMaximumBitwiseORSubsets_RunTest();
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
        cout << _02044_CountNumberOfMaximumBitwiseORSubsets(v[i]) << "\n";
        cout << _02044_CountNumberOfMaximumBitwiseORSubsets0(v[i]) << "\n";
        cout << _02044_CountNumberOfMaximumBitwiseORSubsets1(v[i]) << "\n";
        cout << _02044_CountNumberOfMaximumBitwiseORSubsets2(v[i]) << "\n";
    }
}

static int countSubsets(vector<int> &nums, int index, int currentOr, int targetOr)
{
    if (index == nums.size())
        return (currentOr == targetOr) ? 1 : 0;

    int countWithout = countSubsets(nums, index + 1, currentOr, targetOr);
    int countWith = countSubsets(nums, index + 1, currentOr | nums[index], targetOr);

    return countWithout + countWith;
}

static int _02044_CountNumberOfMaximumBitwiseORSubsets(vector<int> &nums)
{
    int maxOrValue = 0;

    for (int num : nums)
    {
        maxOrValue |= num;
    }

    return countSubsets(nums, 0, 0, maxOrValue);
}

static int countSubsetsRecursive(vector<int> &nums, int index, int currentOr, int targetOr, vector<vector<int>> &memo)
{
    if (index == nums.size())
        return (currentOr == targetOr) ? 1 : 0;

    if (memo[index][currentOr] != -1)
        return memo[index][currentOr];

    int countWithout = countSubsetsRecursive(nums, index + 1, currentOr, targetOr, memo);
    int countWith = countSubsetsRecursive(nums, index + 1, currentOr | nums[index], targetOr, memo);

    return memo[index][currentOr] = countWithout + countWith;
}

static int _02044_CountNumberOfMaximumBitwiseORSubsets0(vector<int> &nums)
{
    int n = nums.size();
    int maxOrValue = 0;

    for (int num : nums)
    {
        maxOrValue |= num;
    }

    vector<vector<int>> memo(n, vector<int>(maxOrValue + 1, -1));

    return countSubsetsRecursive(nums, 0, 0, maxOrValue, memo);
}

static int _02044_CountNumberOfMaximumBitwiseORSubsets1(vector<int> &nums)
{
    int maxOrValue = 0;

    for (int num : nums)
    {
        maxOrValue |= num;
    }

    int totalSubsets = 1 << nums.size();
    int subsetsWithMaxOr = 0;

    for (int subsetMask = 0; subsetMask < totalSubsets; subsetMask++)
    {
        int currentOrValue = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (((subsetMask >> i) & 1) == 1)
                currentOrValue |= nums[i];
        }

        if (currentOrValue == maxOrValue)
            subsetsWithMaxOr++;
    }

    return subsetsWithMaxOr;
}

static int _02044_CountNumberOfMaximumBitwiseORSubsets2(vector<int> &nums)
{
    int max = 0;
    vector<int> dp(1 << 17, 0);
    dp[0] = 1;

    for (int num : nums)
    {
        for (int i = max; i >= 0; i--)
        {
            dp[i | num] += dp[i];
        }

        max |= num;
    }

    return dp[max];
}

#pragma region GTest
static int is_02044_CountNumberOfMaximumBitwiseORSubsets_RunTest()
{
    stringstream ss;
    ss << "*_02044_CountNumberOfMaximumBitwiseORSubsets.expected*"
       << ":"
       << "*_02044_CountNumberOfMaximumBitwiseORSubsets0.expected*"
       << ":"
       << "*_02044_CountNumberOfMaximumBitwiseORSubsets1.expected*"
       << ":"
       << "*_02044_CountNumberOfMaximumBitwiseORSubsets2.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_02044_CountNumberOfMaximumBitwiseORSubsets, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _02044_CountNumberOfMaximumBitwiseORSubsets(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02044_CountNumberOfMaximumBitwiseORSubsets0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _02044_CountNumberOfMaximumBitwiseORSubsets0(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02044_CountNumberOfMaximumBitwiseORSubsets1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _02044_CountNumberOfMaximumBitwiseORSubsets1(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02044_CountNumberOfMaximumBitwiseORSubsets2, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _02044_CountNumberOfMaximumBitwiseORSubsets2(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
