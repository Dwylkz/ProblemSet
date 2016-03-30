#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

static const int N = 1e3+5;

struct P
{
  int i, j, v;

  P()
  {}

  P(int i, int j, int v): i(i), j(j), v(v)
  {
  }

  friend bool operator < (const P& lhs, const P& rhs)
  {
    return lhs.v > rhs.v;
  }
};

int n, m, k, a[N][N], b[N][N], cnt[N][N], t[N][N];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
bool v[N][N];
vector<P> p;

vector<pair<int, int>> same;
set<int> gg;
int Count(int x, int y, int ta)
{
  if (v[x][y])
  {
    if (a[x][y] == ta) return 0;
    if (gg.count(t[x][y])) return 0;
    gg.insert(t[x][y]);
    return cnt[x][y];
  }
  v[x][y] = true;
  same.push_back(make_pair(x, y));
  int res = 1;
  for (int i = 0; i < 4; i++)
  {
    int tx = x+dx[i];
    int ty = y+dy[i];
    if (tx >= 0 && tx < n && ty >= 0 && ty < m && a[tx][ty] >= ta)
    {
      res += Count(tx, ty, ta);
    }
  }
  return res;
}

int remain;
void Fill(int x, int y, int ta)
{
  if (remain == 0) return ;
  if (v[x][y]) return ;
  remain--;
  v[x][y] = true;
  b[x][y] = ta;
  for (int i = 0; i < 4; i++)
  {
    int tx = x+dx[i];
    int ty = y+dy[i];
    if (tx >= 0 && tx < n && ty >= 0 && ty < m && a[tx][ty] >= ta)
    {
      Fill(tx, ty, ta);
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> a[i][j];
      p.push_back(P(i, j, a[i][j]));
    }
  }
  int g = 0;
  sort(p.begin(), p.end());
  for (int i = 0; i < p.size(); i++)
  {
    if (p[i].v == 0) continue;
    if (v[p[i].i][p[i].j] == true) continue;
    same.clear();
    gg.clear();
    int c = Count(p[i].i, p[i].j, p[i].v);
    g++;
    for (auto s: same)
    {
      cnt[s.first][s.second] = c;
      t[s.first][s.second] = g;
    }
    if (k%p[i].v == 0 && c >= k/p[i].v)
    {
      puts("YES");
      memset(v, false, sizeof(v));
      remain = k/p[i].v;
      Fill(p[i].i, p[i].j, p[i].v);
      for (int i = 0; i < n; i++)
      {
        for (int j = 0; j < m; j++)
        {
          printf("%d%c", b[i][j], j < m-1? ' ': '\n');
        }
      }
      return 0;
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      printf("%d%c", cnt[i][j], j < m-1? ' ': '\n');
    }
  }
  puts("NO");
  return 0;
}
