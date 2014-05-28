#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e6+10;

template<class T> struct kmp_t {
  void get(T *p, int pl, int *f) {
    for (int i = 0, j = f[0] = -1; i < pl; f[++i] = ++j)
      for ( ; ~j && p[i] != p[j]; ) j = f[j];
  }
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
template<class T, class C> struct mnn_t {
  int operator () (T *s, int n) {
    int i = 0, j = 1;
    for (int k = 0; k < n; )
      if (s[(i+k)%n] == s[(j+k)%n]) k++;
      else if (C()(s[(i+k)%n], s[(j+k)%n])) j += k+1, k = 0;
      else i += k+1, j = i+1, k = 0;
    return i;
  }
};

char s[N];
int f[N];
kmp_t<char> kmp;
mnn_t<char, less<char> > mnn;
mnn_t<char, greater<char> > mxn;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%s", s); ) {
    int n = strlen(s);
    kmp.get(s, n, f);
#if 0
    for (int i = 0; i <= n; i++) printf(" %d", f[i]);
    puts("");
#endif
    int c = n%(n-f[n])? 1: n/(n-f[n]);
    printf("%d %d %d %d\n", mnn(s, n)+1, c, mxn(s, n)+1, c);
  }
  return 0;
}
