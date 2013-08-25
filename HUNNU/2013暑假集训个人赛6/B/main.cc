#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int n;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  for ( ; T--; ) {
    scanf("%d", &n);
    vector<int> o;
    int pos = 0;
    for (int i = 0; i < n; i++) {
      char op[10];
      scanf("%s", op);
      if (*op == 'L') {
        o.push_back(-1);
        pos--;
      } else if (*op == 'R') {
        o.push_back(-2);
        pos++;
      } else {
        int x;
        scanf("%*s%d", &x);
        o.push_back(--x);
        for (x = o[x]; x >= 0; x = o[x]) ;
#if 0
        printf("x = %d\n", x);
#endif
        if (x == -1) pos--;
        else pos++;
      }
    }
#if 0
    for (int i = 0; i < o.size(); i++)
      printf("%3d ", o[i]);
    puts("");
#endif
    printf("%d\n", pos);
  }
  return 0;
}
