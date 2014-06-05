#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5+10;
const int M = 3e4+10;

int n, x[N], a[N], y[N], mx[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    for (int i = 0; i < n; i++) scanf("%d", x+i);
    for (int i = 0; i < n; i++) scanf("%d", a+i);
    int px = 0;
    for (int i = 2; i < n; i += 3) {
      int ll = i-2, l = i-1, r = i+1;
      x[i] = a[l]-a[ll]+px;
      px = x[i];
    }
    px = 0;
    for (int i = n-3; i >= 0; i -= 3) {
      int ll = i+2, l = i+1, r = i-1;
      x[i] = a[l]-a[ll]+px;
      px = x[i];
    }
    int id = -1;
    for (int i = 1; i < n; i++)
      if (~x[i] && ~x[i-1]) {
        id = i;
        break;
      }
    if (~id) {
      for (int i = id+1; i < n; i++)
        x[i] = a[i-1]-x[i-1]-x[i-2];
      for (int i = id-2; i >= 0; i--)
        x[i] = a[i+1]-x[i+1]-x[i+2];
    } else {
      memcpy(mx, x, sizeof(x));
      for (int i = 0; i <= a[0]; i++) {
        y[0] = i;
        y[1] = a[0]-y[0];
        if (y[1] < 0 || (~x[1] && x[1] != y[1])) continue;
        int flag = 1;
        for (int j = 2; j < n; j++) {
          y[j] = a[j-1]-a[j-2]+y[j-2];
          if (y[j] < 0 || (~x[j] && x[j] != y[j])) {
            flag = 0;
            break;
          }
        }
        if (!flag || y[n-2]+y[n-1] != a[n-1]) continue;
        for (int j = 0; j < n; j++) mx[j] = max(mx[j], y[j]);
      }
      memcpy(x, mx, sizeof(mx));
    }
    int m;
    scanf("%d", &m);
    for ( ; m--; ) {
      int i;
      scanf("%d", &i);
      printf("%d\n", x[i]);
    }
  }
  return 0;
}
