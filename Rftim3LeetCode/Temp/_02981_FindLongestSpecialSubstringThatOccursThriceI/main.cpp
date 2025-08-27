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

// Brute Force
static int _02981_FindLongestSpecialSubstringThatOccursThriceI(string s);
// Optimized Hashing
static int _02981_FindLongestSpecialSubstringThatOccursThriceI0(string s);
// Speed
static int _02981_FindLongestSpecialSubstringThatOccursThriceI1(string s);

static int is_02981_FindLongestSpecialSubstringThatOccursThriceI_RunTest();

/**
 * You are given a string s that consists of lowercase English letters.
 * A string is called special if it is made up of only a single character.
 * For example, the string "abc" is not special, whereas the strings "ddd", "zz", and "f" are special.
 * Return the length of the longest special substring of s which occurs at least thrice,
 * or -1 if no special substring occurs at least thrice.
 * A substring is a contiguous non-empty sequence of characters within a string.
 *
 * Constraints:
 *
 * 3 <= s.length <= 50
 * s consists of only lowercase English letters.
 */
int main()
{
    offline();
    dataCollector();

    solve();
    return 0;

    ::testing::InitGoogleTest();
    is_02981_FindLongestSpecialSubstringThatOccursThriceI_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<string> v;
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
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        cout << _02981_FindLongestSpecialSubstringThatOccursThriceI(v[i]) << "\n";
        cout << _02981_FindLongestSpecialSubstringThatOccursThriceI0(v[i]) << "\n";
        cout << _02981_FindLongestSpecialSubstringThatOccursThriceI1(v[i]) << "\n";
    }
}

static int _02981_FindLongestSpecialSubstringThatOccursThriceI(string s)
{
    map<string, int> count;

    for (int start = 0; start < s.length(); start++)
    {
        string currString;

        for (int end = start; end < s.length(); end++)
        {
            if (currString.empty() or currString.back() == s[end])
            {
                currString.push_back(s[end]);
                count[currString]++;
            }
            else
                break;
        }
    }

    int ans = 0;

    for (auto i : count)
    {
        string str = i.first;

        if (i.second >= 3 && str.length() > ans)
            ans = str.length();
    }

    if (ans == 0)
        return -1;

    return ans;
}

static int _02981_FindLongestSpecialSubstringThatOccursThriceI0(string s)
{
    map<pair<char, int>, int> count;
    int substringLength = 0;

    for (int start = 0; start < s.length(); start++)
    {
        char character = s[start];
        substringLength = 0;

        for (int end = start; end < s.length(); end++)
        {
            if (character == s[end])
            {
                substringLength++;
                count[{character, substringLength}]++;
            }
            else
                break;
        }
    }

    int ans = 0;

    for (auto i : count)
    {
        int len = i.first.second;

        if (i.second >= 3 && len > ans)
            ans = len;
    }

    if (ans == 0)
        return -1;

    return ans;
}

static int _02981_FindLongestSpecialSubstringThatOccursThriceI1(string s)
{
    int l = 0, r = 1, n = s.size();
    int cnt[26][60] = {};
    int ans = -1;
    
    while (r <= n)
    {
        while (r < n && s[r] == s[l])
            r++;
    
        for (int i = r - 1; i >= l; i--)
        {
            int len = i - l + 1;
            cnt[s[l] - 'a'][len] += r - i;
    
            if (cnt[s[l] - 'a'][len] > 2 && len > ans)
                ans = len;
        }
    
        l = r;
        r++;
    }

    return ans;
}

#pragma region GTest
static int is_02981_FindLongestSpecialSubstringThatOccursThriceI_RunTest()
{
    stringstream ss;
    ss << "*_02981_FindLongestSpecialSubstringThatOccursThriceI.expected*"
       << ":"
       << "*_02981_FindLongestSpecialSubstringThatOccursThriceI0.expected*"
       << ":"
       << "*_02981_FindLongestSpecialSubstringThatOccursThriceI1.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_02981_FindLongestSpecialSubstringThatOccursThriceI, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _02981_FindLongestSpecialSubstringThatOccursThriceI(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02981_FindLongestSpecialSubstringThatOccursThriceI0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _02981_FindLongestSpecialSubstringThatOccursThriceI0(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02981_FindLongestSpecialSubstringThatOccursThriceI1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _02981_FindLongestSpecialSubstringThatOccursThriceI1(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
