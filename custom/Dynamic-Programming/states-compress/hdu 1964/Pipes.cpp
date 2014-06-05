#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
#define Rep(c, a, b, d) for (int c = a; c < b; c += d)
#define Clr(c, a, b) fill(c, c + a, b)
#define LLU int
#define MAXN (10)
#define MAXS (707)
#define LR(x, y) ((x) << (y))
#define Get(x, y) (((x) >> (y)) & 3)

int n, m;
char Buf[2 * MAXN + 1][2 * MAXN + 2];
int M[MAXN][MAXN][2];

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
        t = 0;
        S[0].clear();
        S[1].clear();
        Rep(i, 0, MAXS, 1)
            hash[i].clear();
        ts.s = 0;
        ts.c = 0;
        S[0].push_back(ts);
    }
    void clr()
    {
        Rep(i, 0, MAXS, 1)
            hash[i].clear();
        S[!t].clear();
    }
    void ins(LLU x, LLU add)
    {
        LLU key = x % MAXS;
        Rep(i, 0, hash[key].size(), 1)
            if (S[!t][hash[key][i]].s == x)
            {
                if (S[!t][hash[key][i]].c > add)
                    S[!t][hash[key][i]].c = add;
                return ;
            }
        hash[key].push_back(S[!t].size());
        ts.s = x;
        ts.c = add;
        S[!t].push_back(ts);
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
    void rot()
    {
        t ^= 1;
    }
    void mov(int d)
    {
        Rep(i, 0, S[t].size(), 1)
            S[t][i].s <<= d;
    }
    LLU que()
    {
        ts.c = S[t][0].c;
        Rep(i, 1, S[t].size(), 1)
            if (S[t][i].c < ts.c)
                ts.c = S[t][i].c;
        return ts.c;
    }
} H;

int fin(LLU x, int i, bool np)
{
    int b = 1, p = 1, d = 2, tp;
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

LLU PDP()
{
    State ts;
    int l, u, li, ui, cd, cr;

    H.ini();
    Rep(i, 0, n, 1)
    {
        li = 0;
        ui = 2;
        Rep(j, 0, m, 1)
        {
            H.clr();
            cr = M[i][j][0];
            cd = M[i][j][1];
            while (H.siz())
            {
                ts = H.pop();
                l = Get(ts.s, li);
                u = Get(ts.s, ui);
                ts.s -= LR(l, li) + LR(u, ui);
                if (!l && !u)
                {
                    if (cd > -1 && cr > -1)
                        H.ins(ts.s | LR(1, li) | LR(2, ui), ts.c + cd + cr);
                }
                else if ((l && !u) || (!l && u))
                {
                    if (cd > -1)
                        H.ins(ts.s + LR(l | u, li), ts.c + cd);
                    if (cr > -1)
                        H.ins(ts.s + LR(l | u, ui), ts.c + cr);
                }
                else if (l && u)
                {
                    if (l == 1 && u == 2)
                    {
                        if (i == n - 1 && j == m - 1)
                            H.ins(ts.s, ts.c);
                    }
                    if (l == 2 && u == 1)
                        H.ins(ts.s, ts.c);
                    if (l == 1 && u == 1)
                        H.ins(ts.s - LR(1, fin(ts.s, ui, false)), ts.c);
                    if (l == 2 && u == 2)
                        H.ins(ts.s + LR(1, fin(ts.s, li, true)), ts.c);
                }
            }//while
            li += 2;
            ui += 2;
            H.rot();
        }//J
        H.mov(2);
    }//I
    return H.que();
}

int main()
{
    int T;
    #if 0
        freopen("test.txt", "rt", stdin);
    #endif
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d\n", &n, &m);
        Rep(i, 0, 2 * n + 1, 1)
            gets(Buf[i]);
        Rep(i, 0, n, 1) Rep(j, 0, m, 1)
            M[i][j][0] = M[i][j][1] = -1;
        Rep(i, 1, 2 * n, 1)
        {
            Rep(j, 2, 2 * m, 2)
                M[i >> 1][(j >> 1) - 1][0] = Buf[i][j] - '0';
            if (++i == 2 * n) break;
            Rep(j, 1, 2 * m, 2)
                M[(i >> 1) - 1][j >> 1][1] = Buf[i][j] - '0';
        }
        printf("%d\n", PDP());
    }

    return 0;
}
