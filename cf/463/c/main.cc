#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

const int N = 2e3+10;


int n, a[N][N];
LL m[N][N];

bool Check(int x, int y)
{
  return x >= 0 && x < n && y >= 0 && y < n;
}

void Walk(int x, int y, int dx, int dy)
{
  LL s = 0;
  for (int j = 1; j < n; j++) {
    int tx = x+dx;
    int ty = y+dy;
    if (!Check(tx, ty)) 
      break;

    s += a[x][y];
    m[tx][ty] += s;

    x = tx;
    y = ty;
  }
}

int main()
{
  cin.sync_with_stdio(0);
  while (cin >> n) {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        cin >> a[i][j];

    memset(m, 0, sizeof(m));
    for (int i = 0; i < n; i++) {
      Walk(0, i, 1, 1);
      Walk(n-i-1, n-1, -1, -1);
      if (i) {
        Walk(i, 0, 1, 1);
        Walk(n-1, n-i-1, -1, -1);
      }

      Walk(0, i, 1, -1);
      Walk(i, 0, -1, 1);
      if (i) {
        Walk(i, n-1, 1, -1);
        Walk(n-1, i, -1, 1);
      }
    }

    VI v[2];
    for (int i = 0; i < n*n; i++) {
      m[i/n][i%n] += a[i/n][i%n];
      v[(i/n+i%n)&1].push_back(i);
    }

    for (int i = 0; i < 2; i++)
      sort(v[i].begin(), v[i].end(), [&](int a, int b){return m[a/n][a%n] > m[b/n][b%n];});

    cout << m[v[0][0]/n][v[0][0]%n]+m[v[1][0]/n][v[1][0]%n] << endl;
    cout << v[0][0]/n+1 << " " << v[0][0]%n+1 << " " << v[1][0]/n+1 << " " << v[1][0]%n+1 << endl;
  }

  return 0;
}
