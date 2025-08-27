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

// Brute Force
static int _00494_TargetSum(vector<int> &nums, int target);
// Recursion With Memoization
static int _00494_TargetSum0(vector<int> &nums, int target);
// 2D DP
static int _00494_TargetSum1(vector<int> &nums, int target);
// Speed
static int _00494_TargetSum2(vector<int> &nums, int target);

static int is_00494_TargetSum_RunTest();

/**
 * You are given an integer array nums and an integer target.
 * You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer
 * in nums and then concatenate all the integers.
 * For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them
 * to build the expression "+2-1".
 * Return the number of different expressions that you can build, which evaluates to target.
 *
 * Constraints:
 *
 * 1 <= nums.length <= 20
 * 0 <= nums[i] <= 1000
 * 0 <= sum(nums[i]) <= 1000
 * -1000 <= target <= 1000
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_00494_TargetSum_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<vector<int>> v;
static vector<int> v0, v1;

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
        v0.push_back(s0);

        cin >> s0;
        cin.get();
        v1.push_back(s0);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        cout << _00494_TargetSum(v[i], v0[i]) << "\n";
        cout << _00494_TargetSum0(v[i], v0[i]) << "\n";
        cout << _00494_TargetSum1(v[i], v0[i]) << "\n";
        cout << _00494_TargetSum2(v[i], v0[i]) << "\n";
    }
}

#pragma region Brute Force
static int totalWays;

static void calculateWays(std::vector<int> &nums, int currentIndex, int currentSum, int target)
{
    if (currentIndex == nums.size())
    {
        if (currentSum == target)
            totalWays++;
    }
    else
    {
        calculateWays(nums, currentIndex + 1, currentSum + nums[currentIndex], target);
        calculateWays(nums, currentIndex + 1, currentSum - nums[currentIndex], target);
    }
}

static int _00494_TargetSum(vector<int> &nums, int target)
{
    totalWays = 0;
    calculateWays(nums, 0, 0, target);
    return totalWays;
}
#pragma endregion

#pragma region Recursion With Memoization
static int totalSum;

static int calculateWays(vector<int> &nums, int currentIndex, int currentSum, int target, vector<vector<int>> &memo)
{
    if (currentIndex == nums.size())
    {
        if (currentSum == target)
            return 1;
        else
            return 0;
    }
    else
    {
        if (memo[currentIndex][currentSum + totalSum] != numeric_limits<int>::min())
            return memo[currentIndex][currentSum + totalSum];

        int add = calculateWays(nums, currentIndex + 1, currentSum + nums[currentIndex], target, memo);
        int subtract = calculateWays(nums, currentIndex + 1, currentSum - nums[currentIndex], target, memo);
        memo[currentIndex][currentSum + totalSum] = add + subtract;

        return memo[currentIndex][currentSum + totalSum];
    }
}

static int _00494_TargetSum0(vector<int> &nums, int target)
{
    totalSum = accumulate(nums.begin(), nums.end(), 0);
    vector<vector<int>> memo(nums.size(), vector<int>(2 * totalSum + 1, numeric_limits<int>::min()));

    return calculateWays(nums, 0, 0, target, memo);
}
#pragma endregion

#pragma region 2D DP
static int _00494_TargetSum1(vector<int> &nums, int target)
{
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    vector<vector<int>> dp(nums.size(), vector<int>(2 * totalSum + 1, 0));
    dp[0][nums[0] + totalSum] = 1;
    dp[0][-nums[0] + totalSum] += 1;

    for (int index = 1; index < nums.size(); index++)
    {
        for (int sum = -totalSum; sum <= totalSum; sum++)
        {
            if (dp[index - 1][sum + totalSum] > 0)
            {
                dp[index][sum + nums[index] + totalSum] += dp[index - 1][sum + totalSum];
                dp[index][sum - nums[index] + totalSum] += dp[index - 1][sum + totalSum];
            }
        }
    }

    return abs(target) > totalSum ? 0 : dp[nums.size() - 1][target + totalSum];
}
#pragma endregion

#pragma region Speed
static int _00494_TargetSum2(vector<int> &nums, int target)
{
    int n = nums.size();
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
    }

    if ((sum + target) % 2 != 0)
        return 0;

    if (abs(target) > abs(sum))
        return 0;

    int new_target = (sum + target) / 2;
    vector<vector<int>> t(n + 1, vector<int>(new_target + 1));

    for (int i = 1; i < new_target + 1; i++)
    {
        t[0][1] = 0;
    }

    t[0][0] = 1;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 0; j < new_target + 1; j++)
        {
            if (nums[i - 1] <= j)
                t[i][j] = t[i - 1][j - nums[i - 1]] + t[i - 1][j];
            else
                t[i][j] = t[i - 1][j];
        }
    }

    return t[n][new_target];
}
#pragma endregion

#pragma region GTest
static int is_00494_TargetSum_RunTest()
{
    stringstream ss;
    ss << "*_00494_TargetSum.expected*"
       << ":"
       << "*_00494_TargetSum0.expected*"
       << ":"
       << "*_00494_TargetSum1.expected*"
       << ":"
       << "*_00494_TargetSum2.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_00494_TargetSum, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v1[i];

        // Actual
        int actual = _00494_TargetSum(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_00494_TargetSum0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v1[i];

        // Actual
        int actual = _00494_TargetSum0(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_00494_TargetSum1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v1[i];

        // Actual
        int actual = _00494_TargetSum1(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_00494_TargetSum2, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v1[i];

        // Actual
        int actual = _00494_TargetSum2(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
