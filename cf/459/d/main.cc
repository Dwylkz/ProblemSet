#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int N = 1e6+10;

typedef map<int, int> MII;
typedef long long LL;

int n, a[N], l[N], r[N], h[N];

void f(int* to)
{
  memset(h, 0, sizeof(h));
  for (int i = 0; i < n; i++) {
    ++h[a[i]];
    to[i] = h[a[i]];
  }
}

int b[N];
void init()
{
  memset(b, 0, sizeof(b));
}
void add(int x)
{
  for ( ; x < N; x += -x&x)
    b[x]++;
}
int ask(int x)
{
  int ret = 0;
  for ( ; x; x -= -x&x)
    ret += b[x];
  return ret;
}

int main()
{
  cin.sync_with_stdio(0);
  for (;cin >> n;) {
    MII dis;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      dis[a[i]] = 1;
    }

    int rank = 0;
    for (auto &p: dis)
      p.second = rank++;
    for (int i = 0; i < n; i++)
      a[i] = dis[a[i]];

    f(l);
    reverse(a, a+n);
    f(r);
    reverse(l, l+n);

    LL ret = 0;
    init();
    add(r[0]);
    for (int i = 1; i < n; i++) {
      ret += ask(l[i]-1);
      add(r[i]);
    }

    cout << ret << endl;
  }
  return 0;
}
