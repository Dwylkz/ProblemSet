#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e3+10;
const int M = 26;
const int inf = 0x3f3f3f3f;

/* f(n, c): the minimum chunks when the a sequence, say S which |S| = n and end with c.
 * b(i, h, t): the minimum chunks in a blocks when the block start with h and end with t. */
int k, f[N][M], b[N][M][M], cnt[N];
char s[N];

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  int T;
  scanf("%d", &T);
  for ( ; T--; ) {
    scanf("%d%s", &k, s);
    int sl = strlen(s), n = sl/k;
    for (int i = 0; i < n; i++) {
      int h[M] = {0}, id = 0;
      cnt[i] = 0;
      for (int j = i*k; j < i*k+k; j++) h[s[j]-'a'] = 1;
      for (int j = 0; j < M; j++)
        if (h[j]) {
          id = j;
          cnt[i]++;
        }
      memset(b[i], 0x3f, sizeof(b[i]));
      if (cnt[i] == 1) {
        b[i][id][id] = cnt[i];
        continue;
      }
      for (int j = 0; j < M; j++)
        for (int k = 0; k < M; k++)
          if (h[j] && h[k] && j != k) b[i][j][k] = cnt[i];
    }
#if 0
    printf("cnt: ");
    for (int i = 0; i < n; i++) printf(" %4d", cnt[i]);
    puts("");
#endif
    memset(f, 0x3f, sizeof(f));
    for (int i = 0; i < M; i++)
      for (int j = 0; j < M; j++)
        if (b[0][j][i] != inf) {
          f[0][i] = cnt[0];
          break;
        }
#if 0
    printf("f:\n");
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < M; j++)
        printf(" %4d", f[i][j] == inf? -1: f[i][j]);
      puts("");
    }
#endif
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < M; j++) {
        for (int k = 0; k < M; k++) {
          for (int t = 0; t < M; t++) {
            if (f[i-1][k] == inf || b[i][t][j] == inf) continue;
            f[i][j] = min(f[i][j], f[i-1][k]+b[i][t][j]-(k == t));
          } // i's head
        } // i-1's tail
      } // i's tail
    } // block
    int mn = inf;
    for (int i = 0; i < M; i++) mn = min(mn, f[n-1][i]);
    printf("%d\n", mn);
  }
  return 0;
}
