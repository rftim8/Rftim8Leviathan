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
static int _02516_TakeKOfEachCharacterFromLeftandRight(string s, int k);
// Sliding Window
static int _02516_TakeKOfEachCharacterFromLeftandRight0(string s, int k);
// Speed
static int _02516_TakeKOfEachCharacterFromLeftandRight1(string s, int k);

static int is_02516_TakeKOfEachCharacterFromLeftandRight_RunTest();

/**
 * You are given a string s consisting of the characters 'a', 'b', and 'c' and a non-negative integer k.
 * Each minute, you may take either the leftmost character of s, or the rightmost character of s.
 * Return the minimum number of minutes needed for you to take at least k of each character,
 * or return -1 if it is not possible to take k of each character.
 *
 * Constraints:
 *
 * 1 <= s.length <= 10^5
 * s consists of only the letters 'a', 'b', and 'c'.
 * 0 <= k <= s.length
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_02516_TakeKOfEachCharacterFromLeftandRight_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<string> v;
static vector<int> v0, v1;

static void dataCollector()
{
    cin >> n;
    cin >> m;
    cin.get();

    for (int i = 0; i < n * m; i += m)
    {
        string s;
        cin >> s;
        v.push_back(s);

        int s0;
        cin >> s0;
        v0.push_back(s0);

        cin >> s0;
        v1.push_back(s0);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        cout << _02516_TakeKOfEachCharacterFromLeftandRight(v[i], v0[i]) << "\n";
        cout << _02516_TakeKOfEachCharacterFromLeftandRight0(v[i], v0[i]) << "\n";
        cout << _02516_TakeKOfEachCharacterFromLeftandRight1(v[i], v0[i]) << "\n";
    }
}

#pragma region Recursion
static int minMinutes;

static void rec(string &s, int k, int left, int right, vector<int> count, int minutes)
{
    if (count[0] >= k && count[1] >= k && count[2] >= k)
    {
        minMinutes = min(minMinutes, minutes);
        return;
    }

    if (left > right)
        return;

    vector<int> leftCount = count;
    leftCount[s[left] - 'a']++;
    rec(s, k, left + 1, right, leftCount, minutes + 1);

    vector<int> rightCount = count;
    rightCount[s[right] - 'a']++;
    rec(s, k, left, right - 1, rightCount, minutes + 1);
}

static int _02516_TakeKOfEachCharacterFromLeftandRight(string s, int k)
{
    if (k == 0)
        return 0;

    minMinutes = INT_MAX;
    vector<int> count(3, 0);
    rec(s, k, 0, s.length() - 1, count, 0);

    return minMinutes == INT_MAX ? -1 : minMinutes;
}
#pragma endregion

static int _02516_TakeKOfEachCharacterFromLeftandRight0(string s, int k)
{
    vector<int> count(3, 0);
    int n = s.length();

    for (char c : s)
    {
        count[c - 'a']++;
    }

    for (int i = 0; i < 3; i++)
    {
        if (count[i] < k)
            return -1;
    }

    vector<int> window(3, 0);
    int left = 0, maxWindow = 0;

    for (int right = 0; right < n; right++)
    {
        window[s[right] - 'a']++;

        while (left <= right &&
               (count[0] - window[0] < k || count[1] - window[1] < k ||
                count[2] - window[2] < k))
        {
            window[s[left] - 'a']--;
            left++;
        }

        maxWindow = max(maxWindow, right - left + 1);
    }

    return n - maxWindow;
}

static int _02516_TakeKOfEachCharacterFromLeftandRight1(string s, int k)
{
    int ca = 0, cb = 0, cc = 0;
    int n = s.size();
    int ans = n;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a')
            ca++;
        if (s[i] == 'b')
            cb++;
        if (s[i] == 'c')
            cc++;
    }

    if (ca < k || cb < k || cc < k)
        return -1;

    int i = n - 1, j = n - 1;

    while (i >= 0)
    {
        if (s[i] == 'a')
            ca--;
        if (s[i] == 'b')
            cb--;
        if (s[i] == 'c')
            cc--;

        while (ca < k || cb < k || cc < k)
        {
            if (s[j] == 'a')
                ca++;
            if (s[j] == 'b')
                cb++;
            if (s[j] == 'c')
                cc++;
            j--;
        }

        ans = min(ans, i + n - 1 - j);
        i--;
    }

    return ans;
}

#pragma region GTest
static int is_02516_TakeKOfEachCharacterFromLeftandRight_RunTest()
{
    stringstream ss;
    ss << "*_02516_TakeKOfEachCharacterFromLeftandRight.expected*"
       << ":"
       << "*_02516_TakeKOfEachCharacterFromLeftandRight0.expected*"
       << ":"
       << "*_02516_TakeKOfEachCharacterFromLeftandRight1.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_02516_TakeKOfEachCharacterFromLeftandRight, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v1[i];

        // Actual
        int actual = _02516_TakeKOfEachCharacterFromLeftandRight(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02516_TakeKOfEachCharacterFromLeftandRight0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v1[i];

        // Actual
        int actual = _02516_TakeKOfEachCharacterFromLeftandRight0(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02516_TakeKOfEachCharacterFromLeftandRight1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v1[i];

        // Actual
        int actual = _02516_TakeKOfEachCharacterFromLeftandRight1(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
