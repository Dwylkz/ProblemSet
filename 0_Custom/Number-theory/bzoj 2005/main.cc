#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll_t;
const int N = 1e6+10;

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
int n, m;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &m); ) {
    ll_t f = 0;
    if (n > m) swap(n, m);
    for (int i = 1; i <= n; i++)
      for (int j = 1, rt = sqrt(i); j <= rt; j++) {
        if (i%j) continue;
        int k = i/j;
        f += 1ll*(j-1<<1|1)*sieve.m[i/j]*(n/i)*(m/i);
        if (j != k) f += 1ll*(k-1<<1|1)*sieve.m[i/k]*(n/i)*(m/i);
      }
    printf("%lld\n", f);
  }
  return 0;
}
