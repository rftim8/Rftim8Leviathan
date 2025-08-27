#pragma once
#include "rft_global_cpp.hh"

#pragma region Domino
#define NMax_dom 100

static struct Dom
{
    int first, last;
} j[NMax_dom];
static int n_dom, wmax_dom;
static int l_dom[NMax_dom], lmax_dom[NMax_dom], used_dom[NMax_dom];
static void read_dom();
static void print_dom();
static void buildchain_dom(int);

static void domino()
{
    read_dom();

    for (int i = 1; i <= n_dom; i++)
    {
        l_dom[1] = i;
        used_dom[i] = 1;
        buildchain_dom(2);
        used_dom[i] = 0;
    }

    print_dom();
}

static void read_dom()
{
    std::ifstream fin("RftConstruct/Domino.in");
    fin >> n_dom;

    for (int i = 1; i <= n_dom; i++)
    {
        fin >> j[i].first >> j[i].last;
    }

    fin.close();
}

static void print_dom()
{
    std::cout << "Longest chain with the following pieces ";

    for (int i = 1; i <= wmax_dom; i++)
    {
        std::cout << lmax_dom[i] << ' ';
    }
}

static void buildchain(int k)
{
    int extend = 0;

    for (int i = 1; i <= n_dom; i++)
    {
        if (!used_dom[i])
        {
            if (j[i].last == j[l_dom[k - 1]].last)
            {
                int aux = j[i].first;
                j[i].first = j[i].last;
                j[i].last = aux;
            }

            if (j[i].first == j[l_dom[k - 1]].last)
            {
                l_dom[k] = i;
                used_dom[i] = 1;
                extend = 1;
                buildchain_dom(k + 1);
                used_dom[i] = 0;
            }
        }
    }

    if (!extend)
    {
        if (k - 1 > wmax_dom)
        {
            wmax_dom = k - 1;

            for (int i = 0; i <= wmax_dom; i++)
            {
                lmax_dom[i] = l_dom[i];
            }
        }
    }
}
#pragma endregion

#pragma region Packets
#define NMax_pack 100

static std::ifstream fin_pack("RftConstruct/Packets.in");
static std::ofstream fout_pack("RftConstruct/Packets.out");
static int inst_pack[NMax_pack], d_pack[NMax_pack], min_pack[NMax_pack];

static void packets()
{
    int n, i;
    fin_pack >> n;

    for (i = 0; i < n; i++)
    {
        fin_pack >> inst_pack[i] >> d_pack[i];
    }

    fin_pack.close();

    min_pack[n - 1] = d_pack[n - 1];

    for (i = n - 2; i >= 0; i--)
    {
        min_pack[i] = d_pack[i] + std::max(0, min_pack[i + 1] - inst_pack[i]);
    }

    fout_pack << min_pack[0];
    fout_pack.close();
}
#pragma endregion

static struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

static ListNode *buildListNodeFromVectorInt(std::vector<int> v)
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
