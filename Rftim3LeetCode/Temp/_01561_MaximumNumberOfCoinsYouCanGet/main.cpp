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
static int _01561_MaximumNumberOfCoinsYouCanGet();

static int is_01561_MaximumNumberOfCoinsYouCanGet_RunTest();

/**
 * 
*/
int main()
{
    offline();
    dataCollector();
    
    solve();
    return 0;

    ::testing::InitGoogleTest();
    is_01561_MaximumNumberOfCoinsYouCanGet_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<vector<string>> v;
static vector<string> v0;
static vector<string> v1;

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
        string t;
        vector<string> d = {};
        while (getline(ss, t, ','))
        {
            d.push_back(t);
        }
        v.push_back(d);

        string s0;
        getline(cin, s0);
        v0.push_back(s0);

        string s1;
        getline(cin, s1);
        v1.push_back(s1);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        cout << _01561_MaximumNumberOfCoinsYouCanGet() << "\n";
    }
}

static int _01561_MaximumNumberOfCoinsYouCanGet()
{
    return 0;
}

#pragma region GTest
static int is_01561_MaximumNumberOfCoinsYouCanGet_RunTest()
{
    stringstream ss;
    ss << "*_01561_MaximumNumberOfCoinsYouCanGet.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_01561_MaximumNumberOfCoinsYouCanGet, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = 0;

        // Actual
        int actual = _01561_MaximumNumberOfCoinsYouCanGet();

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
