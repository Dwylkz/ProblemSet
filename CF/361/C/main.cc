#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 5e3+10;
const int inf = 2e8;

int n, m, d[N], s[N];

struct op_t {
  int op, a, b, c;
  void input() {
    scanf("%d%d%d%d", &op, &a, &b, &c);
    a--, b--;
  }
} op[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &m); ) {
    memset(d, 0, sizeof(d));
    fill(s, s+n, inf);
    for (int i = 0; i < m; i++) {
      op[i].input();
      if (op[i].op == 1)
        for (int j = op[i].a; j <= op[i].b; j++)
          d[j] += op[i].c;
      else
        for (int j = op[i].a; j <= op[i].b; j++)
          s[j] = min(s[j], op[i].c-d[j]);
    }
    bool yes = 1;
    memcpy(d, s, sizeof(s));
    for (int i = 0; i < m; i++)
      if (op[i].op == 1)
        for (int j = op[i].a; j <= op[i].b; j++)
          s[j] += op[i].c;
      else {
        int mx = -inf;
        for (int j = op[i].a; j <= op[i].b; j++)
          mx = max(mx, s[j]);
        if (mx != op[i].c) {
          yes = 0;
          break;
        }
      }
    if (yes) {
      puts("YES");
      for (int i = 0; i < n; i++)
        printf("%d%c", d[i], i < n-1? ' ': '\n');
    } else puts("NO");
  }
  return 0;
}
