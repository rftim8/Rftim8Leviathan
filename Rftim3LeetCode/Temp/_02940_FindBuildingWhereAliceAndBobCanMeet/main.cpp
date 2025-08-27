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

// Monotonic Stack
static vector<int> _02940_FindBuildingWhereAliceAndBobCanMeet(vector<int> &heights, vector<vector<int>> &queries);
// Priority Queue
static vector<int> _02940_FindBuildingWhereAliceAndBobCanMeet0(vector<int> &heights, vector<vector<int>> &queries);
// Speed
static vector<int> _02940_FindBuildingWhereAliceAndBobCanMeet1(vector<int> &heights, vector<vector<int>> &queries);

static int is_02940_FindBuildingWhereAliceAndBobCanMeet_RunTest();

/**
 * You are given a 0-indexed array heights of positive integers, where heights[i] represents the height
 * of the ith building.
 * If a person is in building i, they can move to any other building j if and only if i < j and heights[i] < heights[j].
 * You are also given another array queries where queries[i] = [ai, bi].
 * On the ith query, Alice is in building ai while Bob is in building bi.
 * Return an array ans where ans[i] is the index of the leftmost building where Alice and Bob can meet on the ith query.
 * If Alice and Bob cannot move to a common building on query i, set ans[i] to -1.
 *
 * Constraints:
 *
 * 1 <= heights.length <= 5 * 10^4
 * 1 <= heights[i] <= 10^9
 * 1 <= queries.length <= 5 * 10^4
 * queries[i] = [ai, bi]
 * 0 <= ai, bi <= heights.length - 1
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_02940_FindBuildingWhereAliceAndBobCanMeet_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<vector<int>> v, v1;
static vector<vector<vector<int>>> v0;

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

        s = "";
        getline(cin, s);
        v0.push_back(stringTo2DVectorInt(s));

        s = "";
        getline(cin, s);
        ss.clear();
        ss.str(s);
        t = "";
        d = {};
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
        vector<int> res = _02940_FindBuildingWhereAliceAndBobCanMeet(v[i], v0[i]);
        for (auto &&j : res)
        {
            cout << j << " ";
        }
        cout << "\n";

        vector<int> res0 = _02940_FindBuildingWhereAliceAndBobCanMeet(v[i], v0[i]);
        for (auto &&j : res0)
        {
            cout << j << " ";
        }
        cout << "\n";

        vector<int> res1 = _02940_FindBuildingWhereAliceAndBobCanMeet(v[i], v0[i]);
        for (auto &&j : res1)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
}

#pragma region Montonic Stack
static int search(int height, vector<pair<int, int>> &monoStack)
{
    int left = 0;
    int right = monoStack.size() - 1;
    int ans = -1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (monoStack[mid].first > height)
        {
            ans = max(ans, mid);
            left = mid + 1;
        }
        else
            right = mid - 1;
    }

    return ans;
}

static vector<int> _02940_FindBuildingWhereAliceAndBobCanMeet(vector<int> &heights, vector<vector<int>> &queries)
{
    vector<pair<int, int>> monoStack;
    vector<int> result(queries.size(), -1);
    vector<vector<pair<int, int>>> newQueries(heights.size());

    for (int i = 0; i < queries.size(); i++)
    {
        int a = queries[i][0];
        int b = queries[i][1];

        if (a > b)
            swap(a, b);

        if (heights[b] > heights[a] || a == b)
            result[i] = b;
        else
            newQueries[b].push_back({heights[a], i});
    }

    for (int i = heights.size() - 1; i >= 0; i--)
    {
        int monoStackSize = monoStack.size();

        for (auto &[a, b] : newQueries[i])
        {
            int position = search(a, monoStack);

            if (position < monoStackSize && position >= 0)
                result[b] = monoStack[position].second;
        }

        while (!monoStack.empty() && monoStack.back().first <= heights[i])
            monoStack.pop_back();

        monoStack.push_back({heights[i], i});
    }

    return result;
}
#pragma endregion

#pragma region Priority Queue
static vector<int> _02940_FindBuildingWhereAliceAndBobCanMeet0(vector<int> &heights, vector<vector<int>> &queries)
{
    vector<vector<vector<int>>> storeQueries(heights.size());
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> maxIndex;
    vector<int> result(queries.size(), -1);

    for (int currQuery = 0; currQuery < queries.size(); currQuery++)
    {
        int a = queries[currQuery][0], b = queries[currQuery][1];

        if (a < b && heights[a] < heights[b])
            result[currQuery] = b;
        else if (a > b && heights[a] > heights[b])
            result[currQuery] = a;
        else if (a == b)
            result[currQuery] = a;
        else
            storeQueries[max(a, b)].push_back({max(heights[a], heights[b]), currQuery});
    }

    for (int index = 0; index < heights.size(); index++)
    {
        while (!maxIndex.empty() && maxIndex.top()[0] < heights[index])
        {
            result[maxIndex.top()[1]] = index;
            maxIndex.pop();
        }

        for (auto &element : storeQueries[index])
        {
            maxIndex.push(element);
        }
    }

    return result;
}
#pragma endregion

#pragma region Speed
static constexpr int MAX_SZ = 5e4 + 10;
static constexpr int INF = 1e5;
static int tree[MAX_SZ * 4];

static void build_tree(int v, int tl, int tr, vector<int> &heights)
{
    if (tl == tr)
    {
        tree[v] = heights[tl];
        return;
    }

    int tm = (tl + tr) / 2;

    build_tree(v * 2 + 1, tl, tm, heights);
    build_tree(v * 2 + 2, tm + 1, tr, heights);
    tree[v] = max(tree[v * 2 + 1], tree[v * 2 + 2]);
}

static int leftmost_greater_idx(int v, int tl, int tr, int l, int r, int min_val)
{
    if (tl > r || tr < l)
        return INF;

    if (tree[v] < min_val)
        return INF;

    if (tl == tr)
        return tl;

    int tm = (tl + tr) / 2;

    int ltree_ans = leftmost_greater_idx(v * 2 + 1, tl, tm, l, r, min_val);

    if (ltree_ans != INF)
        return ltree_ans;

    return leftmost_greater_idx(v * 2 + 2, tm + 1, tr, l, r, min_val);
}

static vector<int> _02940_FindBuildingWhereAliceAndBobCanMeet1(vector<int> &heights, vector<vector<int>> &queries)
{
    vector<int> answers;
    answers.reserve(queries.size());
    int n = heights.size();
    build_tree(0, 0, n - 1, heights);

    for (auto &query : queries)
    {
        int a = query[0], b = query[1];

        if (a > b)
            swap(a, b);

        if (a == b)
        {
            answers.push_back(a);
            continue;
        }

        int min_height = max(heights[a], heights[b]);

        if (heights[a] >= heights[b])
            ++min_height;

        int answer = leftmost_greater_idx(0, 0, n - 1, b, n - 1, min_height);

        if (answer == INF)
            answer = -1;

        answers.push_back(answer);
    }

    return answers;
}
#pragma endregion

#pragma region GTest
static int is_02940_FindBuildingWhereAliceAndBobCanMeet_RunTest()
{
    stringstream ss;
    ss << "*_02940_FindBuildingWhereAliceAndBobCanMeet.expected*"
       << ":"
       << "*_02940_FindBuildingWhereAliceAndBobCanMeet0.expected*"
       << ":"
       << "*_02940_FindBuildingWhereAliceAndBobCanMeet1.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_02940_FindBuildingWhereAliceAndBobCanMeet, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<int> expected = v1[i];

        // Actual
        vector<int> actual = _02940_FindBuildingWhereAliceAndBobCanMeet(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02940_FindBuildingWhereAliceAndBobCanMeet0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<int> expected = v1[i];

        // Actual
        vector<int> actual = _02940_FindBuildingWhereAliceAndBobCanMeet0(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02940_FindBuildingWhereAliceAndBobCanMeet1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<int> expected = v1[i];

        // Actual
        vector<int> actual = _02940_FindBuildingWhereAliceAndBobCanMeet1(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
