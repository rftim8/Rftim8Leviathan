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
static int _01760_MinimumLimitOfBallsinaBag(vector<int> &nums, int maxOperations);
// Speed
static int _01760_MinimumLimitOfBallsinaBag0(vector<int> &nums, int maxOperations);

static int is_01760_MinimumLimitOfBallsinaBag_RunTest();

/**
 * You are given an integer array nums where the ith bag contains nums[i] balls.
 * You are also given an integer maxOperations.
 * You can perform the following operation at most maxOperations times:
 * Take any bag of balls and divide it into two new bags with a positive number of balls.
 * For example, a bag of 5 balls can become two new bags of 1 and 4 balls, or two new bags of 2 and 3 balls.
 * Your penalty is the maximum number of balls in a bag. You want to minimize your penalty after the operations.
 * Return the minimum possible penalty after performing the operations.
 *
 * Constraints:
 *
 * 1 <= nums.length <= 10^5
 * 1 <= maxOperations, nums[i] <= 10^9
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_01760_MinimumLimitOfBallsinaBag_RunTest();
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
        cout << _01760_MinimumLimitOfBallsinaBag(v[i], v0[i]) << "\n";
        cout << _01760_MinimumLimitOfBallsinaBag0(v[i], v0[i]) << "\n";
    }
}

#pragma region Binary Search
static bool isPossible(int maxBallsInBag, vector<int> &nums, int maxOperations)
{
    int totalOperations = 0;

    for (int num : nums)
    {
        int operations = ceil(num / (double)maxBallsInBag) - 1;
        totalOperations += operations;

        if (totalOperations > maxOperations)
            return false;
    }

    return true;
}

static int _01760_MinimumLimitOfBallsinaBag(vector<int> &nums, int maxOperations)
{
    int left = 1;
    int right = 0;

    for (auto num : nums)
    {
        right = max(right, num);
    }

    while (left < right)
    {
        int middle = (left + right) / 2;

        if (isPossible(middle, nums, maxOperations))
            right = middle;
        else
            left = middle + 1;
    }

    return left;
}
#pragma endregion

#pragma region Speed
static int _01760_MinimumLimitOfBallsinaBag0(vector<int> &nums, int maxOperations)
{
    int left = 1, right = 1e9;

    while (left < right)
    {
        int mid = (left + right) / 2, count = 0;

        for (int &i : nums)
        {
            count += (i - 1) / mid;
        }

        if (count > maxOperations)
            left = mid + 1;
        else
            right = mid;
    }

    return left;
}
#pragma endregion

#pragma region GTest
static int is_01760_MinimumLimitOfBallsinaBag_RunTest()
{
    stringstream ss;
    ss << "*_01760_MinimumLimitOfBallsinaBag.expected*"
       << ":"
       << "*_01760_MinimumLimitOfBallsinaBag0.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_01760_MinimumLimitOfBallsinaBag, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v1[i];

        // Actual
        int actual = _01760_MinimumLimitOfBallsinaBag(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_01760_MinimumLimitOfBallsinaBag0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v1[i];

        // Actual
        int actual = _01760_MinimumLimitOfBallsinaBag0(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
