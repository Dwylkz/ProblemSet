#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXV (4000)
#define INFI (0x7fffffff)

struct Edge
{
    int v, w, c, nxt;
};
vector<Edge> E;
int L[MAXV];

void G_ini()
{
    E.clear();
    memset(L, -1, sizeof L);
}

void AE(int u, int v, int w,int c)
{
    Edge te = {v, w, c, L[u]};
    L[u] = E.size();
    E.push_back(te);
}

int n, V, src, snk, mc, mf, dis;
bool vis[MAXV];

int AP(int u, int f)
{
    if (u == snk)
    {
        mc += dis * f;
        mf += f;
        return f;
    }
    vis[u] = 1;
    int rf = f;
    for (int i = L[u]; i > -1; i = E[i].nxt)
        if (!vis[E[i].v] && E[i].w && !E[i].c)
        {
            int df = AP(E[i].v, min(rf, E[i].w));
            E[i].w -= df;
            E[i ^ 1].w += df;
            rf -= df;
            if (!rf) return f;
        }
    return f - rf;
}

bool ML()
{
    int md = INFI;
    Rep(u, 0, V) if (vis[u])
        for (int i = L[u]; i > -1; i = E[i].nxt)
            if (!vis[E[i].v] && E[i].w)
                md = min(md, E[i].c);
    if (md == INFI) return 0;
    Rep(u, 0, V) if (vis[u])
        for (int i = L[u]; i > -1; i = E[i].nxt)
        {
            E[i].c -= md;
            E[i ^ 1].c += md;
        }
    dis += md;
    return 1;
}

int ZKW()
{
    mf = mc = dis = 0;
    do
        do memset(vis, 0, sizeof vis);
        while (AP(src, INFI));
    while (ML());
    return mc;
}

int main()
{
#if 1
    freopen("test.txt", "rt", stdin);
#endif

    int Cas, pi, di, ni;

    scanf("%d", &Cas);
    while (Cas--)
    {
        G_ini();
        scanf("%d", &n);
        V = 3 * n + 2;
        src = 3 * n;
        snk = src + 1;
        Rep(i, 0, n)
        {
            int num = 3 * i, fpr = num + 1, fsr = fpr + 1, nfp = num + 4;
            scanf("%d%d%d", &pi, &ni, &di);
            AE(src, fsr, ni, pi);
            AE(fsr, src, 0, -pi);
            AE(fpr, num, INFI, 0);
            AE(num, fpr, 0, 0);
            AE(fsr, num, INFI, 0);
            AE(num, fsr, 0, 0);
            AE(num, snk, di, 0);
            AE(snk, num, 0, 0);
            if (i == n - 1) continue;
            AE(fsr, nfp, INFI, 0);
            AE(nfp, fsr, 0, 0);
        }
        printf("%d\n", ZKW());
    }

    return 0;
}
