#pragma once
#include "rft_global_cpp.hh"

#pragma region City Drive
#define NMax_cd 101
#define MMax_cd 500
#define TMax_cd 101
#define oo_cd 300000000

static int n_cd, m_cd, a_cd, b_cd, tf_cd;
static std::fstream fin_cd("RftConstruct/CityDrive.in");
static std::fstream fout_cd("RftConstruct/CityDrive.out");
static int p_cd[NMax_cd], mad_cd[NMax_cd][NMax_cd], w_cd[MMax_cd], cost_cd[MMax_cd][TMax_cd], cmin_cd[NMax_cd][TMax_cd];
static void read_cd();
static void solve_cd();
static void print_cd();

static void cityDrive()
{
    read_cd();
    solve_cd();
    print_cd();
}

static void read_cd()
{
    int i, j, o1, o2, l;
    fin_cd >> n_cd >> m_cd;
    fin_cd >> a_cd >> b_cd >> tf_cd;
    a_cd--;
    b_cd--;

    for (i = 0; i < n_cd; i++)
    {
        for (j = 0; j < n_cd; j++)
        {
            mad_cd[i][j] = -1;
        }
    }

    for (i = 0; i < n_cd; i++)
    {
        fin_cd >> p_cd[i];
    }

    p_cd[a_cd] = p_cd[b_cd] = 0;

    for (i = 0; i < m_cd; i++)
    {
        fin_cd >> o1 >> o2 >> l;
        mad_cd[o1 - 1][o2 - 1] = mad_cd[o2 - 1][o1 - 1] = i;
        w_cd[i] = l;

        for (j = 0; j < tf_cd; j++)
        {
            fin_cd >> cost_cd[i][j];
        }
    }

    fin_cd.close();
}

static void solve_cd()
{
    int i, j, k, l, lm, m;

    for (i = 0; i < n_cd; i++)
    {
        for (j = 0; j < tf_cd; j++)
        {
            cmin_cd[i][j] = -1;
        }
    }

    cmin_cd[a_cd][0] = 0;

    for (i = 1; i <= tf_cd; i++)
    {
        for (j = 0; j < n_cd; j++)
        {
            cmin_cd[j][i] = oo_cd;

            for (k = 0; k < i; k++)
            {
                for (l = 0; l < n_cd; l++)
                {
                    if (cmin_cd[l][k] == -1)
                        continue;

                    if (mad_cd[j][l] == -1)
                        continue;

                    lm = w_cd[mad_cd[j][l]];

                    if (lm > i - k)
                        continue;

                    m = cmin_cd[l][k] + cost_cd[mad_cd[j][l]][i - lm] * lm + p_cd[l] * (i - k - lm);

                    if (m < cmin_cd[j][i])
                        cmin_cd[j][i] = m;
                }
            }

            if (cmin_cd[j][i] == oo_cd)
                cmin_cd[j][i] = -1;
        }
    }
}

static void print_cd()
{
    int j, min = oo_cd;

    for (j = 0; j <= tf_cd; j++)
    {
        if (cmin_cd[b_cd][j] != -1 && cmin_cd[b_cd][j] < min)
            min = cmin_cd[b_cd][j];
    }

    fout_cd << min;
    fout_cd.close();
}
#pragma endregion

#pragma region Dijkstra
#define NMaxV_dij 50
#define Inf_dij 10000

static int n_dij, x0_dij;
static double c1_dij[NMaxV_dij][NMaxV_dij];
static int pre_dij[NMaxV_dij], m1_dij[NMaxV_dij];
static double d_dij[NMaxV_dij];
static void read_dij();
static void print_dij();

static void dijkstra()
{
    int i, vmin{}, j;
    double dmin;
    read_dij();

    for (j = 1; j < n_dij; j++)
    {
        dmin = Inf_dij;

        for (i = 1; i <= n_dij; i++)
        {
            if (!m1_dij[i] && dmin > d_dij[i])
            {
                dmin = d_dij[i];
                vmin = i;
            }
        }

        m1_dij[vmin] = 1;

        for (i = 1; i <= n_dij; i++)
        {
            if (!m1_dij[i] && d_dij[i] > dmin + c1_dij[vmin][i])
            {
                pre_dij[i] = vmin;
                d_dij[i] = dmin + c1_dij[vmin][i];
            }
        }
    }

    print_dij();
}

static void read_dij()
{
    int i, j, m, x, y;
    double c;
    std::ifstream fin("RftConstruct/Dijkstra.in");
    fin >> n_dij >> m >> x0_dij;

    for (i = 1; i <= n_dij; i++)
    {
        for (j = i + 1; j <= n_dij; j++)
        {
            c1_dij[j][i] = c1_dij[i][j] = Inf_dij;
        }
    }

    for (i = 1; i <= m; i++)
    {
        fin >> x >> y >> c;
        c1_dij[x][y] = c;
    }

    for (i = 1; i <= n_dij; i++)
    {
        d_dij[i] = c1_dij[x0_dij][i];
        pre_dij[i] = x0_dij;
    }

    m1_dij[x0_dij] = 1;
    pre_dij[x0_dij] = 0;
    fin.close();
}

