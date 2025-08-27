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
static vector<int> _00075_SortColors(vector<int> &nums);
// LeetCode problem
static vector<int> _00075_SortColors0(vector<int> &nums);

static int is_00075_SortColors_RunTest();

/**
 * Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent,
 * with the colors in the order red, white, and blue.
 * We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
 * You must solve this problem without using the library's sort function.
 *
 * Constraints:
 *
 * n == nums.length
 * 1 <= n <= 300
 * nums[i] is either 0, 1, or 2.
 *
 * Follow up: Could you come up with a one-pass algorithm using only constant extra space?
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_00075_SortColors_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<vector<int>> v;
static vector<vector<int>> v0;

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

        s.clear();
        getline(cin, s);
        ss.clear();
        ss.str(s);
        t.clear();
        d.clear();
        while (getline(ss, t, ','))
        {
            d.push_back(stoi(t));
        }
        v0.push_back(d);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        vector<int> res = _00075_SortColors(v[i]);
        for (auto &&i : res)
        {
            cout << i << " ";
        }
        cout << "\n";

        vector<int> res0 = _00075_SortColors(v[i]);
        for (auto &&i : res0)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
}

static vector<int> _00075_SortColors(vector<int> &nums)
{
    int t;
    for (int i = 0; i < nums.size(); i++)
    {
        t = i;
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[j] < nums[t])
                t = j;
        }
        swap(nums[t], nums[i]);
    }

    return nums;
}

static vector<int> _00075_SortColors0(vector<int> &nums)
{
    int low = 0;
    int mid = 0;
    int high = nums.size() - 1;
    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[mid], nums[low]);
            mid++;
            low++;
        }
        else if (nums[mid] == 1)
            mid++;
        else
        {
            swap(nums[mid], nums[high]);
            high--;
        }
    }

    return nums;
}

#pragma region GTest
static int is_00075_SortColors_RunTest()
{
    stringstream ss;
    ss << "*_00075_SortColors.expected*"
       << ":"
       << "*_00075_SortColors0.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_00075_SortColors, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<int> expected = v0[i];

        // Actual
        vector<int> actual = _00075_SortColors(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_00075_SortColors0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<int> expected = v0[i];

        // Actual
        vector<int> actual = _00075_SortColors0(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
