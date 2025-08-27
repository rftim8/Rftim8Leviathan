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

// Recursion
static long long _02463_MinimumTotalDistanceTraveled(vector<int> &robot, vector<vector<int>> &factory);
// Memoization
static long long _02463_MinimumTotalDistanceTraveled0(vector<int> &robot, vector<vector<int>> &factory);
// Tabulation
static long long _02463_MinimumTotalDistanceTraveled1(vector<int> &robot, vector<vector<int>> &factory);
// Tabulation Space Optimized
static long long _02463_MinimumTotalDistanceTraveled2(vector<int> &robot, vector<vector<int>> &factory);
// Speed
static long long _02463_MinimumTotalDistanceTraveled3(vector<int> &robot, vector<vector<int>> &factory);

static int is_02463_MinimumTotalDistanceTraveled_RunTest();

/**
 * There are some robots and factories on the X-axis.
 * You are given an integer array robot where robot[i] is the position of the ith robot.
 * You are also given a 2D integer array factory where factory[j] = [positionj, limitj]
 * indicates that positionj is the position of the jth factory and that the jth factory can
 * repair at most limitj robots.
 * The positions of each robot are unique.
 * The positions of each factory are also unique.
 * Note that a robot can be in the same position as a factory initially.
 * All the robots are initially broken; they keep moving in one direction.
 * The direction could be the negative or the positive direction of the X-axis.
 * When a robot reaches a factory that did not reach its limit, the factory repairs the robot,
 * and it stops moving.
 * At any moment, you can set the initial direction of moving for some robot.
 * Your target is to minimize the total distance traveled by all the robots.
 * Return the minimum total distance traveled by all the robots.
 * The test cases are generated such that all the robots can be repaired.
 *
 * Note that
 *
 * All robots move at the same speed.
 * If two robots move in the same direction, they will never collide.
 * If two robots move in opposite directions and they meet at some point, they do not collide.
 * They cross each other.
 * If a robot passes by a factory that reached its limits, it crosses it as if it does not exist.
 * If the robot moved from a position x to a position y, the distance it moved is |y - x|.
 *
 * Constraints:
 *
 * 1 <= robot.length, factory.length <= 100
 * factory[j].length == 2
 * -10^9 <= robot[i], positionj <= 10^9
 * 0 <= limitj <= robot.length
 * The input will be generated such that it is always possible to repair every robot.
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_02463_MinimumTotalDistanceTraveled_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<vector<int>> v;
static vector<vector<vector<int>>> v0;
static vector<int> v1;

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
        vector<int> d = {};
        while (getline(ss, t, ','))
        {
            d.push_back(stoi(t));
        }
        v.push_back(d);

        s = "";
        getline(cin, s);
        v0.push_back(stringTo2DVectorInt(s));

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
        cout << _02463_MinimumTotalDistanceTraveled(v[i], v0[i]) << "\n";
        cout << _02463_MinimumTotalDistanceTraveled0(v[i], v0[i]) << "\n";
        cout << _02463_MinimumTotalDistanceTraveled1(v[i], v0[i]) << "\n";
        cout << _02463_MinimumTotalDistanceTraveled2(v[i], v0[i]) << "\n";
        cout << _02463_MinimumTotalDistanceTraveled3(v[i], v0[i]) << "\n";
    }
}

#pragma region Recursion
static long long calculateMinDistance(int robotIdx, int factoryIdx,
                                      vector<int> &robot,
                                      vector<int> &factoryPositions)
{
    if (robotIdx == robot.size())
        return 0;

    if (factoryIdx == factoryPositions.size())
        return 1e12;

    long long assign = abs(robot[robotIdx] - factoryPositions[factoryIdx]) +
                       calculateMinDistance(robotIdx + 1, factoryIdx + 1,
                                            robot, factoryPositions);

    long long skip = calculateMinDistance(robotIdx, factoryIdx + 1, robot,
                                          factoryPositions);

    return min(assign, skip);
}

static long long _02463_MinimumTotalDistanceTraveled(vector<int> &robot, vector<vector<int>> &factory)
{
    sort(robot.begin(), robot.end());
    sort(factory.begin(), factory.end());
    vector<int> factoryPositions;

    for (auto &f : factory)
        for (int i = 0; i < f[1]; i++)
            factoryPositions.push_back(f[0]);

    return calculateMinDistance(0, 0, robot, factoryPositions);
}
#pragma endregion

#pragma region Memoization
static long long calculateMinDistance(int robotIdx, int factoryIdx,
                                      vector<int> &robot,
                                      vector<int> &factoryPositions,
                                      vector<vector<long long>> &memo)
{
    if (robotIdx == robot.size())
        return 0;

    if (factoryIdx == factoryPositions.size())
        return 1e12;

    if (memo[robotIdx][factoryIdx] != -1)
        return memo[robotIdx][factoryIdx];

    long long assign = abs(robot[robotIdx] - factoryPositions[factoryIdx]) +
                       calculateMinDistance(robotIdx + 1, factoryIdx + 1,
                                            robot, factoryPositions, memo);

    long long skip = calculateMinDistance(robotIdx, factoryIdx + 1, robot,
                                          factoryPositions, memo);

    return memo[robotIdx][factoryIdx] = min(assign, skip);
}

static long long _02463_MinimumTotalDistanceTraveled0(vector<int> &robot, vector<vector<int>> &factory)
{
    sort(robot.begin(), robot.end());
    sort(factory.begin(), factory.end());
    vector<int> factoryPositions;

    for (auto &f : factory)
        for (int i = 0; i < f[1]; i++)
            factoryPositions.push_back(f[0]);

    int robotCount = robot.size(), factoryCount = factoryPositions.size();
    vector<vector<long long>> memo(robotCount, vector<long long>(factoryCount, -1));

    return calculateMinDistance(0, 0, robot, factoryPositions, memo);
}
#pragma endregion

static long long _02463_MinimumTotalDistanceTraveled1(vector<int> &robot, vector<vector<int>> &factory)
{
    sort(robot.begin(), robot.end());
    sort(factory.begin(), factory.end());
    vector<int> factoryPositions;

    for (auto &f : factory)
        for (int i = 0; i < f[1]; i++)
            factoryPositions.push_back(f[0]);

    int robotCount = robot.size(), factoryCount = factoryPositions.size();
    vector<vector<long long>> dp(robotCount + 1, vector<long long>(factoryCount + 1, 0));

    for (int i = 0; i < robotCount; i++)
        dp[i][factoryCount] = 1e12;

    for (int i = robotCount - 1; i >= 0; i--)
    {
        for (int j = factoryCount - 1; j >= 0; j--)
        {
            long long assign = abs(robot[i] - factoryPositions[j]) + dp[i + 1][j + 1];
            long long skip = dp[i][j + 1];
            dp[i][j] = min(assign, skip);
        }
    }

    return dp[0][0];
}

static long long _02463_MinimumTotalDistanceTraveled2(vector<int> &robot, vector<vector<int>> &factory)
{
    sort(begin(robot), end(robot));
    sort(begin(factory), end(factory));
    vector<int> factoryPositions;

    for (auto &item : factory)
    {
        for (int i = 0; i < item[1]; i++)
        {
            factoryPositions.push_back(item[0]);
        }
    }

    int robotCount = robot.size(), factoryCount = factoryPositions.size();
    vector<long long> next(factoryCount + 1, 0), current(factoryCount + 1, 0);

    for (int i = robotCount - 1; i >= 0; i--)
    {
        if (i != robotCount - 1)
            next[factoryCount] = 1e12;

        current[factoryCount] = 1e12;

        for (int j = factoryCount - 1; j >= 0; j--)
        {
            long long assign = abs(robot[i] - factoryPositions[j]) + next[j + 1];
            long long skip = current[j + 1];
            current[j] = min(assign, skip);
        }

        next = current;
    }

    return current[0];
}

static long long _02463_MinimumTotalDistanceTraveled3(vector<int> &robot, vector<vector<int>> &factory)
{
    int n = robot.size();
    int m = factory.size();
    vector<long long> dp(n + 1, 10e12);
    dp[0] = 0;
    sort(robot.begin(), robot.end());
    sort(factory.begin(), factory.end());

    for (int i = 0; i < m; i++)
    {
        int position = factory[i][0];
        int limit = factory[i][1];

        while (limit--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                dp[j + 1] = min(dp[j + 1], abs(robot[j] - position) + dp[j]);
            }
        }
    }

    return dp[n];
}

#pragma region GTest
static int is_02463_MinimumTotalDistanceTraveled_RunTest()
{
    stringstream ss;
    ss << "*_02463_MinimumTotalDistanceTraveled.expected*"
       << ":"
       << "*_02463_MinimumTotalDistanceTraveled0.expected*"
       << ":"
       << "*_02463_MinimumTotalDistanceTraveled1.expected*"
       << ":"
       << "*_02463_MinimumTotalDistanceTraveled2.expected*"
       << ":"
       << "*_02463_MinimumTotalDistanceTraveled3.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_02463_MinimumTotalDistanceTraveled, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        long long expected = v1[i];

        // Actual
        long long actual = _02463_MinimumTotalDistanceTraveled(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02463_MinimumTotalDistanceTraveled0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        long long expected = v1[i];

        // Actual
        long long actual = _02463_MinimumTotalDistanceTraveled0(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02463_MinimumTotalDistanceTraveled1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        long long expected = v1[i];

        // Actual
        long long actual = _02463_MinimumTotalDistanceTraveled1(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02463_MinimumTotalDistanceTraveled2, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        long long expected = v1[i];

        // Actual
        long long actual = _02463_MinimumTotalDistanceTraveled2(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02463_MinimumTotalDistanceTraveled3, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        long long expected = v1[i];

        // Actual
        long long actual = _02463_MinimumTotalDistanceTraveled3(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
