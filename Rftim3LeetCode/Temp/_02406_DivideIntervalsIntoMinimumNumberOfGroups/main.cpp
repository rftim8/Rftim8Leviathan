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

// Sorting or Priority Queue
static int _02406_DivideIntervalsIntoMinimumNumberOfGroups(vector<vector<int>> &intervals);
// Line Sweep Algorithm With Ordered Container
static int _02406_DivideIntervalsIntoMinimumNumberOfGroups0(vector<vector<int>> &intervals);
// Line Sweep Algorithm Without Ordered Container
static int _02406_DivideIntervalsIntoMinimumNumberOfGroups1(vector<vector<int>> &intervals);
// Speed
static int _02406_DivideIntervalsIntoMinimumNumberOfGroups2(vector<vector<int>> &intervals);

static int is_02406_DivideIntervalsIntoMinimumNumberOfGroups_RunTest();

/**
 * You are given a 2D integer array intervals where intervals[i] = [lefti, righti] represents the inclusive interval [lefti, righti].
 * You have to divide the intervals into one or more groups such that each interval is in exactly one group,
 * and no two intervals that are in the same group intersect each other.
 * Return the minimum number of groups you need to make.
 * Two intervals intersect if there is at least one common number between them.
 * For example, the intervals [1, 5] and [5, 8] intersect.
 *
 * Constraints:
 *
 * 1 <= intervals.length <= 10^5
 * intervals[i].length == 2
 * 1 <= lefti <= righti <= 10^6
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_02406_DivideIntervalsIntoMinimumNumberOfGroups_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<vector<vector<int>>> v;
static vector<int> v0;

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
        v.push_back(stringTo2DVectorInt(s));

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
        cout << _02406_DivideIntervalsIntoMinimumNumberOfGroups(v[i]) << "\n";
        cout << _02406_DivideIntervalsIntoMinimumNumberOfGroups0(v[i]) << "\n";
        cout << _02406_DivideIntervalsIntoMinimumNumberOfGroups1(v[i]) << "\n";
        cout << _02406_DivideIntervalsIntoMinimumNumberOfGroups2(v[i]) << "\n";
    }
}

static int _02406_DivideIntervalsIntoMinimumNumberOfGroups(vector<vector<int>> &intervals)
{
    vector<pair<int, int>> intervalsWithEnd;

    for (vector<int> interval : intervals)
    {
        intervalsWithEnd.push_back({interval[0], 1});
        intervalsWithEnd.push_back({interval[1] + 1, -1});
    }

    sort(intervalsWithEnd.begin(), intervalsWithEnd.end());
    int concurrentIntervals = 0;
    int maxConcurrentIntervals = 0;

    for (auto p : intervalsWithEnd)
    {
        concurrentIntervals += p.second;
        maxConcurrentIntervals = max(maxConcurrentIntervals, concurrentIntervals);
    }

    return maxConcurrentIntervals;
}

static int _02406_DivideIntervalsIntoMinimumNumberOfGroups0(vector<vector<int>> &intervals)
{
    map<int, int> pointToCount;

    for (vector<int> interval : intervals)
    {
        pointToCount[interval[0]]++;
        pointToCount[interval[1] + 1]--;
    }

    int concurrentIntervals = 0;
    int maxConcurrentIntervals = 0;

    for (pair<int, int> p : pointToCount)
    {
        concurrentIntervals += p.second;
        maxConcurrentIntervals = max(maxConcurrentIntervals, concurrentIntervals);
    }

    return maxConcurrentIntervals;
}

static int _02406_DivideIntervalsIntoMinimumNumberOfGroups1(vector<vector<int>> &intervals)
{
    int rangeStart = INT_MAX;
    int rangeEnd = INT_MIN;

    for (vector<int> interval : intervals)
    {
        rangeStart = min(rangeStart, interval[0]);
        rangeEnd = max(rangeEnd, interval[1]);
    }

    vector<int> pointToCount(rangeEnd + 2, 0);

    for (vector<int> interval : intervals)
    {
        pointToCount[interval[0]]++;
        pointToCount[interval[1] + 1]--;
    }

    int concurrentIntervals = 0;
    int maxConcurrentIntervals = 0;

    for (int i = rangeStart; i <= rangeEnd; i++)
    {
        concurrentIntervals += pointToCount[i];
        maxConcurrentIntervals = max(maxConcurrentIntervals, concurrentIntervals);
    }

    return maxConcurrentIntervals;
}

static int _02406_DivideIntervalsIntoMinimumNumberOfGroups2(vector<vector<int>> &intervals)
{
    const int n = intervals.size();
    vector<pair<int, int>> P;

    for (auto &I : intervals)
    {
        int x = I[0], y = I[1] + 1;
        P.emplace_back(x, 1);
        P.emplace_back(y, -1);
    }

    sort(P.begin(), P.end());
    int cnt = 0, x = 0;

    for (auto &[_, f] : P)
    {
        x += f;
        cnt = max(cnt, x);
    }

    return cnt;
}

#pragma region GTest
static int is_02406_DivideIntervalsIntoMinimumNumberOfGroups_RunTest()
{
    stringstream ss;
    ss << "*_02406_DivideIntervalsIntoMinimumNumberOfGroups.expected*"
       << ":"
       << "*_02406_DivideIntervalsIntoMinimumNumberOfGroups0.expected*"
       << ":"
       << "*_02406_DivideIntervalsIntoMinimumNumberOfGroups1.expected*"
       << ":"
       << "*_02406_DivideIntervalsIntoMinimumNumberOfGroups2.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_02406_DivideIntervalsIntoMinimumNumberOfGroups, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _02406_DivideIntervalsIntoMinimumNumberOfGroups(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02406_DivideIntervalsIntoMinimumNumberOfGroups0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _02406_DivideIntervalsIntoMinimumNumberOfGroups0(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02406_DivideIntervalsIntoMinimumNumberOfGroups1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _02406_DivideIntervalsIntoMinimumNumberOfGroups1(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02406_DivideIntervalsIntoMinimumNumberOfGroups2, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _02406_DivideIntervalsIntoMinimumNumberOfGroups2(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
