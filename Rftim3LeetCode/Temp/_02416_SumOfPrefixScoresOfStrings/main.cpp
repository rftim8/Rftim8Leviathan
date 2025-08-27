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

// Trie
static vector<int> _02416_SumOfPrefixScoresOfStrings(vector<string> &words);
// Speed
static vector<int> _02416_SumOfPrefixScoresOfStrings0(vector<string> &words);

static int is_02416_SumOfPrefixScoresOfStrings_RunTest();

/**
 * You are given an array words of size n consisting of non-empty strings.
 * We define the score of a string word as the number of strings words[i] such that word is a prefix of words[i].
 * For example, if words = ["a", "ab", "abc", "cab"], then the score of "ab" is 2, since "ab" is a prefix of both "ab" and "abc".
 * Return an array answer of size n where answer[i] is the sum of scores of every non-empty prefix of words[i].
 *
 * Note that a string is considered as a prefix of itself.
 *
 * Constraints:
 *
 * 1 <= words.length <= 1000
 * 1 <= words[i].length <= 1000
 * words[i] consists of lowercase English letters.
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_02416_SumOfPrefixScoresOfStrings_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<vector<string>> v;
static vector<vector<int>> v0;

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

        s = "";
        getline(cin, s);
        ss.clear();
        ss.str(s);
        t = "";
        vector<int> vv = {};
        while (getline(ss, t, ','))
        {
            vv.push_back(stoi(t));
        }
        v0.push_back(vv);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        vector<int> res = _02416_SumOfPrefixScoresOfStrings(v[i]);
        for (auto &&j : res)
        {
            cout << j << " ";
        }
        cout << "\n";

        vector<int> res0 = _02416_SumOfPrefixScoresOfStrings0(v[i]);
        for (auto &&j : res0)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
}

#pragma region Trie
struct TrieNode
{
    TrieNode *next[26] = {};
    int cnt = 0;
};

static TrieNode root;

static void insert(string word)
{
    auto node = &root;

    for (char c : word)
    {
        if (!node->next[c - 'a'])
            node->next[c - 'a'] = new TrieNode();

        node->next[c - 'a']->cnt++;
        node = node->next[c - 'a'];
    }
}

static int count(string s)
{
    auto node = &root;
    int ans = 0;

    for (char c : s)
    {
        ans += node->next[c - 'a']->cnt;
        node = node->next[c - 'a'];
    }

    return ans;
}

static vector<int> _02416_SumOfPrefixScoresOfStrings(vector<string> &words)
{
    root = TrieNode();
    int N = words.size();

    for (int i = 0; i < N; i++)
    {
        insert(words[i]);
    }

    vector<int> scores(N, 0);

    for (int i = 0; i < N; i++)
    {
        scores[i] = count(words[i]);
    }

    return scores;
}
#pragma endregion

#pragma region Speed
static vector<int> calculateCommonPrefixLengths(const vector<string> &words, const vector<int> &sortedIndices)
{
    vector<int> commonPrefixLengths(words.size(), 0);

    for (int i = 1; i < words.size(); i++)
    {
        const string &prevWord = words[sortedIndices[i - 1]];
        const string &currWord = words[sortedIndices[i]];
        int commonLength = 0;

        while (commonLength < prevWord.length() &&
               commonLength < currWord.length() &&
               prevWord[commonLength] == currWord[commonLength])
        {
            commonLength++;
        }

        commonPrefixLengths[i] = commonLength;
    }

    return commonPrefixLengths;
}

static vector<int> calculateScores(const vector<string> &words, const vector<int> &sortedIndices, const vector<int> &commonPrefixLengths)
{
    vector<int> scores(words.size(), 0);

    for (int i = 0; i < sortedIndices.size(); i++)
    {
        int wordIndex = sortedIndices[i];
        int wordLength = words[wordIndex].length();
        scores[wordIndex] += wordLength;
        int j = i + 1;
        int commonLength = wordLength;

        while (j < words.size())
        {
            commonLength = std::min(commonLength, commonPrefixLengths[j]);

            if (commonLength == 0)
                break;

            scores[wordIndex] += commonLength;
            scores[sortedIndices[j]] += commonLength;
            j++;
        }
    }

    return scores;
}

static vector<int> _02416_SumOfPrefixScoresOfStrings0(vector<string> &words)
{
    int wordCount = words.size();
    vector<int> sortedIndices(wordCount);

    for (int i = 0; i < wordCount; i++)
    {
        sortedIndices[i] = i;
    }

    sort(sortedIndices.begin(), sortedIndices.end(), [&words](int a, int b)
         { return words[a] < words[b]; });

    vector<int> commonPrefixLengths = calculateCommonPrefixLengths(words, sortedIndices);
    vector<int> scores = calculateScores(words, sortedIndices, commonPrefixLengths);
    
    return scores;
}
#pragma endregion

#pragma region GTest
static int is_02416_SumOfPrefixScoresOfStrings_RunTest()
{
    stringstream ss;
    ss << "*_02416_SumOfPrefixScoresOfStrings.expected*"
       << ":"
       << "*_02416_SumOfPrefixScoresOfStrings0.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_02416_SumOfPrefixScoresOfStrings, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<int> expected = v0[i];

        // Actual
        vector<int> actual = _02416_SumOfPrefixScoresOfStrings(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02416_SumOfPrefixScoresOfStrings0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<int> expected = v0[i];

        // Actual
        vector<int> actual = _02416_SumOfPrefixScoresOfStrings0(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
