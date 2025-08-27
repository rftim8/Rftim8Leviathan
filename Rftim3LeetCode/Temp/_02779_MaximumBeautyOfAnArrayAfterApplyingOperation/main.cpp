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
static int _02779_MaximumBeautyOfAnArrayAfterApplyingOperation(vector<int> &nums, int k);
// Sliding Window
static int _02779_MaximumBeautyOfAnArrayAfterApplyingOperation0(vector<int> &nums, int k);
// Line Sweep
static int _02779_MaximumBeautyOfAnArrayAfterApplyingOperation1(vector<int> &nums, int k);
// Speed
static int _02779_MaximumBeautyOfAnArrayAfterApplyingOperation2(vector<int> &nums, int k);

static int is_02779_MaximumBeautyOfAnArrayAfterApplyingOperation_RunTest();

/**
 * You are given a 0-indexed array nums and a non-negative integer k.
 * In one operation, you can do the following:
 * Choose an index i that hasn't been chosen before from the range [0, nums.length - 1].
 * Replace nums[i] with any integer from the range [nums[i] - k, nums[i] + k].
 * The beauty of the array is the length of the longest subsequence consisting of equal elements.
 * Return the maximum possible beauty of the array nums after applying the operation any number of times.
 * Note that you can apply the operation to each index only once.
 * A subsequence of an array is a new array generated from the original array by deleting some elements (possibly none)
 * without changing the order of the remaining elements.
 *
 * Constraints:
 *
 * 1 <= nums.length <= 10^5
 * 0 <= nums[i], k <= 10^5
 */
int main()
{
    offline();
    dataCollector();

    solve();
    return 0;

    ::testing::InitGoogleTest();
    is_02779_MaximumBeautyOfAnArrayAfterApplyingOperation_RunTest();
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
        cout << _02779_MaximumBeautyOfAnArrayAfterApplyingOperation(v[i], v0[i]) << "\n";
        cout << _02779_MaximumBeautyOfAnArrayAfterApplyingOperation0(v[i], v0[i]) << "\n";
        cout << _02779_MaximumBeautyOfAnArrayAfterApplyingOperation1(v[i], v0[i]) << "\n";
        cout << _02779_MaximumBeautyOfAnArrayAfterApplyingOperation2(v[i], v0[i]) << "\n";
    }
}

#pragma region Binary Search
static int findUpperBound(vector<int> &arr, int val)
{
    int low = 0, high = arr.size() - 1, result = 0;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] <= val)
        {
            result = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    return result;
}

static int _02779_MaximumBeautyOfAnArrayAfterApplyingOperation(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    int maxBeauty = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        int upperBound = findUpperBound(nums, nums[i] + 2 * k);
        maxBeauty = max(maxBeauty, upperBound - i + 1);
    }

    return maxBeauty;
}
#pragma endregion

static int _02779_MaximumBeautyOfAnArrayAfterApplyingOperation0(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    int right = 0;
    int maxBeauty = 0;

    for (int left = 0; left < nums.size(); left++)
    {
        while (right < nums.size() && nums[right] - nums[left] <= 2 * k)
        {
            right++;
        }

        maxBeauty = max(maxBeauty, right - left);
    }

    return maxBeauty;
}

static int _02779_MaximumBeautyOfAnArrayAfterApplyingOperation1(vector<int> &nums, int k)
{
    if (nums.size() == 1)
        return 1;

    int maxBeauty = 0;
    int maxValue = 0;

    for (int num : nums)
        maxValue = max(maxValue, num);

    vector<int> count(maxValue + 1, 0);

    for (int num : nums)
    {
        count[max(num - k, 0)]++;

        if (num + k + 1 <= maxValue)
            count[num + k + 1]--;
    }

    int currentSum = 0;

    for (int val : count)
    {
        currentSum += val;
        maxBeauty = max(maxBeauty, currentSum);
    }

    return maxBeauty;
}

static int _02779_MaximumBeautyOfAnArrayAfterApplyingOperation2(vector<int> &nums, int k)
{
    int m = *max_element(nums.begin(), nums.end()) + k * 2 + 2;
    vector<int> d(m);

    for (int x : nums)
    {
        d[x]++;
        d[x + k * 2 + 1]--;
    }

    int ans = 0, s = 0;

    for (int x : d)
    {
        s += x;
        ans = max(ans, s);
    }

    return ans;
}

#pragma region GTest
static int is_02779_MaximumBeautyOfAnArrayAfterApplyingOperation_RunTest()
{
    stringstream ss;
    ss << "*_02779_MaximumBeautyOfAnArrayAfterApplyingOperation.expected*"
       << ":"
       << "*_02779_MaximumBeautyOfAnArrayAfterApplyingOperation0.expected*"
       << ":"
       << "*_02779_MaximumBeautyOfAnArrayAfterApplyingOperation1.expected*"
       << ":"
       << "*_02779_MaximumBeautyOfAnArrayAfterApplyingOperation2.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_02779_MaximumBeautyOfAnArrayAfterApplyingOperation, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v1[i];

        // Actual
        int actual = _02779_MaximumBeautyOfAnArrayAfterApplyingOperation(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02779_MaximumBeautyOfAnArrayAfterApplyingOperation0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v1[i];

        // Actual
        int actual = _02779_MaximumBeautyOfAnArrayAfterApplyingOperation0(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02779_MaximumBeautyOfAnArrayAfterApplyingOperation1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v1[i];

        // Actual
        int actual = _02779_MaximumBeautyOfAnArrayAfterApplyingOperation1(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02779_MaximumBeautyOfAnArrayAfterApplyingOperation2, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v1[i];

        // Actual
        int actual = _02779_MaximumBeautyOfAnArrayAfterApplyingOperation2(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
