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

// Deque
static bool _01813_SentenceSimilarityIII(string sentence1, string sentence2);
// Two Pointers
static bool _01813_SentenceSimilarityIII0(string sentence1, string sentence2);

static int is_01813_SentenceSimilarityIII_RunTest();

/**
 * You are given two strings sentence1 and sentence2, each representing a sentence composed of words.
 * A sentence is a list of words that are separated by a single space with no leading or trailing spaces.
 * Each word consists of only uppercase and lowercase English characters.
 *
 * Two sentences s1 and s2 are considered similar if it is possible to insert an arbitrary sentence (possibly empty)
 * inside one of these sentences such that the two sentences become equal.
 * Note that the inserted sentence must be separated from existing words by spaces.
 *
 * For example,
 *
 * s1 = "Hello Jane" and s2 = "Hello my name is Jane" can be made equal by inserting "my name is" between "Hello" and "Jane" in s1.
 * s1 = "Frog cool" and s2 = "Frogs are cool" are not similar, since although there is a sentence "s are" inserted into s1,
 * it is not separated from "Frog" by a space.
 * Given two sentences sentence1 and sentence2, return true if sentence1 and sentence2 are similar.
 * Otherwise, return false.
 *
 * Constraints:
 *
 * 1 <= sentence1.length, sentence2.length <= 100
 * sentence1 and sentence2 consist of lowercase and uppercase English letters and spaces.
 * The words in sentence1 and sentence2 are separated by a single space.
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_01813_SentenceSimilarityIII_RunTest();
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
        cout << _01813_SentenceSimilarityIII(v[i], v0[i]) << "\n";
        cout << _01813_SentenceSimilarityIII0(v[i], v0[i]) << "\n";
    }
}

static bool _01813_SentenceSimilarityIII(string sentence1, string sentence2)
{
    istringstream iss1(sentence1);
    deque<string> deque1((istream_iterator<string>(iss1)), istream_iterator<string>());
    istringstream iss2(sentence2);
    deque<string> deque2((istream_iterator<string>(iss2)), istream_iterator<string>());

    while (!deque1.empty() && !deque2.empty() &&
           deque1.front() == deque2.front())
    {
        deque1.pop_front();
        deque2.pop_front();
    }

    while (!deque1.empty() && !deque2.empty() &&
           deque1.back() == deque2.back())
    {
        deque1.pop_back();
        deque2.pop_back();
    }

    return deque1.empty() || deque2.empty();
}

static bool _01813_SentenceSimilarityIII0(string sentence1, string sentence2)
{
    stringstream ss1(sentence1), ss2(sentence2);
    string word;
    vector<string> s1Words, s2Words;

    while (ss1 >> word)
        s1Words.push_back(word);

    while (ss2 >> word)
        s2Words.push_back(word);

    int start = 0, ends1 = s1Words.size() - 1, ends2 = s2Words.size() - 1;

    if (s1Words.size() > s2Words.size())
        return _01813_SentenceSimilarityIII0(sentence2, sentence1);

    while (start < s1Words.size() && s1Words[start] == s2Words[start])
        ++start;

    while (ends1 >= 0 && s1Words[ends1] == s2Words[ends2])
    {
        --ends1;
        --ends2;
    }

    return ends1 < start;
}

#pragma region GTest
static int is_01813_SentenceSimilarityIII_RunTest()
{
    stringstream ss;
    ss << "*_01813_SentenceSimilarityIII.expected*"
       << ":"
       << "*_01813_SentenceSimilarityIII0.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_01813_SentenceSimilarityIII, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        bool expected = v1[i];

        // Actual
        bool actual = _01813_SentenceSimilarityIII(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_01813_SentenceSimilarityIII0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        bool expected = v1[i];

        // Actual
        bool actual = _01813_SentenceSimilarityIII0(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
