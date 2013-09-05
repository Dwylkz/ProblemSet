#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
const int N = 1e3+10;

char s[N], b[N];
string f[N][N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%s", s); ) {
    int n = strlen(s);
    strcpy(b, s);
    reverse(b, b+n);
    for (int i = 0; i <= n; i++) f[0][i] = f[i][0] = "";
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        if (s[i-1] == b[j-1]) {
          f[i][j] = f[i-1][j-1]+s[i-1];
        } else if (f[i][j-1].length() == f[i-1][j].length() && f[i][j-1] < f[i-1][j]
            || f[i][j-1].length() > f[i-1][j].length()) {
          f[i][j] = f[i][j-1];
        } else {
          f[i][j] = f[i-1][j];
        }
    puts(f[n][n].data());
  }
  return 0;
}
