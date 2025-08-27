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

// LeetCode problem
static vector<int> _01652_DefuseTheBomb(vector<int> &code, int k);

static int is_01652_DefuseTheBomb_RunTest();

/**
 * You have a bomb to defuse, and your time is running out!
 * Your informer will provide you with a circular array code of length of n and a key k.
 * To decrypt the code, you must replace every number.
 * All the numbers are replaced simultaneously.
 * If k > 0, replace the ith number with the sum of the next k numbers.
 * If k < 0, replace the ith number with the sum of the previous k numbers.
 * If k == 0, replace the ith number with 0.
 * As code is circular, the next element of code[n-1] is code[0], and the previous element of
 * code[0] is code[n-1].
 * Given the circular array code and an integer key k, return the decrypted code to defuse the bomb!
 *
 * Constraints:
 *
 * n == code.length
 * 1 <= n <= 100
 * 1 <= code[i] <= 100
 * -(n - 1) <= k <= n - 1
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_01652_DefuseTheBomb_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<vector<int>> v, v1;
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

        s = "";
        getline(cin, s);
        ss.clear();
        ss.str(s);
        t = "";
        d = {};
        while (getline(ss, t, ','))
        {
            d.push_back(stoi(t));
        }
        v1.push_back(d);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        vector<int> res = _01652_DefuseTheBomb(v[i], v0[i]);
        for (auto &&j : res)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
}

static vector<int> _01652_DefuseTheBomb(vector<int> &code, int k)
{
    int n = code.size();
    vector<int> r(n);

    for (int i = 0; i < n; i++)
    {
        if (k > -1)
        {
            for (int j = 0; j < abs(k); j++)
            {
                r[i] += code[abs((i + j + 1) % n)];
            }
        }
        else
        {
            for (int j = 0; j < abs(k); j++)
            {
                if (i - j - 1 > -1)
                    r[i] += code[i - j - 1];
                else
                    r[i] += code[code.size() - (abs(i - j - 1) % n)];
            }
        }
    }

    return r;
}

#pragma region GTest
static int is_01652_DefuseTheBomb_RunTest()
{
    stringstream ss;
    ss << "*_01652_DefuseTheBomb.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_01652_DefuseTheBomb, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<int> expected = v1[i];

        // Actual
        vector<int> actual = _01652_DefuseTheBomb(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
