#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

const int N = 2e3+5;

typedef map<int, int> MII;

struct BIA {
  int d[N];
  void Init()
  {
    memset(d, 0, sizeof(d));
  }
  void Add(int x, int y)
  {
    for (x++; x < N; x += -x&x)
      d[x] = max(d[x], y);
  }
  int Ask(int x)
  {
    int ans = 0;
    for (x++; x; x -= -x&x)
      ans = max(ans, d[x]);
    return ans;
  }
};

int n, m, a[N], b[N];
BIA f[N];

int main()
{
  int kase;
  scanf("%d", &kase);
  while (kase--) {
    scanf("%d%d", &n, &m);
    MII dis;
    for (int i = 0; i < n; i++) {
      scanf("%d%d", a+i, b+i);
      dis[a[i]] = 0;
      dis[b[i]] = 0;
    }
    int id = 0;
    for (MII::iterator i = dis.begin(); i != dis.end(); i++)
      i->second = id++;
    for (int i = 0; i < n; i++) {
      a[i] = dis[a[i]];
      b[i] = dis[b[i]];
    }
    for (int i = 0; i <= m; i++)
      f[i].Init();
    int maxv = 0;
    for (int i = 0; i < n; i++)
      for (int j = max(0, m-(i+1)); j <= m; j++) {
        int maxa = f[j].Ask(a[i]-1)+1;
        maxv = max(maxv, maxa);
        f[j].Add(a[i], maxa);
        if (j < m) {
          int maxb = f[j+1].Ask(b[i]-1)+1;
          maxv = max(maxv, maxb);
          f[j].Add(b[i], maxb);
        }
      }
    printf("%d\n", maxv);
  }
  return 0;
}
