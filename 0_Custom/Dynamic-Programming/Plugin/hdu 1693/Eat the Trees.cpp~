#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
#define MAXN (12)
#define MAXS (1 << MAXN)
#define LLU __int64
#define Rep(c, a, b) for(int c = a; c < b; c++)
#define Clr(a, b, c) fill(a, a + b, c)
#define Get(x, y) ((x >> y) & 1)
#define LR(x) (1 << x)

int n, m, ei, ej, M[MAXN][MAXN];

struct State
{
    LLU s, c;
} ts;

struct Hash
{
    int hash[MAXS];
    int t;
    vector<State> S[2];
    State th;
    void ini()
    {
        t = 0;
        th.s = 0; th.c = 1;
        S[0].clear();
        S[1].clear();
        Clr(hash, MAXS, -1);
        S[t].push_back(th);
    }
    void rot() { t ^= 1; }
    int siz() { return S[t].size(); }
    void clr()
    {
        S[!t].clear();
        Clr(hash, MAXS, -1);
    }
    void ins(LLU x, LLU add)
    {
        if (hash[x] == -1)
        {
            hash[x] = S[!t].size();
            th.s = x; th.c = add;
            S[!t].push_back(th);
        }
        else S[!t][hash[x]].c += add;
    }
    void mov()
    {
        Rep(i, 0, S[t].size())
            S[t][i].s <<= 1;
    }
    State pop()
    {
        th = S[t][S[t].size() - 1];
        S[t].pop_back();
        return th;
    }
} H;

LLU PDP()
{
    LLU l, u, li, ui, res = 0;

    H.ini();
    Rep(i, 0, n)
    {
        li = 0; ui = 1;
        Rep(j, 0, m)
        {
            H.clr();
            while (H.siz())
            {
                ts = H.pop();
                l = Get(ts.s, li);
                u = Get(ts.s, ui);
                if (!M[i][j] && !l && !u) H.ins(ts.s, ts.c);
                else
                {
                    if (!l && !u) //00->11
                    {
                        if (i + 1 < n && j + 1 < m && M[i + 1][j] && M[i][j + 1])
                            H.ins(ts.s + LR(li) + LR(ui), ts.c);
                    }
                    else if (l && !u)
                    {
                        if (i + 1 < n && M[i + 1][j]) //10->10
                            H.ins(ts.s, ts.c);
                        if (j + 1 < m && M[i][j + 1]) //10->01
                            H.ins(ts.s - LR(li) + LR(ui), ts.c);
                    }
                    else if (!l && u)
                    {
                        if (j + 1 < m && M[i][j + 1]) //01->01
                            H.ins(ts.s, ts.c);
                        if (i + 1 < n && M[i + 1][j]) //01->10
                            H.ins(ts.s - LR(ui) + LR(li), ts.c);
                    }
                    else if (l && u)
                    {
                        if (ei == i && ej == j)
                            res += ts.c;
                        H.ins(ts.s - LR(li) - LR(ui), ts.c);
                    }
                }
            }
            li++; ui++;
            H.rot();
        }
        H.mov();
    }
    return res;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("test.txt", "rt", stdin);
#endif
    int T;

    scanf("%d", &T);
    Rep(C, 0, T)
    {
        scanf("%d%d", &n, &m);
        Rep(i, 0, n) Rep(j, 0, m)
        {
            scanf("%d", M[i] + j);
            if (M[i][j])
            {
                ei = i; ej = j;
            }
        }
        printf("Case %d: There are %I64d ways to eat the trees.\n", C + 1, PDP());
    }

    return 0;
}
