#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 2e2 + 10;
typedef long long LL;

int n, m, l, r;
double p[maxn][maxn];
#define pm(z, x, y) {\
  double _t[maxn] = {0.0};\
  for (int _i = 0; _i < n; _i++)\
    for (int _j = 0; _j < n; _j++)\
      _t[(_i+_j)%n] += x[_i]*y[_j];\
  memcpy(z, _t, sizeof(_t));\
}

void qmod(double x[maxn], int wi, int ci)
{
  double t[maxn] = {0.0}, y[maxn] = {1.0};
#if 0
  printf("x: ");
  for (int i = 0; i < n; i++)
    printf("%lf%c", x[i], i<n-1? ' ': '\n');
#endif
  t[1] = t[n-1] = 0.5;
  for ( ; ci; ci >>= 1) {
    if (ci&1) pm(y, y, t);
    pm(t, t, t);
  }
  memset(t, 0, sizeof(t));
  for (int i = 0; i < n; i++)
    t[i*wi%n] += y[i];
  memcpy(x, t, sizeof(t));
}

int main()
{
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d%d%d", &n, &m, &l, &r), n||m||l||r; ) {
    double w[maxn] = {0.0};
    for (int wi, i = 0; i < m; i++) {
      scanf("%d", &wi);
      w[wi]++;
    }
    double t[maxn] = {1.0};
    for (int i = 1; i < maxn; i++)
      if (w[i]) {
        qmod(p[i], i, w[i]);
        pm(t, t, p[i]);
      }
    double ans = 0.0;
    for (int i = l-1; i < r; i++) ans += t[i];
    printf("%.4lf\n", ans);
#if 0
    puts("hoho");
    for (int i = 1; i < maxn; i++)
      if (w[i]) {
        printf("%d: ", i);
        for (int j = 0; j < n; j++)
        printf("%lf%c", p[i][j], j<n-1? ' ': '\n');
      }
    printf("t: ");
    for (int j = 0; j < n; j++)
      printf("%lf%c", t[j], j<n-1? ' ': '\n');
#endif
  }
  return 0;
}
