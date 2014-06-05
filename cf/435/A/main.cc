#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
const int N = 1e2+10;

int n, m, a[N];

int f(int i, int r) {
  if (i == n)
    return r<m;
  if (a[i] == r)
    return 1+f(i+1, m);
  if (a[i] < r)
    return f(i+1, r-a[i]);
  return 1+f(i, m);
}

int main() {
#ifndef ONLINE_JUDGE 
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d%d", &n, &m); ) {
    for (int i = 0; i < n; i++)
      scanf("%d", a+i);
    printf("%d\n", f(0, m));
  }
  return 0;
}
