#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int N = 50+10;
const int N2 = N*N+10;
typedef vector<int> VI;

int n, m;
char g[N][N];
bool f[N2][N2];
int to[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main() {
#ifndef ONLINE_JUDGE 
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &m); ) {
    for (int i = 0; i < n; i++)
      scanf("%s", g[i]);
    memset(f, 0, sizeof(f));
    int cnt = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (g[i][j] == 'B') {
          cnt++;
          VI cc;
          bool d[4] = {0};
          for (int a = 0; a < max(n, m); a++) {
            for (int b = 0; b < 4; b++)
              if (!d[b]) {
                int x = i+to[b][0]*a, y = j+to[b][1]*a;
                if (0 <= x && x < n && 0 <= y && y < m) {
                  if (g[x][y] == 'B') cc.push_back(x*m+y);
                  else d[b] = 1;
                }
              }
          }
          for (auto x: cc)
            for (auto y: cc)
              f[x][y] = f[y][x] = 1;
        }
    bool yes = 1;
    for (int i = 0; i < n*m; i++)
      if (g[i/m][i%m] == 'B') {
        int cnti = 0;
        for (int j = 0; j < n*m; j++)
          cnti += f[i][j];
        if (cnt != cnti) yes = 0;
      }
    puts(yes? "YES": "NO");
  }
  return 0;
}
