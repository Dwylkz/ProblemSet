#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdio>
#include <cctype>
#include <string.h>
#include <string>
#include <math.h>
#include <stdint.h>
#include <iostream>
using namespace std;
const int maxn = 2020;
typedef unsigned long long LL;
#define Rep(c, a, b) for (int c = a; c < (b); c++)

int n, t, s[maxn * maxn], m[maxn][maxn];

LL DFS(int x, int y, int r)
{
#define mv(i, j) (LL)m[x + i][y + j]
#define ls(x) (x + (r >> 1))
  if (r == 1) {
    if (!m[x][y]) {
      m[x][y] = s[t++];
    }
    return m[x][y];
  }
  if (!m[ls(x)][ls(y)]) {
    m[ls(x)][ls(y)] = s[t++];
  }
  if (!m[ls(x) - 1][ls(y)]) {
    m[ls(x) - 1][ls(y)] = s[t++];
  }
  if (!m[ls(x)][ls(y) - 1]) {
    m[ls(x)][ls(y) - 1] = s[t++];
  }
  if (!m[ls(x) - 1][ls(y) - 1]) {
    m[ls(x) - 1][ls(y) - 1] = s[t++];
  }
  LL res = DFS(ls(x), ls(y), r >> 1)
       + DFS(ls(x), y, r >> 1)
       + DFS(x, ls(y), r >> 1)
       + DFS(x, y, r >> 1);
  LL mx = m[y][y];
  Rep(i, 0, r) {
    Rep(j, 0, r) {
      mx = max(mx, mv(i, j));
    }
  }
#if 0
  printf("bt = %lld\n", res + mx);
  Rep(i, x, x + r) {
    Rep(j, y, y + r) {
      printf("%5d", m[i][j]);
      putchar(j == y + r - 1? '\n': ' ');
    }
  }
#endif
  return res + mx;
#undef ls
#undef sf
}

int main()
{
#if 1
  freopen("input.txt", "r", stdin);
#endif
  for ( ; cin >> n; ) {
    Rep(i, 0, n) {
      cin >> s[i];
    }
    sort(s, s + n, greater<int>());
    int o = 0;
    for ( ; n; n >>= 1) {
      o++;
    }
    n = 1 << (o >> 1);
    Rep(i, 0, n) {
      Rep(j, 0, n) {
        m[i][j] = s[i * n + j];
      }
    }
    t = 0;
    memset(m, 0, sizeof(m));
    cout << DFS(0, 0, n) << endl;
#if 0
    Rep(i, 0, n) {
      Rep(j, 0, n) {
        printf("%5d", m[i][j]);
        putchar(j == n - 1? '\n': ' ');
      }
    }
#endif
  } 
  return 0;
}
