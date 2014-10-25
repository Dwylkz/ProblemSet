#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

const int N = 1e5+5;
const int M = 1e5+5;
const int B = 30;

struct Ask {
  int l, r, q;

  void Read()
  {
    scanf("%d%d%d", &l, &r, &q);
  }
};

Ask ask[M];
int n, m, a[B][M], sum[B][M];

int main()
{
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    ask[i].Read();
    for (int j = 0; j < B; j++)
      if (ask[i].q>>j&1) {
        a[j][ask[i].l]++;
        a[j][ask[i].r+1]--;
      }
  }

  for (int i = 0; i < B; i++)
    for (int j = 1; j < N; j++)
      a[i][j] += a[i][j-1];

  for (int i = 0; i < B; i++)
    for (int j = 0; j < N; j++)
      a[i][j] = a[i][j] > 0;

  for (int i = 0; i < B; i++) {
    sum[i][0] = a[i][0] > 0;
    for (int j = 1; j < N; j++)
      sum[i][j] = sum[i][j-1]+(a[i][j] > 0);
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < B; j++)
      if (~ask[i].q>>j&1)
        if (sum[j][ask[i].r]-sum[j][ask[i].l-1] == ask[i].r+1-ask[i].l) {
          puts("NO");
          return 0;
        }
  }

  puts("YES");
  for (int i = 0; i < n; i++) {
    int x = 0;
    for (int j = 0; j < B; j++)
      x |= a[j][i+1]<<j;
    printf("%d%c", x, i < n-1? ' ': '\n');
  }
  return 0;
}
