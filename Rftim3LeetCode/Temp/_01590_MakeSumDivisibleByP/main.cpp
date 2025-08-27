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

// Brute Force - TLE
static int _01590_MakeSumDivisibleByP(vector<int> &nums, int p);
// Prefix Sum Modulo
static int _01590_MakeSumDivisibleByP0(vector<int> &nums, int p);
// Speed
static int _01590_MakeSumDivisibleByP1(vector<int> &nums, int p);

static int is_01590_MakeSumDivisibleByP_RunTest();

/**
 * Given an array of positive integers nums, remove the smallest subarray (possibly empty) such that
 * the sum of the remaining elements is divisible by p.
 * It is not allowed to remove the whole array.
 * Return the length of the smallest subarray that you need to remove, or -1 if it's impossible.
 *
 * A subarray is defined as a contiguous block of elements in the array.
 *
 * Constraints:
 *
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^9
 * 1 <= p <= 10^9
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_01590_MakeSumDivisibleByP_RunTest();
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
        vector<int> vv = {};
        while (getline(ss, t, ','))
        {
            vv.push_back(stoi(t));
        }
        v.push_back(vv);

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
        cout << _01590_MakeSumDivisibleByP(v[i], v0[i]) << "\n";
        cout << _01590_MakeSumDivisibleByP0(v[i], v0[i]) << "\n";
        cout << _01590_MakeSumDivisibleByP1(v[i], v0[i]) << "\n";
    }
}

static int _01590_MakeSumDivisibleByP(vector<int> &nums, int p)
{
    int n = nums.size();
    long long totalSum = accumulate(nums.begin(), nums.end(), 0LL);

    if (totalSum % p == 0)
        return 0;

    int minLen = n;

    for (int start = 0; start < n; ++start)
    {
        long long subSum = 0;

        for (int end = start; end < n; ++end)
        {
            subSum += nums[end];
            long long remainingSum = (totalSum - subSum) % p;

            if (remainingSum == 0)
                minLen = min(minLen, end - start + 1);
        }
    }

    return minLen == n ? -1 : minLen;
}

static int _01590_MakeSumDivisibleByP0(vector<int> &nums, int p)
{
    int n = nums.size();
    int totalSum = 0;

    for (int num : nums)
    {
        totalSum = (totalSum + num) % p;
    }

    int target = totalSum % p;

    if (target == 0)
        return 0;

    unordered_map<int, int> modMap;
    modMap[0] = -1;
    int currentSum = 0, minLen = n;

    for (int i = 0; i < n; ++i)
    {
        currentSum = (currentSum + nums[i]) % p;
        int needed = (currentSum - target + p) % p;

        if (modMap.find(needed) != modMap.end())
            minLen = min(minLen, i - modMap[needed]);

        modMap[currentSum] = i;
    }

    return minLen == n ? -1 : minLen;
}

static int _01590_MakeSumDivisibleByP1(vector<int> &nums, int p)
{
    int n = nums.size();
    long totalrem = accumulate(nums.begin(), nums.end(), 0l) % p;

    if (totalrem == 0)
        return 0;

    unordered_map<int, int> presums;
    presums[0] = -1;
    long sum = 0;
    int minlen = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        long rem = sum % p;
        long target = (((rem - totalrem) % p) + p) % p;

        if (presums.find(target) != presums.end())
            minlen = min(i - presums[target], minlen);

        presums[rem] = i;
    }

    return (minlen == INT_MAX or minlen == n) ? -1 : minlen;
}

#pragma region GTest
static int is_01590_MakeSumDivisibleByP_RunTest()
{
    stringstream ss;
    ss << "*_01590_MakeSumDivisibleByP.expected*"
       << ":"
       << "*_01590_MakeSumDivisibleByP0.expected*"
       << ":"
       << "*_01590_MakeSumDivisibleByP1.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_01590_MakeSumDivisibleByP, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v1[i];

        // Actual
        int actual = _01590_MakeSumDivisibleByP(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_01590_MakeSumDivisibleByP0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v1[i];

        // Actual
        int actual = _01590_MakeSumDivisibleByP0(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_01590_MakeSumDivisibleByP1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v1[i];

        // Actual
        int actual = _01590_MakeSumDivisibleByP1(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
