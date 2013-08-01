#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;
const int maxn = 5e4 + 10;
typedef long long LL;

struct seg_node {
  seg_node *ls, *rs;
  map<int, bool> d;
} *top, seg[maxn<<1];
void build(seg_node *x, int L, int R)
{
  x->d.clear();
  if (L == R) return ;
  int m = L+R>>1;
  build(x->ls = ++top, L, m);
  build(x->ls = ++top, m+1, R);
}
void cover(seg_node *x, int L, int R, int l, int r, int k)
{
  if (l <= L && R <= R) x->d[k] = 1;
  else {
    int m = L+R>>1;
    if (l <= m) cover(x->ls, L, m, l, r, k);
    if (m < r) cover(x->ls, m+1, R, l, r, k);
  }
}
int ask(seg_node *x, int L, int R, int l, int r)
{
  int ans = 0;
  if (l <= L && R <= r) ans = x->d.rbegin()->first;
  else {
    int m = L+R>>1;
    if (l <= m) ans = max(ans, ask(x->ls, L, m, l, r));
    if (m < r) ans = max(ans, ask(x->rs, m+1, R, l, r));
  }
  return ans;
}

struct querry_t {
  int l, r, id;
  friend bool operator < (querry_t x, querry_t y)
  {
    return x.r < y.r;
  }
} querry[maxn];
int n, q, a[maxn], hash[maxn], ans[maxn];
vector<int> gn;

void gen()
{
}

int main()
{
#if 1
	freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
	for ( ; T--; ) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a+i);
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
      scanf("%d%d", &querry[i].l, &querry[i].r);
      querry[i].id = i;
    }
    sort(querry, querry + q);
    build(top = seg, 0, n-1);
    memset(hash, -1, sizeof(hash));
    for (int i = 0; i < n; i++) {
      vector<int> f;
      gen(f);
      for (int j = 0; j < f.size(); j++)
        if (hash[f[j]] != -1)
        cover(seg, 0, n - 1, 0, hash[f[j]], j);
    }
    for (int i = 0; i < q; i++) printf("%d\n", ans[i]);
	}
	return 0;
}
