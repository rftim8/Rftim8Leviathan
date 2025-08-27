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

// Bottom-Up DP
static int _00983_MinimumCostForTickets(vector<int> &days, vector<int> &costs);
// Top-Down DP
static int _00983_MinimumCostForTickets0(vector<int> &days, vector<int> &costs);

static int is_00983_MinimumCostForTickets_RunTest();

/**
 * You have planned some train traveling one year in advance.
 * The days of the year in which you will travel are given as an integer array days.
 * Each day is an integer from 1 to 365.
 * Train tickets are sold in three different ways:
 * a 1-day pass is sold for costs[0] dollars,
 * a 7-day pass is sold for costs[1] dollars, and
 * a 30-day pass is sold for costs[2] dollars.
 * The passes allow that many days of consecutive travel.
 * For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
 * Return the minimum number of dollars you need to travel every day in the given list of days.
 *
 * Constraints:
 *
 * 1 <= days.length <= 365
 * 1 <= days[i] <= 365
 * days is in strictly increasing order.
 * costs.length == 3
 * 1 <= costs[i] <= 1000
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_00983_MinimumCostForTickets_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<vector<int>> v, v0;
static vector<int> v1;

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

        int s0;
        cin >> s0;
        cin.get();
        v1.push_back(s0);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        cout << _00983_MinimumCostForTickets(v[i], v0[i]) << "\n";
        cout << _00983_MinimumCostForTickets0(v[i], v0[i]) << "\n";
    }
}

static int _00983_MinimumCostForTickets(vector<int> &days, vector<int> &costs)
{
    int lastDay = days.back();
    vector<int> dp(lastDay + 1, 0);
    int i = 0;

    for (int day = 1; day <= lastDay; day++)
    {
        if (day < days[i])
            dp[day] = dp[day - 1];
        else
        {
            i++;
            dp[day] = min(dp[day - 1] + costs[0], min(dp[max(0, day - 7)] + costs[1], dp[max(0, day - 30)] + costs[2]));
        }
    }

    return dp[lastDay];
}

#pragma region Top-Down DP
static unordered_set<int> isTravelNeeded;

static int solve(vector<int> &dp, vector<int> &days, vector<int> &costs, int currDay)
{
    if (currDay > days[days.size() - 1])
        return 0;

    if (isTravelNeeded.find(currDay) == isTravelNeeded.end())
        return solve(dp, days, costs, currDay + 1);

    if (dp[currDay] != -1)
        return dp[currDay];

    int oneDay = costs[0] + solve(dp, days, costs, currDay + 1);
    int sevenDay = costs[1] + solve(dp, days, costs, currDay + 7);
    int thirtyDay = costs[2] + solve(dp, days, costs, currDay + 30);

    return dp[currDay] = min(oneDay, min(sevenDay, thirtyDay));
}

static int _00983_MinimumCostForTickets0(vector<int> &days, vector<int> &costs)
{
    int lastDay = days[days.size() - 1];
    vector<int> dp(lastDay + 1, -1);

    for (int day : days)
    {
        isTravelNeeded.insert(day);
    }

    return solve(dp, days, costs, 1);
}
#pragma endregion

#pragma region GTest
static int is_00983_MinimumCostForTickets_RunTest()
{
    stringstream ss;
    ss << "*_00983_MinimumCostForTickets.expected*"
       << ":"
       << "*_00983_MinimumCostForTickets0.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_00983_MinimumCostForTickets, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v1[i];

        // Actual
        int actual = _00983_MinimumCostForTickets(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_00983_MinimumCostForTickets0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v1[i];

        // Actual
        int actual = _00983_MinimumCostForTickets0(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
