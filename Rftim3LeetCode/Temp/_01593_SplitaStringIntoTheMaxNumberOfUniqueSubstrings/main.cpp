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

// Backtracking
static int _01593_SplitaStringIntoTheMaxNumberOfUniqueSubstrings(string s);
// Backtracking with Pruning
static int _01593_SplitaStringIntoTheMaxNumberOfUniqueSubstrings0(string s);

static int is_01593_SplitaStringIntoTheMaxNumberOfUniqueSubstrings_RunTest();

/**
 * Given a string s, return the maximum number of unique substrings that the given string can be split into.
 * You can split string s into any list of non-empty substrings, where the concatenation of the substrings forms the original string.
 * However, you must split the substrings such that all of them are unique.
 * A substring is a contiguous sequence of characters within a string.
 *
 * Constraints:
 *
 * 1 <= s.length <= 16
 * s contains only lower case English letters.
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_01593_SplitaStringIntoTheMaxNumberOfUniqueSubstrings_RunTest();
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
        cin.get();
        v0.push_back(s0);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        cout << _01593_SplitaStringIntoTheMaxNumberOfUniqueSubstrings(v[i]) << "\n";
        cout << _01593_SplitaStringIntoTheMaxNumberOfUniqueSubstrings0(v[i]) << "\n";
    }
}

static int backtrack(const string &s, int start, unordered_set<string> &seen)
{
    if (start == s.size())
        return 0;

    int maxCount = 0;

    for (int end = start + 1; end <= s.size(); ++end)
    {
        string substring = s.substr(start, end - start);

        if (seen.find(substring) == seen.end())
        {
            seen.insert(substring);
            maxCount = max(maxCount, 1 + backtrack(s, end, seen));
            seen.erase(substring);
        }
    }

    return maxCount;
}

static int _01593_SplitaStringIntoTheMaxNumberOfUniqueSubstrings(string s)
{
    unordered_set<string> seen;

    return backtrack(s, 0, seen);
}

static void backtrack0(const string &s, int start, unordered_set<string> &seen, int count, int &maxCount)
{
    if (count + (s.size() - start) <= maxCount)
        return;

    if (start == s.size())
    {
        maxCount = max(maxCount, count);

        return;
    }

    for (int end = start + 1; end <= s.size(); ++end)
    {
        string substring = s.substr(start, end - start);

        if (seen.find(substring) == seen.end())
        {
            seen.insert(substring);
            backtrack0(s, end, seen, count + 1, maxCount);
            seen.erase(substring);
        }
    }
}

static int _01593_SplitaStringIntoTheMaxNumberOfUniqueSubstrings0(string s)
{
    unordered_set<string> seen;
    int maxCount = 0;
    backtrack0(s, 0, seen, 0, maxCount);
    return maxCount;
}

#pragma region GTest
static int is_01593_SplitaStringIntoTheMaxNumberOfUniqueSubstrings_RunTest()
{
    stringstream ss;
    ss << "*_01593_SplitaStringIntoTheMaxNumberOfUniqueSubstrings.expected*"
       << ":"
       << "*_01593_SplitaStringIntoTheMaxNumberOfUniqueSubstrings0.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_01593_SplitaStringIntoTheMaxNumberOfUniqueSubstrings, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _01593_SplitaStringIntoTheMaxNumberOfUniqueSubstrings(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_01593_SplitaStringIntoTheMaxNumberOfUniqueSubstrings0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _01593_SplitaStringIntoTheMaxNumberOfUniqueSubstrings0(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
