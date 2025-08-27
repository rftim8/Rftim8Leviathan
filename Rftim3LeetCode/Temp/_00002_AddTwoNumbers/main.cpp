#include <bits/stdc++.h>
#include <fstream>
#include <gtest/gtest.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

static ListNode *buildListNodeFromVectorInt(vector<int> v)
{
    ListNode *head = new ListNode(v[0]);
    ListNode *ln = head;

    for (int i = 1; i < v.size(); i++)
    {
        ListNode *t = new ListNode(v[i]);
        ln->next = t;
        ln = ln->next;
    }

    return head;
}

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
static ListNode *_00002_AddTwoNumbers(ListNode *l1, ListNode *l2);

static int is_00002_AddTwoNumbers_RunTest();

/**
 * You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order, and each of their nodes contains a single digit.
 * Add the two numbers and return the sum as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *
 * Constraints:
 *
 * The number of nodes in each linked list is in the range [1, 100].
 * 0 <= Node.val <= 9
 * It is guaranteed that the list represents a number that does not have leading zeros.
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_00002_AddTwoNumbers_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<vector<int>> v, v0, v1;

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
        vector<int> vv = {};
        while (getline(ss, t, ','))
        {
            vv.push_back(stoi(t));
        }
        v.push_back(vv);

        s = "";
        getline(cin, s);
        ss.clear();
        ss.str(s);
        t = "";
        vv = {};
        while (getline(ss, t, ','))
        {
            vv.push_back(stoi(t));
        }
        v0.push_back(vv);

        s = "";
        getline(cin, s);
        ss.clear();
        ss.str(s);
        t = "";
        vv = {};
        while (getline(ss, t, ','))
        {
            vv.push_back(stoi(t));
        }
        v1.push_back(vv);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        ListNode *head = buildListNodeFromVectorInt(v[i]);
        ListNode *head0 = buildListNodeFromVectorInt(v0[i]);
        ListNode *res = _00002_AddTwoNumbers(head, head0);

        while (res != NULL)
        {
            cout << res->val << " ";
            res = res->next;
        }
        cout << "\n";
    }
}

static ListNode *_00002_AddTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *dummyHead = new ListNode(0);
    ListNode *curr = dummyHead;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0)
    {
        int x = l1 ? l1->val : 0;
        int y = l2 ? l2->val : 0;
        int sum = carry + x + y;
        carry = sum / 10;
        curr->next = new ListNode(sum % 10);
        curr = curr->next;
        l1 = l1 ? l1->next : nullptr;
        l2 = l2 ? l2->next : nullptr;
    }

    return dummyHead->next;
}

#pragma region GTest
static int is_00002_AddTwoNumbers_RunTest()
{
    stringstream ss;
    ss << "*_00002_AddTwoNumbers.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_00002_AddTwoNumbers, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<int> expected = v1[i];

        // Actual
        ListNode *head = buildListNodeFromVectorInt(v[i]);
        ListNode *head0 = buildListNodeFromVectorInt(v0[i]);
        ListNode *res = _00002_AddTwoNumbers(head, head0);

        vector<int> actual = {};
        while (res != NULL)
        {
            actual.push_back(res->val);
            res = res->next;
        }

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
