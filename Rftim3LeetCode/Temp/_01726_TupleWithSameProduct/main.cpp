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

// Brute Force - My submission
static int _01726_TupleWithSameProduct(vector<int> &nums);
// Runtime
static int _01726_TupleWithSameProduct_0(vector<int> &nums);
// Memory
static int _01726_TupleWithSameProduct_1(vector<int> &nums);

static int is_01726_TupleWithSameProduct_RunTest();

/**
 * Given an array nums of distinct positive integers, return the number of tuples (a, b, c, d) such that
 * a * b = c * d where a, b, c, and d are elements of nums, and a != b != c != d.
 *
 * Constraints:
 *
 * 1 <= nums.length <= 1000
 * 1 <= nums[i] <= 10^4
 * All elements in nums are distinct.
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_01726_TupleWithSameProduct_RunTest();
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
        cout << _01726_TupleWithSameProduct(v[i]) << "\n";
        cout << _01726_TupleWithSameProduct_0(v[i]) << "\n";
        cout << _01726_TupleWithSameProduct_1(v[i]) << "\n";
    }
}

static int _01726_TupleWithSameProduct(vector<int> &nums)
{
    int res = 0;
    unordered_map<int, int> um = {};

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            int t = nums[i] * nums[j];

            if (um[t])
                res += um[t] * 8;

            um[t]++;
        }
    }

    return res;
}

static int _01726_TupleWithSameProduct_0(vector<int> &nums)
{
    int numsLength = nums.size();
    vector<int> pairProducts;
    int totalNumberOfTuples = 0;

    for (int firstIndex = 0; firstIndex < numsLength; firstIndex++)
    {
        for (int secondIndex = firstIndex + 1; secondIndex < numsLength;
             secondIndex++)
        {
            pairProducts.push_back(nums[firstIndex] * nums[secondIndex]);
        }
    }

    sort(pairProducts.begin(), pairProducts.end());
    int lastProductSeen = -1;
    int sameProductCount = 0;

    for (int productIndex = 0; productIndex < pairProducts.size();
         productIndex++)
    {
        if (pairProducts[productIndex] == lastProductSeen)
            sameProductCount++;
        else
        {
            int pairsOfEqualProduct = (sameProductCount - 1) * sameProductCount / 2;
            totalNumberOfTuples += 8 * pairsOfEqualProduct;
            lastProductSeen = pairProducts[productIndex];
            sameProductCount = 1;
        }
    }

    int pairsOfEqualProduct = (sameProductCount - 1) * sameProductCount / 2;
    totalNumberOfTuples += 8 * pairsOfEqualProduct;

    return totalNumberOfTuples;
}

static int _01726_TupleWithSameProduct_1(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    const int n = nums.size();
    int ret = 0;
    int a = 0;
    int d = nums.size() - 1;

    for (int a = 0; a < n; ++a)
    {
        for (int d = a + 3; d < n; ++d)
        {
            const int ad = nums[a] * nums[d];
            int b = a + 1;
            int c = d - 1;

            while (b < c)
            {
                const int bc = nums[b] * nums[c];
                if (bc == ad)
                {
                    ret += 1;
                    b += 1;
                    c -= 1;
                }
                else if (bc > ad)
                    c -= 1;
                else // bc < ad
                    b += 1;
            }
        }
    }

    return ret * 8;
}

#pragma region GTest
static int is_01726_TupleWithSameProduct_RunTest()
{
    stringstream ss;
    ss << "*_01726_TupleWithSameProduct.expected*"
       << ":"
       << "*_01726_TupleWithSameProduct_0.expected*"
       << ":"
       << "*_01726_TupleWithSameProduct_1.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_01726_TupleWithSameProduct, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _01726_TupleWithSameProduct(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_01726_TupleWithSameProduct_0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _01726_TupleWithSameProduct_0(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_01726_TupleWithSameProduct_1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        int expected = v0[i];

        // Actual
        int actual = _01726_TupleWithSameProduct_1(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
