#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;
const int N = 2e5+10;
typedef long long LL;

int n, a[N], s[N], id[N];
LL b[N];

void add(int x, int y) {
  for (x++; x < N; x += -x&x) s[x] += y;
}
void rAdd(int x, int y, int z) {
  add(x, z);
  add(y+1, -z);
}
LL ask(int x) {
  LL ret = 0;
  for (x++; x; x -= -x&x) ret += s[x];
  return ret;
}

bool cmp(int lhs, int rhs) {
  int ls = a[lhs]? n-1-lhs: lhs-1, rs = a[rhs]? n-1-rhs: rhs-1;
  if (ls != rs) return ls > rs;
  return b[lhs] < b[rhs];
}

int main() {
#ifndef ONLINE_JUDGE 
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    memset(s, 0, sizeof(s));
    for (int i = 0; i < n; i++) {
      scanf("%d", a+i);
      id[i] = i;
      if (a[i]) rAdd(i+1, n, 1);
      else rAdd(0, i-1, 1);
    }
    for (int i = 0; i < n; i++) b[i] = ask(i);
    sort(id, id+n, cmp);
    LL ret = 0;
    for (int i = 0; i < n; i++) {
      int j = id[i];
      ret += ask(j);
      if (a[j]) rAdd(j+1, n, -1);
      else rAdd(0, j-1, -1);
    }
    cout << ret << endl;
  }
  return 0;
}
