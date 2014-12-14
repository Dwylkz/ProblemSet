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

const int N = 1e2+5;

struct Dp {
  Dp* p;
  int c, w;
  Dp() {}
  Dp(Dp* p, int c, int w): p(p), c(c), w(w) {}
  void Cmp(const Dp& rhs)
  {
    if (w < rhs.w)
      *this = rhs;
  }
};

Dp f[N][N][N];
int n, p[N];
char a[N], b[N], v[N];

int main()
{
  scanf("%s%s%s", a, b, v);
  int na = strlen(a), nb = strlen(b), nv = strlen(v);
  for (int i = 1, j = p[0] = -1; v[i]; i++) {
    while (~j && v[j+1] != v[i])
      j = p[j];
    if (v[j+1] == v[i])
      j++;
    p[i] = j;
  }
  // for (int i = 0; v[i]; i++)
  //   printf("%d%c", p[i], v[i+1]? ' ': '\n');
  for (int i = 1; i <= na; i++)
    for (int j = 1; j <= nb; j++)
      for (int k = 0; k < nv; k++) {
        if (a[i-1] == b[j-1] && f[i-1][j-1]) {
          int l = k-1, c = a[i-1];
          while (~l && v[l+1] != c)
            l = p[l];
          if (v[l+1] == c)
            l++;
          f[i][j][l+1].Cmp(Dp(&f[i-1][j-1][k], c, f[i-1][j-1][k].w+1));
        }
        f[i][j][k].Cmp(Dp(&f[i][j-1][k], 0, f[i][j-1][k].w));
        f[i][j][k].Cmp(Dp(&f[i-1][j][k], 0, f[i-1][j][k].w));
      }
  // for (int i = 0; i <= nv; i++)
  //   printf("%d%c", f[na][nb][i].w, v[i]? ' ': '\n');
  int mi = 0;
  for (int i = 1; i < nv; i++)
    if (f[na][nb][i].w > f[na][nb][mi].w)
      mi = i;
  string ans = "0";
  if (f[na][nb][mi].w != 0) {
    ans = "";
    for (Dp* p = &f[na][nb][mi]; p; p = p->p)
      if (p->c)
        ans += p->c;
    reverse(ans.begin(), ans.end());
  }
  printf("%s\n", ans.data());
  return 0;
}
