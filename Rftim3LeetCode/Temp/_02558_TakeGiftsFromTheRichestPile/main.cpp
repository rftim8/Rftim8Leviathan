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
static long long _02558_TakeGiftsFromTheRichestPile(vector<int> &gifts, int k);
// Speed
static long long _02558_TakeGiftsFromTheRichestPile0(vector<int> &gifts, int k);

static int is_02558_TakeGiftsFromTheRichestPile_RunTest();

/**
 * You are given an integer array gifts denoting the number of gifts in various piles.
 * Every second, you do the following:
 * Choose the pile with the maximum number of gifts.
 * If there is more than one pile with the maximum number of gifts, choose any.
 * Leave behind the floor of the square root of the number of gifts in the pile.
 * Take the rest of the gifts.
 * Return the number of gifts remaining after k seconds.
 *
 * Constraints:
 *
 * 1 <= gifts.length <= 10^3
 * 1 <= gifts[i] <= 10^9
 * 1 <= k <= 10^3
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_02558_TakeGiftsFromTheRichestPile_RunTest();
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
        cout << _02558_TakeGiftsFromTheRichestPile(v[i], v0[i]) << "\n";
        cout << _02558_TakeGiftsFromTheRichestPile0(v[i], v0[i]) << "\n";
    }
}

static long long _02558_TakeGiftsFromTheRichestPile(vector<int> &gifts, int k)
{
    vector<int> v(gifts);
    for (int i = 0; i < k; i++)
    {
        sort(v.begin(), v.end());
        v.back() = (int)floor(sqrt(v.back()));
    }

    long long res = 0;
    for (auto &&i : v)
    {
        res += (long long)i;
    }

    return res;
}

static long long _02558_TakeGiftsFromTheRichestPile0(vector<int> &gifts, int k)
{
    priority_queue<int> q;
    long long ans = 0;

    for (int i : gifts)
    {
        q.push(i);
        ans += i;
    }

    while (k--)
    {
        int v = q.top();
        ans -= (v - sqrt(v));
        q.pop();
        q.push(sqrt(v));
    }

    return ans;
}

#pragma region GTest
static int is_02558_TakeGiftsFromTheRichestPile_RunTest()
{
    stringstream ss;
    ss << "*_02558_TakeGiftsFromTheRichestPile.expected*"
       << ":"
       << "*_02558_TakeGiftsFromTheRichestPile0.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_02558_TakeGiftsFromTheRichestPile, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        long long expected = v1[i];

        // Actual
        long long actual = _02558_TakeGiftsFromTheRichestPile(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02558_TakeGiftsFromTheRichestPile0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        long long expected = v1[i];

        // Actual
        long long actual = _02558_TakeGiftsFromTheRichestPile0(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
