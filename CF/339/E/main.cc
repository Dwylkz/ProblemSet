#include <map>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <cctype>
#include <string.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
const int N = 1e3+10;

int n, s[N], t[N];

int main()
{
#if 1
	freopen("input.txt", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    for (int i = 1; i <= n; i++) s[i] = i;
    for (int i = 1; i <= n; i++) scanf("%d", t+i);
    int yes = 1;
    for (int i = 1; i <= n; i++) if (s[i] != t[i]) {
      yes = 0;
      break;
    }
    if (yes) puts("0");
    else {
      int x1, y1;
      for (int i = 1; i <= n; i++)
        if (t[i] != i) {
          x1 = i;
          break;
        }
      for (int i = 1; i <= n; i++)
        if (t[i] == x1) {
          y1 = i;
          break;
        }
      if (x1 > y1) swap(x1, y1);
      for (int i = x1, j = y1; i < j; i++, j--) swap(t[i], t[j]);
      int x2, y2;
      for (int i = 1; i <= n; i++)
        if (t[i] != i) {
          x2 = i;
          break;
        }
      y2 = t[x2];
      if (x2 > y2) swap(x2, y2);
      for (int i = x2, j = y2; i < j; i++, j--) swap(s[i], s[j]);
      yes = 1;
      for (int i = 1; i <= n; i++) if (s[i] != t[i]) {
        yes = 0;
        break;
      }
      if (yes) printf("%d %d\n%d %d\n", x1, y1, x2, y2);
      else {
        int x = 1, y = n;
        for ( ; s[x] == t[x]; x++) ;
        for ( ; s[y] == t[y]; y--) ;
        printf("%d %d\n%d %d\n%d %d\n", x1, y1, x, y, x2, y2);
      }
    }
  }
	return 0;
}
