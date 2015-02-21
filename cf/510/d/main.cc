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

const int N = 3e2+10;
const int P = 9;
const int S = 1<<P;

typedef vector<int> VI;

int n, l[N], c[N];

void Min(int& a, int b)
{
  if (a == -1 || a > b)
    a = b;
}

void Factorize(int x, VI& ps)
{
  for (int i = 2; 1ll*i*i <= x; i++)
    if (x%i == 0) {
      ps.push_back(i);
      while (x%i == 0)
        x /= i;
    }
  if (x > 1)
    ps.push_back(x);
}

int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", l+i);
  for (int i = 0; i < n; i++)
    scanf("%d", c+i);
  int res = -1;
  for (int i = 0; i < n; i++) {
    VI ps;
    Factorize(l[i], ps);
    int m[N] = {0};
    for (int j = 0; j <= i; j++)
      for (int k = 0; k < (int)ps.size(); k++)
        if (l[j]%ps[k] != 0)
          m[j] |= 1<<k;
    int f[N][S];
    memset(f, -1, sizeof(f));
    f[0][0] = 0;
    int ns = 1<<ps.size();
    for (int j = 1; j <= i; j++)
      for (int s = 0; s < ns; s++)
        if (f[j-1][s] != -1) {
          Min(f[j][s], f[j-1][s]);
          Min(f[j][s|m[j-1]], f[j-1][s]+c[j-1]);
        }
    for (int j = 0; j <= i; j++)
      if (f[i][ns-1] != -1)
        Min(res, f[i][ns-1]+c[i]);
  }
  printf("%d\n", res);
  return 0;
}
