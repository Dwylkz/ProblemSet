#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;
const int N = 1e5+10;
typedef map<int, int> mii_t;
typedef long long LL;
#define _i(t) t::iterator

/* Suffix Array
 * Notice that the input array should end with 0 (s[s's length-1] = 0)
 * and then invoke dc3, remember to expand N to 3 times of it. */
template<int N> struct sa_t {
  int wa[N], wb[N], wv[N], ws[N], r[N];
  void da(int *s, int n, int *sa, int m) {
#define da_F(c, a, b) for (int c = (a); i < (b); i++)
#define da_C(s, a, b, l) (s[a] == s[b] && s[a+l] == s[b+l])
#define da_R(x, y, z) da_F(i, 0, m) ws[i] = 0; da_F(i, 0, n) ws[x]++;\
    da_F(i, 1, m) ws[i] += ws[i-1]; da_F(i, 0, n) sa[--ws[y]] = z;
    int *x = wa, *y = wb;
    da_R(x[i] = s[i], x[n-i-1], n-i-1);
    for(int j = 1,  p = 1; p < n; j *= 2, m = p) {
      da_F(i, (p = 0, n-j), n) y[p++] = i;
      da_F(i, 0, n) if(sa[i] >= j) y[p++] = sa[i]-j;
      da_F(i, 0, n) wv[i] = x[y[i]];
      da_R(wv[i], wv[n-i-1], y[n-i-1]);
      da_F(i, (swap(x, y), x[sa[0]] = 0, p = 1), n)
        x[sa[i]] = da_C(y, sa[i-1], sa[i], j)? p-1: p++;
    }
  }
  void ch(int *s, int n, int *sa, int *h) {
    for (int i = 1; i < n; i++) r[sa[i]] = i;
    for (int i = 0, j, k = 0; i < n-1; h[r[i++]] = k)
      for (k? k--: 0, j = sa[r[i]-1]; s[i+k] == s[j+k]; k++);
  }
  void icats(int *b, int *l, char *s) {
    static int delim = 'z'+1;
    for (*l += strlen(s)+1; *s; s++) *b++ = *s;
    *b++ = delim++;
  }
};
/* RMQ Sparse Table
 * */
template<int N> struct rmq_t {
  int s[20][N], *k;
  void operator () (int l, int *_k) {
    k = _k;
    for (int i = 0; i < l; i++) s[0][i] = i;
    for (int i = 1; i < 20; i++)
      if ((1<<i) <= l) for (int j = 0; j < l; j++)
        if (k[s[i-1][j]] < k[s[i-1][j+(1<<(i-1))]]) s[i][j] = s[i-1][j];
        else s[i][j] = s[i-1][j+(1<<(i-1))];
  }
  int operator () (int l, int r) {
    if (l > r) swap(l ,r);
    int i = r-l+1, o = 1, j = 0;
    for (int o = 1 ; o <= i; o <<= 1) j++;
    j--, r = r-(1<<j)+1;
    return k[s[j][l]] < k[s[j][r]]? s[j][l]: s[j][r];
  }
};

typedef sa_t<N> sa_i;
typedef rmq_t<N> rmq_i;

sa_i sa;
rmq_i rmq;
int n, f, p[N], s[N], h[N], r[N];

bool look(int a, int c, int dt) {
  for (int i = 0; i <= dt; i++)
    if (p[a+i] != p[c+i]) return 0;
  return 1;
}
int lcp(int a, int c) {
  if (r[a] > r[c]) swap(a, c);
  return h[rmq(r[a]+1, r[c])];
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &f); ) {
    mii_t d;
    for (int i = 0; i < n; i++) {
      scanf("%d", p+i);
      d[p[i]] = 1;
    }
    int rank = 0;
    for (_i(mii_t) i = d.begin(); i != d.end(); i++)
      i->second = ++rank;
    for (int i = 0; i < n; i++) p[i] = d[p[i]];
    int l = n+1;
    p[l-1] = 0;
    sa.da(p, l, s, d.size()+1);
    sa.ch(p, l, s, h);
    for (int i = 0; i < l; i++) r[s[i]] = i;
    rmq(l, h);
#if 0
    printf("i : ");
    for (int i = 0; i < n; i++) printf(" %2d", i);
    puts("");
    printf("p : ");
    for (int i = 0; i < n; i++) printf(" %2d", p[i]);
    puts("");
    printf("sa:\n");
    for (int i = 0; i < n; i++) {
      printf("i=%2d s=%2d h=%2d:", i, s[i], h[i]);
      for (int j = s[i]; j < n; j++) printf(" %d", p[j]);
    puts("");
    }
#endif
    LL rv = 0;
    for (int a = 0; a < n; a++)
      for (int dt = 0; a+f+1+2*dt < n; dt++) {
        int c = a+f+1+dt;
//         rv += look(a, c, dt);
#if 0
        printf("lcp(%2d->%2d, %2d->%2d) = %2d dt = %2d\n",
            a, r[a], c, r[c], lcp(a, c), dt);
#endif
        rv += lcp(a, c) > dt;
      }
    cout << rv << endl;
  }
  return 0;
}
