#include <cstdio>
#include <cmath>
#include <queue>
#include <cstdlib>
#include <stack>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int maxn = 2e4 + 10;
typedef long long LL;
typedef int int_a[maxn];

struct edge {
  int v, to;
  double w;
};
vector<edge> E;
int_a L;
void graph_init()
{
  E.clear();
  memset(L, -1, sizeof(L));
}
void graph_add(int u, int v, double w)
{
  edge t = {v, L[u], w};
  L[u] = E.size();
  E.push_back(t);
}

int n, m, k;

struct point {
  int x, y;
  friend bool operator < (point x, point y)
  {
    if (x.x != y.x) return x.x < y.x;
    return x.y < y.y;
  }
  friend bool operator <= (point x, point y)
  {
    return x.x <= y.x && x.y <= y.y;
  }
} src, snk;
vector<point> p;
map<point, int> pi; 

double dis[maxn];
bool inq[maxn];
void SPFA()
{
  for (int i = 0; i < p.size(); i++) {
    inq[i] = 0;
    dis[i] = 0x7fffffff;
  }
  for (int k = dis[1] = 0; k < p.size(); k++) {
    int u = 0;
    for (int i = 1; i < p.size(); i++)
      if (!inq[i] && dis[i] < dis[u]) u = i;
    inq[u] = 1;
    for (int i = L[u]; i != -1; i = E[i].to) {
      int v = E[i].v;
      double w = E[i].w;
      if (dis[v] - w > dis[u]) dis[v] = dis[u] + w;
    }
  }
}

int main()
{
#if 1
	freopen("input.in", "r", stdin);
#endif
	for ( ; ~scanf("%d%d%d", &n, &m, &k); ) {
    graph_init();
    src = (point){1, 1};
    snk = (point){n+1, m+1};
    p.clear();
    pi.clear();

    p.push_back((point){0, 0});
    pi[src] = p.size();
    p.push_back(src);
    pi[snk] = p.size();
    p.push_back(snk);

    for ( ; k--; ) {
      int x, y;
      scanf("%d%d", &x, &y);
      point tsrc = {x, y}, tsnk = {x+1, y+1};
      if (!pi[tsrc]) {
        pi[tsrc] = p.size();
        p.push_back(tsrc);
      }
      if (!pi[tsnk]) {
        pi[tsnk] = p.size();
        p.push_back(tsnk);
      }
      double d = sqrt(2.0)*100.0;
      graph_add(pi[tsrc], pi[tsnk], sqrt(2.0)*100.0);
    }
    for (int i = 1; i < p.size(); i++) {
      for (int j = 1; j < i; j++) {
        double d = (abs(p[i].x-p[j].x)+abs(p[i].y-p[j].y))*100.0;
        if (p[i] <= p[j]) graph_add(i, j, d);
        if (p[j] <= p[i]) graph_add(j, i, d);
      }
    }
    SPFA();
    printf("%.0lf\n", dis[2]);
	}
	return 0;
}
