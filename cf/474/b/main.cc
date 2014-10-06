#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+10;

int n, a[N], m, q[N], id[N], ans[N];

int main()
{
  scanf("%d", &n);
  a[0] = 1;
  for (int i = 1; i <= n; i++) {
    scanf("%d", a+i);
    a[i] += a[i-1];
  }

  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%d", q+i);
    id[i] = i;
  }
  sort(id, id+m, [&](const int& a, const int& b){return q[a] < q[b];});

  int j = 0;
  for (int i = 1; i <= n; i++) {
    while (j < m)
      if (a[i-1] <= q[id[j]] && q[id[j]] < a[i]) {
        ans[id[j]] = i;
        j++;
      }
      else
        break;
  }

  for (int i = 0; i < m; i++)
    printf("%d\n", ans[i]);
  return 0;
}
