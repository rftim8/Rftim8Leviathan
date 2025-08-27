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

// Longest Increasing Subsequence DP
static int _01671_MinimumNumberOfRemovalsToMakeMountainArray(vector<int> &nums);
// Longest Increasing Subsequence Binary Search
static int _01671_MinimumNumberOfRemovalsToMakeMountainArray0(vector<int> &nums);

static int is_01671_MinimumNumberOfRemovalsToMakeMountainArray_RunTest();

/**
 * You may recall that an array arr is a mountain array if and only if:
 *
 * arr.length >= 3
 * There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
 * arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
 * arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
 * Given an integer array nums​​​, return the minimum number of elements to remove to make
 * nums​​​ a mountain array.
 *
 * Constraints:
 *
 * 3 <= nums.length <= 1000
 * 1 <= nums[i] <= 10^9
 * It is guaranteed that you can make a mountain array out of nums.
 */
int main()
{
    offline();
    dataCollector();

    solve();
    return 0;

    ::testing::InitGoogleTest();
    is_01671_MinimumNumberOfRemovalsToMakeMountainArray_RunTest();
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
        cout << _01671_MinimumNumberOfRemovalsToMakeMountainArray(v[i]) << "\n";
        cout << _01671_MinimumNumberOfRemovalsToMakeMountainArray0(v[i]) << "\n";
    }
}

static int _01671_MinimumNumberOfRemovalsToMakeMountainArray(vector<int> &nums)
{
    int N = nums.size();
    vector<int> lisLength(N, 1);
    vector<int> ldsLength(N, 1);

    for (int i = 0; i < N; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (nums[i] > nums[j])
                lisLength[i] = max(lisLength[i], lisLength[j] + 1);
        }
    }

    for (int i = N - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (nums[i] > nums[j])
                ldsLength[i] = max(ldsLength[i], ldsLength[j] + 1);
        }
    }

    int minRemovals = INT_MAX;

    for (int i = 0; i < N; i++)
    {
        if (lisLength[i] > 1 && ldsLength[i] > 1)
        {
            minRemovals =
                min(minRemovals, N - lisLength[i] - ldsLength[i] + 1);
        }
    }

    return minRemovals;
}

#pragma region LIS BS
static vector<int> getLongestIncreasingSubsequenceLength(vector<int> &v)
{
    vector<int> lisLen(v.size(), 1);
    vector<int> lis = {v[0]};

    for (int i = 1; i < v.size(); i++)
    {
        int index = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();

        if (index == lis.size())
            lis.push_back(v[i]);
        else
            lis[index] = v[i];

        lisLen[i] = lis.size();
    }

    return lisLen;
}

static int _01671_MinimumNumberOfRemovalsToMakeMountainArray0(vector<int> &nums)
{
    int N = nums.size();
    vector<int> lisLength = getLongestIncreasingSubsequenceLength(nums);
    reverse(nums.begin(), nums.end());
    vector<int> ldsLength = getLongestIncreasingSubsequenceLength(nums);
    reverse(ldsLength.begin(), ldsLength.end());
    int minRemovals = INT_MAX;

    for (int i = 0; i < N; i++)
    {
        if (lisLength[i] > 1 && ldsLength[i] > 1)
            minRemovals = min(minRemovals, N - lisLength[i] - ldsLength[i] + 1);
    }

    return minRemovals;
}
#pragma endregion

#pragma region GTest
static int is_01671_MinimumNumberOfRemovalsToMakeMountainArray_RunTest()
{
    stringstream ss;
    ss << "*_01671_MinimumNumberOfRemovalsToMakeMountainArray.expected*"
       << ":"
       << "*_01671_MinimumNumberOfRemovalsToMakeMountainArray0.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_01671_MinimumNumberOfRemovalsToMakeMountainArray, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _01671_MinimumNumberOfRemovalsToMakeMountainArray(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_01671_MinimumNumberOfRemovalsToMakeMountainArray0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _01671_MinimumNumberOfRemovalsToMakeMountainArray0(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
