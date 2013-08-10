#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 5e4 + 10;
typedef long long LL;

struct query {
  int l, r, i;
  friend bool operator < (query lhs, query rhs)
  {
    return lhs.r < rhs.r;
  }
};
query q[maxn];
int ans[maxn];

int bia[maxn];
void bia_init()
{
  memset(bia, 0, sizeof(bia));
}
void bia_push(int x, int y)
{
  for (x++; x; x -= -x&x)
    bia[x] = max(bia[x], y);
}
int bia_ask(int x, int rv = 0)
{
  for (x++; x < maxn; x += -x&x)
    rv = max(rv, bia[x]);
  return rv;
}

int n, m, a[maxn], pre[maxn];

int main()
{
#if 1
	freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
	for ( ; T--; ) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      scanf("%d", a+i);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
      scanf("%d%d", &q[i].l, &q[i].r);
      q[i].l--, q[i].r--;
      q[i].i = i;
    }
    sort(q, q + m);
    bia_init();
    memset(pre, -1, sizeof(pre));
    for (int i = 0, j = 0; i < n && j < m; i++) {
      for (int k = 1; k*k <= a[i]; k++) 
        if (a[i] % k == 0) {
          if (pre[k] != -1) bia_push(pre[k], k);
          pre[k] = i;
          if (k*k == a[i]) continue;
          if (pre[a[i]/k] != -1) bia_push(pre[a[i]/k], a[i]/k);
          pre[a[i]/k] = i;
        }
      for ( ; j < m && q[j].r == i; j++)
        ans[q[j].i] = q[j].l == q[j].r? 0: bia_ask(q[j].l);
    }
    for (int i = 0; i < m; i++) printf("%d\n", ans[i]);
	}
	return 0;
}
