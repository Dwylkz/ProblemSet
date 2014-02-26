#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 3e2+10;

int n, d[N];

int main() {
#ifndef ONLINE_JUDGE 
  freopen("input.in", "r", stdin);
#endif
  for ( ; ~scanf("%d", &n); ) {
    for (int i = 0; i < N; i++)
      d[i] = i&1? 0: 1;
    int l, r;
    scanf("%d%d", &l, &r);
    for (int i = 0; i < n-1; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      fill(d+x*2, d+y*2, 1);
    }
    printf("%d\n", count(d+l*2, d+r*2, 0));
  }
  return 0;
}
