#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e6+10;

template<class T> struct kmp_t {
  void operator () (T *p, int pl, int *f) {
    int i = 0, j = f[0] = -1;
    for ( ; i < pl; i++, j++, f[i] = p[i] == p[j]? f[j]: j)
      for ( ; ~j && p[i] != p[j]; ) j = f[j];
  }
  int operator () (T *s, int sl, T *p, int pl, int *f) {
    int i = 0, j = 0;
    for ( ; i < sl && j < pl; i++, j++)
      for ( ; ~j && s[i] != p[j]; ) j = f[j];
    return j;
  }
};

kmp_t<char> zkl;
char a[N], b[N];
int f[N], g[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  for ( ; T--; ) {
    scanf("%s%s", a, b);
    int al = strlen(a), bl = strlen(b), rv = 0;
    zkl(b, bl, f);
    rv = max(rv, zkl(a, al, b, bl, f));
    zkl(a, al, f);
    rv = max(rv, zkl(b, bl, a, al, f));
    printf("%d\n", al+bl-rv);
  }
  return 0;
}
