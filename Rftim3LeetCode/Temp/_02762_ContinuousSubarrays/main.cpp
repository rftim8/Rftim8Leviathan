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

// Sorted Map
static long long _02762_ContinuousSubarrays(vector<int> &nums);
// Priority Queue
static long long _02762_ContinuousSubarrays0(vector<int> &nums);
// Monotonic Dequeue
static long long _02762_ContinuousSubarrays1(vector<int> &nums);
// Optimized Two Pointer
static long long _02762_ContinuousSubarrays2(vector<int> &nums);
// Speed
static long long _02762_ContinuousSubarrays3(vector<int> &nums);

static int is_02762_ContinuousSubarrays_RunTest();

/**
 * You are given a 0-indexed integer array nums. A subarray of nums is called continuous if:
 * Let i, i + 1, ..., j be the indices in the subarray.
 * Then, for each pair of indices i <= i1, i2 <= j, 0 <= |nums[i1] - nums[i2]| <= 2.
 * Return the total number of continuous subarrays.
 * A subarray is a contiguous non-empty sequence of elements within an array.
 *
 * Constraints:
 *
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^9
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_02762_ContinuousSubarrays_RunTest();
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
        cout << _02762_ContinuousSubarrays(v[i]) << "\n";
        cout << _02762_ContinuousSubarrays0(v[i]) << "\n";
        cout << _02762_ContinuousSubarrays1(v[i]) << "\n";
        cout << _02762_ContinuousSubarrays2(v[i]) << "\n";
        cout << _02762_ContinuousSubarrays3(v[i]) << "\n";
    }
}

static long long _02762_ContinuousSubarrays(vector<int> &nums)
{
    map<int, int> freq;
    int left = 0, right = 0;
    int n = nums.size();
    long long count = 0;

    while (right < n)
    {
        freq[nums[right]]++;

        while (freq.rbegin()->first - freq.begin()->first > 2)
        {
            freq[nums[left]]--;

            if (freq[nums[left]] == 0)
                freq.erase(nums[left]);

            left++;
        }

        count += right - left + 1;
        right++;
    }

    return count;
}

static long long _02762_ContinuousSubarrays0(vector<int> &nums)
{
    int left = 0, right = 0;
    long long count = 0;

    priority_queue<int, vector<int>, function<bool(int, int)>> minHeap(
        [&nums](int a, int b)
        { return nums[a] > nums[b]; });

    priority_queue<int, vector<int>, function<bool(int, int)>> maxHeap(
        [&nums](int a, int b)
        { return nums[a] < nums[b]; });

    while (right < nums.size())
    {
        minHeap.push(right);
        maxHeap.push(right);

        while (left < right &&
               nums[maxHeap.top()] - nums[minHeap.top()] > 2)
        {
            left++;

            while (!maxHeap.empty() && maxHeap.top() < left)
            {
                maxHeap.pop();
            }

            while (!minHeap.empty() && minHeap.top() < left)
            {
                minHeap.pop();
            }
        }

        count += right - left + 1;
        right++;
    }

    return count;
}

static long long _02762_ContinuousSubarrays1(vector<int> &nums)
{
    deque<int> maxQ, minQ;
    int left = 0;
    long long count = 0;

    for (int right = 0; right < nums.size(); right++)
    {
        while (!maxQ.empty() && nums[maxQ.back()] < nums[right])
        {
            maxQ.pop_back();
        }

        maxQ.push_back(right);

        while (!minQ.empty() && nums[minQ.back()] > nums[right])
        {
            minQ.pop_back();
        }

        minQ.push_back(right);

        while (!maxQ.empty() && !minQ.empty() &&
               nums[maxQ.front()] - nums[minQ.front()] > 2)
        {
            if (maxQ.front() < minQ.front())
            {
                left = maxQ.front() + 1;
                maxQ.pop_front();
            }
            else
            {
                left = minQ.front() + 1;
                minQ.pop_front();
            }
        }

        count += right - left + 1;
    }

    return count;
}

static long long _02762_ContinuousSubarrays2(vector<int> &nums)
{
    int right = 0, left = 0;
    int curMin, curMax;
    long long windowLen = 0, total = 0;

    curMin = curMax = nums[right];

    for (right = 0; right < nums.size(); right++)
    {
        curMin = min(curMin, nums[right]);
        curMax = max(curMax, nums[right]);

        if (curMax - curMin > 2)
        {
            windowLen = right - left;
            total += (windowLen * (windowLen + 1) / 2);

            left = right;
            curMin = curMax = nums[right];

            while (left > 0 && abs(nums[right] - nums[left - 1]) <= 2)
            {
                left--;
                curMin = min(curMin, nums[left]);
                curMax = max(curMax, nums[left]);
            }

            if (left < right)
            {
                windowLen = right - left;
                total -= (windowLen * (windowLen + 1) / 2);
            }
        }
    }

    windowLen = right - left;
    total += (windowLen * (windowLen + 1) / 2);

    return total;
}

static long long _02762_ContinuousSubarrays3(vector<int> &nums)
{
    map<int, int> mp;
    long long ans = 0;
    int R = -1;

    for (int L = 0, n = nums.size(); L < n; L++)
    {
        if (R < L)
            ++mp[nums[R = L]];

        while (R < (n - 1) && (abs(mp.begin()->first - nums[R + 1]) <= 2 &&
                               abs(mp.rbegin()->first - nums[R + 1]) <= 2))
            ++mp[nums[++R]];
        ans += (R - L + 1);

        if (mp[nums[L]] == 1)
            mp.erase(nums[L]);
        else
            --mp[nums[L]];
    }

    return ans;
}

#pragma region GTest
static int is_02762_ContinuousSubarrays_RunTest()
{
    stringstream ss;
    ss << "*_02762_ContinuousSubarrays.expected*"
       << ":"
       << "*_02762_ContinuousSubarrays0.expected*"
       << ":"
       << "*_02762_ContinuousSubarrays1.expected*"
       << ":"
       << "*_02762_ContinuousSubarrays2.expected*"
       << ":"
       << "*_02762_ContinuousSubarrays3.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_02762_ContinuousSubarrays, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        long long expected = v0[i];

        // Actual
        long long actual = _02762_ContinuousSubarrays(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02762_ContinuousSubarrays0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        long long expected = v0[i];

        // Actual
        long long actual = _02762_ContinuousSubarrays0(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02762_ContinuousSubarrays1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        long long expected = v0[i];

        // Actual
        long long actual = _02762_ContinuousSubarrays1(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02762_ContinuousSubarrays2, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        long long expected = v0[i];

        // Actual
        long long actual = _02762_ContinuousSubarrays2(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02762_ContinuousSubarrays3, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        long long expected = v0[i];

        // Actual
        long long actual = _02762_ContinuousSubarrays3(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
