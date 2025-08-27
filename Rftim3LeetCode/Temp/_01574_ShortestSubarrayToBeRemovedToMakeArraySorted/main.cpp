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

// Two Pointers
static int _01574_ShortestSubarrayToBeRemovedToMakeArraySorted(vector<int> &arr);

static int is_01574_ShortestSubarrayToBeRemovedToMakeArraySorted_RunTest();

/**
 * Given an integer array arr, remove a subarray (can be empty) from arr such that the remaining elements
 * in arr are non-decreasing.
 * Return the length of the shortest subarray to remove.
 * A subarray is a contiguous subsequence of the array.
 *
 * Constraints:
 *
 * 1 <= arr.length <= 10^5
 * 0 <= arr[i] <= 10^9
 */
int main()
{
    offline();
    dataCollector();

    solve();
    return 0;

    ::testing::InitGoogleTest();
    is_01574_ShortestSubarrayToBeRemovedToMakeArraySorted_RunTest();
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
        cout << _01574_ShortestSubarrayToBeRemovedToMakeArraySorted(v[i]) << "\n";
    }
}

static int _01574_ShortestSubarrayToBeRemovedToMakeArraySorted(vector<int> &arr)
{
    int right = arr.size() - 1;

    while (right > 0 && arr[right] >= arr[right - 1])
    {
        right--;
    }

    int ans = right;
    int left = 0;

    while (left < right && (left == 0 || arr[left - 1] <= arr[left]))
    {
        while (right < arr.size() && arr[left] > arr[right])
        {
            right++;
        }

        ans = min(ans, right - left - 1);
        left++;
    }

    return ans;
}

#pragma region GTest
static int is_01574_ShortestSubarrayToBeRemovedToMakeArraySorted_RunTest()
{
    stringstream ss;
    ss << "*_01574_ShortestSubarrayToBeRemovedToMakeArraySorted.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_01574_ShortestSubarrayToBeRemovedToMakeArraySorted, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _01574_ShortestSubarrayToBeRemovedToMakeArraySorted(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
