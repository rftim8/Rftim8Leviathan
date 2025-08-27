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

// DP - Iterative
static int _02466_CountWaysToBuildGoodStrings(int low, int high, int zero, int one);
// Speed
static int _02466_CountWaysToBuildGoodStrings0(int low, int high, int zero, int one);
// DP - Recursive
static int _02466_CountWaysToBuildGoodStrings1(int low, int high, int zero, int one);

static int is_02466_CountWaysToBuildGoodStrings_RunTest();

/**
 * Given the integers zero, one, low, and high, we can construct a string by starting with an empty string,
 * and then at each step perform either of the following:
 * Append the character '0' zero times.
 * Append the character '1' one times.
 * This can be performed any number of times.
 * A good string is a string constructed by the above process having a length between low and high (inclusive).
 * Return the number of different good strings that can be constructed satisfying these properties.
 * Since the answer can be large, return it modulo 10^9 + 7.
 *
 * Constraints:
 *
 * 1 <= low <= high <= 10^5
 * 1 <= zero, one <= low
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_02466_CountWaysToBuildGoodStrings_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<int> v, v0, v1, v2, v3;

static void dataCollector()
{
    cin >> n;
    cin >> m;
    cin.get();

    for (int i = 0; i < n * m; i += m)
    {
        int s;
        cin >> s;
        v.push_back(s);

        cin >> s;
        v0.push_back(s);

        cin >> s;
        v1.push_back(s);

        cin >> s;
        v2.push_back(s);

        cin >> s;
        cin.get();
        v3.push_back(s);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        cout << _02466_CountWaysToBuildGoodStrings(v[i], v0[i], v1[i], v2[i]) << "\n";
        cout << _02466_CountWaysToBuildGoodStrings0(v[i], v0[i], v1[i], v2[i]) << "\n";
        cout << _02466_CountWaysToBuildGoodStrings1(v[i], v0[i], v1[i], v2[i]) << "\n";
    }
}

static int _02466_CountWaysToBuildGoodStrings(int low, int high, int zero, int one)
{
    vector<int> x(high + 1);
    x[0] = 1;
    int mod = 1000000007;

    for (int end = 1; end <= high; ++end)
    {
        if (end >= zero)
            x[end] += x[end - zero];

        if (end >= one)
            x[end] += x[end - one];

        x[end] %= mod;
    }

    int y = 0;

    for (int i = low; i <= high; ++i)
    {
        y += x[i];
        y %= mod;
    }

    return y;
}

static int _02466_CountWaysToBuildGoodStrings0(int low, int high, int zero, int one)
{
    int sum[100001];
    sum[0] = 1;

    for (int i = 1; i <= high; i++)
    {
        long long sumCur = 0;

        if (i >= zero)
            sumCur += sum[i - zero];

        if (i >= one)
            sumCur += sum[i - one];

        if (sumCur > 0x3000000000000000ll)
            sumCur %= 1000000007;

        sum[i] = sumCur % 1000000007;
    }

    long long sumTotal = 0;

    for (int i = low; i <= high; i++)
        sumTotal += sum[i];

    return sumTotal % 1000000007;
}

#pragma region DP - Recursive
static vector<int> dp;
static int mod = 1000000007;

static int dfs(int end, int zero, int one)
{
    if (dp[end] != -1)
        return dp[end];

    int count = 0;

    if (end >= one)
        count += dfs(end - one, zero, one);

    if (end >= zero)
        count += dfs(end - zero, zero, one);

    dp[end] = count % mod;

    return dp[end];
}

static int _02466_CountWaysToBuildGoodStrings1(int low, int high, int zero, int one)
{
    dp = vector<int>(high + 1, -1);
    dp[0] = 1;
    int answer = 0;

    for (int end = low; end <= high; ++end)
    {
        answer += dfs(end, zero, one);
        answer %= mod;
    }

    return answer;
}
#pragma endregion

#pragma region GTest
static int is_02466_CountWaysToBuildGoodStrings_RunTest()
{
    stringstream ss;
    ss << "*_02466_CountWaysToBuildGoodStrings.expected*"
       << ":"
       << "*_02466_CountWaysToBuildGoodStrings0.expected*"
       << ":"
       << "*_02466_CountWaysToBuildGoodStrings1.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_02466_CountWaysToBuildGoodStrings, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v3[i];

        // Actual
        int actual = _02466_CountWaysToBuildGoodStrings(v[i], v0[i], v1[i], v2[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02466_CountWaysToBuildGoodStrings0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v3[i];

        // Actual
        int actual = _02466_CountWaysToBuildGoodStrings0(v[i], v0[i], v1[i], v2[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02466_CountWaysToBuildGoodStrings1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v3[i];

        // Actual
        int actual = _02466_CountWaysToBuildGoodStrings1(v[i], v0[i], v1[i], v2[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
