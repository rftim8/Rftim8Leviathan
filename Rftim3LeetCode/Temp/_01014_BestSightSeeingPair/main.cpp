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
static int _01014_BestSightSeeingPair(vector<int> &values);
// Speed
static int _01014_BestSightSeeingPair0(vector<int> &values);
// DP
static int _01014_BestSightSeeingPair1(vector<int> &values);
// Space-Optimized DP
static int _01014_BestSightSeeingPair2(vector<int> &values);

static int is_01014_BestSightSeeingPair_RunTest();

/**
 * You are given an integer array values where values[i] represents the value of the ith sightseeing spot.
 * Two sightseeing spots i and j have a distance j - i between them.
 * The score of a pair (i < j) of sightseeing spots is values[i] + values[j] + i - j:
 * the sum of the values of the sightseeing spots, minus the distance between them.
 * Return the maximum score of a pair of sightseeing spots.
 *
 * Constraints:
 *
 * 2 <= values.length <= 5 * 10^4
 * 1 <= values[i] <= 1000
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_01014_BestSightSeeingPair_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<vector<int>> v;
static vector<int> v0;

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
        cin.get();
        v0.push_back(s0);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        cout << _01014_BestSightSeeingPair(v[i]) << "\n";
        cout << _01014_BestSightSeeingPair0(v[i]) << "\n";
        cout << _01014_BestSightSeeingPair1(v[i]) << "\n";
        cout << _01014_BestSightSeeingPair2(v[i]) << "\n";
    }
}

static int _01014_BestSightSeeingPair(vector<int> &values)
{
    int n = values.size();
    vector<int> x(n);
    x[0] = values[0];

    for (int i = 1; i < n; i++)
    {
        x[i] = max(x[i - 1], values[i] + i);
    }

    int c = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        c = max(c, values[i] - i + x[i - 1]);
    }

    return c;
}

static int _01014_BestSightSeeingPair0(vector<int> &values)
{
    int ans = 0;
    int a = values[0];

    for (int i = 1; i < values.size(); i++)
    {
        a--;
        int b = values[i];
        ans = max(ans, a + b);
        a = max(a, b);
    }

    return ans;
}

static int _01014_BestSightSeeingPair1(vector<int> &values)
{
    int n = values.size();
    vector<int> maxLeftScore(n);
    maxLeftScore[0] = values[0];
    int maxScore = 0;

    for (int i = 1; i < n; i++)
    {
        int currentRightScore = values[i] - i;
        maxScore = max(maxScore, maxLeftScore[i - 1] + currentRightScore);
        int currentLeftScore = values[i] + i;
        maxLeftScore[i] = max(maxLeftScore[i - 1], currentLeftScore);
    }

    return maxScore;
}

static int _01014_BestSightSeeingPair2(vector<int> &values)
{
    int n = values.size();
    int maxLeftScore = values[0];
    int maxScore = 0;

    for (int i = 1; i < n; i++)
    {
        int currentRightScore = values[i] - i;
        maxScore = max(maxScore, maxLeftScore + currentRightScore);
        int currentLeftScore = values[i] + i;
        maxLeftScore = max(maxLeftScore, currentLeftScore);
    }

    return maxScore;
}

#pragma region GTest
static int is_01014_BestSightSeeingPair_RunTest()
{
    stringstream ss;
    ss << "*_01014_BestSightSeeingPair.expected*"
       << ":"
       << "*_01014_BestSightSeeingPair0.expected*"
       << ":"
       << "*_01014_BestSightSeeingPair1.expected*"
       << ":"
       << "*_01014_BestSightSeeingPair2.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_01014_BestSightSeeingPair, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _01014_BestSightSeeingPair(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_01014_BestSightSeeingPair0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _01014_BestSightSeeingPair0(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_01014_BestSightSeeingPair1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _01014_BestSightSeeingPair1(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_01014_BestSightSeeingPair2, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _01014_BestSightSeeingPair2(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
