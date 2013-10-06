#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e2+10;
const int inf = 0x3f3f3f3f;

int n;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    int s[10] = {0};
    for (int i = 0; i < n; i++) {
      int ai;
      scanf("%d", &ai);
      s[ai]++;
    }
    if (s[5]/9 && s[0]) {
      for (int i = s[5]/9; i; i--) printf("555555555");
      for (int i = 0; i < s[0]; i++) putchar('0');
      puts("");
    } else if (s[0]) puts("0");
    else puts("-1");
  }
  return 0;
}
