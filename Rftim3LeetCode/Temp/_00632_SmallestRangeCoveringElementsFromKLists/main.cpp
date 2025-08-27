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
static vector<int> _00632_SmallestRangeCoveringElementsFromKLists(vector<vector<int>> &nums);
// Priority Queue (Heap)
static vector<int> _00632_SmallestRangeCoveringElementsFromKLists0(vector<vector<int>> &nums);
// Two Pointer
static vector<int> _00632_SmallestRangeCoveringElementsFromKLists1(vector<vector<int>> &nums);
// Speed
static vector<int> _00632_SmallestRangeCoveringElementsFromKLists2(vector<vector<int>> &nums);

static int is_00632_SmallestRangeCoveringElementsFromKLists_RunTest();

/**
 * You have k lists of sorted integers in non-decreasing order.
 * Find the smallest range that includes at least one number from each of the k lists.
 * We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.
 *
 * Constraints:
 *
 * nums.length == k
 * 1 <= k <= 3500
 * 1 <= nums[i].length <= 50
 * -10^5 <= nums[i][j] <= 10^5
 * nums[i] is sorted in non-decreasing order.
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_00632_SmallestRangeCoveringElementsFromKLists_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<vector<vector<int>>> v;
static vector<vector<int>> v0;

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
        string t = "";
        vector<int> vv = {};
        while (getline(ss, t, ','))
        {
            vv.push_back(stoi(t));
        }
        v0.push_back(vv);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        vector<int> res = _00632_SmallestRangeCoveringElementsFromKLists(v[i]);
        for (auto &&j : res)
        {
            cout << j << " ";
        }
        cout << "\n";

        vector<int> res0 = _00632_SmallestRangeCoveringElementsFromKLists0(v[i]);
        for (auto &&j : res0)
        {
            cout << j << " ";
        }
        cout << "\n";

        vector<int> res1 = _00632_SmallestRangeCoveringElementsFromKLists1(v[i]);
        for (auto &&j : res1)
        {
            cout << j << " ";
        }
        cout << "\n";

        vector<int> res2 = _00632_SmallestRangeCoveringElementsFromKLists2(v[i]);
        for (auto &&j : res2)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
}

static vector<int> _00632_SmallestRangeCoveringElementsFromKLists(vector<vector<int>> &nums)
{
    int k = nums.size();
    vector<int> indices(k, 0);
    vector<int> range = {0, INT_MAX};

    while (true)
    {
        int curMin = INT_MAX, curMax = INT_MIN, minListIndex = 0;

        for (int i = 0; i < k; i++)
        {
            int currentElement = nums[i][indices[i]];

            if (currentElement < curMin)
            {
                curMin = currentElement;
                minListIndex = i;
            }

            if (currentElement > curMax)
                curMax = currentElement;
        }

        if (curMax - curMin < range[1] - range[0])
        {
            range[0] = curMin;
            range[1] = curMax;
        }

        if (++indices[minListIndex] == nums[minListIndex].size())
            break;
    }

    return range;
}

static vector<int> _00632_SmallestRangeCoveringElementsFromKLists0(vector<vector<int>> &nums)
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    int maxVal = INT_MIN, rangeStart = 0, rangeEnd = INT_MAX;

    for (int i = 0; i < nums.size(); i++)
    {
        pq.push({nums[i][0], {i, 0}});
        maxVal = max(maxVal, nums[i][0]);
    }

    while (pq.size() == nums.size())
    {
        auto [minVal, indices] = pq.top();
        pq.pop();
        int row = indices.first, col = indices.second;

        if (maxVal - minVal < rangeEnd - rangeStart)
        {
            rangeStart = minVal;
            rangeEnd = maxVal;
        }

        if (col + 1 < nums[row].size())
        {
            int nextVal = nums[row][col + 1];
            pq.push({nextVal, {row, col + 1}});
            maxVal = max(maxVal, nextVal);
        }
    }

    return {rangeStart, rangeEnd};
}

static vector<int> _00632_SmallestRangeCoveringElementsFromKLists1(vector<vector<int>> &nums)
{
    vector<pair<int, int>> merged;

    for (int i = 0; i < nums.size(); i++)
    {
        for (int num : nums[i])
        {
            merged.push_back({num, i});
        }
    }

    sort(merged.begin(), merged.end());
    unordered_map<int, int> freq;
    int left = 0, count = 0;
    int rangeStart = 0, rangeEnd = INT_MAX;

    for (int right = 0; right < merged.size(); right++)
    {
        freq[merged[right].second]++;

        if (freq[merged[right].second] == 1)
            count++;

        while (count == nums.size())
        {
            int curRange = merged[right].first - merged[left].first;

            if (curRange < rangeEnd - rangeStart)
            {
                rangeStart = merged[left].first;
                rangeEnd = merged[right].first;
            }

            freq[merged[left].second]--;

            if (freq[merged[left].second] == 0)
                count--;

            left++;
        }
    }

    return {rangeStart, rangeEnd};
}

static vector<int> _00632_SmallestRangeCoveringElementsFromKLists2(vector<vector<int>> &nums)
{
    vector<pair<int, int>> ordered;

    for (size_t k = 0; k < nums.size(); ++k)
        for (auto n : nums[k])
            ordered.push_back({n, k});

    sort(ordered.begin(), ordered.end());
    int i = 0, k = 0;
    vector<int> ans;
    unordered_map<int, int> count;

    for (size_t j = 0; j < ordered.size(); ++j)
    {
        if (!count[ordered[j].second]++)
            ++k;

        if (k == nums.size())
        {
            while (count[ordered[i].second] > 1)
                --count[ordered[i++].second];

            if (ans.empty() || ans[1] - ans[0] > ordered[j].first - ordered[i].first)
                ans = vector<int>{ordered[i].first, ordered[j].first};
        }
    }

    return ans;
}

#pragma region GTest
static int is_00632_SmallestRangeCoveringElementsFromKLists_RunTest()
{
    stringstream ss;
    ss << "*_00632_SmallestRangeCoveringElementsFromKLists.expected*"
       << ":"
       << "*_00632_SmallestRangeCoveringElementsFromKLists0.expected*"
       << ":"
       << "*_00632_SmallestRangeCoveringElementsFromKLists1.expected*"
       << ":"
       << "*_00632_SmallestRangeCoveringElementsFromKLists2.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_00632_SmallestRangeCoveringElementsFromKLists, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<int> expected = v0[i];

        // Actual
        vector<int> actual = _00632_SmallestRangeCoveringElementsFromKLists(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_00632_SmallestRangeCoveringElementsFromKLists0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<int> expected = v0[i];

        // Actual
        vector<int> actual = _00632_SmallestRangeCoveringElementsFromKLists0(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_00632_SmallestRangeCoveringElementsFromKLists1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<int> expected = v0[i];

        // Actual
        vector<int> actual = _00632_SmallestRangeCoveringElementsFromKLists1(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_00632_SmallestRangeCoveringElementsFromKLists2, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<int> expected = v0[i];

        // Actual
        vector<int> actual = _00632_SmallestRangeCoveringElementsFromKLists2(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
