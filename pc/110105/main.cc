#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int N = 250+5;

int n, m;
char b[N][N];
char foo[BUFSIZ];

bool ban[N][N];
void Fill(int x, int y, int fc, int tc)
{
  if (x < 0 || x >= n || y < 0 || y >= m || b[x][y] != fc || ban[x][y])
    return ;
  ban[x][y] = true;
  b[x][y] = tc;
  int tx[] = {x, x+1, x, x-1};
  int ty[] = {y+1, y, y-1, y};
  for (int i = 0; i < 4; i++)
    Fill(tx[i], ty[i], fc, tc);
}

int main()
{
  while (gets(foo)) {
    char op[2];
    sscanf(foo, "%s", op);
    if (strlen(op) != 1)
      continue;
    switch (op[0]) {
      case 'I': {
        sscanf(foo, "%*s%d%d", &n, &m);
        memset(b, 'O', sizeof(b));
        break;
      }
      case 'C': {
        memset(b, 'O', sizeof(b));
        break;
      }
      case 'L': {
        int x, y;
        char c[2];
        sscanf(foo, "%*s%d%d%s", &x, &y, c);
        b[x-1][y-1] = c[0];
        break;
      }
      case 'V': {
        int x, y1, y2;
        char c[2];
        sscanf(foo, "%*s%d%d%d%s", &x, &y1, &y2, c);
        if (y1 > y2)
          swap(y1, y2);
        for (int i = y1-1; i < y2; i++)
          b[x-1][i] = c[0];
        break;
      }
      case 'H': {
        int x1, x2, y;
        char c[2];
        sscanf(foo, "%*s%d%d%d%s", &x1, &x2, &y, c);
        if (x1 > x2)
          swap(x1, x2);
        for (int i = x1-1; i < x2; i++)
          b[i][y-1] = c[0];
        break;
      }
      case 'K': {
        int x1, y1, x2, y2;
        char c[2];
        sscanf(foo, "%*s%d%d%d%d%s", &x1, &y1, &x2, &y2, c);
        for (int i = x1-1; i < x2; i++)
          for (int j = y1-1; j < y2; j++)
            b[i][j] = c[0];
        break;
      }
      case 'F': {
        int x, y;
        char c[2];
        sscanf(foo, "%*s%d%d%s", &x, &y, c);
        memset(ban, 0, sizeof(ban));
        Fill(x-1, y-1, b[x-1][y-1], c[0]);
        break;
      }
      case 'S': {
        char name[BUFSIZ];
        sscanf(foo, "%*s%s", name);
        puts(name);
        for (int i = 0; i < m; i++) {
          for (int j = 0; j < n; j++)
            putchar(b[j][i]);
          puts("");
        }
        break;
      }
      case 'X': {
        return 0;
        break;
      }
      default: {
      }
    }
  }
  return 0;
}
