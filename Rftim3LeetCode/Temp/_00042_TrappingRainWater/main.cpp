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

// Two Pointers
static int _00042_TrappingRainWater(vector<int> &height);
// Two Pointers Optimized
static int _00042_TrappingRainWater0(vector<int> &height);
// Stack
static int _00042_TrappingRainWater1(vector<int> &height);

static int is_00042_TrappingRainWater_RunTest();

/**
 * Given n non-negative integers representing an elevation map where the width of each bar is 1,
 * compute how much water it can trap after raining.
 * Constraints:
 *
 * n == height.length
 * 1 <= n <= 2 * 10^4
 * 0 <= height[i] <= 10^5
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_00042_TrappingRainWater_RunTest();
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
        cout << _00042_TrappingRainWater(v[i]) << "\n";
        cout << _00042_TrappingRainWater0(v[i]) << "\n";
        cout << _00042_TrappingRainWater1(v[i]) << "\n";
    }
}

static int _00042_TrappingRainWater(vector<int> &height)
{
    int res = 0;
    int l = 0, r = height.size() - 1;
    int l0 = 0, r0 = 0;

    while (l < r)
    {
        if (height[l] < height[r])
        {
            if (height[l] >= l0)
                l0 = height[l];
            else
                res += l0 - height[l];
            l++;
        }
        else
        {
            if (height[r] >= r0)
                r0 = height[r];
            else
                res += r0 - height[r];
            r--;
        }
    }

    return res;
}

static int _00042_TrappingRainWater0(vector<int> &h)
{
    int l = 0, r = h.size() - 1, lmax = INT_MIN, rmax = INT_MIN, ans = 0;

    while (l < r)
    {
        lmax = max(lmax, h[l]);
        rmax = max(rmax, h[r]);
        ans += (lmax < rmax) ? lmax - h[l++] : rmax - h[r--];
    }

    return ans;
}

static int _00042_TrappingRainWater1(vector<int> &height)
{
    int ans = 0, current = 0;
    stack<int> st;

    while (current < height.size())
    {
        while (!st.empty() && height[current] > height[st.top()])
        {
            int top = st.top();
            st.pop();

            if (st.empty())
                break;

            int distance = current - st.top() - 1;
            int bounded_height = min(height[current], height[st.top()]) - height[top];
            ans += distance * bounded_height;
        }

        st.push(current++);
    }

    return ans;
}

#pragma region GTest
static int is_00042_TrappingRainWater_RunTest()
{
    stringstream ss;
    ss << "*_00042_TrappingRainWater.expected*"
       << ":"
       << "*_00042_TrappingRainWater0.expected*"
       << ":"
       << "*_00042_TrappingRainWater1.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_00042_TrappingRainWater, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _00042_TrappingRainWater(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_00042_TrappingRainWater0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _00042_TrappingRainWater0(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_00042_TrappingRainWater1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _00042_TrappingRainWater1(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
