#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 1e5+10;

int GCD(int a, int b)
{
  return b? GCD(b, a%b): a;
}

int n, a[N], q;

map<int, LL> ans;
void DC(int l, int r)
{
  if (r-l == 1) {
    ans[a[l]]++;
    return ;
  }

  int m = (l+r)/2;
  DC(l, m);
  DC(m, r);

  vector<pair<int, int>> tol, tor;
  int gcd = a[m], lower = m, upper = m;
  for (int i = m+1; i < r; i++)
    if (gcd != GCD(gcd, a[i])) {
      tor.push_back(make_pair(gcd, i-lower));
      gcd = GCD(gcd, a[i]);
      lower = i;
    }
  tor.push_back(make_pair(gcd, r-lower));

  gcd = a[m-1];
  for (int i = m-2; i >= l; i--)
    if (gcd != GCD(gcd, a[i])) {
      tol.push_back(make_pair(gcd, upper-(i+1)));
      gcd = GCD(gcd, a[i]);
      upper = i+1;
    }
  tol.push_back(make_pair(gcd, upper-l));

  for (auto& pl: tol)
    for (auto& pr: tor)
      ans[GCD(pl.first, pr.first)] += 1ll*pl.second*pr.second;
}

int main()
{
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  DC(0, n);

  scanf("%d", &q);
  while (q--) {
    int qi;
    scanf("%d", &qi);
    cout << ans[qi] << endl;
  }
  return 0;
}
