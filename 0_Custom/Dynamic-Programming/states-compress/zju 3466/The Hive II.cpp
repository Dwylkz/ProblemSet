#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
#define LLU unsigned long long
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define Clr(c, a, b) fill(c, c + a, b)
#define MAXN (8)
#define MAXM (11)
#define MAXS (1 << 13)
#define Get(x, y) ((x >> y) & 1)
#define LR(x, y) (x << y)

int n, m, ei, ej;
bool M[MAXN][MAXM];

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
        ts.c = 1;
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
                S[!t][hash[key][i]].c += add;
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
        LLU res = 0;
        Rep(i, 0, S[t].size())
            res += S[t][i].c;
        return res;
    }
} H;

bool jud(int x, int y)
{
    return -1 < x && x < 8 && -1 < y && y < n && M[x][y];
}

LLU PDP()
{
    int l, ul, ur, li, uli, uri, bl, br;
    State ts;
    H.ini();
    bl = 0; br = 1;
    Rep(i, 0, 8)
    {
        li = 0; uli = 1; uri = 2;
        Rep(j, 0, n)
        {
            H.clr();
            while (H.siz())
            {
                ts = H.pop();
                l = Get(ts.s, li);
                ul = Get(ts.s, uli);
                ur = Get(ts.s, uri);
                if (!M[i][j])
                {
                    if (!l && !ul && !ur)
                        H.ins(ts.s, ts.c);
                    continue;
                }
                ts.s -= LR(l, li) + LR(ul, uli) + LR(ur, uri);
                if ((l && ul && !ur) ||
                    (l && !ul && ur) ||
                    (!l && ul && ur))
                    H.ins(ts.s, ts.c);
                else if ((l && !ul && !ur) ||
                         (!l && ul && !ur) ||
                         (!l && !ul && ur))
                {
                    if (jud(i + 1, j + bl))
                        H.ins(ts.s + LR(1, li), ts.c);
                    if (jud(i + 1, j + br))
                        H.ins(ts.s + LR(1, uli), ts.c);
                    if (jud(i, j + 1))
                        H.ins(ts.s + LR(1, uri), ts.c);
                }
                else if (!l && !ul && !ur)
                {
                    if (jud(i + 1, j + bl) && jud(i + 1, j + br))
                        H.ins(ts.s + LR(1, li) + LR(1, uli), ts.c);
                    if (jud(i + 1, j + bl) && jud(i, j + 1))
                        H.ins(ts.s + LR(1, li) + LR(1, uri), ts.c);
                    if (jud(i + 1, j + br) && jud(i, j + 1))
                        H.ins(ts.s + LR(1, uli) + LR(1, uri), ts.c);
                }
            }//while
            li += 2; uli += 2; uri += 2;
            H.rot();
        }//J
        if (!(i & 1)) H.mov(2);
        swap(bl, br);
        bl *= -1; br *= -1;
    }//I
    return H.que();
}

int main()
{
    char id[2];

#if 0
    freopen("test.txt", "rt", stdin);
#endif
    while (~scanf("%d%d", &n, &m))
    {
        Rep(i, 0, MAXN) Clr(M[i], n, true);
        while (m--)
        {
            scanf("%s", id);
            M[id[1] - 'A'][id[0] - 'A'] = false;
        }
        printf("%lld\n", PDP());
    }

    return 0;
}



