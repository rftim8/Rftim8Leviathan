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

// Overlapped Intervals
static vector<string> _00731_MyCalendarII(vector<string> v, vector<vector<int>> v0);
// Line Sweep
static vector<string> _00731_MyCalendarII0(vector<string> v, vector<vector<int>> v0);
// Speed
static vector<string> _00731_MyCalendarII1(vector<string> v, vector<vector<int>> v0);

static int is_00731_MyCalendarII_RunTest();

/**
 * You are implementing a program to use as your calendar. We can add a new event if adding the event will not cause a triple booking.
 * A triple booking happens when three events have some non-empty intersection (i.e., some moment is common to all the three events.).
 * The event can be represented as a pair of integers start and end that represents a booking on the half-open interval [start, end),
 * the range of real numbers x such that start <= x < end.
 *
 * Implement the MyCalendarTwo class:
 *
 * MyCalendarTwo() Initializes the calendar object.
 * boolean book(int start, int end) Returns true if the event can be added to the calendar successfully without causing a triple booking.
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
    is_00731_MyCalendarII_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<vector<string>> v;
static vector<vector<vector<int>>> v0;
static vector<vector<string>> v1;

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
        vector<string> res = _00731_MyCalendarII(v[i], v0[i]);
        for (auto &&j : res)
        {
            cout << j << " ";
        }
        cout << "\n";

        vector<string> res0 = _00731_MyCalendarII0(v[i], v0[i]);
        for (auto &&j : res0)
        {
            cout << j << " ";
        }
        cout << "\n";

        vector<string> res1 = _00731_MyCalendarII1(v[i], v0[i]);
        for (auto &&j : res1)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
}

class MyCalendarTwo
{
private:
    bool doesOverlap(int start1, int end1, int start2, int end2)
    {
        return max(start1, start2) < min(end1, end2);
    }

    pair<int, int> getOverlapped(int start1, int end1, int start2, int end2)
    {
        return {max(start1, start2), min(end1, end2)};
    }

public:
    vector<pair<int, int>> bookings;
    vector<pair<int, int>> overlapBookings;

    MyCalendarTwo()
    {
    }

    bool book(int start, int end)
    {
        for (pair<int, int> booking : overlapBookings)
        {
            if (doesOverlap(booking.first, booking.second, start, end))
                return false;
        }

        for (pair<int, int> booking : bookings)
        {
            if (doesOverlap(booking.first, booking.second, start, end))
                overlapBookings.push_back(getOverlapped(booking.first, booking.second, start, end));
        }

        bookings.push_back({start, end});

        return true;
    }
};

static vector<string> _00731_MyCalendarII(vector<string> v, vector<vector<int>> v0)
{
    vector<string> res = {};

    MyCalendarTwo *obj = new MyCalendarTwo();
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == "MyCalendarTwo")
            res.push_back("null");
        else
        {
            bool param_1 = obj->book(v0[i][0], v0[i][1]);

            res.push_back(param_1 ? "true" : "false");
        }
    }

    return res;
}

class MyCalendarTwo0
{
public:
    map<int, int> bookingCount;
    int maxOverlappedBooking;

    MyCalendarTwo0() { maxOverlappedBooking = 2; }

    bool book(int start, int end)
    {
        bookingCount[start]++;
        bookingCount[end]--;

        int overlappedBooking = 0;

        for (pair<int, int> bookings : bookingCount)
        {
            overlappedBooking += bookings.second;

            if (overlappedBooking > maxOverlappedBooking)
            {
                bookingCount[start]--;
                bookingCount[end]++;

                if (bookingCount[start] == 0)
                    bookingCount.erase(start);

                if (bookingCount[end] == 0)
                    bookingCount.erase(end);

                return false;
            }
        }

        return true;
    }
};

static vector<string> _00731_MyCalendarII0(vector<string> v, vector<vector<int>> v0)
{
    vector<string> res = {};

    MyCalendarTwo0 *obj = new MyCalendarTwo0();
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == "MyCalendarTwo")
            res.push_back("null");
        else
        {
            bool param_1 = obj->book(v0[i][0], v0[i][1]);

            res.push_back(param_1 ? "true" : "false");
        }
    }

    return res;
}

class MyCalendarTwo1
{
    vector<pair<int, int>> b;
    vector<pair<int, int>> db;

public:
    MyCalendarTwo1()
    {
    }

    bool book(int start, int end)
    {

        for (pair<int, int> x : db)
        {
            if (start < x.second && end > x.first)
                return false;
        }

        for (pair<int, int> x : b)
        {
            if (start < x.second && end > x.first)
                db.push_back({max(start, x.first), min(end, x.second)});
        }
        b.push_back({start, end});

        return true;
    }
};

static vector<string> _00731_MyCalendarII1(vector<string> v, vector<vector<int>> v0)
{
    vector<string> res = {};

    MyCalendarTwo1 *obj = new MyCalendarTwo1();
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == "MyCalendarTwo")
            res.push_back("null");
        else
        {
            bool param_1 = obj->book(v0[i][0], v0[i][1]);

            res.push_back(param_1 ? "true" : "false");
        }
    }

    return res;
}

#pragma region GTest
static int is_00731_MyCalendarII_RunTest()
{
    stringstream ss;
    ss << "*_00731_MyCalendarII.expected*"
       << ":"
       << "*_00731_MyCalendarII0.expected*"
       << ":"
       << "*_00731_MyCalendarII1.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_00731_MyCalendarII, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<string> expected = v1[i];

        // Actual
        vector<string> actual = _00731_MyCalendarII(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_00731_MyCalendarII0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<string> expected = v1[i];

        // Actual
        vector<string> actual = _00731_MyCalendarII0(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_00731_MyCalendarII1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<string> expected = v1[i];

        // Actual
        vector<string> actual = _00731_MyCalendarII1(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
