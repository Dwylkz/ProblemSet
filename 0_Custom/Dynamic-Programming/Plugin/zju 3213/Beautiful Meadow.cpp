#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
#define LLU int
#define MAXN (8)
#define MAXS (30007)
#define GET(x, y) (((x) >> (y)) & 3)
#define INS(x, y) ((x) << (y))

int n, m, M[MAXN][MAXN];

struct State
{
    LLU s, c;
};

struct RA
{
    State ts;
    vector<int> hash[MAXS];
    vector<State> S[2];
    int t;
    void ini()
    {
        int i;
        t = 0;
        S[0].clear();
        S[1].clear();
        for (i = 0; i < MAXS; i++)
            hash[i].clear();
        ts.s = 0;
        ts.c = 0;
        S[0].push_back(ts);
    }
    void clr()
    {
        int i;
        for (i = 0; i < MAXS; i++)
            hash[i].clear();
        S[!t].clear();
    }
    void rot()
    {
        t ^= 1;
    }
    void mov(int d)
    {
        int i;
        for (i = 0; i < S[t].size(); i++)
            S[t][i].s <<= d;
    }
    int siz()
    {
        return S[t].size();
    }
    State pop()
    {
        ts = S[t][S[t].size() - 1];
        S[t].pop_back();
        return ts;
    }
    LLU res()
    {
        int i;
        LLU maxi = 0;
        for (i = 0; i < S[t].size(); i++)
            if (S[t][i].c > maxi)
                maxi = S[t][i].c;
        return maxi;
    }
    void ins(LLU x, LLU add)
    {
        int i;
        LLU key = x % MAXS;
        for (i = 0; i < hash[key].size(); i++)
            if (S[!t][hash[key][i]].s == x)
            {
                if (S[!t][hash[key][i]].c < add)
                    S[!t][hash[key][i]].c = add;
                return ;
            }
        ts.s = x;
        ts.c = add;
        hash[key].push_back(S[!t].size());
        S[!t].push_back(ts);
    }
} H;

int fin(LLU x, int i, bool lr)
{
    int tp, b = 1, p = 1, d = 2;
    if (lr) swap(p, d);
    while (b)
    {
        if (lr) i -= 2;
        else i += 2;
        tp = GET(x, i);
        if (tp == p) b++;
        if (tp == d) b--;
    }
    return i;
}

int csp(LLU x)
{
    int tsu = 0;
    while (x && tsu < 2)
    {
        if (GET(x, 0) == 3)
            tsu++;
        x >>= 2;
    }
    return tsu;
}

bool jud(int x, int y)
{
    return -1 < x && x < n && -1 < y && y < m && M[x][y];
}

LLU PDP()
{
    State ts;
    int tp, i, j, l, u, li, ui;
    LLU res = 0;
    bool bd, br;

    H.ini();
    for (i = 0; i < n; i++)
    {
        li = 0;
        ui = 2;
        for (j = 0; j < m; j++)
        {
            H.clr();
            if (M[i][j] > res) res = M[i][j];
            while (H.siz())
            {
                ts = H.pop();
                if (!M[i][j])
                {
                    H.ins(ts.s, ts.c);
                    continue;
                }
                l = GET(ts.s, li);
                u = GET(ts.s, ui);
                tp = csp(ts.s);
                bd = jud(i + 1, j);
                br = jud(i, j + 1);
                ts.s -= (INS(l, li) | INS(u, ui));
                ts.c += M[i][j];
                if (!l && !u)
                {
                    H.ins(ts.s, ts.c - M[i][j]);
                    if (bd && br)
                        H.ins(ts.s | INS(1, li) | INS(2, ui), ts.c);
                    if (bd && tp < 2)
                        H.ins(ts.s | INS(3, li), ts.c);
                    if (br && tp < 2)
                        H.ins(ts.s | INS(3, ui), ts.c);
                }
                else if (!l || !u)
                {
                    if (bd) H.ins(ts.s | INS(l | u, li), ts.c);
                    if (br) H.ins(ts.s | INS(l | u, ui), ts.c);
                    if ((l | u) < 3 && tp < 2)
                        H.ins(ts.s | INS(3, fin(ts.s, (l | u) == 1? ui: li, (l | u) == 1? false: true)), ts.c);
                    if ((l | u) == 3 && tp == 1 && res < ts.c) res = ts.c;
                }
                else if (l && u)
                {
                    if (l == 1 && u == 1)
                        H.ins(ts.s - INS(1, fin(ts.s, ui, false)), ts.c);
                    if (l == 2 && u == 2)
                        H.ins(ts.s + INS(1, fin(ts.s, li, true)), ts.c);
                    if (l == 2 && u == 1)
                        H.ins(ts.s, ts.c);
                    if ((l == 3 && u != 3) || (l != 3 && u == 3))
                        H.ins(ts.s | INS(3, fin(ts.s, l + u == 4? ui: li, l + u == 4? false: true)), ts.c);
                    if (l == 3 && u == 3 && tp == 2 && res < ts.c) res = ts.c;

                }
            }//while
            li += 2;
            ui += 2;
            H.rot();
        }//J
        H.mov(2);
    }//I
    return res;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("test.txt", "rt", stdin);
    #endif
    int T, i, j;

    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++)
                scanf("%d", M[i] + j);
        printf("%d\n", PDP());
    }

    return 0;
}
