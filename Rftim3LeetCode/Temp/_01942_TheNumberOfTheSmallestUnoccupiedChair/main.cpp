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
static int _01942_TheNumberOfTheSmallestUnoccupiedChair(vector<vector<int>> &times, int targetFriend);
// Event-Based Two Priority Queues
static int _01942_TheNumberOfTheSmallestUnoccupiedChair0(vector<vector<int>> &times, int targetFriend);
// Set With Sorted Insertion
static int _01942_TheNumberOfTheSmallestUnoccupiedChair1(vector<vector<int>> &times, int targetFriend);
// Speed
static int _01942_TheNumberOfTheSmallestUnoccupiedChair2(vector<vector<int>> &times, int targetFriend);

static int is_01942_TheNumberOfTheSmallestUnoccupiedChair_RunTest();

/**
 * There is a party where n friends numbered from 0 to n - 1 are attending.
 * There is an infinite number of chairs in this party that are numbered from 0 to infinity.
 * When a friend arrives at the party, they sit on the unoccupied chair with the smallest number.
 * For example, if chairs 0, 1, and 5 are occupied when a friend comes, they will sit on chair number 2.
 * When a friend leaves the party, their chair becomes unoccupied at the moment they leave.
 * If another friend arrives at that same moment, they can sit in that chair.
 * You are given a 0-indexed 2D integer array times where times[i] = [arrivali, leavingi],
 * indicating the arrival and leaving times of the ith friend respectively, and an integer targetFriend.
 * All arrival times are distinct.
 * Return the chair number that the friend numbered targetFriend will sit on.
 *
 * Constraints:
 *
 * n == times.length
 * 2 <= n <= 10^4
 * times[i].length == 2
 * 1 <= arrivali < leavingi <= 10^5
 * 0 <= targetFriend <= n - 1
 * Each arrivali time is distinct.
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_01942_TheNumberOfTheSmallestUnoccupiedChair_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<vector<vector<int>>> v;
static vector<int> v0, v1;

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
        cout << _01942_TheNumberOfTheSmallestUnoccupiedChair(v[i], v0[i]) << "\n";
        cout << _01942_TheNumberOfTheSmallestUnoccupiedChair0(v[i], v0[i]) << "\n";
        cout << _01942_TheNumberOfTheSmallestUnoccupiedChair1(v[i], v0[i]) << "\n";
        cout << _01942_TheNumberOfTheSmallestUnoccupiedChair2(v[i], v0[i]) << "\n";
    }
}

static int _01942_TheNumberOfTheSmallestUnoccupiedChair(vector<vector<int>> &times, int targetFriend)
{
    vector<vector<int>> times0 = times;
    vector<int> targetTime = times0[targetFriend];
    sort(times0.begin(), times0.end());
    int n = times0.size();
    vector<int> chairTime(n);

    for (auto time : times0)
    {
        for (int i = 0; i < n; i++)
        {
            if (chairTime[i] <= time[0])
            {
                chairTime[i] = time[1];

                if (time == targetTime)
                    return i;

                break;
            }
        }
    }

    return 0;
}

static int _01942_TheNumberOfTheSmallestUnoccupiedChair0(vector<vector<int>> &times, int targetFriend)
{
    int n = times.size();
    vector<pair<int, int>> events;

    for (int i = 0; i < n; i++)
    {
        events.push_back({times[i][0], i});
        events.push_back({times[i][1], ~i});
    }

    sort(events.begin(), events.end());
    priority_queue<int, vector<int>, greater<int>> availableChairs;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> occupiedChairs;

    for (int i = 0; i < n; i++)
        availableChairs.push(i);

    for (auto &event : events)
    {
        int time = event.first;
        int friendIndex = event.second;

        while (!occupiedChairs.empty() &&
               occupiedChairs.top().first <= time)
        {
            availableChairs.push(occupiedChairs.top().second);
            occupiedChairs.pop();
        }

        if (friendIndex >= 0)
        {
            int chair = availableChairs.top();
            availableChairs.pop();

            if (friendIndex == targetFriend)
                return chair;

            occupiedChairs.push({times[friendIndex][1], chair});
        }
    }

    return -1;
}

static int _01942_TheNumberOfTheSmallestUnoccupiedChair1(vector<vector<int>> &times, int targetFriend)
{
    vector<vector<int>> times0 = times;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> leavingQueue;
    int targetArrival = times0[targetFriend][0];
    sort(times0.begin(), times0.end());
    int nextChair = 0;
    set<int> availableChairs;

    for (auto time : times0)
    {
        int arrival = time[0];
        int leave = time[1];

        while (!leavingQueue.empty() &&
               leavingQueue.top().first <= arrival)
        {
            availableChairs.insert(leavingQueue.top().second);
            leavingQueue.pop();
        }

        int currentChair;

        if (!availableChairs.empty())
        {
            currentChair = *availableChairs.begin();
            availableChairs.erase(availableChairs.begin());
        }
        else
            currentChair = nextChair++;

        leavingQueue.push({leave, currentChair});

        if (arrival == targetArrival)
            return currentChair;
    }

    return 0;
}

static int _01942_TheNumberOfTheSmallestUnoccupiedChair2(vector<vector<int>> &times, int targetFriend)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    priority_queue<int, vector<int>, greater<int>> chairs;
    targetFriend = times[targetFriend][0];
    sort(times.begin(), times.end());
    int start = 0;
    int ans = 0;

    for (int i = 0;; i++)
    {
        int at = times[i][0];
        int ct = times[i][1];

        while (!pq.empty() and pq.top().first <= at)
        {
            chairs.push(pq.top().second);
            pq.pop();
        }

        if (!chairs.empty())
        {
            ans = chairs.top();
            chairs.pop();
        }
        else
        {
            ans = start;
            start++;
        }

        pq.push({ct, ans});

        if (at == targetFriend)
            break;
    }

    return ans;
}

#pragma region GTest
static int is_01942_TheNumberOfTheSmallestUnoccupiedChair_RunTest()
{
    stringstream ss;
    ss << "*_01942_TheNumberOfTheSmallestUnoccupiedChair.expected*"
       << ":"
       << "*_01942_TheNumberOfTheSmallestUnoccupiedChair0.expected*"
       << ":"
       << "*_01942_TheNumberOfTheSmallestUnoccupiedChair1.expected*"
       << ":"
       << "*_01942_TheNumberOfTheSmallestUnoccupiedChair2.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_01942_TheNumberOfTheSmallestUnoccupiedChair, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v1[i];

        // Actual
        int actual = _01942_TheNumberOfTheSmallestUnoccupiedChair(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_01942_TheNumberOfTheSmallestUnoccupiedChair0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v1[i];

        // Actual
        int actual = _01942_TheNumberOfTheSmallestUnoccupiedChair0(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_01942_TheNumberOfTheSmallestUnoccupiedChair1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v1[i];

        // Actual
        int actual = _01942_TheNumberOfTheSmallestUnoccupiedChair1(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_01942_TheNumberOfTheSmallestUnoccupiedChair2, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v1[i];

        // Actual
        int actual = _01942_TheNumberOfTheSmallestUnoccupiedChair2(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
