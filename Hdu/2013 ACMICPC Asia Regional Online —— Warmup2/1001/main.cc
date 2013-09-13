#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  for (int ks = 1; T--; ks++) {
    printf("Case #%d:\n", ks);
    int n;
    scanf("%d", &n);
    n /= 10;
    puts("*------------*");
    for (int i = 0; i < 10-n; i++)
      puts("|............|");
    for (int i = 0; i < n; i++)
      puts("|------------|");
    puts("*------------*");
  }
  return 0;
}
