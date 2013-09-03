#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
#define Rep(c, a, b, d) for (int c = a; c < b; c += d)
#define Clr(c, a, b) fill(c, c + a, b)
#define LLU long long
#define MAXN (8)
#define MAXS (1 << 18)
#define Get(x, y) ((x >> y) & 3)
#define LR(x, y) (x << y)

int n, m, si, sj, ei, ej;
char M[MAXN][MAXN];

struct State
{
    LLU s, c;
};

struct RA
{
    State ts;
    int t, hash[MAXS];
    vector<State> S[2];
    void ini()
    {
        t = 0;
        ts.s = 0;
        ts.c = 1;
        S[0].clear();
        S[1].clear();
        S[0].push_back(ts);
        Clr(hash, MAXS, -1);
    }
    void clr()
    {
        Clr(hash, MAXS, -1);
        S[!t].clear();
    }
    void rot()
    {
        t ^= 1;
    }
    int siz()
    {
        return S[t].size();
    }
    void ins(LLU x, LLU add)
    {
        LLU key = x % MAXS;
        if (hash[key] > 0)
        {
            S[!t][hash[key]].c += add;
            return ;
        }
        hash[key] = S[!t].size();
        ts.s = x; ts.c = add;
        S[!t].push_back(ts);
    }
    State pop()
    {
        ts = S[t][S[t].size() - 1];
        S[t].pop_back();
        return ts;
    }
    void mov(int d)
    {
        Rep(i, 0, S[t].size(), 1)
            S[t][i].s <<= d;
    }
    LLU que()
    {
        LLU res = 0;
        Rep(i, 0, S[t].size(), 1)
            res += S[t][i].c;
        return res;
    }
} H;

int fin(LLU x, int i, bool np)
{
    int tp, b = 1, p = 1, d = 2;
    if (np) swap(p, d);
    while (b)
    {
        if (np) i -= 2;
        else i += 2;
        tp = Get(x, i);
        if (tp == p) b++;
        if (tp == d) b--;
    }
    return i;
}

bool jud(int x, int y)
{
    return  -1 < x && x < n && -1 < y && y < m && M[x][y] == '.';
}

LLU PDP()
{
    State ts;
    int l, u, li, ui, tb;
    H.ini();
    Rep(i, 0, n, 1)
    {
        li = 0; ui = 2;
        Rep(j, 0, m, 1)
        {
            H.clr();
            while (H.siz())
            {
                ts = H.pop();
                l = Get(ts.s, li);
                u = Get(ts.s, ui);
                if (M[i][j] == '#')
                {
                    if (!l && !u)
                        H.ins(ts.s, ts.c);
                    continue;
                }
                if (i == si && j == sj)
                {
                    if (u == 1)
                        H.ins(ts.s - LR(1, ui), ts.c);
                    else if (!u && jud(i, j + 1))
                        H.ins(ts.s + LR(1, ui), ts.c);
                    continue;
                }
                if (i == ei && j == ej)
                {
                    if ((l && !u) ||
                        (!l && u))
                        H.ins(ts.s - LR(l, li) - LR(u, ui), ts.c);
                    continue;
                }
                ts.s -= LR(l, li) + LR(u, ui);
                if (!l && !u && jud(i, j + 1) && jud(i + 1, j))
                    H.ins(ts.s + LR(1, li) + LR(2, ui), ts.c);
                else if ((l && !u) || (!l && u))
                {
                    if (jud(i, j + 1))
                        H.ins(ts.s + LR((l | u), ui), ts.c);
                    if (jud(i + 1, j))
                        H.ins(ts.s + LR((l | u), li), ts.c);
                }
                else if (l && u)
                {
                    if (l == 1 && u == 1)
                    {
                        H.ins(ts.s - LR(1, fin(ts.s, ui, false)), ts.c);
                    }
                    if (l == 2 && u == 2)
                    {
                        H.ins(ts.s + LR(1, fin(ts.s, li, true)), ts.c);
                    }
                    if (l == 2 && u == 1)
                        H.ins(ts.s, ts.c);
                }
            }//while
            li += 2; ui += 2;
            H.rot();
        }//J
        H.mov(2);
    }//I
    return H.que();
}

int main()
{
    #if 0
        freopen("test.txt", "rt", stdin);
    #endif
    while (~scanf("%d%d", &n, &m), n || m)
    {
        Rep(i, 0, n, 1) scanf("%s", M[i]);
        si = n - 1; sj = 0;
        ei = n - 1; ej = m - 1;
        printf("%lld\n", PDP());
    }

    return 0;
}
