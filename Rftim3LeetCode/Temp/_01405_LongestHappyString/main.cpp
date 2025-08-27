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
static string _01405_LongestHappyString(int a, int b, int c);
// Greedy
static string _01405_LongestHappyString0(int a, int b, int c);
// Speed
static string _01405_LongestHappyString1(int a, int b, int c);

static int is_01405_LongestHappyString_RunTest();

/**
 * A string s is called happy if it satisfies the following conditions:
 * s only contains the letters 'a', 'b', and 'c'.
 * s does not contain any of "aaa", "bbb", or "ccc" as a substring.
 * s contains at most a occurrences of the letter 'a'.
 * s contains at most b occurrences of the letter 'b'.
 * s contains at most c occurrences of the letter 'c'.
 * Given three integers a, b, and c, return the longest possible happy string.
 * If there are multiple longest happy strings, return any of them.
 * If there is no such string, return the empty string "".
 * A substring is a contiguous sequence of characters within a string.
 *
 * Constraints:
 *
 * 0 <= a, b, c <= 100
 * a + b + c > 0
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_01405_LongestHappyString_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<int> v, v0, v1;
static vector<string> v2;

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

        cin >> s;
        v1.push_back(s);

        string s0;
        cin >> s0;
        cin.get();
        v2.push_back(s0);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        cout << _01405_LongestHappyString(v[i], v0[i], v1[i]) << "\n";
        cout << _01405_LongestHappyString0(v[i], v0[i], v1[i]) << "\n";
        cout << _01405_LongestHappyString1(v[i], v0[i], v1[i]) << "\n";
    }
}

static string _01405_LongestHappyString(int a, int b, int c)
{
    priority_queue<pair<int, char>> pq;

    if (a > 0)
        pq.push({a, 'a'});

    if (b > 0)
        pq.push({b, 'b'});

    if (c > 0)
        pq.push({c, 'c'});

    string ans = "";
    while (!pq.empty())
    {
        pair<int, char> p = pq.top();
        pq.pop();
        int count = p.first;
        char character = p.second;

        if (ans.length() >= 2 and ans[ans.length() - 1] == p.second and
            ans[ans.length() - 2] == p.second)
        {
            if (pq.empty())
                break;

            pair<int, char> temp = pq.top();
            pq.pop();
            ans += temp.second;

            if (temp.first - 1 > 0)
                pq.push({temp.first - 1, temp.second});
        }
        else
        {
            count--;
            ans = ans + character;
        }

        if (count > 0)
            pq.push({count, character});
    }

    return ans;
}

static string _01405_LongestHappyString0(int a, int b, int c)
{
    int curra = 0, currb = 0, currc = 0;
    int totalIterations = a + b + c;
    string ans = "";

    for (int i = 0; i < totalIterations; i++)
    {
        if ((a >= b and a >= c and curra != 2) or
            (a > 0 and (currb == 2 or currc == 2)))
        {
            ans += 'a';
            a--;
            curra++;
            currb = 0;
            currc = 0;
        }
        else if ((b >= a and b >= c and currb != 2) or
                 (b > 0 and (currc == 2 or curra == 2)))
        {
            ans += 'b';
            b--;
            currb++;
            curra = 0;
            currc = 0;
        }
        else if ((c >= a and c >= b and currc != 2) or
                 (c > 0 and (curra == 2 or currb == 2)))
        {
            ans += 'c';
            c--;
            currc++;
            curra = 0;
            currb = 0;
        }
    }

    return ans;
}

static pair<int, int> fun(int a, int b, int c)
{
    int k1 = max(max(a, b), c);
    int k2;

    if (k1 == a)
        k2 = max(b, c);

    if (k1 == b)
        k2 = max(a, c);

    if (k1 == c)
        k2 = max(a, b);

    return make_pair(k1, k2);
}

static string _01405_LongestHappyString1(int a, int b, int c)
{
    string res = "";
    int curr = 0;

    while ((a + b + c) > 0)
    {
        pair<int, int> p = fun(a, b, c);

        if (p.first == a)
        {
            if (res.size() >= 2)
            {
                if (res[curr - 2] == 'a' && res[curr - 1] == 'a')
                {
                    if (p.second == 0)
                        return res;

                    if (p.second == b)
                    {
                        res = res + "b";
                        b--;
                    }
                    else
                    {
                        res = res + "c";
                        c--;
                    }
                }
                else
                {
                    res = res + "a";
                    a--;
                }
            }
            else
            {
                res = res + "a";
                a--;
            }

            curr++;
        }
        else if (p.first == b)
        {
            if (res.size() >= 2)
            {
                if (res[curr - 2] == 'b' && res[curr - 1] == 'b')
                {
                    if (p.second == 0)
                        return res;

                    if (p.second == a)
                    {
                        res = res + "a";
                        a--;
                    }
                    else
                    {
                        res = res + "c";
                        c--;
                    }
                }
                else
                {
                    res = res + "b";
                    b--;
                }
            }
            else
            {
                res = res + "b";
                b--;
            }

            curr++;
        }
        else
        {
            if (res.size() >= 2)
            {
                if (res[curr - 2] == 'c' && res[curr - 1] == 'c')
                {
                    if (p.second == 0)
                        return res;

                    if (p.second == b)
                    {
                        res = res + "b";
                        b--;
                    }
                    else
                    {
                        res = res + "a";
                        a--;
                    }
                }
                else
                {
                    res = res + "c";
                    c--;
                }
            }
            else
            {
                res = res + "c";
                c--;
            }

            curr++;
        }
    }

    return res;
}

#pragma region GTest
static int is_01405_LongestHappyString_RunTest()
{
    stringstream ss;
    ss << "*_01405_LongestHappyString.expected*"
       << ":"
       << "*_01405_LongestHappyString0.expected*"
       << ":"
       << "*_01405_LongestHappyString1.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_01405_LongestHappyString, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        string expected = v2[i];
        sort(expected.begin(), expected.end());

        // Actual
        string actual = _01405_LongestHappyString(v[i], v0[i], v1[i]);
        sort(actual.begin(), actual.end());

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_01405_LongestHappyString0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        string expected = v2[i];
        sort(expected.begin(), expected.end());

        // Actual
        string actual = _01405_LongestHappyString0(v[i], v0[i], v1[i]);
        sort(actual.begin(), actual.end());

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_01405_LongestHappyString1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        string expected = v2[i];
        sort(expected.begin(), expected.end());

        // Actual
        string actual = _01405_LongestHappyString1(v[i], v0[i], v1[i]);
        sort(actual.begin(), actual.end());

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
