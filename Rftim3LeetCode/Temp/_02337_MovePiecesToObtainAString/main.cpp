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

// Brute Force - TLE
static bool _02337_MovePiecesToObtainAString(string start, string target);
// Queue
static bool _02337_MovePiecesToObtainAString0(string start, string target);
// Two Pointer
static bool _02337_MovePiecesToObtainAString1(string start, string target);
// Speed
static bool _02337_MovePiecesToObtainAString2(string start, string target);

static int is_02337_MovePiecesToObtainAString_RunTest();

/**
 * You are given two strings start and target, both of length n.
 * Each string consists only of the characters 'L', 'R', and '_' where:
 * The characters 'L' and 'R' represent pieces, where a piece 'L' can move to the left only if there is
 * a blank space directly to its left, and a piece 'R' can move to the right only if there is a blank space
 * directly to its right.
 * The character '_' represents a blank space that can be occupied by any of the 'L' or 'R' pieces.
 * Return true if it is possible to obtain the string target by moving the pieces of the string start
 * any number of times.
 * Otherwise, return false.
 *
 * Constraints:
 *
 * n == start.length == target.length
 * 1 <= n <= 10^5
 * start and target consist of the characters 'L', 'R', and '_'.
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_02337_MovePiecesToObtainAString_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<string> v, v0;
static vector<bool> v1;

static void dataCollector()
{
    cin >> n;
    cin >> m;
    cin.get();

    for (int i = 0; i < n * m; i += m)
    {
        string s;
        getline(cin, s);
        v.push_back(s);

        s = "";
        getline(cin, s);
        v0.push_back(s);

        bool s0;
        cin >> s0;
        cin.get();
        v1.push_back(s0);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        cout << _02337_MovePiecesToObtainAString(v[i], v0[i]) << "\n";
        cout << _02337_MovePiecesToObtainAString0(v[i], v0[i]) << "\n";
        cout << _02337_MovePiecesToObtainAString1(v[i], v0[i]) << "\n";
        cout << _02337_MovePiecesToObtainAString2(v[i], v0[i]) << "\n";
    }
}

static bool _02337_MovePiecesToObtainAString(string start, string target)
{
    unordered_set<string> visitedStates;
    queue<string> stateQueue;
    stateQueue.push(start);

    while (!stateQueue.empty())
    {
        string currentState = stateQueue.front();
        stateQueue.pop();

        if (currentState == target)
            return true;

        for (int position = 1; position < currentState.size(); position++)
        {
            if (currentState[position] == 'L' &&
                currentState[position - 1] == '_')
            {
                swap(currentState[position], currentState[position - 1]);

                if (visitedStates.find(currentState) ==
                    visitedStates.end())
                {
                    stateQueue.push(currentState);
                    visitedStates.insert(currentState);
                }

                swap(currentState[position], currentState[position - 1]);
            }

            if (currentState[position - 1] == 'R' &&
                currentState[position] == '_')
            {
                swap(currentState[position], currentState[position - 1]);

                if (visitedStates.find(currentState) ==
                    visitedStates.end())
                {
                    stateQueue.push(currentState);
                    visitedStates.insert(currentState);
                }

                swap(currentState[position], currentState[position - 1]);
            }
        }
    }

    return false;
}

static bool _02337_MovePiecesToObtainAString0(string start, string target)
{
    queue<pair<char, int>> startQueue, targetQueue;

    for (int i = 0; i < start.size(); i++)
    {
        if (start[i] != '_')
            startQueue.push({start[i], i});

        if (target[i] != '_')
            targetQueue.push({target[i], i});
    }

    if (startQueue.size() != targetQueue.size())
        return false;

    while (!startQueue.empty())
    {
        auto [startChar, startIndex] = startQueue.front();
        startQueue.pop();
        auto [targetChar, targetIndex] = targetQueue.front();
        targetQueue.pop();

        if (startChar != targetChar ||
            (startChar == 'L' && startIndex < targetIndex) ||
            (startChar == 'R' && startIndex > targetIndex))
            return false;
    }

    return true;
}

static bool _02337_MovePiecesToObtainAString1(string start, string target)
{
    int startLength = start.size();
    int startIndex = 0, targetIndex = 0;

    while (startIndex < startLength || targetIndex < startLength)
    {
        while (startIndex < startLength && start[startIndex] == '_')
        {
            startIndex++;
        }

        while (targetIndex < startLength && target[targetIndex] == '_')
        {
            targetIndex++;
        }

        if (startIndex == startLength || targetIndex == startLength)
            return startIndex == startLength && targetIndex == startLength;

        if (start[startIndex] != target[targetIndex] ||
            (start[startIndex] == 'L' && startIndex < targetIndex) ||
            (start[startIndex] == 'R' && startIndex > targetIndex))
            return false;

        startIndex++;
        targetIndex++;
    }

    return true;
}

static bool _02337_MovePiecesToObtainAString2(string start, string target)
{
    int index, r = 0, l = 0;
    int size = target.length();

    for (int i = 0, j = 0; i < size; i++)
    {
        if (start[i] == 'R')
            r++;

        if (start[i] == 'L')
            l++;

        if (target[i] == 'R')
            r--;

        if (target[i] == 'L')
            l--;

        if (start[i] != '_')
        {
            index = i;

            while (j < size && target[j] == '_')
                j++;

            if (start[i] != target[j] || (start[i] == 'R' && index > j) || (start[i] == 'L' && index < j))
                return false;
            j++;
        }
    }

    if (r == 0 && l == 0)
        return true;
    else
        return false;
}

#pragma region GTest
static int is_02337_MovePiecesToObtainAString_RunTest()
{
    stringstream ss;
    ss << "*_02337_MovePiecesToObtainAString.expected*"
       << ":"
       << "*_02337_MovePiecesToObtainAString0.expected*"
       << ":"
       << "*_02337_MovePiecesToObtainAString1.expected*"
       << ":"
       << "*_02337_MovePiecesToObtainAString2.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_02337_MovePiecesToObtainAString, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        bool expected = v1[i];

        // Actual
        bool actual = _02337_MovePiecesToObtainAString(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02337_MovePiecesToObtainAString0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        bool expected = v1[i];

        // Actual
        bool actual = _02337_MovePiecesToObtainAString0(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02337_MovePiecesToObtainAString1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        bool expected = v1[i];

        // Actual
        bool actual = _02337_MovePiecesToObtainAString1(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02337_MovePiecesToObtainAString2, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        bool expected = v1[i];

        // Actual
        bool actual = _02337_MovePiecesToObtainAString2(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
