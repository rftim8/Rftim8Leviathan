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

// Bit Count Array
static int _02275_LargestCombinationWithBitwiseANDGreaterThanZero(vector<int> &candidates);
// Direct Maximum Bit Count
static int _02275_LargestCombinationWithBitwiseANDGreaterThanZero0(vector<int> &candidates);
// Speed
static int _02275_LargestCombinationWithBitwiseANDGreaterThanZero1(vector<int> &candidates);

static int is_02275_LargestCombinationWithBitwiseANDGreaterThanZero_RunTest();

/**
 * The bitwise AND of an array nums is the bitwise AND of all integers in nums.
 * For example, for nums = [1, 5, 3], the bitwise AND is equal to 1 & 5 & 3 = 1.
 * Also, for nums = [7], the bitwise AND is 7.
 * You are given an array of positive integers candidates.
 * Evaluate the bitwise AND of every combination of numbers of candidates.
 * Each number in candidates may only be used once in each combination.
 * Return the size of the largest combination of candidates with a bitwise AND greater than 0.
 *
 * Constraints:
 *
 * 1 <= candidates.length <= 10^5
 * 1 <= candidates[i] <= 10^7
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_02275_LargestCombinationWithBitwiseANDGreaterThanZero_RunTest();
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
        cout << _02275_LargestCombinationWithBitwiseANDGreaterThanZero(v[i]) << "\n";
        cout << _02275_LargestCombinationWithBitwiseANDGreaterThanZero0(v[i]) << "\n";
        cout << _02275_LargestCombinationWithBitwiseANDGreaterThanZero1(v[i]) << "\n";
    }
}

static int _02275_LargestCombinationWithBitwiseANDGreaterThanZero(vector<int> &candidates)
{
    vector<int> bitCount(24, 0);

    for (int i = 0; i < 24; i++)
    {
        for (int num : candidates)
        {
            if ((num & (1 << i)) != 0)
                bitCount[i]++;
        }
    }

    return *max_element(bitCount.begin(), bitCount.end());
}

static int _02275_LargestCombinationWithBitwiseANDGreaterThanZero0(vector<int> &candidates)
{
    int maxCount = 0;

    for (int i = 0; i < 24; i++)
    {
        int count = 0;

        for (int num : candidates)
        {
            if ((num & (1 << i)) != 0)
                count++;
        }

        maxCount = max(maxCount, count);
    }

    return maxCount;
}

static int _02275_LargestCombinationWithBitwiseANDGreaterThanZero1(vector<int> &candidates)
{
    array<int, 24> bc{};

    for (int i : candidates)
    {
        int sh{0};
    
        while (i)
        {
            bc[sh] += i & 1;
            ++sh;
            i >>= 1;
        }
    }

    return *max_element(bc.cbegin(), bc.cend());
}

#pragma region GTest
static int is_02275_LargestCombinationWithBitwiseANDGreaterThanZero_RunTest()
{
    stringstream ss;
    ss << "*_02275_LargestCombinationWithBitwiseANDGreaterThanZero.expected*"
       << ":"
       << "*_02275_LargestCombinationWithBitwiseANDGreaterThanZero0.expected*"
       << ":"
       << "*_02275_LargestCombinationWithBitwiseANDGreaterThanZero1.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_02275_LargestCombinationWithBitwiseANDGreaterThanZero, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _02275_LargestCombinationWithBitwiseANDGreaterThanZero(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02275_LargestCombinationWithBitwiseANDGreaterThanZero0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _02275_LargestCombinationWithBitwiseANDGreaterThanZero0(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02275_LargestCombinationWithBitwiseANDGreaterThanZero1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _02275_LargestCombinationWithBitwiseANDGreaterThanZero1(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
