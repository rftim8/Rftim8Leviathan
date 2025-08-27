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

// Binary Search
static int _03097_ShortestSubarrayWithORAtLeastKII(vector<int> &nums, int k);
// Sliding Window
static int _03097_ShortestSubarrayWithORAtLeastKII0(vector<int> &nums, int k);
// Speed
static int _03097_ShortestSubarrayWithORAtLeastKII1(vector<int> &nums, int k);

static int is_03097_ShortestSubarrayWithORAtLeastKII_RunTest();

/**
 * You are given an array nums of non-negative integers and an integer k.
 * An array is called special if the bitwise OR of all of its elements is at least k.
 * Return the length of the shortest special non-empty subarray of nums,
 * or return -1 if no special subarray exists.
 *
 * Constraints:
 *
 * 1 <= nums.length <= 2 * 10^5
 * 0 <= nums[i] <= 10^9
 * 0 <= k <= 10^9
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_03097_ShortestSubarrayWithORAtLeastKII_RunTest();
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
        cout << _03097_ShortestSubarrayWithORAtLeastKII(v[i], v0[i]) << "\n";
        cout << _03097_ShortestSubarrayWithORAtLeastKII0(v[i], v0[i]) << "\n";
        cout << _03097_ShortestSubarrayWithORAtLeastKII1(v[i], v0[i]) << "\n";
    }
}

#pragma region Binary Search
static void updateBitCounts(vector<int> &bitCounts, int number, int delta)
{
    for (int bitPosition = 0; bitPosition < 32; bitPosition++)
    {
        if (((number >> bitPosition) & 1) != 0)
            bitCounts[bitPosition] += delta;
    }
}

static int convertBitCountsToNumber(vector<int> &bitCounts)
{
    int number = 0;

    for (int bitPosition = 0; bitPosition < 32; bitPosition++)
    {
        if (bitCounts[bitPosition] != 0)
            number |= 1 << bitPosition;
    }

    return number;
}

static bool hasValidSubarray(vector<int> &nums, int targetSum, int windowSize)
{
    int arrayLength = nums.size();
    vector<int> bitCounts(32, 0);

    for (int right = 0; right < arrayLength; right++)
    {
        updateBitCounts(bitCounts, nums[right], 1);

        if (right >= windowSize)
            updateBitCounts(bitCounts, nums[right - windowSize], -1);

        if (right >= windowSize - 1 && convertBitCountsToNumber(bitCounts) >= targetSum)
            return true;
    }

    return false;
}

static int _03097_ShortestSubarrayWithORAtLeastKII(vector<int> &nums, int k)
{
    int left = 1;
    int right = nums.size();
    int minLength = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (hasValidSubarray(nums, k, mid))
        {
            minLength = mid;
            right = mid - 1;
        }
        else
            left = mid + 1;
    }

    return minLength;
}
#pragma endregion

#pragma region Sliding Window
static int convertBitCountsToNumber(const vector<int> &bitCounts)
{
    int result = 0;

    for (int bitPosition = 0; bitPosition < 32; bitPosition++)
    {
        if (bitCounts[bitPosition] != 0)
            result |= 1 << bitPosition;
    }

    return result;
}

static int _03097_ShortestSubarrayWithORAtLeastKII0(vector<int> &nums, int k)
{
    int minLength = INT_MAX;
    int windowStart = 0;
    int windowEnd = 0;
    vector<int> bitCounts(32, 0);

    while (windowEnd < nums.size())
    {
        updateBitCounts(bitCounts, nums[windowEnd], 1);

        while (windowStart <= windowEnd && convertBitCountsToNumber(bitCounts) >= k)
        {
            minLength = min(minLength, windowEnd - windowStart + 1);
            updateBitCounts(bitCounts, nums[windowStart], -1);
            windowStart++;
        }

        windowEnd++;
    }

    return minLength == INT_MAX ? -1 : minLength;
}
#pragma endregion

static int _03097_ShortestSubarrayWithORAtLeastKII1(vector<int> &nums, int k)
{
    if (k == 0)
        return 1;
    
    int shortest = nums.size() + 1;
    int count[32] = {};
    int val = 0;
    int start = 0;
    
    for (int i = 0; i < nums.size(); ++i)
    {
        int num = nums[i];
        val |= num;
    
        for (int ibit = 0; num; ++ibit)
        {
            count[ibit] += num & 1;
            num >>= 1;
        }
    
        while (val >= k && start < nums.size())
        {
            shortest = min(shortest, i - start + 1);
            num = nums[start];
            ++start;
    
            for (int ibit = 0; num; ++ibit)
            {
                count[ibit] -= num & 1;
    
                if (count[ibit] == 0)
                    val &= ~(1 << ibit);
    
                num >>= 1;
            }
        }
    }

    return shortest == (nums.size() + 1) ? -1 : shortest;
}

#pragma region GTest
static int is_03097_ShortestSubarrayWithORAtLeastKII_RunTest()
{
    stringstream ss;
    ss << "*_03097_ShortestSubarrayWithORAtLeastKII.expected*"
       << ":"
       << "*_03097_ShortestSubarrayWithORAtLeastKII0.expected*"
       << ":"
       << "*_03097_ShortestSubarrayWithORAtLeastKII1.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_03097_ShortestSubarrayWithORAtLeastKII, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v1[i];

        // Actual
        int actual = _03097_ShortestSubarrayWithORAtLeastKII(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_03097_ShortestSubarrayWithORAtLeastKII0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v1[i];

        // Actual
        int actual = _03097_ShortestSubarrayWithORAtLeastKII0(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_03097_ShortestSubarrayWithORAtLeastKII1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v1[i];

        // Actual
        int actual = _03097_ShortestSubarrayWithORAtLeastKII1(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
