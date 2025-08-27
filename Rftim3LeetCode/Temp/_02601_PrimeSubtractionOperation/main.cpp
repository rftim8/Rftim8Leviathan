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
static bool _02601_PrimeSubtractionOperation(vector<int> &nums);
// Storing the Primes
static bool _02601_PrimeSubtractionOperation0(vector<int> &nums);
// Sieve of Eratosthenes + Two Pointers
static bool _02601_PrimeSubtractionOperation1(vector<int> &nums);

static int is_02601_PrimeSubtractionOperation_RunTest();

/**
 * You are given a 0-indexed integer array nums of length n.
 * You can perform the following operation as many times as you want:
 * Pick an index i that you haven’t picked before, and pick a prime p strictly less than nums[i],
 * then subtract p from nums[i].
 * Return true if you can make nums a strictly increasing array using the above operation and
 * false otherwise.
 * A strictly increasing array is an array whose each element is strictly greater than its
 * preceding element.
 *
 * Constraints:
 *
 * 1 <= nums.length <= 1000
 * 1 <= nums[i] <= 1000
 * nums.length == n
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_02601_PrimeSubtractionOperation_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<vector<int>> v;
static vector<bool> v0;

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

        bool s0;
        cin >> s0;
        cin.get();
        v0.push_back(s0);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        cout << _02601_PrimeSubtractionOperation(v[i]) << "\n";
        cout << _02601_PrimeSubtractionOperation0(v[i]) << "\n";
        cout << _02601_PrimeSubtractionOperation1(v[i]) << "\n";
    }
}

#pragma region Brute Force
static bool checkPrime(int x)
{
    for (int i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
            return 0;
    }

    return 1;
}

static bool _02601_PrimeSubtractionOperation(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        int bound;

        if (i == 0)
            bound = nums[0];
        else
            bound = nums[i] - nums[i - 1];

        if (bound <= 0)
            return 0;

        int largestPrime = 0;

        for (int j = bound - 1; j >= 2; j--)
        {
            if (checkPrime(j))
            {
                largestPrime = j;
                break;
            }
        }

        nums[i] = nums[i] - largestPrime;
    }

    return 1;
}
#pragma endregion

static bool _02601_PrimeSubtractionOperation0(vector<int> &nums)
{
    int maxElement = *max_element(nums.begin(), nums.end());
    vector<int> previousPrime(maxElement + 1, 0);

    for (int i = 2; i <= maxElement; i++)
    {
        if (checkPrime(i))
            previousPrime[i] = i;
        else
            previousPrime[i] = previousPrime[i - 1];
    }

    for (int i = 0; i < nums.size(); i++)
    {
        int bound;

        if (i == 0)
            bound = nums[0];
        else
            bound = nums[i] - nums[i - 1];

        if (bound <= 0)
            return 0;

        int largestPrime = previousPrime[bound - 1];
        nums[i] = nums[i] - largestPrime;
    }

    return 1;
}

static bool _02601_PrimeSubtractionOperation1(vector<int> &nums)
{
    int maxElement = *max_element(nums.begin(), nums.end());
    vector<int> sieve(maxElement + 1, 1);
    sieve[1] = 0;

    for (int i = 2; i <= sqrt(maxElement + 1); i++)
    {
        if (sieve[i] == 1)
        {
            for (int j = i * i; j <= maxElement; j += i)
            {
                sieve[j] = 0;
            }
        }
    }

    int currValue = 1;
    int i = 0;

    while (i < nums.size())
    {
        int difference = nums[i] - currValue;

        if (difference < 0)
            return 0;

        if (sieve[difference] == 1 or difference == 0)
        {
            i++;
            currValue++;
        }
        else
            currValue++;
    }

    return 1;
}

#pragma region GTest
static int is_02601_PrimeSubtractionOperation_RunTest()
{
    stringstream ss;
    ss << "*_02601_PrimeSubtractionOperation.expected*"
       << ":"
       << "*_02601_PrimeSubtractionOperation0.expected*"
       << ":"
       << "*_02601_PrimeSubtractionOperation1.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_02601_PrimeSubtractionOperation, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        bool expected = v0[i];

        // Actual
        bool actual = _02601_PrimeSubtractionOperation(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02601_PrimeSubtractionOperation0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        bool expected = v0[i];

        // Actual
        bool actual = _02601_PrimeSubtractionOperation0(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02601_PrimeSubtractionOperation1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        bool expected = v0[i];

        // Actual
        bool actual = _02601_PrimeSubtractionOperation1(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
