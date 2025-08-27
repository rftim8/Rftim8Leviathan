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

// Sorting
static long long _02593_FindScoreOfAnArrayAfterMarkingAllElements(vector<int> &nums);
// Heap
static long long _02593_FindScoreOfAnArrayAfterMarkingAllElements0(vector<int> &nums);

static int is_02593_FindScoreOfAnArrayAfterMarkingAllElements_RunTest();

/**
 * You are given an array nums consisting of positive integers.
 * Starting with score = 0, apply the following algorithm:
 * Choose the smallest integer of the array that is not marked.
 * If there is a tie, choose the one with the smallest index.
 * Add the value of the chosen integer to score.
 * Mark the chosen element and its two adjacent elements if they exist.
 * Repeat until all the array elements are marked.
 * Return the score you get after applying the above algorithm.
 *
 * Constraints:
 *
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^6
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_02593_FindScoreOfAnArrayAfterMarkingAllElements_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<vector<int>> v;
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
        stringstream ss(s);
        string t;
        vector<int> d = {};
        while (getline(ss, t, ','))
        {
            d.push_back(stoi(t));
        }
        v.push_back(d);

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
        cout << _02593_FindScoreOfAnArrayAfterMarkingAllElements(v[i]) << "\n";
        cout << _02593_FindScoreOfAnArrayAfterMarkingAllElements0(v[i]) << "\n";
    }
}

static long long _02593_FindScoreOfAnArrayAfterMarkingAllElements(vector<int> &nums)
{
    long ans = 0;
    vector<pair<int, int>> sorted(nums.size());

    for (int i = 0; i < nums.size(); i++)
    {
        sorted[i] = make_pair(nums[i], i);
    }

    sort(sorted.begin(), sorted.end());
    vector<bool> marked(nums.size(), false);

    for (int i = 0; i < nums.size(); i++)
    {
        int number = sorted[i].first;
        int index = sorted[i].second;

        if (!marked[index])
        {
            ans += number;
            marked[index] = true;

            if (index - 1 >= 0)
                marked[index - 1] = true;

            if (index + 1 < nums.size())
                marked[index + 1] = true;
        }
    }

    return ans;
}

static long long _02593_FindScoreOfAnArrayAfterMarkingAllElements0(vector<int> &nums)
{
    long long ans = 0;
    vector<bool> marked(nums.size());

    auto cmp = [](pair<int, int> &pair1, pair<int, int> &pair2)
    {
        if (pair1.first != pair2.first)
            return pair1.first > pair2.first;

        return pair1.second > pair2.second;
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)>
        heap(cmp);

    for (int i = 0; i < nums.size(); ++i)
    {
        heap.push(make_pair(nums[i], i));
    }

    while (!heap.empty())
    {
        pair<int, int> element = heap.top();
        heap.pop();
        int number = element.first;
        int index = element.second;

        if (!marked[index])
        {
            ans += number;
            marked[index] = true;

            if (index - 1 >= 0)
                marked[index - 1] = true;

            if (index + 1 < nums.size())
                marked[index + 1] = true;
        }
    }

    return ans;
}

#pragma region GTest
static int is_02593_FindScoreOfAnArrayAfterMarkingAllElements_RunTest()
{
    stringstream ss;
    ss << "*_02593_FindScoreOfAnArrayAfterMarkingAllElements.expected*"
       << ":"
       << "*_02593_FindScoreOfAnArrayAfterMarkingAllElements0.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_02593_FindScoreOfAnArrayAfterMarkingAllElements, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _02593_FindScoreOfAnArrayAfterMarkingAllElements(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02593_FindScoreOfAnArrayAfterMarkingAllElements0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _02593_FindScoreOfAnArrayAfterMarkingAllElements0(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
