#pragma comment(linker,"/STACK:65536000,65536000")
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

typedef unsigned long long ULL;

const int N = 15e4+5;

struct UFS {
  int f[N], s[N];
  void Init()
  {
    for (int i = 0; i < N; i++) {
      f[i] = i;
      s[i] = 1;
    }
  }
  int Find(int x)
  {
    if (f[x] != x)
      f[x] = Find(f[x]);
    return f[x];
  }
  bool Union(int x, int y)
  {
    x = Find(x);
    y = Find(y);
    if (x == y)
      return false;
    f[x] = y;
    s[y] += s[x];
    return true;
  }
  int Size(int x)
  {
    return s[Find(x)];
  }
};

struct Arc {
  int u, v, w;
  void Input()
  {
    scanf("%d%d%d", &u, &v, &w);
    u--;
    v--;
  }
  friend bool operator < (const Arc& lhs, const Arc& rhs)
  {
    return lhs.w < rhs.w;
  }
};

UFS ufs;
Arc arcs[N];
int n;

ULL Calc()
{
  ULL res = 0ull;
  ufs.Init();
  for (int i = 0; i < n-1; i++) {
    int u = arcs[i].u, v = arcs[i].v;
    res += 1ull*arcs[i].w*ufs.Size(u)*ufs.Size(v);
    ufs.Union(u, v);
  }
  return res;
}

int main()
{
  ios_base::sync_with_stdio(false);
  int kase = 1;
  while (~scanf("%d", &n)) {
    for (int i = 0; i < n-1; i++)
      arcs[i].Input();
    sort(arcs, arcs+n-1);
    ULL smax = Calc();
    reverse(arcs, arcs+n-1);
    ULL smin = Calc();
    cout << "Case #" << kase++ << ": " << smax-smin << endl;
  }
  return 0;
}
