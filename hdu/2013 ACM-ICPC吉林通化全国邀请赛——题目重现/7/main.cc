#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int N = 5+10;

struct p_t {
  int x, y;
};

int n, m, q, b[N][N], h[N][N], v[N][N], c[N*N];
vector<int> u[N*N*N];
vector<p_t> p;

int limit;
void dfs(int i = 0, int d = 0) {
  if (p.size()-i+d < limit) return ;
  limit = max(limit, d);
  if (i == p.size()) return ;
  dfs(i+1, d); // not use
  int x = p[i].x, y = p[i].y, hi = h[x][y], vi = v[x][y];
  for (int j = 0; j < u[hi].size(); j++) // check horizontal area.
    if (c[u[hi][j]] < 2) return ;
  for (int j = 0; j < u[vi].size() ;j++) // check vertical area.
    if (c[u[vi][j]] < 2) return ;
  if (!c[hi] || !c[vi]) return ; // check if there is a legal place left.
  c[hi]--, c[vi]--;
  dfs(i+1, d+1);
  c[hi]++, c[vi]++;
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d%d", &n, &m, &q); ) {
    memset(b, 0, sizeof(b));
    for (int i = 0; i < q; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      b[x][y] = 1;
      h[x][y] = v[x][y] = -1;
    }
    int id = 0;
    p.clear();
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (!b[i][j]) {
          p_t t = {i, j};
          p.push_back(t);
        }
    for (int i = 0; i < n*m*3; i++) u[i].clear();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (b[i][j]) {
          id++;
          u[id].push_back(id-1);
          u[id-1].push_back(id);
        } else h[i][j] = id;
      }
      id++;
    } // dividing horizontally
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (b[j][i]) {
          id++;
          u[id].push_back(id-1);
          u[id-1].push_back(id);
        } else v[j][i] = id;
      }
      id++;
    } // dividing vertically
    for (int i = 0; i < id; i++) c[i] = 2;
    limit = 0;
    dfs();
    printf("%d\n", limit);
  }
  return 0;
}