static void print_dij()
{
    int i, j, lg, dr[NMaxV]{};

    for (i = 1; i <= n_dij; i++)
    {
        if (i != x0_dij)
        {
            std::cout << "Cost of the minimal cost path " << x0_dij << " at " << i << " is " << d_dij[i] << "\n";
            std::cout << "Minimal cost path:";
            dr[0] = i;
            lg = 0;

            while (pre_dij[dr[lg]])
            {
                lg++;
                dr[lg] = pre_dij[dr[lg - 1]];
            }

            for (j = lg; j >= 0; j--)
            {
                std::cout << ' ' << dr[j];
            }

            std::cout << "\n";
        }
    }
}
#pragma endregion

#pragma region GrayCode
#define NMax_gc 10
#define NrMaxS (1 << NMax_gc)

static int n_gc, C_gc[NrMaxS][NMax];
static void print_gc();
static void generator_gc(int);

static void grayCode()
{
    std::cout << "n = ";
    std::cin >> n;
    generator_gc(n);
    print_gc();
}

static void generator_gc(int x)
{
    if (x == 1)
        C_gc[1][0] = 1;
    else
    {
        generator_gc(x - 1);

        for (int i = (1 << (x - 1)) - 1; i >= 0; i--)
        {
            for (int j = 0; j < x - 1; j++)
            {
                C_gc[(1 << x) - i - 1][j] = C_gc[i][j];
            }

            C_gc[(1 << x) - i - 1][x - 1] = 1;
        }
    }
}

static void print_gc()
{
    std::ofstream f("RftConstruct/Gray.out");

    for (int i = 0; i < 1 << n_gc; i++)
    {
        for (int j = 0; j < n_gc; j++)
        {
            f << C_gc[i][j];
        }

        f << "\n";
    }

    f.close();
}
#pragma endregion

#pragma region Kosaraju
#define NMax_kos 101

static int n_kos, nr_kos, nrc_kos;
static int *a_kos[NMax_kos], *at_kos[NMax_kos];
static int post_kos[NMax_kos], visited_kos[NMax_kos];
static std::ifstream fin_kos("RftConstruct/KosarajuSharir.in");
static void read_kos();
static void dfst_kos(int);
static void dfs_kos(int);

static void kosarajuSharir()
{
    int i;
    read_kos();

    for (i = 1; i <= n_kos; i++)
    {
        if (!visited_kos[i])
            dfs_kos(i);
    }

    for (i = n_kos; i > 0; i--)
    {
        if (visited_kos[post_kos[i]])
        {
            std::cout << "Strongly connected component: " << ++nrc_kos;
            dfst_kos(post_kos[i]);
            std::cout << "\n";
        }
    }
}

static void read_kos()
{
    int x, y, m, i;
    fin_kos >> n_kos >> m;

    for (i = 1; i <= n_kos; i++)
    {
        a_kos[i] = (int *)realloc(a_kos[i], sizeof(int));
        a_kos[i][0] = 0;
        at_kos[i] = (int *)realloc(at_kos[i], sizeof(int));
        at_kos[i][0] = 0;
    }

    for (i = 0; i < m; i++)
    {
        fin_kos >> x >> y;
        a_kos[x][0]++;
        a_kos[x] = (int *)realloc(a_kos[x], (a_kos[x][0] + 1) * sizeof(int));
        a_kos[x][a_kos[x][0]] = y;
        at_kos[y][0]++;
        at_kos[y] = (int *)realloc(at_kos[y], (at_kos[y][0] + 1) * sizeof(int));
        at_kos[y][at_kos[y][0]] = x;
    }
}

static void dfst_kos(int x)
{
    int i;
    visited_kos[x] = 0;
    std::cout << x;

    for (i = 1; i <= at_kos[x][0]; i++)
    {
        if (visited_kos[at_kos[x][i]])
            dfst_kos(at_kos[x][i]);
    }
}

static void dfs_kos(int x)
{
    int i;
    visited_kos[x] = 1;

    for (i = 1; i <= a_kos[x][0]; i++)
    {
        if (!visited_kos[a_kos[x][i]])
            dfs_kos(a_kos[x][i]);
    }

    post_kos[++nr_kos] = x;
}
#pragma endregion

#pragma region Level Graph
#define NMax_lg 101

static int n_lg, a_lg[NMax_lg][NMax_lg];
static int np_lg[NMax_lg], level_lg[NMax_lg];
static void read_lg();

static void levelGraphs()
{
    int i, j, total = 0, nlevel = 0;
    read_lg();

    while (total < n_lg)
    {
        std::cout << "Level " << ++nlevel << ":";

        for (i = 1; i <= n_lg; i++)
        {
            if (!np_lg[i])
            {
                level_lg[i] = nlevel;
                std::cout << " " << i;
                total++;
            }
        }

        std::cout << "\n";

        for (i = 1; i <= n_lg; i++)
        {
            if (level_lg[i] == nlevel)
            {
                np_lg[i] = -1;

                for (j = 1; j <= a_lg[i][0]; j++)
                {
                    np_lg[a_lg[i][j]]--;
                }
            }
        }
    }
}

