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

// Count Left Zeroes And Right Zeroes - Brute Force
static int _01422_MaximumScoreAfterSplittingAString(string s);
// Count Left Zeroes And Right Zeroes - Optimized
static int _01422_MaximumScoreAfterSplittingAString0(string s);
// One Pass
static int _01422_MaximumScoreAfterSplittingAString1(string s);

static int is_01422_MaximumScoreAfterSplittingAString_RunTest();

/**
 * Given a string s of zeros and ones, return the maximum score after splitting the string into two
 * non-empty substrings (i.e. left substring and right substring).
 * The score after splitting a string is the number of zeros in the left substring plus the number
 * of ones in the right substring.
 *
 * Constraints:
 *
 * 2 <= s.length <= 500
 * The string s consists of characters '0' and '1' only.
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_01422_MaximumScoreAfterSplittingAString_RunTest();
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
        getline(cin, s);
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
        cout << _01422_MaximumScoreAfterSplittingAString(v[i]) << "\n";
        cout << _01422_MaximumScoreAfterSplittingAString0(v[i]) << "\n";
        cout << _01422_MaximumScoreAfterSplittingAString1(v[i]) << "\n";
    }
}

static int _01422_MaximumScoreAfterSplittingAString(string s)
{
    vector<int> x = {};

    for (int i = 0; i < s.size() - 1; i++)
    {
        int l = count(s.begin(), s.begin() + i + 1, '0');
        int r = count(s.begin() + i + 1, s.end(), '1');
        x.push_back(l + r);
    }

    return *max_element(x.begin(), x.end());
}

static int _01422_MaximumScoreAfterSplittingAString0(string s)
{
    int ones = count(s.begin(), s.end(), '1');
    int ans = 0;
    int zeros = 0;

    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] == '1')
            ones--;
        else
            zeros++;

        ans = max(ans, zeros + ones);
    }

    return ans;
}

static int _01422_MaximumScoreAfterSplittingAString1(string s)
{
    int ones = 0;
    int zeros = 0;
    int best = INT_MIN;

    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] == '1')
            ones++;
        else
            zeros++;

        best = max(best, zeros - ones);
    }

    if (s[s.size() - 1] == '1')
        ones++;

    return best + ones;
}

#pragma region GTest
static int is_01422_MaximumScoreAfterSplittingAString_RunTest()
{
    stringstream ss;
    ss << "*_01422_MaximumScoreAfterSplittingAString.expected*"
       << ":"
       << "*_01422_MaximumScoreAfterSplittingAString0.expected*"
       << ":"
       << "*_01422_MaximumScoreAfterSplittingAString1.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_01422_MaximumScoreAfterSplittingAString, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _01422_MaximumScoreAfterSplittingAString(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_01422_MaximumScoreAfterSplittingAString0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _01422_MaximumScoreAfterSplittingAString0(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_01422_MaximumScoreAfterSplittingAString1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _01422_MaximumScoreAfterSplittingAString1(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
