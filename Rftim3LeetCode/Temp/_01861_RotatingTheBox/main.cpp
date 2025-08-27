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
static vector<vector<char>> _01861_RotatingTheBox(vector<vector<char>> &box);
// Brute Force - Optimized
static vector<vector<char>> _01861_RotatingTheBox0(vector<vector<char>> &box);
// Combine Rotation and Gravity Operations
static vector<vector<char>> _01861_RotatingTheBox1(vector<vector<char>> &box);
// Speed
static vector<vector<char>> _01861_RotatingTheBox2(vector<vector<char>> &box);

static int is_01861_RotatingTheBox_RunTest();

/**
 * You are given an m x n matrix of characters box representing a side-view of a box.
 * Each cell of the box is one of the following:
 * A stone '#'
 * A stationary obstacle '*'
 * Empty '.'
 * The box is rotated 90 degrees clockwise, causing some of the stones to fall due to gravity.
 * Each stone falls down until it lands on an obstacle, another stone, or the bottom of the box.
 * Gravity does not affect the obstacles' positions, and the inertia from the box's rotation
 * does not affect the stones' horizontal positions.
 * It is guaranteed that each stone in box rests on an obstacle, another stone, or the bottom
 * of the box.
 * Return an n x m matrix representing the box after the rotation described above.
 *
 * Constraints:
 *
 * m == box.length
 * n == box[i].length
 * 1 <= m, n <= 500
 * box[i][j] is either '#', '*', or '.'.
 */
int main()
{
    offline();
    dataCollector();

    solve();
    return 0;

    ::testing::InitGoogleTest();
    is_01861_RotatingTheBox_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<vector<vector<char>>> v, v0;

static vector<vector<char>> stringTo2DVectorChar(string s)
{
    vector<vector<char>> res = {};
    int l = 0, r = 0;
    string a = "";
    vector<string> vv = {};
    for (auto &&j : s)
    {
        if (j == '[')
            l++;
        else if (j == ']')
        {
            r++;
            if (l > r)
            {
                vv.push_back(a);
                a = "";
            }
        }
        else
            a += j;
    }

    for (auto &&j : vv)
    {
        vector<char> a = {};
        string t;
        stringstream ss(j);
        while (getline(ss, t, ','))
        {
            if (t != "null" &&
                t != "")
                a.push_back(t[0]);
        }
        res.push_back(a);
    }

    return res;
}

static void dataCollector()
{
    cin >> n;
    cin >> m;
    cin.get();

    for (int i = 0; i < n * m; i += m)
    {
        string s;
        getline(cin, s);
        v.push_back(stringTo2DVectorChar(s));

        s = "";
        getline(cin, s);
        v0.push_back(stringTo2DVectorChar(s));
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        vector<vector<char>> res = _01861_RotatingTheBox(v[i]);
        for (auto &&j : res)
        {
            for (auto &&k : j)
            {
                cout << k << " ";
            }
            cout << "\n";
        }
        cout << "\n";

        vector<vector<char>> res0 = _01861_RotatingTheBox0(v[i]);
        for (auto &&j : res0)
        {
            for (auto &&k : j)
            {
                cout << k << " ";
            }
            cout << "\n";
        }
        cout << "\n";

        vector<vector<char>> res1 = _01861_RotatingTheBox1(v[i]);
        for (auto &&j : res1)
        {
            for (auto &&k : j)
            {
                cout << k << " ";
            }
            cout << "\n";
        }
        cout << "\n";

        vector<vector<char>> res2 = _01861_RotatingTheBox2(v[i]);
        for (auto &&j : res2)
        {
            for (auto &&k : j)
            {
                cout << k << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
}

static vector<vector<char>> _01861_RotatingTheBox(vector<vector<char>> &box)
{
    int m = box.size();
    int n = box[0].size();
    vector<vector<char>> result(n, vector<char>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            result[i][j] = box[j][i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        reverse(result[i].begin(), result[i].end());
    }

    for (int j = 0; j < m; j++)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            if (result[i][j] == '.')
            {
                int nextRowWithStone = -1;

                for (int k = i - 1; k >= 0; k--)
                {
                    if (result[k][j] == '*')
                        break;

                    if (result[k][j] == '#')
                    {
                        nextRowWithStone = k;
                        break;
                    }
                }

                if (nextRowWithStone != -1)
                {
                    result[nextRowWithStone][j] = '.';
                    result[i][j] = '#';
                }
            }
        }
    }

    return result;
}

static vector<vector<char>> _01861_RotatingTheBox0(vector<vector<char>> &box)
{
    int m = box.size();
    int n = box[0].size();
    vector<vector<char>> result(n, vector<char>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            result[i][j] = box[j][i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        reverse(result[i].begin(), result[i].end());
    }

    for (int j = 0; j < m; j++)
    {
        int lowestRowWithEmptyCell = n - 1;

        for (int i = n - 1; i >= 0; i--)
        {
            if (result[i][j] == '#')
            {
                result[i][j] = '.';
                result[lowestRowWithEmptyCell][j] = '#';
                lowestRowWithEmptyCell--;
            }

            if (result[i][j] == '*')
                lowestRowWithEmptyCell = i - 1;
        }
    }

    return result;
}

static vector<vector<char>> _01861_RotatingTheBox1(vector<vector<char>> &box)
{
    int m = box.size();
    int n = box[0].size();
    vector<vector<char>> result(n, vector<char>(m, '.'));

    for (int i = 0; i < m; i++)
    {
        int lowestRowWithEmptyCell = n - 1;

        for (int j = n - 1; j >= 0; j--)
        {
            if (box[i][j] == '#')
            {
                result[lowestRowWithEmptyCell][m - i - 1] = '#';
                lowestRowWithEmptyCell--;
            }

            if (box[i][j] == '*')
            {
                result[j][m - i - 1] = '*';
                lowestRowWithEmptyCell = j - 1;
            }
        }
    }

    return result;
}

static vector<vector<char>> _01861_RotatingTheBox2(vector<vector<char>> &box)
{
    const int r = box.size(), c = box[0].size();
    vector<vector<char>> rotate(c, vector<char>(r, '.'));
    
    for (int i = 0; i < r; i++)
    {
        int bottom = c - 1;
    
        for (int j = c - 1; j >= 0; j--)
        {
            if (box[i][j] == '#')
            {
                rotate[bottom][r - 1 - i] = '#';
                bottom--;
            }
            else if (box[i][j] == '*')
            {
                rotate[j][r - 1 - i] = '*';
                bottom = j - 1;
            }
        }
    }

    return rotate;
}

#pragma region GTest
static int is_01861_RotatingTheBox_RunTest()
{
    stringstream ss;
    ss << "*_01861_RotatingTheBox.expected*"
       << ":"
       << "*_01861_RotatingTheBox0.expected*"
       << ":"
       << "*_01861_RotatingTheBox1.expected*"
       << ":"
       << "*_01861_RotatingTheBox2.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_01861_RotatingTheBox, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<vector<char>> expected = v0[i];

        // Actual
        vector<vector<char>> actual = _01861_RotatingTheBox(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_01861_RotatingTheBox0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<vector<char>> expected = v0[i];

        // Actual
        vector<vector<char>> actual = _01861_RotatingTheBox0(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_01861_RotatingTheBox1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<vector<char>> expected = v0[i];

        // Actual
        vector<vector<char>> actual = _01861_RotatingTheBox1(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_01861_RotatingTheBox2, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<vector<char>> expected = v0[i];

        // Actual
        vector<vector<char>> actual = _01861_RotatingTheBox2(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
