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
static int _01455_CheckIfAWordOccursAsAPrefixOfAnyWordInASentence(string sentence, string searchWord);

static int is_01455_CheckIfAWordOccursAsAPrefixOfAnyWordInASentence_RunTest();

/**
 * Given a sentence that consists of some words separated by a single space, and a searchWord,
 * check if searchWord is a prefix of any word in sentence.
 * Return the index of the word in sentence (1-indexed) where searchWord is a prefix of this word.
 * If searchWord is a prefix of more than one word, return the index of the first word (minimum index).
 * If there is no such word return -1.
 * A prefix of a string s is any leading contiguous substring of s.
 *
 * Constraints:
 *
 * 1 <= sentence.length <= 100
 * 1 <= searchWord.length <= 10
 * sentence consists of lowercase English letters and spaces.
 * searchWord consists of lowercase English letters.
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_01455_CheckIfAWordOccursAsAPrefixOfAnyWordInASentence_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<string> v, v0;
static vector<int> v1;

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
        cout << _01455_CheckIfAWordOccursAsAPrefixOfAnyWordInASentence(v[i], v0[i]) << "\n";
    }
}

static int _01455_CheckIfAWordOccursAsAPrefixOfAnyWordInASentence(string sentence, string searchWord)
{
    int res = -1;
    vector<string> r = {};
    stringstream ss(sentence);
    string t = "";
    
    while (getline(ss, t, ' '))
    {
        r.push_back(t);
    }

    for (int i = 0; i < r.size(); i++)
    {
        if (r[i].rfind(searchWord) == 0)
            return i + 1;
    }

    return res;
}

#pragma region GTest
static int is_01455_CheckIfAWordOccursAsAPrefixOfAnyWordInASentence_RunTest()
{
    stringstream ss;
    ss << "*_01455_CheckIfAWordOccursAsAPrefixOfAnyWordInASentence.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_01455_CheckIfAWordOccursAsAPrefixOfAnyWordInASentence, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v1[i];

        // Actual
        int actual = _01455_CheckIfAWordOccursAsAPrefixOfAnyWordInASentence(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
