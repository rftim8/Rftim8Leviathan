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

// Memoization
static vector<int> _00689_MaximumSumOf3NonOverlappingSubarrays(vector<int> &nums, int k);
// Tabulation
static vector<int> _00689_MaximumSumOf3NonOverlappingSubarrays0(vector<int> &nums, int k);
// Three Pointers
static vector<int> _00689_MaximumSumOf3NonOverlappingSubarrays1(vector<int> &nums, int k);

static int is_00689_MaximumSumOf3NonOverlappingSubarrays_RunTest();

/**
 * Given an integer array nums and an integer k, find three non-overlapping subarrays of length k with
 * maximum sum and return them.
 * Return the result as a list of indices representing the starting position of each interval (0-indexed).
 * If there are multiple answers, return the lexicographically smallest one.
 * Constraints:
 *
 * 1 <= nums.length <= 2 * 10^4
 * 1 <= nums[i] < 216
 * 1 <= k <= floor(nums.length / 3)
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_00689_MaximumSumOf3NonOverlappingSubarrays_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<vector<int>> v, v1;
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

        s = "";
        getline(cin, s);
        ss.clear();
        ss.str(s);
        t = "";
        d = {};
        while (getline(ss, t, ','))
        {
            d.push_back(stoi(t));
        }
        v1.push_back(d);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        vector<int> res = _00689_MaximumSumOf3NonOverlappingSubarrays(v[i], v0[i]);
        for (auto &&j : res)
        {
            cout << j << " ";
        }
        cout << "\n";

        vector<int> res0 = _00689_MaximumSumOf3NonOverlappingSubarrays0(v[i], v0[i]);
        for (auto &&j : res0)
        {
            cout << j << " ";
        }
        cout << "\n";

        vector<int> res1 = _00689_MaximumSumOf3NonOverlappingSubarrays1(v[i], v0[i]);
        for (auto &&j : res1)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
}

#pragma region Memoization
static int dp(vector<int> &sums, int k, int idx, int rem, vector<vector<int>> &memo)
{
    if (rem == 0)
        return 0;

    if (idx >= sums.size())
        return rem > 0 ? INT_MIN : 0;

    if (memo[idx][rem] != -1)
        return memo[idx][rem];

    int withCurrent = sums[idx] + dp(sums, k, idx + k, rem - 1, memo);
    int skipCurrent = dp(sums, k, idx + 1, rem, memo);
    memo[idx][rem] = max(withCurrent, skipCurrent);

    return memo[idx][rem];
}

static void dfs(vector<int> &sums, int k, int idx, int rem, vector<vector<int>> &memo, vector<int> &indices)
{
    if (rem == 0)
        return;

    if (idx >= sums.size())
        return;

    int withCurrent = sums[idx] + dp(sums, k, idx + k, rem - 1, memo);
    int skipCurrent = dp(sums, k, idx + 1, rem, memo);

    if (withCurrent >= skipCurrent)
    {
        indices.push_back(idx);
        dfs(sums, k, idx + k, rem - 1, memo, indices);
    }
    else
        dfs(sums, k, idx + 1, rem, memo, indices);
}

static vector<int> _00689_MaximumSumOf3NonOverlappingSubarrays(vector<int> &nums, int k)
{
    int n = nums.size() - k + 1;
    vector<int> sums(n);
    int windowSum = 0;

    for (int i = 0; i < k; i++)
    {
        windowSum += nums[i];
    }

    sums[0] = windowSum;

    for (int i = k; i < nums.size(); i++)
    {
        windowSum = windowSum - nums[i - k] + nums[i];
        sums[i - k + 1] = windowSum;
    }

    vector<vector<int>> memo(n, vector<int>(4, -1));
    vector<int> indices;
    dp(sums, k, 0, 3, memo);
    dfs(sums, k, 0, 3, memo, indices);

    return indices;
}
#pragma endregion

#pragma region Tabulation
static vector<int> _00689_MaximumSumOf3NonOverlappingSubarrays0(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> prefixSum(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
    }

    vector<vector<int>> bestSum(4, vector<int>(n + 1, 0));
    vector<vector<int>> bestIndex(4, vector<int>(n + 1, 0));

    for (int subarrayCount = 1; subarrayCount <= 3; subarrayCount++)
    {
        for (int endIndex = k * subarrayCount; endIndex <= n; endIndex++)
        {
            int currentSum = prefixSum[endIndex] - prefixSum[endIndex - k] + bestSum[subarrayCount - 1][endIndex - k];

            if (currentSum > bestSum[subarrayCount][endIndex - 1])
            {
                bestSum[subarrayCount][endIndex] = currentSum;
                bestIndex[subarrayCount][endIndex] = endIndex - k;
            }
            else
            {
                bestSum[subarrayCount][endIndex] = bestSum[subarrayCount][endIndex - 1];
                bestIndex[subarrayCount][endIndex] = bestIndex[subarrayCount][endIndex - 1];
            }
        }
    }

    vector<int> result(3, 0);
    int currentEnd = n;

    for (int subarrayIndex = 3; subarrayIndex >= 1; subarrayIndex--)
    {
        result[subarrayIndex - 1] = bestIndex[subarrayIndex][currentEnd];
        currentEnd = result[subarrayIndex - 1];
    }

    return result;
}
#pragma endregion

#pragma region Three Pointers
static vector<int> _00689_MaximumSumOf3NonOverlappingSubarrays1(vector<int> &nums, int k)
{
    int n = nums.size();
    int maxSum = 0;
    vector<int> prefixSum(n + 1);

    for (int i = 0; i < n; i++)
    {
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    }

    vector<int> leftMaxIndex(n);
    vector<int> rightMaxIndex(n);
    vector<int> result(3);

    for (int i = k, currentMaxSum = prefixSum[k] - prefixSum[0]; i < n; i++)
    {
        if (prefixSum[i + 1] - prefixSum[i + 1 - k] > currentMaxSum)
        {
            leftMaxIndex[i] = i + 1 - k;
            currentMaxSum = prefixSum[i + 1] - prefixSum[i + 1 - k];
        }
        else
            leftMaxIndex[i] = leftMaxIndex[i - 1];
    }

    rightMaxIndex[n - k] = n - k;

    for (int i = n - k - 1, currentMaxSum = prefixSum[n] - prefixSum[n - k]; i >= 0; i--)
    {
        if (prefixSum[i + k] - prefixSum[i] >= currentMaxSum)
        {
            rightMaxIndex[i] = i;
            currentMaxSum = prefixSum[i + k] - prefixSum[i];
        }
        else
            rightMaxIndex[i] = rightMaxIndex[i + 1];
    }

    for (int i = k; i <= n - 2 * k; i++)
    {
        int leftIndex = leftMaxIndex[i - 1];
        int rightIndex = rightMaxIndex[i + k];
        int totalSum = (prefixSum[i + k] - prefixSum[i]) + (prefixSum[leftIndex + k] - prefixSum[leftIndex]) + (prefixSum[rightIndex + k] - prefixSum[rightIndex]);

        if (totalSum > maxSum)
        {
            maxSum = totalSum;
            result[0] = leftIndex;
            result[1] = i;
            result[2] = rightIndex;
        }
    }

    return result;
}
#pragma endregion

#pragma region GTest
static int is_00689_MaximumSumOf3NonOverlappingSubarrays_RunTest()
{
    stringstream ss;
    ss << "*_00689_MaximumSumOf3NonOverlappingSubarrays.expected*"
       << ":"
       << "*_00689_MaximumSumOf3NonOverlappingSubarrays0.expected*"
       << ":"
       << "*_00689_MaximumSumOf3NonOverlappingSubarrays1.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_00689_MaximumSumOf3NonOverlappingSubarrays, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<int> expected = v1[i];

        // Actual
        vector<int> actual = _00689_MaximumSumOf3NonOverlappingSubarrays(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_00689_MaximumSumOf3NonOverlappingSubarrays0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<int> expected = v1[i];

        // Actual
        vector<int> actual = _00689_MaximumSumOf3NonOverlappingSubarrays0(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_00689_MaximumSumOf3NonOverlappingSubarrays1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<int> expected = v1[i];

        // Actual
        vector<int> actual = _00689_MaximumSumOf3NonOverlappingSubarrays1(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
