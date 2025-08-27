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

// Sorting + Hash Map
static vector<int> _01331_RankTransformOfAnArray(vector<int> &arr);
// Deduplicating with Set
static vector<int> _01331_RankTransformOfAnArray0(vector<int> &arr);
// Ordered Map
static vector<int> _01331_RankTransformOfAnArray1(vector<int> &arr);
// Speed
static vector<int> _01331_RankTransformOfAnArray2(vector<int> &arr);

static int is_01331_RankTransformOfAnArray_RunTest();

/**
 * Given an array of integers arr, replace each element with its rank.
 * The rank represents how large the element is. The rank has the following rules:
 *
 * Rank is an integer starting from 1.
 * The larger the element, the larger the rank. If two elements are equal, their rank must be the same.
 * Rank should be as small as possible.
 *
 * Constraints:
 *
 * 0 <= arr.length <= 10^5
 * -10^9 <= arr[i] <= 10^9
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_01331_RankTransformOfAnArray_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<vector<int>> v, v0;

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
        vector<int> vv = {};
        while (getline(ss, t, ','))
        {
            vv.push_back(stoi(t));
        }
        v.push_back(vv);

        s = "";
        getline(cin, s);
        ss.clear();
        ss.str(s);
        t = "";
        vv = {};
        while (getline(ss, t, ','))
        {
            vv.push_back(stod(t));
        }
        v0.push_back(vv);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        vector<int> res = _01331_RankTransformOfAnArray(v[i]);
        for (auto &&j : res)
        {
            cout << j << " ";
        }
        cout << "\n";

        vector<int> res0 = _01331_RankTransformOfAnArray0(v[i]);
        for (auto &&j : res0)
        {
            cout << j << " ";
        }
        cout << "\n";

        vector<int> res1 = _01331_RankTransformOfAnArray1(v[i]);
        for (auto &&j : res1)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
}

static vector<int> _01331_RankTransformOfAnArray(vector<int> &arr)
{
    map<int, int> numToRank;
    vector<int> sortedArr(arr);
    sort(sortedArr.begin(), sortedArr.end());
    int rank = 1;

    for (int i = 0; i < sortedArr.size(); i++)
    {
        if (i > 0 && sortedArr[i] > sortedArr[i - 1])
            rank++;

        numToRank[sortedArr[i]] = rank;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = numToRank[arr[i]];
    }

    return arr;
}

static vector<int> _01331_RankTransformOfAnArray0(vector<int> &arr)
{
    unordered_map<int, int> numToRank;
    set<int> nums(arr.begin(), arr.end());
    int rank = 1;

    for (auto num : nums)
    {
        numToRank[num] = rank;
        rank++;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = numToRank[arr[i]];
    }

    return arr;
}

static vector<int> _01331_RankTransformOfAnArray1(vector<int> &arr)
{
    map<int, vector<int>> numToIndices;

    for (int i = 0; i < arr.size(); i++)
    {
        numToIndices[arr[i]].push_back(i);
    }

    int rank = 1;

    for (auto &pair : numToIndices)
    {
        for (int index : pair.second)
        {
            arr[index] = rank;
        }

        rank++;
    }

    return arr;
}

static vector<int> _01331_RankTransformOfAnArray2(vector<int> &arr)
{
    int size = arr.size();

    if (size)
    {
        vector<pair<int, int>> sarr;
        int i;

        for (int i = 0; i < size; i++)
            sarr.push_back({arr[i], i});

        sort(sarr.begin(), sarr.end());
        int r = 1;

        for (i = 0; i < size - 1; i++)
        {
            arr[sarr[i].second] = r;

            if (sarr[i].first != sarr[i + 1].first)
                r += 1;
        }

        arr[sarr[i].second] = r;
    }

    return arr;
}

#pragma region GTest
static int is_01331_RankTransformOfAnArray_RunTest()
{
    stringstream ss;
    ss << "*_01331_RankTransformOfAnArray.expected*"
       << ":"
       << "*_01331_RankTransformOfAnArray0.expected*"
       << ":"
       << "*_01331_RankTransformOfAnArray1.expected*"
       << ":"
       << "*_01331_RankTransformOfAnArray2.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_01331_RankTransformOfAnArray, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<int> expected = v0[i];

        // Actual
        vector<int> actual = _01331_RankTransformOfAnArray(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_01331_RankTransformOfAnArray0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<int> expected = v0[i];

        // Actual
        vector<int> actual = _01331_RankTransformOfAnArray0(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_01331_RankTransformOfAnArray1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<int> expected = v0[i];

        // Actual
        vector<int> actual = _01331_RankTransformOfAnArray1(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_01331_RankTransformOfAnArray2, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<int> expected = v0[i];

        // Actual
        vector<int> actual = _01331_RankTransformOfAnArray2(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
