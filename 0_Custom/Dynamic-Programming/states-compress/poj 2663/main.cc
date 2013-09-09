#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long LL;
const int N = 11;

struct hm_t {
  static const int n = 1317;
  struct node {
     int to, k;
     LL w;
  };
  vector<node> h;
  int s[n];
  void init() {
    h.clear();
    memset(s, -1, sizeof(s));
  }
  int operator () (int k, LL w) {
    int u = k%n;
    for (int i = s[u]; ~i; i = h[i].to)
      if (k == h[i].k) {
        h[i].w += w;
        return i;
      }
    node t = {s[u], k, w};
    s[u] = h.size();
    h.push_back(t);
    return h.size()-1;
  }
  node &operator [] (int i) {
    return h[i];
  }
};

int n, m = 3;
hm_t h[2];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n), ~n; ) {
    int t = 0;
    h[0].init();
    h[0](0, 1);
    for (int i = 0; i < n; i++) {
      int li = 0, ui = 1;
      for (int j = 0; j < m; j++) {
        h[!t].init();
        for (int k = 0; k < h[t].h.size(); k++) {
          int s = h[t][k].k, l = s>>li&1, u = s>>ui&1;
          LL w = h[t][k].w;
          if (!l && !u) {
            if (i < n-1) h[!t](s|(1<<li), w);
            if (j < m-1) h[!t](s|(1<<ui), w);
          } else if (l && !u) {
            h[!t](s^(1<<li), w);
          } else if (!l && u) {
            h[!t](s^(1<<ui), w);
          }
        }
        t ^= 1;
        li++, ui++;
      }
      for (int j = 0; j < h[t].h.size(); j++)
        h[t][j].k <<= 1;
    }
    printf("%lld\n", h[t][h[t](0, 0)].w);
  }
  return 0;
}
