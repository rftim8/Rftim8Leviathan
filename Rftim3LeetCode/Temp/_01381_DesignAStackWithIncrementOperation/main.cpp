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

// Array
static vector<string> _01381_DesignAStackWithIncrementOperation(vector<string> v, vector<vector<int>> v0);
// LinkedList
static vector<string> _01381_DesignAStackWithIncrementOperation0(vector<string> v, vector<vector<int>> v0);
// Array Using Lazy Propagation
static vector<string> _01381_DesignAStackWithIncrementOperation1(vector<string> v, vector<vector<int>> v0);

static int is_01381_DesignAStackWithIncrementOperation_RunTest();

/**
 * Design a stack that supports increment operations on its elements.
 *
 * Implement the CustomStack class:
 *
 * CustomStack(int maxSize) Initializes the object with maxSize which is the maximum number of elements in the stack.
 * void push(int x) Adds x to the top of the stack if the stack has not reached the maxSize.
 * int pop() Pops and returns the top of the stack or -1 if the stack is empty.
 * void inc(int k, int val) Increments the bottom k elements of the stack by val.
 * If there are less than k elements in the stack, increment all the elements in the stack.
 *
 * Constraints:
 *
 * 1 <= maxSize, x, k <= 1000
 * 0 <= val <= 100
 * At most 1000 calls will be made to each method of increment, push and pop each separately.
 */
int main()
{
    offline();
    dataCollector();

    solve();
    return 0;

    ::testing::InitGoogleTest();
    is_01381_DesignAStackWithIncrementOperation_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<vector<string>> v;
static vector<vector<vector<int>>> v0;
static vector<vector<string>> v1;

static vector<vector<int>> stringTo2DVectorInt(string s)
{
    vector<vector<int>> res = {};
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
        vector<int> a = {};
        string t;
        stringstream ss(j);
        while (getline(ss, t, ','))
        {
            if (t != "null" &&
                t != "")
                a.push_back(stoi(t));
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
        stringstream ss(s);
        string t;
        vector<string> vv = {};
        while (getline(ss, t, ','))
        {
            vv.push_back(t);
        }
        v.push_back(vv);

        s = "";
        getline(cin, s);
        v0.push_back(stringTo2DVectorInt(s));

        s = "";
        getline(cin, s);
        ss.clear();
        ss.str(s);
        t = "";
        vv = {};
        while (getline(ss, t, ','))
        {
            vv.push_back(t);
        }
        v1.push_back(vv);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        vector<string> res = _01381_DesignAStackWithIncrementOperation(v[i], v0[i]);
        for (auto &&j : res)
        {
            cout << j << " ";
        }
        cout << "\n";

        vector<string> res0 = _01381_DesignAStackWithIncrementOperation0(v[i], v0[i]);
        for (auto &&j : res0)
        {
            cout << j << " ";
        }
        cout << "\n";

        vector<string> res1 = _01381_DesignAStackWithIncrementOperation1(v[i], v0[i]);
        for (auto &&j : res1)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
}

class CustomStack
{
private:
    vector<int> stackVector;
    int topIndex;

public:
    CustomStack(int maxSize)
    {
        stackVector.resize(maxSize);
        topIndex = -1;
    }

    void push(int x)
    {
        if (topIndex < (int)(stackVector.size()) - 1)
            stackVector[++topIndex] = x;
    }

    int pop()
    {
        if (topIndex >= 0)
            return stackVector[topIndex--];

        return -1;
    }

    void increment(int k, int val)
    {
        int limit = min(k, topIndex + 1);

        for (int i = 0; i < limit; i++)
        {
            stackVector[i] += val;
        }
    }
};

static vector<string> _01381_DesignAStackWithIncrementOperation(vector<string> v, vector<vector<int>> v0)
{
    vector<string> res = {};

    CustomStack *obj = new CustomStack(v0[0][0]);
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == "CustomStack")
            res.push_back("null");
        else
        {
            if (v[i] == "push")
            {
                obj->push(v0[i][0]);
                res.push_back("null");
            }
            else if (v[i] == "pop")
            {
                string param = to_string(obj->pop());
                res.push_back(param);
            }
            else if (v[i] == "increment")
            {
                obj->increment(v0[i][0], v0[i][1]);
                res.push_back("null");
            }
        }
    }

    return res;
}

