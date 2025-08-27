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

// Iterative
static bool _01346_CheckIfNAndItsDoubleExist(vector<int> &arr);

static int is_01346_CheckIfNAndItsDoubleExist_RunTest();

/**
 * Given an array arr of integers, check if there exist two indices i and j such that :
 *
 * i != j
 * 0 <= i, j < arr.length
 * arr[i] == 2 * arr[j]
 *
 * Constraints:
 *
 * 2 <= arr.length <= 500
 * -10^3 <= arr[i] <= 10^3
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_01346_CheckIfNAndItsDoubleExist_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<vector<int>> v;
static vector<bool> v0;

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

        bool s0;
        cin >> s0;
        cin.get();
        v0.push_back(s0);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        cout << _01346_CheckIfNAndItsDoubleExist(v[i]) << "\n";
    }
}

static bool _01346_CheckIfNAndItsDoubleExist(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j &&
                (arr[i] == 2 * arr[j] ||
                 arr[j] == arr[i] * 2))
                return true;
        }
    }

    return false;
}

#pragma region GTest
static int is_01346_CheckIfNAndItsDoubleExist_RunTest()
{
    stringstream ss;
    ss << "*_01346_CheckIfNAndItsDoubleExist.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_01346_CheckIfNAndItsDoubleExist, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        bool expected = v0[i];

        // Actual
        bool actual = _01346_CheckIfNAndItsDoubleExist(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
