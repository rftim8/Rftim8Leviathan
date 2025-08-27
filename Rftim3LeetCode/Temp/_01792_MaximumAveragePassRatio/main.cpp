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

// Brute Force - TLE
static double _01792_MaximumAveragePassRatio(vector<vector<int>> &classes, int extraStudents);
// Priority Queue
static double _01792_MaximumAveragePassRatio0(vector<vector<int>> &classes, int extraStudents);
// Speed
static double _01792_MaximumAveragePassRatio1(vector<vector<int>> &classes, int extraStudents);

static int is_01792_MaximumAveragePassRatio_RunTest();

/**
 * There is a school that has classes of students and each class will be having a final exam.
 * You are given a 2D integer array classes, where classes[i] = [passi, totali].
 * You know beforehand that in the ith class, there are totali total students, but only passi number of students
 * will pass the exam.
 * You are also given an integer extraStudents.
 * There are another extraStudents brilliant students that are guaranteed to pass the exam of any class they are assigned to.
 * You want to assign each of the extraStudents students to a class in a way that maximizes the average pass ratio
 * across all the classes.
 * The pass ratio of a class is equal to the number of students of the class that will pass the exam divided
 * by the total number of students of the class.
 * The average pass ratio is the sum of pass ratios of all the classes divided by the number of the classes.
 * Return the maximum possible average pass ratio after assigning the extraStudents students.
 * Answers within 10-5 of the actual answer will be accepted.
 *
 * Constraints:
 *
 * 1 <= classes.length <= 10^5
 * classes[i].length == 2
 * 1 <= passi <= totali <= 10^5
 * 1 <= extraStudents <= 10^5
 */
int main()
{
    offline();
    dataCollector();

    solve();
    return 0;

    ::testing::InitGoogleTest();
    is_01792_MaximumAveragePassRatio_RunTest();
    return RUN_ALL_TESTS();
}

static int n;
static int m;
static vector<vector<vector<int>>> v;
static vector<int> v0;
static vector<double> v1;

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
        v.push_back(stringTo2DVectorInt(s));

        int s0;
        cin >> s0;
        v0.push_back(s0);

        double s1;
        cin >> s1;
        cin.get();
        v1.push_back(s1);
    }
}

static void solve()
{
    for (int i = 0; i < n; i++)
    {
        cout << _01792_MaximumAveragePassRatio(v[i], v0[i]) << "\n";
        cout << _01792_MaximumAveragePassRatio0(v[i], v0[i]) << "\n";
        cout << _01792_MaximumAveragePassRatio1(v[i], v0[i]) << "\n";
    }
}

static double _01792_MaximumAveragePassRatio(vector<vector<int>> &classes0, int extraStudents)
{
    vector<vector<int>> classes(classes0);
    vector<double> passRatios;

    for (int classIndex = 0; classIndex < classes.size(); classIndex++)
    {
        double initialRatio = classes[classIndex][0] / (double)classes[classIndex][1];
        passRatios.push_back(initialRatio);
    }

    while (extraStudents--)
    {
        vector<double> updatedRatios;

        for (int classIndex = 0; classIndex < classes.size(); classIndex++)
        {
            double newRatio = (classes[classIndex][0] + 1) / (double)(classes[classIndex][1] + 1);
            updatedRatios.push_back(newRatio);
        }

        int bestClassIndex = 0;
        double maximumGain = 0;

        for (int classIndex = 0; classIndex < updatedRatios.size(); classIndex++)
        {
            double gain = updatedRatios[classIndex] - passRatios[classIndex];

            if (gain > maximumGain)
            {
                bestClassIndex = classIndex;
                maximumGain = gain;
            }
        }

        passRatios[bestClassIndex] = updatedRatios[bestClassIndex];
        classes[bestClassIndex][0]++;
        classes[bestClassIndex][1]++;
    }

    double totalPassRatio = 0;

    for (double passRatio : passRatios)
    {
        totalPassRatio += passRatio;
    }

    return totalPassRatio / classes.size();
}

static double _01792_MaximumAveragePassRatio0(vector<vector<int>> &classes0, int extraStudents)
{
    vector<vector<int>> classes(classes0);
    auto calculateGain = [](int passes, int totalStudents)
    {
        return (double)(passes + 1) / (totalStudents + 1) - (double)passes / totalStudents;
    };

    priority_queue<pair<double, pair<int, int>>> maxHeap;

    for (const auto &singleClass : classes)
    {
        maxHeap.push({calculateGain(singleClass[0], singleClass[1]), {singleClass[0], singleClass[1]}});
    }

    while (extraStudents--)
    {
        auto [currentGain, classInfo] = maxHeap.top();
        maxHeap.pop();
        int passes = classInfo.first;
        int totalStudents = classInfo.second;
        maxHeap.push({calculateGain(passes + 1, totalStudents + 1), {passes + 1, totalStudents + 1}});
    }

    double totalPassRatio = 0;

    while (!maxHeap.empty())
    {
        auto [_, classInfo] = maxHeap.top();
        maxHeap.pop();
        totalPassRatio += (double)classInfo.first / classInfo.second;
    }

    return totalPassRatio / classes.size();
}

static double _01792_MaximumAveragePassRatio1(vector<vector<int>> &classes, int extraStudents)
{
    auto profit = [&](double pass, double total)
    {
        return (pass + 1) / (total + 1) - pass / total;
    };

    double total = 0;
    priority_queue<pair<double, array<int, 2>>> pq;

    for (int i = 0; i < classes.size(); i++)
    {
        total += (double)classes[i][0] / classes[i][1];
        pq.push({profit(classes[i][0], classes[i][1]), {classes[i][0], classes[i][1]}});
    }

    while (extraStudents--)
    {
        auto [pfit, arr] = pq.top();
        pq.pop();
        total += pfit;
        pq.push({profit(arr[0] + 1, arr[1] + 1), {arr[0] + 1, arr[1] + 1}});
    }

    return total / classes.size();
}

#pragma region GTest
static int is_01792_MaximumAveragePassRatio_RunTest()
{
    stringstream ss;
    ss << "*_01792_MaximumAveragePassRatio.expected*"
       << ":"
       << "*_01792_MaximumAveragePassRatio0.expected*"
       << ":"
       << "*_01792_MaximumAveragePassRatio1.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_01792_MaximumAveragePassRatio, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        double expected = v1[i];

        // Actual
        double actual = _01792_MaximumAveragePassRatio(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_01792_MaximumAveragePassRatio0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        double expected = v1[i];

        // Actual
        double actual = _01792_MaximumAveragePassRatio0(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_01792_MaximumAveragePassRatio1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        double expected = v1[i];

        // Actual
        double actual = _01792_MaximumAveragePassRatio1(v[i], v0[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
