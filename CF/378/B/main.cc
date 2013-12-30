#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
const int N = 2e5+10;
typedef vector<int> VI;

int n, a[N], b[N];

int s[N];
void init() {
  memset(s, 0, sizeof(s));
}
void add(int x, int y) {
  for (x++; x < N; x += -x&x) s[x] += y;
}
int sum(int x) {
  int r = 0;
  for (x++; x; x -= -x&x) r += s[x];
  return r;
}

int main() {
#ifndef ONLINE_JUDGE 
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    VI c, id(2*n), ok(2*n), rank(2*n);
    for (int i = 0; i < n; i++) scanf("%d%d", a+i, b+i);
    for (int i = 0; i < n; i++) c.push_back(a[i]);
    for (int i = 0; i < n; i++) c.push_back(b[i]);
    iota(id.begin(), id.end(), 0);
    sort(id.begin(), id.end(), [&](int a, int b){return c[a] < c[b];});
    for (int i = 0; i < 2*n; i++) rank[id[i]] = i;
    init();
    for (int i = 0; i < 2*n; i++) add(i, 1);
    int p = 0;
    while (p < n) ok[id[p++]] = 1;
    for (int k = 1; 2*k <= n; k++) {
      add(rank[k-1], -1);
      add(rank[n+k-1], -1);
      ok[k-1] = ok[n+k-1] = 1;
      while (p < 2*n && sum(p) < n-2*(k))
        ok[id[p++]] = 1;
    }
    for (int i = 0; i < n; i++) putchar(ok[i]+'0');
    puts("");
    for (int i = n; i < 2*n; i++) putchar(ok[i]+'0');
    puts("");
  }
  return 0;
}
