#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string.h>
#include <map>
#include <vector>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define LL long long
#define MAXN (1100)
#define MOD (1000003)

struct BST
{
    struct node
    {
        int k, s[2], c;

        void set(int tk)
        {
            k = tk;
            s[0] = s[1] = 0;
            c = 1;
        }
    } t[MAXN];

    int ind;

    void ini()
    {
        t[ind = 0].set(-1);
        t[0].c = 0;
    }

    void ins(int k, int x = 1)
    {
        if (!ind)
        {
            t[1].set(k);
            ind = 2;
        }
        else
        {
            int lr = k > t[x].k;

            if (!t[x].s[lr])
            {
                t[ind].set(k);
                t[x].s[lr] = ind++;
            }
            else ins(k, t[x].s[lr]);
        }
    }

    int siz(int x = 1)
    {
        if (!t[x].s[0] && !t[x].s[1]) return t[x].c = 1;
        t[x].c = 1;
        if (t[x].s[0]) t[x].c += siz(t[x].s[0]);
        if (t[x].s[1]) t[x].c += siz(t[x].s[1]);
        return t[x].c;
    }

    void FT(int x = 1)
    {
        if (!x) return ;
        printf(" %d", t[x].k);
        FT(t[x].s[0]);
        FT(t[x].s[1]);
    }

    void MT(int x = 1)
    {
        if (!x) return ;
        MT(t[x].s[0]);
        printf(" %d", t[x].k);
        MT(t[x].s[1]);
    }
} zkl;

bool vis[MAXN];
int n, m, kin, H[MAXN * MAXN];
LL S[MAXN * MAXN];


LL GCD(LL a, LL b)
{
    return b? GCD(b, a % b): a;
}

LL C(LL n, LL m)
{
    LL tsu = 1;
    vector<LL> p;

    #if 0
        printf(" C(%lld, %lld)\n", n, m);
    #endif
    if (m - n < n) n = m - n;
    Rep(i, m - n + 1, m + 1) p.push_back(i);
    Rep(i, 1, n + 1)
    {
        LL ti = i;
        Rep(j, 0, p.size())
        {
            LL gcd = GCD(ti, p[j]);
            ti /= gcd;
            p[j] /= gcd;
            if (ti < 2) break;
        }
    }
    Rep(i, 0, p.size()) tsu = (tsu * p[i]) % MOD;

    return tsu;
}

int DFS(int x)
{
    int l = zkl.t[x].s[0], r = zkl.t[x].s[1];
    LL lc = zkl.t[l].c, rc = zkl.t[r].c;
    int f, lh = 0, rh = 0;

    if (!l && !r)
    {
        if (!H[0])
        {
            H[0] = kin++;
            S[H[0]] = 1;
        }
        return H[0];
    }

    vis[x] = 1;
    if (l && !vis[l]) lh = DFS(l);
    if (r && !vis[r]) rh = DFS(r);
    f = lh + rh * MAXN;
    if (!H[f])
    {
        H[f] = kin++;
        if (!l) S[H[f]] = S[rh];
        else if (!r) S[H[f]] = S[lh];
        else S[H[f]] = S[lh] * S[rh] % MOD * C(lc, lc * (rc + 1)) % MOD;
    }
    vis[x] = 0;

    #if 0
        printf(" f = (%d, %d)\n", f % MAXN, f / MAXN);
        printf(" %d (%d, %d)\n", zkl.t[x].k, zkl.t[l].c, zkl.t[r].c);
        printf(" S = %lld\n", S[H[f]]);
        printf(" %d, %d\n", S[lh], S[rh]);
    #endif

    return H[f];
}

int main()
{
#if 1
    freopen("test.txt", "rt", stdin);
#endif
    int T, ai, maxi;

    scanf ("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        zkl.ini();
        Rep(i, 0, n)
        {
            scanf("%d", &ai);
            zkl.ins(ai);
        }
        zkl.siz();
#if 0
        printf(" size = %d\n", zkl.ind);
        printf("FT :");
        zkl.FT();
        puts("");
        printf("MT :");
        zkl.MT();
        puts("");
#endif
        memset(vis, 0, sizeof vis);
        memset(H, 0, sizeof H);
        memset(S, -1, sizeof S);
        S[0] = 0;
        kin = 1;
        printf("%lld\n", C(n, m) * S[DFS(1)] % MOD);
    }

    return 0;
}
