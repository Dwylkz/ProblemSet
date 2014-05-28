#include <map>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <cctype>
#include <string.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
const int N = 2e3 + 10;
typedef pair<int, int> pii_t;

int n[11], m, f[N][20][11];
pii_t p[N][20][11];

void show(int d, int i, int j) {
  if (d == 1) printf("%d", j);
  else {
    show(d-1, p[d][i][j].first, p[d][i][j].second);
    printf(" %d", j);
  }
}

int main()
{
#if 1
	freopen("input.txt", "r", stdin);
#endif
  for (int i = 1; i <= 10; i++) scanf("%1d", n+i);
  scanf("%d", &m);
  memset(f, 0, sizeof(f));
  memset(p, -1, sizeof(p));
  for (int i = 1; i <= 10; i++)
    if (n[i]) f[1][i][i] = 1;
  for (int i = 1; i < m; i++)
    for (int j = 1; j < 20; j++)
      for (int k = 1; k <= 10; k++)
        if (f[i][j][k])
          for (int l = j+1; l <= 10; l++)
            if (l != k && n[l]) {
              f[i+1][l-j][l] = 1;
              p[i+1][l-j][l] = pii_t(j, k);
            }
  int x = -1, y = -1;
  for (int i = 1; i < 20; i++)
    for (int j = 1; j <= 10; j++)
      if (f[m][i][j]) {
        x = i, y = j;
      }
  if (x != -1) {
    puts("YES");
    show(m, x, y);
    puts("");
  } else puts("NO");
	return 0;
}
