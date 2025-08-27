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

// Bottom-Up DP
static int _01639_NumberOfWaysToFormATargetStringGivenADictionary(vector<string> &words, string target);
// Speed
static int _01639_NumberOfWaysToFormATargetStringGivenADictionary0(vector<string> &words, string target);
// Top-Down DP
static int _01639_NumberOfWaysToFormATargetStringGivenADictionary1(vector<string> &words, string target);
// Bottom-Up DP
static int _01639_NumberOfWaysToFormATargetStringGivenADictionary2(vector<string> &words, string target);

static int is_01639_NumberOfWaysToFormATargetStringGivenADictionary_RunTest();

/**
 * You are given a list of strings of the same length words and a string target.
 * Your task is to form target using the given words under the following rules:
 * target should be formed from left to right.
 * To form the ith character (0-indexed) of target, you can choose the kth character of the jth string in words
 * if target[i] = words[j][k].
 * Once you use the kth character of the jth string of words, you can no longer use the xth character of
 * any string in words where x <= k.
 * In other words, all characters to the left of or at index k become unusuable for every string.
 * Repeat the process until you form the string target.
 * Notice that you can use multiple characters from the same string in words provided the conditions above are met.
 *
 * Return the number of ways to form target from words.
 * Since the answer may be too large, return it modulo 10^9 + 7.
 *
 * Constraints:
 *
 * 1 <= words.length <= 1000
 * 1 <= words[i].length <= 1000
 * All strings in words have the same length.
 * 1 <= target.length <= 1000
 * words[i] and target contain only lowercase English letters.
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_01639_NumberOfWaysToFormATargetStringGivenADictionary_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<vector<string>> v;
static vector<string> v0;
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
        stringstream ss(s);
        string t;
        vector<string> d = {};
        while (getline(ss, t, ','))
        {
            d.push_back(t);
        }
        v.push_back(d);

        string s0;
        cin >> s0;
        v0.push_back(s0);

        int s1;
        cin >> s1;
        cin.get();
        v1.push_back(s1);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        cout << _01639_NumberOfWaysToFormATargetStringGivenADictionary(v[i], v0[i]) << "\n";
        cout << _01639_NumberOfWaysToFormATargetStringGivenADictionary0(v[i], v0[i]) << "\n";
        cout << _01639_NumberOfWaysToFormATargetStringGivenADictionary1(v[i], v0[i]) << "\n";
        cout << _01639_NumberOfWaysToFormATargetStringGivenADictionary2(v[i], v0[i]) << "\n";
    }
}

static int _01639_NumberOfWaysToFormATargetStringGivenADictionary(vector<string> &words, string target)
{
    int n = words.size();
    int m = words[0].size();
    int l = target.size();
    int mod = 1000000007;
    int alphabet = 26;
    vector<vector<int>> cnt(alphabet, vector<int>(m));

    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            cnt[words[i][j] - 'a'][j]++;
        }
    }

    vector<vector<long>> dp(l + 1, vector<long>(m + 1));
    dp[0][0] = 1;

    for (int i = 0; i <= l; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i < l)
            {
                dp[i + 1][j + 1] += cnt[target[i] - 'a'][j] * dp[i][j];
                dp[i + 1][j + 1] %= mod;
            }
            dp[i][j + 1] += dp[i][j];
            dp[i][j + 1] %= mod;
        }
    }

    return (int)dp[l][m];
}

static int _01639_NumberOfWaysToFormATargetStringGivenADictionary0(vector<string> &words, string target)
{
    const int wl = words[0].size();
    const int tl = target.size();

    if (tl > wl)
        return 0;

    vector<array<int, 26>> char_cnt(wl, array<int, 26>{});

    for (const string &w : words)
        for (int k = 0; k < wl; ++k)
            ++char_cnt[k][w[k] - 'a'];

    constexpr int mod = 1000000007;
    vector<int> dp, new_dp;
    dp.reserve(wl - tl + 1);
    new_dp.reserve(wl - tl + 1);
    dp.emplace_back(char_cnt[0][target[0] - 'a']);

    for (int k = 1; k < wl; ++k)
    {
        const int start_i = max(0, (k - 1) + tl - wl);

        for (int i = max(0, k + tl - wl); i <= k && i < tl; ++i)
        {
            uint64_t cnt = (uint64_t)(i > 0 ? dp[(i - 1) - start_i] : 1) * char_cnt[k][target[i] - 'a'];

            if (i < k)
                cnt += dp[i - start_i];

            new_dp.emplace_back(cnt % mod);
        }

        std::swap(dp, new_dp);
        new_dp.clear();
    }

    return (int)(dp.back() % mod);
}

#pragma region Top-Down DP
static long getWords(vector<string> &words,
                     string &target,
                     int wordsIndex,
                     int targetIndex,
                     vector<vector<int>> &dp,
                     vector<vector<int>> &charFrequency)
{
    if (targetIndex == target.size())
        return 1;

    if (wordsIndex == words[0].size() ||
        words[0].size() - wordsIndex < target.size() - targetIndex)
        return 0;

    if (dp[wordsIndex][targetIndex] != -1)
        return dp[wordsIndex][targetIndex];

    long countWays = 0;
    int curPos = target[targetIndex] - 'a';
    countWays += getWords(words, target, wordsIndex + 1, targetIndex, dp, charFrequency);
    countWays += charFrequency[wordsIndex][curPos] * getWords(words,
                                                              target,
                                                              wordsIndex + 1,
                                                              targetIndex + 1,
                                                              dp,
                                                              charFrequency);

    return dp[wordsIndex][targetIndex] = countWays % 1000000007;
}

static int _01639_NumberOfWaysToFormATargetStringGivenADictionary1(vector<string> &words, string target)
{
    vector<vector<int>> dp(words[0].size(), vector<int>(target.size(), -1));
    vector<vector<int>> charFrequency(words[0].size(), vector<int>(26, 0));

    for (int i = 0; i < words.size(); i++)
    {
        for (int j = 0; j < words[0].size(); j++)
        {
            int character = words[i][j] - 'a';
            charFrequency[j][character]++;
        }
    }

    return getWords(words, target, 0, 0, dp, charFrequency);
}
#pragma endregion

#pragma region Bottom-Up DP Optimized
static int _01639_NumberOfWaysToFormATargetStringGivenADictionary2(vector<string> &words, string target)
{
    int wordLength = words[0].size();
    int targetLength = target.size();
    const int MOD = 1000000007;
    vector<vector<int>> charFrequency(wordLength, vector<int>(26, 0));

    for (const string &word : words)
    {
        for (int j = 0; j < wordLength; ++j)
        {
            charFrequency[j][word[j] - 'a']++;
        }
    }

    vector<long> prevCount(targetLength + 1, 0);
    vector<long> currCount(targetLength + 1, 0);
    prevCount[0] = 1;

    for (int currWord = 1; currWord <= wordLength; ++currWord)
    {
        currCount = prevCount;

        for (int currTarget = 1; currTarget <= targetLength; ++currTarget)
        {
            int curPos = target[currTarget - 1] - 'a';
            currCount[currTarget] += (charFrequency[currWord - 1][curPos] * prevCount[currTarget - 1]) % MOD;
            currCount[currTarget] %= MOD;
        }

        prevCount = currCount;
    }

    return currCount[targetLength];
}
#pragma endregion

#pragma region GTest
static int is_01639_NumberOfWaysToFormATargetStringGivenADictionary_RunTest()
{
    stringstream ss;
    ss << "*_01639_NumberOfWaysToFormATargetStringGivenADictionary.expected*"
       << ":"
       << "*_01639_NumberOfWaysToFormATargetStringGivenADictionary0.expected*"
       << ":"
       << "*_01639_NumberOfWaysToFormATargetStringGivenADictionary1.expected*"
       << ":"
       << "*_01639_NumberOfWaysToFormATargetStringGivenADictionary2.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_01639_NumberOfWaysToFormATargetStringGivenADictionary, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v1[i];

        // Actual
        int actual = _01639_NumberOfWaysToFormATargetStringGivenADictionary(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_01639_NumberOfWaysToFormATargetStringGivenADictionary0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v1[i];

        // Actual
        int actual = _01639_NumberOfWaysToFormATargetStringGivenADictionary0(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_01639_NumberOfWaysToFormATargetStringGivenADictionary1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v1[i];

        // Actual
        int actual = _01639_NumberOfWaysToFormATargetStringGivenADictionary1(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_01639_NumberOfWaysToFormATargetStringGivenADictionary2, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v1[i];

        // Actual
        int actual = _01639_NumberOfWaysToFormATargetStringGivenADictionary2(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
