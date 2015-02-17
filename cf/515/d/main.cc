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

const int N = 2e3+5;
const char* FAIL = "Not unique";
const int DN = 4;
const int D[DN][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
const int C[DN][2] = {{'<', '>'}, {'^', 'v'}, {'>', '<'}, {'v', '^'}};

typedef pair<int, int> PII;

int n, m;
char b[N][N];

bool IsValid(int x, int y)
{
  return 0 <= x && x < n && 0 <= y && y < m && b[x][y] == '.';
}

bool Check(int x, int y, int* rx, int* ry)
{
  int cnt = 0, ri = 0;
  for (int i = 0; i < DN; i++) {
    int tx = x+D[i][0];
    int ty = y+D[i][1];
    if (!IsValid(tx, ty)) {
      continue;
    }
    ri = i;
    cnt++;
    *rx = tx;
    *ry = ty;
    if (cnt > 1) {
      return false;
    }
  }
  b[x][y] = C[ri][0];
  b[*rx][*ry] = C[ri][1];
  return true;
}

int main()
{
  scanf("%d%d", &n, &m);
  deque<PII> q;
  int nw = 0, nb = 0;
  for (int i = 0; i < n; i++) {
    scanf("%s", b[i]);
    for (int j = 0; j < m; j++) {
      if (b[i][j] == '*') {
        continue;
      }
      if ((i+j)%2 == 0) {
        nw++; 
      } else {
        nb++;
      }
      q.push_back(PII(i, j));
    }
  }
  if (nw != nb) {
    puts(FAIL);
    return 0;
  }
  // puts("pass");
  while (q.size() > 0) {
    PII c = q.front();
    q.pop_front();
    int x, y;
    if (!IsValid(c.first, c.second) || !Check(c.first, c.second, &x, &y)) {
      continue;
    }
    for (int i = 0; i < DN; i++) {
      int tx = x+D[i][0];
      int ty = y+D[i][1];
      if (!IsValid(tx, ty)) {
        continue;
      }
      q.push_back(PII(tx, ty));
    }
  }
  for (int i = 0; i < n; i++) {
    if (count(b[i], b[i]+m, '.') > 0) {
      puts(FAIL);
      return 0;
    }
  }
  for (int i = 0; i < n; i++) {
    puts(b[i]);
  }
  return 0;
}
