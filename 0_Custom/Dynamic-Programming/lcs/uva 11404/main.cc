#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
const int N = 1e3+10;

char s[N], b[N];

struct dp_t {
  string s;
  dp_t() {
    s = "";
  }
  friend bool operator < (const dp_t &lhs, const dp_t &rhs) {
    return lhs.s.length() == rhs.s.length()?
      lhs.s < rhs.s:
      lhs.s.length() > rhs.s.length();
  }
} f[N][N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%s", s); ) {
    int n = strlen(s);
    strcpy(b, s);
    reverse(b, b+n);
    for (int i = 0; i <= n; i++)
      f[i][0].s = f[0][i].s = "";
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        if (s[i-1] == b[j-1]) {
          f[i][j] = f[i-1][j-1];
          f[i][j].s += s[i-1];
        } else f[i][j] = min(f[i][j-1], f[i-1][j]);
    if (f[n][n].s.length()&1) {
      dp_t ans;
      for (int i = 1; i <= n; i++)
        ans = min(ans, f[i][n-i+1]);
      printf("%s", ans.s.data());
      ans.s = ans.s.substr(0, ans.s.length()-1);
      reverse(ans.s.begin(), ans.s.end());
      puts(ans.s.data());
    } else {
      dp_t ans;
      for (int i = 1; i <= n; i++)
        ans = min(ans, f[i][n-i]);
      printf("%s", ans.s.data());
      reverse(ans.s.begin(), ans.s.end());
      puts(ans.s.data());
    }
  }
  return 0;
}
