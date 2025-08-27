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

// Brute Force
static vector<int> _01475_FinalPricesWithASpecialDiscountInAShop(vector<int> &prices);
// Monotonic Stack
static vector<int> _01475_FinalPricesWithASpecialDiscountInAShop0(vector<int> &prices);

static int is_01475_FinalPricesWithASpecialDiscountInAShop_RunTest();

/**
 * You are given an integer array prices where prices[i] is the price of the ith item in a shop.
 * There is a special discount for items in the shop.
 * If you buy the ith item, then you will receive a discount equivalent to prices[j] where j is the minimum
 * index such that j > i and prices[j] <= prices[i].
 * Otherwise, you will not receive any discount at all.
 * Return an integer array answer where answer[i] is the final price you will pay for the ith item of the shop,
 * considering the special discount.
 *
 * Constraints:
 *
 * 1 <= prices.length <= 500
 * 1 <= prices[i] <= 1000
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_01475_FinalPricesWithASpecialDiscountInAShop_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<vector<int>> v, v0;

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
        ss.clear();
        ss.str(s);
        t = "";
        d = {};
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
        vector<int> res = _01475_FinalPricesWithASpecialDiscountInAShop(v[i]);
        for (auto &&j : res)
        {
            cout << j << " ";
        }
        cout << "\n";

        vector<int> res0 = _01475_FinalPricesWithASpecialDiscountInAShop0(v[i]);
        for (auto &&j : res0)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
}

static vector<int> _01475_FinalPricesWithASpecialDiscountInAShop(vector<int> &prices0)
{
    vector<int> prices(prices0);
    int n = prices.size();
    if (n == 1)
        return prices;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (prices[j] <= prices[i])
            {
                prices[i] -= prices[j];
                break;
            }
        }
    }

    return prices;
}

static vector<int> _01475_FinalPricesWithASpecialDiscountInAShop0(vector<int> &prices)
{
    vector<int> result = prices;
    stack<int> stack;

    for (int i = 0; i < prices.size(); i++)
    {
        while (!stack.empty() && prices[stack.top()] >= prices[i])
        {
            result[stack.top()] -= prices[i];
            stack.pop();
        }

        stack.push(i);
    }

    return result;
}

#pragma region GTest
static int is_01475_FinalPricesWithASpecialDiscountInAShop_RunTest()
{
    stringstream ss;
    ss << "*_01475_FinalPricesWithASpecialDiscountInAShop.expected*"
       << ":"
       << "*_01475_FinalPricesWithASpecialDiscountInAShop0.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_01475_FinalPricesWithASpecialDiscountInAShop, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<int> expected = v0[i];

        // Actual
        vector<int> actual = _01475_FinalPricesWithASpecialDiscountInAShop(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_01475_FinalPricesWithASpecialDiscountInAShop0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<int> expected = v0[i];

        // Actual
        vector<int> actual = _01475_FinalPricesWithASpecialDiscountInAShop0(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
