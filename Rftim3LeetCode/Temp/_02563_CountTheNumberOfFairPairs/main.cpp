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

// BS
static long long _02563_CountTheNumberOfFairPairs(vector<int> &nums, int lower, int upper);
// Two Pointers
static long long _02563_CountTheNumberOfFairPairs0(vector<int> &nums, int lower, int upper);
// Speed, Recursive
static long long _02563_CountTheNumberOfFairPairs1(vector<int> &nums, int lower, int upper);

static int is_02563_CountTheNumberOfFairPairs_RunTest();

/**
 * Given a 0-indexed integer array nums of size n and two integers lower and upper,
 * return the number of fair pairs.
 * A pair (i, j) is fair if:
 * 0 <= i < j < n, and
 * lower <= nums[i] + nums[j] <= upper
 *
 * Constraints:
 *
 * 1 <= nums.length <= 10^5
 * nums.length == n
 * -10^9 <= nums[i] <= 10^9
 * -10^9 <= lower <= upper <= 10^9
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_02563_CountTheNumberOfFairPairs_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<vector<int>> v;
static vector<int> v0, v1, v2;

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
        v1.push_back(s0);

        cin >> s0;
        cin.get();
        v2.push_back(s0);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        cout << _02563_CountTheNumberOfFairPairs(v[i], v0[i], v1[i]) << "\n";
        cout << _02563_CountTheNumberOfFairPairs0(v[i], v0[i], v1[i]) << "\n";
        cout << _02563_CountTheNumberOfFairPairs1(v[i], v0[i], v1[i]) << "\n";
    }
}

#pragma region BS
static long long lower_bound(vector<int> &nums, int low, int high, int element)
{
    while (low <= high)
    {
        int mid = low + ((high - low) / 2);

        if (nums[mid] >= element)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return low;
}

static long long _02563_CountTheNumberOfFairPairs(vector<int> &nums, int lower, int upper)
{
    sort(nums.begin(), nums.end());
    long long ans = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        int low = lower_bound(nums, i + 1, nums.size() - 1, lower - nums[i]);
        int high = lower_bound(nums, i + 1, nums.size() - 1, upper - nums[i] + 1);
        ans += 1LL * (high - low);
    }

    return ans;
}
#pragma endregion

#pragma region Two Pointers
static long long lower_bound(vector<int> &nums, int value)
{
    int left = 0, right = nums.size() - 1;
    long long result = 0;

    while (left < right)
    {
        int sum = nums[left] + nums[right];

        if (sum < value)
        {
            result += (right - left);
            left++;
        }
        else
            right--;
    }

    return result;
}

static long long _02563_CountTheNumberOfFairPairs0(vector<int> &nums, int lower, int upper)
{
    sort(nums.begin(), nums.end());

    return lower_bound(nums, upper + 1) - lower_bound(nums, lower);
}
#pragma endregion

#pragma region Speed, Recursive
static long long countLess(vector<int> &nums, int val)
{
    long long res = 0;

    for (int i = 0, j = nums.size() - 1; i < j; ++i)
    {
        while (i < j && nums[i] + nums[j] > val)
            --j;
    
        res += j - i;
    }
    
    return res;
}

static long long _02563_CountTheNumberOfFairPairs1(vector<int> &nums, int lower, int upper)
{
    sort(begin(nums), end(nums));
    
    return countLess(nums, upper) - countLess(nums, lower - 1);
}
#pragma endregion

#pragma region GTest
static int is_02563_CountTheNumberOfFairPairs_RunTest()
{
    stringstream ss;
    ss << "*_02563_CountTheNumberOfFairPairs.expected*"
       << ":"
       << "*_02563_CountTheNumberOfFairPairs0.expected*"
       << ":"
       << "*_02563_CountTheNumberOfFairPairs1.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_02563_CountTheNumberOfFairPairs, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        long long expected = v2[i];

        // Actual
        long long actual = _02563_CountTheNumberOfFairPairs(v[i], v0[i], v1[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02563_CountTheNumberOfFairPairs0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        long long expected = v2[i];

        // Actual
        long long actual = _02563_CountTheNumberOfFairPairs0(v[i], v0[i], v1[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02563_CountTheNumberOfFairPairs1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        long long expected = v2[i];

        // Actual
        long long actual = _02563_CountTheNumberOfFairPairs1(v[i], v0[i], v1[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
