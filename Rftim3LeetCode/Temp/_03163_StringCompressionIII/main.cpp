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

// String Manipulation
static string _03163_StringCompressionIII(string word);
// Speed
static string _03163_StringCompressionIII0(string word);

static int is_03163_StringCompressionIII_RunTest();

/**
 * Given a string word, compress it using the following algorithm:
 * Begin with an empty string comp. While word is not empty, use the following operation:
 * Remove a maximum length prefix of word made of a single character c repeating at most 9 times.
 * Append the length of the prefix followed by c to comp.
 * Return the string comp.
 *
 * Constraints:
 *
 * 1 <= word.length <= 2 * 10^5
 * word consists only of lowercase English letters.
 */
int main()
{
    offline();
    dataCollector();

    solve();
    return 0;

    ::testing::InitGoogleTest();
    is_03163_StringCompressionIII_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<string> v, v0;

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

        cin >> s;
        v0.push_back(s);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        cout << _03163_StringCompressionIII(v[i]) << "\n";
        cout << _03163_StringCompressionIII0(v[i]) << "\n";
    }
}

static string _03163_StringCompressionIII(string word)
{
    string comp = "";
    int pos = 0;

    while (pos < word.length())
    {
        int consecutiveCount = 0;
        char currentChar = word[pos];

        while (pos < word.length() &&
               consecutiveCount < 9 &&
               word[pos] == currentChar)
        {
            consecutiveCount++;
            pos++;
        }

        comp += to_string(consecutiveCount) + currentChar;
    }

    return comp;
}

static string _03163_StringCompressionIII0(string word)
{
    string ret;
    char prev = word[0], cnt = '0';

    for (const auto c : word)
    {
        if (c != prev || cnt == '9')
        {
            ret.push_back(cnt);
            ret.push_back(prev);
            cnt = '0';
        }

        prev = c;
        cnt++;
    }

    if (cnt != '0')
    {
        ret.push_back(cnt);
        ret.push_back(prev);
    }

    return ret;
}

#pragma region GTest
static int is_03163_StringCompressionIII_RunTest()
{
    stringstream ss;
    ss << "*_03163_StringCompressionIII.expected*"
       << ":"
       << "*_03163_StringCompressionIII0.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_03163_StringCompressionIII, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        string expected = v0[i];

        // Actual
        string actual = _03163_StringCompressionIII(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_03163_StringCompressionIII0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        string expected = v0[i];

        // Actual
        string actual = _03163_StringCompressionIII0(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
