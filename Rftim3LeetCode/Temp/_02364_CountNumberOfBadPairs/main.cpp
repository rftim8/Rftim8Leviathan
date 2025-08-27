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

// Greedy - TLE
static long long _02364_CountNumberOfBadPairs(vector<int> &nums);
// Hash Map - My submission
static long long _02364_CountNumberOfBadPairs_0(vector<int> &nums);
// Runtime
static long long _02364_CountNumberOfBadPairs_1(vector<int> &nums);
// Memory
static long long _02364_CountNumberOfBadPairs_2(vector<int> &nums);

static int is_02364_CountNumberOfBadPairs_RunTest();

/**
 * You are given a 0-indexed integer array nums.
 * A pair of indices (i, j) is a bad pair if i < j and j - i != nums[j] - nums[i].
 * Return the total number of bad pairs in nums.
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
    is_02364_CountNumberOfBadPairs_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<vector<int>> v;
static vector<long long> v0;

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

        long long s0;
        cin >> s0;
        cin.get();
        v0.push_back(s0);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        cout << _02364_CountNumberOfBadPairs(v[i]) << "\n";
        cout << _02364_CountNumberOfBadPairs_0(v[i]) << "\n";
        cout << _02364_CountNumberOfBadPairs_1(v[i]) << "\n";
        cout << _02364_CountNumberOfBadPairs_2(v[i]) << "\n";
    }
}

static long long _02364_CountNumberOfBadPairs(vector<int> &nums)
{
    long long res = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[j] - nums[i] != j - i)
                res++;
        }
    }

    return res;
}

static long long _02364_CountNumberOfBadPairs_0(vector<int> &nums)
{
    long long res = 0;
    unordered_map<int, int> um;

    for (int i = 0; i < nums.size(); i++)
    {
        int diff = i - nums[i];
        int good = um[diff];
        res += i - good;
        um[diff] = good + 1;
    }

    return res;
}

static long long _02364_CountNumberOfBadPairs_1(vector<int> &nums)
{
    vector<int> v(nums);
    long long int b = v.size(), g = 0, k = 0;

    for (int i = 0; i < b; i++)
    {
        v[i] = i - v[i];
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < b - 1; i++)
    {
        if (v[i] == v[i + 1])
            k++;
        else
        {
            g = g + (k * (k + 1)) / 2;
            k = 0;
        }
    }

    return (b * (b - 1)) / 2 - g - (k * (k + 1)) / 2;
}

static long long _02364_CountNumberOfBadPairs_2(vector<int> &nums)
{
    int n = nums.size();
    long long cnt = n * (n - 1LL) / 2;

    for (int i = 0; i < n; i++)
        nums[i] -= i;

    sort(nums.begin(), nums.end());

    for (int l = 0, r = 0; r < n; r++)
    {
        int x = nums[l];

        while (r < n && x == nums[r])
            r++;

        long long f = r - l;

        cnt -= f * (f - 1) / 2;
        l = r;
    }

    return cnt;
}

#pragma region GTest
static int is_02364_CountNumberOfBadPairs_RunTest()
{
    stringstream ss;
    ss << "*_02364_CountNumberOfBadPairs.expected*"
       << ":"
       << "*_02364_CountNumberOfBadPairs_0.expected*"
       << ":"
       << "*_02364_CountNumberOfBadPairs_1.expected*"
       << ":"
       << "*_02364_CountNumberOfBadPairs_2.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_02364_CountNumberOfBadPairs, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        long long expected = v0[i];

        // Actual
        long long actual = _02364_CountNumberOfBadPairs(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02364_CountNumberOfBadPairs_0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        long long expected = v0[i];

        // Actual
        long long actual = _02364_CountNumberOfBadPairs_0(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02364_CountNumberOfBadPairs_1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        long long expected = v0[i];

        // Actual
        long long actual = _02364_CountNumberOfBadPairs_1(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02364_CountNumberOfBadPairs_2, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        long long expected = v0[i];

        // Actual
        long long actual = _02364_CountNumberOfBadPairs_2(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
