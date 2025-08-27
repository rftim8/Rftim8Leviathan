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

// Greedy
static bool _03011_FindIfArrayCanBeSorted(vector<int> &nums);
// Speed
static bool _03011_FindIfArrayCanBeSorted0(vector<int> &nums);

static int is_03011_FindIfArrayCanBeSorted_RunTest();

/**
 * You are given a 0-indexed array of positive integers nums.
 * In one operation, you can swap any two adjacent elements if they have the same number of
 * set bits.
 * You are allowed to do this operation any number of times (including zero).
 * Return true if you can sort the array, else return false.
 *
 * Constraints:
 *
 * 1 <= nums.length <= 100
 * 1 <= nums[i] <= 2^8
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_03011_FindIfArrayCanBeSorted_RunTest();
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
        cout << _03011_FindIfArrayCanBeSorted(v[i]) << "\n";
        cout << _03011_FindIfArrayCanBeSorted0(v[i]) << "\n";
    }
}

static bool _03011_FindIfArrayCanBeSorted(vector<int> &nums)
{
    int n = nums.size();
    bool r = true;

    for (int j = 0; j < n; j++)
    {
        for (int i = n - 1; i > 0; i--)
        {
            if (nums[i - 1] > nums[i])
            {
                string c0 = bitset<64>(nums[i]).to_string();
                int n0 = count(c0.begin(), c0.end(), '1');

                string c1 = bitset<64>(nums[i - 1]).to_string();
                int n1 = count(c1.begin(), c1.end(), '1');

                if (n0 != n1)
                    return false;
                else
                    swap(nums[i], nums[i - 1]);
            }
        }
    }

    return r;
}

static bool _03011_FindIfArrayCanBeSorted0(vector<int> &nums)
{
    vector<pair<int, int>> mm;
    mm.push_back({nums[0], nums[0]});
    
    for (int i = 1; i < nums.size(); i++)
    {
        int cur = __builtin_popcount(nums[i]);
        int prev = __builtin_popcount(nums[i - 1]);
    
        if (cur != prev)
            mm.push_back({nums[i], nums[i]});
    
        mm.back().first = min(mm.back().first, nums[i]);
        mm.back().second = max(mm.back().second, nums[i]);
    }
    
    for (int i = 1; i < mm.size(); i++)
    {
        if (mm[i - 1].second > mm[i].first)
            return false;
    }

    return true;
}

#pragma region GTest
static int is_03011_FindIfArrayCanBeSorted_RunTest()
{
    stringstream ss;
    ss << "*_03011_FindIfArrayCanBeSorted.expected*"
       << ":"
       << "*_03011_FindIfArrayCanBeSorted0.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_03011_FindIfArrayCanBeSorted, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        bool expected = v0[i];

        // Actual
        bool actual = _03011_FindIfArrayCanBeSorted(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_03011_FindIfArrayCanBeSorted0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        bool expected = v0[i];

        // Actual
        bool actual = _03011_FindIfArrayCanBeSorted0(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
