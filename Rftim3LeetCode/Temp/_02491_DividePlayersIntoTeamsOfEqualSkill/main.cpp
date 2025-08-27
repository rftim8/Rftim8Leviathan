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

// Sorting
static long long _02491_DividePlayersIntoTeamsOfEqualSkill(vector<int> &skill);
// Frequency Table
static long long _02491_DividePlayersIntoTeamsOfEqualSkill0(vector<int> &skill);
// Map
static long long _02491_DividePlayersIntoTeamsOfEqualSkill1(vector<int> &skill);
// Speed
static long long _02491_DividePlayersIntoTeamsOfEqualSkill2(vector<int> &skill);

static int is_02491_DividePlayersIntoTeamsOfEqualSkill_RunTest();

/**
 * You are given a positive integer array skill of even length n where skill[i] denotes the skill of the ith player.
 * Divide the players into n / 2 teams of size 2 such that the total skill of each team is equal.
 * The chemistry of a team is equal to the product of the skills of the players on that team.
 *
 * Return the sum of the chemistry of all the teams, or return -1 if there is no way to divide the players into teams
 * such that the total skill of each team is equal.
 *
 * Constraints:
 *
 * 2 <= skill.length <= 10^5
 * skill.length is even.
 * 1 <= skill[i] <= 1000
 */
int main()
{
    offline();
    dataCollector();

    // solve();
    // return 0;

    ::testing::InitGoogleTest();
    is_02491_DividePlayersIntoTeamsOfEqualSkill_RunTest();
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
        vector<int> vv = {};
        while (getline(ss, t, ','))
        {
            vv.push_back(stoi(t));
        }
        v.push_back(vv);

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
        cout << _02491_DividePlayersIntoTeamsOfEqualSkill(v[i]) << "\n";
        cout << _02491_DividePlayersIntoTeamsOfEqualSkill0(v[i]) << "\n";
        cout << _02491_DividePlayersIntoTeamsOfEqualSkill1(v[i]) << "\n";
        cout << _02491_DividePlayersIntoTeamsOfEqualSkill2(v[i]) << "\n";
    }
}

static long long _02491_DividePlayersIntoTeamsOfEqualSkill(vector<int> &skill)
{
    sort(skill.begin(), skill.end());

    int n = skill.size();
    long long totalChemistry = 0;
    int targetTeamSkill = skill[0] + skill[n - 1];

    for (int i = 0; i < n / 2; i++)
    {
        int currentTeamSkill = skill[i] + skill[n - i - 1];

        if (currentTeamSkill != targetTeamSkill)
            return -1;

        totalChemistry += (long long)skill[i] * (long long)skill[n - i - 1];
    }

    return totalChemistry;
}

static long long _02491_DividePlayersIntoTeamsOfEqualSkill0(vector<int> &skill)
{
    int n = skill.size();
    int totalSkill = 0;
    vector<int> skillFrequency(1001, 0);

    for (int playerSkill : skill)
    {
        totalSkill += playerSkill;
        skillFrequency[playerSkill]++;
    }

    if (totalSkill % (n / 2) != 0)
        return -1;

    int targetTeamSkill = totalSkill / (n / 2);
    long long totalChemistry = 0;

    for (int playerSkill : skill)
    {
        int partnerSkill = targetTeamSkill - playerSkill;

        if (skillFrequency[partnerSkill] == 0)
            return -1;

        totalChemistry += (long long)playerSkill * (long long)partnerSkill;
        skillFrequency[partnerSkill]--;
    }

    return totalChemistry / 2;
}

static long long _02491_DividePlayersIntoTeamsOfEqualSkill1(vector<int> &skill)
{
    int n = skill.size();
    int totalSkill = 0;
    unordered_map<int, int> skillMap;

    for (int s : skill)
    {
        totalSkill += s;
        skillMap[s] = skillMap[s] + 1;
    }

    if (totalSkill % (n / 2) != 0)
        return -1;

    int targetSkill = totalSkill / (n / 2);
    long long totalChemistry = 0;

    for (auto &[currSkill, currFreq] : skillMap)
    {
        int partnerSkill = targetSkill - currSkill;

        if (skillMap.find(partnerSkill) == skillMap.end() ||
            currFreq != skillMap[partnerSkill])
            return -1;

        totalChemistry += (long long)currSkill * (long long)partnerSkill * (long long)currFreq;
    }

    return totalChemistry / 2;
}

static long long _02491_DividePlayersIntoTeamsOfEqualSkill2(vector<int> &skill)
{
    vector<int> v(1001, 0);
    int n = skill.size();
    int tsum = 0;

    for (auto it : skill)
    {
        tsum += it;
        v[it]++;
    }

    n >>= 1;

    if (tsum % n != 0)
        return -1;

    int sum = tsum / n;
    int64_t ans = 0;

    for (int i = 0; i <= sum / 2; ++i)
    {
        if (v[i] == 0)
            continue;

        int c = sum - i;

        if (i != c)
        {
            if (v[i] != v[c])
                return -1;

            ans += 1ll * i * c * v[i];
            n -= v[i];
        }
        else
        {
            if (v[i] & 1)
                return -1;

            ans += 1LL * i * i * v[i] / 2;
            n -= v[i] / 2;
        }
    }

    if (n > 0)
        return -1;

    return ans;
}

#pragma region GTest
static int is_02491_DividePlayersIntoTeamsOfEqualSkill_RunTest()
{
    stringstream ss;
    ss << "*_02491_DividePlayersIntoTeamsOfEqualSkill.expected*"
       << ":"
       << "*_02491_DividePlayersIntoTeamsOfEqualSkill0.expected*"
       << ":"
       << "*_02491_DividePlayersIntoTeamsOfEqualSkill1.expected*"
       << ":"
       << "*_02491_DividePlayersIntoTeamsOfEqualSkill2.expected*";
    ::testing::GTEST_FLAG(filter) = ss.str();
    return 0;
}

TEST(_02491_DividePlayersIntoTeamsOfEqualSkill, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        long long expected = v0[i];

        // Actual
        long long actual = _02491_DividePlayersIntoTeamsOfEqualSkill(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02491_DividePlayersIntoTeamsOfEqualSkill0, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        long long expected = v0[i];

        // Actual
        long long actual = _02491_DividePlayersIntoTeamsOfEqualSkill0(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02491_DividePlayersIntoTeamsOfEqualSkill1, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        long long expected = v0[i];

        // Actual
        long long actual = _02491_DividePlayersIntoTeamsOfEqualSkill1(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}

TEST(_02491_DividePlayersIntoTeamsOfEqualSkill2, expected)
{
    for (int i = 0; i < n; i++)
    {
        // Arrange
        long long expected = v0[i];

        // Actual
        long long actual = _02491_DividePlayersIntoTeamsOfEqualSkill2(v[i]);

        // Assert
        EXPECT_EQ(actual, expected);
    }
}
#pragma endregion
