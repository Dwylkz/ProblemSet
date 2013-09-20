#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll_t;
const int N = 1e7+10;

/* p[]: primes
 * n  : primes number
 * e[]: eular funtion
 * d[]: divisors number
 * f[]: minimum prime factor
 * c[]: minimum prime factor's power
 * m[]: mobius function
 * */
template<int N> struct sieve_t {
  bool b[N];
  int p[N], n, f[N], c[N], t[N], m[N];
  sieve_t() {
    m[1] = 1;
    for (int i = 2; i < N; i++) {
      if (!b[i]) {
        f[i] = 1;
        c[i] = 1;
        t[i] = 0;
        p[n++] = i;
      }
      for (int j = 0; j < n && p[j] < N/i; j++) {
        int k = i*p[j];
        b[k] = 1;
        if (i%p[j]) {
          f[k] = f[i]+1;
          c[k] = 1;
          t[k] = t[i];
        } else {
          f[k] = f[i];
          c[k] = c[i]+1;
          if (c[k] == 2) t[k] = t[i]+1;
          else if (c[k] > 2) t[k] = 100;
          else t[k] = t[i];
        }
      }
      if (!t[i]) {
        if (f[i]-1&1) m[i] = -f[i];
        else m[i] = f[i];
      } else if (t[i] == 1) {
        if (f[i]&1) m[i] = -1;
        else m[i] = 1;
      } else m[i] = 0;
      m[i] += m[i-1];
    }
  }
};

sieve_t<N> sieve;
int n, m;

ll_t sum(int x, int y) {
  if (x > y) swap(x, y);
  ll_t f = 0;
  for (int i = 2, r = 0; i <= x; i = r+1) {
    r = min(x/(x/i), y/(y/i));
    f += 1ll*(sieve.m[r]-sieve.m[i-1])*(x/i)*(y/i);
  }
  return f;
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  for ( ; T--; ) {
    scanf("%d%d", &n, &m);
    printf("%lld\n", sum(n, m));
  }
  return 0;
}
