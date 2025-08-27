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
static vector<int> _03254_FindThePowerOfKSizeSubarraysI(vector<int> &nums, int k);
// Sliding Window with Dequeue
static vector<int> _03254_FindThePowerOfKSizeSubarraysI0(vector<int> &nums, int k);
// Optimized via counter
static vector<int> _03254_FindThePowerOfKSizeSubarraysI1(vector<int> &nums, int k);

static int is_03254_FindThePowerOfKSizeSubarraysI_RunTest();

/**
 * You are given an array of integers nums of length n and a positive integer k.
 * The power of an array is defined as:
 * Its maximum element if all of its elements are consecutive and sorted in ascending order.
 * -1 otherwise.
 * You need to find the power of all subarrays of nums of size k.
 * Return an integer array results of size n - k + 1, where results[i] is the power of
 * nums[i..(i + k - 1)].
 *
 * Constraints:
 *
 * 1 <= n == nums.length <= 500
 * 1 <= nums[i] <= 10^5
 * 1 <= k <= n
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_03254_FindThePowerOfKSizeSubarraysI_RunTest();
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
        vector<int> res = _03254_FindThePowerOfKSizeSubarraysI(v[i], v0[i]);
        for (auto &&j : res)
        {
            cout << j << " ";
        }
        cout << "\n";

        vector<int> res0 = _03254_FindThePowerOfKSizeSubarraysI0(v[i], v0[i]);
        for (auto &&j : res0)
        {
            cout << j << " ";
        }
        cout << "\n";

        vector<int> res1 = _03254_FindThePowerOfKSizeSubarraysI1(v[i], v0[i]);
        for (auto &&j : res1)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
}

static vector<int> _03254_FindThePowerOfKSizeSubarraysI(vector<int> &nums, int k)
{
    int length = nums.size();
    vector<int> result(length - k + 1);

    for (int start = 0; start <= length - k; start++)
    {
        bool isConsecutiveAndSorted = true;

        for (int index = start; index < start + k - 1; index++)
        {
            if (nums[index + 1] != nums[index] + 1)
            {
                isConsecutiveAndSorted = false;
                break;
            }
        }

        if (isConsecutiveAndSorted)
            result[start] = nums[start + k - 1];
        else
            result[start] = -1;
    }

    return result;
}

static vector<int> _03254_FindThePowerOfKSizeSubarraysI0(vector<int> &nums, int k)
{
    int length = nums.size();
    vector<int> result(length - k + 1, -1);
    deque<int> indexDeque;

    for (int currentIndex = 0; currentIndex < length; currentIndex++)
    {
        if (!indexDeque.empty() &&
            indexDeque.front() < currentIndex - k + 1)
            indexDeque.pop_front();

        if (!indexDeque.empty() &&
            nums[currentIndex] != nums[currentIndex - 1] + 1)
            indexDeque.clear();

        indexDeque.push_back(currentIndex);

        if (currentIndex >= k - 1)
        {
            if (indexDeque.size() == k)
                result[currentIndex - k + 1] = nums[indexDeque.back()];
            else
                result[currentIndex - k + 1] = -1;
        }
    }

    return result;
}

static vector<int> _03254_FindThePowerOfKSizeSubarraysI1(vector<int> &nums, int k)
{
    if (k == 1)
        return nums;

    size_t length = nums.size();
    vector<int> result(length - k + 1, -1);
    int consecutiveCount = 1;

    for (size_t index = 0; index < length - 1; index++)
    {
        if (nums[index] + 1 == nums[index + 1])
            consecutiveCount++;
        else
            consecutiveCount = 1;

        if (consecutiveCount >= k)
            result[index - k + 2] = nums[index + 1];
    }

    return result;
}

#pragma region GTest
static int is_03254_FindThePowerOfKSizeSubarraysI_RunTest()
{
    stringstream ss;
    ss << "*_03254_FindThePowerOfKSizeSubarraysI.expected*"
       << ":"
       << "*_03254_FindThePowerOfKSizeSubarraysI0.expected*"
       << ":"
       << "*_03254_FindThePowerOfKSizeSubarraysI1.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_03254_FindThePowerOfKSizeSubarraysI, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<int> expected = v1[i];

        // Actual
        vector<int> actual = _03254_FindThePowerOfKSizeSubarraysI(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_03254_FindThePowerOfKSizeSubarraysI0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<int> expected = v1[i];

        // Actual
        vector<int> actual = _03254_FindThePowerOfKSizeSubarraysI0(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_03254_FindThePowerOfKSizeSubarraysI1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<int> expected = v1[i];

        // Actual
        vector<int> actual = _03254_FindThePowerOfKSizeSubarraysI1(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
