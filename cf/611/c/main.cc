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

const int N = 500+5;

int h, w, q, r1, c1, r2, c2;
char b[N][N];
int sum[N][N][2], acc[N][N];

int main()
{
  scanf("%d%d", &h, &w);
  for (int i = 1; i <= h; i++)
    scanf("%s", b[i]+1);
  for (int i = 1; i <= h; i++)
    for (int j = 1; j <= w; j++) {
      if (b[i][j] == '.' && b[i][j-1] == '.') sum[i][j][0]++;
      if (b[i][j] == '.' && b[i-1][j] == '.') sum[i][j][1]++;
      acc[i][j] = sum[i][j][0]+sum[i][j][1]+acc[i-1][j]+acc[i][j-1]-acc[i-1][j-1];
    }
  scanf("%d", &q);
  while (q--) {
    scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
    int res = acc[r2][c2]-acc[r2][c1-1]-acc[r1-1][c2]+acc[r1-1][c1-1];
    for (int i = c1; i <= c2; i++) res -= sum[r1][i][1];
    for (int i = r1; i <= r2; i++) res -= sum[i][c1][0];
    printf("%d\n", res);
  }
  return 0;
}
