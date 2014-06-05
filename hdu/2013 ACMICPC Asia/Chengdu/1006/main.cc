#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e5+10;
const int mod = 1e9+7;

char p[N], q[N], a[N], b[N];
int f[N], g[N], h[N], c[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  for (int ks = 1; T--; ks++) {
    printf("Case #%d:\n", ks);
    scanf("%s%s", p, q);
    strcpy(a, p);
    strcpy(b, q);
    int id = 0, n = strlen(q);
    for (int i = 0; i < n-1; i++)
      if (!(a[i] == '0' && b[i] == '0')) break;
    strcpy(p, a+id);
    strcpy(q, b+id);

    n = strlen(p);
    memset(g, 0, sizeof(g));
    memset(f, 0, sizeof(f));
    memset(h, 0, sizeof(h));
    g[n+1] = g[n+2] = 1;
    for (int i = n; i; i--) {
      int j = i-1;
      if (p[j] != '1' && q[j] != '1') g[i] = 1;
      else break;
    }
    h[n+1] = 1;
    for (int i = 1; i <= n; i++) {
      int j = i-1;
      if (p[j] != '0' && q[j] != '0') h[i] = 1;
    }
    f[0] = 1;
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= n; i++) {
      int j = i-1;
      if (p[j] != '?' && q[j] != '?') {
        if (p[j] == q[j]) f[i] = f[i-1];
        else break;
      } else if (p[j] == '?' && q[j] == '?') f[i] = f[i-1]*2;
      else f[i] = f[i-1];
      if (f[i] > mod) {
        c[i] = 1;
        f[i] %= mod;
      }
    }

#if 1
    for (int i = 1; i <= n; i++)
      printf(" %d", f[i]);
    puts("");
#endif
    int rv = 0, flg = 1, b = -1;
    for (int i = 1; i <= n; i++) {
      int j = i-1;
      if (!(h[i+1] && g[i+2])) continue;
      if (p[j] == '?' || q[j] == '?' || p[j] != q[j]) {
        if (p[j] == '1' && !j) continue;
        if (f[i-1] && !c[i-1]) b = j;
        rv = rv+f[i-1];
        if (c[i-1] || rv > 1) {
          flg = 0;
          rv %= mod;
        }
        if ((p[j] == '?' && !j) || i == n) continue;
        rv = rv+f[i-1];
        if (c[i-1] || rv > 1) {
          flg = 0;
          rv %= mod;
        }
        printf("in %d, f = %d, rv = %d\n", j, f[i-1], rv);
      }
    }
    if (n == 1 && p[0] == '1' && q[0] == '0') rv = 0;
    if (!rv) puts("Impossible");
    else if (rv == 1 && flg) {
#if 0
      printf("b = %d\n", b);
#endif
      for (int i = 0; i < b; i++)
        if (p[i] == '?') p[i] = q[i];
        else q[i] = p[i];
      for (int i = b+2; i < n; i++)
        p[i] = q[i] = '0';
      if (b+1 < n) p[b+1] = q[b+1] = '1';
      char pre = p[0]-'0', now = p[0]-'0';
      for (int i = 1; i < b-1; i++) {
        now = (p[i]-'0')^pre;
        pre = now;
      }
      if (now) {
        p[b] = '1';
        q[b] = '0';
      } else {
        p[b] = '0';
        q[b] = '1';
      }
      puts(p);
      puts(q);
    } else printf("Ambiguous %d\n", rv);
  }
  return 0;
}
