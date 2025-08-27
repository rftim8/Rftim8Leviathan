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

// Prefix Max and Suffix Min Arrays
static int _00769_MaxChunksToMakeSorted(vector<int> &arr);
// Prefix Sums
static int _00769_MaxChunksToMakeSorted0(vector<int> &arr);
// Monotonic Increasing Stack
static int _00769_MaxChunksToMakeSorted1(vector<int> &arr);
// Maximum Element
static int _00769_MaxChunksToMakeSorted2(vector<int> &arr);

static int is_00769_MaxChunksToMakeSorted_RunTest();

/**
 * You are given an integer array arr of length n that represents a permutation of the integers in the range [0, n - 1].
 * We split arr into some number of chunks (i.e., partitions), and individually sort each chunk.
 * After concatenating them, the result should equal the sorted array.
 * Return the largest number of chunks we can make to sort the array.
 *
 * Constraints:
 *
 * n == arr.length
 * 1 <= n <= 10
 * 0 <= arr[i] < n
 * All the elements of arr are unique.
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_00769_MaxChunksToMakeSorted_RunTest();
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
        cout << _00769_MaxChunksToMakeSorted(v[i]) << "\n";
        cout << _00769_MaxChunksToMakeSorted0(v[i]) << "\n";
        cout << _00769_MaxChunksToMakeSorted1(v[i]) << "\n";
        cout << _00769_MaxChunksToMakeSorted2(v[i]) << "\n";
    }
}

static int _00769_MaxChunksToMakeSorted(vector<int> &arr)
{
    int n = arr.size();
    vector<int> prefixMax = arr;
    vector<int> suffixMin = arr;

    for (int i = 1; i < n; i++)
    {
        prefixMax[i] = max(prefixMax[i - 1], prefixMax[i]);
    }

    for (int i = n - 2; i >= 0; i--)
    {
        suffixMin[i] = min(suffixMin[i + 1], suffixMin[i]);
    }

    int chunks = 0;

    for (int i = 0; i < n; i++)
    {
        if (i == 0 || suffixMin[i] > prefixMax[i - 1])
            chunks++;
    }

    return chunks;
}

static int _00769_MaxChunksToMakeSorted0(vector<int> &arr)
{
    int n = arr.size();
    int chunks = 0, prefixSum = 0, sortedPrefixSum = 0;

    for (int i = 0; i < n; i++)
    {
        prefixSum += arr[i];
        sortedPrefixSum += i;

        if (prefixSum == sortedPrefixSum)
            chunks++;
    }

    return chunks;
}

static int _00769_MaxChunksToMakeSorted1(vector<int> &arr)
{
    int n = arr.size();
    stack<int> monotonicStack;

    for (int i = 0; i < n; i++)
    {
        if (monotonicStack.empty() || arr[i] > monotonicStack.top())
            monotonicStack.push(arr[i]);
        else
        {
            int maxElement = monotonicStack.top();

            while (!monotonicStack.empty() &&
                   arr[i] < monotonicStack.top())
            {
                monotonicStack.pop();
            }
            monotonicStack.push(maxElement);
        }
    }

    return monotonicStack.size();
}

static int _00769_MaxChunksToMakeSorted2(vector<int> &arr)
{
    int n = arr.size();
    int chunks = 0, maxElement = 0;

    for (int i = 0; i < n; i++)
    {
        maxElement = max(maxElement, arr[i]);

        if (maxElement == i)
            chunks++;
    }

    return chunks;
}

#pragma region GTest
static int is_00769_MaxChunksToMakeSorted_RunTest()
{
    stringstream ss;
    ss << "*_00769_MaxChunksToMakeSorted.expected*"
       << ":"
       << "*_00769_MaxChunksToMakeSorted0.expected*"
       << ":"
       << "*_00769_MaxChunksToMakeSorted1.expected*"
       << ":"
       << "*_00769_MaxChunksToMakeSorted2.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_00769_MaxChunksToMakeSorted, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _00769_MaxChunksToMakeSorted(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_00769_MaxChunksToMakeSorted0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _00769_MaxChunksToMakeSorted0(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_00769_MaxChunksToMakeSorted1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _00769_MaxChunksToMakeSorted1(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_00769_MaxChunksToMakeSorted2, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _00769_MaxChunksToMakeSorted2(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
