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

// Sliding Window
static long long _02461_MaximumSumOfDistinctSubarraysWithLengthK(vector<int> &nums, int k);

static int is_02461_MaximumSumOfDistinctSubarraysWithLengthK_RunTest();

/**
 * You are given an integer array nums and an integer k.
 * Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:
 * The length of the subarray is k, and
 * All the elements of the subarray are distinct.
 * Return the maximum subarray sum of all the subarrays that meet the conditions.
 * If no subarray meets the conditions, return 0.
 * A subarray is a contiguous non-empty sequence of elements within an array.
 *
 * Constraints:
 *
 * 1 <= k <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^5
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_02461_MaximumSumOfDistinctSubarraysWithLengthK_RunTest();
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
        cout << _02461_MaximumSumOfDistinctSubarraysWithLengthK(v[i], v0[i]) << "\n";
    }
}

static long long _02461_MaximumSumOfDistinctSubarraysWithLengthK(vector<int> &nums, int k)
{
    long long ans = 0;
    long long currentSum = 0;
    int begin = 0;
    int end = 0;

    unordered_map<int, int> numToIndex;

    while (end < nums.size())
    {
        int currNum = nums[end];
        int lastOccurrence = (numToIndex.count(currNum) ? numToIndex[currNum] : -1);

        while (begin <= lastOccurrence || end - begin + 1 > k)
        {
            currentSum -= nums[begin];
            begin++;
        }
    
        numToIndex[currNum] = end;
        currentSum += nums[end];
    
        if (end - begin + 1 == k)
            ans = max(ans, currentSum);
    
        end++;
    }

    return ans;
}

#pragma region GTest
static int is_02461_MaximumSumOfDistinctSubarraysWithLengthK_RunTest()
{
    stringstream ss;
    ss << "*_02461_MaximumSumOfDistinctSubarraysWithLengthK.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_02461_MaximumSumOfDistinctSubarraysWithLengthK, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        long long expected = v1[i];

        // Actual
        long long actual = _02461_MaximumSumOfDistinctSubarraysWithLengthK(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
