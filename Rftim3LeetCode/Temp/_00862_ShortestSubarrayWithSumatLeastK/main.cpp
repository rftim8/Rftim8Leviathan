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

// Priority Queue
static int _00862_ShortestSubarrayWithSumatLeastK(vector<int> &nums, int k);
// Monotonic Stack + BS
static int _00862_ShortestSubarrayWithSumatLeastK0(vector<int> &nums, int k);
// Deque
static int _00862_ShortestSubarrayWithSumatLeastK1(vector<int> &nums, int k);

static int is_00862_ShortestSubarrayWithSumatLeastK_RunTest();

/**
 * Given an integer array nums and an integer k, return the length of the shortest non-empty
 * subarray of nums with a sum of at least k.
 * If there is no such subarray, return -1.
 * A subarray is a contiguous part of an array.
 *
 * Constraints:
 *
 * 1 <= nums.length <= 10^5
 * -105 <= nums[i] <= 10^5
 * 1 <= k <= 10^9
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_00862_ShortestSubarrayWithSumatLeastK_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<vector<int>> v;
static vector<int> v0, v1;

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
        v0.push_back(s0);

        cin >> s0;
        cin.get();
        v1.push_back(s0);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        cout << _00862_ShortestSubarrayWithSumatLeastK(v[i], v0[i]) << "\n";
        cout << _00862_ShortestSubarrayWithSumatLeastK0(v[i], v0[i]) << "\n";
        cout << _00862_ShortestSubarrayWithSumatLeastK1(v[i], v0[i]) << "\n";
    }
}

static int _00862_ShortestSubarrayWithSumatLeastK(vector<int> &nums, int k)
{
    int n = nums.size();
    int shortestSubarrayLength = INT_MAX;
    long long cumulativeSum = 0;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> prefixSumHeap;

    for (int i = 0; i < n; i++)
    {
        cumulativeSum += nums[i];

        if (cumulativeSum >= k)
            shortestSubarrayLength = min(shortestSubarrayLength, i + 1);

        while (!prefixSumHeap.empty() &&
               cumulativeSum - prefixSumHeap.top().first >= k)
        {
            shortestSubarrayLength = min(shortestSubarrayLength, i - prefixSumHeap.top().second);
            prefixSumHeap.pop();
        }

        prefixSumHeap.emplace(cumulativeSum, i);
    }

    return shortestSubarrayLength == INT_MAX ? -1 : shortestSubarrayLength;
}

#pragma region Monotonic Stack + BS
static int findCandidateIndex(const vector<pair<long long, int>> &nums, long long target)
{
    int left = 0, right = nums.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid].first <= target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return right;
}

static int _00862_ShortestSubarrayWithSumatLeastK0(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<pair<long long, int>> cumulativeSumStack;
    cumulativeSumStack.emplace_back(0LL, -1);
    long long runningCumulativeSum = 0;
    int shortestSubarrayLength = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        runningCumulativeSum += nums[i];

        while (!cumulativeSumStack.empty() &&
               runningCumulativeSum <= cumulativeSumStack.back().first)
        {
            cumulativeSumStack.pop_back();
        }

        cumulativeSumStack.emplace_back(runningCumulativeSum, i);
        int candidateIndex = findCandidateIndex(cumulativeSumStack, runningCumulativeSum - k);

        if (candidateIndex != -1)
            shortestSubarrayLength = min(shortestSubarrayLength, i - cumulativeSumStack[candidateIndex].second);
    }

    return shortestSubarrayLength == INT_MAX ? -1 : shortestSubarrayLength;
}
#pragma endregion

static int _00862_ShortestSubarrayWithSumatLeastK1(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<long long> prefixSums(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        prefixSums[i] = prefixSums[i - 1] + nums[i - 1];
    }

    deque<int> candidateIndices;
    int shortestSubarrayLength = INT_MAX;

    for (int i = 0; i <= n; i++)
    {
        while (!candidateIndices.empty() &&
               prefixSums[i] - prefixSums[candidateIndices.front()] >=
                   k)
        {
            shortestSubarrayLength = min(shortestSubarrayLength, i - candidateIndices.front());
            candidateIndices.pop_front();
        }

        while (!candidateIndices.empty() &&
               prefixSums[i] <= prefixSums[candidateIndices.back()])
        {
            candidateIndices.pop_back();
        }

        candidateIndices.push_back(i);
    }

    return shortestSubarrayLength == INT_MAX ? -1 : shortestSubarrayLength;
}

#pragma region GTest
static int is_00862_ShortestSubarrayWithSumatLeastK_RunTest()
{
    stringstream ss;
    ss << "*_00862_ShortestSubarrayWithSumatLeastK.expected*"
       << ":"
       << "*_00862_ShortestSubarrayWithSumatLeastK0.expected*"
       << ":"
       << "*_00862_ShortestSubarrayWithSumatLeastK1.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_00862_ShortestSubarrayWithSumatLeastK, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v1[i];

        // Actual
        int actual = _00862_ShortestSubarrayWithSumatLeastK(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_00862_ShortestSubarrayWithSumatLeastK0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v1[i];

        // Actual
        int actual = _00862_ShortestSubarrayWithSumatLeastK0(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_00862_ShortestSubarrayWithSumatLeastK1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v1[i];

        // Actual
        int actual = _00862_ShortestSubarrayWithSumatLeastK1(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
