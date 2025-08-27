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

// Binary Search
static int _02064_MinimizedMaximumOfProductsDistributedToAnyStore(int n, vector<int> &quantities);
// Greedy Using Heap
static int _02064_MinimizedMaximumOfProductsDistributedToAnyStore0(int n, vector<int> &quantities);
// Speed
static int _02064_MinimizedMaximumOfProductsDistributedToAnyStore1(int n, vector<int> &quantities);

static int is_02064_MinimizedMaximumOfProductsDistributedToAnyStore_RunTest();

/**
 * You are given an integer n indicating there are n specialty retail stores.
 * There are m product types of varying amounts, which are given as a 0-indexed integer array
 * quantities, where quantities[i] represents the number of products of the ith product type.
 * You need to distribute all products to the retail stores following these rules:
 * A store can only be given at most one product type but can be given any amount of it.
 * After distribution, each store will have been given some number of products (possibly 0).
 * Let x represent the maximum number of products given to any store.
 * You want x to be as small as possible, i.e., you want to minimize the maximum number of
 * products that are given to any store.
 * Return the minimum possible x.
 *
 * Constraints:
 *
 * m == quantities.length
 * 1 <= m <= n <= 10^5
 * 1 <= quantities[i] <= 10^5
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_02064_MinimizedMaximumOfProductsDistributedToAnyStore_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<int> v, v1;
static vector<vector<int>> v0;

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
        stringstream ss(s0);
        string t;
        vector<int> d = {};
        while (getline(ss, t, ','))
        {
            d.push_back(stoi(t));
        }
        v0.push_back(d);

        cin >> s;
        v1.push_back(s);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        cout << _02064_MinimizedMaximumOfProductsDistributedToAnyStore(v[i], v0[i]) << "\n";
        cout << _02064_MinimizedMaximumOfProductsDistributedToAnyStore0(v[i], v0[i]) << "\n";
        cout << _02064_MinimizedMaximumOfProductsDistributedToAnyStore1(v[i], v0[i]) << "\n";
    }
}

#pragma region BS
static bool canDistribute(int x, vector<int> &quantities, int n)
{
    int j = 0;
    int remaining = quantities[j];

    for (int i = 0; i < n; i++)
    {
        if (remaining <= x)
        {
            j++;

            if (j == quantities.size())
                return true;
            else
                remaining = quantities[j];
        }
        else
            remaining -= x;
    }

    return false;
}

static int _02064_MinimizedMaximumOfProductsDistributedToAnyStore(int n, vector<int> &quantities)
{
    int left = 0;
    int right = *max_element(quantities.begin(), quantities.end());

    while (left < right)
    {
        int middle = (left + right) / 2;

        if (canDistribute(middle, quantities, n))
            right = middle;
        else
            left = middle + 1;
    }

    return left;
}
#pragma endregion

static int _02064_MinimizedMaximumOfProductsDistributedToAnyStore0(int n, vector<int> &quantities)
{
    int m = quantities.size();

    auto compareTypeStorePairs = [](pair<int, int> &a, pair<int, int> &b)
    {
        return (long long)a.first * b.second <
               (long long)a.second * b.first;
    };

    vector<pair<int, int>> typeStorePairsArray;

    for (int i = 0; i < m; i++)
    {
        typeStorePairsArray.push_back({quantities[i], 1});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compareTypeStorePairs)>
        typeStorePairs(typeStorePairsArray.begin(), typeStorePairsArray.begin() + m, compareTypeStorePairs);

    for (int i = 0; i < n - m; i++)
    {
        pair<int, int> pairWithMaxRatio = typeStorePairs.top();
        int totalQuantityOfType = pairWithMaxRatio.first;
        int storesAssignedToType = pairWithMaxRatio.second;
        typeStorePairs.pop();
        typeStorePairs.push({totalQuantityOfType, storesAssignedToType + 1});
    }

    pair<int, int> pairWithMaxRatio = typeStorePairs.top();
    int totalQuantityOfType = pairWithMaxRatio.first;
    int storesAssignedToType = pairWithMaxRatio.second;

    return ceil((double)totalQuantityOfType / storesAssignedToType);
}

#pragma region Speed
static bool isPossible(int target, int n, vector<int> &q)
{
    int sz = q.size();
    int cnt = 0;

    for (int i = 0; i < sz; i++)
    {
        int div = q[i] / target;
        int rem = q[i] % target;
        cnt += div;

        if (rem > 0)
            cnt++;
    }

    return cnt <= n;
}

static int _02064_MinimizedMaximumOfProductsDistributedToAnyStore1(int n, vector<int> &quantities)
{
    int sz = quantities.size();
    int mx = 0;

    for (int i = 0; i < sz; i++)
    {
        mx = max(mx, quantities[i]);
    }

    int lo = 1, hi = mx;
    int ans = 0;

    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;

        if (isPossible(mid, n, quantities))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }

    return ans;
}

#pragma region GTest
static int is_02064_MinimizedMaximumOfProductsDistributedToAnyStore_RunTest()
{
    stringstream ss;
    ss << "*_02064_MinimizedMaximumOfProductsDistributedToAnyStore.expected*"
       << ":"
       << "*_02064_MinimizedMaximumOfProductsDistributedToAnyStore0.expected*"
       << ":"
       << "*_02064_MinimizedMaximumOfProductsDistributedToAnyStore1.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_02064_MinimizedMaximumOfProductsDistributedToAnyStore, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v1[i];

        // Actual
        int actual = _02064_MinimizedMaximumOfProductsDistributedToAnyStore(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02064_MinimizedMaximumOfProductsDistributedToAnyStore0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v1[i];

        // Actual
        int actual = _02064_MinimizedMaximumOfProductsDistributedToAnyStore0(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02064_MinimizedMaximumOfProductsDistributedToAnyStore1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v1[i];

        // Actual
        int actual = _02064_MinimizedMaximumOfProductsDistributedToAnyStore1(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
