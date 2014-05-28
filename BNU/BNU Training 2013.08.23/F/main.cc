#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int N = 2e2+10;
typedef pair<int, int> PII;

int n, m, l[N][N], use[N][N], g[N][N];

const int to[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
bool judge(int x, int y) {
  return 0 <= x && x < n && 0 <= y && y < m;
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &m); ) {
    vector<PII> q;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        scanf("%d", l[i]+j);
        if (l[i][j] == 1) q.push_back(PII(i, j));
      }
    vector<PII> ans;
    for (int h = 0; h < q.size(); h++) {
      int x = q[h].first, y = q[h].second;
      ans.push_back(PII(x, y));
      l[x][y] = 0;
      for (int i = 0; i < 4; i++) {
        int tx = x+to[i][0], ty = y+to[i][1];
        if (!judge(tx, ty)) continue;
        if (l[tx][ty] == 1) goto end;
        if (--l[tx][ty] == 1) q.push_back(PII(tx, ty));
      }
    }
end:
    if (ans.size() == n*m) for (int i = ans.size()-1; i >= 0; i--)
      printf("%d %d\n", ans[i].first+1, ans[i].second+1);
    else puts("No solution");
  }
  return 0;
}
