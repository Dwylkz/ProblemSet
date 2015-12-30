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

const int M = 1e9+7;
const int N = 5000+5;

int Add(int a, int b)
{
  return (a+b)%M;
}

int n;
char p[N];
int f[N][N], g[N][N];

int main()
{
  scanf("%d%s", &n, p);
  f[1][1] = 1;
  g[1][1] = 1;
  for (int i = 2; i <= n; i++) {
    for (int l = 1; l < i; l++) {
      if (p[i-l] != '0') {
        f[i][l] = g[i-l][min(i-l, l-1)];
        if (f[i-l][l] > 0) {
          if (i-2*l+1 < 1) f[i][l] = Add(f[i][l], f[i-l][l]);
          else {
            // cout << "l=";
            // for_each(p+i-2*l, p+i-l, [](char& c){cout<<c;});
            // cout << endl;
            // cout << "r=";
            // for_each(p+i-l, p+i, [](char& c){cout<<c;});
            // cout << endl;
            if (strncmp(p+i-2*l, p+i-l, l) < 0) f[i][l] = Add(f[i][l], f[i-l][l]);
          }
        }
      }
      g[i][l] = Add(g[i][l-1], f[i][l]);
    }
    f[i][i] = 1;
    g[i][i] = Add(g[i][i-1], f[i][i]);
  }
  // for (int i = 1; i <= n; i++)
  //   for (int j = 1; j <= n; j++)
  //     printf("(%5d, %5d)%c", f[i][j], g[i][j], j == n? '\n': ' ');
  printf("%d\n", g[n][n]);
  return 0;
}
