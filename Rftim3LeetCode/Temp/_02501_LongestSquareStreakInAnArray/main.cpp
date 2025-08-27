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
static int _02501_LongestSquareStreakInAnArray(vector<int> &nums);
// Set
static int _02501_LongestSquareStreakInAnArray0(vector<int> &nums);
// Map
static int _02501_LongestSquareStreakInAnArray1(vector<int> &nums);
// Speed
static int _02501_LongestSquareStreakInAnArray2(vector<int> &nums);

static int is_02501_LongestSquareStreakInAnArray_RunTest();

/**
 * You are given an integer array nums. A subsequence of nums is called a square streak if:
 * The length of the subsequence is at least 2, and
 * after sorting the subsequence, each element (except the first element) is the square
 * of the previous number.
 * Return the length of the longest square streak in nums, or return -1 if there is no square streak.
 *
 * A subsequence is an array that can be derived from another array by deleting some or
 * no elements without changing the order of the remaining elements.
 *
 * Constraints:
 *
 * 2 <= nums.length <= 10^5
 * 2 <= nums[i] <= 10^5
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_02501_LongestSquareStreakInAnArray_RunTest();
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
        cout << _02501_LongestSquareStreakInAnArray(v[i]) << "\n";
        cout << _02501_LongestSquareStreakInAnArray0(v[i]) << "\n";
        cout << _02501_LongestSquareStreakInAnArray1(v[i]) << "\n";
        cout << _02501_LongestSquareStreakInAnArray2(v[i]) << "\n";
    }
}

#pragma region Binary Search
static bool binarySearch(vector<int> &nums, int target)
{
    if (target < 0)
        return false;

    int left = 0;
    int right = nums.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
            return true;

        if (nums[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }

    return false;
}

static int _02501_LongestSquareStreakInAnArray(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    set<int> processedNumbers;
    int longestStreak = 0;

    for (int current : nums)
    {
        if (processedNumbers.find(current) != processedNumbers.end())
            continue;

        int streak = current;
        int streakLength = 1;

        while (true)
        {
            if ((long long)streak * (long long)streak > 1e5)
                break;

            if (binarySearch(nums, streak * streak))
            {
                streak *= streak;
                processedNumbers.insert(streak);
                streakLength++;
            }
            else
                break;
        }

        longestStreak = max(longestStreak, streakLength);
    }

    return longestStreak < 2 ? -1 : longestStreak;
}
#pragma endregion

static int _02501_LongestSquareStreakInAnArray0(vector<int> &nums)
{
    int longestStreak = 0;
    unordered_set<int> uniqueNumbers(nums.begin(), nums.end());

    for (int startNumber : nums)
    {
        int currentStreak = 0;
        long long current = startNumber;

        while (uniqueNumbers.find((int)current) != uniqueNumbers.end())
        {
            currentStreak++;

            if (current * current > 1e5)
                break;

            current *= current;
        }

        longestStreak = max(longestStreak, currentStreak);
    }

    return longestStreak < 2 ? -1 : longestStreak;
}

static int _02501_LongestSquareStreakInAnArray1(vector<int> &nums)
{
    unordered_map<int, int> streakLengths;

    sort(nums.begin(), nums.end());

    for (int number : nums)
    {
        int root = (int)sqrt(number);

        if (root * root == number &&
            streakLengths.find(root) != streakLengths.end())
            streakLengths[number] = streakLengths[root] + 1;
        else
            streakLengths[number] = 1;
    }

    int longestStreak = 0;

    for (auto &[key, streakLength] : streakLengths)
    {
        longestStreak = max(longestStreak, streakLength);
    }

    return longestStreak == 1 ? -1 : longestStreak;
}

static int _02501_LongestSquareStreakInAnArray2(vector<int> &nums)
{
    constexpr int N{100'000};
    array<bool, N + 1> ns{};

    for (const int i : nums)
    {
        ns[i] = true;
    }

    int ans{-1};

    for (size_t i{0}; i < N; ++i)
    {
        if (ns[i] == false)
            continue;

        int len{0};
        size_t index{i};

        while (index < N && ns[index])
        {
            ++len;
            index = index * index;
        }

        if (len > 1)
            ans = max(ans, len);
    }

    return ans;
}

#pragma region GTest
static int is_02501_LongestSquareStreakInAnArray_RunTest()
{
    stringstream ss;
    ss << "*_02501_LongestSquareStreakInAnArray.expected*"
       << ":"
       << "*_02501_LongestSquareStreakInAnArray0.expected*"
       << ":"
       << "*_02501_LongestSquareStreakInAnArray1.expected*"
       << ":"
       << "*_02501_LongestSquareStreakInAnArray2.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_02501_LongestSquareStreakInAnArray, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _02501_LongestSquareStreakInAnArray(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02501_LongestSquareStreakInAnArray0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _02501_LongestSquareStreakInAnArray0(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02501_LongestSquareStreakInAnArray1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _02501_LongestSquareStreakInAnArray1(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02501_LongestSquareStreakInAnArray2, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _02501_LongestSquareStreakInAnArray2(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
