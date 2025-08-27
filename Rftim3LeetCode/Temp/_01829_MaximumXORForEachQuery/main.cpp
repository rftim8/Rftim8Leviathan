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

// Prefix Array + Bit Masking
static vector<int> _01829_MaximumXORForEachQuery(vector<int> &nums, int maximumBit);
// Optimized Calculation + Bit Masking
static vector<int> _01829_MaximumXORForEachQuery0(vector<int> &nums, int maximumBit);
// Speed
static vector<int> _01829_MaximumXORForEachQuery1(vector<int> &nums, int maximumBit);

static int is_01829_MaximumXORForEachQuery_RunTest();

/**
 * You are given a sorted array nums of n non-negative integers and an integer maximumBit.
 * You want to perform the following query n times:
 * Find a non-negative integer k < 2maximumBit such that nums[0] XOR nums[1]
 * XOR ... XOR nums[nums.length-1] XOR k is maximized. k is the answer to the ith query.
 * Remove the last element from the current array nums.
 * Return an array answer, where answer[i] is the answer to the ith query.
 *
 * Constraints:
 *
 * nums.length == n
 * 1 <= n <= 10^5
 * 1 <= maximumBit <= 20
 * 0 <= nums[i] < 2^maximumBit
 * nums​​​ is sorted in ascending order.
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_01829_MaximumXORForEachQuery_RunTest();
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
        vector<int> res = _01829_MaximumXORForEachQuery(v[i], v0[i]);
        for (auto &&j : res)
        {
            cout << j << " ";
        }
        cout << "\n";

        vector<int> res0 = _01829_MaximumXORForEachQuery0(v[i], v0[i]);
        for (auto &&j : res0)
        {
            cout << j << " ";
        }
        cout << "\n";

        vector<int> res1 = _01829_MaximumXORForEachQuery1(v[i], v0[i]);
        for (auto &&j : res1)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
}

static vector<int> _01829_MaximumXORForEachQuery(vector<int> &nums, int maximumBit)
{
    int n = nums.size();
    vector<int> prefixXOR(n);
    prefixXOR[0] = nums[0];

    for (int i = 1; i < n; i++)
    {
        prefixXOR[i] = prefixXOR[i - 1] ^ nums[i];
    }

    vector<int> ans(n);
    int mask = (1 << maximumBit) - 1;

    for (int i = 0; i < n; i++)
    {
        int currentXOR = prefixXOR[n - 1 - i];
        ans[i] = currentXOR ^ mask;
    }

    return ans;
}

static vector<int> _01829_MaximumXORForEachQuery0(vector<int> &nums, int maximumBit)
{
    int xorProduct = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        xorProduct = xorProduct ^ nums[i];
    }

    vector<int> ans(nums.size());
    int mask = (1 << maximumBit) - 1;

    for (int i = 0; i < nums.size(); i++)
    {
        ans[i] = xorProduct ^ mask;
        xorProduct = xorProduct ^ nums[nums.size() - 1 - i];
    }

    return ans;
}

static vector<int> _01829_MaximumXORForEachQuery1(vector<int> &nums, int maximumBit)
{
    int mask = (1LL << maximumBit) - 1, n = nums.size();
    vector<int> res(n);
    
    for (int i = 0, curr = 0; i < n; i++)
    {
        curr ^= nums[i];
        res[n - i - 1] = ~curr & mask;
    }

    return res;
}

#pragma region GTest
static int is_01829_MaximumXORForEachQuery_RunTest()
{
    stringstream ss;
    ss << "*_01829_MaximumXORForEachQuery.expected*"
       << ":"
       << "*_01829_MaximumXORForEachQuery0.expected*"
       << ":"
       << "*_01829_MaximumXORForEachQuery1.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_01829_MaximumXORForEachQuery, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<int> expected = v1[i];

        // Actual
        vector<int> actual = _01829_MaximumXORForEachQuery(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_01829_MaximumXORForEachQuery0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<int> expected = v1[i];

        // Actual
        vector<int> actual = _01829_MaximumXORForEachQuery0(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_01829_MaximumXORForEachQuery1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<int> expected = v1[i];

        // Actual
        vector<int> actual = _01829_MaximumXORForEachQuery1(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
