#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

const int N = 2e3+5;
const int M = 1e9+7;

int Add(int a, int b)
{
  return ((a+b)%M+M)%M;
}

int Mul(int a, int b)
{
  return 1ll*a*b%M;
}

int n, d, a[N];
VI g[N];

int DFS(int root, int u, int p = -1)
{
  if (a[u] < a[root] || a[u] > a[root]+d)
    return 0;

  if (a[u] == a[root] && u < root)
    return 0;

  int ret = 1;
  for (int v: g[u])
    if (v != p)
      ret = Mul(ret, DFS(root, v, u)+1);
  return ret;
}

int main()
{
  scanf("%d%d", &d, &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);

  for (int i = 0; i < n-1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  int ans = 0;
  for (int i = 0; i < n; i++)
    ans = Add(ans, DFS(i, i));

  printf("%d\n", ans);
  return 0;
}
