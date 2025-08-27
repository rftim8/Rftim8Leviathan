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

// DFS
static vector<int> _00386_LexicographicalNumbers(int n);
// Iterative
static vector<int> _00386_LexicographicalNumbers0(int n);

static int is_00386_LexicographicalNumbers_RunTest();

/**
 * Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.
 * You must write an algorithm that runs in O(n) time and uses O(1) extra space.
 *
 * Constraints:
 *
 * 1 <= n <= 5 * 10^4
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_00386_LexicographicalNumbers_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<int> v;
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
        vector<int> res = _00386_LexicographicalNumbers(v[i]);
        for (auto &&j : res)
        {
            cout << j << " ";
        }
        cout << "\n";

        vector<int> res0 = _00386_LexicographicalNumbers0(v[i]);
        for (auto &&j : res0)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
}

static void generateLexicalNumbers(int currentNumber, int limit, vector<int> &result)
{
    if (currentNumber > limit)
        return;

    result.push_back(currentNumber);

    for (int nextDigit = 0; nextDigit <= 9; ++nextDigit)
    {
        int nextNumber = currentNumber * 10 + nextDigit;

        if (nextNumber <= limit)
            generateLexicalNumbers(nextNumber, limit, result);
        else
            break;
    }
}

static vector<int> _00386_LexicographicalNumbers(int n)
{
    vector<int> lexicographicalNumbers;

    for (int start = 1; start <= 9; ++start)
    {
        generateLexicalNumbers(start, n, lexicographicalNumbers);
    }

    return lexicographicalNumbers;
}

static vector<int> _00386_LexicographicalNumbers0(int n)
{
    vector<int> res;
    int currentNumber = 1;

    for (int i = 0; i < n; ++i)
    {
        res.push_back(currentNumber);

        if (currentNumber * 10 <= n)
            currentNumber *= 10;
        else
        {
            while (currentNumber % 10 == 9 || currentNumber >= n)
            {
                currentNumber /= 10;
            }

            currentNumber += 1;
        }
    }

    return res;
}

#pragma region GTest
static int is_00386_LexicographicalNumbers_RunTest()
{
    stringstream ss;
    ss << "*_00386_LexicographicalNumbers.expected*"
       << ":"
       << "*_00386_LexicographicalNumbers0.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_00386_LexicographicalNumbers, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<int> expected = v0[i];

        // Actual
        vector<int> actual = _00386_LexicographicalNumbers(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_00386_LexicographicalNumbers0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<int> expected = v0[i];

        // Actual
        vector<int> actual = _00386_LexicographicalNumbers0(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
