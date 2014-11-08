#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

typedef vector<int> VI;

const int N = (1<<22)+5;
const int M = 2896+5;

struct BIA {
  VI d;

  void Init(int n)
  {
    d = VI(n+5, 0);
  }

  void Add(int x, int y)
  {
    for (x++; x < d.size(); x += -x&x)
      d[x] = max(d[x], y);
  }

  int Ask(int x)
  {
    int y = 0;
    for (x++; x; x -= -x&x)
      y = max(y, d[x]);
    return y;
  }
};

int t, n, m, a[M], l[N], w[N];
BIA b[M];

int main()
{
  ios_base::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> n >> m;
    memset(w, 0, sizeof(w));
    for (int i = 0; i < n; i++) {
      int ai;
      cin >> ai;
      w[ai]++;
    }

    int n = 0;
    for (int i = 0; i < N; i++)
      if (w[i] > 0)
        a[n++] = i;

    int maxd = a[n-1]-a[0];
    for (int i = 0; i < n; i++) {
      b[i].Init(maxd);
      b[i].Add(0, w[a[i]]);
    }

    for (int i = 0; i < n; i++)
      for (int j = 0; j < i; j++) {
        int k = a[i]-a[j];
        b[i].Add(k, b[j].Ask(k)+1);
      }

    int maxval = 0;
    for (int i = 0; i < n; i++)
      maxval = max(maxval, b[i].Ask(maxd));
    cout << maxval << endl;
  }
  return 0;
}
