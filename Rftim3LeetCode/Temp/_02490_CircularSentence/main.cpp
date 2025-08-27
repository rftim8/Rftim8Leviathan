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
static bool _02490_CircularSentence(string sentence);

static int is_02490_CircularSentence_RunTest();

/**
 * A sentence is a list of words that are separated by a single space with no leading or
 * trailing spaces.
 * For example, "Hello World", "HELLO", "hello world hello world" are all sentences.
 * Words consist of only uppercase and lowercase English letters.
 * Uppercase and lowercase English letters are considered different.
 * A sentence is circular if:
 * The last character of a word is equal to the first character of the next word.
 * The last character of the last word is equal to the first character of the first word.
 * For example, "leetcode exercises sound delightful", "eetcode", "leetcode eats soul" are
 * all circular sentences. However, "Leetcode is cool", "happy Leetcode", "Leetcode" and
 * "I like Leetcode" are not circular sentences.
 * Given a string sentence, return true if it is circular. Otherwise, return false.
 *
 * Constraints:
 *
 * 1 <= sentence.length <= 500
 * sentence consist of only lowercase and uppercase English letters and spaces.
 * The words in sentence are separated by a single space.
 * There are no leading or trailing spaces.
 */
int main()
{
    offline();
    dataCollector();

    solve();
    return 0;

    ::testing::InitGoogleTest();
    is_02490_CircularSentence_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<string> v;
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
        v.push_back(s);

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
        cout << _02490_CircularSentence(v[i]) << "\n";
    }
}

static bool _02490_CircularSentence(string sentence)
{
    vector<string> r = {};

    stringstream ss(sentence);
    string t = "";
    
    while (getline(ss, t, ' '))
    {
        r.push_back(t);
    }

    int n = r.size();

    if (r[0][0] != r.back().back())
        return false;

    for (int i = 0; i < n - 1; i++)
    {
        if (r[i].back() != r[i + 1][0])
            return false;
    }

    return true;
}

#pragma region GTest
static int is_02490_CircularSentence_RunTest()
{
    stringstream ss;
    ss << "*_02490_CircularSentence.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_02490_CircularSentence, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        bool expected = v0[i];

        // Actual
        bool actual = _02490_CircularSentence(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
