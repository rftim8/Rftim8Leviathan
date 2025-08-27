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

// String Manipulation
static bool _01106_ParsingABooleanExpression(string expression);
// Recursive
static bool _01106_ParsingABooleanExpression0(string expression);
// Stack
static bool _01106_ParsingABooleanExpression1(string expression);
// Optimized Stack
static bool _01106_ParsingABooleanExpression2(string expression);

static int is_01106_ParsingABooleanExpression_RunTest();

/**
 * A boolean expression is an expression that evaluates to either true or false.
 * It can be in one of the following shapes:
 * 't' that evaluates to true.
 * 'f' that evaluates to false.
 * '!(subExpr)' that evaluates to the logical NOT of the inner expression subExpr.
 * '&(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical AND of the inner expressions subExpr1,
 * subExpr2, ..., subExprn where n >= 1.
 * '|(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical OR of the inner expressions subExpr1,
 * subExpr2, ..., subExprn where n >= 1.
 * Given a string expression that represents a boolean expression, return the evaluation of that expression.
 * It is guaranteed that the given expression is valid and follows the given rules.
 *
 * Constraints:
 *
 * 1 <= expression.length <= 2 * 104
 * expression[i] is one following characters: '(', ')', '&', '|', '!', 't', 'f', and ','.
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_01106_ParsingABooleanExpression_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<string> v;
static vector<bool> v0;

static void dataCollector()
{
    cin >> n;
    cin >> m;
    cin.get();

    for (int i = 0; i < n * m; i += m)
    {
        string s;
        cin >> s;
        v.push_back(s);

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
        cout << _01106_ParsingABooleanExpression(v[i]) << "\n";
        cout << _01106_ParsingABooleanExpression0(v[i]) << "\n";
        cout << _01106_ParsingABooleanExpression1(v[i]) << "\n";
        cout << _01106_ParsingABooleanExpression2(v[i]) << "\n";
    }
}

#pragma region String Manipulation
static char evaluateSubExpr(const string &subExpr)
{
    char op = subExpr[0];
    string values = subExpr.substr(2, subExpr.length() - 3);

    if (op == '!')
        return values[0] == 't' ? 'f' : 't';

    if (op == '&')
        return values.find('f') != string::npos ? 'f' : 't';

    if (op == '|')
        return values.find('t') != string::npos ? 't' : 'f';

    return 'f';
}

static bool _01106_ParsingABooleanExpression(string expression)
{
    while (expression.length() > 1)
    {
        int start = expression.find_last_of("!&|");
        int end = expression.find(')', start);
        string subExpr = expression.substr(start, end - start + 1);
        char result = evaluateSubExpr(subExpr);
        expression.replace(start, end - start + 1, 1, result);
    }

    return expression[0] == 't';
}
#pragma endregion

#pragma region Recursive
static bool evaluate(string &expr, int &index)
{
    char currChar = expr[index++];

    if (currChar == 't')
        return true;

    if (currChar == 'f')
        return false;

    if (currChar == '!')
    {
        index++;
        bool result = !evaluate(expr, index);
        index++;

        return result;
    }

    vector<bool> values;
    index++;

    while (expr[index] != ')')
    {
        if (expr[index] != ',')
            values.push_back(evaluate(expr, index));
        else
            index++;
    }

    index++;

    if (currChar == '&')
    {
        for (bool v : values)
        {
            if (!v)
                return false;
        }

        return true;
    }

    if (currChar == '|')
    {
        for (bool v : values)
        {
            if (v)
                return true;
        }

        return false;
    }

    return false;
}

static bool _01106_ParsingABooleanExpression0(string expression)
{
    int index = 0;

    return evaluate(expression, index);
}
#pragma endregion

#pragma region Stack
static char evaluateSubExpr(char op, vector<char> &values)
{
    if (op == '!')
        return values[0] == 't' ? 'f' : 't';

    if (op == '&')
    {
        for (char value : values)
        {
            if (value == 'f')
                return 'f';
        }

        return 't';
    }

    if (op == '|')
    {
        for (char value : values)
        {
            if (value == 't')
                return 't';
        }

        return 'f';
    }

    return 'f';
}

static bool _01106_ParsingABooleanExpression1(string expression)
{
    stack<char> st;

    for (char currChar : expression)
    {
        if (currChar == ')')
        {
            vector<char> values;

            while (st.top() != '(')
            {
                values.push_back(st.top());
                st.pop();
            }

            st.pop();
            char op = st.top();
            st.pop();
            char result = evaluateSubExpr(op, values);
            st.push(result);
        }
        else if (currChar != ',')
            st.push(currChar);
    }

    return st.top() == 't';
}
#pragma endregion

#pragma region Optimized Stack
static bool _01106_ParsingABooleanExpression2(string expression)
{
    stack<char> st;

    for (char currChar : expression)
    {
        if (currChar == ',' ||
            currChar == '(')
            continue;

        if (currChar == 't' ||
            currChar == 'f' ||
            currChar == '!' ||
            currChar == '&' ||
            currChar == '|')
            st.push(currChar);
        else if (currChar == ')')
        {
            bool hasTrue = false, hasFalse = false;

            while (st.top() != '!' && st.top() != '&' && st.top() != '|')
            {
                char topValue = st.top();
                st.pop();

                if (topValue == 't')
                    hasTrue = true;

                if (topValue == 'f')
                    hasFalse = true;
            }

            char op = st.top();
            st.pop();

            if (op == '!')
                st.push(hasTrue ? 'f' : 't');
            else if (op == '&')
                st.push(hasFalse ? 'f' : 't');
            else
                st.push(hasTrue ? 't' : 'f');
        }
    }

    return st.top() == 't';
}
#pragma endregion

#pragma region GTest
static int is_01106_ParsingABooleanExpression_RunTest()
{
    stringstream ss;
    ss << "*_01106_ParsingABooleanExpression.expected*"
       << ":"
       << "*_01106_ParsingABooleanExpression0.expected*"
       << ":"
       << "*_01106_ParsingABooleanExpression1.expected*"
       << ":"
       << "*_01106_ParsingABooleanExpression2.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_01106_ParsingABooleanExpression, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        bool expected = v0[i];

        // Actual
        bool actual = _01106_ParsingABooleanExpression(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_01106_ParsingABooleanExpression0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        bool expected = v0[i];

        // Actual
        bool actual = _01106_ParsingABooleanExpression0(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_01106_ParsingABooleanExpression1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        bool expected = v0[i];

        // Actual
        bool actual = _01106_ParsingABooleanExpression1(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_01106_ParsingABooleanExpression2, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        bool expected = v0[i];

        // Actual
        bool actual = _01106_ParsingABooleanExpression2(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
