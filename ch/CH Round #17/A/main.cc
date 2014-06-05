#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int N = 50+5;

/* Chinese Remind Theory
 * */
template<int N> struct crt_t {
  vector<int> a, b;
  int gcd(int a, int b, int &x, int &y) {
    int d, tx, ty;
    if (b == 0) {
      x = 1;
      y = 0;
      return a;
    }
    d = gcd(b, a%b, tx, ty);
    x = ty;
    y = tx-(a/b)*ty;
    return d;
  }
  int mle(int a, int b, int n) {
    int d, x, y;
    d = gcd(a, n, x, y);
    if (b%d == 0) {
      x = 1ll*x*b/d%n;
      return x;
    }
    return 0;
  }
  int init() {
    a.clear();
    b.clear();
  }
  int operator () () {
    int x = 0, n = 1, i, bi;
    for (i = 0; i < b.size(); i++) n *= b[i];
    for (i = 0; i < a.size(); i++) {
      bi = mle(n/b[i], 1, b[i]);
      x = (x+1ll*a[i]*bi*(n/b[i]))%n;
    }
    return x;
  }
};
typedef crt_t<N> crt_i;

int mod[5] = {31, 37, 41, 43, 47},
    strling[5][N][N],
    bell[5][N];
void init() {
  for (int k = 0; k < 5; k++)
    for (int i = strling[k][0][0] = 1; i < N; i++) {
      strling[k][i][0] = 0;
      for (int j = 1; j <= i; j++)
        strling[k][i][j] = (strling[k][i-1][j]*j+strling[k][i-1][j-1])%mod[k];
    }
  for (int k = 0; k < 5; k++)
    for (int i = 0; i < N; i++)
      for (int j = bell[k][i] = 0; j <= i; j++)
        (bell[k][i] += strling[k][i][j]) %= mod[k];
#if 0
  int k = 4;
  printf("strling[%2d]\n", mod[k]);
  for (int i = 0; i < mod[k]; i++) {
    for (int j = 0; j <= i; j++)
      printf(" %2d", strling[k][i][j]);
    puts("");
  }
  printf("bell[%2d]: ", mod[k]);
  for (int i = 0; i < mod[k]; i++) printf(" %2d", bell[k][i]);
  puts("");
#endif
}

void mul(int a[][N], int b[][N], int result[][N], int n, int m) {
  int t[N][N] = {0};
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++)
        t[i][j] = t[i][j]+a[i][k]*b[k][j]%m;
  memcpy(result, t, sizeof(t));
}
void qmod(int a[][N], int b, int result[][N], int n, int m) {
  int x[N][N], t[N][N] = {0};
  for (int i = 0; i < n; i++) t[i][i] = 1;
  memcpy(x, a, sizeof(x));
  for ( ; b; b >>= 1) {
    if (b&1) mul(t, x, t, n, m);
    mul(x, x, x, n, m);
  }
  memcpy(result, t, sizeof(t));
}

int x[N][N], y[N][N];
int calc(int n, int j) {
  int k = mod[j];
  memset(x, 0, sizeof(x));
  memset(y, 0, sizeof(y));
  for (int i = 0; i < k; i++) x[i][0] = bell[j][i];
  for (int i = 0; i < k-1; i++) y[i][i] = y[i][i+1] = 1;
  y[k-1][k-1] = y[k-1][0] = y[k-1][1] = 1;
  qmod(y, n/k, y, k, k);
  if (n/k) mul(y, x, x, k, k);
  return x[n%k][0];
}

crt_i crt;
int n;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  init();
  int T;
  scanf("%d", &T);
  for ( ; T--; ) {
    scanf("%d", &n);
    int answer[5];
    for (int i = 0; i < 5; i++) answer[i] = calc(n, i);
#if 0
    for (int i = 0; i < 5; i++) printf(" %d", answer[i]);
    puts("");
#endif
    crt.init();
    for (int i = 0; i < 5; i++) {
      crt.a.push_back(answer[i]);
      crt.b.push_back(mod[i]);
    }
    printf("%d\n", crt());
  }
  return 0;
}
