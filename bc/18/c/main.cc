#include <queue>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>
#include <memory>

using namespace std;

const int N = 1e3+5;
const int MOD = 1e9+7;

int Add(int a, int b)
{
  return (a+b)%MOD;
}

int Mul(int a, int b)
{
  return 1ll*a*b%MOD;
}

int n, f[N][N][2], g[N][N][2], p2[N];
char foo[N];

void Sub1(int i)
{
  if (i < 0) {
    // should not happend
  }
  if (foo[i] == '1') {
    foo[i] = '0';
    return ;
  }
  Sub1(i-1);
  foo[i] = '1';
}

int main()
{
  ios_base::sync_with_stdio(0);

  p2[0] = 1;
  for (int i = 1; i < N; i++)
    p2[i] = Mul(p2[i-1], 2);

  while (cin >> n >> foo) {
    char* r = foo;
    int m = strlen(r);
    Sub1(m-1);
    if (foo[0] == '0') {
      r++;
      m--;
    }
    // cout << r << endl;

    memset(g, 0, sizeof(g));
    g[0][0][0] = 1;
    g[0][1][1] = 1;
    for (int i = 1; i < m; i++) {
      int (&pg)[N][2] = g[i-1];
      g[i][0][0] = 1;
      for (int j = 1; j <= n; j++) {
        int (&cg)[2] = g[i][j];
        // non-max prefix
        cg[0] = Add(cg[0], pg[j][0]);
        cg[0] = Add(cg[0], pg[j-1][0]);
        if (r[i] == '1')
          cg[0] = Add(cg[0], pg[j][1]);
        // max prefix
        if (r[i] == '1')
          cg[1] = Add(cg[1], pg[j-1][1]);
        else
          cg[1] = Add(cg[1], pg[j][1]);
      }
    }
    // for (int i = 0; i < m; i++)
    //   for (int j = 0; j <= n; j++)
    //     fprintf(stderr, "(%4d,%4d)%c", g[i][j][0], g[i][j][1], j < n? ' ': '\n');
    // cout << Add(g[m-1][n][0], g[m-1][n][1]) << endl;

    memset(f, 0, sizeof(f));
    f[0][0][0] = 0;
    f[0][1][1] = p2[m-1];
    for (int i = 1; i < m; i++) {
      int (&pf)[N][2] = f[i-1];
      int (&pg)[N][2] = g[i-1];
      int cp2 = p2[m-1-i];
      for (int j = 1; j <= n; j++) {
        int (&cf)[2] = f[i][j];
        // non-max prefix
        cf[0] = Add(cf[0], pf[j][0]);
        cf[0] = Add(cf[0], Add(pf[j-1][0], Mul(pg[j-1][0], cp2)));
        if (r[i] == '1')
          cf[0] = Add(cf[0], pf[j][1]);
        // max prefix
        if (r[i] == '1')
          cf[1] = Add(cf[1], Add(pf[j-1][1], Mul(pg[j-1][1], cp2)));
        else
          cf[1] = Add(cf[1], pf[j][1]);
      }
    }
    // for (int i = 0; i < m; i++)
    //   for (int j = 0; j <= n; j++)
    //     fprintf(stderr, "(%4d,%4d)%c", f[i][j][0], f[i][j][1], j < n? ' ': '\n');
    cout << Add(f[m-1][n][0], f[m-1][n][1]) << endl;
  }
  return 0;
}
