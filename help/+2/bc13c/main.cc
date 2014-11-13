#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = (2<<21) + 2;
int a[maxn];
int cha[maxn], pre_cha[maxn];
int cnt[maxn], cc[maxn];

int main()
{
  int T, n, m;

#ifndef ONLINE_JUDGE
  freopen("input.in", "r", stdin);
#endif

  while (scanf("%d", &T) != EOF)
  {
    while (T--)
    {
      scanf("%d%d", &n, &m);
      memset(cc, 0, sizeof(cc));
      memset(cha, 0, sizeof(cha));
      memset(cnt, 0, sizeof(cnt));
      memset(pre_cha, 0, sizeof(pre_cha));

      for (int i = 1; i <= n; i++)
      {
        scanf("%d", &a[i]);
        cc[a[i]]++;
      }
      int maxa = 0;
      int maxx = 0;
      for (int i = 1; i <= maxn; i++)
      {
        if (maxx < cc[i])
        {
          maxx = cc[i];
          maxa = i;
        }
      }
      sort(a+1, a+n+1);
      int ans = 0;
      if (maxa != a[1])
        ans = maxx;
      cha[1] = 0;
      for (int i = 2; i <= n; i++)
        cha[i] = a[i] - a[i-1];

      cnt[1] = 1;
      cnt[2] = 2;
      pre_cha[1] = 0;
      pre_cha[2] = cha[2];
      for (int i = 3; i <= n; i++)
      {
        int k = i;
        int tmp = cha[k];
        while (tmp < pre_cha[k-1] && k > 1)
        {
          k--;
          tmp += cha[k];
        }
        pre_cha[i] = tmp;
        if (k > 1)
          cnt[i] = cnt[k-1] + 1;
      }
      for (int i = 1; i <= n; i++)
        ans = max(ans, cnt[i]);
      printf("%d\n", ans);
    }
  }
  return 0;
}
