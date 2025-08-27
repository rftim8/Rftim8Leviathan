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

// Top-Down DP
static int _02054_TwoBestNonOverlappingEvents(vector<vector<int>> &events);
// Min Heap
static int _02054_TwoBestNonOverlappingEvents0(vector<vector<int>> &events);
// Greedy
static int _02054_TwoBestNonOverlappingEvents1(vector<vector<int>> &events);
// Speed
static int _02054_TwoBestNonOverlappingEvents2(vector<vector<int>> &events);

static int is_02054_TwoBestNonOverlappingEvents_RunTest();

/**
 * You are given a 0-indexed 2D integer array of events where events[i] = [startTimei, endTimei, valuei].
 * The ith event starts at startTimei and ends at endTimei, and if you attend this event, you will receive a value of valuei.
 * You can choose at most two non-overlapping events to attend such that the sum of their values is maximized.
 * Return this maximum sum.
 * Note that the start time and end time is inclusive: that is, you cannot attend two events where one of them starts
 * and the other ends at the same time.
 * More specifically, if you attend an event with end time t, the next event must start at or after t + 1.
 *
 * Constraints:
 *
 * 2 <= events.length <= 10^5
 * events[i].length == 3
 * 1 <= startTimei <= endTimei <= 10^9
 * 1 <= valuei <= 10^6
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_02054_TwoBestNonOverlappingEvents_RunTest();
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
        cout << _02054_TwoBestNonOverlappingEvents(v[i]) << "\n";
        cout << _02054_TwoBestNonOverlappingEvents0(v[i]) << "\n";
        cout << _02054_TwoBestNonOverlappingEvents1(v[i]) << "\n";
        cout << _02054_TwoBestNonOverlappingEvents2(v[i]) << "\n";
    }
}

#pragma region Top-Down DP
static int findEvents(vector<vector<int>> &events, int idx, int cnt,
                      vector<vector<int>> &dp)
{
    if (cnt == 2 || idx >= events.size())
        return 0;

    if (dp[idx][cnt] == -1)
    {
        int end = events[idx][1];
        int lo = idx + 1, hi = events.size() - 1;

        while (lo < hi)
        {
            int mid = lo + ((hi - lo) >> 1);

            if (events[mid][0] > end)
                hi = mid;
            else
                lo = mid + 1;
        }

        int include = events[idx][2] + (lo < events.size() && events[lo][0] > end
                                            ? findEvents(events, lo, cnt + 1, dp)
                                            : 0);
        int exclude = findEvents(events, idx + 1, cnt, dp);
        dp[idx][cnt] = max(include, exclude);
    }

    return dp[idx][cnt];
}

static int _02054_TwoBestNonOverlappingEvents(vector<vector<int>> &events)
{
    sort(events.begin(), events.end());
    vector<vector<int>> dp(events.size(), vector<int>(3, -1));
    return findEvents(events, 0, 0, dp);
}
#pragma endregion

static int _02054_TwoBestNonOverlappingEvents0(vector<vector<int>> &events)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    sort(events.begin(), events.end());
    int maxVal = 0, maxSum = 0;

    for (auto &event : events)
    {
        while (pq.size() && pq.top().first < event[0])
        {
            maxVal = max(maxVal, pq.top().second);
            pq.pop();
        }

        maxSum = max(maxSum, maxVal + event[2]);
        pq.push({event[1], event[2]});
    }

    return maxSum;
}

static int _02054_TwoBestNonOverlappingEvents1(vector<vector<int>> &events)
{
    vector<array<int, 3>> times;

    for (auto &e : events)
    {
        times.push_back({e[0], 1, e[2]});
        times.push_back({e[1] + 1, 0, e[2]});
    }

    int ans = 0, maxValue = 0;
    sort(begin(times), end(times));

    for (auto &timeValue : times)
    {
        if (timeValue[1])
            ans = max(ans, timeValue[2] + maxValue);
        else
            maxValue = max(maxValue, timeValue[2]);
    }

    return ans;
}

static int _02054_TwoBestNonOverlappingEvents2(vector<vector<int>> &events)
{
    using Event = array<int, 3>;

    auto sortval = [&](auto &&a, auto &&b) -> bool
    {
        return (a[2] > b[2]) || (a[2] == b[2] && a < b);
    };

    set<Event, decltype(sortval)> byVal(sortval);
    priority_queue<Event, vector<Event>, greater<>> byLeft;

    sort(events.begin(), events.end(), [](auto &&a, auto &&b) -> bool
         { return a[1] < b[1]; });

    for (auto &event : events)
    {
        byVal.insert({event[0], event[1], event[2]});
        byLeft.push({event[0], event[1], event[2]});
    }

    int ans = 0;

    for (auto &event : events)
    {
        while (!byLeft.empty() && byLeft.top()[0] <= event[1])
        {
            byVal.erase(byLeft.top());
            byLeft.pop();
        }

        if (byVal.empty())
            ans = max(ans, event[2]);
        else
            ans = max(ans, event[2] + (*byVal.begin())[2]);
    }

    return ans;
}

#pragma region GTest
static int is_02054_TwoBestNonOverlappingEvents_RunTest()
{
    stringstream ss;
    ss << "*_02054_TwoBestNonOverlappingEvents.expected*"
       << ":"
       << "*_02054_TwoBestNonOverlappingEvents0.expected*"
       << ":"
       << "*_02054_TwoBestNonOverlappingEvents1.expected*"
       << ":"
       << "*_02054_TwoBestNonOverlappingEvents2.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_02054_TwoBestNonOverlappingEvents, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _02054_TwoBestNonOverlappingEvents(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02054_TwoBestNonOverlappingEvents0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _02054_TwoBestNonOverlappingEvents0(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02054_TwoBestNonOverlappingEvents1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _02054_TwoBestNonOverlappingEvents1(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02054_TwoBestNonOverlappingEvents2, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _02054_TwoBestNonOverlappingEvents2(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
