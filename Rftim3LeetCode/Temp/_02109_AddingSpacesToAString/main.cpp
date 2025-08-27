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

// Iterative
static string _02109_AddingSpacesToAString(string s, vector<int> &spaces);
// Two-Pointers
static string _02109_AddingSpacesToAString0(string s, vector<int> &spaces);
// Speed
static string _02109_AddingSpacesToAString1(string s, vector<int> &spaces);

static int is_02109_AddingSpacesToAString_RunTest();

/**
 * You are given a 0-indexed string s and a 0-indexed integer array spaces that describes the indices
 * in the original string where spaces will be added.
 * Each space should be inserted before the character at the given index.
 *
 * For example, given s = "EnjoyYourCoffee" and spaces = [5, 9], we place spaces before 'Y' and 'C',
 * which are at indices 5 and 9 respectively.
 * Thus, we obtain "Enjoy Your Coffee".
 * Return the modified string after the spaces have been added.
 *
 * Constraints:
 *
 * 1 <= s.length <= 3 * 10^5
 * s consists only of lowercase and uppercase English letters.
 * 1 <= spaces.length <= 3 * 10^5
 * 0 <= spaces[i] <= s.length - 1
 * All the values of spaces are strictly increasing.
 */
int main()
{
    offline();
    dataCollector();

    solve();
    return 0;

    ::testing::InitGoogleTest();
    is_02109_AddingSpacesToAString_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<string> v, v1;
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
        v.push_back(s);

        s = "";
        getline(cin, s);
        stringstream ss(s);
        string t;
        vector<int> d = {};
        while (getline(ss, t, ','))
        {
            d.push_back(stoi(t));
        }
        v0.push_back(d);

        s = "";
        getline(cin, s);
        v1.push_back(s);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        cout << _02109_AddingSpacesToAString(v[i], v0[i]) << "\n";
        cout << _02109_AddingSpacesToAString0(v[i], v0[i]) << "\n";
        cout << _02109_AddingSpacesToAString1(v[i], v0[i]) << "\n";
    }
}

static string _02109_AddingSpacesToAString(string s, vector<int> &spaces)
{
    stringstream result;
    int spaceIndex = 0;

    for (int stringIndex = 0; stringIndex < s.size(); ++stringIndex)
    {
        if (spaceIndex < spaces.size() &&
            stringIndex == spaces[spaceIndex])
        {
            result << ' ';
            ++spaceIndex;
        }

        result << s[stringIndex];
    }

    return result.str();
}

static string _02109_AddingSpacesToAString0(string s, vector<int> &spaces)
{
    string result;
    result.reserve(s.size() + spaces.size());
    int spaceIndex = 0;

    for (int stringIndex = 0; stringIndex < s.size(); ++stringIndex)
    {
        if (spaceIndex < spaces.size() &&
            stringIndex == spaces[spaceIndex])
        {
            result += ' ';
            ++spaceIndex;
        }

        result += s[stringIndex];
    }

    return result;
}

static string _02109_AddingSpacesToAString1(string s, vector<int> &spaces)
{
    int totalLength = s.size() + spaces.size();
    char result[totalLength];
    int sIndex = 0, spacesIndex = 0, resultIndex = 0;

    while (sIndex < s.size())
    {
        if (spacesIndex < spaces.size() && sIndex == spaces[spacesIndex])
        {
            result[resultIndex++] = ' ';
            spacesIndex++;
        }

        result[resultIndex++] = s[sIndex++];
    }

    return string(result, totalLength);
}

#pragma region GTest
static int is_02109_AddingSpacesToAString_RunTest()
{
    stringstream ss;
    ss << "*_02109_AddingSpacesToAString.expected*"
       << ":"
       << "*_02109_AddingSpacesToAString0.expected*"
       << ":"
       << "*_02109_AddingSpacesToAString1.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_02109_AddingSpacesToAString, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        string expected = v1[i];

        // Actual
        string actual = _02109_AddingSpacesToAString(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02109_AddingSpacesToAString0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        string expected = v1[i];

        // Actual
        string actual = _02109_AddingSpacesToAString0(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02109_AddingSpacesToAString1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        string expected = v1[i];

        // Actual
        string actual = _02109_AddingSpacesToAString1(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