static void read_lg()
{
    std::fstream fin("RftConstruct/LevelGraphs.in");
    int x, y, m, i;
    fin >> n_lg >> m;

    for (i = 0; i < m; i++)
    {
        fin >> x >> y;
        a_lg[x][0]++;
        a_lg[x][a_lg[x][0]] = y;
        np_lg[y]++;
    }
}
#pragma endregion

#pragma region Mailman
#define NCities 20

static float a_mail[NCities][NCities];
static int n_mail;
static int t_mail[NCities], tmin_mail[NCities], v_mail[NCities];
static float w_mail, wmin_mail, inf_mail;
static void read_mail();
static float geninf_mail();
static void print_mail();
static void buildpath_mail(int);

static void mailman()
{
    read_mail();
    t_mail[1] = v_mail[1] = 1;
    wmin_mail = inf_mail = geninf_mail();
    buildpath_mail(2);
    print_mail();
}

static void read_mail()
{
    std::ifstream fin("RftConstruct/Mailman.in");
    int i, j;
    float d;
    fin >> n_mail;

    while (!fin.eof())
    {
        fin >> i >> j >> d;
        a_mail[i][j] = a_mail[j][i] = d;
    }

    fin.close();
}

static float geninf_mail()
{
    float s = 0;

    for (int i = 1; i <= n_mail; i++)
    {
        for (int j = 1; j <= n_mail; j++)
        {
            s += a_mail[i][j];
        }
    }

    return s + 1;
}

static void print_mail()
{
    if (wmin_mail == inf_mail)
        std::cout << "No solutions\n";
    else
    {
        std::cout << "Length of shortest path = ";
        std::cout << std::setprecision(10) << wmin_mail << "\n";
        std::cout << "Path = ";

        for (int i = 1; i <= n_mail; i++)
        {
            std::cout << tmin_mail[i] << ',';
        }

        std::cout << tmin_mail[1] << "\n";
    }
}

static void buildpath_mail(int k)
{
    if (k - 1 == n_mail)
    {
        if (a_mail[1][t_mail[n_mail]])
        {
            if (w_mail + a_mail[1][t_mail[n_mail]] < wmin_mail)
            {
                for (int i = 1; i <= n_mail; i++)
                {
                    tmin_mail[i] = t_mail[i];
                }

                wmin_mail = w_mail + a_mail[1][t_mail[n_mail]];
            }
            else
            {
            }
        }
        else
        {
        }
    }
    else
    {
        for (int i = 2; i <= n_mail; i++)
        {
            if (a_mail[i][t_mail[k - 1]] && !v_mail[i])
            {
                t_mail[k] = i;
                v_mail[i] = 1;
                w_mail += a_mail[i][t_mail[k - 1]];

                if (w_mail <= wmin_mail)
                    buildpath_mail(k + 1);

                v_mail[i] = 0;
                w_mail -= a_mail[i][t_mail[k - 1]];
            }
        }
    }
}
#pragma endregion

#pragma region Monk And Rotation
static int a_mr[100000]{};

static void monkAndRotation()
{
    int t1 = 1;
    int n1 = 5;
    int k1 = 2;
    int a1[] = {1, 2, 3, 4, 5};
    int t, n, k;
    t = t1;

    for (int i = 0; i < t; i++)
    {
        n = n1;
        k = k1;
        int m = 0;

        if (n < k)
            m = k % n;
        else
            m = k;

        for (int j = 0; j < n; j++)
        {
            a_mr[j] = a1[j];
        }

        for (int j = n - m; j < n; j++)
        {
            std::cout << a_mr[j] << ' ';
        }

        for (int j = 0; j < n - m; j++)
        {
            std::cout << a_mr[j] << ' ';
        }

        std::cout << "\n";
    }
}
#pragma endregion

#pragma region Non Attacking Queens
static int n_naq, nsol_naq, c_naq[30];
static void print_naq();
static void placeQueen_naq(int);

static void nonAttackingQueens()
{
    std::cout << "n = ";
    std::cin >> n;
    placeQueen_naq(0);
}

static void print_naq()
{
    int i, j;
    std::cout << "Solution nr: " << ++nsol_naq << "\n";

    for (i = 0; i < n_naq; i++)
    {
        for (j = 0; j < n_naq; j++)
        {
            if (j == c_naq[i])
                std::cout << " * ";
            else
                std::cout << " o ";
        }

        std::cout << "\n";
        std::cin.get();
    }
}

static void placeQueen_naq(int k)
{
    int i, j, ok;

    if (k == n_naq)
        print_naq();
    else
    {
        for (i = 0; i < n_naq; i++)
        {
            for (ok = 1, j = 0; j < k; j++)
            {
                if (c_naq[j] == i || abs(c_naq[j] - i) == (k - j))
                    ok = 0;
            }

            if (ok)
            {
                c_naq[k] = i;
                placeQueen_naq(k + 1);
            }
        }
    }
}
#pragma endregion
