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
static int _00962_MaximumWidthRamp(vector<int> &nums);
// Sorting
static int _00962_MaximumWidthRamp0(vector<int> &nums);
// Two Pointers
static int _00962_MaximumWidthRamp1(vector<int> &nums);
// Monotonic Stack
static int _00962_MaximumWidthRamp2(vector<int> &nums);
// Speed
static int _00962_MaximumWidthRamp3(vector<int> &nums);

static int is_00962_MaximumWidthRamp_RunTest();

/**
 * A ramp in an integer array nums is a pair (i, j) for which i < j and nums[i] <= nums[j].
 * The width of such a ramp is j - i.
 * Given an integer array nums, return the maximum width of a ramp in nums.
 * If there is no ramp in nums, return 0.
 *
 * Constraints:
 *
 * 2 <= nums.length <= 5 * 10^4
 * 0 <= nums[i] <= 5 * 10^4
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_00962_MaximumWidthRamp_RunTest();
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
        vector<int> vv = {};
        while (getline(ss, t, ','))
        {
            vv.push_back(stoi(t));
        }
        v.push_back(vv);

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
        cout << _00962_MaximumWidthRamp(v[i]) << "\n";
        cout << _00962_MaximumWidthRamp0(v[i]) << "\n";
        cout << _00962_MaximumWidthRamp1(v[i]) << "\n";
        cout << _00962_MaximumWidthRamp2(v[i]) << "\n";
        cout << _00962_MaximumWidthRamp3(v[i]) << "\n";
    }
}

static int _00962_MaximumWidthRamp(vector<int> &nums)
{
    int n = nums.size();
    int maxWidth = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (nums[i] <= nums[j])
                maxWidth = max(maxWidth, j - i);
        }
    }

    return maxWidth;
}

static int _00962_MaximumWidthRamp0(vector<int> &nums)
{
    int n = nums.size();
    vector<int> indices(n);

    for (int i = 0; i < n; i++)
    {
        indices[i] = i;
    }

    sort(indices.begin(), indices.end(), [&](int i, int j)
         { return nums[i] != nums[j] ? nums[i] < nums[j] : i < j; });

    int minIndex = n;
    int maxWidth = 0;

    for (int i = 0; i < n; i++)
    {
        maxWidth = max(maxWidth, indices[i] - minIndex);
        minIndex = min(minIndex, indices[i]);
    }

    return maxWidth;
}

static int _00962_MaximumWidthRamp1(vector<int> &nums)
{
    int n = nums.size();
    vector<int> rightMax(n);
    rightMax[n - 1] = nums[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        rightMax[i] = max(rightMax[i + 1], nums[i]);
    }

    int left = 0, right = 0;
    int maxWidth = 0;

    while (right < n)
    {
        while (left < right && nums[left] > rightMax[right])
        {
            left++;
        }

        maxWidth = max(maxWidth, right - left);
        right++;
    }

    return maxWidth;
}

static int _00962_MaximumWidthRamp2(vector<int> &nums)
{
    int n = nums.size();
    stack<int> indicesStack;

    for (int i = 0; i < n; i++)
    {
        if (indicesStack.empty() ||
            nums[indicesStack.top()] > nums[i])
            indicesStack.push(i);
    }

    int maxWidth = 0;

    for (int j = n - 1; j >= 0; j--)
    {
        while (!indicesStack.empty() &&
               nums[indicesStack.top()] <= nums[j])
        {
            maxWidth = max(maxWidth, j - indicesStack.top());
            indicesStack.pop();
        }
    }

    return maxWidth;
}

static int _00962_MaximumWidthRamp3(vector<int> &nums)
{
    int n = nums.size();
    stack<int> st;

    st.push(0);

    for (int i = 1; i < n; i++)
    {
        if (nums[st.top()] > nums[i])
            st.push(i);
    }

    int ans = 0;

    for (int i = n - 1; i >= 0;)
    {
        while (!st.empty() and nums[st.top()] <= nums[i])
        {
            ans = max(ans, i - st.top());
            st.pop();
        }

        if (st.empty())
            break;

        i--;
    }

    return ans;
}

#pragma region GTest
static int is_00962_MaximumWidthRamp_RunTest()
{
    stringstream ss;
    ss << "*_00962_MaximumWidthRamp.expected*"
       << ":"
       << "*_00962_MaximumWidthRamp0.expected*"
       << ":"
       << "*_00962_MaximumWidthRamp1.expected*"
       << ":"
       << "*_00962_MaximumWidthRamp2.expected*"
       << ":"
       << "*_00962_MaximumWidthRamp3.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_00962_MaximumWidthRamp, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _00962_MaximumWidthRamp(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_00962_MaximumWidthRamp0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _00962_MaximumWidthRamp0(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_00962_MaximumWidthRamp1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _00962_MaximumWidthRamp1(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_00962_MaximumWidthRamp2, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _00962_MaximumWidthRamp2(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_00962_MaximumWidthRamp3, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _00962_MaximumWidthRamp3(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
