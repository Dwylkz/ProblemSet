#include <map>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 1e5 + 10;
typedef long long LL;
typedef map<int, int> mii;
typedef mii::iterator mii_i;

struct monk {
  int k, g;
} m[maxn];

int bia[maxn];
void init()
{
  memset(bia, 0, sizeof(bia));
}
void push(int x)
{
  for ( ; x < maxn; x += -x&x) bia[x]++;
}
int ask(int x, int y, int rv = 0)
{
  for ( ; y; y -= -y&y) rv += bia[y];
  for (x--; x; x -= -x&x) rv -= bia[x];
  return rv;
}

int n;
mii ddi;

int fight(int x)
{
  int lhs = -1;
  if (ask(1, x)) {
    for (int l = 1, r = x; l < r; ) {
      int m = l+r>>1;
      if (ask(m+1, r)) l = lhs = m+1;
      else r = lhs = m;
    }
  }
  int rhs = -1;
  if (ask(x, n)) {
    for (int l = x, r = n; l < r; ) {
      int m = l+r>>1;
      if (ask(l, m)) r = rhs = m;
      else l = rhs = m+1;
    }
  }
  if (lhs == -1) return rhs;
  if (rhs == -1) return lhs;
  if (abs(ddi[lhs]-ddi[x]) > abs(ddi[rhs]-ddi[x])) swap(lhs, rhs);
  return lhs;
}

int main()
{
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; scanf("%d", &n), n; ) {
    mii dis;
    for (int i = 0; i < n; i++) {
      scanf("%d%d", &m[i].k, &m[i].g);
      dis[m[i].g] = -1;
    }
    int id = 1;
    ddi.clear();
    for (mii_i i = dis.begin(); i != dis.end(); i++)
      ddi[i->second = id++] = i->first;
    mii rfl;
    for (int i = 0; i < n; i++) {
      m[i].g = dis[m[i].g];
      rfl[m[i].g] = m[i].k;
    }
#if 0
    for (mii_i i = rfl.begin(); i != rfl.end(); i++)
      printf("%d->%d\n", i->first, i->second);
#endif
    init();
    push(m[0].g);
    printf("%d 1\n", m[0].k);
    for (int i = 1; i < n; i++) {
#if 0
      printf("\t%d %d\n", m[i].g, fight(m[i].g));
      printf("tree: ");
      for (int j = 1; j <= n; j++)
        printf("%d%c", ask(j, j), j<n-1? ' ': '\n');
#endif
      printf("%d %d\n", m[i].k, rfl[fight(m[i].g)]);
      push(m[i].g);
    }
  }
  return 0;
}
