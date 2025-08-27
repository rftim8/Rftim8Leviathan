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

// My submission
static int _02342_MaxSumOfAPairWithEqualSumOfDigits(vector<int> &nums);
// Runtime
static int _02342_MaxSumOfAPairWithEqualSumOfDigits_0(vector<int> &nums);
// Memory
static int _02342_MaxSumOfAPairWithEqualSumOfDigits_1(vector<int> &nums);

static int is_02342_MaxSumOfAPairWithEqualSumOfDigits_RunTest();

/**
 * You are given a 0-indexed array nums consisting of positive integers.
 * You can choose two indices i and j, such that i != j, and the sum of digits of the number nums[i]
 * is equal to that of nums[j].
 * Return the maximum value of nums[i] + nums[j] that you can obtain over all possible indices
 * i and j that satisfy the conditions.
 *
 * Constraints:
 *
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^9
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_02342_MaxSumOfAPairWithEqualSumOfDigits_RunTest();
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
        cout << _02342_MaxSumOfAPairWithEqualSumOfDigits(v[i]) << "\n";
        cout << _02342_MaxSumOfAPairWithEqualSumOfDigits_0(v[i]) << "\n";
        cout << _02342_MaxSumOfAPairWithEqualSumOfDigits_1(v[i]) << "\n";
    }
}

static int _02342_MaxSumOfAPairWithEqualSumOfDigits(vector<int> &nums)
{
    int res = -1;
    unordered_map<int, vector<int>> um = {};

    for (auto &&i : nums)
    {
        int sum = 0;
        int num = i;

        while (num > 0)
        {
            sum += num % 10;
            num /= 10;
        }

        um[sum].push_back(i);
    }

    for (auto &&i : um)
    {
        if (i.second.size() > 1)
        {
            int largest = 0, secondLargest = 0;
            for (int num : i.second)
            {
                if (num > largest)
                {
                    secondLargest = largest;
                    largest = num;
                }
                else if (num > secondLargest)
                {
                    secondLargest = num;
                }
            }
            res = max(res, largest + secondLargest);
        }
    }

    return res;
}

static int _02342_MaxSumOfAPairWithEqualSumOfDigits_0(vector<int> &nums)
{
    auto sumDigits = [](int numb)
    {
        int sum = 0;

        while (numb)
        {
            sum += numb % 10;
            numb /= 10;
        }

        return sum;
    };

    vector<int> sameDigit(82, -1);
    int sum, maxSum = -1;

    for (int i = 0; i < nums.size(); i++)
    {
        sum = sumDigits(nums[i]);
        if (sameDigit[sum] != -1)
        {
            maxSum = max(maxSum, sameDigit[sum] + nums[i]);
            sameDigit[sum] = max(sameDigit[sum], nums[i]);
        }
        else
            sameDigit[sum] = nums[i];
    }

    return maxSum;
}

static int _02342_MaxSumOfAPairWithEqualSumOfDigits_1(vector<int> &nums)
{
    auto digit_sum_to_max_num = vector<int>(82, 0);
    auto max_pair_sum = -1;

    for (auto num : nums)
    {
        auto digit_sum = 0;
        auto remaining_digits = num;

        while (remaining_digits)
        {
            auto [quotient, digit] = div(remaining_digits, 10);
            digit_sum += digit;
            remaining_digits = quotient;
        }

        auto &prior_max = digit_sum_to_max_num[digit_sum];

        if (prior_max)
        {
            if (auto pair_sum = num + prior_max;
                pair_sum > max_pair_sum)
                max_pair_sum = pair_sum;
        }

        if (num > prior_max)
            prior_max = num;
    }

    return max_pair_sum;
}

#pragma region GTest
static int is_02342_MaxSumOfAPairWithEqualSumOfDigits_RunTest()
{
    stringstream ss;
    ss << "*_02342_MaxSumOfAPairWithEqualSumOfDigits.expected*"
       << ":"
       << "*_02342_MaxSumOfAPairWithEqualSumOfDigits_0.expected*"
       << ":"
       << "*_02342_MaxSumOfAPairWithEqualSumOfDigits_1.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_02342_MaxSumOfAPairWithEqualSumOfDigits, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _02342_MaxSumOfAPairWithEqualSumOfDigits(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02342_MaxSumOfAPairWithEqualSumOfDigits_0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _02342_MaxSumOfAPairWithEqualSumOfDigits_0(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02342_MaxSumOfAPairWithEqualSumOfDigits_1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _02342_MaxSumOfAPairWithEqualSumOfDigits_1(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
