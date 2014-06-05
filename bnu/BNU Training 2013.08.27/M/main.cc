#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int N = 20+1;
typedef pair<int, int> pii_t;
#define _x first
#define _y second
typedef vector<pii_t> vp_t;
typedef vector<vp_t> vvp_t;
typedef vector<int> vi_t;

int n;
char m[N][N], ban[N][N];

int to[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
vp_t b;
struct block {
  vp_t b[4];
  int c;
  friend bool operator < (block lhs, block rhs) {
    return lhs.b[0].size() > rhs.b[0].size();
  }
};
vector<block> bs;
void dfs(int x, int y) {
  ban[x][y] = 1;
  b.push_back(pii_t(x, y));
  for (int i = 0; i < 4; i++) {
    int tx = x+to[i][0], ty = y+to[i][1];
    if (0 <= tx && tx < 20
        && 0 <= ty && ty < 20
        && !ban[tx][ty]
        && m[tx][ty] == m[x][y]) dfs(tx, ty);
  }
}

void spin(vp_t &v) {
  vp_t t(v.size());
  for (int i = 0; i < t.size(); i++)
    t[i]._x = -v[i]._y, t[i]._y = v[i]._x;
  v = t;
}
vp_t spin(vp_t &v, int c) {
  vp_t t = v;
  for ( ; c--; ) spin(t);
  return t;
}
void show(vp_t v) {
  char t[10][10] = {0}, x = 4, y = 4;
  printf("%d points\n", (int)v.size());
  for (int i = 0; i < v.size(); i++)
    printf("\t(%2d, %2d)\n", v[i]._x, v[i]._y);
  for (int i = 0; i < v.size(); i++)
    t[x+v[i]._x][y+v[i]._y] = '#';
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++)
      if (t[i][j]) putchar(t[i][j]);
      else putchar('.');
    puts("");
  }
}

void paint(int x, int y, vp_t &v, int c) {
  for (int i = 0; i < v.size(); i++) {
    int tx = x+v[i]._x, ty = y+v[i]._y;
    m[tx][ty] = c;
  }
}

vp_t pos, tpos;
bool check(int x, int y, vp_t &v) {
  for (int i = 1; i < v.size(); i++) {
    int tx = x+v[i]._x, ty = y+v[i]._y;
    if (0 > tx || tx >= n || 0 > ty || ty >= n || ban[tx][ty])
      return 0;
  }
  return 1;
}
void rm(int x, int y, vp_t &v) {
  for (int i = 0; i < v.size(); i++) {
    int tx = x+v[i]._x, ty = y+v[i]._y;
    ban[tx][ty] = 1;
  }
  for (int i = 0; i < pos.size(); i++)
    if (ban[pos[i]._x][pos[i]._y]) {
      tpos.push_back(pos[i]);
      swap(pos[i], pos.back());
      pos.pop_back();
      i--;
    }
}
void rs(int x, int y, vp_t &v) {
  for (int i = 0; i < v.size(); i++) {
    int tx = x+v[i]._x, ty = y+v[i]._y;
    ban[tx][ty] = 0;
  }
  for (int i = 0; i < tpos.size(); i++)
    if (!ban[tpos[i]._x][tpos[i]._y]) {
      pos.push_back(tpos[i]);
      swap(tpos[i], tpos.back());
      tpos.pop_back();
      i--;
    }
}
bool match(int d) {
  if (d == bs.size()) return 1;
  for (int i = 0; i < pos.size(); i++) {
    int x = pos[i]._x, y = pos[i]._y;
    for (int k = 0; k < 4; k++) {
      vp_t &t = bs[d].b[k];
      if (!check(x, y, t)) continue;
      rm(x, y, t);
      if (match(d+1)) {
        paint(x, y, t, bs[d].c);
        return 1;
      }
      rs(x, y, t);
    }
  }
  return 0;
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    for (int i = 0; i < 20; i++) scanf("%s", m[i]);
    memset(ban, 0, sizeof(ban));
    bs.clear();
    for (int i = 0; i < 20; i++)
      for (int j = 0; j < 20; j++)
        if (m[i][j] != '.' && !ban[i][j]) {
          b.clear();
          dfs(i, j);
          for (int k = 0; k < b.size(); k++)
            b[k]._x -= i, b[k]._y -= j;
          block t;
          t.b[0] = b;
          for (int k = 1; k < 4; k++) {
            spin(b);
            t.b[k] = b;
          }
          t.c = m[i][j];
          bs.push_back(t);
        }
    sort(bs.begin(), bs.end());
    memset(ban, 0, sizeof(ban));
    pos.clear();
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        pos.push_back(pii_t(i, j));
    tpos.clear();
    if (!match(0)) puts("fuck");
    else for (int i = 0; i < n; i++) {
      m[i][n] = 0;
      printf("%s\n", m[i]);
    }
  }
  return 0;
}
