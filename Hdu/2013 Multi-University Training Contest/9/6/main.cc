#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 3e5+10;
typedef long long LL;

void sa_da(int *s, int n, int *sa, int m) {
#define da_F(c, a, b) for (int c = (a); i < (b); i++)
#define da_C(s, a, b, l) (s[a] == s[b] && s[a+l] == s[b+l])
#define da_R(x, y, z) da_F(i, 0, m) ws[i] = 0; da_F(i, 0, n) ws[x]++;\
  da_F(i, 1, m) ws[i] += ws[i-1]; da_F(i, 0, n) sa[--ws[y]] = z;
  static int wa[N], wb[N], wv[N], ws[N];
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
void sa_ch(int *s, int n, int *sa, int *h) {
  static int r[N];
  for (int i = 1; i < n; i++) r[sa[i]] = i;
  for (int i = 0, j, k = 0; i < n-1; h[r[i++]] = k)
    for (k? k--: 0, j = sa[r[i]-1]; s[i+k] == s[j+k]; k++);
}
void icats(int *b, int *l, char *s) {
  static int delim = 'z'+1;
  for (*l += strlen(s)+1; *s; s++) *b++ = *s;
  *b++ = delim++;
}
void rmq_init(int (*s)[N], int l, int *k) {
  for (int i = 0; i < l; i++) s[0][i] = i;
  for (int i = 1; i < 20; i++)
    if ((1<<i) <= l) for (int j = 0; j < l; j++)
      if (k[s[i-1][j]] < k[s[i-1][j+(1<<(i-1))]]) s[i][j] = s[i-1][j];
      else s[i][j] = s[i-1][j+(1<<(i-1))];
}
int rmq_ask(int (*s)[N], int l, int r, int *k) {
  if (l > r) swap(l ,r);
  int i = r-l+1, j = 0;
  for (int o = 1; o <= i; o <<= 1) j++;
  j--, r = r-(1<<j)+1;
  return k[s[j][l]] < k[s[j][r]]? s[j][l]: s[j][r];
}

char b[N];
int s[N], sa[N], h[N], rank[N], rmq[20][N];

int dw(int x) {
  if (!x) return 1;
  int rv = 0;
  for ( ; x; x /= 10) rv++;
  return rv;
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%s", b); ) {
    int sl = 0;
    icats(s, &sl, b);
    int gap = sl;
    icats(s+sl, &sl, b);
    s[sl++] = 0;
    sa_da(s, sl, sa, N);
    sa_ch(s, sl, sa, h);
    rmq_init(rmq, sl, h);
    for (int i = 0; i < sl; i++) rank[sa[i]] = i;
    int n, pl, pr;
    scanf("%d", &n);
    scanf("%d%d", &pl, &pr);
    LL in = pr-pl+1, out = in+2;
    for (n--; n--; ) {
      int l, r;
      scanf("%d%d", &l, &r);
      int len = r-l, p = min(len, min(pr-pl, h[rmq_ask(rmq, rank[l]+1, rank[gap+pl], h)]));
      in += len+1;
      out += dw(p)+1+(len-p)+1;
      pl = l ,pr = r;
    }
    printf("%lld %lld\n", in, out);
  }
  return 0;
}
