#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

const int N = 3e3+5;

typedef long long LL;
typedef vector<int> VI;

int n, m;
VI g[N];

int main()
{
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u-1].push_back(v-1);
  }
  LL ans = 0;
  for (int u = 0; u < n; u++) {
    bool in2[N] = {false};
    for (int v: g[u])
      in2[v] = true;
    int cnt[N] = {0};
    for (int v = 0; v < n; v++)
      if (in2[v])
        for (int w: g[v])
          if (w != u)
            cnt[w]++;
    for (int v = 0; v < n; v++)
      ans += 1ll*cnt[v]*(cnt[v]-1)/2;
  }
  cout << ans << endl;
  return 0;
}
