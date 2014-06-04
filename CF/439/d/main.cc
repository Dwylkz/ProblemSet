#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
const int N = 1e5+10;
const double EPS = 1e-4;
typedef long long LL;
typedef vector<int> VI;

int n, m, a[N], b[N];

void input(int* a, int n)
{
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a+n);
}

LL trans(int *a, int n, int x, int o)
{
  LL res = 0;
  int val = a[0], cur = 0;
  while (val != x) {
    int b = x;
    if (cur+1 < n)
      b = a[cur+1];
    int d = min(abs(x-val), abs(b-val));
    res += 1ll*(cur+1)*d;
    val += o*d;
    cur++;
  }
  return res;
}

LL look(int x)
{
  return trans(a, n, x, 1)+trans(b, m, x, -1);
}

int main()
{
  cin.sync_with_stdio(0);
  while (cin >> n >> m) {
    input(a, n);
    input(b, m);
    reverse(b, b+m);
    if (a[0] >= b[0]) {
      puts("0");
      continue;
    }

    double lb = a[0], rb = b[0];
    LL res = 0;
    while (lb < rb-EPS) {
      double len = (rb-lb)/3.0;
      double midl = lb+len, midr = rb-len;
      LL resl = look(floor(midl)), resr = look(ceil(midr));
      if (resl < resr)
        rb = midr;
      else
        lb = midl;
      res = min(resl, resr);
    }
    cout << res << endl;
  }
  return 0;
}
