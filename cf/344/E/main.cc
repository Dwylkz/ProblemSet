#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;
typedef long long LL;
typedef map<int, LL> mill_t; 
const int N = 1e5+10;

int n, m, h[N], p[N], L[N], R[N];

int rbs(int x) {
  int l = 0, r = x, rv = -1;
  for ( ; l < r; ) {
    int m = l+r>>1;
    if (h[m] <= x) rv = R = m;
    else l = m+1;
  }
  return rv;
}
int lbs(int x) {
  int l = x, r = n-1, rv = -1;
  for ( ; l < r; ) {
    int m = l+r>>1;
    if (x < h[m]) rv = L = m+1;
    else r = m;
  }
  return h[rv] >= x? rv: -1;
}

int main() {
#if 1
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &m); ) {
    for (int i = 0; i < n; i++) scanf("%d", h+i);
    for (int i = 1; i <= m; i++) scanf("%d", p+i);
    for (int i = 0; i <= m; i++) {
      L[i] = (i-1+m+1)%m+1;
      R[i] = (i+1)%m+1;
    }
    LL rv = 0;
    for ( ; R[0]; ) {
      mill_t m;
    }
  }
  return 0;
}
