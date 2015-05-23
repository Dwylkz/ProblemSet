#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int N = 2e2+5;
const int INF = N*N;

struct Graph {
  struct Edge {
    int to, v, w;
  };
  Graph()
  {
    e.clear();
    memset(h, -1, sizeof(h));
  }
  vector<Edge> e;
  int h[N];
  void Add(int u, int v, int w)
  {
    Edge t = {h[u], v, w};
    h[u] = e.size();
    e.push_back(t);
  }
  void BAdd(int u, int v, int w)
  {
    Add(u, v, w);
    Add(v, u, 0);
  }
  int d[N];
  bool Adjust(int src, int snk)
  {
    memset(d, -1, sizeof(d));
    queue<int> q;
    q.push(snk);
    d[snk] = 0;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int i = h[u]; i != -1; i = e[i].to) {
        int w = e[i^1].w, v = e[i].v;
        if (d[v] == -1 && w > 0) {
          d[v] = d[u]+1;
          q.push(v);
        }
      }
    }
    return d[src] != -1;
  }
  int Flood(int u, int snk, int flow)
  {
    if (u == snk) return flow;
    int all = flow;
    for (int i = h[u]; i != -1; i = e[i].to) {
      int v = e[i].v, w = e[i].w;
      if (!(d[u] == d[v]+1 && w > 0)) continue;
      int df = Flood(v, snk, min(w, all));
      e[i].w -= df;
      e[i^1].w += df;
      all -= df;
      if (all == 0) return flow;
    }
    return flow-all;
  }
  int Dicnic(int src, int snk)
  {
    int flow = 0;
    while (Adjust(src, snk)) flow += Flood(src, snk, INF);
    return flow;
  }
};

int main()
{
  int n, m;
  scanf("%d%d", &n, &m);
  int src = n+n, snk = src+1;
  Graph g;
  int alla = 0;
  for (int i = 0; i < n; i++) {
    int w;
    scanf("%d", &w);
    g.BAdd(src, i, w);
    alla += w;
  }
  int allb = 0;
  for (int i = 0; i < n; i++) {
    int w;
    scanf("%d", &w);
    g.BAdd(n+i, snk, w);
    allb += w;
  }
  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    g.BAdd(u, n+v, INF);
    g.BAdd(v, n+u, INF);
  }
  for (int i = 0; i < n; i++) g.BAdd(i, n+i, INF);
  int flow = g.Dicnic(src, snk);
  if (!(alla == allb && flow == alla)) {
    puts("NO");
    return 0;
  }
  puts("YES");
  int b[N][N];
  memset(b, 0, sizeof(b));
  for (int v = n; v < n+n; v++)
    for (int e = g.h[v]; e != -1; e = g.e[e].to)
      if (e&1) b[g.e[e].v][v-n] = g.e[e].w;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      printf("%d%c", b[i][j], j < n-1? ' ': '\n');
  return 0;
}
