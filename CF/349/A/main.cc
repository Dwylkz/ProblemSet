#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e5+10;

int n;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    int c[101] = {0}, yes = 1;
    for (int i = 0, si; i < n; i++) {
      scanf("%d", &si);
      si -= 25;
      if (si == 100) {
        if (c[100]) c[100]--;
        else if (c[50] > 1) c[50] -= 2;
        else if (c[50] && c[25] > 1) c[50]--, c[25] -= 2;
        else if (c[25] > 3) c[25] -= 4;
        else yes = 0;
      } else if (si == 75) {
        if (c[50] && c[25]) c[50]--, c[25]--;
        else if (c[25] > 2) c[25] -= 3;
        else yes = 0;
      } else if (si == 50) {
        if (c[50]) c[50]--;
        else if (c[25] > 1) c[25]--;
        else yes = 0;
      } else if (si == 25) {
        if (c[25]) c[25]--;
        else yes = 0;
      }
      c[si+25]++;
    }
    puts(yes? "YES": "NO");
  }
  return 0;
}
