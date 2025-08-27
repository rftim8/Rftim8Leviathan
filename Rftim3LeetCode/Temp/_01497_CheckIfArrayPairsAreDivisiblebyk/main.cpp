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

// Hashing / Counting
static bool _01497_CheckIfArrayPairsAreDivisiblebyk(vector<int> &arr, int k);
// Sorting + Two Pointers
static bool _01497_CheckIfArrayPairsAreDivisiblebyk0(vector<int> &arr, int k);
// Speed
static bool _01497_CheckIfArrayPairsAreDivisiblebyk1(vector<int> &arr, int k);

static int is_01497_CheckIfArrayPairsAreDivisiblebyk_RunTest();

/**
 * Given an array of integers arr of even length n and an integer k.
 * We want to divide the array into exactly n / 2 pairs such that the sum of each pair is divisible by k.
 * Return true If you can find a way to do that or false otherwise.
 *
 * Constraints:
 *
 * arr.length == n
 * 1 <= n <= 10^5
 * n is even.
 * -10^9 <= arr[i] <= 10^9
 * 1 <= k <= 10^5
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_01497_CheckIfArrayPairsAreDivisiblebyk_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<vector<int>> v;
static vector<int> v0;
static vector<bool> v1;

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

        int s0;
        cin >> s0;
        v0.push_back(s0);

        bool s1;
        cin >> s1;
        cin.get();
        v1.push_back(s1);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        cout << _01497_CheckIfArrayPairsAreDivisiblebyk(v[i], v0[i]) << "\n";
        cout << _01497_CheckIfArrayPairsAreDivisiblebyk0(v[i], v0[i]) << "\n";
        cout << _01497_CheckIfArrayPairsAreDivisiblebyk1(v[i], v0[i]) << "\n";
    }
}

static bool _01497_CheckIfArrayPairsAreDivisiblebyk(vector<int> &arr, int k)
{
    unordered_map<int, int> remainderCount;

    for (auto i : arr)
        remainderCount[(i % k + k) % k]++;

    for (auto i : arr)
    {
        int rem = (i % k + k) % k;

        if (rem == 0)
        {
            if (remainderCount[rem] % 2 == 1)
                return false;
        }

        else if (remainderCount[rem] != remainderCount[k - rem])
            return false;
    }

    return true;
}

struct Comparator
{
    int k;
    Comparator(int k) { this->k = k; }
    bool operator()(int i, int j)
    {
        return (k + i % k) % k < (k + j % k) % k;
    }
};

static bool _01497_CheckIfArrayPairsAreDivisiblebyk0(vector<int> &arr, int k)
{
    sort(arr.begin(), arr.end(), Comparator(k));
    int start = 0, end = arr.size() - 1;

    while (start < end)
    {
        if (arr[start] % k != 0)
            break;

        if (arr[start + 1] % k != 0)
            return false;

        start = start + 2;
    }

    while (start < end)
    {
        if ((arr[start] + arr[end]) % k != 0)
            return false;

        start++;
        end--;
    }

    return true;
}

static bool _01497_CheckIfArrayPairsAreDivisiblebyk1(vector<int> &arr, int k)
{
    vector<int> freq(k, 0);

    for (int num : arr)
    {
        freq[(num % k + k) % k]++;
    }

    if (freq[0] % 2 != 0)
        return false;

    for (int i = 1; i <= k / 2; i++)
    {
        if (freq[i] != freq[k - i])
            return false;
    }

    return true;
}

#pragma region GTest
static int is_01497_CheckIfArrayPairsAreDivisiblebyk_RunTest()
{
    stringstream ss;
    ss << "*_01497_CheckIfArrayPairsAreDivisiblebyk.expected*"
       << ":"
       << "*_01497_CheckIfArrayPairsAreDivisiblebyk0.expected*"
       << ":"
       << "*_01497_CheckIfArrayPairsAreDivisiblebyk1.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_01497_CheckIfArrayPairsAreDivisiblebyk, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        bool expected = v1[i];

        // Actual
        bool actual = _01497_CheckIfArrayPairsAreDivisiblebyk(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_01497_CheckIfArrayPairsAreDivisiblebyk0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        bool expected = v1[i];

        // Actual
        bool actual = _01497_CheckIfArrayPairsAreDivisiblebyk0(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_01497_CheckIfArrayPairsAreDivisiblebyk1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        bool expected = v1[i];

        // Actual
        bool actual = _01497_CheckIfArrayPairsAreDivisiblebyk1(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
