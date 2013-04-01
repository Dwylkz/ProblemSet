#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define Rep(c, a, b) for (int c = a; c < b; c++)
#define MAXV (800000)
#define INFI (20000)

inline void scan_d(int &num)
{
    char in;
    in = getchar();
    while(in<'0' || in>'9') in = getchar();
    num = in - '0';
    while(in = getchar(), in>='0' && in<='9')
    {
        num *= 10, num += in - '0';
    }
}

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

int n, V, src, snk, dis[MAXV], pe[MAXV];
bool IQ[MAXV];

bool MMF_SPFA(int u)
{
    queue<int> Q;

    Rep(i, 0, V)
    {
        dis[i] = INFI;
        pe[i] = -1;
        IQ[i] = 0;
    }
    dis[u] = 0;
    IQ[u] = 1;
    Q.push(u);
    while (!Q.empty())
    {
        u = Q.front();
        IQ[u] = 0;
        Q.pop();
        for (int i = L[u]; i != -1; i = E[i].nxt)
        {
            int v = E[i].v, w = E[i].w, c = E[i].c;
            if (w && dis[v] > dis[u] + c)
            {
                dis[v] = dis[u] + c;
                pe[v] = i ^ 1;
                if (IQ[v]) continue;
                IQ[v] = 1;
                Q.push(v);
            }
        }
    }

    return pe[snk] != -1;
}

int EKMMF()
{
    int mmf = 0;

    while (MMF_SPFA(src))
    {
        int i, minf = INFI;
        for (i = pe[snk]; i != -1; i = pe[E[i].v])
            minf = min(minf, E[i ^ 1].w);
        for (i = pe[snk]; i != -1; i = pe[E[i].v])
        {
            E[i].w += minf;
            E[i ^ 1].w -= minf;
        }
        mmf += dis[snk] * minf;
    }

    return mmf;
}

int main()
{
#if 1
    freopen("test.txt", "rt", stdin);
#endif

    int Cas, pi, di, ni, ws, wk;

    while (~scanf("%d", &n))
    {
        G_ini();
        V = 2 * n * n + 2;
        src = 0;
        snk = 2 * n * n - 1;
        Rep(i, 0, n) Rep(j, 0, n)
        {
            int w = 1, c, u = (i * n - n + j) * 2, l = (i * n + j - 1) * 2, v = (i * n + j) * 2;
            scanf("%d", &c);
            if (!i && !j)
            {
                w++;
                ws = c;
            }
            if (i == n - 1 && j == n - 1)
            {
                w++;
                wk = c;
            }
            AE(v, v + 1, w, -c);
            AE(v + 1, v, 0, c);
            if (i)
            {
                AE(u + 1, v, INFI, 0);
                AE(v, u + 1, 0, 0);
            }
            if (j)
            {
                AE(l + 1, v, INFI, 0);
                AE(v, l + 1, 0, 0);
            }
        }
        printf("%d\n", -EKMMF() - ws - wk);
    }

    return 0;
}
