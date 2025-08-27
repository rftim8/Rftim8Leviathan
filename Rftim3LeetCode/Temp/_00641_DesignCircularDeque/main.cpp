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

// LinkedList
static vector<string> _00641_DesignCircularDeque(vector<string> v, vector<vector<int>> v0);
// Speed
static vector<string> _00641_DesignCircularDeque0(vector<string> v, vector<vector<int>> v0);

static int is_00641_DesignCircularDeque_RunTest();

/**
 * Design your implementation of the circular double-ended queue (deque).
 *
 * Implement the MyCircularDeque class:
 *
 * MyCircularDeque(int k) Initializes the deque with a maximum size of k.
 * boolean insertFront() Adds an item at the front of Deque. Returns true if the operation is successful, or false otherwise.
 * boolean insertLast() Adds an item at the rear of Deque. Returns true if the operation is successful, or false otherwise.
 * boolean deleteFront() Deletes an item from the front of Deque. Returns true if the operation is successful, or false otherwise.
 * boolean deleteLast() Deletes an item from the rear of Deque. Returns true if the operation is successful, or false otherwise.
 * int getFront() Returns the front item from the Deque. Returns -1 if the deque is empty.
 * int getRear() Returns the last item from Deque. Returns -1 if the deque is empty.
 * boolean isEmpty() Returns true if the deque is empty, or false otherwise.
 * boolean isFull() Returns true if the deque is full, or false otherwise.
 *
 * Constraints:
 *
 * 1 <= k <= 1000
 * 0 <= value <= 1000
 * At most 2000 calls will be made to insertFront, insertLast, deleteFront, deleteLast, getFront, getRear, isEmpty, isFull.
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_00641_DesignCircularDeque_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<vector<string>> v, v1;
static vector<vector<vector<int>>> v0;

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
        string t = "";
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
        vector<string> res = _00641_DesignCircularDeque(v[i], v0[i]);
        for (auto &&j : res)
        {
            cout << j << " ";
        }
        cout << "\n";

        vector<string> res0 = _00641_DesignCircularDeque0(v[i], v0[i]);
        for (auto &&j : res0)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
}

#pragma region LinkedList
struct Node
{
    int val;
    Node *next;
    Node *prev;
    Node(int val, Node *next = NULL, Node *prev = NULL) : val(val), next(next), prev(prev) {}
};

class MyCircularDeque
{
private:
    Node *head;
    Node *rear;
    int size;
    int capacity;

public:
    MyCircularDeque(int k)
    {
        head = NULL;
        rear = NULL;
        size = 0;
        capacity = k;
    }

    bool insertFront(int value)
    {
        if (isFull())
            return false;

        if (head == NULL)
        {
            head = new Node(value);
            rear = head;
        }
        else
        {
            Node *newHead = new Node(value);
            newHead->next = head;
            head->prev = newHead;
            head = newHead;
        }
        size++;

        return true;
    }

    bool insertLast(int value)
    {
        if (isFull())
            return false;

        if (head == NULL)
        {
            head = new Node(value);
            rear = head;
        }
        else
        {
            Node *newNode = new Node(value, NULL, rear);
            rear->next = newNode;
            rear = newNode;
        }
        size++;

        return true;
    }

    bool deleteFront()
    {
        if (isEmpty())
            return false;

        if (size == 1)
        {
            head = NULL;
            rear = NULL;
        }
        else
        {
            Node *nextNode = head->next;
            delete head;
            head = nextNode;
        }
        size--;

        return true;
    }

    bool deleteLast()
    {
        if (isEmpty())
            return false;

        if (size == 1)
        {
            head = NULL;
            rear = NULL;
        }
        else
        {
            Node *prevNode = rear->prev;
            delete rear;
            rear = prevNode;
        }
        size--;

        return true;
    }

    int getFront()
    {
        return (isEmpty()) ? -1 : head->val;
    }

    int getRear()
    {
        return (isEmpty()) ? -1 : rear->val;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == capacity;
    }
};

static vector<string> _00641_DesignCircularDeque(vector<string> v, vector<vector<int>> v0)
{
    vector<string> res = {};

    MyCircularDeque *obj = new MyCircularDeque(v0[0][0]);
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == "MyCircularDeque")
            res.push_back("null");
        else
        {
            if (v[i] == "insertLast")
            {
                bool param = obj->insertLast(v0[i][0]);
                res.push_back(param ? "true" : "false");
            }
            else if (v[i] == "insertFront")
            {
                bool param = obj->insertFront(v0[i][0]);
                res.push_back(param ? "true" : "false");
            }
            else if (v[i] == "deleteLast")
            {
                bool param = obj->deleteLast();
                res.push_back(param ? "true" : "false");
            }
            else if (v[i] == "deleteFront")
            {
                bool param = obj->deleteFront();
                res.push_back(param ? "true" : "false");
            }
            else if (v[i] == "getFront")
            {
                int param = obj->getFront();
                res.push_back(to_string(param));
            }
            else if (v[i] == "getRear")
            {
                int param = obj->getRear();
                res.push_back(to_string(param));
            }
            else if (v[i] == "isEmpty")
            {
                bool param = obj->isEmpty();
                res.push_back(param ? "true" : "false");
            }
            else if (v[i] == "isFull")
            {
                bool param = obj->isFull();
                res.push_back(param ? "true" : "false");
            }
        }
    }

    return res;
}
#pragma endregion

#pragma region Speed
class Node0
{
public:
    int data;
    Node0 *prev;
    Node0 *next;

    Node0()
    {
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }

    Node0(int x)
    {
        this->data = x;
        this->prev = NULL;
        this->next = NULL;
    }
};

class MyCircularDeque0
{
    Node0 *left = new Node0(-1);
    Node0 *right = new Node0(-1);
    int size = 0, capacity = 0;

public:
    void remove(Node0 *temp)
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        temp->next = NULL;
        temp->prev = NULL;
    }

    void add(Node0 *dummy, Node0 *temp)
    {
        dummy->prev->next = temp;
        temp->prev = dummy->prev;
        temp->next = dummy;
        dummy->prev = temp;
    }

    MyCircularDeque0(int k)
    {
        left->next = right;
        right->prev = left;
        capacity = k;
    }

    bool insertFront(int value)
    {
        if (isFull())
            return false;

        Node0 *element = new Node0(value);
        add(left->next, element);
        size++;

        return true;
    }

    bool insertLast(int value)
    {
        if (isFull())
            return false;

        Node0 *element = new Node0(value);
        add(right, element);
        size++;

        return true;
    }

    bool deleteFront()
    {
        if (isEmpty())
            return false;

        remove(left->next);
        size--;

        return true;
    }

    bool deleteLast()
    {
        if (isEmpty())
            return false;

        remove(right->prev);
        size--;

        return true;
    }

    int getFront()
    {
        if (isEmpty())
            return -1;

        return left->next->data;
    }

    int getRear()
    {
        if (isEmpty())
            return -1;

        return right->prev->data;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == capacity;
    }
};

static vector<string> _00641_DesignCircularDeque0(vector<string> v, vector<vector<int>> v0)
{
    vector<string> res = {};

    MyCircularDeque0 *obj = new MyCircularDeque0(v0[0][0]);
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == "MyCircularDeque")
            res.push_back("null");
        else
        {
            if (v[i] == "insertLast")
            {
                bool param = obj->insertLast(v0[i][0]);
                res.push_back(param ? "true" : "false");
            }
            else if (v[i] == "insertFront")
            {
                bool param = obj->insertFront(v0[i][0]);
                res.push_back(param ? "true" : "false");
            }
            else if (v[i] == "deleteLast")
            {
                bool param = obj->deleteLast();
                res.push_back(param ? "true" : "false");
            }
            else if (v[i] == "deleteFront")
            {
                bool param = obj->deleteFront();
                res.push_back(param ? "true" : "false");
            }
            else if (v[i] == "getFront")
            {
                int param = obj->getFront();
                res.push_back(to_string(param));
            }
            else if (v[i] == "getRear")
            {
                int param = obj->getRear();
                res.push_back(to_string(param));
            }
            else if (v[i] == "isEmpty")
            {
                bool param = obj->isEmpty();
                res.push_back(param ? "true" : "false");
            }
            else if (v[i] == "isFull")
            {
                bool param = obj->isFull();
                res.push_back(param ? "true" : "false");
            }
        }
    }

    return res;
}
#pragma endregion

#pragma region GTest
static int is_00641_DesignCircularDeque_RunTest()
{
    stringstream ss;
    ss << "*_00641_DesignCircularDeque.expected*"
       << ":"
       << "*_00641_DesignCircularDeque0.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_00641_DesignCircularDeque, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<string> expected = v1[i];

        // Actual
        vector<string> actual = _00641_DesignCircularDeque(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_00641_DesignCircularDeque0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        vector<string> expected = v1[i];

        // Actual
        vector<string> actual = _00641_DesignCircularDeque0(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
