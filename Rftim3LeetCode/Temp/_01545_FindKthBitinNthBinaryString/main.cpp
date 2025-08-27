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
static char _01545_FindKthBitinNthBinaryString(int n, int k);
// Recursion
static char _01545_FindKthBitinNthBinaryString0(int n, int k);
// Iterative Divide and Conquer
static char _01545_FindKthBitinNthBinaryString1(int n, int k);
// Bit Manipulation
static char _01545_FindKthBitinNthBinaryString2(int n, int k);
// Speed
static char _01545_FindKthBitinNthBinaryString3(int n, int k);

static int is_01545_FindKthBitinNthBinaryString_RunTest();

/**
 * Given two positive integers n and k, the binary string Sn is formed as follows:
 * S1 = "0"
 * Si = Si - 1 + "1" + reverse(invert(Si - 1)) for i > 1
 * Where + denotes the concatenation operation, reverse(x) returns the reversed string x,
 * and invert(x) inverts all the bits in x (0 changes to 1 and 1 changes to 0).
 * For example, the first four strings in the above sequence are:
 * S1 = "0"
 * S2 = "011"
 * S3 = "0111001"
 * S4 = "011100110110001"
 * Return the kth bit in Sn. It is guaranteed that k is valid for the given n.
 *
 * Constraints:
 *
 * 1 <= n <= 20
 * 1 <= k <= 2^n - 1
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_01545_FindKthBitinNthBinaryString_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<int> v, v0;
static vector<char> v1;

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
        v0.push_back(s);

        char s0;
        cin >> s0;
        cin.get();
        v1.push_back(s0);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        cout << _01545_FindKthBitinNthBinaryString(v[i], v0[i]) << "\n";
        cout << _01545_FindKthBitinNthBinaryString0(v[i], v0[i]) << "\n";
        cout << _01545_FindKthBitinNthBinaryString1(v[i], v0[i]) << "\n";
        cout << _01545_FindKthBitinNthBinaryString2(v[i], v0[i]) << "\n";
    }
}

static char _01545_FindKthBitinNthBinaryString(int n, int k)
{
    string sequence = "0";

    for (int i = 1; i < n && k > sequence.length(); ++i)
    {
        sequence += '1';
        string temp = sequence;

        for (int j = temp.length() - 2; j >= 0; --j)
        {
            char invertedBit = (temp[j] == '1') ? '0' : '1';
            sequence += invertedBit;
        }
    }

    return sequence[k - 1];
}

static char _01545_FindKthBitinNthBinaryString0(int n, int k)
{
    if (n == 1)
        return '0';

    int len = 1 << n;

    if (k < len / 2)
        return _01545_FindKthBitinNthBinaryString0(n - 1, k);
    else if (k == len / 2)
        return '1';
    else
    {
        char correspondingBit = _01545_FindKthBitinNthBinaryString0(n - 1, len - k);

        return (correspondingBit == '0') ? '1' : '0';
    }
}

static char _01545_FindKthBitinNthBinaryString1(int n, int k)
{
    int invertCount = 0;
    int len = (1 << n) - 1;

    while (k > 1)
    {
        if (k == len / 2 + 1)
            return invertCount % 2 == 0 ? '1' : '0';

        if (k > len / 2)
        {
            k = len + 1 - k;
            invertCount++;
        }

        len /= 2;
    }

    return invertCount % 2 == 0 ? '0' : '1';
}

static char _01545_FindKthBitinNthBinaryString2(int n, int k)
{
    int positionInSection = k & -k;
    bool isInInvertedPart = ((k / positionInSection) >> 1 & 1) == 1;
    bool originalBitIsOne = (k & 1) == 0;

    if (isInInvertedPart)
        return originalBitIsOne ? '0' : '1';
    else
        return originalBitIsOne ? '1' : '0';
}

static char _01545_FindKthBitinNthBinaryString3(int n, int k)
{
    if (n == 1)
        return '0';

    int len = (1 << n) - 1;
    int mid = len / 2 + 1;

    if (k == mid)
        return '1';

    if (k < mid)
        return _01545_FindKthBitinNthBinaryString3(n - 1, k);

    char bit = _01545_FindKthBitinNthBinaryString3(n - 1, len - k + 1);

    return bit == '0' ? '1' : '0';
}

#pragma region GTest
static int is_01545_FindKthBitinNthBinaryString_RunTest()
{
    stringstream ss;
    ss << "*_01545_FindKthBitinNthBinaryString.expected*"
       << ":"
       << "*_01545_FindKthBitinNthBinaryString0.expected*"
       << ":"
       << "*_01545_FindKthBitinNthBinaryString1.expected*"
       << ":"
       << "*_01545_FindKthBitinNthBinaryString2.expected*"
       << ":"
       << "*_01545_FindKthBitinNthBinaryString3.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_01545_FindKthBitinNthBinaryString, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        char expected = v1[i];

        // Actual
        char actual = _01545_FindKthBitinNthBinaryString(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_01545_FindKthBitinNthBinaryString0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        char expected = v1[i];

        // Actual
        char actual = _01545_FindKthBitinNthBinaryString0(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_01545_FindKthBitinNthBinaryString1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        char expected = v1[i];

        // Actual
        char actual = _01545_FindKthBitinNthBinaryString1(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_01545_FindKthBitinNthBinaryString2, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        char expected = v1[i];

        // Actual
        char actual = _01545_FindKthBitinNthBinaryString2(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_01545_FindKthBitinNthBinaryString3, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        char expected = v1[i];

        // Actual
        char actual = _01545_FindKthBitinNthBinaryString3(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
