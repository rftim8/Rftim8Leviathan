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
static vector<string> _00729_MyCalendarI(vector<string> v, vector<vector<int>> v0);
// Sorted List + Binary Search
static vector<string> _00729_MyCalendarI0(vector<string> v, vector<vector<int>> v0);

static int is_00729_MyCalendarI_RunTest();

/**
 * You are implementing a program to use as your calendar.
 * We can add a new event if adding the event will not cause a double booking.
 * A double booking happens when two events have some non-empty intersection (i.e., some moment is common to both events.).
 * The event can be represented as a pair of integers start and end that represents a booking
 * on the half-open interval [start, end), the range of real numbers x such that start <= x < end.
 *
 * Implement the MyCalendar class:
 *
 * MyCalendar() Initializes the calendar object.
 * boolean book(int start, int end) Returns true if the event can be added to the calendar successfully
 * without causing a double booking.
 * Otherwise, return false and do not add the event to the calendar.
 *
 * Constraints:
 *
 * 0 <= start < end <= 10^9
 * At most 1000 calls will be made to book.
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_00729_MyCalendarI_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<vector<string>> v, v1;
static vector<vector<vector<int>>> v0;

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
        string t = "";
        vector<string> vv = {};
        while (getline(ss, t, ','))
        {
            vv.push_back(t);
        }
        v.push_back(vv);

        s = "";
        getline(cin, s);
        v0.push_back(stringTo2DVectorInt(s));

        s = "";
        getline(cin, s);
        ss.clear();
        ss.str(s);
        t = "";
        vv = {};
        while (getline(ss, t, ','))
        {
            vv.push_back(t);
        }
        v1.push_back(vv);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        vector<string> res = _00729_MyCalendarI(v[i], v0[i]);
        for (auto &&j : res)
        {
            cout << j << " ";
        }
        cout << "\n";

        vector<string> res0 = _00729_MyCalendarI0(v[i], v0[i]);
        for (auto &&j : res0)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
}

class MyCalendar
{
public:
    vector<pair<int, int>> calendar;

    MyCalendar()
    {
    }

    bool book(int start, int end)
    {
        for (const auto [s, e] : calendar)
        {
            if (start < e && s < end)
                return false;
        }
        calendar.emplace_back(start, end);

        return true;
    }
};

static vector<string> _00729_MyCalendarI(vector<string> v, vector<vector<int>> v0)
{
    vector<string> res = {};

    MyCalendar *obj = new MyCalendar();
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == "MyCalendar")
            res.push_back("null");
        else
        {
            bool param_1 = obj->book(v0[i][0], v0[i][1]);

            if (param_1)
                res.push_back("true");
            else
                res.push_back("false");
        }
    }

    return res;
}

class MyCalendar0
{
private:
    set<pair<int, int>> calendar;

public:
    bool book(int start, int end)
    {
        const pair<int, int> event{start, end};
        const auto nextEvent = calendar.lower_bound(event);

        if (nextEvent != calendar.end() && nextEvent->first < end)
            return false;

        if (nextEvent != calendar.begin())
        {
            const auto prevEvent = prev(nextEvent);

            if (prevEvent->second > start)
                return false;
        }

        calendar.insert(event);

        return true;
    }
};

static vector<string> _00729_MyCalendarI0(vector<string> v, vector<vector<int>> v0)
{
    vector<string> res = {};

    MyCalendar0 *obj = new MyCalendar0();
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == "MyCalendar")
            res.push_back("null");
        else
        {
            bool param_1 = obj->book(v0[i][0], v0[i][1]);

            if (param_1)
                res.push_back("true");
            else
                res.push_back("false");
        }
    }

    return res;
}

#pragma region GTest
static int is_00729_MyCalendarI_RunTest()
{
    stringstream ss;
    ss << "*_00729_MyCalendarI.expected*"
       << ":"
       << "*_00729_MyCalendarI0.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_00729_MyCalendarI, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<string> expected = v1[i];

        // Actual
        vector<string> actual = _00729_MyCalendarI(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_00729_MyCalendarI0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<string> expected = v1[i];

        // Actual
        vector<string> actual = _00729_MyCalendarI0(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
