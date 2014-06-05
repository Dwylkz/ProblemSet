#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll_t;
const int N = 5e4+10;

/* p[]: primes
 * n  : primes number
 * e[]: eular funtion
 * d[]: divisors number
 * f[]: minimum prime factor
 * c[]: minimum prime factor's power
 * m[]: mobius function
 * */
template<int N> struct sieve_t {
  int b[N], p[N], n, e[N], d[N], f[N], c[N], m[N];
  sieve_t() {
    memset(this, 0, sizeof(sieve_t));
    d[1] = m[1] = 1;
    for (int i = 2; i < N; i++) {
      if (!b[i]) {
        e[i] = i-1;
        c[i] = 1;
        d[i] = 2;
        f[i] = i;
        m[i] = -1;
        p[n++] = i;
      }
      for (int j = 0; j < n && 1ll*i*p[j] < N; j++) {
        int k = i*p[j];
        b[k] = 1;
        f[k] = p[j];
        if (i%p[j]) {
          e[k] = e[i]*(p[j]-1);
          c[k] = 1;
          d[k] = d[i]*(c[k]+1);
          m[k] = m[i]*m[p[j]];
        } else {
          e[k] = e[i]*p[j];
          c[k] = c[i]+1;
          d[k] = d[i]/(c[i]+1)*(c[k]+1);
          m[k] = 0;
          break;
        }
      }
    }
  }
};

sieve_t<N> sieve;
int n, a, b, c, d, k, sm[N];

ll_t sum(int x, int y) {
  if (x > y) swap(x, y);
  ll_t f = 0;
  for (int i = 1, r = 0; i <= x; i = r+1) {
    r = min(x/(x/i), y/(y/i));
    f += 1ll*(sm[r]-sm[i-1])*(x/i)*(y/i);
  }
  return f;
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for (int i = 1; i < N; i++) sm[i] = sm[i-1]+sieve.m[i];
  for ( ; ~scanf("%d", &n); ) {
    for ( ; n--; ) {
      scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
      a = (a-1)/k;
      b = b/k;
      c = (c-1)/k;
      d = d/k;
      printf("%lld\n", sum(b, d)-sum(a, d)-sum(b, c)+sum(a, c));
    }
  }
  return 0;
}
