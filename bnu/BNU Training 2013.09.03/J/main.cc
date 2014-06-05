#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int eps = 1e4;
typedef long long LL;

int p[4][3];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d%d", p[0], p[0]+1, p[0]+2), p[0][0]|p[0][1]|p[0][2]; ) {
    for (int i = 1; i < 4; i++)
      for (int j = 0; j < 3; j++)
        scanf("%d", p[i]+j);
    int s[3] = {0}, t[3] = {0};
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
        s[j] += p[i][j];
    memcpy(t, p[3], sizeof(p[3]));
    LL lhs = 1ll*s[0]*s[1]*s[2], rhs = 1ll*t[0]*s[1]*s[2]+1ll*t[1]*s[0]*s[2]+1ll*t[2]*s[0]*s[1];
    puts(t[0] && t[1] && t[2] && lhs == rhs? "YES": "NO");
  }
  return 0;
}
