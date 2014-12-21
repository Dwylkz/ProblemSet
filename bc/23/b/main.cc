#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

const int N = 5e4+5;

struct Fenwick {
  int d[N];
  void Init()
  {
    memset(d, 0, sizeof(d));
  }
  void Add(int x)
  {
    for (x++; x < N; x += -x&x)
      d[x]++;
  }
  int Ask(int x)
  {
    int ret = 0;
    for (x++; x; x -= -x&x)
      ret += d[x];
    return ret;
  }
};

typedef long long LL;

Fenwick h;
int n, a[N];
LL f[N];

int main()
{
  int kase;
  scanf("%d", &kase);
  while (kase--) {
    scanf("%d", &n);
    h.Init();
    for (int i = 0; i < n; i++) {
      scanf("%d", a+i);
      f[i] = h.Ask(a[i]-1);
      h.Add(a[i]);
    }
    for (int i = 1; i < n; i++)
      f[i] += f[i-1];
    h.Init();
    LL ans = 0;
    for (int i = n-1; i > 0; i--) {
      ans += (h.Ask(n)-h.Ask(a[i]))*f[i-1];
      h.Add(a[i]);
    }
    cout << ans << endl;
  }
  return 0;
}
