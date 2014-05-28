#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
const int N = 2e3+10;

int n, m;
char b[N][N];

int dis[N][N], inT[N][N], t[N*N];
unordered_map<char, pair<int, int> > to = {
  {'>', {0, 1}},
  {'v', {1, 0}},
  {'<', {0, -1}},
  {'^', {-1, 0}}
};
bool inS[N][N], hasLoop;
int dfs(int x, int y) {
  if (hasLoop) return 0;
  if (b[x][y] == '#') return 0;
  if (~dis[x][y]) return dis[x][y];
  inS[x][y] = 1;
  int tx = x+to[b[x][y]].first, ty = y+to[b[x][y]].second;
  if (inS[tx][ty]) hasLoop = 1;
  dis[x][y] = dfs(tx, ty)+1;
  if (~inT[tx][ty]) inT[x][y] = inT[tx][ty];
  else inT[x][y] = x*m+y;
  t[inT[x][y]] = max(t[inT[x][y]], dis[x][y]);
  inS[x][y] = 0;
  return dis[x][y];
}

int main() {
#ifndef ONLINE_JUDGE 
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &m); ) {
    for (int i = 0; i < n; i++) scanf("%s", b+i);
    memset(dis, -1, sizeof(dis));
    memset(inS, 0, sizeof(inS));
    memset(inT, -1, sizeof(inT));
    memset(t, 0, sizeof(t));
    hasLoop = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        dfs(i, j);
    if (hasLoop) puts("-1");
    else {
      int mx1 = 0, mx2 = 0;
      for (int i = 0; i < n*m; i++)
        if (mx1 <= t[i]) {
          mx2 = mx1;
          mx1 = t[i];
        }
      printf("%d\n", max(mx1+mx2, 2*mx1-1));
    }
  }
  return 0;
}
