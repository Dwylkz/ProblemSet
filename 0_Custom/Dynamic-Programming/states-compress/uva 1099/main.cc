#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 100+10;
const int M = 15;
const int S = 1<<M;

/* bi               : means the i-th requirment.
 * sm(s=[s0...sn])  : means the total blocks of bi which si=1.
 * cnt(s=[s0...sn]) : means the amount of bi which si=1.
 * f(r, s=[s0...sn]): means if we could embed bi which si=1
 *                    into a rectangle with r row, sm(s) blocks;
 * */
int n, x, y, b[M], sm[S], cnt[S], f[N][S];

int dfs(int r, int s) {
  if (~f[r][s]) return f[r][s];
  if (cnt[s] == 1) return f[r][s] = 1;
  if (sm[s]%r) return f[r][s] = 0;
  int c = sm[s]/r;
  for (int z = (s-1)&s; z; z = (z-1)&s) {
    int y = s^z;
    if (sm[z]%r == 0 && dfs(min(r, sm[z]/r), z)
        && sm[y]%r == 0 && dfs(min(r, sm[y]/r), y)) return f[r][s] = 1;
    if (sm[z]%c == 0 && dfs(min(c, sm[z]/c), z)
        && sm[y]%c == 0 && dfs(min(c, sm[y]/c), y)) return f[r][s] = 1;
  }
  return f[r][s] = 0;
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for (int Case = 1; ~scanf("%d", &n), n; Case++) {
    scanf("%d%d", &x, &y);
    for (int i = 0; i < n; i++) scanf("%d", b+i);
    int sl = 1<<n;
    for (int s = 0; s < sl; s++) {
      sm[s] = cnt[s] = 0;
      for (int i = 0; i < n; i++)
        if (s>>i&1) {
          sm[s] += b[i];
          cnt[s]++;
        }
    }
    memset(f, -1, sizeof(f));
    printf("Case %d: ", Case);
    puts(sm[sl-1] == x*y && dfs(min(x, y), sl-1)? "Yes": "No");
  }
  return 0;
}
