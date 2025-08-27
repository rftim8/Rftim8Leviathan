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
static int _00670_MaximumSwap(int num);
// Greedy Two-Pass
static int _00670_MaximumSwap0(int num);
// Suboptimal Greedy
static int _00670_MaximumSwap1(int num);
// Space Optimized Greedy
static int _00670_MaximumSwap2(int num);
// Speed
static int _00670_MaximumSwap3(int num);

static int is_00670_MaximumSwap_RunTest();

/**
 * You are given an integer num. You can swap two digits at most once to get the maximum valued number.
 * Return the maximum valued number you can get.
 *
 * Constraints:
 *
 * 0 <= num <= 10^8
 */
int main()
{
    offline();
    dataCollector();

    solve();
    return 0;

    ::testing::InitGoogleTest();
    is_00670_MaximumSwap_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<int> v, v0;

static void dataCollector()
{
    cin >> n;
    cin >> m;
    cin.get();

    for (int i = 0; i < n * m; i += m)
    {
        int s;
        cin >> s;
        v.push_back(s);

        cin >> s;
        cin.get();
        v0.push_back(s);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        cout << _00670_MaximumSwap(v[i]) << "\n";
        cout << _00670_MaximumSwap0(v[i]) << "\n";
        cout << _00670_MaximumSwap1(v[i]) << "\n";
        cout << _00670_MaximumSwap2(v[i]) << "\n";
        cout << _00670_MaximumSwap3(v[i]) << "\n";
    }
}

static int _00670_MaximumSwap(int num)
{
    string numStr = to_string(num);
    int n = numStr.size();
    int maxNum = num;

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            swap(numStr[i], numStr[j]);
            maxNum = max(maxNum, stoi(numStr));
            swap(numStr[i], numStr[j]);
        }
    }

    return maxNum;
}

static int _00670_MaximumSwap0(int num)
{
    string numStr = to_string(num);
    int n = numStr.size();
    vector<int> maxRightIndex(n);

    maxRightIndex[n - 1] = n - 1;

    for (int i = n - 2; i >= 0; --i)
    {
        maxRightIndex[i] = (numStr[i] > numStr[maxRightIndex[i + 1]]) ? i : maxRightIndex[i + 1];
    }

    for (int i = 0; i < n; ++i)
    {
        if (numStr[i] < numStr[maxRightIndex[i]])
        {
            swap(numStr[i], numStr[maxRightIndex[i]]);
            return stoi(numStr);
        }
    }

    return num;
}

static int _00670_MaximumSwap1(int num)
{
    string numStr = to_string(num);
    int n = numStr.size();
    vector<int> lastSeen(10, -1);

    for (int i = 0; i < n; ++i)
    {
        lastSeen[numStr[i] - '0'] = i;
    }

    for (int i = 0; i < n; ++i)
    {
        for (int d = 9; d > numStr[i] - '0'; --d)
        {
            if (lastSeen[d] > i)
            {
                swap(numStr[i], numStr[lastSeen[d]]);
                return stoi(numStr);
            }
        }
    }

    return num;
}

static int _00670_MaximumSwap2(int num)
{
    string numStr = to_string(num);
    int n = numStr.size();
    int maxDigitIndex = -1, swapIdx1 = -1, swapIdx2 = -1;

    for (int i = n - 1; i >= 0; --i)
    {
        if (maxDigitIndex == -1 || numStr[i] > numStr[maxDigitIndex])
            maxDigitIndex = i;
        else if (numStr[i] < numStr[maxDigitIndex])
        {
            swapIdx1 = i;
            swapIdx2 = maxDigitIndex;
        }
    }

    if (swapIdx1 != -1 && swapIdx2 != -1)
        swap(numStr[swapIdx1], numStr[swapIdx2]);

    return stoi(numStr);
}

static int _00670_MaximumSwap3(int num)
{
    int i, n, firstGreater = -1, tempNum = num, ans = 0, max;
    vector<int> digits;

    while (num > 0)
    {
        digits.push_back(num % 10);
        num /= 10;
    }

    n = digits.size();

    for (i = n - 2; i >= 0; i--)
    {
        if (digits[i] > digits[i + 1])
        {
            firstGreater = i;
            break;
        }
    }

    if (firstGreater == -1)
        return tempNum;

    max = firstGreater;

    for (i = firstGreater + 1; i >= 0; i--)
    {
        if (digits[i] >= digits[max])
            max = i;
    }

    for (i = n - 1; i > max; i--)
    {
        if (digits[i] < digits[max])
        {
            tempNum = digits[max];
            digits[max] = digits[i];
            digits[i] = tempNum;
            break;
        }
    }

    for (i = n - 1; i >= 0; i--)
    {
        ans = ans * 10 + (digits[i] % 10);
    }

    return ans;
}

#pragma region GTest
static int is_00670_MaximumSwap_RunTest()
{
    stringstream ss;
    ss << "*_00670_MaximumSwap.expected*"
       << ":"
       << "*_00670_MaximumSwap0.expected*"
       << ":"
       << "*_00670_MaximumSwap1.expected*"
       << ":"
       << "*_00670_MaximumSwap2.expected*"
       << ":"
       << "*_00670_MaximumSwap3.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_00670_MaximumSwap, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _00670_MaximumSwap(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_00670_MaximumSwap0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _00670_MaximumSwap0(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_00670_MaximumSwap1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _00670_MaximumSwap1(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_00670_MaximumSwap2, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _00670_MaximumSwap2(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_00670_MaximumSwap3, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _00670_MaximumSwap3(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
