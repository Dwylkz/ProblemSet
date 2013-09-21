#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1e2+10;

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

kmp_t<char> kmp;
char a[N], b[N], v[N];
int g[N];
struct dp_t {
  string t;
  int p;
  dp_t(string _t = "", int _p = 0):
    t(_t), p(_p) {}
  int l() {
    return t.length();
  }
  friend bool operator < (const dp_t &lhs, const dp_t &rhs) {
    return lhs.t < rhs.t;
  }
  friend bool operator == (const dp_t &lhs, const dp_t &rhs) {
    return lhs.t == rhs.t;
  }
};
typedef vector<dp_t> vd_t;
vd_t f[N][N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%s%s%s", a, b, v); ) {
    int al = strlen(a), bl = strlen(b), vl = strlen(v);
    kmp(v, vl, g);
    for (int i = 0; i <= al; i++) f[i][0].push_back(dp_t("", 0));
    for (int i = 0; i <= bl; i++) f[0][i].push_back(dp_t("", 0));
    for (int i = 1; i <= al; i++)
      for (int j = 1; j <= bl; j++) {
        vd_t &tv = f[i][j];
        tv.clear();
        if (a[i-1] == b[j-1]) {
          for (int k = 0; k < f[i-1][j-1].size(); k++) {
            string &t = f[i-1][j-1][k].t;
            t += a[i-1];
            int bk = t.length()-1, &p = f[i-1][j-1][k].p;
            for ( ; ~p && t[bk] != v[p]; ) p = g[p];
            if (++p < vl) tv.push_back(f[i-1][j-1][k]);
          }
          sort(tv.begin(), tv.end());
          vd_t::iterator end = unique(tv.begin(), tv.end());
          tv.erase(end, tv.end());
          if (!tv.size())  tv.push_back(dp_t("", 0));
        } else if (f[i-1][j][0].l() == f[i][j-1][0].l()) {
          tv = f[i-1][j];
          tv.insert(tv.end(), f[i][j-1].begin(), f[i][j-1].end());
        } else if (f[i-1][j][0].l() > f[i][j-1][0].l()) tv = f[i-1][j];
        else tv = f[i][j-1];
      }
    if (f[al][bl][0].t == "") puts("0");
    else printf("%s\n", f[al][bl][0].t.data());
  }
  return 0;
}
