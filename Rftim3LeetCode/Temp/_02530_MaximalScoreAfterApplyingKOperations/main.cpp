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

// Priority Queue
static long long _02530_MaximalScoreAfterApplyingKOperations(vector<int> &nums, int k);
// Speed
static long long _02530_MaximalScoreAfterApplyingKOperations0(vector<int> &nums, int k);

static int is_02530_MaximalScoreAfterApplyingKOperations_RunTest();

/**
 * You are given a 0-indexed integer array nums and an integer k. You have a starting score of 0.
 * In one operation:
 * 1. choose an index i such that 0 <= i < nums.length,
 * 2. increase your score by nums[i], and
 * 3. replace nums[i] with ceil(nums[i] / 3).
 * Return the maximum possible score you can attain after applying exactly k operations.
 * The ceiling function ceil(val) is the least integer greater than or equal to val.
 *
 * Constraints:
 *
 * 1 <= nums.length, k <= 10^5
 * 1 <= nums[i] <= 10^9
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_02530_MaximalScoreAfterApplyingKOperations_RunTest();
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
        cout << _02530_MaximalScoreAfterApplyingKOperations(v[i], v0[i]) << "\n";
        cout << _02530_MaximalScoreAfterApplyingKOperations0(v[i], v0[i]) << "\n";
    }
}

static long long _02530_MaximalScoreAfterApplyingKOperations(vector<int> &nums, int k)
{
    long long int ans = 0;
    priority_queue<int> pq;

    for (auto &i : nums)
    {
        pq.push(i);
    }

    while (k--)
    {
        int maxElement = pq.top();
        ans += maxElement;
        pq.pop();
        pq.push(ceil(maxElement / 3.0));
    }

    return ans;
}

static long long _02530_MaximalScoreAfterApplyingKOperations0(vector<int> &nums, int k)
{
    priority_queue<int> pq(nums.begin(), nums.end());
    long long score = 0;

    for (int i = 0; i < k; i++)
    {
        int x = pq.top();
        score += x;

        if (x == 1)
        {
            score += (k - 1 - i);
            break;
        }

        pq.pop();
        pq.push((x + 2) / 3);
    }

    return score;
}

#pragma region GTest
static int is_02530_MaximalScoreAfterApplyingKOperations_RunTest()
{
    stringstream ss;
    ss << "*_02530_MaximalScoreAfterApplyingKOperations.expected*"
       << ":"
       << "*_02530_MaximalScoreAfterApplyingKOperations0.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_02530_MaximalScoreAfterApplyingKOperations, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        long long expected = v1[i];

        // Actual
        long long actual = _02530_MaximalScoreAfterApplyingKOperations(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02530_MaximalScoreAfterApplyingKOperations0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        long long expected = v1[i];

        // Actual
        long long actual = _02530_MaximalScoreAfterApplyingKOperations0(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
