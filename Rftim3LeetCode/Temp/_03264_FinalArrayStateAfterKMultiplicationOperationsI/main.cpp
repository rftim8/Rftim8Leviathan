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

// K Full Array Scans for Minimum Element Multiplication
static vector<int> _03264_FinalArrayStateAfterKMultiplicationOperationsI(vector<int> &nums, int k, int multiplier);
// Heap-Optimized K Minimum Value Multiplication
static vector<int> _03264_FinalArrayStateAfterKMultiplicationOperationsI0(vector<int> &nums, int k, int multiplier);
// Priority Queue - Speed
static vector<int> _03264_FinalArrayStateAfterKMultiplicationOperationsI1(vector<int> &nums, int k, int multiplier);

static int is_03264_FinalArrayStateAfterKMultiplicationOperationsI_RunTest();

/**
 * You are given an integer array nums, an integer k, and an integer multiplier.
 * You need to perform k operations on nums. In each operation:
 * Find the minimum value x in nums. If there are multiple occurrences of the minimum value,
 * select the one that appears first.
 * Replace the selected minimum value x with x * multiplier.
 * Return an integer array denoting the final state of nums after performing all k operations.
 *
 * Constraints:
 *
 * 1 <= nums.length <= 100
 * 1 <= nums[i] <= 100
 * 1 <= k <= 10
 * 1 <= multiplier <= 5
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_03264_FinalArrayStateAfterKMultiplicationOperationsI_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<vector<int>> v, v2;
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
        v2.push_back(d);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        vector<int> res = _03264_FinalArrayStateAfterKMultiplicationOperationsI(v[i], v0[i], v1[i]);
        for (auto &&j : res)
        {
            cout << j << " ";
        }
        cout << "\n";

        vector<int> res0 = _03264_FinalArrayStateAfterKMultiplicationOperationsI0(v[i], v0[i], v1[i]);
        for (auto &&j : res0)
        {
            cout << j << " ";
        }
        cout << "\n";

        vector<int> res1 = _03264_FinalArrayStateAfterKMultiplicationOperationsI1(v[i], v0[i], v1[i]);
        for (auto &&j : res1)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
}

static vector<int> _03264_FinalArrayStateAfterKMultiplicationOperationsI(vector<int> &nums0, int k, int multiplier)
{
    vector<int> nums(nums0);
    int n = nums.size();

    while (k--)
    {
        int minIndex = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] < nums[minIndex])
                minIndex = i;
        }

        nums[minIndex] *= multiplier;
    }

    return nums;
}

static vector<int> _03264_FinalArrayStateAfterKMultiplicationOperationsI0(vector<int> &nums0, int k, int multiplier)
{
    vector<int> nums(nums0);
    int n = nums.size();

    while (k--)
    {
        int minIndex = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] < nums[minIndex])
                minIndex = i;
        }

        nums[minIndex] *= multiplier;
    }

    return nums;
}

static vector<int> _03264_FinalArrayStateAfterKMultiplicationOperationsI1(vector<int> &nums, int k, int multiplier)
{
    int n = nums.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    for (int i = 0; i < n; i++)
    {
        minHeap.push({nums[i], i});
    }

    while (k)
    {
        auto [value, index] = minHeap.top();
        nums[index] = nums[index] * multiplier;
        minHeap.pop();
        minHeap.push({nums[index], index});
        k--;
    }

    return nums;
}

#pragma region GTest
static int is_03264_FinalArrayStateAfterKMultiplicationOperationsI_RunTest()
{
    stringstream ss;
    ss << "*_03264_FinalArrayStateAfterKMultiplicationOperationsI.expected*"
       << ":"
       << "*_03264_FinalArrayStateAfterKMultiplicationOperationsI0.expected*"
       << ":"
       << "*_03264_FinalArrayStateAfterKMultiplicationOperationsI1.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_03264_FinalArrayStateAfterKMultiplicationOperationsI, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<int> expected = v2[i];

        // Actual
        vector<int> actual = _03264_FinalArrayStateAfterKMultiplicationOperationsI(v[i], v0[i], v1[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_03264_FinalArrayStateAfterKMultiplicationOperationsI0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<int> expected = v2[i];

        // Actual
        vector<int> actual = _03264_FinalArrayStateAfterKMultiplicationOperationsI0(v[i], v0[i], v1[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_03264_FinalArrayStateAfterKMultiplicationOperationsI1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<int> expected = v2[i];

        // Actual
        vector<int> actual = _03264_FinalArrayStateAfterKMultiplicationOperationsI1(v[i], v0[i], v1[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
