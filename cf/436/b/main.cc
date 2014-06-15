#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
const int N = 2e3+10;

int n, m, k, r[N]; 
char g[N][N];

int main()
{
  cin.sync_with_stdio(0);
  while (cin >> n >> m >> k) {
    for (int i = 0; i < n; i++)
      cin >> g[i];

    int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    char c[] = {'L', 'U', 'R', 'D'};
    memset(r, 0, sizeof(r));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        for (int k = 0; k < 4; k++) {
          int x = i+i*d[k][0];
          int y = j+i*d[k][1];
          if (0 <= x && x < n && 0 <= y && y < m
              && g[x][y] == c[k])
            r[j]++;
        }

    for (int i = 0; i < m; i++)
      printf("%d%c", r[i], i < m-1? ' ': '\n');
  }
  return 0;
}