class CustomStack0
{
private:
    list<int> stack;
    int maxSize;

public:
    CustomStack0(int maxSize) { this->maxSize = maxSize; }

    void push(int x)
    {
        if (stack.size() < maxSize)
            stack.push_back(x);
    }

    int pop()
    {
        if (stack.empty())
            return -1;

        int topElement = stack.back();
        stack.pop_back();

        return topElement;
    }

    void increment(int k, int val)
    {
        auto it = stack.begin();

        for (int i = 0; i < k && it != stack.end(); i++, it++)
        {
            *it += val;
        }
    }
};

static vector<string> _01381_DesignAStackWithIncrementOperation0(vector<string> v, vector<vector<int>> v0)
{
    vector<string> res = {};

    CustomStack0 *obj = new CustomStack0(v0[0][0]);
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == "CustomStack")
            res.push_back("null");
        else
        {
            if (v[i] == "push")
            {
                obj->push(v0[i][0]);
                res.push_back("null");
            }
            else if (v[i] == "pop")
            {
                string param = to_string(obj->pop());
                res.push_back(param);
            }
            else if (v[i] == "increment")
            {
                obj->increment(v0[i][0], v0[i][1]);
                res.push_back("null");
            }
        }
    }

    return res;
}

class CustomStack1
{
private:
    vector<int> stackArray;
    vector<int> incrementArray;
    int topIndex;

public:
    CustomStack1(int maxSize)
    {
        stackArray.resize(maxSize);
        incrementArray.resize(maxSize);
        topIndex = -1;
    }

    void push(int x)
    {
        if (topIndex < (int)(stackArray.size()) - 1)
            stackArray[++topIndex] = x;
    }

    int pop()
    {
        if (topIndex < 0)
            return -1;

        int result = stackArray[topIndex] + incrementArray[topIndex];

        if (topIndex > 0)
            incrementArray[topIndex - 1] += incrementArray[topIndex];

        incrementArray[topIndex] = 0;
        topIndex--;

        return result;
    }

    void increment(int k, int val)
    {
        if (topIndex >= 0)
        {
            int incrementIndex = min(topIndex, k - 1);
            incrementArray[incrementIndex] += val;
        }
    }
};

static vector<string> _01381_DesignAStackWithIncrementOperation1(vector<string> v, vector<vector<int>> v0)
{
    vector<string> res = {};

    CustomStack1 *obj = new CustomStack1(v0[0][0]);
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == "CustomStack")
            res.push_back("null");
        else
        {
            if (v[i] == "push")
            {
                obj->push(v0[i][0]);
                res.push_back("null");
            }
            else if (v[i] == "pop")
            {
                string param = to_string(obj->pop());
                res.push_back(param);
            }
            else if (v[i] == "increment")
            {
                obj->increment(v0[i][0], v0[i][1]);
                res.push_back("null");
            }
        }
    }

    return res;
}

#pragma region GTest
static int is_01381_DesignAStackWithIncrementOperation_RunTest()
{
    stringstream ss;
    ss << "*_01381_DesignAStackWithIncrementOperation.expected*"
       << ":"
       << "*_01381_DesignAStackWithIncrementOperation0.expected*"
       << ":"
       << "*_01381_DesignAStackWithIncrementOperation1.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_01381_DesignAStackWithIncrementOperation, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<string> expected = v1[i];

        // Actual
        vector<string> actual = _01381_DesignAStackWithIncrementOperation(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_01381_DesignAStackWithIncrementOperation0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<string> expected = v1[i];

        // Actual
        vector<string> actual = _01381_DesignAStackWithIncrementOperation0(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_01381_DesignAStackWithIncrementOperation1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<string> expected = v1[i];

        // Actual
        vector<string> actual = _01381_DesignAStackWithIncrementOperation1(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
