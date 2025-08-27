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

// Sorting Items + BS
static vector<int> _02070_MostBeautifulItemForEachQuery(vector<vector<int>> &items, vector<int> &queries);
// Sorting Items + Sorting Queues
static vector<int> _02070_MostBeautifulItemForEachQuery0(vector<vector<int>> &items, vector<int> &queries);
// Speed
static vector<int> _02070_MostBeautifulItemForEachQuery1(vector<vector<int>> &items, vector<int> &queries);

static int is_02070_MostBeautifulItemForEachQuery_RunTest();

/**
 * You are given a 2D integer array items where items[i] = [pricei, beautyi] denotes the price and
 * beauty of an item respectively.
 * You are also given a 0-indexed integer array queries.
 * For each queries[j], you want to determine the maximum beauty of an item whose price is less
 * than or equal to queries[j].
 * If no such item exists, then the answer to this query is 0.
 * Return an array answer of the same length as queries where answer[j] is the answer to the jth query.
 *
 * Constraints:
 *
 * 1 <= items.length, queries.length <= 10^5
 * items[i].length == 2
 * 1 <= pricei, beautyi, queries[j] <= 10^9
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_02070_MostBeautifulItemForEachQuery_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<vector<vector<int>>> v;
static vector<vector<int>> v0, v1;

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
        v.push_back(stringTo2DVectorInt(s));

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
        vector<int> res = _02070_MostBeautifulItemForEachQuery(v[i], v0[i]);
        for (auto &&j : res)
        {
            cout << j << " ";
        }
        cout << "\n";

        vector<int> res0 = _02070_MostBeautifulItemForEachQuery0(v[i], v0[i]);
        for (auto &&j : res0)
        {
            cout << j << " ";
        }
        cout << "\n";

        vector<int> res1 = _02070_MostBeautifulItemForEachQuery1(v[i], v0[i]);
        for (auto &&j : res1)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
}

#pragma region Sorting Items + BS
static int binarySearch(vector<vector<int>> &items, int targetPrice)
{
    int left = 0;
    int right = items.size() - 1;
    int maxBeauty = 0;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (items[mid][0] > targetPrice)
            right = mid - 1;
        else
        {
            maxBeauty = max(maxBeauty, items[mid][1]);
            left = mid + 1;
        }
    }

    return maxBeauty;
}

static vector<int> _02070_MostBeautifulItemForEachQuery(vector<vector<int>> &items, vector<int> &queries)
{
    vector<int> ans(queries.size());
    sort(items.begin(), items.end(),
         [](vector<int> &a, vector<int> &b)
         { return a[0] < b[0]; });
    int maxBeauty = items[0][1];

    for (int i = 0; i < items.size(); i++)
    {
        maxBeauty = max(maxBeauty, items[i][1]);
        items[i][1] = maxBeauty;
    }

    for (int i = 0; i < queries.size(); i++)
    {
        ans[i] = binarySearch(items, queries[i]);
    }

    return ans;
}
#pragma endregion

static vector<int> _02070_MostBeautifulItemForEachQuery0(vector<vector<int>> &items, vector<int> &queries)
{
    vector<int> ans(queries.size());

    sort(items.begin(), items.end(),
         [](vector<int> &a, vector<int> &b)
         { return a[0] < b[0]; });

    vector<vector<int>> queriesWithIndices(queries.size(), vector<int>(2));

    for (int i = 0; i < queries.size(); i++)
    {
        queriesWithIndices[i][0] = queries[i];
        queriesWithIndices[i][1] = i;
    }

    sort(queriesWithIndices.begin(), queriesWithIndices.end(),
         [](vector<int> &a, vector<int> &b)
         { return a[0] < b[0]; });

    int itemIndex = 0;
    int maxBeauty = 0;

    for (int i = 0; i < queries.size(); i++)
    {
        int query = queriesWithIndices[i][0];
        int originalIndex = queriesWithIndices[i][1];

        while (itemIndex < items.size() && items[itemIndex][0] <= query)
        {
            maxBeauty = max(maxBeauty, items[itemIndex][1]);
            itemIndex++;
        }

        ans[originalIndex] = maxBeauty;
    }

    return ans;
}

#pragma region Speed
static int bs(vector<int> &prices, int target)
{
    int low = 0;
    int high = prices.size() - 1;
    int result = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (prices[mid] <= target)
        {
            result = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    return result;
}

static vector<int> _02070_MostBeautifulItemForEachQuery1(vector<vector<int>> &items, vector<int> &queries)
{
    sort(items.begin(), items.end());
    int n = items.size();
    vector<int> maxBeauty(n), prices(n);
    maxBeauty[0] = items[0][1];
    prices[0] = items[0][0];

    for (int i = 1; i < n; i++)
    {
        prices[i] = items[i][0];
        maxBeauty[i] = max(maxBeauty[i - 1], items[i][1]);
    }

    int m = queries.size();
    vector<int> ans(m);

    for (int i = 0; i < m; i++)
    {
        int idx = bs(prices, queries[i]);

        if (idx == -1)
            ans[i] = 0;
        else
            ans[i] = maxBeauty[idx];
    }

    return ans;
}
#pragma endregion

#pragma region GTest
static int is_02070_MostBeautifulItemForEachQuery_RunTest()
{
    stringstream ss;
    ss << "*_02070_MostBeautifulItemForEachQuery.expected*"
       << ":"
       << "*_02070_MostBeautifulItemForEachQuery0.expected*"
       << ":"
       << "*_02070_MostBeautifulItemForEachQuery1.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_02070_MostBeautifulItemForEachQuery, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<int> expected = v1[i];

        // Actual
        vector<int> actual = _02070_MostBeautifulItemForEachQuery(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02070_MostBeautifulItemForEachQuery0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<int> expected = v1[i];

        // Actual
        vector<int> actual = _02070_MostBeautifulItemForEachQuery0(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02070_MostBeautifulItemForEachQuery1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<int> expected = v1[i];

        // Actual
        vector<int> actual = _02070_MostBeautifulItemForEachQuery1(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
