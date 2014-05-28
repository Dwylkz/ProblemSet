#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5+10;
typedef vector<int> vi_t;

int n, t[N], f[N], out[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    for (int i = 0; i < n; i++) scanf("%d", t+i);
    memset(out, 0, sizeof(out));
    for (int i = 0; i < n; i++) {
      scanf("%d", f+i);
      f[i]--;
      if (~f[i]) out[f[i]]++;
    }
#if 0
    printf("f: ");
    for (int i = 0; i < n; i++) printf(" %d", f[i]);
    puts("");
#endif
    vi_t rv;
    for (int i = 0; i < n; i++)
      if (t[i]) {
        vi_t trv;
        for (int u = i; out[u] < 2; u = f[u]) {
          trv.push_back(u+1);
          if (f[u] < 0) break;
        }
        if (trv.size() > rv.size()) rv = trv;
      }
    printf("%d\n", (int)rv.size());
    for (int i = 0; i < rv.size(); i++)
      printf("%d%c", rv[rv.size()-i-1], i < rv.size()-1? ' ': '\n');
  }
  return 0;
}
