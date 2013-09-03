#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Clr(c, a, b) fill(c, c + a, b)
#define LLU int
#define MAXN (10)
#define INFI ((1 << 31) - 1)
#define MAXS (3007)
#define Get(x, y) ((x >> y) & 3)
#define LR(x, y) (x << y)

int n, m;
int M[MAXN][MAXN];

struct State
{
    LLU s, c;
};

struct RA
{
    int t;
    State ts;
    vector<State> S[2];
    vector<int> hash[MAXS];
    void ini()
    {
        t = 0;
        ts.s = 0;
        ts.c = 0;
        S[0].clear();
        S[1].clear();
        Rep(i, 0, MAXS)
            hash[i].clear();
        S[0].push_back(ts);
    }
    void rot() { t ^= 1; }
    void clr()
    {
        Rep(i, 0, MAXS)
            hash[i].clear();
        S[!t].clear();
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
    void ins(LLU x, LLU add)
    {
        LLU key = x % MAXS;
        Rep(i, 0, hash[key].size())
            if (S[!t][hash[key][i]].s == x)
            {
                if (S[!t][hash[key][i]].c < add)
                    S[!t][hash[key][i]].c = add;
                return ;
            }
        ts.s = x; ts.c = add;
        hash[key].push_back(S[!t].size());
        S[!t].push_back(ts);
    }
    void mov(int d)
    {
        Rep(i, 0, S[t].size())
            S[t][i].s <<= d;
    }
    LLU que()
    {
        LLU res = -INFI;
        #if 0
            printf("INFI = %d\n", res);
        #endif
        Rep(i, 0, S[t].size())
            if (res < S[t][i].c)
                res = S[t][i].c;
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
    return  -1 < x && x < n && -1 < y && y < m;
}

LLU PDP()
{
    State ts;
    int l, u, li, ui, tb;
    H.ini();
    Rep(i, 0, n)
    {
        li = 0; ui = 2;
        Rep(j, 0, m)
        {
            H.clr();
            #if 0
                printf("[%d, %d] : size = %d\n", i, j, H.siz());
            #endif
            while (H.siz())
            {
                ts = H.pop();
                l = Get(ts.s, li);
                u = Get(ts.s, ui);
                ts.c += M[i][j];
                ts.s -= LR(l, li) + LR(u, ui);
                #if 0
                    printf("    l = %d u = %d\n", l, u);
                #endif
                if (n == m && n == 1)
                    H.ins(ts.s, ts.c);
                if (i == 0 && j == 0)
                {
                    if (jud(i, j + 1))
                        H.ins(ts.s + LR(1, ui), ts.c);
                    if (jud(i + 1, j))
                        H.ins(ts.s + LR(1, li), ts.c);
                }
                else if (i == n - 1 && j == m - 1)
                {
                    if ((l && !u) || (!l && u))
                        H.ins(ts.s, ts.c);
                }
                else if (!l && !u)
                {
                    H.ins(ts.s, ts.c - M[i][j]);
                    if (jud(i, j + 1) && jud(i + 1, j))
                        H.ins(ts.s + LR(1, li) + LR(2, ui), ts.c);
                }
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
                        H.ins(ts.s - LR(1, fin(ts.s, ui, false)), ts.c);
                    if (l == 2 && u == 2)
                        H.ins(ts.s + LR(1, fin(ts.s, li, true)), ts.c);
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
    #ifndef ONLINE_JUDGE
        freopen("test.txt", "rt", stdin);
    #endif
    int C = 1;

    while (~scanf("%d%d", &n, &m))
    {
        Rep(i, 0, n) Rep(j, 0, m)
            scanf("%d", M[i] + j);
        printf("Case %d: %d\n", C++, PDP());
    }

    return 0;
}
