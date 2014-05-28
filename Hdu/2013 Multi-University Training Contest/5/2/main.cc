#include <cstdio>
#include <map>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 2100086+10;
typedef long long LL;

void bwt_decompress(char *L, char *S)
{
  static const int maxc = 256;
  static int P[maxn];
  int l = strlen(L), sum = S[l] = 0, C[maxc] = {0};
  for (int i = 0; i < l; i++) P[i] = C[L[i]]++;
  for (int c = 0; c < maxc; c++) sum += C[c], C[c] = sum - C[c];
  for (int i = 0, j = l-1; 0 <= j; j--) S[j] = L[i], i = P[i] + C[L[i]];
}
int kmp(char *s, char *p, int *f, int o)
{
  int sl = strlen(s), pl = strlen(p);
  for (int i = 0, j = -1; (o&1) && i<pl; i++) {
    for (j -= (j>=0); j!=-1 && p[i]!=p[j+1]; j = f[j]);
    f[i] = (j<0 || p[i]==p[j])? j++: -1;
  }
  for (int i = -1, j = -1; (o&2) && i<sl-1; i++) {
    for ( ; j!=-1 && s[i+1]!=p[j+1]; j = f[j]);
    if (s[i+1]==p[j+1] && ++j==pl-1) return i+1;
  }
  return -1;
}

char s[maxn], t[maxn];
int n, f[maxn];

int main()
{
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%s", s); ) {
    bwt_decompress(s, t);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%s", s);
      puts(kmp(t, s, f, 3) != -1? "YES": "NO");
    }
  }
  return 0;
}
