#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int N = 1e2+5;

int n, m;
char g[N][N];

int main()
{
  cin.tie(NULL);
  int kase = 1;
  while (cin >> n >> m && !(n == 0 && m == 0)) {
    for (int i = 0; i < n; i++)
      cin >> g[i];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (g[i][j] == '.')
          g[i][j] = '0';
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (g[i][j] == '*') {
          int tx[] = {i, i+1, i+1, i+1, i, i-1, i-1, i-1};
          int ty[] = {j+1, j+1, j, j-1, j-1, j-1, j, j+1};
          for (int k = 0; k < 8; k++) {
            int x = tx[k], y = ty[k];
            if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] != '*')
              g[x][y]++;
          }
        }
    if (kase > 1)
      cout << endl;
    printf("Field #%d:\n", kase);
    for (int i = 0; i < n; i++)
      cout << g[i] << endl; 
    kase++;
  }
  return 0;
}
