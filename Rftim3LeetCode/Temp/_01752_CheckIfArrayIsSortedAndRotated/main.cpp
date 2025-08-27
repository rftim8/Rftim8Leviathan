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

// LeetCode problem
static bool _01752_CheckIfArrayIsSortedAndRotated(vector<int> &nums);

static int is_01752_CheckIfArrayIsSortedAndRotated_RunTest();

/**
 * Given an array nums, return true if the array was originally sorted in non-decreasing order,
 * then rotated some number of positions (including zero).
 * Otherwise, return false.
 * There may be duplicates in the original array.
 * Note: An array A rotated by x positions results in an array B of the same length such that
 * A[i] == B[(i+x) % A.length], where % is the modulo operation.
 *
 * Constraints:
 *
 * 1 <= nums.length <= 100
 * 1 <= nums[i] <= 100
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_01752_CheckIfArrayIsSortedAndRotated_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<vector<int>> v;
static vector<bool> v0;

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

        bool s0;
        cin >> s0;
        cin.get();
        v0.push_back(s0);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        cout << _01752_CheckIfArrayIsSortedAndRotated(v[i]) << "\n";
    }
}

static bool _01752_CheckIfArrayIsSortedAndRotated(vector<int> &nums)
{
    int n = nums.size();
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] > nums[(i + 1) % n])
            count++;
    }

    return count <= 1;
}

#pragma region GTest
static int is_01752_CheckIfArrayIsSortedAndRotated_RunTest()
{
    stringstream ss;
    ss << "*_01752_CheckIfArrayIsSortedAndRotated.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_01752_CheckIfArrayIsSortedAndRotated, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        bool expected = v0[i];

        // Actual
        bool actual = _01752_CheckIfArrayIsSortedAndRotated(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
