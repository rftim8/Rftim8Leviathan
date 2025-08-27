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

// Greedy Character Frequency Distribution
static string _02182_ConstructStringWithRepeatLimit(string s, int repeatLimit);
// Heap-Optimized Greedy Character Frequency Distribution
static string _02182_ConstructStringWithRepeatLimit0(string s, int repeatLimit);

static int is_02182_ConstructStringWithRepeatLimit_RunTest();

/**
 * You are given a string s and an integer repeatLimit.
 * Construct a new string repeatLimitedString using the characters of s such that no letter appears more
 * than repeatLimit times in a row.
 * You do not have to use all characters from s.
 * Return the lexicographically largest repeatLimitedString possible.
 * A string a is lexicographically larger than a string b if in the first position where a and b differ,
 * string a has a letter that appears later in the alphabet than the corresponding letter in b.
 * If the first min(a.length, b.length) characters do not differ, then the longer string is the
 * lexicographically larger one.
 *
 * Constraints:
 *
 * 1 <= repeatLimit <= s.length <= 10^5
 * s consists of lowercase English letters.
 */
int main()
{
    offline();
    dataCollector();

    solve();
    return 0;

    ::testing::InitGoogleTest();
    is_02182_ConstructStringWithRepeatLimit_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<string> v, v1;
static vector<int> v0;

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

        s = "";
        cin >> s;
        cin.get();
        v1.push_back(s);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        cout << _02182_ConstructStringWithRepeatLimit(v[i], v0[i]) << "\n";
        cout << _02182_ConstructStringWithRepeatLimit0(v[i], v0[i]) << "\n";
    }
}

static string _02182_ConstructStringWithRepeatLimit(string s, int repeatLimit)
{
    vector<int> freq(26, 0);
    for (char ch : s)
    {
        freq[ch - 'a']++;
    }

    string result;
    int currentCharIndex = 25;

    while (currentCharIndex >= 0)
    {
        if (freq[currentCharIndex] == 0)
        {
            currentCharIndex--;
            continue;
        }

        int use = min(freq[currentCharIndex], repeatLimit);
        result.append(use, 'a' + currentCharIndex);
        freq[currentCharIndex] -= use;

        if (freq[currentCharIndex] >
            0)
        {
            int smallerCharIndex = currentCharIndex - 1;

            while (smallerCharIndex >= 0 && freq[smallerCharIndex] == 0)
            {
                smallerCharIndex--;
            }

            if (smallerCharIndex < 0)
                break;

            result.push_back('a' + smallerCharIndex);
            freq[smallerCharIndex]--;
        }
    }

    return result;
}

static string _02182_ConstructStringWithRepeatLimit0(string s, int repeatLimit)
{
    unordered_map<char, int> freq;
    for (char ch : s)
    {
        freq[ch]++;
    }

    priority_queue<char> maxHeap;
    for (auto &[ch, count] : freq)
    {
        maxHeap.push(ch);
    }

    string result;

    while (!maxHeap.empty())
    {
        char ch = maxHeap.top();
        maxHeap.pop();
        int count = freq[ch];

        int use = min(count, repeatLimit);
        result.append(use, ch);

        freq[ch] -= use;

        if (freq[ch] > 0 && !maxHeap.empty())
        {
            char nextCh = maxHeap.top();
            maxHeap.pop();

            result.push_back(nextCh);
            freq[nextCh]--;

            if (freq[nextCh] > 0)
                maxHeap.push(nextCh);

            maxHeap.push(ch);
        }
    }

    return result;
}

#pragma region GTest
static int is_02182_ConstructStringWithRepeatLimit_RunTest()
{
    stringstream ss;
    ss << "*_02182_ConstructStringWithRepeatLimit.expected*"
       << ":"
       << "*_02182_ConstructStringWithRepeatLimit0.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_02182_ConstructStringWithRepeatLimit, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        string expected = v1[i];

        // Actual
        string actual = _02182_ConstructStringWithRepeatLimit(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02182_ConstructStringWithRepeatLimit0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        string expected = v1[i];

        // Actual
        string actual = _02182_ConstructStringWithRepeatLimit0(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
