#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

typedef long long LL;

const int N = 5e3+10;

int n, m, k, p[N];
LL s[N], f[N][N], maxs[N];

int main()
{
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; i++)
    scanf("%d", p+i);

  s[0] = p[0];
  for (int i = 1; i < m; i++)
    s[i] = s[i-1]+p[i];
  for (int i = m; i < n; i++)
    s[i] = s[i-1]-p[i-m]+p[i];

  memset(f, -1, sizeof(f));
  int bound = min(2*m-1, n);
  for (int i = m-1; i < bound; i++)
    f[i][1] = s[i];

  memset(maxs+1, -1, sizeof(maxs));
  for (int i = bound; i < n; i++) {
    for (int j = 0; j <= k; j++)
      if (f[i-m][j] != -1)
        maxs[j] = max(maxs[j], f[i-m][j]);

    for (int j = 1; j <= k; j++)
      if (maxs[j-1] != -1)
        f[i][j] = max(f[i][j], maxs[j-1]+s[i]);
  }

  LL result = 0ll;
  for (int i = m-1; i < n; i++)
    result = max(result, f[i][k]);
  cout << result  << endl;
  return 0;
}
