#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

typedef map<int, int> MII;

const int N = 1e4+10;
const int M = 1e2+10;
const int MOD = 123456789;

int MAdd(int a, int b)
{
  return (a+b)%MOD;
}

void Discrete(int a[], int n)
{
  MII d;
  for (int i = 0; i < n; i++)
    d[a[i]] = 1;

  int rank = 1;
  for (MII::iterator i = d.begin(); i != d.end(); i++)
    i->second = rank++;

  for (int i = 0; i < n; i++)
    a[i] = d[a[i]];
}

struct BIA {
  int d[N];

  void Init()
  {
    memset(d, 0, sizeof(d));
  }

  void Add(int x, int y)
  {
    for (x++; x < N; x += -x&x)
      d[x] = MAdd(d[x], y);
  }

  int Ask(int x)
  {
    int ret = 0;
    for (x++; x; x -= -x&x)
      ret = MAdd(ret, d[x]);
    return ret;
  }
};

int n, m, a[N];
BIA b[M];

int main()
{
  cin.sync_with_stdio(0);
  while (cin >> n >> m) {
    for (int i = 0; i < n; i++)
      cin >> a[i];

    Discrete(a, n);
    for (int i = 0; i < M; i++)
      b[i].Init();

    b[0].Add(0, 1);
    for (int i = 0; i < n; i++)
      for (int j = m; j; j--)
        b[j].Add(a[i], b[j-1].Ask(a[i]-1));

    cout << b[m].Ask(n) << endl;
  }
  return 0;
}
