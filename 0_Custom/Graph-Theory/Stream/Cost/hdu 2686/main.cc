#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int N = 2e5+10;
const int inf = 0x3f3f3f3f;

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

struct edge_t
{
    int v, w, c, to;
};
vector<edge_t> E;
int L[N];

void G_ini()
{
    E.clear();
    memset(L, -1, sizeof L);
}

void AE(int u, int v, int w,int c)
{
    edge_t te = {v, w, c, L[u]};
    L[u] = E.size();
    E.push_back(te);
}

struct ek_t {
  vector<edge_t> E;
  int n, *L, src, snk, dis[N], ra[N], inq[N];
  int spfa(int u) {
    vector<int> q(1, u);
    memset(dis, 0x3f, sizeof(int)*n);
    memset(ra, -1, sizeof(int)*n);
    memset(inq, 0, sizeof(int)*n);
    dis[u] = 0;
    inq[u] = 1;
    for (int h = 0; h < q.size(); h++) {
      u = q[h], inq[u] = 0;
      for (int e = L[u]; ~e; e = E[e].to) {
        int v = E[e].v, w = E[e].w, c = E[e].c;
        if (w && dis[v] > dis[u]+c) {
          dis[v] = dis[u]+c;
          ra[v] = e^1;
          if (inq[v]) continue;
          inq[v] = 1;
          q.push_back(v);
        }
      }
    }
    return ra[snk] != -1;
  }
  int operator () (vector<edge_t> _E, int *_L, int _n, int _src, int _snk) {
    E = _E, L = _L, n = _n;
    src = _src, snk = _snk;
    int mmf = 0;
    for ( ; spfa(src); ) {
      int mf = inf;
      for (int e = ra[snk]; ~e; e = ra[E[e].v])
        mf = min(mf, E[e^1].w);
      for (int e = ra[snk]; ~e; e = ra[E[e].v])
        E[e].w += mf, E[e^1].w -= mf;
      mmf += dis[snk]*mf;
    }
    return mmf;
  }
} ek;

int n;


int main()
{
#if 1
    freopen("input.in", "rt", stdin);
#endif

    int Cas, pi, di, ni, ws, wk;

    while (~scanf("%d", &n))
    {
        G_ini();
        int V = 2 * n * n + 2, src = 0, snk = 2 * n * n - 1;
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
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
                AE(u + 1, v, inf, 0);
                AE(v, u + 1, 0, 0);
            }
            if (j)
            {
                AE(l + 1, v, inf, 0);
                AE(v, l + 1, 0, 0);
            }
        }
        printf("%d\n", -ek(E, L, V, src, snk) - ws - wk);
    }

    return 0;
}
