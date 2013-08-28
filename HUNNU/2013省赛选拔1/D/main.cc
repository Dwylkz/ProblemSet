#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 2e5+10;
typedef long long LL;

int n, f[N<<1], g[N<<1];
LL d[N<<1], s[N<<2];

#define _ls x<<1
#define _rs x<<1|1
void build(int l, int r, int x = 1) {
  if (l == r) {
    s[x] = d[l];
    return ;
  }
  int m = l+r>>1;
  build(l, m, _ls);
  build(m+1, r, _rs);
  s[x] = min(s[_ls], s[_rs]);
}
int ask(int l, int r, int L, int R, int x = 1) {
  int ans = 0x7fffffff;
  if (l <= L && R <= r) ans = s[x];
  else {
    int m = L+R>>1;
    if (l <= m) ans = min(ans, ask(l, r, L, m, _ls));
    if (m < r) ans = min(ans, ask(l, r, m+1, R, _rs));
  }
  return ans;
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for (int T = 1; ~scanf("%d", &n), n; ) {
    printf("Case %d:", T++);
    for (int i = 0; i < n; i++) scanf("%d", f+i);
    for (int i = 0; i < n; i++) scanf("%d", g+i);
    int m = n+n-1;
    for (int i = n; i < m; i++) {
      f[i] = f[i-n];
      g[i] = g[i-n];
    }
    d[0] = 0;
    for (int i = 1; i <= m; i++) d[i] = d[i-1]+f[i-1]-g[i-1];
#if 0
    puts("");
    for (int i = 1; i <= m; i++)
      printf(" %d", d[i]);
    puts("");
#endif
    build(0, m);
    vector<int> ans;
    for (int i = 1; i <= m; i++)
      if (i+n-1 <=m && ask(i, i+n-1, 0, m)-d[i-1] >= 0)
        ans.push_back(i > n? i-n: i);
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) printf(" %d", ans[i]);
    puts("");
  }
  return 0;
}
