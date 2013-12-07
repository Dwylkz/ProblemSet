#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 3e3+10;

int n, m, d[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &m); ) {
    for (int i = 0; i < m; i++) scanf("%d", d+i);
    sort(d, d+m);
    if (d[0] == 1 || d[m-1] == n) {
      puts("NO");
      continue;
    }
#if 0
    for (int i = 0; i < m; i++)
      printf(" %d", d[i]);
    puts("");
#endif
    int yes = 1;
    for (int i = 0; i < m; i++) {
      int j = i+1;
      for ( ; j < m && d[j] == d[j-1]+1; ) j++;
      if (j-i > 2) {
        yes = 0;
        break;
      }
      i = j-1;
    }
    puts(yes? "YES": "NO");
  }
  return 0;
}
