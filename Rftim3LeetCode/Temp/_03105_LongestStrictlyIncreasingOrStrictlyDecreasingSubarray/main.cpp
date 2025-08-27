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
static int _03105_LongestStrictlyIncreasingOrStrictlyDecreasingSubarray(vector<int> &nums);

static int is_03105_LongestStrictlyIncreasingOrStrictlyDecreasingSubarray_RunTest();

/**
 * You are given an array of integers nums.
 * Return the length of the longest subarray of nums which is either strictly increasing or strictly decreasing.
 *
 * Constraints:
 *
 * 1 <= nums.length <= 50
 * 1 <= nums[i] <= 50
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_03105_LongestStrictlyIncreasingOrStrictlyDecreasingSubarray_RunTest();
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
        cout << _03105_LongestStrictlyIncreasingOrStrictlyDecreasingSubarray(v[i]) << "\n";
    }
}

static int _03105_LongestStrictlyIncreasingOrStrictlyDecreasingSubarray(vector<int> &nums)
{
    int inc = 1, dec = 1, res = 1;

    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] < nums[i + 1])
        {
            dec = 1;
            inc++;
        }
        else if (nums[i] > nums[i + 1])
        {
            inc = 1;
            dec++;
        }
        else
        {
            inc = 1;
            dec = 1;
        }

        res = max(res, inc);
        res = max(res, dec);
    }

    return res;
}

#pragma region GTest
static int is_03105_LongestStrictlyIncreasingOrStrictlyDecreasingSubarray_RunTest()
{
    stringstream ss;
    ss << "*_03105_LongestStrictlyIncreasingOrStrictlyDecreasingSubarray.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_03105_LongestStrictlyIncreasingOrStrictlyDecreasingSubarray, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _03105_LongestStrictlyIncreasingOrStrictlyDecreasingSubarray(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
