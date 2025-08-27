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
static vector<bool> _03152_SpecialArrayII(vector<int> &nums, vector<vector<int>> &queries);
// Prefix Sum
static vector<bool> _03152_SpecialArrayII0(vector<int> &nums, vector<vector<int>> &queries);
// Sliding Window
static vector<bool> _03152_SpecialArrayII1(vector<int> &nums, vector<vector<int>> &queries);
// Speed
static vector<bool> _03152_SpecialArrayII2(vector<int> &nums, vector<vector<int>> &queries);

static int is_03152_SpecialArrayII_RunTest();

/**
 * An array is considered special if every pair of its adjacent elements contains two numbers with different parity.
 * You are given an array of integer nums and a 2D integer matrix queries, where for queries[i] = [fromi, toi] your task
 * is to check that
 * subarray nums[fromi..toi] is special or not.
 * Return an array of booleans answer such that answer[i] is true if nums[fromi..toi] is special.
 *
 * Constraints:
 *
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^5
 * 1 <= queries.length <= 10^5
 * queries[i].length == 2
 * 0 <= queries[i][0] <= queries[i][1] <= nums.length - 1
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_03152_SpecialArrayII_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<vector<int>> v;
static vector<vector<vector<int>>> v0;
static vector<vector<bool>> v1;

static vector<vector<int>> stringTo2DVectorInt(string s)
{
    vector<vector<int>> res = {};
    int l = 0, r = 0;
    string a = "";
    vector<string> vv = {};
    for (auto &&j : s)
    {
        if (j == '[')
            l++;
        else if (j == ']')
        {
            r++;
            if (l > r)
            {
                vv.push_back(a);
                a = "";
            }
        }
        else
            a += j;
    }

    for (auto &&j : vv)
    {
        vector<int> a = {};
        string t;
        stringstream ss(j);
        while (getline(ss, t, ','))
        {
            if (t != "null" &&
                t != "")
                a.push_back(stoi(t));
        }
        res.push_back(a);
    }

    return res;
}

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

        s = "";
        getline(cin, s);
        v0.push_back(stringTo2DVectorInt(s));

        s = "";
        getline(cin, s);
        ss.clear();
        ss.str(s);
        t = "";
        vector<bool> d0 = {};
        while (getline(ss, t, ','))
        {
            d0.push_back(stoi(t));
        }
        v1.push_back(d0);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        vector<bool> res = _03152_SpecialArrayII(v[i], v0[i]);
        for (auto &&j : res)
        {
            cout << j << " ";
        }
        cout << "\n";

        vector<bool> res0 = _03152_SpecialArrayII0(v[i], v0[i]);
        for (auto &&j : res0)
        {
            cout << j << " ";
        }
        cout << "\n";

        vector<bool> res1 = _03152_SpecialArrayII1(v[i], v0[i]);
        for (auto &&j : res1)
        {
            cout << j << " ";
        }
        cout << "\n";

        vector<bool> res2 = _03152_SpecialArrayII2(v[i], v0[i]);
        for (auto &&j : res2)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
}

#pragma region Binary Search
static bool binarySearch(int start, int end, vector<int> &violatingIndices)
{
    int left = 0;
    int right = violatingIndices.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        int violatingIndex = violatingIndices[mid];

        if (violatingIndex < start)
            left = mid + 1;
        else if (violatingIndex > end)
            right = mid - 1;
        else
            return true;
    }

    return false;
}

static vector<bool> _03152_SpecialArrayII(vector<int> &nums, vector<vector<int>> &queries)
{
    vector<bool> ans(queries.size());
    vector<int> violatingIndices;

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] % 2 == nums[i - 1] % 2)
            violatingIndices.push_back(i);
    }

    for (int i = 0; i < queries.size(); i++)
    {
        vector<int> query = queries[i];
        int start = query[0];
        int end = query[1];

        bool foundViolatingIndex =
            binarySearch(start + 1, end, violatingIndices);

        if (foundViolatingIndex)
            ans[i] = false;
        else
            ans[i] = true;
    }

    return ans;
}
#pragma endregion

static vector<bool> _03152_SpecialArrayII0(vector<int> &nums, vector<vector<int>> &queries)
{
    vector<bool> ans(queries.size(), false);
    vector<int> prefix(nums.size(), 0);
    prefix[0] = 0;

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] % 2 == nums[i - 1] % 2)
            prefix[i] = prefix[i - 1] + 1;
        else
            prefix[i] = prefix[i - 1];
    }

    for (int i = 0; i < queries.size(); i++)
    {
        vector<int> query = queries[i];
        int start = query[0];
        int end = query[1];

        ans[i] = prefix[end] - prefix[start] == 0;
    }

    return ans;
}

static vector<bool> _03152_SpecialArrayII1(vector<int> &nums, vector<vector<int>> &queries)
{
    int n = nums.size();
    vector<int> maxReach(n);
    int end = 0;

    for (int start = 0; start < n; start++)
    {
        end = max(end, start);

        while (end < n - 1 && nums[end] % 2 != nums[end + 1] % 2)
        {
            ++end;
        }

        maxReach[start] = end;
    }

    vector<bool> ans(queries.size());

    for (int i = 0; i < queries.size(); i++)
    {
        vector<int> query = queries[i];
        int start = query[0];
        int end = query[1];
        ans[i] = end <= maxReach[start];
    }

    return ans;
}

static vector<bool> _03152_SpecialArrayII2(vector<int> &nums, vector<vector<int>> &queries)
{
    int n = nums.size();
    vector<int> maxR(n);
    int R = 0;

    for (int L = 0; L < n; L++)
    {
        R = max(R, L);

        while (R < (n - 1) && nums[R] % 2 != nums[R + 1] % 2)
        {
            ++R;
        }

        maxR[L] = R;
    }

    vector<bool> res(queries.size());

    for (int i = 0, qn = queries.size(); i < qn; i++)
    {
        res[i] = queries[i][1] <= maxR[queries[i][0]];
    }

    return res;
}

#pragma region GTest
static int is_03152_SpecialArrayII_RunTest()
{
    stringstream ss;

    ss << "*_03152_SpecialArrayII.expected*"
       << ":"
       << "*_03152_SpecialArrayII0.expected*"
       << ":"
       << "*_03152_SpecialArrayII1.expected*"
       << ":"
       << "*_03152_SpecialArrayII2.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_03152_SpecialArrayII, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<bool> expected = v1[i];

        // Actual
        vector<bool> actual = _03152_SpecialArrayII(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_03152_SpecialArrayII0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<bool> expected = v1[i];

        // Actual
        vector<bool> actual = _03152_SpecialArrayII0(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_03152_SpecialArrayII1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<bool> expected = v1[i];

        // Actual
        vector<bool> actual = _03152_SpecialArrayII1(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_03152_SpecialArrayII2, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<bool> expected = v1[i];

        // Actual
        vector<bool> actual = _03152_SpecialArrayII2(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
