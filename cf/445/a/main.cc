#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int N = 1e2+10;

int n, m;
char g[N][N];

void Flood(int x, int y, int c)
{
  g[x][y] = c? 'W': 'B';
  for (int i = 0; i < 4; i++) {
    int tx[] = {x, x+1, x, x-1};
    int ty[] = {y+1, y, y-1, y};
    if (0 <= tx[i] && tx[i] < n && 0 <= ty[i] && ty[i] < m
        && g[tx[i]][ty[i]] == '.')
      Flood(tx[i], ty[i], 1-c);
  }
}

int main()
{
  cin.sync_with_stdio(0);
  for ( ; cin >> n >> m; ) {
    for (int i = 0; i < n; i++)
      cin >> g[i];

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (g[i][j] == '.')
          Flood(i, j, 0);

    for (int i = 0; i < n; i++)
      cout << g[i] << endl;
  }
  return 0;
}
