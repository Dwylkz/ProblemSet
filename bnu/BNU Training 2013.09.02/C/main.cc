#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e3+10;

char s[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  for ( ; T--; ) {
    scanf("%s", s);
    int n = strlen(s), sum = 0;
    for (char *i = s; *i; i++)
      sum += min(*i-'A', 'Z'+1-*i);
    int mn = n-1;
    for (int j, i = 1; i < n; i++)
      if (s[i] == 'A') {
        for (j = i+1; j <= n; j++)
          if (s[j] != 'A') break;
        mn = min(mn, min(i-1, n-j)+(i-1)+(n-j));
        i = j;
      }
    printf("%d\n", mn+sum);
  }
  return 0;
}
