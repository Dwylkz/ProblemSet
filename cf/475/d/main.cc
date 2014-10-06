#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 1e5+10;

int n, q;
struct Ans {
  int first, last;
  LL count;
};
unordered_map<int, Ans> ans;
Ans& Find(int x)
{
  if (ans.find(x) == ans.end()) {
    ans[x].count = 0;
    ans[x].first = -2;
    ans[x].last = -2;
  }
  return ans[x];
}

void Count(int i, int x, int y)
{
  Ans& xa = Find(x);
  if (xa.last != i)
    return ;

  int first = -2;
  for (int j = 2; 1ll*j*j <= y; j++) {
    if (y%j)
      continue;

    while (y%j == 0)
      y /= j;

    Ans& ia = Find(j);
    if (first == -2 || (ia.last == i && ia.first < first))
      first = ia.first;
  }
  if (y != 1) {
    Ans& ia = Find(y);
    if (first == -2 || (ia.last == i && ia.first < first))
      first = ia.first;
  }

  if (first == -2)
    xa.count += i-xa.first;
  else if (xa.first < first)
    xa.count += first-xa.first;
}

void Update(int i, int x)
{
  Ans& xa = ans[x];
  if (xa.last == i)
    xa.last++;
  else {
    xa.first = i;
    xa.last = i+1;
  }
}

int main()
{
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    int ai;
    scanf("%d", &ai);

    for (int j = 1; 1ll*j*j <= ai; j++) {
      if (ai%j)
        continue;

      Count(i, j, ai/j);
      if (ai/j != j)
        Count(i, ai/j, j);
    }

    for (int j = 1; 1ll*j*j <= ai; j++) {
      if (ai%j)
        continue;

      Update(i, j);
      if (ai/j != j)
        Update(i, ai/j);
    }

    ans[ai].count++;
    for (auto& a: ans)
      printf("%d: %d %d %lld\n", a.first, a.second.first, a.second.last, a.second.count);
    puts("---------");
  }

  scanf("%d", &q);
  while (q--) {
    int qi;
    scanf("%d", &qi);
    cout << Find(qi).count << endl;
  }
  return 0;
}
