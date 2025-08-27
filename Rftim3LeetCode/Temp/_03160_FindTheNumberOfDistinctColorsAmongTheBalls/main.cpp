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

// Two Unordered_Maps - My submission
static vector<int> _03160_FindTheNumberOfDistinctColorsAmongTheBalls(int limit, vector<vector<int>> &queries);
// Runtime
static vector<int> _03160_FindTheNumberOfDistinctColorsAmongTheBalls_0(int limit, vector<vector<int>> &queries);
// Memory
static vector<int> _03160_FindTheNumberOfDistinctColorsAmongTheBalls_1(int limit, vector<vector<int>> &queries);

static int is_03160_FindTheNumberOfDistinctColorsAmongTheBalls_RunTest();

/**
 * You are given an integer limit and a 2D array queries of size n x 2.
 * There are limit + 1 balls with distinct labels in the range [0, limit].
 * Initially, all balls are uncolored.
 * For every query in queries that is of the form [x, y], you mark ball x with the color y.
 * After each query, you need to find the number of distinct colors among the balls.
 * Return an array result of length n, where result[i] denotes the number of distinct colors after ith query.
 * Note that when answering a query, lack of a color will not be considered as a color.
 *
 * Constraints:
 *
 * 1 <= limit <= 10^9
 * 1 <= n == queries.length <= 10^5
 * queries[i].length == 2
 * 0 <= queries[i][0] <= limit
 * 1 <= queries[i][1] <= 10^9
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_03160_FindTheNumberOfDistinctColorsAmongTheBalls_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<int> v;
static vector<vector<vector<int>>> v0;
static vector<vector<int>> v1;

static vector<vector<int>> stringTo2DVectorInt(string s)
{
    vector<vector<int>> res = {};
    int l = 0, r = 0;
    string a = "";
    vector<string> vv = {};
    for (auto &&j : s)
    {
        if (j == '[')
            l++;
        else if (j == ']')
        {
            r++;
            if (l > r)
            {
                vv.push_back(a);
                a = "";
            }
        }
        else
            a += j;
    }

    for (auto &&j : vv)
    {
        vector<int> a = {};
        string t;
        stringstream ss(j);
        while (getline(ss, t, ','))
        {
            if (t != "null" &&
                t != "")
                a.push_back(stoi(t));
        }
        res.push_back(a);
    }

    return res;
}

static void dataCollector()
{
    cin >> n;
    cin >> m;
    cin.get();

    for (int i = 0; i < n * m; i += m)
    {
        int s;
        cin >> s;
        cin.get();
        v.push_back(s);

        string s0;
        getline(cin, s0);
        v0.push_back(stringTo2DVectorInt(s0));

        string s1;
        getline(cin, s1);
        stringstream ss(s1);
        string t;
        vector<int> d = {};
        while (getline(ss, t, ','))
        {
            d.push_back(stoi(t));
        }
        v1.push_back(d);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        vector<int> res = _03160_FindTheNumberOfDistinctColorsAmongTheBalls(v[i], v0[i]);
        for (auto &&j : res)
        {
            cout << j << " ";
        }
        cout << "\n";

        vector<int> res0 = _03160_FindTheNumberOfDistinctColorsAmongTheBalls_0(v[i], v0[i]);
        for (auto &&j : res0)
        {
            cout << j << " ";
        }
        cout << "\n";

        vector<int> res1 = _03160_FindTheNumberOfDistinctColorsAmongTheBalls_1(v[i], v0[i]);
        for (auto &&j : res1)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
}

static vector<int> _03160_FindTheNumberOfDistinctColorsAmongTheBalls(int limit, vector<vector<int>> &queries)
{
    vector<int> res = {};
    unordered_map<int, int> um = {};
    unordered_map<int, int> colors = {};

    for (auto &&i : queries)
    {
        if (!um[i[0]])
        {
            um[i[0]] = i[1];
            colors[i[1]]++;
        }
        else
        {
            colors[um[i[0]]]--;
            if (colors[um[i[0]]] == 0)
                colors.erase(um[i[0]]);

            um[i[0]] = i[1];
            colors[i[1]]++;
        }

        if (colors.size() <= limit + 1)
            res.push_back(colors.size());
    }

    return res;
}

static vector<int> _03160_FindTheNumberOfDistinctColorsAmongTheBalls_0(int limit, vector<vector<int>> &queries)
{
    auto ball_to_color = unordered_map<int, int>{};
    auto color_counts = unordered_map<int, int>{};
    auto num_colors = 0;
    auto result = vector<int>{};
    result.reserve(size(queries));

    for (const auto &query : queries)
    {
        auto [ball, color] = make_pair(query[0], query[1]);
        auto &color_assignment = ball_to_color[ball];

        if (color_assignment)
        {
            if (--color_counts[color_assignment] == 0)
                --num_colors;
        }

        color_assignment = color;

        if (++color_counts[color] == 1)
            ++num_colors;

        result.push_back(num_colors);
    }

    return result;
}

static vector<int> _03160_FindTheNumberOfDistinctColorsAmongTheBalls_1(int limit, vector<vector<int>> &queries)
{
    auto ball_to_color = unordered_map<int, int>{};
    auto color_counts = unordered_map<int, int>{};
    auto num_colors = 0;
    auto result = vector<int>{};
    result.reserve(size(queries));

    for (const auto &query : queries)
    {
        auto [ball, color] = make_pair(query[0], query[1]);
        auto &color_assignment = ball_to_color[ball];

        if (color_assignment)
        {
            if (--color_counts[color_assignment] == 0)
                --num_colors;
        }

        color_assignment = color;

        if (++color_counts[color] == 1)
            ++num_colors;

        result.push_back(num_colors);
    }

    return result;
}

#pragma region GTest
static int is_03160_FindTheNumberOfDistinctColorsAmongTheBalls_RunTest()
{
    stringstream ss;
    ss << "*_03160_FindTheNumberOfDistinctColorsAmongTheBalls.expected*"
       << ":"
       << "*_03160_FindTheNumberOfDistinctColorsAmongTheBalls_0.expected*"
       << ":"
       << "*_03160_FindTheNumberOfDistinctColorsAmongTheBalls_1.expected*"
       << ":";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_03160_FindTheNumberOfDistinctColorsAmongTheBalls, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<int> expected = v1[i];

        // Actual
        vector<int> actual = _03160_FindTheNumberOfDistinctColorsAmongTheBalls(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_03160_FindTheNumberOfDistinctColorsAmongTheBalls_0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<int> expected = v1[i];

        // Actual
        vector<int> actual = _03160_FindTheNumberOfDistinctColorsAmongTheBalls_0(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_03160_FindTheNumberOfDistinctColorsAmongTheBalls_1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<int> expected = v1[i];

        // Actual
        vector<int> actual = _03160_FindTheNumberOfDistinctColorsAmongTheBalls_1(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
