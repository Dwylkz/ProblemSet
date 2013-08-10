#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 2e3 + 10;
typedef long long LL;

struct hash_table {
  static const int hash_size = 1<<20;
  struct hash_node {
    int x, to;
    double p;
  };
  vector<hash_node> H;
  int L[hash_size];
  hash_table()
  {
    memset(L, -1, sizeof(L));
  }
  void clear()
  {
    for (int i = 0; i < H.size(); i++)
      L[H[i].x] = -1;
    H.clear();
  }
  void push(int x, double p)
  {
    if (L[x] != -1) {
      H[L[x]].p += p;
      return ;
    }
    hash_node t = {x, L[x], p};
    L[x] = H.size();
    H.push_back(t);
  }
  int size()
  {
    return H.size();
  }
  hash_node & operator [] (int x)
  {
    return H[x];
  }
};

int n, a[maxn];
char o[maxn];
double p[maxn];

double dp_run()
{
  static hash_table h[2];
  int r = 0;
  h[0].clear();
  h[0].push(a[0], 1.0);
  for (int i = 0; i < n; i++) {
    h[!r].clear();
    for (int j = 0; j < h[r].size(); j++)
      if (h[r][j].x != 0 && h[r][j].p != 0.0) {
        h[!r].push(h[r][j].x, h[r][j].p * p[i]);
        int x = a[i+1];
        switch (o[i]) {
          case '&':
            x &= h[r][j].x;
            break;
          case '|':
            x |= h[r][j].x;
            break;
          case '^':
            x ^= h[r][j].x;
            break;
          default:
            ;
        }
        h[!r].push(x, h[r][j].p * (1.0-p[i]));
    }
    h[r].clear();
    r ^= 1;
  }
  double expect = 0.0;
  for (int i = 0; i < h[r].size(); i++)
    expect += h[r][i].x * h[r][i].p;
  return expect;
}

#define getb(x, y) ((x)>>(y)&1)
double b[2][20][2];
double dp_bit_run()
{
  int r = 0;
  memset(b[0], 0, sizeof(b[0]));
  for (int i = 0; i < 20; i++)
    b[0][i][getb(a[0], i)] = 1.0;
  for (int i = 0; i < n; i++) {
    memset(b[!r], 0, sizeof(b[!r]));
    for (int j = 0; j < 20; j++) {
      int x = getb(a[i+1], j);
      for (int k = 0; k < 2; k++) {
        b[!r][j][k] += b[r][j][k] * p[i];
        if (o[i] == '&') b[!r][j][k&x] += b[r][j][k] * (1-p[i]);
        else if (o[i] == '|') b[!r][j][k|x] += b[r][j][k] * (1-p[i]);
        else b[!r][j][k^x] += b[r][j][k] * (1-p[i]);
      }
    }
    r ^= 1;
  }
  double rv = 0;
  for (int i = 0; i < 20; i++)
    for (int j = 0; j < 2; j++)
      rv += b[r][i][j] * (j<<i);
  return rv;
}

int main()
{
#if 1
	freopen("input.in", "r", stdin);
#endif
	for (int T = 1; ~scanf("%d", &n); T++) {
    for (int i = 0; i <= n; i++)
      scanf("%d", a+i);
    for (int i = 0; i < n; i++) {
      char op[2];
      scanf("%1s", op);
      o[i] = op[0];
    }
    for (int i = 0; i < n; i++)
      scanf("%lf", p+i);
    printf("Case %d:\n%.6lf\n", T, dp_bit_run());
	}
	return 0;
}
