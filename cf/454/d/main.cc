#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
typedef vector<int> VI;

const int N = 2e3+10;
const int P = 100;

struct edge_t {
  int v, to, w, c;
};
vector<edge_t> E;
int L[N];
void Init()
{
  E.clear();
  memset(L, -1, sizeof(L));
}
void Add(int u, int v, int w, int c)
{
  edge_t t = {v, L[u], w, c};
  L[u] = E.size();
  E.push_back(t);
}
void DAdd(int u, int v, int w, int c)
{
  Add(u, v, w, c);
  Add(v, u, 0, -c);
}

/* Spfa_Cost_Stream
 * */
template<class edge_t, int N> struct ek_t {
vector<edge_t> E;
static const int inf = 0x7f7f7f7f;
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
int operator () (vector<edge_t>& _E, int *_L, int _n, int _src, int _snk) {
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
};
ek_t<edge_t, N> ek;

VI ps;
bool IsPrime(int x)
{
  for (int i = 2; i*i <= x; i++)
    if (x%i == 0)
      return false;
  return true;
}
void Gen()
{
  for (int i = 2; ps.size() < P; i++)
    if (IsPrime(i))
      ps.push_back(i);
}

int n, a[N];

int main()
{
  cin.sync_with_stdio(0);
  Gen();
  for ( ;cin >> n; ) {
    for (int i = 0; i < n; i++)
      cin >> a[i];

    Init();
    int one = n+P, src = one+1, snk = src+1;
    for (int i = 0; i < n; i++) {
      DAdd(src, i, 1, 0);
      DAdd(i, one, 1, a[i]-1);
      for (int j = 0; j < P; j++)
        DAdd(i, n+j, 1, abs(a[i]-ps[j]));
    }
    for (int i = 0; i < P; i++)
      DAdd(n+i, snk, 1, 0);
    DAdd(one, snk, n, 0);

    int res = ek(E, L, snk+1, src, snk);
    VI ans;
    for (int i = 0; i < n; i++)
      for (int e = L[i]; ~e; e = E[e].to)
        if (e%2 == 0 && ek.E[e].w == 0)
          if (E[e].v == one)
            ans.push_back(1);
          else
            ans.push_back(ps[E[e].v-n]);

    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i];
      if (i == ans.size()-1)
        cout << endl;
      else
        cout << " ";
    }
  }
  return 0;
}
